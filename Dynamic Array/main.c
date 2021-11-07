#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "array_dy.h"

int main()
{
    Darray *buf_one, *buf_two, *intersect;

    int intesect_test[] = { 20, 30, 40}, i;


    buf_one = initialize_darray(5);
    buf_two = initialize_darray(9);

    // Test whether both the array are initialized
    assert(buf_one->op_status == INIT);
    assert(buf_two->op_status == INIT);

    assert(buf_one->c_size == 0 && buf_one->t_size == 5);
    assert(buf_two->c_size == 0 && buf_two->t_size == 9);

    //insert data in buf_one
    assert(insert_data(buf_one, 10));
    assert(insert_data(buf_one, 20));
    assert(insert_data(buf_one, 20));
    assert(insert_data(buf_one, 30));
    assert(insert_data(buf_one, 40));

    assert(buf_one->c_size == buf_one->t_size);
    assert(buf_one->op_status == SUCCESS);

    assert(insert_data(buf_one, 90) == FULL);
    assert(buf_one->op_status == FULL);

    assert(insert_data(buf_two, 20));
    assert(insert_data(buf_two, 60));
    assert(insert_data(buf_two, 20));
    assert(insert_data(buf_two, 80));
    assert(insert_data(buf_two, 20));
    assert(insert_data(buf_two, 40));
    assert(insert_data(buf_two, 30));
    assert(insert_data(buf_two, 5));
    assert(insert_data(buf_two, 7));


    assert(buf_two->c_size == buf_two->t_size);
    assert(insert_data(buf_two, 30));
    assert(buf_two->op_status  == FULL);

    assert(search(buf_one, 10) == SUCCESS);
    assert(search(buf_one, 90) == FAIL);


    intersect = intersection(buf_one, buf_two);
    assert(intersect->c_size == 3);

    for(i=0; i<intersect->c_size; i++)
        assert(intersect->arr[i] == intesect_test[i]);

//find and replace

    assert(find_and_replace(buf_one,30)==1);
    assert(find_and_replace(buf_two,10)==0);

//count number of primes
    assert(find_number_of_prime_numbers(buf_one)==0);
    assert(find_number_of_prime_numbers(buf_two)==2);

//sort the array
    assert(sort(buf_two)==1);

//deallocate array
    buf_one = deallocate(buf_one);
    buf_two = deallocate(buf_two);

    assert(buf_one == NULL);
    assert(buf_two == NULL);
    return 0;
}

