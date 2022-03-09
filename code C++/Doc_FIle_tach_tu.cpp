#include <stdio.h>
#include <istream.h>
#include <string.h>

char *p;
int main(int argc, char *argv[])
{
	FILE *fin;
	int n = 0;
	char code[10];
	char name[100], line[100];
	char add[100];
	char birth[100];

	fin = fopen("E:\\PERSON.TXT", "r");
	if(fin==NULL)
	{
		printf("\n File khong ton tai");
		return 0;
	}
	while(!feof(fin))
		{
			fgets(line, 100,fin);
			p = strtok(line,":");
			strcpy(code,p);
			p = strtok(NULL,":");
			strcpy(name,p);
			p = strtok(NULL,":");
			strcpy(add,p);
			p = strtok(NULL,":");
			strcpy(birth,p);
			// Hien thi
			printf("\n code: %s", code);
			printf("\n name: %s", name);
			printf("\n add: %s", add);
			printf("\n birth: %s", birth);
			printf("\n");
		}
	
	fclose(fin);
	
	return 0;
}