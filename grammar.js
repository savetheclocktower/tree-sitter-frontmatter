module.exports = grammar({
  name: 'frontmatter',

  extras: ($) => [/[\s\n]/],

  externals: ($) => [
    $._front_matter_delimiter,
    $._front_matter_body_line,
    $.remainder,
    $._eof
  ],

  rules: {
    source_file: $ => (
      seq(
        optional($.front_matter),
        choice(
          $.remainder,
          alias(
            $.unsuccessful_front_matter_reinterpreted_as_remainder,
            $.remainder
          )
        )
      )
    ),

    front_matter_body: ($) => (
      repeat1($._front_matter_body_line)
    ),

    unsuccessful_front_matter_reinterpreted_as_remainder: ($) => (
      seq(
        $._front_matter_delimiter,
        repeat1($._front_matter_body_line),
        $._eof
      )
    ),

    front_matter: ($) => (
      seq(
        alias($._front_matter_delimiter, "---"),
        alias($.front_matter_body, $.text),
        alias($._front_matter_delimiter, "---")
      )
    ),

  }
});
