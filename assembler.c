/***************************************************************/
/*                                                             */
/*   RISC-V (RV32I) assembler                                  */
/*                                                             */
/*   KECE343/COMM307 Korea University                          */
/*   assembler.c                                               */
/*                                                             */
/***************************************************************/

#include "assembler.h"
#include "util.h"

/******************************************************
 * Global Variable Declaration
 *******************************************************/

inst_t inst_list[INST_LIST_LEN] = {                  //  idx
    {"add",   "0110011", TYPE_R, "000", "0000000"},  //   0
    {"sub",   "0110011", TYPE_R, "000", "0100000"},  //   1
    {"addi",  "0010011", TYPE_I, "000", ""},         //   2
    {"and",   "0110011", TYPE_R, "111", "0000000"},  //   3
    {"andi",  "0010011", TYPE_I, "111", ""},         //   4
    {"beq",   "1100011", TYPE_SB, "000", ""},        //   5
    {"bne",   "1100011", TYPE_SB, "001", ""},        //   6
    {"jal",   "1101111", TYPE_UJ, "",    ""},        //   7
    {"jalr",  "1100111", TYPE_I, "000", ""},         //   8
    {"auipc", "0010111", TYPE_U, "",    ""},         //   9
    {"lui",   "0110111", TYPE_U, "",    ""},         //   10
    {"lw",    "0000011", TYPE_I, "010", ""},         //   11
    {"xori",  "0010011", TYPE_I, "100", ""},         //   12
    {"or",    "0110011", TYPE_R, "110", "0000000"},  //   13
    {"ori",   "0010011", TYPE_I, "110", ""},         //   14
    {"sltiu", "0010011", TYPE_I, "011", ""},         //   15
    {"sltu",  "0110011", TYPE_R, "011", "0000000"},  //   16
    {"slli",  "0010011", TYPE_I, "001", "0000000"},  //   17
    {"srli",  "0010011", TYPE_I, "101", "0000000"},  //   18
    {"sw",    "0100011", TYPE_S, "010", ""},         //   19
    {"blt",   "1100011", TYPE_SB, "100", ""},        //   20
    {"bge",   "1100011", TYPE_SB, "101", ""},        //   21
};

symbol_t SYMBOL_TABLE[MAX_SYMBOL_TABLE_SIZE]; // Global symbol table

uint32_t symbol_table_cur_index = 0; // For indexing of symbol table

/* Temporary file stream pointers */
FILE *data_seg;
FILE *text_seg;

/* Size of each section */
uint32_t data_section_size = 0;
uint32_t text_section_size = 0;

/******************************************************
 * Function Declaration
 *******************************************************/

/* Add symbol to global symbol table */
void symbol_table_add_entry(symbol_t symbol)
{
    SYMBOL_TABLE[symbol_table_cur_index++] = symbol;
#if DEBUG
    printf("%s: 0x%08x\n", symbol.name, symbol.address);
#endif
}

/* Record .text section to output file */
void record_text_section(FILE *output)
{
    // print text section
    uint32_t cur_addr = MEM_TEXT_START;
    char line[1024];

    /* Point to text_seg stream */
    rewind(text_seg);

    /* Print .text section */
    while (fgets(line, 1024, text_seg) != NULL) {
        char inst[0x1000] = {0};
        char *temp, *imm_bits;
        int i, idx = 0;
        inst_type_t type = TYPE_UNKNOWN;
        char op[32] = {0};
        char label[32] = {0};
        int addr;
        int rs2, rs1, rd, imm;

        /* blank */

    }
}

/* Record .data section to output file */
void record_data_section(FILE *output)
{
    uint32_t cur_addr = MEM_DATA_START;
    char line[1024];

    /* Point to data segment stream */
    rewind(data_seg);

    /* Print .data section */
    while (fgets(line, 1024, data_seg) != NULL) {
         
        /* blank */

#if DEBUG
        printf("0x%08x: ", cur_addr);
        printf("%s", line);
#endif

    }
}

/* Fill in the blank */
void make_binary_file(FILE *output)
{
#if DEBUG
    char line[1024] = {0};
    rewind(text_seg);
    /* Print line of text segment */
    while (fgets(line, 1024, text_seg) != NULL) {
        printf("%s",line);
    }
    printf("\ntext size: %d, data size: %d\n", text_section_size, data_section_size);
#endif

    /* blank */
    
}

/* Fill in the blank */
void make_symbol_table(FILE *input)
{
    char line[1024] = {0};
    uint32_t *section_size = NULL;
    uint32_t address = 0;

    enum section cur_section = MAX_SIZE;

    /* Read each section and put the stream */
    while (fgets(line, 1024, input) != NULL) {

        /* blank */

    }
}
