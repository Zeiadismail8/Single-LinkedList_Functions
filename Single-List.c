
#include "list.h"


node_t*create_node(int data)
{
     node_t*newNode=malloc(sizeof(node_t));
     newNode->data=data;
     newNode->next=NULLPTR;
     return newNode;
}


void list_print(node_t*head)
{
    node_t*current=head;

    while(current!=NULLPTR)
    {
      printf("%d ",current->data);
      current=current->next;
    }
printf("\n==============================================\n");
}


void list_addNodeToLast(node_t*head,int data)
{
    node_t*newNode=create_node(data);
    node_t*current=head;

    while(current->next!=NULLPTR)
    {
      current=current->next;
    }
    current->next=newNode;
}

void list_addNodeToFirst(node_t**phead,int data)
{
     node_t*newNode=create_node(data);
     newNode->next=*phead;
     *phead=newNode;
}

listStatus_t list_editData(node_t*head,int oldData,int newData)
{
    if(head==NULLPTR)
    {
        return LIST_EMPTY;
    }
     node_t*current=head;
     while(current!=NULLPTR)
    {
      if(current->data==oldData)
      {
          current->data=newData;
          return LIST_DONE;
      }
      current=current->next;
    }
    return LIST_NOTFOUND;


}

listStatus_t list_removeData(node_t*head,int oldData)
{
      node_t*current=head;
      node_t*temp;
     while(current->next!=NULLPTR)
    {
      if(current->next->data==oldData)
      {
          temp=current->next;
          current->next=current->next->next;
          free(temp);

          return LIST_DONE;
      }
      current=current->next;
    }
}
