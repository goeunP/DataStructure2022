#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true }bool;
typedef char Data;

typedef struct _Node {
	Data item;
	struct _Node* next;
}Node;

typedef struct {
	Node* head;
	Node* cursor;
	int len;
}LinkedList;

void InitList(LinkedList* plist);

void Add(LinkedList* plist, Data item);

void Erase(LinkedList* plist);

void Move(LinkedList* plist, char direction);

void PrintList(LinkedList* plist);

void InitList(LinkedList* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->cursor = (Node*)malloc(sizeof(Node));
	plist->head->next = plist->cursor;
	plist->cursor->next = NULL;
	plist->len = 0;
}

void Add(LinkedList* plist, Data item)
{
	Node *prev,* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;
	newNode->next = NULL;
	prev=plist->head;

	for (int i = 0; prev->next != plist->cursor; i++)
		prev = prev->next;
	newNode->next = plist->cursor;
	prev->next = newNode;
	plist->len++;
}

void Erase(LinkedList* plist)
{
	Node* prev,*pprev, *temp;
	prev = plist->head;
	pprev = plist->head;
	for (int i = 0; prev->next != plist->cursor; i++)
		prev = prev->next;
	for (int i = 0; pprev->next != prev; i++)
		pprev = pprev->next;
	if (plist->head->next!=plist->cursor)
	{
		temp = prev;
		pprev->next = plist->cursor;
		plist->len--;
		free(temp);
	}
}

void Move (LinkedList* plist, char direction)
{
	Node* prev, * pprev, *temp;
	prev = plist->head;
	pprev = plist->head;
	for (int i = 0; prev->next != plist->cursor; i++)
		prev = prev->next;
	for (int i = 0;pprev!=NULL&& pprev->next != prev; i++)
	{
		pprev = pprev->next;
	}

	if (direction == 'l')
	{
		if (prev != plist->head)
		{
			pprev->next = plist->cursor;
			prev->next = plist->cursor->next;
			plist->cursor->next = prev;
		}
	}
	else if (direction == 'r')
	{
		if (plist->cursor->next != NULL)
		{		
			temp = plist->cursor->next;
			plist->cursor->next = plist->cursor->next->next;
			prev->next = temp;
			temp->next = plist->cursor;
		}
	}
	else
		printf("wrong direction");
	
}

void PrintList(LinkedList* plist)
{
	for (Node* cur = plist->head->next; cur != plist->cursor; cur = cur->next)
		printf("%c", cur->item);
	for(Node*cur=plist->cursor->next;cur!=NULL;cur=cur->next)
		printf("%c", cur->item);
}

int main(void)
{
	int num;
	LinkedList searchBar;

	printf("the number of operations:");
	scanf("%d", &num);
	InitList(&searchBar);

	for (int i = 0; i < num; i++)
	{
		char operation[6];
		char ch[2];
		scanf("%s", operation);
		if(operation[0]==97||operation[0]==109)
			scanf("%s", ch);    

		if (operation[0] == 97 && operation[1]==100 & operation[2]==100) //add
		{
			if ((ch[0] >= 65 && ch[0] <= 90) || (ch[0] >= 97 && ch[0] <= 122) || ch[0] == 95)
				Add(&searchBar, ch[0]);
			else
				printf("only A-Z, a-z, _ are available");
		}
		else if (operation[0]==101&&operation[1]==114&&operation[2]==97&&operation[3]==115&&operation[4]==101) //erase
			Erase(&searchBar);

		else if (operation[0]==109&&operation[1]==111&&operation[2]==118&&operation[3]==101) //move
			Move(&searchBar,ch[0]);

		else
			printf("wrong operation");
	}
	PrintList(&searchBar);
	return 0;
}