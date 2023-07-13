#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 10
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 8
#define ALIAS_COUNT 0
#define TOKEN_COUNT 4
#define EXTERNAL_TOKEN_COUNT 3
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum {
  sym__frontmatter_delimiter = 1,
  sym__frontmatter_body_line = 2,
  sym_remainder = 3,
  sym_source_file = 4,
  sym_frontmatter_body = 5,
  sym_frontmatter = 6,
  aux_sym_frontmatter_body_repeat1 = 7,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__frontmatter_delimiter] = "_frontmatter_delimiter",
  [sym__frontmatter_body_line] = "_frontmatter_body_line",
  [sym_remainder] = "remainder",
  [sym_source_file] = "source_file",
  [sym_frontmatter_body] = "text",
  [sym_frontmatter] = "frontmatter",
  [aux_sym_frontmatter_body_repeat1] = "frontmatter_body_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym__frontmatter_delimiter] = sym__frontmatter_delimiter,
  [sym__frontmatter_body_line] = sym__frontmatter_body_line,
  [sym_remainder] = sym_remainder,
  [sym_source_file] = sym_source_file,
  [sym_frontmatter_body] = sym_frontmatter_body,
  [sym_frontmatter] = sym_frontmatter,
  [aux_sym_frontmatter_body_repeat1] = aux_sym_frontmatter_body_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym__frontmatter_delimiter] = {
    .visible = false,
    .named = true,
  },
  [sym__frontmatter_body_line] = {
    .visible = false,
    .named = true,
  },
  [sym_remainder] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_frontmatter_body] = {
    .visible = true,
    .named = true,
  },
  [sym_frontmatter] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_frontmatter_body_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      if (eof) ADVANCE(1);
      END_STATE();
    case 1:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0, .external_lex_state = 2},
  [2] = {.lex_state = 0, .external_lex_state = 3},
  [3] = {.lex_state = 0, .external_lex_state = 4},
  [4] = {.lex_state = 0, .external_lex_state = 4},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0, .external_lex_state = 5},
  [7] = {.lex_state = 0, .external_lex_state = 2},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0, .external_lex_state = 5},
};

enum {
  ts_external_token__frontmatter_delimiter = 0,
  ts_external_token__frontmatter_body_line = 1,
  ts_external_token_remainder = 2,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__frontmatter_delimiter] = sym__frontmatter_delimiter,
  [ts_external_token__frontmatter_body_line] = sym__frontmatter_body_line,
  [ts_external_token_remainder] = sym_remainder,
};

static const bool ts_external_scanner_states[6][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__frontmatter_delimiter] = true,
    [ts_external_token__frontmatter_body_line] = true,
    [ts_external_token_remainder] = true,
  },
  [2] = {
    [ts_external_token__frontmatter_delimiter] = true,
  },
  [3] = {
    [ts_external_token__frontmatter_body_line] = true,
  },
  [4] = {
    [ts_external_token__frontmatter_delimiter] = true,
    [ts_external_token__frontmatter_body_line] = true,
  },
  [5] = {
    [ts_external_token_remainder] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym__frontmatter_delimiter] = ACTIONS(1),
    [sym__frontmatter_body_line] = ACTIONS(1),
    [sym_remainder] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(5),
    [sym_frontmatter] = STATE(6),
    [sym__frontmatter_delimiter] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(5), 1,
      sym__frontmatter_body_line,
    STATE(3), 1,
      aux_sym_frontmatter_body_repeat1,
    STATE(7), 1,
      sym_frontmatter_body,
  [10] = 3,
    ACTIONS(7), 1,
      sym__frontmatter_delimiter,
    ACTIONS(9), 1,
      sym__frontmatter_body_line,
    STATE(4), 1,
      aux_sym_frontmatter_body_repeat1,
  [20] = 3,
    ACTIONS(11), 1,
      sym__frontmatter_delimiter,
    ACTIONS(13), 1,
      sym__frontmatter_body_line,
    STATE(4), 1,
      aux_sym_frontmatter_body_repeat1,
  [30] = 1,
    ACTIONS(16), 1,
      ts_builtin_sym_end,
  [34] = 1,
    ACTIONS(18), 1,
      sym_remainder,
  [38] = 1,
    ACTIONS(20), 1,
      sym__frontmatter_delimiter,
  [42] = 1,
    ACTIONS(22), 1,
      ts_builtin_sym_end,
  [46] = 1,
    ACTIONS(24), 1,
      sym_remainder,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 10,
  [SMALL_STATE(4)] = 20,
  [SMALL_STATE(5)] = 30,
  [SMALL_STATE(6)] = 34,
  [SMALL_STATE(7)] = 38,
  [SMALL_STATE(8)] = 42,
  [SMALL_STATE(9)] = 46,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_frontmatter_body, 1),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_frontmatter_body_repeat1, 2),
  [13] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_frontmatter_body_repeat1, 2), SHIFT_REPEAT(4),
  [16] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [18] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [20] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [22] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2),
  [24] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_frontmatter, 3),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_frontmatter_external_scanner_create(void);
void tree_sitter_frontmatter_external_scanner_destroy(void *);
bool tree_sitter_frontmatter_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_frontmatter_external_scanner_serialize(void *, char *);
void tree_sitter_frontmatter_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_frontmatter(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_frontmatter_external_scanner_create,
      tree_sitter_frontmatter_external_scanner_destroy,
      tree_sitter_frontmatter_external_scanner_scan,
      tree_sitter_frontmatter_external_scanner_serialize,
      tree_sitter_frontmatter_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
