# ciof

**ciof** (Contents In One File) is a command-line tool that collects source files from a project and exports them in a format suitable for large language models.

It scans directories, filters files, and produces a structured output file containing file metadata and contents.

The tool is designed for workflows where codebases must be passed into AI systems for analysis, review, or transformation.

## Features

* Recursive directory scanning
* Multiple input paths
* Extension filtering
* Maximum file size limits
* Multiple output formats
* Clean modern C++ implementation

Supported output formats:

* plain text
* markdown
* json

## Build

Requirements:

* CMake 3.16+
* C++20 compiler

Build:

```
cmake . --preset=release
cmake --build . --preset=release
```

## Usage

Example:

```
ciof \
  --path src \
  --path include \
  --extensions .cpp .hpp .h \
  --format markdown \
  --output context.md
```

### Options

| Flag               | Description                         |
| ------------------ | ----------------------------------- |
| `--path`           | Path to scan (can be repeated)      |
| `--extensions`     | File extensions to include          |
| `--output`         | Output file                         |
| `--format`         | plain, markdown, json               |
| `--max-file-size`  | Maximum file size (e.g. 200KB, 5MB) |
| `--timestamps`     | Include file timestamps             |
| `--relative-paths` | Use relative paths                  |
| `--exclude`        | Exclude directories                 |

Example:

```
ciof \
  --path src \
  --extensions .cpp .hpp \
  --exclude build \
  --max-file-size 500KB
```

## Project Structure

```
Include/
    ciofxx/
        CliOptions.hpp
        FileData.hpp
        FileScanner.hpp
        FileSize.hpp
        Formatter.hpp
        FormatterFactory.hpp
        Formatters.hpp
        OutputFormat.hpp
        OutputWriter.hpp
        Utils.hpp

Source/
    CliOptions.cpp
    FileScanner.cpp
    FileSize.cpp
    FormatterFactory.cpp
    Formatters.cpp
    OutputFormat.cpp
    OutputWriter.cpp
    Utils.cpp
    Main.cpp
```

## Design

The program consists of three major components:

CLI parsing
→ converts command-line arguments into `CliOptions`.

File scanning
→ collects files and loads contents into `FileData`.

Output writing
→ serializes files into the selected format.

## License

MIT
