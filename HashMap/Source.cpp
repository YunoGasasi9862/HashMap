#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include"LinkedList.h"
#define MAX 10
node_t* createLinkedList(node_t* hp)
{
	node_t* temp;
	printf("Enter a number (-1 to stop ): ");
	int number;
	scanf("%d", &number);
	hp = addBeginning(hp, number);
	temp = hp;
	while (number != -1)
	{
		scanf("%d", &number);

		if (number != -1)
		{
			AddAfter(temp, number);
			temp = temp->next;

		}
	}

	return hp;
}

void PrintLinked(node_t* hp)
{
	while (hp != NULL)
	{
		printf("%d -> ", hp->data);
		hp = hp->next;
	}
	printf("NULL\n");
}
node_t* findIntersection(node_t* l1, node_t* l2)
{
	int counter = 0;
	int flag = 1;
	node_t* HashTable[MAX];
	node_t* intersection = NULL;
	node_t* temp=NULL;
	for (int i = 0; i < MAX; i++)
		HashTable[i] = NULL;
	while (l2 != NULL)
	{
		HashTable[counter++] = l2;
		l2 = l2->next;
	}

	while (l1 != NULL)
	{
		for (int i = 0; i < counter; i++)
		{
			if (l1->data == HashTable[i]->data)
			{
				if (flag == 1)
				{
					intersection = addBeginning(intersection, l1->data); //for beginning
					temp = intersection;
					flag = 0;
				}
				else
				{
					AddAfter(temp, l1->data);
					temp = temp->next;
				}


			}


		}
		l1 = l1->next;
	}

	return intersection;
}
int main(void)
{
	node_t* linkedList1 = NULL;
	 linkedList1=createLinkedList(linkedList1);

	 node_t* linkedList2 = NULL;
		linkedList2= createLinkedList(linkedList2);

		node_t* newLinked= findIntersection(linkedList1, linkedList2);

	return 0;
}