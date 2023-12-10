#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define child(P) P->child
#include <iostream>

using namespace std;

struct Maskapai {
    int Id_Maskapai;
    string Nama_Masakapai;
    string Alamat_Maskapai;
    string Telp_maskapai;
};

typedef Maskapai infotype_parent;
typedef struct elmlist_parent *adr_parent;

struct elmlist_parent {
    infotype_parent info;
    adr_parent next;
//    list child
};

struct List_parent {
    adr_parent first;
};
void apaitu(List_parent &L);
void createList(List_parent &L);
void insertFirst(List_parent &L, adr_parent P);
void insertAfter(List_parent &L, adr_parent Prec, adr_parent P);
void insertLast(List_parent &L, adr_parent P);
void deleteFirst(List_parent &L, adr_parent &P);
void deleteLast(List_parent &L, adr_parent &P);
void deleteAfter(List_parent &L, adr_parent Prec, adr_parent &P);

adr_parent findElm(List_parent L, int x);
adr_parent createElm(int id_peng, string nama_peng);
bool duplicate(List_parent L, int x);
void printInfo(List_parent L,bool kondisi);
bool caridata(List_parent L);
void deletefirstchild(List_parent L,int id);
#endif // PARENT_H_INCLUDED
