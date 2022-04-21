// /와\로 구성된 문자열을 입력받아 산의 형태로 출력하는 프로그램
#include <stdio.h>
#include <stdlib.h>


#define MAX_STACK 100
typedef enum { false, true } bool;
typedef char Data;
int row;

typedef struct {
	Data items[MAX_STACK];
	int top;
}Stack;

void InitStack(Stack* pstack);

bool IsFull(Stack* pstack);

bool IsEmpty(Stack* pstack);

Data Peek(Stack* pstack, int cnt);

void Push(Stack* pstack, Data item);

void Pop(Stack* pstack, int height);

int Height(Stack* pstack, char* arr[1000], int len);

bool IsSame(Stack* pstack);

int RowNum(Stack* pstack, int cnt, char* arr, int i);

void InitStack(Stack* pstack)
{
	pstack->top = -1;
}

bool IsFull(Stack* pstack)
{
	return pstack->top == MAX_STACK - 1;
}

bool IsEmpty(Stack* pstack)
{
	return pstack->top == -1;
}

Data Peek(Stack* pstack, int cnt)
{
	if (IsEmpty(pstack))
		return 0;
	return pstack->items[pstack->items[cnt]];
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
	if (IsEmpty(pstack) || pstack->top < -1)
		height = 0;
}

int Height(Stack * pstack, char * arr, int len)
{
	int cnt = 0;
	int height = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == 47)
		{
			Push(pstack, arr[i]);
			cnt++;
		}
		else if (arr[i] == 92)
		{
			if (height < cnt)
			{
				height = cnt;
			}
			cnt = 0;
			Pop(pstack, height);
		}
	}
	return height;
}

bool IsSame(Stack* pstack)
{
	return ((pstack->items[pstack->top]) == (pstack->items[(pstack->top) - 1]));
}

int RowNum(Stack* pstack, int row, char * arr, int i)
{
	if (IsSame(pstack))
	{
		if (arr[i] == '/')
			row--;
		else if (arr[i] == '\\')
			row++;
	}
	return row;
}

int main(void)
{
	int height;
	int len = 0;
	int row = 0;

	char mountain[1000];
	Stack mountainstack;
	Stack heightstack;
	int rowarr[1000];

	printf("¹®ÀÚ¿­ ÀÔ·Â");
	scanf_s("%s", &mountain, sizeof(mountain));
	InitStack(&mountainstack);
	InitStack(&heightstack);

	for (int j = 0; mountain[j] != 0; j++)
	{
		len++;
	}

	height = Height(&heightstack, mountain, len);
	int cnt = height;

	for (int h = 0; mountain[h] != 0; h++)
	{

		Push(&mountainstack, mountain[h]);
		row = RowNum(&mountainstack, cnt, &mountain, h);
		cnt = row;
		rowarr[h] = row;
	}

	for (int k = 0; k < height; k++)
	{
		for (int x = 0; x < len; x++)
		{
			if (rowarr[x] == k + 1)
			{
				printf("%c", mountain[x]);
			}
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
