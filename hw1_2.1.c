#include <stdio.h>
#include <stdlib.h>


#define MAX_STACK 100
typedef enum { false, true } bool;
typedef char Data;

typedef struct {
	Data items[MAX_STACK];
	int top;
}Stack;

void InitStack(Stack* pstack);

bool IsFull(Stack* pstack);

bool IsEmpty(Stack* pstack);

Data Peek(Stack* pstack);

void Push(Stack* pstack, Data item);

void Pop(Stack* pstack, int height);



void InitStack(Stack* pstack)
{
	pstack->top = -1;
}

bool IsFull(Stack* pstack)
{ 
	return pstack-> top == MAX_STACK - 1;
}

bool IsEmpty(Stack* pstack)
{
	return pstack->top == -1;
}

Data Peek(Stack* pstack)
{
	if (IsEmpty(pstack))
		return 0;
	return pstack->items[pstack->top];
}

void Push(Stack* pstack, Data item)
{
	if (IsFull(pstack))
		exit(1);
	pstack->items[++(pstack->top)] = item;
}

void Pop(Stack* pstack, int height)
{
	--(pstack->top);
	if (IsEmpty(pstack)|| pstack->top < -1)
		height = 0;
	
}

int main(void)
{
	int cnt = 0;
	int height = 0;
	int len = 0;
	char mountain[1000];
	Stack mountainstack;

	printf("¹®ÀÚ¿­ ÀÔ·Â");
	scanf_s("%s", &mountain, sizeof(mountain));

	for (int j = 0; mountain[j] != 0; j++)
	{
		len++;
	}

	InitStack(&mountainstack);
	for (int i = 0; i < len; i++)
	{
		if (mountain[i] == 47)
		{
			Push(&mountainstack, mountain[i]);
			cnt++;
		}
		else if (mountain[i] == 92)
		{
			if (height < cnt)
			{
				height = cnt;
			}
			cnt = 0;
			Pop(&mountainstack, height);
		}
	}
	if (IsEmpty(&mountainstack))
		printf("³ôÀÌ : %d",height);
	else
		printf("³ôÀÌ : 0");
	
	return 0;
}
