#include <tree_sitter/parser.h>
#include <wctype.h>
// #include <stdio.h>

enum TokenType {
  FRONTMATTER_DELIMITER,
  FRONTMATTER_BODY,
  REMAINDER_BODY,
  EOF_MARKER
};

typedef struct {
  bool started_frontmatter;
  bool ended_frontmatter;
} Scanner;

static inline void advance(TSLexer *lexer) { lexer->advance(lexer, false); }
static inline void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

static unsigned serialize(Scanner *scanner, char *buffer) {
  buffer[0] = (char) scanner->started_frontmatter;
  buffer[1] = (char) scanner->ended_frontmatter;
  return 2;
}

static void deserialize(Scanner *scanner, const char *buffer, unsigned length) {
  if (length == 0) {
    scanner->started_frontmatter = false;
    scanner->ended_frontmatter = false;
  } else {
    scanner->started_frontmatter = buffer[0];
    scanner->ended_frontmatter = buffer[1];
  }
}

static bool scan_frontmatter_start(Scanner *scanner, TSLexer *lexer) {
  if (lexer->eof(lexer)) {
    return false;
  }
  for (int i = 0; i < 3; i++) {
    if (lexer->lookahead == '-') {
      advance(lexer);
    } else {
      return false;
    }
    if (iswspace(lexer->lookahead)) {
      lexer->mark_end(lexer);
      while (iswspace(lexer->lookahead) && lexer->lookahead != '\n') {
        advance(lexer);
      }
      if (lexer->lookahead == '\n') {
        advance(lexer);
        lexer->result_symbol = FRONTMATTER_DELIMITER;
        scanner->started_frontmatter = true;
        return true;
      }
    }
  }
  return false;
}

static bool scan_frontmatter_contents(Scanner *scanner, TSLexer *lexer) {
  bool didAdvance = false;
  // Skip whitespace until we reach the first non-whitespace content — then
  // switch to advancing until we reach a new line.
  while (lexer->get_column(lexer) != 0 && !lexer->eof(lexer)) {
    if (iswspace(lexer->lookahead)) {
      if (didAdvance) { advance(lexer); }
      else { skip(lexer); }
    } else {
      didAdvance = true;
      advance(lexer);
    }
  }

  if (lexer->lookahead == '\n') {
    // If we reach this branch, either (a) we started in the middle of a line
    // and have parsed its remainder, or (b) we just parsed an empty (or
    // whitespace-only) line.
    advance(lexer);
    lexer->mark_end(lexer);
    lexer->result_symbol = FRONTMATTER_BODY;
    return true;
  }

  // Each individual line is either part of the frontmatter's contents or is the
  // end of the frontmatter section. If it successfully parses as the ending
  // delimiter, then we've consumed the entire line, so we can return.
  if (scan_frontmatter_start(scanner, lexer)) {
    scanner->ended_frontmatter = true;
    return true;
  } else {
    // If it returns false, then it's bailed before it can consume the entire
    // line; we know that everything it already consumed, along with the rest
    // of the line, is part of a line of frontmatter contents.
    while (!lexer->eof(lexer) && lexer->lookahead != '\n') {
      advance(lexer);
    }
    lexer->mark_end(lexer);
    lexer->result_symbol = FRONTMATTER_BODY;
    return true;
  }
}

static bool scan_remainder_contents(Scanner *scanner, TSLexer *lexer) {
  // The remainder shouldn't start until the beginning of the next line.
  while (iswspace(lexer->lookahead) && !lexer->eof(lexer)) {
    skip(lexer);
  }

  // If we've reached this point, the hard part is over. Everything else in the
  // file is now part of the remainder content. We use the scanner for this
  // because it's the only good way to detect EOF.
  while (!lexer->eof(lexer)) {
    advance(lexer);
  }

  lexer->result_symbol = REMAINDER_BODY;
  lexer->mark_end(lexer);
  return true;
}

static bool scan(Scanner *scanner, TSLexer *lexer, const bool *valid_symbols) {
  // printf("SCAN: Column %i, char '%c'\n", lexer->get_column(lexer), lexer->lookahead);
  if (valid_symbols[EOF_MARKER] && lexer->eof(lexer)) {
    lexer->result_symbol = EOF_MARKER;
    lexer->mark_end(lexer);
    return true;
  }

  if (valid_symbols[FRONTMATTER_DELIMITER] && !scanner->started_frontmatter && lexer->get_column(lexer) == 0) {
    bool result = scan_frontmatter_start(scanner, lexer);
    if (result) return true;
  }

  if (valid_symbols[FRONTMATTER_BODY] && scanner->started_frontmatter) {
    return scan_frontmatter_contents(scanner, lexer);
  }

  if (valid_symbols[REMAINDER_BODY] && (scanner->ended_frontmatter || !scanner->started_frontmatter)) {
    return scan_remainder_contents(scanner, lexer);
  }
  return false;
}

void *tree_sitter_frontmatter_external_scanner_create() {
  Scanner *scanner = calloc(1, sizeof(Scanner));
  scanner->started_frontmatter = false;
  scanner->ended_frontmatter = false;
  return scanner;
}

void tree_sitter_frontmatter_external_scanner_destroy(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  free(scanner);
}

void tree_sitter_frontmatter_external_scanner_reset(void *p) {}

unsigned tree_sitter_frontmatter_external_scanner_serialize(void *payload, char *state) {
  Scanner *scanner = (Scanner *)payload;
  return serialize(scanner, state);
}

void tree_sitter_frontmatter_external_scanner_deserialize(void *payload, const char *state, unsigned length) {
  Scanner *scanner = (Scanner *)payload;
  deserialize(scanner, state, length);
}

bool tree_sitter_frontmatter_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
  Scanner *scanner = (Scanner *)payload;
  return scan(scanner, lexer, valid_symbols);
}
