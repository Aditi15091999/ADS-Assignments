
#include "head.h"
#include<stdlib.h>

List* initialize_list()
{
    List *mylist;

    mylist=(List*)malloc(sizeof(List));

    if(mylist== NULL) return NULL;

    mylist->count=0;
    mylist->head=mylist->tail=NULL;

    return mylist;
}
Node* getnode(int data)
{
    Node* newnode;

    newnode=(Node*)malloc(sizeof(Node)); // assign memory for newnode

    newnode->data=data; // insert data
    newnode->ptr=NULL;
    return newnode;
}

int insert_data_beg(List *mylist, int data)
{
    Node *newnode;

    newnode=getnode(data);

    if(newnode==NULL) return 0;

    if(mylist->count==0)
    {
        mylist->head=mylist->tail=newnode;
    }
    else{
        newnode->ptr=mylist->head;
        mylist->head=newnode;
    }
    mylist->count++;
    return 1;
}

int insert_data_end(List *mylist, int data)
{
    Node *newnode;

    newnode=getnode(data);

    if(newnode==NULL) return 0;

    if(mylist->count==0)
    {
        mylist->head=mylist->tail=newnode;
    }
    else{
       mylist->tail->ptr=newnode;
       mylist->tail=newnode;
    }
    mylist->count++;
    return 1;
}

List* merge(List* lista, List* listb)
{
    List * result;

    result=initialize_list();

    Node* temp_a, *temp_b;

    temp_a=lista->head;

    temp_b=listb->head;

    if(lista->head==NULL)
        return listb;
    else if(listb->head==NULL)
        return lista;
    while(temp_a!=NULL && temp_b!=NULL)
    {
       if(temp_a->data<=temp_b->data){
            insert_data_end(result,temp_a->data);
            temp_a=temp_a->ptr;
       }
        else
        {
            insert_data_end(result,temp_b->data);
            temp_b=temp_b->ptr;
        }
   }
   if(temp_a!=NULL)
   {
       insert_data_end(result,temp_a->data);
   }
   else{
    insert_data_end(result,temp_b->data);

   }

   return result;
}
