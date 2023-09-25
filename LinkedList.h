#include <stdio.h>
#include <stdlib.h>

#define NULLPTR ((void*)0)

#define NODE_T  node_t*

typedef struct node {

int data;
struct node* next;
int counter;

}node_t;

typedef enum{
LIST_DONE,
LIST_EMPTY,

LIST_DONE_REMOVED,
LIST_NODE_REMOVED,
LIST_NODE_INSERT_DONE,
LIST_NODE_NOT_FOUND,
LIST_DATA_NOT_FOUND,

LIST_PUSH_DONE,
LIST_POP_DONE,

LIST_ENQUEUE_DONE,
LIST_DEQUEUE_DONE
}ListStatus_t;

NODE_T list_CreateNode(int data);
void list_AddNodeToLast(NODE_T head,int data);
void list_AddNodeToFirst(NODE_T* head,int data);

ListStatus_t list_Print(NODE_T head);

ListStatus_t list_RemoveNode(NODE_T* head, int oldData);
//ListStatus_t list_RemoveAll(NODE_T* head);

ListStatus_t list_EditData(NODE_T head,int newdata,int olddata);
ListStatus_t list_InsertData(NODE_T* head,int newdata,int olddata);

ListStatus_t list_Push(NODE_T* head,int data);
ListStatus_t list_Pop(NODE_T* head);

ListStatus_t list_enqueue(NODE_T* head,int data);
ListStatus_t list_dequeue(NODE_T* head);

