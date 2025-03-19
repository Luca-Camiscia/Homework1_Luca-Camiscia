#include "Ej3.hpp"

int main(void) {
    shared_ptr<list_t> lista = create_list();
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
    cout << "Inserto elemento 2 super adelante" << endl;
    insert(&val2, lista, 80);
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
    cout << "Elimino num > largo de la lista" <<endl;
    erase(lista,100);
    print_list(lista);

    free_list(lista);

    return 0;
}

shared_ptr<node_t> create_node(void* val) {
    shared_ptr<node_t> new_node = make_shared<node_t>();
    new_node->value = make_shared<void*>(val);
    new_node->next = nullptr;
    return new_node;
}

shared_ptr<list_t> create_list(void) {
    shared_ptr<list_t> new_list = make_shared<list_t>();
    new_list->head = nullptr;
    new_list->tail = nullptr;
    new_list->size = 0;
    return new_list;
}
bool push_front(void* val, shared_ptr<list_t>& lista) {
    shared_ptr<node_t> new_node = create_node(val);
    // caso lista vacia
    if (!lista->head) {
        lista->head = new_node;
        lista->tail = lista->head;
        lista->size++;
        return true;
    }
    //caso default
    new_node->next = lista->head;
    lista->head = new_node;
    lista->size++;
    return true;
}
bool push_back(void * val, shared_ptr<list_t>& lista){
    shared_ptr<node_t> new_node = create_node(val);
    // caso lista vacia
    if (!lista->head) {
        lista->head = new_node;
        lista->tail = lista->head;
        lista->size++;
        return true;
    }
    // caso default

        lista->tail->next = new_node;
        lista->tail = lista->tail->next;
        lista->size ++;
        return true;
}
bool insert(void * val, shared_ptr<list_t>& lista,unsigned pos){
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

    shared_ptr<node_t> new_node = create_node(val);
    
    shared_ptr<node_t> aux= lista->head;
    for (int i = 0; i<(pos-2);i++){ //me paro en el nodo anterior a la posicion
        aux = aux->next;
    }
    new_node->next = aux->next;
    aux->next = new_node;
    lista->size ++;
    return true;
}


bool erase_front(shared_ptr<list_t>& lista) {
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
    lista->head = lista->head->next;
    if (!lista->head) {
        lista->tail = nullptr;
    }
    lista->size--;
    return true;
}

bool erase_back(shared_ptr<list_t>& lista){
    if (!lista->head){
        cout << "La lista esta vacia" << endl;
        return false;
    }
    if (lista->size == 1) {
        lista->head.reset();
        lista->tail.reset();
        lista->size--;
        return true;
    }
    //tengo que llegar hasta la pos antes de la tail
    shared_ptr<node_t> aux = lista->head;
    for (int i = 0; i<((lista->size)-2);i++){ //me paro en el nodo anterior a la posicion
        aux = aux->next;
    }
    aux ->next.reset();
    lista->tail = aux;
    lista->size --;
    return true;
    }

bool erase(shared_ptr<list_t>& lista, unsigned pos){
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
    aux->next = aux->next->next;
    lista->size -- ;
    return true;
}
void print_list(shared_ptr<list_t>& lista) {
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
void free_list(shared_ptr<list_t>& lista) {
    while (lista->head) {
        lista->head = move(lista->head->next);
    }
    lista->tail = nullptr;
    lista->size = 0;
}
