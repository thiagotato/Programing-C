#include<stdio.h>

int main(int argc, char *argv[])
{

	int i = 1;
	char *test[] =
	{
		"California", "Oregon",
		"Washington", "Texas"
	};

	while(i < argc)
	{
		test[i] = argv[i];
		printf("arg %d: %s\n", i, test[i]);
		i++;
		printf("arg %d: %s\n", i, test[i]);
	}
	
	char *states[] =
	{
		"California", "Oregon",
		"Washington", "Texas"
	};
	
	int num_states = 4;
	i = 0;
	while(i < num_states)
	{
		printf("State %d: %s\n",i, states[i]);
		i++;
	}			

	return 0;

}
