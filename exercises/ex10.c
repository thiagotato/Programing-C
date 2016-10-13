#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas"
	};

	argc = 2;
	argv[1] = states[0];
//	printf("%d\n",argc);
	for (i=1; i < argc;i++)
	{
		printf("arg %d: %s\n",i, argv[i]);
	}

	int num_states = 4;

	for (i=0; i < num_states;i++)
	{
		printf("State %d: %s\n\n\n",i,states[i]);
	}

    printf("NULL is %p\n",(int *)NULL);
    printf("\\0 is %d\n",'\0');
    printf("Size of int = %ld\n",sizeof(int));
    printf("Size of NULL = %ld\n",sizeof(NULL));
	

	return 0;

}
