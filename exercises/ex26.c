#include <stdio.h>
#include <glob.h>
#include <string.h>
#include <stdlib.h>
#include "dbg.h"

glob_t log_find(glob_t *globbuf)
{
	glob("*.txt", GLOB_DOOFFS, NULL, globbuf);

	glob("*.log", GLOB_DOOFFS | GLOB_APPEND, NULL, globbuf);
	return *globbuf;
}

int print_result(glob_t globbuf)
{
	int i;

	printf("Total of results: %ld\n", globbuf.gl_pathc);
	for(i=1; i <= globbuf.gl_pathc; i++)
	{
		printf(" %s\n", globbuf.gl_pathv[i]);
	}
	
	return 0;
}

int check_file(glob_t globbuf, char *search)
{
	FILE *fh;
	char *ptr, *token, *str1, *saveptr;
	char *delim = " ";
	int comp, j, rc;
	long buff;
	size_t length;

	fh = fopen(globbuf.gl_pathv[1], "r");
	fseek(fh, 0, SEEK_END);
	buff = ftell(fh);
	ptr = malloc(buff);
	check_mem(ptr);
	rewind(fh);
	rc = fread(ptr,buff,1,fh);
	check(rc = 1, "Could't read this file");
	fclose(fh);

/*	printf(" %s\n", ptr);
	
	index = rindex(ptr, ind);
	printf("teste: %s\n", index); */
	
	for (j = 1, str1 = ptr; ; j++, str1 = NULL) 
	{
		token = strtok_r(str1, delim, &saveptr);
		if (token == NULL)
		    break;
		length = strlen(search);
//		printf("%d: %s\n", j, token);
		comp = strncmp(search, token, length);
		printf("Encontrado: %d\n", comp);
	}

	return 0;

error:
	globfree(&globbuf);
	free(ptr);
	return -1;	
}

int usage()
{
	printf("You are able to search into:\n*.txt\n*.log\n");

	return 0;
}

int main(int argc, char *argv[])
{
	glob_t globbuf;
	int i;
		
	if(argc == 1)
	{
		usage();
	}

	log_find(&globbuf);
	check( globbuf.gl_pathc != 0, "File not found");

	for(i=1; i < argc; i++)
	{
		check_file(globbuf, argv[i]);
	}
//	print_result(globbuf);

	return 0;

error:
	globfree(&globbuf);
	return -1;
}
