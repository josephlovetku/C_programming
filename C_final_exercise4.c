#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSubstr(char *s, char *t);

int main()
{
	int result = 0;
	char str1[] = "abcdefg";
	char str2[] = "efg"; 
	int size = strlen(str1);
	result = isSubstr(str1, str2);
	
	if (result == 0) {
		printf("%s is NOT a substring of %s\n", str2, str1);
	} else {
		printf("%s is a substring of %s\n", str2, str1);
	}
}

int isSubstr(char *s, char *t)
{
	int i, j;
	int match = 0;
	int found = 0;
	
	int size_s = strlen(s);
	int size_t = strlen(t);
	
	if (size_s < size_t) 
		return 0;
		
	for (i=0; i<size_s; i++) {
		match = 0;
		for (j=0; j<size_t; j++) {
			if (s[i+j] == t[j]) {
				match++;
			} else {
				break;
			}
		}
		if (match == size_t) return 1;
	}
	return 0;
}
