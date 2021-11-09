
#define FAIL 2
struct _pixel_
{
    unsigned int r,g,b;
    float intensity;
    int opacity;

};
 typedef struct _pixel_ pix;

 struct _array_
 {
     pix *arr;
     int c_size,t_size;
     int rcnt,gcnt,bcnt;
 };
 typedef struct _array_ darray;

 darray* initialize_array(int size);//initialize array
 int insert_data(darray *, unsigned int,unsigned int,unsigned int, float,int );//insertion
 int count_rgb(darray *);//count rgb
 int set_opacity(darray *,int ele);//set and unset opacity
 int highest_intensity(darray *);//find max intensity
