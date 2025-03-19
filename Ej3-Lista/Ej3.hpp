
#include <iostream>
#include <memory>

using namespace std;

struct node;
typedef struct node node_t;
typedef struct list list_t;

shared_ptr<node_t> create_node(void* val);
shared_ptr<list_t> create_list(void);
bool push_front(void* val, shared_ptr<list_t>& lista);
bool push_back(void* val, shared_ptr<list_t>& lista);
bool insert(void* val, shared_ptr<list_t>& lista, unsigned pos);
bool erase_front(shared_ptr<list_t>& lista);
bool erase_back(shared_ptr<list_t>& lista);
bool erase(shared_ptr<list_t>& lista, unsigned pos);
void print_list(shared_ptr<list_t>& lista);
void free_list(shared_ptr<list_t>& lista);

struct node {
    shared_ptr<void*> value;
    shared_ptr<node_t> next;
};

struct list {
    shared_ptr<node_t> head;
    shared_ptr<node_t> tail;
    unsigned size;
};
