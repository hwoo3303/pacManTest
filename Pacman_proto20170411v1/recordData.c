#pragma warning(disable: 4996)

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#include "control.h"

extern int record;
extern int wall[MAP_HEIGHT][MAP_WIDTH];
extern int pacMan_x, pacMan_y;
extern FILE *saveData;

void recordRank()
{
	int saveRecord;
	//int cnt = 1;
	linkedList *L = (linkedList *)malloc(sizeof(linkedList));
	//node *p = L->head;
	L->cur = NULL;
	L->head = NULL;
	L->tail = NULL;

	saveData = fopen("record.txt", "rt");
	if (saveData == NULL)
	{
		printf("파일 읽기 에러\n");
		return;
	}

	system("cls");
	while (!feof(saveData))
	{
		fscanf(saveData, "%d", &saveRecord);
		createNode(L, saveRecord);
	}
	printNodes(L);

	fclose(saveData);
}

void recordRenew() 
{
	record += 10;
	wall[pacMan_y][pacMan_x] = 1;
	gotoxy(128, 16);
	printf("%d", record);
}

void recordSave(linkedList *L)
{
	//int i, j, temp;
	node *p = L->head;
	
	if (record == 0) 
	{
		return;
	}
	createNode(L, record);
	p = L->head;
	saveData = fopen("record.txt", "wt");
	while (p != '\0' && record != 0)
	{
		fprintf(saveData, " %d", p->data);
		p = p->next;
	}
	
	fclose(saveData);
}

void recordLoad()
{
	int saveRecord;
	linkedList *L = (linkedList *)malloc(sizeof(linkedList));
	L->cur = NULL;
	L->head = NULL;
	L->tail = NULL;

	saveData = fopen("record.txt", "rt");
	if (saveData == NULL)
	{
		printf("파일 읽기 에러\n");
		return;
	}
	
	system("cls");
	while (!feof(saveData))
	{
		fscanf(saveData, "%d", &saveRecord);
		createNode(L, saveRecord);
	}
	//printNodes(L);
	
	fclose(saveData);
	recordSave(L);
}

void itemList() 
{

}

void createNode(linkedList *L, int tdata)
{ 
	node *newNode = (node *)malloc(sizeof(node));
	node *cur;
	newNode->data = tdata;
	newNode->next = NULL;
	cur = L->head;

	if (L->head == NULL && L->tail == NULL)
	{
		L->head = L->tail = newNode;
	}
	else if (L->head->data < newNode->data) 
	{
		newNode->next = L->head;
		L->head = newNode;
		return;
	}
	else 
	{
		while (cur->next != NULL) 
		{
			if (cur->next->data < newNode->data) 
			{
				newNode->next = cur->next;
				cur->next = newNode;
				return;
			}
			cur = cur->next;
		}
		L->tail->next = newNode; 
		L->tail = newNode; 
	}
	L->cur = newNode; 
}

void printNodes(linkedList *L) 
{ 
	node *p = L->head;
	int cnt = 0, i;

	setcolor(0, 15);
	gotoxy(64, 5);
	printf(" H I G H   S C O R E \n");

	setcolor(14, 0);
	gotoxy(40, 8);
	puts("R A N K");

	for (i = 0; i < 10; i++)
	{
		setcolor(15, 0);
		gotoxy(43, 10 + (i * 2));
		printf("%2d", i + 1);
	}
	setcolor(11, 0);
	gotoxy(70, 8);
	puts("S C O R E");

	setcolor(13, 0);
	gotoxy(100, 8);
	puts("N A M E");

	setcolor(15, 0);
	while (p != NULL)
	{
		gotoxy(70, 10 + (2 * cnt));
		printf("%7d", p->data);
		cnt++;
		p = p->next;
		if (cnt > 9)
		{
			break;
		}
	}
}