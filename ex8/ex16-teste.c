#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

struct person
{
	char *name;
	int age, height, weight;
};

struct person person_create(char *name, int age, int height, int weight)
{
	struct person who;

	who.name = strdup(name);
	who.age = age;
	who.height = height;
	who.weight = weight;
	
	return who;
}


void person_print(struct person who)
{
	printf("Name: %s\n", who.name);
	printf("\tAge: %d\n", who.age);
	printf("\tHeight: %d", who.height);
	printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char *argv[])
{
	struct person joe = person_create("Joe Alex", 32, 40, 140);

	struct person frank = person_create("Frank Blank", 20, 72, 180);

//	printf("Joe is at memory location %p\n", joe);
	person_print(joe);

//	printf("Frank is at memory location %p\n", frank);
	person_print(frank);

	joe.age += 20;
	joe.height -= 2;
	joe.weight += 40;
	person_print(joe);

	frank.age += 20;
	frank.weight += 20;
	person_print(frank);


	return 0;

}
