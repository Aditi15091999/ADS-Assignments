#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "head.h"
int main()
{
    List *buf, *test, *result;
    Node *temp;

    //initialize list
    buf=initialize_list();
    test=initialize_list();

    assert(buf->count==0);
    assert(test->count==0);

    assert(buf->head==NULL && buf->tail==NULL);
    assert(test->head==NULL && test->tail==NULL);

    //insert data

    assert(insert_data_beg(buf,100));
    assert(insert_data_beg(buf,30));
    assert(insert_data_beg(buf,20));
    assert(insert_data_beg(buf,10));

    assert(buf->count==4);
    assert(buf->head->data==10);
    assert(buf->tail->data==100);

    assert(insert_data_beg(test,80));
    assert(insert_data_beg(test,50));
    assert(insert_data_beg(test,40));
    assert(insert_data_beg(test,20));

    assert(test->count==4);
    assert(test->head->data==20);
    assert(test->tail->data==80);

    result=merge(buf,test);
    for(temp=result->head;temp!=NULL;temp=temp->ptr)
    {
        printf("%d\t",temp->data);
    }

    return 0;
}
