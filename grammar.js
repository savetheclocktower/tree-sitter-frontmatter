module.exports = grammar({
  name: 'frontmatter',

  extras: ($) => [/\s/],

  externals: ($) => [
    $._frontmatter_delimiter,
    $._frontmatter_body_line,
    $.remainder
  ],

  rules: {
    source_file: $ => (
      seq(
        $.frontmatter,
        $.remainder
      )
    ),

    frontmatter_body: ($) => (
      // repeat1(/.*?\n/)
      repeat1($._frontmatter_body_line)
    ),

    frontmatter: ($) => (
      seq(
        $._frontmatter_delimiter,
        alias($.frontmatter_body, $.text),
        $._frontmatter_delimiter
      )
    ),

  }
});
