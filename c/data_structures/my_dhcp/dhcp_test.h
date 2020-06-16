#include <assert.h> /*assert*/
#include <stdio.h>  /*printf*/
#include <limits.h> /* CHAR_BIT, UCHAR_MAX */
#include <math.h>   /* pow */
#include <string.h> /* memcmp */

#include "dhcp.h"

#define RED   "\x1B[0;31m"
#define BRED   "\x1B[1;31m"
#define GRN   "\x1B[0;32m"
#define BGRN   "\x1B[1;32m"
#define YEL   "\x1B[0;33m"
#define BYEL   "\x1B[1;33m"
#define BLU   "\x1B[0;34m"
#define BBLU   "\x1B[1;34m"
#define MAG   "\x1B[0;35m"
#define BMAG   "\x1B[1;35m"
#define CYN   "\x1B[0;36m"
#define BCYN   "\x1B[1;36m"
#define WHT   "\x1B[0;37m"
#define BWHT   "\x1B[1;37m"
#define RESET "\x1B[0m"

/*printf(RED "a" RESET);*/
/*printf(GRN "a" RESET);*/
/*printf(YEL "a" RESET);*/
/*printf(BLU "a" RESET);*/
/*printf(MAG "a" RESET);*/
/*printf(CYN "a\n" RESET);*/

