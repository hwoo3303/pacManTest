#ifndef __RECORDDATA_H__
#define __RECORDDATA_H__

typedef struct node
{
	int data;
	struct node *next;
} node;

typedef struct list
{
	struct node *cur;
	struct node *head;
	struct node *tail;
} linkedList;

void recordRenew();
void itemList();
void recordRank();
void recordLoad();
void recordSave(linkedList *L);
void createNode(linkedList *L, int tdata);
void printNodes(linkedList *L);

#endif