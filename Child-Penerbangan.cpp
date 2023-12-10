#include "Child-Penerbangan.h"

void createList(List_child &L){
    L.first = NULL;
    L.last = NULL;
}

adr_child alokasi(infotype X){
    adr_child P = new elmlist_child;
    P->info = X;
    P->next = NULL;
    return P;
}

void insertFirst(List_child &L, adr_child P){
    next(P)=first(L);
    first(L)=P;
}

void insertLast(List_child &L, adr_child P){
    if (L.first == NULL){
        L.first = P;
    } else {
        adr_child Q = L.first;
        while (Q->next != NULL){
            Q = next(Q);
        }
        Q -> next = P;
    }
}

void insertAfter(adr_child Prec, adr_child P){
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}

void insertAsc(List_child &L, adr_child P){

}

void deleteFirst(List_child &L, adr_child &P);
void deleteLast(List_child &L, adr_child &P);
void deleteAfter(adr_child Prec, adr_child &P);

void printInfo(List_child L);
bool TemukanChild(List_child L, string Kode);
adr_child findchild(List_child L, string Kode);
