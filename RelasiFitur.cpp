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

adr_child findjadwal(adr_parent P, tm jadwal, string asal, string tujuan){
    adr_relasi Q = P->child;
    system_clock::time_point input_time = system_clock::from_time_t(std::mktime(&jadwal));
    while (Q != NULL){
        system_clock::time_point temp_time = system_clock::from_time_t(std::mktime(&Q->nextPenerbangan->info.date_time));
        if (Q->nextPenerbangan->info.Asal == asal && Q->nextPenerbangan->info.Tujuan == tujuan && input_time == temp_time){
            return Q->nextPenerbangan;
        }
        Q = Q->next;
    }
    return NULL;
}

int jmlhchild(adr_parent P){
    adr_relasi Q = P->child;
    int jumlah = 0;
    while (Q != NULL){
        jumlah++;
        Q = Q->next;
    }
    return jumlah;
}

void printInfo(List_parent L, bool kondisi){
    adr_parent P = L.first;
    cout << "List Maskapai: "<<endl;
    if(P==NULL){
        cout<<"data kosong \n";
    }
    while (P != NULL) {
        cout << "Nama Maskapai :" << P->info.Nama_Masakapai << "\n";
        cout << "Alamat Maskapai :" << P->info.Alamat_Maskapai << "\n";
        cout << "No-Telp Maskapai :" << P->info.Telp_maskapai << "\n";
        if (kondisi == true){
            cout << endl;
            cout << "List Penerbangan dengan Maskapai " << P->info.Nama_Masakapai << ": "<< endl;
            adr_relasi Q = P->child;
            if (Q == NULL){
                cout << "Belum memiliki penerbangan" << endl;
            }
            while (Q != NULL){
                cout << "Jenis Pesawat: "<<Q->nextPenerbangan->info.Jenis << endl;
                cout << "Waktu Penerbangan: "<< put_time(&Q->nextPenerbangan->info.date_time, "%Y-%m-%d %H:%M:%S")  << endl;
                cout << "Asal Keberangkatan: "<<Q->nextPenerbangan->info.Asal << endl;
                cout << "Tujuan Keberangkatan: "<<Q->nextPenerbangan->info.Tujuan << endl;
                cout << "List Penumpang: ";
                for (int i = 0; i < Q->nextPenerbangan->info.jumlah; i++){
                    cout << Q->nextPenerbangan->info.Nama_Penumpang[i] << " ";
                }
                cout << endl;
                cout << endl;
                Q = Q->next;
            }
        }
        P = P->next;
        cout << endl;
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

void delete_x(adr_parent &maskapai, string jenis , tm jadwal, string asal, string tujuan){
    adr_relasi p,q;
    p = maskapai->child;
    system_clock::time_point input_time = system_clock::from_time_t(std::mktime(&jadwal));
    system_clock::time_point time_first = system_clock::from_time_t(std::mktime(&p->nextPenerbangan->info.date_time));
    if (time_first == input_time && p->nextPenerbangan->info.Jenis == jenis && p->nextPenerbangan->info.Asal == asal && p->nextPenerbangan->info.Tujuan == tujuan) {
        q = maskapai->child;
        maskapai->child = maskapai->child->next;
        q->next == NULL;
    } else {
        system_clock::time_point time_temp = system_clock::from_time_t(std::mktime(&p->next->nextPenerbangan->info.date_time));
        while(time_temp != input_time && p->next->nextPenerbangan->info.Jenis != jenis && p->next->nextPenerbangan->info.Asal != asal && p->next->nextPenerbangan->info.Tujuan != tujuan) {
            p = p->next;
            system_clock::time_point time_temp = system_clock::from_time_t(std::mktime(&p->next->nextPenerbangan->info.date_time));
        }
        q = p->next;
        p->next = q->next;
        q->next = NULL;
        q->nextPenerbangan = NULL;
    }
}

void dlteallPenerbagan(List_child &L, string maskapai){
    adr_child Z = NULL;
    if (L.first->info.nama_maskapai == maskapai){
        deleteFirst(L,Z);
    } else if (L.last->info.nama_maskapai == maskapai) {
        deleteLast(L,Z);
    } else {
        cout << "testing1" << endl;
        adr_child Q = L.first;
        bool sudah = false;
        while (Q->next != NULL && !sudah){
            if (Q->next->info.nama_maskapai == maskapai){
                deleteAfter(Q,Z);
                sudah = true;
            }
            Q = Q-> next;
        }
    }
    Z = NULL;
}