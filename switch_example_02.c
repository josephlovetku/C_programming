#include <stdio.h>

int main()
{
	int month; 
	while (scanf("%d", &month) != EOF) {
		switch (month) {
			case 3: case 4: case 5: 
				printf("It's spring\n");
				break;
			case 6: case 7: case 8: 
				printf("It's summer\n");
				break; 
			case 9: case 10: case 11:
				printf("It's autumn\n");
				break;
			case 12: case 1: case 2: 
				printf("It's winter.\n");
				break;
			default:
				printf("It's in your dream!\n");
				break;
		}
	}
	return 0;
}
