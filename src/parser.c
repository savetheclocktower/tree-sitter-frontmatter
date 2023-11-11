#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 15
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 10
#define ALIAS_COUNT 1
#define TOKEN_COUNT 5
#define EXTERNAL_TOKEN_COUNT 4
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 2

enum {
  sym__front_matter_delimiter = 1,
  sym__front_matter_body_line = 2,
  sym_remainder = 3,
  sym__eof = 4,
  sym_source_file = 5,
  sym_front_matter_body = 6,
  sym_unsuccessful_front_matter_reinterpreted_as_remainder = 7,
  sym_front_matter = 8,
  aux_sym_front_matter_body_repeat1 = 9,
  anon_alias_sym_DASH_DASH_DASH = 10,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__front_matter_delimiter] = "_front_matter_delimiter",
  [sym__front_matter_body_line] = "_front_matter_body_line",
  [sym_remainder] = "remainder",
  [sym__eof] = "_eof",
  [sym_source_file] = "source_file",
  [sym_front_matter_body] = "text",
  [sym_unsuccessful_front_matter_reinterpreted_as_remainder] = "remainder",
  [sym_front_matter] = "front_matter",
  [aux_sym_front_matter_body_repeat1] = "front_matter_body_repeat1",
  [anon_alias_sym_DASH_DASH_DASH] = "---",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym__front_matter_delimiter] = sym__front_matter_delimiter,
  [sym__front_matter_body_line] = sym__front_matter_body_line,
  [sym_remainder] = sym_remainder,
  [sym__eof] = sym__eof,
  [sym_source_file] = sym_source_file,
  [sym_front_matter_body] = sym_front_matter_body,
  [sym_unsuccessful_front_matter_reinterpreted_as_remainder] = sym_remainder,
  [sym_front_matter] = sym_front_matter,
  [aux_sym_front_matter_body_repeat1] = aux_sym_front_matter_body_repeat1,
  [anon_alias_sym_DASH_DASH_DASH] = anon_alias_sym_DASH_DASH_DASH,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym__front_matter_delimiter] = {
    .visible = false,
    .named = true,
  },
  [sym__front_matter_body_line] = {
    .visible = false,
    .named = true,
  },
  [sym_remainder] = {
    .visible = true,
    .named = true,
  },
  [sym__eof] = {
    .visible = false,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_front_matter_body] = {
    .visible = true,
    .named = true,
  },
  [sym_unsuccessful_front_matter_reinterpreted_as_remainder] = {
    .visible = true,
    .named = true,
  },
  [sym_front_matter] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_front_matter_body_repeat1] = {
    .visible = false,
    .named = false,
  },
  [anon_alias_sym_DASH_DASH_DASH] = {
    .visible = true,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [0] = anon_alias_sym_DASH_DASH_DASH,
    [2] = anon_alias_sym_DASH_DASH_DASH,
  },
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
  [7] = 3,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
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
  [3] = {.lex_state = 0, .external_lex_state = 3},
  [4] = {.lex_state = 0, .external_lex_state = 4},
  [5] = {.lex_state = 0, .external_lex_state = 2},
  [6] = {.lex_state = 0, .external_lex_state = 5},
  [7] = {.lex_state = 0, .external_lex_state = 5},
  [8] = {.lex_state = 0, .external_lex_state = 4},
  [9] = {.lex_state = 0, .external_lex_state = 2},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0, .external_lex_state = 6},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
};

enum {
  ts_external_token__front_matter_delimiter = 0,
  ts_external_token__front_matter_body_line = 1,
  ts_external_token_remainder = 2,
  ts_external_token__eof = 3,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__front_matter_delimiter] = sym__front_matter_delimiter,
  [ts_external_token__front_matter_body_line] = sym__front_matter_body_line,
  [ts_external_token_remainder] = sym_remainder,
  [ts_external_token__eof] = sym__eof,
};

static const bool ts_external_scanner_states[7][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__front_matter_delimiter] = true,
    [ts_external_token__front_matter_body_line] = true,
    [ts_external_token_remainder] = true,
    [ts_external_token__eof] = true,
  },
  [2] = {
    [ts_external_token__front_matter_delimiter] = true,
    [ts_external_token_remainder] = true,
  },
  [3] = {
    [ts_external_token__front_matter_delimiter] = true,
    [ts_external_token__front_matter_body_line] = true,
    [ts_external_token__eof] = true,
  },
  [4] = {
    [ts_external_token__front_matter_body_line] = true,
  },
  [5] = {
    [ts_external_token__front_matter_body_line] = true,
    [ts_external_token__eof] = true,
  },
  [6] = {
    [ts_external_token__front_matter_delimiter] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym__front_matter_delimiter] = ACTIONS(1),
    [sym__front_matter_body_line] = ACTIONS(1),
    [sym_remainder] = ACTIONS(1),
    [sym__eof] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(11),
    [sym_unsuccessful_front_matter_reinterpreted_as_remainder] = STATE(10),
    [sym_front_matter] = STATE(5),
    [sym__front_matter_delimiter] = ACTIONS(3),
    [sym_remainder] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(7), 1,
      sym__front_matter_delimiter,
    ACTIONS(9), 1,
      sym__front_matter_body_line,
    ACTIONS(11), 1,
      sym__eof,
    STATE(3), 1,
      aux_sym_front_matter_body_repeat1,
  [13] = 3,
    ACTIONS(15), 1,
      sym__front_matter_body_line,
    STATE(3), 1,
      aux_sym_front_matter_body_repeat1,
    ACTIONS(13), 2,
      sym__front_matter_delimiter,
      sym__eof,
  [24] = 3,
    ACTIONS(18), 1,
      sym__front_matter_body_line,
    STATE(2), 1,
      aux_sym_front_matter_body_repeat1,
    STATE(12), 1,
      sym_front_matter_body,
  [34] = 3,
    ACTIONS(20), 1,
      sym__front_matter_delimiter,
    ACTIONS(22), 1,
      sym_remainder,
    STATE(13), 1,
      sym_unsuccessful_front_matter_reinterpreted_as_remainder,
  [44] = 3,
    ACTIONS(11), 1,
      sym__eof,
    ACTIONS(24), 1,
      sym__front_matter_body_line,
    STATE(7), 1,
      aux_sym_front_matter_body_repeat1,
  [54] = 3,
    ACTIONS(13), 1,
      sym__eof,
    ACTIONS(26), 1,
      sym__front_matter_body_line,
    STATE(7), 1,
      aux_sym_front_matter_body_repeat1,
  [64] = 2,
    ACTIONS(29), 1,
      sym__front_matter_body_line,
    STATE(6), 1,
      aux_sym_front_matter_body_repeat1,
  [71] = 1,
    ACTIONS(31), 2,
      sym__front_matter_delimiter,
      sym_remainder,
  [76] = 1,
    ACTIONS(33), 1,
      ts_builtin_sym_end,
  [80] = 1,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
  [84] = 1,
    ACTIONS(37), 1,
      sym__front_matter_delimiter,
  [88] = 1,
    ACTIONS(39), 1,
      ts_builtin_sym_end,
  [92] = 1,
    ACTIONS(41), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 13,
  [SMALL_STATE(4)] = 24,
  [SMALL_STATE(5)] = 34,
  [SMALL_STATE(6)] = 44,
  [SMALL_STATE(7)] = 54,
  [SMALL_STATE(8)] = 64,
  [SMALL_STATE(9)] = 71,
  [SMALL_STATE(10)] = 76,
  [SMALL_STATE(11)] = 80,
  [SMALL_STATE(12)] = 84,
  [SMALL_STATE(13)] = 88,
  [SMALL_STATE(14)] = 92,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_front_matter_body, 1),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_front_matter_body_repeat1, 2),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_front_matter_body_repeat1, 2), SHIFT_REPEAT(3),
  [18] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [20] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [22] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [24] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_front_matter_body_repeat1, 2), SHIFT_REPEAT(7),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_front_matter, 3, .production_id = 1),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [35] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unsuccessful_front_matter_reinterpreted_as_remainder, 3),
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
