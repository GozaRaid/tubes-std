#ifndef CHILD_PENERBANGAN_H_INCLUDED
#define CHILD_PENERBANGAN_H_INCLUDED
#include <iostream>
#include <chrono>
#include <iomanip>
#define next(P) P->next
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

using namespace std;
using namespace std::chrono;

struct Penerbangan {
    string nama_maskapai;
    string Kode;
    string Jenis;
    tm date_time;
    string Asal;
    string Tujuan;
    string Nama_Penumpang[100];
    int jumlah = 0;
};

typedef struct elmlist_child *adr_child;
typedef Penerbangan infotype_child;

struct elmlist_child {
    infotype_child info;
    adr_child next;
};

struct List_child {
    adr_child first;
    adr_child last;
};

void createList(List_child &L);
void insertFirst(List_child &L, adr_child P);
void insertLast(List_child &L, adr_child P);
void insertAfter(adr_child Prec, adr_child P);
void insertAsc(List_child &L, adr_child P);
void deleteFirst(List_child &L, adr_child &P);
void deleteLast(List_child &L, adr_child &P);
void deleteAfter(adr_child Prec, adr_child &P);
void deletePenerbaganX(List_child &L, string jenis, tm jadwal, string asal, string tujuan, adr_child &Z);

adr_child createElm(infotype_child X);
void printInfo(List_child L);
bool duplicateC(List_child L, string kode_penerbangan);
adr_child findchild(List_child L, string nama_penerbangan);
#endif // CHILD-PENERBANGAN_H_INCLUDED
