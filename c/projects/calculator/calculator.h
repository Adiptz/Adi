/******************************************************************************
 * Owner: OL712                                                               *
 * Reviewer: OL712                                                            *
 ******************************************************************************/

#ifndef ILRD_CALCULATOR_H
#define ILRD_CALCULATOR_H

typedef enum calc_errno
{
	CALC_SUCCESS,
	CALC_FAILED_ALOC,
	CALC_ERR_INVALID_CALCULATION,
	CALC_ERR_INVALID_EXPRESSION
}calc_errno_t;

/*
 * Calculates double based on <expression>.
 * @expression: non-empty null terminated string containing a mathematical 
 *				expression.
 *				a supported mathematical expression must be a valid expression
 *					and can include:
 *				double type numbers,
 *				the operators: '+', '-', '*', '/', '^',
 *				unary operators: '+', '-' before numbers,
 *				parentheses: '(', ')',
 *				white space between anything except unary operators and their
 *					operand. white space includes everything that is counted as
 *					space in the isspace function in <ctype.h> library.
 * return :in success returns CALC_SUCCESS and update result of <expression> 
 * in result, 
 * otherwise return calc_errno enum value and result is undefined.
 * errors : if error encountered,
 *			returns calc_errno enum value accordingly.
 *			if <expression> is not null terminated, behaviour is undefined.
 */
calc_errno_t Calculator(const char *expression, double *result);

#endif /* ILRD_CALCULATOR_H */
