#ifndef CHILD-PENERBANGAN_H_INCLUDED
#define CHILD-PENERBANGAN_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

struct Penerbangan {
    string Kode;
    string Jenis;
    tm date_time;
    string Asal;
    string Tujuan;
    int Kapasitas;
    string Nama_Penumpang[Kapasitas];
};

typedef struct elmlist_child *adr_child;
typedef Penerbangan infotype_child;

struct elmlist_child {
    infotype_child info;
    adr_child next;
};

struct List_child {
    adr_child first;
};

void createList(List_child &L);
void insertFirst(List_child &L, adr_child P);
void insertLast(List_child &L, adr_child P);
void insertAfter(adr_child Prec, adr_child P);
void insertAsc(List_child &L, adr_child P);
void deleteFirst(List_child &L, adr_child &P);
void deleteLast(List_child &L, adr_child &P);
void deleteAfter(adr_child Prec, adr_child &P);

adr_child alokasi(infotype X);
void printInfo(List_child L);
bool TemukanChild(List_child L, string Kode);
adr_child findchild(List_child L, string Kode);
#endif // CHILD-PENERBANGAN_H_INCLUDED
