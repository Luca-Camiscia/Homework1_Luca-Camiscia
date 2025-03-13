#include <iostream>
using namespace std;
struct node;
typedef struct node node_t;
typedef struct list list_t;
bool push_front(void* val, list_t lista);

struct node {
    void* value;
    node_t* next;
};

struct list{
    node_t* head;
    node_t* tail;
    unsigned size;
};

node_t* create_node(void*val);

int main (void);


node_t* create_node(void* val){
    node_t* new_node = new (nothrow) node_t;
    if (new_node == NULL){
        cout << "Error al crear un nodo" <<endl;
        return NULL;
    }
    new_node->value = val;
    new_node->next = nullptr;
    return new_node;
}

list_t * create_list(void){
    list_t* new_list = new (nothrow) list_t;
    if (new_list == NULL){
        cout << "Error al crear una lista" << endl;
        return NULL;
    }
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}

bool push_front(void* val, list_t* lista){
    node_t* new_node = create_node(val);
    if (new_node == NULL){
        cout << "Error" << endl;
        return false;
    }
    //caso lista vacia
    if (lista->head == NULL){
        lista->head = new_node;
        lista->tail = new_node;
        lista->size ++;
        return NULL;
    }
    new_node->next = lista->head;
    lista->head = new_node;
    lista->size ++;
    return true;
}