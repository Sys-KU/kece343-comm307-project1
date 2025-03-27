/***************************************************************/
/*                                                             */
/*   RISC-V (RV32I) assembler                                  */
/*                                                             */
/*   KECE343/COMM307 Korea University                          */
/*   assembler.h                                               */
/*                                                             */
/***************************************************************/

/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
/*          DO NOT MODIFY THIS FILE!                            */
/*          You should only assembler.c file!                   */
/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <errno.h>

/*
 * For debug option. If you want to debug, set 1
 * If not, set 0.
 */
#define DEBUG 0

#define MAX_SYMBOL_TABLE_SIZE   1024
#define MEM_TEXT_START          0x00400000
#define MEM_DATA_START          0x10000000
#define BYTES_PER_WORD          4
#define INST_LIST_LEN           20

/******************************************************
 * Structure Declaration
 *******************************************************/

typedef enum {
    TYPE_UNKNOWN,
    TYPE_R,
    TYPE_I,
    TYPE_S,
    TYPE_SB,
    TYPE_UJ,
    TYPE_U
} inst_type_t;

typedef struct inst_struct {
    char *name;
    char *op;
    char type;
    char *funct3;
    char *funct7;
} inst_t;

typedef struct symbol_struct {
    char name[32];
    uint32_t address;
} symbol_t;

enum section {
    DATA = 0,
    TEXT,
    MAX_SIZE
};

/* Functions */
void symbol_table_add_entry(symbol_t symbol);
void record_text_section(FILE *output);
void record_data_section(FILE *output);
void make_binary_file(FILE *output);
void make_symbol_table(FILE *input);

#endif