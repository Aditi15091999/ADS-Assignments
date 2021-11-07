#include<stdlib.h>
#include<assert.h>
#include "array_dy.h"

Darray * initialize_darray(int size){

    Darray *my_darray;
    my_darray = (Darray *)malloc(sizeof(Darray)); // Allocate memory for Darray

    if(NULL == my_darray) return NULL; // return NULL if memory not
                                       // not allocated dynamically
    my_darray->c_size = 0;    // set to ZERO as not elements are present
    my_darray->t_size = size; // equals to input size
    my_darray->arr = (int *)malloc(sizeof(int) * size);

    if(NULL == my_darray->arr) return NULL; // return NULL if memory not
                                            // allocated for int array
    my_darray->op_status = INIT;    // set the status to initialize

    return my_darray; // return the address of Darray
}


int insert_data(Darray *my_darray, int data){

    if(my_darray == NULL) return FAIL; // memory not initialized

    if(my_darray->c_size == my_darray->t_size) // check array if FULL
    {
        my_darray->op_status = FULL;
        return FULL;
    }

    *(my_darray->arr + my_darray->c_size) = data; // store the data
    my_darray->c_size++;                          //at c_size pos and increment the c_size

    my_darray->op_status = SUCCESS; // set the status to SUCCESS

    return SUCCESS;
}


Darray * deallocate(Darray *buf)
{
    if(buf == NULL) return NULL;

    free(buf->arr); // deallocate array
    free(buf);      // deallocate the structure

    return NULL;
}

int search(Darray *buf, int element)
{
    int i;

    if( buf->c_size == ZERO || buf == NULL) return ZERO;

    for(i=0; i < buf->c_size; i++){
        if(buf->arr[i] == element)
            return SUCCESS;
    }
    return FAIL;
}

Darray * intersection(Darray *buf_one, Darray *buf_two)
{
    Darray *result;
    int i;

    if(buf_one == NULL || buf_two == NULL) return NULL;

    if(buf_one->c_size == 0 || buf_two->c_size == 0) return NULL;

    if(buf_one->c_size < buf_two->c_size)
        result = initialize_darray(buf_one->c_size);
    else
        result = initialize_darray(buf_two->c_size);

    for(i=0; i< buf_one->c_size; i++){

        if(search(buf_two, buf_one->arr[i]) && !search(result, buf_one->arr[i]))
            assert(insert_data(result, buf_one->arr[i]) == SUCCESS);
    }
    return result;
}

int find_and_replace(Darray *my_darray, int key)
{
    int num=9,i;
    if(my_darray == NULL) return FAIL;
    for(i=0;i<my_darray->c_size;i++)
    {
        if(my_darray->arr[i]==key)
        {
            my_darray->arr[i]=num;
            return 1;
        }
    }
    return 0;
}

int find_number_of_prime_numbers(Darray *my_darray)
{
 int count=0,j,i,flag;
 for(i=0;i<my_darray->c_size;i++)
 {
     flag=0;
     for(j=2;j<my_darray->arr[i];j++)
     {
         if(my_darray->arr[i]%j==0)
         {
             flag=0;
             break;
         }
         else
         {
             flag=1;
         }
     }
     if(flag==1)
        count=count+1;
 }
 return count;
}

int sort(Darray *my_darray)
{
    int i,j,temp;
    for(i=0;i<my_darray->c_size;i++)
    {
        for(j=i+1;j<my_darray->c_size;j++)
        {
            if(my_darray->arr[i]>my_darray->arr[j])
            {
                temp=my_darray->arr[i];
                my_darray->arr[i]=my_darray->arr[j];
                my_darray->arr[j]=temp;
            }
        }
    }
    for(i=0;i<my_darray->c_size;i++)
        printf("%d\t",my_darray->arr[i]);
    return 1;
}











