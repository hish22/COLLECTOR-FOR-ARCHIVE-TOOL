# COLLECTOR-FOR-ARCHIVE-TOOL

<img src="docs/cfat_Edited.png" width="400px">

## Description

CFAT is an archiving utility designed to enable users consolidate multiple files into a single, organized archive.

## Features

- **Archive Creation:** Consolidate any group of files into a single, new archive file.
- **Archive Management:** Insert, replace, or delete files directly within an existing archive.
- **Extraction:** Effortlessly extract specific content from the archive.
- **Introspection:** View a list of all archived files and retrieve the total file count for quick auditing.

## Build from Source
> [!NOTE]
preferred to use gcc (GNU Compiler Collection) as the primary compiler.

```bash
gcc cfat.c -o cfat
```

## Usage

```bash
./cfat <command> <archive_name> [file_name]
```

**Commands:**
* `-c` : Create a new archive
* `-i` : Insert a file
* `-d` : Delete a file
* `-l` : List contents
* `-x` : Extract a specific file (or all)
* `-n` : Show file count
* `-r` : Replace a file with another
* `-h` : Show help menu

## Contributing

We welcome contributions! Please follow these steps:

* **Bugs/Features:** Open an issue to discuss or report a problem.
* **Pull Requests:** Fork the repo and submit a PR for your changes.
* **Guidelines:** Keep code clean, test your changes, and ensure documentation is updated.

Thanks for helping improve CFAT!