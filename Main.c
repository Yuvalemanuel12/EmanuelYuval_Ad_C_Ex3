
#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

#include <stdio.h>
#include <string.h>;
#include <stdlib.h>;
#include "Stack.h"
#include "Queue.h"
void stack();
void queue();
void main()
{
	stack();
}





void stack()
{
	Stack s1;
	Stack* ptrs = &s1;
	initStack(ptrs);
	push(ptrs, 5);
	push(ptrs, 7);
	push(ptrs, 10);
	push(ptrs, 10);
	push(ptrs, 7);
	push(ptrs, 5);
	printf("the stack is/not palindrome if 1/0: %d\n", isPalindrome(ptrs));
	rotateStack(ptrs, 5);
	printf("after the rotate function: ");
	print(ptrs);
	char* sentence = "remem#reb# thi#carp s#tice";
	printf("after the flip between hashes function: \n");
	flipBetweenHashes(sentence);
	print(ptrs);
	pop(ptrs);
	pop(ptrs);
	printf("after pop: \n");
	print(ptrs);
	destroyStack(ptrs);
}

void queue()
{
	Queue q1;
	initQueue(&q1);
	enqueue(&q1, 6);
	printQueue(&q1);
	enqueue(&q1, 5);
	enqueue(&q1, 2);
	enqueue(&q1, 3);
	enqueue(&q1, 1);
	enqueue(&q1, 9);
	printQueue(&q1);
	rotateQueue(&q1);
	printf("after the rotate function:\n ");
	printQueue(&q1);
	printf("after the cut and replace function: \n");
	cutAndReplace(&q1);
	printQueue(&q1);
	sortKidsFirst(&q1);
	printf("after the sort kids first function: \n");
	dequeue(&q1);
	dequeue(&q1);
	printf("after dequeue: \n");
	printQueue(&q1);
	destroyQueue(&q1);
}
