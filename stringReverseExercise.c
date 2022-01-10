#include <string.h>
/* reverse: reverse string s in place */

#include <stdio.h>

void reverse(char string[]);

int main()
{
	char str[100]; 
	scanf("%s", str);
	reverse(str);
	return 0;
}

void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	printf("%s\n", s);
}
