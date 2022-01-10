#include <ctype.h>
/* atoi: convert s to integer; version 2 */

int atoi(char string[]); // a function which translation characters into numerical value

int main()
{
	char testString[100] = "12345";
	printf("The number is %d\n", atoi(testString));
	return 0;
}

int atoi(char s[])
{
	int i, n, sign;
	
	for (i = 0; isspace(s[i]); i++); /* skip white space */
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') /* skip sign */
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}
