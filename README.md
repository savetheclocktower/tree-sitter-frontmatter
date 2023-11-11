# tree-sitter-frontmatter

[Tree-sitter][] parser for [front matter](https://jekyllrb.com/docs/front-matter/) in arbitrary files.

Does not try to understand the contents of the file beyond the front matter delimiters. The proper parsers for the front-matter contents and the remainder of the file can be injected as needed.

## Why does this exist?

[Pulsar][] uses [ikatyang/tree-sitter-markdown](https://github.com/ikatyang/tree-sitter-markdown) for Markdown files; it’s very robust, but lacks support for the [YAML front matter](https://jekyllrb.com/docs/front-matter/) convention popularized by Jekyll.

Instead of trying to add such support to a complex and intimidating Tree-sitter parser, I chose to write my own Tree-sitter parser instead, one whose only purpose is to separate a front matter block from other content in a file.

Pulsar uses this parser to divide a file into two parts. It then injects YAML syntax highlighting into the front matter (if present) and Markdown syntax highlighting into the remainder of the file.

## How does parsing work?

In lieu of a proper front-matter specification, I’ve tried to capture what seem to be the universal rules about a front matter block:

* The starting and ending delimiters are `---`s on lines by themselves. Trailing whitespace is allowed, but leading whitespace is not. If there is trailing non-whitespace content on the same line, the delimiter is ignored.
* The starting delimiter must be on the very first line of the file.
* The very next valid delimiter encountered is treated as the ending delimiter. All other content in the file — even another line that would count as a valid delimiter — is treated as the remainder, because the front matter block is complete.
* Any would-be front matter block that _opens_ but never _closes_ is not treated as a front matter block.

[Pulsar]: https://pulsar-edit.dev
[tree-sitter]: https://github.com/tree-sitter/tree-sitter
