#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct Person
{
	char name[30];
	unsigned int weight;
	unsigned char gender;
	struct list_head list;
};

int main()
{
	struct Person personList;
	INIT_LIST_HEAD(&personList.list);

	struct Person* aNewPersonPointer;

	aNewPersonPointer = malloc(sizeof(*aNewPersonPointer));
	strcpy(aNewPersonPointer->name, "roman10");
	aNewPersonPointer->weight = 130;
	aNewPersonPointer->gender = 1;
	INIT_LIST_HEAD(&aNewPersonPointer->list);


	list_add(&aNewPersonPointer->list, &personList.list);


	struct Person* aNewPersonPointer2;
	aNewPersonPointer2 = malloc(sizeof(*aNewPersonPointer));
	strcpy(aNewPersonPointer2->name, "roman20");
	aNewPersonPointer2->weight = 130;
	aNewPersonPointer2->gender = 1;
	INIT_LIST_HEAD(&aNewPersonPointer2->list);


	list_add(&aNewPersonPointer->list, &personList.list);

	printf("%s\n",personList.list->name);
	return 0;
}
