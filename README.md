# Programming Assignment #1: Implementing a RISC-V (RV32I) Assembler

**Due**: April 14th, 11:59PM

**TA**: Youngjoon Cheon (yjcheon@csl.korea.ac.kr)

---

## 1. Overview

In this project, you will implement a **two-pass assembler** for a subset of
the RISC-V (RV32I) instruction set.  The assembler reads a `.s` assembly file
and produces a binary `.o` file that the simulator can execute.

```text
assembly (.s)  →  [assembler]  →  binary (.o)  →  [simulator]
```

This is a simplified assembler which does not support linking, so there are no
symbol or relocation tables.  A single `.s` file is the entire program.

---

## 2. Instruction Set

Your assembler must handle the following instructions.

| Format | Instructions |
| --- | --- |
| R-type | `add`, `sub`, `and`, `or`, `sltu` |
| I-type | `addi`, `andi`, `xori`, `ori`, `sltiu`, `slli`, `srli`, `lw`, `jalr` |
| S-type | `sw` |
| B-type | `beq`, `bne`, `blt`, `bge` |
| J-type | `jal` |
| U-type | `lui`, `auipc` |
| Pseudo | `la` (expands to `auipc` + `addi`) |

Additional constraints:

- Signed operations (`add`, `sub`) and unsigned operations (`sltiu`, `sltu`,
  `slli`, `srli`) must both be supported.
- Only word-sized (4-byte) loads and stores (`lw`, `sw`) are required.
- Immediates may be decimal (e.g., `1024`) or hexadecimal (e.g., `0x400`).
- Register names are written as `x0` through `x31`.

### `la` pseudo-instruction

`la` loads the 32-bit address of a data-section label into a register.
It expands into `auipc` + `addi`:

```text
la  x<n>, VAR1

→  auipc  x<n>, D[31:12]   # hi20 = (D + 0x800) >> 12,  D = VAR1 − PC
→  addi   x<n>, x<n>, D[11:0]  # lo12 = D − (hi20 << 12)
```

Adding `0x800` before the right-shift ensures that the signed 12-bit `addi`
immediate (`lo12`) always stays within [−2048, +2047].

**Example — D = `0x0FCFFFFC`:**

```text
auipc  x2, 0x0FD00   # hi20 = (0x0FCFFFFC + 0x800) >> 12
addi   x2, x2, 0xFFC # lo12 = D − (hi20 << 12)
```

**Example — D = `0x0FC00000`** (lo12 = 0, `addi` can be omitted):

```text
auipc  x2, 0x0FC00
```

---

## 3. Assembly File Format

### 3.1 Directives

| Directive | Description | Start address |
| --- | --- | --- |
| `.data` | Static data segment | `0x10000000` |
| `.text` | Instruction segment | `0x00400000` |
| `.word` | 32-bit data word | — |

Rules:

- The `.data` section must appear **before** `.text`.
- Each section appears exactly once.
- All words in `.data` have an initial value.

### 3.2 Input syntax

- Fields (opcode, operands) are separated by **tabs**.
- Labels in `.text` appear on their **own line** followed by a colon (e.g., `loop:`).
- Labels in `.data` appear on the **same line** as `.word` (e.g., `array:  .word  9`).

**Example input file** (fields are tab-separated in actual files):

```asm
    .data
array:  .word   3
    .word   123
    .word   4346
array2: .word   0x11111111
    .text
main:
    addi    x2, x0, 1024
    add     x3, x2, x2
    la      x4, array2
    sw      x3, 0(x2)
    lw      x5, 0(x2)
    bne     x3, x5, main
```

### 3.3 Memory layout

```text
0x7FFFFFFC  ← sp  (stack top)
            Stack (grows ↓)
            Dynamic Data (grows ↑)
0x10008000  ← gp
0x10000000        Static Data   (.data starts here)
0x00400000  ← pc  Text          (.text starts here)
0x00000000        Reserved
```

### 3.4 Output format

The assembler writes a binary `.o` file with the following layout:

```text
<text section size>          (32-bit word: number of bytes in .text)
<data section size>          (32-bit word: number of bytes in .data)
<instruction 1>              (32-bit words, one per instruction)
...
<instruction n>
<initial value of data 1>    (32-bit words, one per .word)
...
```

The output file is placed in the **same directory** as the input `.s` file.

---

## 4. Skeleton Code

The provided skeleton (`assembler.c`) implements file I/O and a two-pass
framework.  Your task is to write code in the four functions marked `/* blank */`:

| Function | What to implement |
| --- | --- |
| `make_symbol_table(FILE *input)` | 1st pass: build label-to-address map; separate `.data` and `.text` segments |
| `make_binary_file(FILE *output)` | 2nd pass: call `record_text_section()` and `record_data_section()` |
| `record_text_section(FILE *output)` | Translate each `.text` line to a 32-bit binary instruction |
| `record_data_section(FILE *output)` | Translate each `.data` word to its 32-bit binary value |

Utility functions in `util.c` are available for common operations (see the
file for details).
You may want to write the assembler from scratch, but the input/output format
must match exactly. 

Please note that **only `assembler.c` can be modified.**

### Debug option

In `assembler.h`, set `#define DEBUG 1` to enable verbose trace output that
shows the code flow.  Set it back to `0` before submitting.

---

## 5. Files

| File | Status | Description |
| --- | --- | --- |
| `main.c` | **Do not modify** | Entry point and file handling |
| `assembler.h` | **Do not modify** | Struct definitions and prototypes |
| `util.c` / `util.h` | **Do not modify** | Utility functions |
| **`assembler.c`** | **You modify this** | Two-pass assembler implementation |

---

## 6. Build and Test

```bash
make              # build the assembler
make test         # run all test cases
make clean        # remove build artifacts
```

Run a single test manually:

```bash
./ku-rv32i-as sample_input/example0.s   # produces sample_input/example0.o
```

Compare with the reference output:

```bash
diff -Naur sample_input/example0.o sample_output/example0.o
```

No output from `diff` means your result is correct.

The `make test` target runs `diff` on all 9 examples automatically.

---

## 7. Grading

Your output must be **bit-for-bit identical** to the reference files in
`sample_output/`.  A single wrong bit gives **0 points** for that test case.

There are **9 graded test cases** total (the last 3 cases are hidden on the grader). 
Grades are determined automatically by the grader.

---

## 8. Submission

Submit **only `assembler.c`** to the course submission system. Thus, you
are **not allowed to change the file name** or include any other files. 

In addition, submit a **1-page PDF report** (no cover page required) that
includes:

1. How you understand the structure and flow of the skeleton code
2. How you implemented `make_symbol_table()`
3. What you learned from this assignment
4. (Optional) Suggestions to improve the assignment

Include your **name** and **student ID** at the top of the report.
Submit your report via LMS 'Assignments' tab.
**Do not include code or screenshots.**

---

## 9. Reference

### Useful C library functions

| Function | Description |
| --- | --- |
| `FILE *tmpfile(void)` | Create a temporary file opened in `wb+` mode |
| `void rewind(FILE *fp)` | Reset file stream position to the beginning |

### `la` address-calculation detail

When computing `D = label_address − PC`:

```c
int32_t hi20 = (D + 0x800) >> 12;   // upper 20 bits (rounded)
int32_t lo12 = D - (hi20 << 12);    // lower 12 bits, fits in [-2048, 2047]
```

If `lo12 == 0`, the `addi` instruction may be omitted and only `auipc` is
emitted.

---

## 10. Misc

We will accept your late submissions, but your score will lose up to 50%. 
Please do not give up the project.

**Be aware of plagiarism!** Although it is encouraged to discuss with others 
and refer to extra materials, **copying other students or opening code publicly is strictly banned.**
The TAs will compare your source code with other team’s code. 
If you are caught, you will receive a penalty for plagiarism.

Last semester, we found a couple of plagiarism cases through an automated tool. Please do not try to cheat TAs. 
If you have any requests or questions regarding administrative issues (such as late submission due to an unfortunate accident, gradescope is not working), please send an e-mail to the TAs.