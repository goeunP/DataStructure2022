#include <stdio.h>

#define MAX_QUEUE 100000

typedef enum {false, true} bool;
typedef int Data;
int count;

typedef struct {
	int front, rear;
	Data items[MAX_QUEUE];
} Queue;

void InitQueue(Queue* pqueue);

bool IsFull(Queue* pqueue);

bool IsEmpty(Queue* pqueue);

void InsertNum(Queue* pqueue, Data item);

void PrintQueue(Queue* pqueue, int cnt);

void SortQueue(Queue* pqueue, int cnt);

Data EvenMiddleQUeue(Queue* pqueue);

Data OddMiddleQUeue(Queue* pqueue);


void InitQueue(Queue* pqueue)
{
	pqueue->front = pqueue->rear = 0;
}

bool IsFull(Queue* pqueue)
{
	return pqueue->front == (pqueue->rear + 1) % MAX_QUEUE;
}

bool IsEmpty(Queue* pqueue)
{
	return pqueue->front == pqueue->rear;
}

void PrintQueue(Queue* pqueue, int cnt)
{
	for (int k = 0; k < cnt; k++)
	{
		printf("%d ", pqueue->items[(pqueue->rear) - count + k]);
	}
}

void InsertNum(Queue* pqueue, Data item)
{
	if (IsFull(pqueue))
		exit(1);
	pqueue->items[pqueue->rear] = item;
	pqueue->rear = (pqueue->rear + 1) % MAX_QUEUE;

	count = pqueue->rear - pqueue->front;
}


void SortQueue(Queue* pqueue, int cnt)
{
	int i, j;
	int temp;
	for (i = 0; i < cnt - 1; i++)
	{
		for (j = 0; j < cnt - i-1; j++)
		{
			if (pqueue->items[pqueue->front+j] > pqueue->items[pqueue->front+j+1])
			{
			temp = pqueue->items[pqueue->front + j];
			pqueue->items[pqueue->front + j] = pqueue->items[pqueue->front  + j + 1];
			pqueue->items[pqueue->front+ j + 1] = temp;
			}
		}	 
	}
}

Data EvenMiddleQUeue(Queue* pqueue)
{
	Data middle = pqueue->items[(pqueue->rear / 2)-1];
	return middle;
}

Data OddMiddleQUeue(Queue* pqueue)
{
	Data middle = pqueue->items[(pqueue->rear)-((pqueue->rear / 2)+1)];
	return middle;
}

int main(void)

{
	int N;
	int num;
	Queue numqueue;

	printf("전체 숫자 개수 입력:");
	scanf_s("%d", &N);

	InitQueue(&numqueue);
	for (int i = 0; i < N; i++)
	{
		printf("\n%d번째 숫자:", i + 1);
		scanf_s("%d", &num);
		InsertNum(&numqueue, num);

		SortQueue(&numqueue, count);
		PrintQueue(&numqueue, count);
		if (count % 2 == 0)
		{
			printf("중간값: %d\n", EvenMiddleQUeue(&numqueue));
		}
		else
		{
			printf("중간값: %d\n", OddMiddleQUeue(&numqueue));
		}
	}
	return 0;
}