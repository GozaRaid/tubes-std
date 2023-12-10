#include "Parent.h"

void createList(List_parent &L){
    L.first = NULL;
}

adr_parent createElm(x infotype_parent){
    adr_parent P = new elmlist_parent;
    P->info = x;
    P->next = NULL;
    return P;
}

void insertFirst(List_parent &L, adr_parent P){
    P->next = L.first;
    L.first = P;
}

void insertAfter(List_parent &L, adr_parent Prec, adr_parent P){

}

void insertLast(List_parent &L, adr_parent P);
void deleteFirst(List_parent &L, adr_parent &P);
void deleteLast(List_parent &L, adr_parent &P);
void deleteAfter(List_parent &L, adr_parent Prec, adr_parent &P)
