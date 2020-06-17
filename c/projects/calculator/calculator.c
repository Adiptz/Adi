/************************
*	Author   :  Adi     *
*	Reviewer :  Hay	    *
*	Status   : 	Fixed   *
*************************/

/********************* LIBARIES *******************/

#include <assert.h>  /*  assert  */
#include <math.h>    /*  pow     */
#include <string.h>  /*  strlen  */
#include <ctype.h>   /*  isdigit */
#include <stdlib.h>  /*  strtod  */

#include "calculator.h" /* calculate functions */
#include "stack.h"      /* stack functions */

#define UNUSED(x) (void)(x)
#define POW_PRECEDENCE 3
#define NUM_OF_STATE 2
#define RANGE_OF_OPERATORS 95
#define RANGE_OF_ASCII_TABLE 256

typedef unsigned int uint;
/********************** DECLERATIONS ********************/

/* action funcs*/
static calc_errno_t FoldBracket(char **exp, stack_t *stacks[]);
static calc_errno_t CheckIfUnary(char **exp, stack_t *stacks[]);
static calc_errno_t PushToNumStack(char **exp, stack_t *stacks[]);
static calc_errno_t PushToOpStack(char **exp, stack_t *stacks[]);
static calc_errno_t ErrInvalidExp(char **exp, stack_t *stacks[]);
static calc_errno_t IgnoreWhiteSpace(char **exp, stack_t *stacks[]);
static calc_errno_t FoldAllStack(char **exp, stack_t *stacks[]);
static calc_errno_t PushOpenBracket(char **exp, stack_t *stacks[]);
static calc_errno_t FoldByPrecedence(char **exp, stack_t *stacks[]);

/* calculate funcs*/
static calc_errno_t Addition(double left_exp, double right_exp, stack_t *stack);
static calc_errno_t Subtraction(double left_exp, double right_exp, stack_t *stack);
static calc_errno_t Multiply(double left_exp, double right_exp, stack_t *stack);
static calc_errno_t Division(double left_exp, double right_exp, stack_t *stack);
static calc_errno_t Pow(double left_exp, double right_exp, stack_t *stack);
static calc_errno_t OPInvalidExp(double left_exp, double right_exp, stack_t *stack);

/* others */
static calc_errno_t CreateStacks(stack_t *stacks[], size_t length);
static void DestroyStacks(stack_t *stacks[]);
static void PromoteExpression(char **exp);
static char GetTopOperator(stack_t *stack); 
static double GetTopNumber(stack_t *stack);
static int IsFoldNeeded(int op_precedence, stack_t *stack);
static calc_errno_t PushOp(char **exp, stack_t *stacks[]);

/********************** STRUCTS ********************/
enum stacks{NUM, OPERATOR};

typedef enum states
{
	WAIT_FOR_NUM, 
	WAIT_FOR_OPERATOR,
	ERROR,
	END
} state_t;

typedef struct transition 
{
	state_t next_state;
	calc_errno_t (*action_func)(char **exp, stack_t *stacks[]);
} transition_t;

typedef struct operator
{
	calc_errno_t (*calc_func)(double left_expression,
							  double right_expression,
							  stack_t *stack);
	int precedence;
}  operator_t;

/********************** LUTS ********************/
static stack_t *stacks[] = {NULL};

calc_errno_t (*LUT_PRECEDENCE[])() = {FoldByPrecedence, PushOp};

calc_errno_t (*LUT_UNARY[])() = {ErrInvalidExp, PushToNumStack};


operator_t LUT_OPERATORS[RANGE_OF_OPERATORS] =
{
	{NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0},    /*   0 - 4 */
	{NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0},	  /*  5 -  9 */
	{NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0},	  /* 10 - 14 */
	{NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0},	  /* 15 - 19 */
	{NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0},	  /* 20 - 24 */
	{NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0},	  /* 25 - 29 */
	{NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0},	  /* 30 - 34 */
	{NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0},	  /* 35 - 39 */
	{OPInvalidExp, 0}, {NULL, 0}, {Multiply, 2}, {Addition, 1}, {NULL, 0},/* 40 - 44 */
	{Subtraction, 1},{NULL, 0}, {Division, 2}, {NULL, 0},{NULL, 0},/* 45 - 49 */
	{NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0},	  /* 50 - 54 */
	{NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0},	  /* 55 - 59 */
	{NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0},	  /* 60 - 64 */
	{NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0},	  /* 65 - 69 */
	{NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0},	  /* 70 - 74 */
	{NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0},	  /* 75 - 79 */
	{NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0},	  /* 80 - 84 */
	{NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0},	  /* 84 - 89 */
	{NULL, 0}, {NULL, 0}, {NULL, 0}, {NULL, 0}, {Pow, 3}	  /* 90 - 94 */
};


transition_t TRANSITION_LUT[RANGE_OF_ASCII_TABLE][NUM_OF_STATE] = 
{ 
 /*WAIT_FOR_NUM*/		  /*WAIT_FOR_OPERATOR*/
 {{ERROR, ErrInvalidExp}, {END, FoldAllStack}},    /*0*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*1*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*2*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*3*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*4*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*5*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*6*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*7*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*8*/
 {{WAIT_FOR_NUM, IgnoreWhiteSpace}, {WAIT_FOR_OPERATOR, IgnoreWhiteSpace}}, /*TAB*/
 {{WAIT_FOR_NUM, IgnoreWhiteSpace}, {WAIT_FOR_OPERATOR, IgnoreWhiteSpace}}, /*10*/
 {{WAIT_FOR_NUM, IgnoreWhiteSpace}, {WAIT_FOR_OPERATOR, IgnoreWhiteSpace}}, /*11*/
 {{WAIT_FOR_NUM, IgnoreWhiteSpace}, {WAIT_FOR_OPERATOR, IgnoreWhiteSpace}}, /*12*/
 {{WAIT_FOR_NUM, IgnoreWhiteSpace}, {WAIT_FOR_OPERATOR, IgnoreWhiteSpace}}, /*13*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*14*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*15*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*16*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*17*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*18*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*19*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*20*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*21*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*22*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*23*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*24*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*25*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*26*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*27*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*28*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*29*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*30*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*31*/
 {{WAIT_FOR_NUM, IgnoreWhiteSpace}, {WAIT_FOR_OPERATOR, IgnoreWhiteSpace}}, /*SPACE*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*33*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*34*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*35*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*36*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*37*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*38*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*39*/
 {{WAIT_FOR_NUM, PushOpenBracket},         {ERROR, ErrInvalidExp}},           /* ( */
 {{ERROR, ErrInvalidExp},              {WAIT_FOR_OPERATOR, FoldBracket}}, /* ) */ 
 {{ERROR, ErrInvalidExp},              {WAIT_FOR_NUM, FoldByPrecedence}},   /* * */
 {{WAIT_FOR_OPERATOR, CheckIfUnary},   {WAIT_FOR_NUM, FoldByPrecedence}},   /*+*/
 {{ERROR, ErrInvalidExp},              {ERROR, ErrInvalidExp}},           /*44*/
 {{WAIT_FOR_OPERATOR, CheckIfUnary},   {WAIT_FOR_NUM, FoldByPrecedence}},  /* - */
 {{WAIT_FOR_OPERATOR, PushToNumStack}, {ERROR, ErrInvalidExp}}, /*.*/
 {{ERROR, ErrInvalidExp},              {WAIT_FOR_NUM, FoldByPrecedence}},       /*/*/
 {{WAIT_FOR_OPERATOR, PushToNumStack}, {ERROR, ErrInvalidExp}}, /*0*/
 {{WAIT_FOR_OPERATOR, PushToNumStack}, {ERROR, ErrInvalidExp}}, /*1*/
 {{WAIT_FOR_OPERATOR, PushToNumStack}, {ERROR, ErrInvalidExp}}, /*2*/
 {{WAIT_FOR_OPERATOR, PushToNumStack}, {ERROR, ErrInvalidExp}}, /*3*/
 {{WAIT_FOR_OPERATOR, PushToNumStack}, {ERROR, ErrInvalidExp}}, /*4*/
 {{WAIT_FOR_OPERATOR, PushToNumStack}, {ERROR, ErrInvalidExp}}, /*5*/
 {{WAIT_FOR_OPERATOR, PushToNumStack}, {ERROR, ErrInvalidExp}}, /*6*/
 {{WAIT_FOR_OPERATOR, PushToNumStack}, {ERROR, ErrInvalidExp}}, /*7*/
 {{WAIT_FOR_OPERATOR, PushToNumStack}, {ERROR, ErrInvalidExp}}, /*8*/
 {{WAIT_FOR_OPERATOR, PushToNumStack}, {ERROR, ErrInvalidExp}}, /*9*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*58*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*59*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*60*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*61*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*62*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*63*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*64*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*65*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*66*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*67*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*68*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*69*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*70*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*71*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*72*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*73*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*74*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*75*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*76*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*77*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*78*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*79*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*80*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*81*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*82*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*83*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*84*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*85*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*86*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*87*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*88*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*89*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*90*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*91*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*92*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*93*/
 {{ERROR, ErrInvalidExp}, {WAIT_FOR_NUM, PushToOpStack}}, /*^*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*95*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*96*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*97*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*98*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*99*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*100*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*101*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*102*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*103*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*104*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*105*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*106*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*107*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*108*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*109*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*110*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*111*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*112*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*113*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*114*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*115*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*116*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*117*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*118*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*119*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*120*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*121*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*122*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*123*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*124*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*125*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*126*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*127*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*128*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*129*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*130*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*131*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*132*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*133*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*134*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*135*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*136*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*137*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*138*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*139*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*140*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*141*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*142*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*143*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*144*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*145*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*146*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*147*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*148*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*149*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*150*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*151*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*152*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*153*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*154*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*155*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*156*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*157*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*158*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*159*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*160*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*161*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*162*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*163*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*164*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*165*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*166*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*167*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*168*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*169*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*170*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*171*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*172*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*173*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*174*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*175*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*176*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*177*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*178*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*179*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*180*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*181*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*182*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*183*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*184*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*185*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*186*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*187*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*188*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*189*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*190*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*191*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*192*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*193*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*194*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*195*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*196*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*197*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*198*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*199*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*200*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*201*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*202*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*203*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*204*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*205*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*206*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*207*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*208*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*209*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*210*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*211*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*212*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*213*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*214*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*215*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*216*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*217*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*218*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*219*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*220*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*221*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*222*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*223*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*224*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*225*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*226*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*227*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*228*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*229*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*230*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*231*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*232*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*233*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*234*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*235*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*236*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*237*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*238*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*239*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*240*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*241*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*242*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*243*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*244*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*245*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*246*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*247*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*248*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*249*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*250*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*251*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*252*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*253*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*254*/
 {{ERROR, ErrInvalidExp}, {ERROR, ErrInvalidExp}}, /*255*/
};



/**************************** -- MAIN PART -- *********************************/

calc_errno_t Calculator(const char *expression, double *result)
{	
	state_t current_state = WAIT_FOR_NUM;
	calc_errno_t return_status = CALC_SUCCESS;
	
	assert (NULL != expression);
	assert (NULL != result);
	
	/*if Create failed -> return_status will be CALC_FAILED_ALOC */	
	return_status = CreateStacks(stacks, strlen(expression)); 
	
	while (return_status == CALC_SUCCESS
		   && ERROR != current_state
		   && END != current_state)
	{
		state_t next_state = 0;
		
		next_state = TRANSITION_LUT[(uint)*expression] 
		                                             [current_state].next_state;
		
		return_status = TRANSITION_LUT
		[(uint)*expression][current_state].action_func
		                                         ((char **)&expression, stacks);
		
		current_state = next_state;
	}
	
	/* NUM stack can be empty in case of invalid exp / stacks creation failed */
	if(!StackIsEmpty(stacks[NUM])) 
	{                              
		*result = GetTopNumber(stacks[NUM]);
	}
	
	DestroyStacks(stacks);
		
	return return_status;
}


/****************************** -- ACTION FUNCS *******************************/

static calc_errno_t FoldSingleExp(char **exp, stack_t *stacks[])
{
	calc_errno_t return_status = CALC_SUCCESS;

	double right_exp = 0.0;
	double left_exp = 0.0;

	assert(NULL != stacks);
	assert(NULL != *exp);	
	UNUSED(exp);
	
	right_exp = GetTopNumber(stacks[NUM]);
	StackPop(stacks[NUM]);
	
	left_exp = GetTopNumber(stacks[NUM]);
	StackPop(stacks[NUM]);
			
	return_status = LUT_OPERATORS[(uint)GetTopOperator(stacks[OPERATOR])]. 
				                    calc_func(left_exp, right_exp, stacks[NUM]);
				                    
	StackPop(stacks[OPERATOR]);
	
	return return_status;
}

calc_errno_t FoldAllStack(char **exp, stack_t *stacks[])
{
	calc_errno_t return_status = CALC_SUCCESS;
	
	assert(NULL != stacks);
	assert(NULL != *exp);
		
	while (!StackIsEmpty(stacks[OPERATOR])
		   && CALC_SUCCESS == return_status)
	{
		return_status = FoldSingleExp(exp, stacks);
	}
		
	return return_status;
}


calc_errno_t FoldByPrecedence(char **exp, stack_t *stacks[])
{
	calc_errno_t return_status = CALC_SUCCESS;
	int new_op_precedence = 0;
	  
	assert(NULL != stacks);
	assert(NULL != *exp);
	
	new_op_precedence = LUT_OPERATORS[(uint)**exp].precedence;
		
	while ( CALC_SUCCESS == return_status
		    && (!StackIsEmpty(stacks[OPERATOR]))
		    && IsFoldNeeded(new_op_precedence, stacks[OPERATOR])) 
		    													  
	{
		return_status = FoldSingleExp(exp, stacks);
	}
	
	StackPush(stacks[OPERATOR], *exp);

	PromoteExpression(exp);
	
	return return_status;
}

static calc_errno_t FoldBracket(char **exp, stack_t *stacks[])
{
	calc_errno_t return_status = CALC_SUCCESS;
	
	assert(NULL != stacks);
	assert(NULL != *exp);
	
	while (CALC_SUCCESS == return_status
		   && (!StackIsEmpty(stacks[OPERATOR]))
		   && ('(' != GetTopOperator(stacks[OPERATOR])))
	{
		return_status = FoldSingleExp(exp, stacks);	
	}
	
	if (!StackIsEmpty(stacks[OPERATOR]))
	{
		StackPop(stacks[OPERATOR]);
		PromoteExpression(exp);
	}
	else /*	if there were no open-brackets before the closing brackets*/
	{
		return_status = CALC_ERR_INVALID_EXPRESSION;
	}
	
	return return_status;
}

calc_errno_t CheckIfUnary(char **exp, stack_t *stacks[])
{
	assert(NULL != stacks);
	assert(NULL != *exp);
	
	return LUT_UNARY[(0 < (isdigit(*(*exp + 1))))](exp, stacks);
}

calc_errno_t IgnoreWhiteSpace(char **exp, stack_t *stacks[])
{
	assert(NULL != stacks);
	assert(NULL != *exp);
	
	UNUSED(stacks);
	
	PromoteExpression(exp);
	
	return CALC_SUCCESS;
}

calc_errno_t ErrInvalidExp(char **exp, stack_t *stacks[])
{	
	assert(NULL != stacks);
	assert(NULL != *exp);
	
	UNUSED(exp);
	UNUSED(stacks);
		
	return CALC_ERR_INVALID_EXPRESSION;
}

static calc_errno_t OPInvalidExp(double left_exp,
								 double right_exp,
								 stack_t *stack)
{
	assert(NULL != stacks);
	
	UNUSED(right_exp);
	UNUSED(left_exp);
	UNUSED(stack);
		
	return CALC_ERR_INVALID_EXPRESSION;
}

calc_errno_t PushToNumStack(char **exp, stack_t *stacks[])
{
	double num_to_push = 0.0;
	
	assert(NULL != stacks);
	assert(NULL != *exp);
	
	num_to_push = strtod(*exp, exp);
	
	StackPush(stacks[NUM], &num_to_push);
	
	return CALC_SUCCESS;
}

calc_errno_t PushToOpStack(char **exp, stack_t *stacks[])
{
	calc_errno_t action_func_status = CALC_SUCCESS;
	
	assert(NULL != stacks);
	assert(NULL != *exp);
	
	if (StackIsEmpty(stacks[OPERATOR]))
	{
		StackPush(stacks[OPERATOR], *exp); 
	}
	else
	{
		action_func_status = 
        LUT_PRECEDENCE[LUT_OPERATORS[(uint)**exp].precedence >
        LUT_OPERATORS[(uint)GetTopOperator(stacks[OPERATOR])].precedence]
        (exp, stacks); /* arguments */
	}
	
	PromoteExpression(exp);
	
	return action_func_status;
}

calc_errno_t PushOp(char **exp, stack_t *stacks[])
{
	assert(NULL != stacks);
	assert(NULL != *exp);
	
	StackPush(stacks[OPERATOR], *exp);
	
	PromoteExpression(exp);
		
	return CALC_SUCCESS;
}

calc_errno_t PushOpenBracket(char **exp, stack_t *stacks[])
{
	assert(NULL != stacks);
	assert(NULL != *exp);  
	
	StackPush(stacks[OPERATOR], *exp);

	PromoteExpression(exp);
	
	return CALC_SUCCESS;
}

/************************* -- CALCULATE FUNCS -- ******************************/
calc_errno_t Addition(double left_exp, double right_exp, stack_t *stack)
{
	double result = 0.0;
	
	assert(NULL != stack);
	
	result = left_exp + right_exp;
	
	StackPush(stack, &result);
	
	return CALC_SUCCESS;	
}

calc_errno_t Subtraction(double left_exp, double right_exp, stack_t *stack)
{
	double result = 0.0;
	
	assert(NULL != stack);
	
	result = left_exp - right_exp;
	
	StackPush(stack, &result);
	
	return CALC_SUCCESS;
}

calc_errno_t Multiply(double left_exp, double right_exp, stack_t *stack)
{
	double result = 0.0;
	
	assert(NULL != stack);
	
	result = left_exp * right_exp;
	
	StackPush(stack, &result);
	
	return CALC_SUCCESS;
}

calc_errno_t Division(double left_exp, double right_exp, stack_t *stack)
{
	double result = 0.0;
	
	assert(NULL != stack);
	
	if (0 == right_exp)
	{
		return CALC_ERR_INVALID_CALCULATION;
	}
	
	result = left_exp / right_exp;
	
	StackPush(stack, &result);
	
	return CALC_SUCCESS;	
}

calc_errno_t Pow(double left_exp, double right_exp, stack_t *stack)
{
	double result = 0.0;
	
	if (((0 >= left_exp) || (0 == left_exp && 0 > right_exp)))
	{
		return CALC_ERR_INVALID_CALCULATION;
	}
	
	assert(NULL != stack);
	
	result = pow(left_exp, right_exp);
	
	StackPush(stack, &result);	
	
	return CALC_SUCCESS;		
}

/********************************* -- OTHERS -- *******************************/

static calc_errno_t CreateStacks(stack_t *stacks[], size_t length)
{
	stack_t *num_stack = NULL;
	stack_t *operator_stack = NULL;
	
	num_stack  = StackCreate(length, sizeof(double));
	if (NULL == num_stack)
	{
		return CALC_FAILED_ALOC;
	}
	
	operator_stack = StackCreate(length, sizeof(char));
	if (NULL == operator_stack)
	{
		StackDestroy(num_stack); num_stack = NULL;
		
		return CALC_FAILED_ALOC;
	}
	
	stacks[NUM] = num_stack;
	stacks[OPERATOR] = operator_stack;
	
	return CALC_SUCCESS;
}

static void DestroyStacks(stack_t *stacks[])
{
	StackDestroy(stacks[NUM]); stacks[NUM] = NULL;
	StackDestroy(stacks[OPERATOR]); stacks[OPERATOR] = NULL;
}

static int IsFoldNeeded(int op_precedence, stack_t *stack)
{
	UNUSED(stack);
	
    return ((POW_PRECEDENCE != op_precedence)
    		&& (LUT_OPERATORS[(unsigned int)GetTopOperator(stack)].precedence
    		   >= op_precedence));
}

static void PromoteExpression(char **exp)
{
	++*exp;
}

static char GetTopOperator(stack_t *stack) 
{
	assert(NULL != stack);

	return *(char *)StackPeek(stack);
}

static double GetTopNumber(stack_t *stack)
{
	assert(NULL != stack);

	return *(double *)StackPeek(stack);
}
