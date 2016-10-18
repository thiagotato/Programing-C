#include <stdio.h>
#include <glob.h>

int main(int argc, char *argv[])
{
	glob_t globbuf;
	char *search = "/tmp/*.tmp";
	
	glob(search, GLOB_DOOFFS, NULL, &globbuf);
	glob("*.tt", GLOB_DOOFFS | GLOB_APPEND, NULL, &globbuf);

	printf("Encontrado: %s, total: %ld \n", globbuf.gl_pathv[2], globbuf.gl_pathc);
	
}
