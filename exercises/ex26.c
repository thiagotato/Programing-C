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

int check_file(glob_t globbuf)
{
	FILE *open;
	char *ptr, *token, *saveptr, *str1;
	char *delim = " ";
	int comp, j, rc;

	ptr = malloc(sizeof(char));
	fseek();
	ftell();
	check_mem(ptr);

	open = fopen(globbuf.gl_pathv[1], "r");

	rc = fread(ptr,100,1,open);
	check(rc = 1, "Could't read this file");

	printf(" %s\n", ptr);
	
	for (j = 1, str1 = ptr; ; j++, str1 = NULL) 
	{
		token = strtok_r(str1, delim, &saveptr);
		if (token == NULL)
		    break;
		printf("%d: %s\n", j, token);
			comp = strcmp("thiago",token);
			printf("Encontrado: %d\n", comp);
	}
	
	fclose(open);

	return 0;

error:
	globfree(&globbuf);
	free(ptr);
	return -1;
	
}

int main(int argc, char *argv[])
{
	glob_t globbuf;

	log_find(&globbuf);
	check( globbuf.gl_pathc != 0, "File not found");
	print_result(globbuf);
	check_file(globbuf);

	return 0;

error:
	globfree(&globbuf);
	return -1;
}
