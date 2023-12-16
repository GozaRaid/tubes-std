#include "RelasiorFitur.h"

adr_relasi addrelasi(adr_child penerbangan){
    adr_relasi P = new elm_relasi;
    P->nextPenerbangan = penerbangan;
    P->next = NULL;
    return P;
}

void insertrelasi(adr_parent &P, adr_child Q){
    adr_relasi Z = addrelasi(Q);
    cout << "apa1"<< endl;
    if (P->child == NULL) {
        cout << "apa2"<< endl;
           P->child = Z;
        } else {
            cout << "apa3"<< endl;
            adr_relasi Y = P->child;
            while (Y -> next != NULL){
                Y = Y->next;
            }
            Y->next = Z;
    }
}


// void deleteall_relasi(adr_parent &maskapai){
//     adr_relasi p;
//     while (maskapai.child != NULL) {
//         p = maskapai.child;
//         while (p->next != NULL) {
//             p = p->next;
//         }
//         p->next->Penerbangan = NULL;
//         p->next = NULL;
//     }
// }

// void delete_x(adr_parent &maskapai, tm jadwal ){
//     adr_relasi p,q;
//     p = maskapai.child;
//     while (p->next->penerbangan->info.date_time != jadwal){
//         p = p->next;
//     }
//     q = p->next;
//     p->next = q->next;
//     q->next = NULL;
//     q->penerbangan = NULL;
// }
