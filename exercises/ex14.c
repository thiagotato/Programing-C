#include<stdio.h>
#include<ctype.h>
#include<string.h>

//int can_print_it(char ch);
void print_letters(int tam, char arg[]);

void print_arguments(int argc, char *argv[])
{
	int i = 0;
	size_t tam;

	for(i = 0; i < argc; i++)
	{
		tam = strlen(argv[i]);		
		print_letters(tam, argv[i]);
	}
}

void print_letters(int tam, char arg[])
{
	int i = 0;
	for(i = 0; i < tam; i++)
	{
		char ch = arg[i];

		if(isgraph(ch))
		{
			printf("'%c' == %d ", ch, ch);		
		}
		printf("\n");
	}
}

//int can_print_it(char ch)
//{
//	return isalpha(ch) || isblank(ch);
//}

int main(int argc, char *argv[])
{
	print_arguments(argc, argv);
	return 0;
}

