#include <stdio.h>
#include <glob.h>
#include <string.h>

glob_t log_find(char *search, glob_t *globbuf)
{
	glob(search, GLOB_DOOFFS, NULL, globbuf);
	return *globbuf;

//	glob(search, GLOB_DOOFFS, NULL, &globbuf);
//	glob("*.tt", GLOB_DOOFFS | GLOB_APPEND, NULL, &globbuf);
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
	char ptr[100];
	char *token, *saveptr, *str1;
	char *delim = " ";
	int comp, j;

	open = fopen(globbuf.gl_pathv[1], "r");

	fread(ptr,100,1,open);
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
	
/*	cmp = strtok_r(str1, " ", &saveptr);
	comp = strcmp("ok", cmp);
	printf("%d\n", comp);

	str1 = NULL;
	cmp = strtok_r(str1, " ", &saveptr);
	comp = strcmp("ok", cmp);
	printf("%d\n", comp);
*/
	fclose(open);

	return 0;
	
}

int main(int argc, char *argv[])
{
	glob_t globbuf;
	char *search = "tmp";
//	char *filename = argv[1];

	log_find(search, &globbuf);
	print_result(globbuf);
	check_file(globbuf);

	return 0;
}
