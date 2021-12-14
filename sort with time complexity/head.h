
typedef struct _node_
{
    int data;
    struct _node_ *ptr;
}Node;

typedef struct Linked_list
{
    Node *head,*tail;
    unsigned int count;
}List;

List* initialize_list();
int insert_data_beg(List*, int);
int insert_data_end(List*, int);
List* merge(List *,List *);
