# CFAT Usage

## Build

```bash
gcc cfat.c -o cfat
```

## Synopsis

```bash
./cfat <command> <archive_name> [file_name ...]
```

The archive name is used *without* extension for creation, and *with* `.cfat` extension for all other operations.

## Commands

### `-c` — Create a new archive

```bash
./cfat -c myarchive
```
Creates `myarchive.cfat` with zero files.

### `-i` — Insert a file

```bash
./cfat -i myarchive.cfat document.txt
```
Inserts `document.txt` into the archive.

### `-d` — Delete a file

```bash
./cfat -d myarchive.cfat document.txt
```
Removes `document.txt` from the archive.

### `-r` — Replace a file

```bash
./cfat -r myarchive.cfat old.txt new.txt
```
Replaces `old.txt` (inside the archive) with the contents of `new.txt`.

### `-x` — Extract a file

```bash
./cfat -x myarchive.cfat document.txt
```
Extracts `document.txt` from the archive and writes it to disk.

### `-l` — List contents

```bash
./cfat -l myarchive.cfat
```
Displays a table of all files and their sizes.

### `-n` — Show file count

```bash
./cfat -n myarchive.cfat
```
Prints the total number of files in the archive.

### `-h` — Help

```bash
./cfat -h
```
Displays usage information.
