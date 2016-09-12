// Objetivo ler um arquivo passado por parametro e imprimir seu caracters em hexa



#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
FILE *stream;
char ptr[10];
size_t read;
void *tam;
int i, end;

	if(argc < 2)
	{
		fprintf(stderr,"Parametro nao identificado.\n");
		return 1;
	}
	
	stream = fopen(argv[1],"r");
	if(stream == NULL)
	{
		fprintf(stderr, "Arquivo não encontrado ou sem premissão de leitura");
		return 1;
	}
	
	if ( (fseek(stream,0,SEEK_END)) != 0)
	{
		fprintf(stderr, "Arquivo vazio");
		return 1;
	}
//	tam = malloc(stream);
	rewind(stream);
	read = fread(ptr,10,1,stream);
	//if (read == NULL)
	//{
		//fprintf(stderr, "Arquivo vazio");
	//	return 1;
// 	}
//	printf("%s read response", read);
	fclose(stream);
		
	for (i=0; i < 10 ; i++)
	{
	printf("%c\n", ptr[i]);
	}
}
