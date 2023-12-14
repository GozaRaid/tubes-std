#include "Child-Penerbangan.h"

void createList(List_child &L){
    L.first = NULL;
    L.last = NULL;
}

adr_child alokasi(infotype_child X){
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
        L.last = P;
    } else {
        L.last -> next = P;
        L.last = P;
    }
}

void insertAfter(adr_child Prec, adr_child P){
    P->next = Prec->next;
    Prec->next = P;
}

void insertAsc(List_child &L, adr_child P){
    system_clock::time_point input_time = system_clock::from_time_t(std::mktime(&P->info.date_time));
    system_clock::time_point time_first = system_clock::from_time_t(std::mktime(&L.first->info.date_time));
    system_clock::time_point time_last = system_clock::from_time_t(std::mktime(&L.last->info.date_time));
    if (L.first == NULL){
        insertFirst(L,P);
    } else if (input_time < time_first){
        insertFirst(L,P);
    } else if (input_time > time_last){
        insertLast(L,P);
    } else {
        adr_child Q = L.first;
        while (Q->next != NULL){
            system_clock::time_point temp_time = system_clock::from_time_t(std::mktime(&P->info.date_time));
            if (temp_time > input_time){
                insertAfter(Q,P);
            }
            P = next(P);
        }
    }
}

void deleteFirst(List_child &L, adr_child &P){
    P = L.first;
    L.first = L.first -> next;
}

void deleteLast(List_child &L, adr_child &P){
    P = L.last;
    adr_child Q = L.first;
    while (next(next(Q)) != NULL){
        Q = next(Q);
    }    
    L.last = Q;
    Q->next == NULL;
}

void deleteAfter(adr_child Prec, adr_child &P){
    P = Prec->next;
    Prec->next = P->next;
}

void deletePenerbaganX(List_child &L, string maskapai){
    adr_child P;
    adr_child Q = L.first;
    while (Q != NULL){
        if (L.first->info.nama_maskapai == maskapai){
            deleteFirst(L,P);
        } else if (L.last->info.nama_maskapai == maskapai){
            deleteLast(L,P);
        } else if (Q->next->info.nama_maskapai == maskapai){
            deleteAfter(Q,P);
        }
        Q=next(Q);
    }
}


//void printInfo(List_child L);
bool TemukanChild(List_child L, string Kode);
adr_child findchild(List_child L, string Kode);
