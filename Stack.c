#include "Stack.h"
#include <stdio.h>



/***************** Stack ADT Implementation *****************/

void initStack(Stack* s) {
	s->head = NULL;

}



void destroyStack(Stack* s)
{
	charNode* temp;
	while (s->head != NULL)
	{
		temp = s->head->next;
		free(s->head);
		s->head = temp;
	}
}



void push(Stack* s, char data) {
	charNode* temp = (charNode*)malloc(sizeof(charNode));
	if (temp == NULL)exit(1);
	temp->data = data;
	temp->next = s->head;
	s->head = temp;
}

char pop(Stack* s)
{
	char val = s->head->data;
	charNode* temp = s->head->next;
	free(s->head);
	s->head = temp;
	return val;
}

int isEmptyStack(const Stack* s)
{
	return (s->head == NULL ? 1 : 0);
}



void flipBetweenHashes(const char* sentence) {

	Stack* temp;
	temp = (Stack*)malloc(sizeof(Stack));
	initStack(temp);
	for (int i = 0; i < strlen(sentence); i++)
	{
		if (sentence[i] == '#')
		{
			int j = 0;
			while (sentence[j] != '#')
			{
				push(temp, sentence[j]);
				j++;
			}
			display(temp);
		}

		else printf("%d", sentence[i]);
	}
}


int isPalindrome(Stack* s)
{
	charNode* node1, * node2;
	if (s->head == NULL)
	{
		return 1;
	}
	int size = 0, i;
	for (size = 0, node1 = s->head; node1 != NULL; node1 = node1->next)
	{
		size++;
	}

	int distance;
	for (node1 = s->head, distance = size - 1; distance > 0; node1 = node1->next, distance -= 2)
	{
		for (node2 = node1, i = 0; i < distance; node2 = node2->next, i++)
		{
		}
		if (node1->data != node2->data)
		{
			return 0;
		}
	}
	return 1;
}



void rotateStack(Stack* s, int n)
{
	charNode* counter = s->head;
	int count = 0;
	while (counter != NULL)
	{
		counter = counter->next;
		count++;
	}
	if (n<0 || n>count || isEmptyStack(s))
	{
		return;
	}
	Stack* tmp1 = (Stack*)malloc(sizeof(Stack));
	Stack* tmp2 = (Stack*)malloc(sizeof(Stack));
	if (tmp1 == NULL || tmp2 == NULL)
	{
		printf("error");
	}
	for (int i = 0; i < count - n; i++)
	{
		push(tmp1, pop(s));
	}
	for (int i = 0; i < n; i++)
	{
		push(tmp2, pop(s));
	}
	for (int i = 0; i < count; i++)
	{
		push(s, pop(tmp1));
	}
	for (int i = 0; i < n; i++)
	{
		push(s, pop(tmp2));
	}


}



void printStack(charNode* head)
{
	charNode* tmp;
	tmp = head;
	while (tmp != NULL)
	{
		printf(" % d ", tmp->data);
		tmp = tmp->next;
	}
}

void display(Stack* S)
{
	print(S->head);
}
