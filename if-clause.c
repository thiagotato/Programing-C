#include <stdio.h>

int main (int argc, char *argv[])
{
	char buffer[10];
	
	if (argc < 2)
	{
		printf("Usage: we need an option.\n");
		exit(1);
	}
	
	strncpy(buffer,argv[1],9);

	if (!strcmp(buffer,"/?"))
		printf("They want help.\n");

	else if (!strcmp(buffer,"/A"))
		printf("Option A\n");
	
	else if (!strcmp(buffer,"/b"))
		printf("Option B\n");
	
	else
		printf("Unknown Option\n");
}
