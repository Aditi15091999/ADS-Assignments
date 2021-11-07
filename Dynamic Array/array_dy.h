
#define SUCCESS 1
#define FULL -1
#define FAIL 0
#define INIT 2
#define NOT_INIT 5
#define ZERO 0


struct _dynamic_array_
{
    int *arr;
    int c_size, t_size;
    int op_status;
};

typedef struct _dynamic_array_ Darray;

Darray * initialize_darray(int size);
int insert_data(Darray *, int data);
Darray * deallocate(Darray *);

int search(Darray *, int element);


// assignments

int find_and_replace(Darray *, int);
int sort(Darray *);
int find_number_of_prime_numbers(Darray *);

Darray * merge_arrays(Darray *, Darray *); // class
Darray * intersection(Darray *, Darray *); // class
Darray * split_array(Darray *); // class

