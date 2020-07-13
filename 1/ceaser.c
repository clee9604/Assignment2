#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *str1;
	FILE *str2;
	char filename[100];
	char c;

	int key = 9;


	printf("Enter the filename to open for read\n");
	scanf("%s", filename);
	str1 = fopen(filename, "r");
	if(str1 == NULL)
	{
		printf("Cannot open file");
		exit(0);
	}


	printf("Enter the filename to open for writing\n");
	scanf("%s", filename);
	str2 = fopen(filename, "w");
	if(str2 == NULL)
	{
		printf("Cannot open file");
		exit(0);
	}

	c = fgetc(str1);

	while (c != EOF)
	{
		if (c >= 65 && c <= 90)
		{
			c = ((c +32) + key -97) % 26 + 97;
			fputc(c, str2);
		}
		else if (c >= 97 && c <= 122)
		{
			c = (c + key -97) % 26 +97;
			fputc(c, str2);
		}
		else
		{
			c = c;
			fputc(c, str2);
		}
		c = fgetc(str1);
	}


	printf("contents copied to ", filename);

	fclose(str1);
	fclose(str2);

	return 0;
}	
