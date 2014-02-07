#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;

void node_insert(LNode **head,int value)
{
    LNode **p,*tmp;
    for(p=head;
        (*p)!=NULL && ((*p)->data) < value;
        p=&(*p)->next);
        
    tmp=*p;
    *p=(LNode*)malloc(sizeof(LNode));
    (*p)->data=value;
    (*p)->next=tmp;
}

void node_remove(LNode **head,int key)
{
    LNode **p,*tmp;
    for(p=head;
        (*p)!=NULL && (*p)->data != key;
        p=&(*p)->next);
    
    if((*p)->data == key)
    {
        tmp=(*p)->next;
        free(*p);
        *p=tmp;
    }
}

int main()
{
    int n,a,i;
    LNode *head=NULL,*p;
    
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        node_insert(&head,a);
    }
    
    for(p=head;p!=NULL;p=p->next)
    {
        printf("%d ",p->data);
    }
    printf("\n");

    return 0;
}
