#include "Parent-Maskapai.h"

void createList(List_parent &L){
    L.first = NULL;
}

adr_parent createElm(infotype_parent X){
    adr_parent P = new elmlist_parent;
    P->info = X;
    P->next = NULL;
    return P;
}

void insertLast(List_parent &L, adr_parent P){
    if (L.first == NULL){
        L.first = P;
    } else {
        adr_parent Q = L.first;
        while (Q->next != NULL){
            Q = next(Q);
        }
        Q -> next = P;
    }
}

void deleteFirst(List_parent &L, adr_parent &P){
    P = L.first;
    L.first = L.first->next;
}
void deleteLast(List_parent &L, adr_parent &P){
    
}
//void deleteAfter(List_parent &L, adr_parent Prec, adr_parent &P)

adr_parent findElm(List_parent L, int ID_Maskapai){
    adr_parent P = L.first;
    while (P!= NULL){
        if (P->info.Id_Maskapai== ID_Maskapai){
            return P;
        }
        P = next(P);
    }
    return P;
}

bool duplicateP(List_parent L, int ID_Maskapai){
    adr_parent P = L.first;
    while (P!=NULL){
        if (P->info.Id_Maskapai == ID_Maskapai){
            return true;
        }
        P = next(P);
    }
    return false;
}

/*void printInfo(List_parent L,bool kondisi){

} */
//
