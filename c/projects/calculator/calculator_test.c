/****************************
 * Author: Dandan Ogni		*
 * Reviewer: 				*
 * Revision: 				*
 * Status: 					*
 ****************************/

/******************************************************************************/

/****************
 * HEADER FILES	*
 ****************/

#include <stdio.h> /* printf */
#include <assert.h> /* assert */
#include <ctype.h> /* isdigit, isspace */
#include <math.h> /* pow */

#include "calculator.h" /* calculator API */

/******************************************************************************/

/****************
 * TOGGLE ZONE	*
 ****************/

/************************
 * END OF TOGGLE ZONE	*
 ************************/

/******************************************************************************/

/************
 * MACRO	*
 ************/
#define PASS(str) printf("\033[0;32m%s\033[0m\n", #str)

#define Expect(x) \
{\
	if (!(x))\
	{\
		printf("Test failed for ret_val %d sum %f at line %d\n", ret_val, sum, __LINE__);\
		return 0;\
	}\
} /* end of Expect */

#define ExpectMain(x, str) \
{\
	if (!(x))\
	{\
		printf("Test failed for %s\n", str);\
	}\
} /* end of ExpectMain */

#define UNUSED(x) ((void)(x))

/******************************************************************************/

/************************
 * FUNCTION DECLARATION	*
 ************************/

static int CheckAddition();
static int CheckSubtitution();
static int CheckMultiplication();
static int CheckDivisionSuccess();
static int CheckDivisionFail();
static int CheckPowerSuccess();
static int CheckPowerFail();

static int CheckInvalidExpressions();

static int CheckVariousBasicExpressions();
static int CheckParentheseExpressions();
static int CheckComplexExpression();


/******************************************************************************/

/************************
 * FUNCTION DEFINITION	*
 ************************/

int main()
{
	ExpectMain(CheckAddition(), "CheckAddition");
	ExpectMain(CheckSubtitution(), "CheckSubtitution");
	ExpectMain(CheckMultiplication(), "CheckMultiplication");
	ExpectMain(CheckDivisionSuccess(), "CheckDivisionSuccess");
	ExpectMain(CheckDivisionFail(), "CheckDivisionFail");
	ExpectMain(CheckInvalidExpressions(), "CheckInvalidExpressions");
	ExpectMain(CheckVariousBasicExpressions(), "CheckVariousBasicExpressions");
	ExpectMain(CheckParentheseExpressions(), "CheckParentheseExpressions");
	ExpectMain(CheckPowerSuccess(), "CheckPowerSuccess");
	ExpectMain(CheckPowerFail(), "CheckPowerFail");
	ExpectMain(CheckComplexExpression(), "CheckComplexExpression");

	return 0;
}

static int CheckAddition()
{
	int ret_val = 0;
	double sum = 0;

	char str[] = "	4+   9.23";

	ret_val = Calculator(str, &sum);
	Expect(CALC_SUCCESS == ret_val);
	Expect((4 + 9.23) == sum);

	return 1;
}

static int CheckSubtitution()
{
	int ret_val = 0;
	double sum = 0;

	char str[] = "13.2-9";

	ret_val = Calculator(str, &sum);
	Expect(CALC_SUCCESS == ret_val);
	Expect((13.2 - 9) == sum);

	return 1;
}

static int CheckMultiplication()
{
	int ret_val = 0;
	double sum = 0;

	char str[] = "165 * 15.7";

	ret_val = Calculator(str, &sum);
	Expect(CALC_SUCCESS == ret_val);
	Expect((165 * 15.7) == sum);

	return 1;
}

static int CheckDivisionSuccess()
{
	int ret_val = 0;
	double sum = 0;

	char str[] = "			14.234/ 12.2";

	ret_val = Calculator(str, &sum);
	Expect(CALC_SUCCESS == ret_val);
	Expect((14.234 / 12.2) == sum);

	return 1;
}

static int CheckDivisionFail()
{
	int ret_val = 0;
	double sum = 0;

	char str[] = "	 	14.234/0";

	ret_val = Calculator(str, &sum);
	Expect(CALC_ERR_INVALID_CALCULATION == ret_val);

	return 1;
}

static int CheckInvalidExpressions()
{
	int ret_val = 0;
	double sum = 0;
	size_t i = 0;

	char *str[] = {
	"", "3 + 8 / 7 + A", "3.5 * 3.4.2 + 5", "5.2 + 2 .3", "3.5 * * 2.3",
	"2.2 +++ 2.3", "3 + (5 + 7) / (2 + (3 + 2)", "2 / 7 ) + 3",
	"2 ( + 3 / 2)", "(2 + 3 / ) 7"
	"3 + (5 + 7) / (2 + (3 + 2)"
	};

	for (i = 0; i < (sizeof(str) / sizeof(char *)); ++i)
	{
		ret_val = Calculator(str[i], &sum);
		Expect(CALC_ERR_INVALID_EXPRESSION == ret_val);
	}

	return 1;
}

static int CheckVariousBasicExpressions()
{
	int ret_val = 0;
	double sum = 0;

	{
		char *str = "1.2+2-3.3*52/7+2";
		ret_val = Calculator(str, &sum);
		Expect(CALC_SUCCESS == ret_val);
		Expect((1.2+2-3.3*52/7+2) == sum);
	}
	{
		char *str = "32   ";
		ret_val = Calculator(str, &sum);
		Expect(CALC_SUCCESS == ret_val);
		Expect((32) == sum);
	}
	{
		char *str = "-52.1 + +5 / 2";
		ret_val = Calculator(str, &sum);
		Expect(CALC_SUCCESS == ret_val);
		Expect(((-52.1) + 5.0/2.0) == sum);
	}
	{
		char *str = "1 + 2 * 5 - 3 / -0.0 + 3";
		ret_val = Calculator(str, &sum);
		Expect(CALC_ERR_INVALID_CALCULATION == ret_val);
	}

	return 1;
}

static int CheckParentheseExpressions()
{
	
	int ret_val = 0;
	double sum = 0;

	{
		char *str = "(1)";
		ret_val = Calculator(str, &sum);
		Expect(CALC_SUCCESS == ret_val);
		Expect((1) == sum);
	}

	{
		char *str = "(1 + 1)";
		ret_val = Calculator(str, &sum);
		Expect(CALC_SUCCESS == ret_val);
		Expect((1 + 1) == sum);
	}

	{
		char *str = "(((((((1 + 2)))))))";
		ret_val = Calculator(str, &sum);
		Expect(CALC_SUCCESS == ret_val);
		Expect((1 + 2) == sum);
	}

	{
		char *str = "(1 + ((2 * 5) - 3) / -0.0 + 3)";
		ret_val = Calculator(str, &sum);
		Expect(CALC_ERR_INVALID_CALCULATION == ret_val);
	}

	{
		char *str = "(1.2+(2)-(3.3*(52)/(7+2)))";
		ret_val = Calculator(str, &sum);
		Expect(CALC_SUCCESS == ret_val);
		Expect((1.2+(2)-(3.3*(52)/(7+2))) == sum);
	}

	return 1;
}

static int CheckPowerSuccess()
{
	int ret_val = 0;
	double sum = 0;

	char str[] = " 8.3 ^ -2.5 ";

	ret_val = Calculator(str, &sum);
	Expect(CALC_SUCCESS == ret_val);
	Expect((pow(8.3, -2.5) == sum));

	return 1;
}

static int CheckPowerFail()
{
	int ret_val = 0;
	double sum = 0;

	{
		char str[] = " -8.3 ^ 2.5 ";

		ret_val = Calculator(str, &sum);
		Expect(CALC_ERR_INVALID_CALCULATION == ret_val);
	}

	{
		char str[] = " -0 ^ 0 ";

		ret_val = Calculator(str, &sum);
		Expect(CALC_ERR_INVALID_CALCULATION == ret_val);
	}

	{
		char str[] = " 0 ^ -2 ";

		ret_val = Calculator(str, &sum);
		Expect(CALC_ERR_INVALID_CALCULATION == ret_val);
	}

	return 1;
}

static int CheckComplexExpression()
{
	int ret_val = 0;
	double sum = 0;
	char str[] = " 1.001 ^ (2.3 * -7*(-6 /3.12))+  +2 ^ 3.256 ^ 0.78";

	ret_val = Calculator(str, &sum);
	Expect(CALC_SUCCESS == ret_val);
	Expect((pow(1.001, (2.3 * -7 * (-6 / 3.12))) + pow(2, pow(3.256, 0.78))) == sum);

	return 1;
}
