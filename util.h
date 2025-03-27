/***************************************************************/
/*                                                             */
/*   RISC-V (RV32I) assembler                                  */
/*                                                             */
/*   KECE343/COMM307 Korea University                          */
/*   util.h                                                    */
/*                                                             */
/***************************************************************/

/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
/*          DO NOT MODIFY THIS FILE!                            */
/*          You should only assembler.c file!                   */
/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Functions */
char* num_to_bits(unsigned int num, int len);
char* change_file_ext(char *str);

#endif