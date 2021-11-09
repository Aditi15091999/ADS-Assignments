#include "head.h"
#include <stdlib.h>
#include<stdio.h>
darray* initialize_array(int size)
{
    darray *my_array;

    my_array = (darray *)malloc(sizeof(darray));

    if(my_array == NULL) return NULL;

    my_array->c_size = 0;
    my_array->t_size = size;
    my_array->rcnt = 0;
    my_array->gcnt = 0;
    my_array->bcnt = 0;
    my_array->arr = (pix *)malloc(sizeof(pix)*size);

    if(NULL == my_array->arr) return NULL;

    return my_array;
}

 int insert_data(darray * my_array, unsigned int R,unsigned int G,unsigned int B, float intensity,int opacity )
 {
    if(my_array == NULL) return FAIL; // memory not initialized

    if(my_array->c_size == my_array->t_size) // check array if FULL
    {
        return 0;
    }

    (my_array->arr[my_array->c_size].r) = R;// store the data
    (my_array->arr[my_array->c_size].g) = G;
    (my_array->arr[my_array->c_size].b) = B;
    (my_array->arr[my_array->c_size].intensity) = intensity;
    (my_array->arr[my_array->c_size].opacity) = opacity;
     my_array->c_size++;                          //at c_size pos and increment the c_size

    return 1;
 }

int count_rgb(darray *myarray)
{
    int i;
    if(myarray == NULL) return FAIL;
    for(i=0;i<myarray->t_size;i++)
    {
       if(myarray->arr[i].r==255 && myarray->arr[i].g==0 && myarray->arr[i].b==0)
       {
           //rcnt++;
          myarray->rcnt++;
       }
       if(myarray->arr[i].r==0 && myarray->arr[i].g==255 && myarray->arr[i].b==0)
       {
           myarray->gcnt++;
       }
       if(myarray->arr[i].r==0 && myarray->arr[i].g==0 && myarray->arr[i].b==255)
       {
           myarray->bcnt++;
       }

    }
    printf("%d\t%d\t%d\t",myarray->rcnt,myarray->gcnt,myarray->bcnt);
    return 1;
}
int set_opacity(darray *myarray,int ele)
{
    int i;
    if(myarray == NULL) return 0;
    for(i=0;i<myarray->t_size;i++)
    {
        if(myarray->arr[i].opacity==0)
        {
            myarray->arr[i].opacity=ele;
        }
    }
   return 1;
}

int highest_intensity(darray *myarray)
{
  float max=0.0;
  int i;
 // if(myarray == NULL) return 0;
  for(i=0;i<myarray->t_size;i++)
  {
     if(myarray->arr[i].intensity>max)
     {
         max=myarray->arr[i].intensity;
     }
  }
  printf("%.2f",max);
  return 1;

}
