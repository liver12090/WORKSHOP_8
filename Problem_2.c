#include<stdio.h>
#include<string.h>
#include<ctype.h>
int exist(char *file)
{
	int existed = 0;
	FILE* f=fopen(file,"r");
	if(f!=NULL)
	{
		existed=1;
		fclose(f);
	}
	return existed;
}
int writeFile(char *filename)
{
	if(exist(filename)==1)
	{
		printf("The file %s existed. Override it Y/N? :",filename);
		if(toupper(getchar())=='N') return 0;
	}
	char line[201];
	int lenght=0;
	FILE *f=fopen(filename,"w");
	fflush(stdin);
	do
	{
		gets(line);
		lenght=strlen(line);
		if (lenght>0)
		{
			fputs(line,f);
			fputs("\n",f);
		}
	}while(lenght>0);
	fclose(f);
	return 1;
}
int printFile(char* filename)
{
	char c;
	if(exist(filename)==0)
	{
		printf("The file %s does not exist.\n",filename);
		return 0;
	}
	FILE *f= fopen(filename,"r");
	while((c=fgetc(f))!=EOF) putchar(c);
	fclose(f);
	return 1;
}

int main(int argc, char*argv[])
{
	char filename[81];
	printf("Program for writing then reding afile\n");
	printf("Enter a filename:");
	gets(filename);
	printf("Write file: \n");
	if(writeFile(filename)==1)
	{
		printf("Data in the file %s: \n",filename);
		if(printFile(filename)==0) printf("File error!\n");
	}
	else printf("Writing file fail!\n",filename);
	getchar();
	return 0;
}