#include <stdlib.h>
#include<assert.h>
#include "head.h"

int main()
{
    darray *buf_one;

    buf_one=initialize_array(5);

    //Test if the pointer is intialized
    assert(buf_one->t_size==5);
    assert(buf_one->c_size==0);
    assert(buf_one->rcnt==0);

    //insertion of data
    assert(insert_data(buf_one,255,0,0,0.5,1));
    assert(insert_data(buf_one,0,0,255,0.2,0));
    assert(insert_data(buf_one,255,0,0,0.35,1));
    assert(insert_data(buf_one,0,0,255,0.25,0));
    assert(insert_data(buf_one,0,255,0,0.80,1));

    assert(buf_one->c_size == buf_one->t_size);

    assert(buf_one->arr[1].r==0);
    assert(buf_one->arr[0].g==0);
    assert(buf_one->arr[1].b==255);

    assert(insert_data(buf_one,255,0,0,0.5,1)==0);

    //count the r g b values in a pixel
    assert(count_rgb(buf_one)==1);

    //set opacity
    assert(set_opacity(buf_one,1)==1);
    assert(buf_one->arr[1].opacity==1);
    assert(buf_one->arr[3].opacity==1);

    //find highest intensity
    assert(highest_intensity(buf_one)==1);
    return 0;
}
