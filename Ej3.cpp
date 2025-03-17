#include <iostream>
#include <memory>
using namespace std;

struct node;
typedef struct node node_t;
typedef struct list list_t;

bool push_front(void* val, unique_ptr<list_t>& lista);
bool push_back(void * val, unique_ptr<list_t>& lista);
bool insert(void * val, unique_ptr<list_t>& lista,unsigned pos);
bool erase_front(unique_ptr<list_t>& lista);
bool erase_back(unique_ptr<list_t>& lista);
bool erase(unique_ptr<list_t>& lista, unsigned pos);
void print_list(unique_ptr<list_t>& lista);
void free_list(unique_ptr<list_t>& lista);
struct node {
    unique_ptr<void*> value;
    unique_ptr<node_t> next;
};

struct list {
    unique_ptr<node_t> head;
    node_t* tail; // tail does not need to be a unique_ptr
    unsigned size;
};

unique_ptr<node_t> create_node(void* val);
unique_ptr<list_t> create_list(void);
int main(void) {
    unique_ptr<list_t> lista = create_list();
    if (!lista) {
        return -1;
    }

    int val1 = 1, val2 = 2, val3 = 3, val4 = 4, val5 = 5;

    cout << "Creo lista incial insertando al frente" << endl;
    push_front(&val1, lista);
    push_front(&val2, lista);
    push_front(&val3, lista);
    print_list(lista);
    cout << "Inserto dos elementos al final" << endl;
    push_back(&val4, lista);
    push_back(&val5, lista);
    print_list(lista);
    cout << "Inserto elemento von val 6 en la pos 2" << endl;
    int val6 = 6;
    insert(&val6, lista, 2);
    print_list(lista);

    cout << "Elimino elemento al frente" << endl; 
    erase_front(lista);
    print_list(lista);
    cout << "Elimino elemento al fondo" << endl;
    erase_back(lista);
    print_list(lista);
    cout << "Elimino elemento en la pos 2" << endl;
    erase(lista, 2);
    print_list(lista);

    free_list(lista);

    return 0;
}

unique_ptr<node_t> create_node(void* val) {
    unique_ptr<node_t> new_node = make_unique<node_t>();
    if (!new_node) {
        cout << "Error al crear un nodo" << endl;
        return nullptr;
    }
    new_node->value = make_unique<void*>(val);
    new_node->next = nullptr;
    return new_node;
}

unique_ptr<list_t> create_list(void) {
    unique_ptr<list_t> new_list = make_unique<list_t>();
    if (!new_list) {
        cout << "Error al crear una lista" << endl;
        return nullptr;
    }
    new_list->head = nullptr;
    new_list->tail = nullptr;
    new_list->size = 0;
    return new_list;
}
bool push_front(void* val, unique_ptr<list_t>& lista) {
    unique_ptr<node_t> new_node = create_node(val);
    if (!new_node) {
        cout << "Error" << endl;
        return false;
    }
    // caso lista vacia
    if (!lista->head) {
        lista->head = move(new_node);
        lista->tail = lista->head.get();
        lista->size++;
        return true;
    }
    //caso default
    new_node->next = move(lista->head);
    lista->head = move(new_node);
    lista->size++;
    return true;
}
bool push_back(void * val, unique_ptr<list_t>& lista){
    unique_ptr<node_t> new_node = create_node(val);
    if (!new_node) {
        cout << "Error" << endl;
        return false;
    }
    // caso lista vacia
    if (!lista->head) {
        lista->head = move(new_node);
        lista->tail = lista->head.get();
        lista->size++;
        return true;
    }
    // caso default

        lista->tail->next = move(new_node);
        lista->tail = lista->tail->next.get();
        lista->size ++;
        return true;
}
bool insert(void * val, unique_ptr<list_t>& lista,unsigned pos){
    if (pos > lista->size){ //mayor al largo de la lista
        cout << "Posicion mayor al largo de la lista -> Insertando elemento al final de la lista..." << endl;
        return push_back(val, lista); 
    }
    if (pos == lista->size){
        return push_back(val, lista);
    }
    if (pos == 0){
        return push_front(val, lista);
    }

    unique_ptr<node_t> new_node = create_node(val);
    if (!new_node) {
        cout << "Error" << endl;
        return false;
    }
    node_t* aux = lista->head.get();
    for (int i = 0; i<(pos-2);i++){ //me paro en el nodo anterior a la posicion
        aux = aux->next.get();
    }
    new_node->next = move(aux->next);
    aux->next = move(new_node);
    lista->size ++;
    return true;
}


bool erase_front(unique_ptr<list_t>& lista) {
    if (!lista->head) {
        cout << "La lista esta vacía" << endl;
        return false;
    }
    if (lista->size == 1){
        lista->head.reset();
        lista->tail = nullptr;
        lista->size--;
        return true;
    }
    lista->head = move(lista->head->next);
    if (!lista->head) {
        lista->tail = nullptr;
    }
    lista->size--;
    return true;
}

bool erase_back(unique_ptr<list_t>& lista){
    if (!lista->head){
        cout << "La lista esta vacia" << endl;
        return false;
    }
    if (lista->size == 1) {
        lista->head.reset();
        lista->tail = nullptr;
        lista->size--;
        return true;
    }
    //tengo que llegar hasta la pos antes de la tail
    node_t* aux = lista->head.get();
    for (int i = 0; i<((lista->size)-1);i++){ //me paro en el nodo anterior a la posicion
        aux = aux->next.get();
    }
    aux ->next.reset();
    lista->tail = aux;
    lista->size --;
    return true;
    }

bool erase(unique_ptr<list_t>& lista, unsigned pos){
    if (pos == 0 || lista->size == 1){
        return erase_front(lista);
    }
    if (pos == lista->size ){
        return erase_back(lista);
    }
    if (pos > lista->size){
        cout << "Posicion mayor al largo de la lista -> Eliminando elemento al final de la lista..." << endl;
        return erase_back(lista);
    }

    node*aux = lista->head.get();
    for (int i = 0;i<(pos-2);i++){
        aux = aux->next.get();
    }
    aux->next = move(aux->next->next);
    lista->size -- ;
    return true;
}
void print_list(unique_ptr<list_t>& lista) {
    if (!lista->head) {
        cout << "La lista esta vacia" << endl;
        return;
    }
    node_t* current = lista->head.get();
    while (current) {
        cout << *static_cast<int*>(*current->value) << " -> " ;
        current = current->next.get();
    }
    cout << "NULL" << endl;
}
void free_list(unique_ptr<list_t>& lista) {
    while (lista->head) {
        lista->head = move(lista->head->next);
    }
    lista->tail = nullptr;
    lista->size = 0;
}
