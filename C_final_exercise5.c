#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *duplicate(const char *p)
{
	char *q = (char *)malloc(sizeof(char) * strlen(p)); 

	strcpy(q, p); 
	return q;
}

int main()
{
	char str1[] = "abcde";
	char *str2 = duplicate(str1);
	printf("str1 = %s\nstr2 = %s\n", str1, str2);
	return 0;
}
