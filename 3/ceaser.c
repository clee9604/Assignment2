#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *str1;
	FILE *str2;
	char filename[100];
	char c;

	int key = 0;


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

	int i;
	int count[26];

	for (i = 0; i < 26; i++)
	{
		count[i] = 0;
	}	

	for(c =	fgetc(str1); c != EOF; c = fgetc(str1))
	{
		 if (c >= 65 && c <= 90)
                 {
			count[c-65]++;
                 }
                 else if (c >= 97 && c <= 122)
                 {
                        count[c-97]++;
                 }
	}

	int j;
	int key1 = 0;
	int key2 = 0;

	for (i = 0; i < 26; i++)
        {	
		if( count[i] > count[key])
		{
			key2 = key1;
			key1 = key;
			key = i;
		}
        }

	for( i =0; i <3; i++)
	{
		if ( i == 1)
		{
			key = key1;
		}
		if ( i == 2)
		{
			key = key2;
		}	
	
	printf("\n\nOur key: %d", key);
	rewind(str1);

	for(c = fgetc(str1); c != EOF; c = fgetc(str1))
	{
		if (c >= 65 && c <= 90)
		{
			if (( c-65 -key) <0)
			{
				c = c+ 26;
			} 
			c = ((c - 65) -  key) % 26 + 97;
			fputc(c, str2);
			printf("%c", c);
		}
		else if (c >= 97 && c <= 122)
		{
			if (( c-97 -key) <0)
                        {
                                c = c+ 26;
                        }

			c = ((c - 97) - key) % 26 + 97;
			fputc(c, str2);
			printf("%c", c);
		}
		else
		{
			c = c;
			fputc(c, str2);
			printf("%c", c);
		}
	}

	}
	printf("contents copied to ", filename);

	fclose(str1);
	fclose(str2);

	return 0;
}	
