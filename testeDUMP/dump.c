#include <stdio.h>

int main (int argc, char *argv[])
{
	FILE *stream;
	size_t buffer, size;
	void *ptr;	

	if ( argc < 2 )
	{
		fprintf(stderr, "Nenhum parâmetro foi passado, veja \"dump --help\"\n");
	}

	stream = fopen(argv[1], "r");
	if ( stream = NULL )
	{
		fprintf(stderr, "Arquivo não encontrado");
	}
	
	buffer = fread(ptr, 1, 5, stream);
//	if ( buffer = 0 )
//	{
//		fprintf(stderr, "Arquivo não encontrado");
//	}
	printf("%s\n", ptr);
	
	
}
