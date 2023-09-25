#include"list.h"

NODE_T list_CreateNode(int data)
{
    NODE_T newNode=malloc(sizeof(node_t));
    newNode->data=data;
    newNode->next=NULLPTR;
    return newNode;
}

void list_AddNodeToLast(NODE_T head,int data)
{
    NODE_T newNode=list_CreateNode(data);
    NODE_T current=head;

    while(current->next!=NULLPTR)
    {
        current=current->next;
    }
    current->next=newNode;
}

void list_AddNodeToFirst(NODE_T* head,int data)
{
    NODE_T newNode=list_CreateNode(data);
    newNode->next=*head;
    *head=newNode;
}

ListStatus_t list_Print(NODE_T head)
{
    NODE_T current=head;

    if(current==NULLPTR)
    {
        return LIST_EMPTY;
    }

    while(current!=NULLPTR)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n==============================================\n");
}

ListStatus_t list_RemoveNode(NODE_T *head, int oldData)
{
    NODE_T current = *head;
    NODE_T temp = NULLPTR;

    if(current == NULLPTR)
    {
        return LIST_EMPTY;
    }
    if(current->data == oldData)
    {
        temp = *head;
        *head = current -> next;
        free(temp);
        return LIST_NODE_REMOVED;
    }
    while(current->next->data != oldData)
    {
        current = current -> next;
        if(current->next == NULLPTR)
        {
            return LIST_NODE_NOT_FOUND;
        }
    }
    temp = current -> next;
    current -> next = current -> next -> next;
    free(temp);

    return LIST_NODE_REMOVED;
}

/*ListStatus_t list_RemoveAll(NODE_T* head)
{
    if(head==NULLPTR)
    {
        return LIST_EMPTY;
    }

    NODE_T current=*head;
    NODE_T temp=NULLPTR;

    while(current->next!=NULLPTR)
    {
        temp=*head;
        *head=current->next;
        current=*head;
        free(temp);
    }

    temp = current;
    free(temp);
    return LIST_DONE_REMOVED;

}*/ // This Function need Edit

ListStatus_t list_EditData(NODE_T head,int newdata,int olddata)
{
    if(head==NULLPTR)
    {
        return LIST_EMPTY;
    }
    NODE_T current=head;
    while(current!=NULLPTR)
    {
        if(current->data==olddata)
        {
            current->data=newdata;
            return LIST_DONE;
        }
        current=current->next;
    }
    return LIST_DATA_NOT_FOUND;
}

ListStatus_t list_InsertData(NODE_T* head,int newdata,int olddata)
{
    if(head==NULLPTR)
    {
        return LIST_EMPTY;
    }
    NODE_T newNode=list_CreateNode(newdata);
    NODE_T current=head;

    while(current!=NULLPTR)
    {
        if(current->data!=olddata)
        {
            current=current->next;
        }
        else
        {
            newNode->next=current->next;
            current->next=newNode;
            return LIST_NODE_INSERT_DONE;
        }
    }
}

ListStatus_t list_Push(NODE_T* head,int data)
{
    NODE_T newNode=list_CreateNode(data);
    newNode->next=*head;
    *head=newNode;
    return LIST_PUSH_DONE;
}

ListStatus_t list_Pop(NODE_T* head)
{
    NODE_T current=*head;
    NODE_T temp=*head;

    *head=current->next;
    free(temp);
    return LIST_POP_DONE;
}

ListStatus_t list_enqueue(NODE_T* head,int data)
{
    NODE_T newNode=list_CreateNode(data);
    NODE_T current=*head;

    if(current==NULLPTR)
    {
        *head=newNode;
    }
    else
    {
        while(current->next!=NULLPTR)
        {
            current=current->next;
        }
        current->next=newNode;
    }
    return LIST_ENQUEUE_DONE;
}

ListStatus_t list_dequeue(NODE_T* head)
{
    NODE_T current=*head;
    NODE_T temp=*head;

    *head=current->next;
    free(temp);
    return LIST_DEQUEUE_DONE;
}
