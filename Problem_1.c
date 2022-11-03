#include<stdio.h>
#include<ctype.h>
#define TRUE 1
#define FALSE 0
int exist(char *file)
{
	int existed = FALSE;
	FILE* f=fopen(file,"r");
	if(f!=NULL)
	{
		existed=TRUE;
		fclose(f);
	}
	return existed;
}

int writeFile(char *file)
{
	char c;
	int CTRL_Z=-1;
	if(exist(file)==TRUE)
	{
		printf("The file %s existed. Override it Y/N? :",file);
		if(toupper(getchar())=='N') return FALSE;
	}
	FILE *f=fopen(file,"w");
	fflush(stdin);
	do
	{
		c=getchar();
		if(c!=CTRL_Z) fputc(c,f);
	}while(c!=CTRL_Z);
	fclose(f);
	return TRUE;
}
int main(int argc, char *argv[])
{
	if(argc!=2) printf("Syntax: copy_con filename\n");
	else if(writeFile(argv[1])==TRUE)
	printf("Writing the file %s: done\n",argv[1]);
	else printf("Can nor write the file %s\n",argv[1]);
	return 0;
}