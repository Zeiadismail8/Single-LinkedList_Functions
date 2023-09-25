#include"list.h"

int main()
{
    NODE_T l=NULLPTR,*l2=NULLPTR,*l3=NULLPTR;

    l=list_createnode(5);
    l->next=list_createnode(7);
    l->next->next=list_createnode(8);

    list_AddNodeToLast(l,50);
    list_AddNodeToFirst(&l,99);

    list_Print(l);

    list_EditData(l,4,99);

    list_Print(l);

    return 0;
}
