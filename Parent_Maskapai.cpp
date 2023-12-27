#include "Parent_Maskapai.h"
#include "RelasiorFitur.h"

void createList(List_parent &L){
    L.first = NULL;
}

adr_parent createElm(infotype_parent X){
    adr_parent P = new elmlist_parent;
    P->info = X;
    P->next = NULL;
    P->child = NULL;
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
    P->next = NULL; 
}

void deleteLast(List_parent &L, adr_parent &P){
    adr_parent Q = L.first;
    while (next(Q) != NULL){
        Q = next(Q);
    }
    P = Q->next;
    Q->next = NULL;
}

void deleteAfter(adr_parent Prec, adr_parent &P){
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}

void deleteMaskapaiX(List_parent &L, adr_parent P){
    adr_parent Q = L.first;
    adr_parent Z = NULL;
    if (Q == P){
        deleteFirst(L, Z);
    }else{
        while (Q->next != P){
            Q = Q->next;
        }
        deleteAfter(Q,P);
    }
    delete P;
}

adr_parent findElm(List_parent L, string nama_Maskapai){
    adr_parent P = L.first;
    while (P!= NULL){
        if (P->info.Nama_Masakapai== nama_Maskapai){
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
