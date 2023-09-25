
#define  NULLPTR   ((void*)0)



typedef struct node{

int data;
struct node *next;

}node_t;


typedef enum{
LIST_DONE,
LIST_EMPTY,
LIST_NOTFOUND

}listStatus_t;
