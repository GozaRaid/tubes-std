#include "Child_Penerbangan.h"

void createList(List_child &L){
    L.first = NULL;
    L.last = NULL;
}

adr_child createElm(infotype_child X){
    adr_child P = new elmlist_child;
    P->info = X;
    P->next = NULL;
    return P;
}

void insertFirst(List_child &L, adr_child P){
    if (L.first == NULL){
        L.first = P;
        L.last = P;
    } else {
        next(P)=first(L);
        first(L)=P;
    }
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
    if (L.first == NULL){
        insertFirst(L,P);
    } else {  
        system_clock::time_point time_first = system_clock::from_time_t(std::mktime(&L.first->info.date_time));
        system_clock::time_point time_last = system_clock::from_time_t(std::mktime(&L.last->info.date_time)); 
        if (input_time < time_first){
            insertFirst(L,P);
        } else if (input_time > time_last){
            insertLast(L,P);
        } else {
            adr_child Q = L.first;
            bool sudah = false;
            while (Q->next != NULL && !sudah){
                system_clock::time_point temp_time = system_clock::from_time_t(std::mktime(&Q->info.date_time));
                if (temp_time > input_time){
                    insertAfter(Q,P);
                    sudah = true;
                }
                Q = next(Q);
            }
        }
    }
}

void deleteFirst(List_child &L, adr_child &P){
    P = L.first;
    L.first = L.first -> next;
    P->next = NULL; 
}

void deleteLast(List_child &L, adr_child &P){
    P = L.last;
    adr_child Q = L.first;
    while (next(Q) != L.last){
        Q = next(Q);
    }    
    L.last = Q;
    L.last->next = NULL;
}

void deleteAfter(adr_child Prec, adr_child &P){
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}

void deletePenerbaganX(List_child &L, string jenis, tm jadwal, string asal, string tujuan, adr_child &Z){
    system_clock::time_point input_time = system_clock::from_time_t(std::mktime(&jadwal));
    system_clock::time_point time_first = system_clock::from_time_t(std::mktime(&L.first->info.date_time));
    system_clock::time_point time_last = system_clock::from_time_t(std::mktime(&L.last->info.date_time)); 
    if (L.first->info.Jenis == jenis && L.first->info.Asal == asal && L.first->info.Tujuan == tujuan && input_time == time_first){
        deleteFirst(L,Z);
    } else if (L.last->info.Jenis == jenis && L.last->info.Asal == asal && L.last->info.Tujuan == tujuan && input_time == time_last) {
        deleteLast(L,Z);
    } else {
        adr_child Q = L.first;
        bool sudah = false;
        while (Q->next != NULL && !sudah){
            system_clock::time_point time_temp = system_clock::from_time_t(std::mktime(&Q->next->info.date_time)); 
            if (Q->next->info.Jenis == jenis && time_temp == input_time && Q->next->info.Asal == asal && Q->next->info.Tujuan == tujuan){
                deleteAfter(Q,Z);
                sudah = true;
            }
            Q = Q-> next;
        }
    }
}


void printInfo(List_child L){
    adr_child Q = L.first;
        while (Q != NULL){
            cout << "Jenis Pesawat: "<<Q->info.Jenis << endl;
            cout << "Waktu Penerbangan: "<< put_time(&Q->info.date_time, "%Y-%m-%d %H:%M:%S")  << endl;
            cout << "Asal Keberangkatan: "<<Q->info.Asal << endl;
            cout << "Tujuan Keberangkatan: "<<Q->info.Tujuan << endl;
            cout << endl;
            Q = Q-> next;
        }
}

bool duplicateC(List_child L, string kode_penerbangan){
    adr_child P = L.first;
    while (P!=NULL){
        if (P->info.Kode == kode_penerbangan){
            return true;
        }
        P = next(P);
    }
    return false;
}
