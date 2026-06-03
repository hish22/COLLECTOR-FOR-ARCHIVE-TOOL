# CFAT Documentation

**Collector for Archive Tool** — a lightweight archiving utility for consolidating, managing, and extracting files from a single archive.

---

## Documentation Map

| Document | Description |
|----------|-------------|
| [entry.md](entry.md) | You are here — documentation guide and index |
| [arch.md](arch.md) | Internal architecture, archive format, and design decisions |
| [usage.md](usage.md) | Build instructions, CLI commands, and examples |

---

## Quick Start

```bash
gcc cfat.c -o cfat
./cfat -c myarchive
./cfat -i myarchive.cfat file.txt
./cfat -x myarchive.cfat file.txt
```

For a full reference, see [usage.md](usage.md).

---

## Porting Guide

When porting CFAT to another platform or language, refer to these key files:

| Concern | Source File |
|---------|-------------|
| Archive header structs | `carchive.h` |
| Archive creation | `carchive.c` |
| File insertion | `ifarchive.c` |
| File deletion | `dfarchive.c` |
| File replacement | `rarchive.c` |
| File extraction | `xarchive.c` |
| Archive listing | `larchive.c` |
| File counting | `narchive.c` |
| CLI parser | `cmdparser.c` |
| Path helpers | `helper.c` / `helper.h` |
| Terminal UI | `design.c` / `design.h` |

Archive layout is documented in [arch.md](arch.md).
