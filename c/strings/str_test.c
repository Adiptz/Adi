#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "str.h"

void StrcpyTest();
void StrncpyTest();
void StrcasecmpTest();

int main()
{


printf("Strcmp \n:");
printf ("-1 : %d\n", Strcmp("1234","1254"));
printf (" 1  :  %d\n", Strcmp("1243","1234"));
printf (" 0  :  %d\n", Strcmp("1234","1234"));
printf ("-1  : %d\n", Strcmp("120","1204"));
printf (" 1  :  %d\n", Strcmp("1204","120"));
printf (" 1  :  %d\n", Strcmp("bac","abc"));


printf("\nStrlen\n");
printf(  "5  : %ld\n", Strlen("10590"));/* string with 0 */
printf(  "5  : %ld\n", Strlen("105 8"));/* string with spacebar */
printf(  "10 : %ld\n", Strlen("jsxdhtrtry"));/* regular 10 characters string */


printf("\nStrcpy\n");
StrcpyTest();

printf("\nStrncpy\n");
StrncpyTest();

printf("\nStrcasecmp\n");
StrcasecmpTest();

return 0;
}


void StrcpyTest()/* Strcpy */
{
	char a[] = {"hello, world!"};
	char a1[] = {"hi"};
	char b[]= {"hi"};
	char b1[] = {"hello, world!"};
	char c[] = {"     "};
	char c1[] = {"not empty"};
	char d[] = {"not empty"};
	char d1[] = {"     "};
	char aviv[]={"asdfdsadfdadfasdf"};
	char aviv1[]={'c','0','y','\0','d'};
	printf("hi : %s\n", Strcpy(aviv1,aviv));
	printf("hi : %s\n", Strcpy(a,a1));
	printf("hello, world! : %s\n", Strcpy(b,b1));
	printf("not empty : %s\n", Strcpy(c,c1));
	printf("      : %s\n", Strcpy(d,d1));
} 

void StrncpyTest() /* Strncpy */
{
	char a[] = {"hello, world!"};
	char a1[] = {"hi"};

	printf(" : %s\n", Strncpy(a,a1,3));
	printf("ISITWORK: %d\n, %d\n",a[5],a[6]); 

} 

void StrcasecmpTest()
{
	/*Test of 0*/
	char a[] = {"hI\n"};
	char a1[] = {"hi\n"};
	char b[] = {"Adi\n"};
	char b1[] = {"adi\n"};

	/*Test of 1*/
	char c[] = {"cnana\n"};
	char c1[] = {"bananab\n"};
	char d[] = {"gdi\n"};
	char d1[] = {"adi\n"};

	/*Test of -1*/
	char e[] = {"abc[\n"};
	char e1[] = {"abc{\n"};
	char f[] = {"A\n"};
	char f1[] = {"&\n"};
	char g[]={"9813549"};
	char g1[]={"9309715"};

	printf("zero :\n");
	printf("%d, ", Strcasecmp(a,a1));
	printf("%d\n", Strcasecmp(b,b1));
	printf("positive :\n");
	printf("%d, ", Strcasecmp(c,c1));
	printf("%d\n", Strcasecmp(d,d1));
	printf("negative :\n");
	printf("%d, ", Strcasecmp(e,e1));
	printf("%d\n", Strcasecmp(f,f1));
	printf("%d\n", Strcasecmp(g,g1));
}



