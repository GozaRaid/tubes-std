#ifndef PARENT-MASKAPAI_H_INCLUDED
#define PARENT-MASKAPAI_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define child(P) P->child

using namespace std;

struct Maskapai {
    int Id_Maskapai;
    string Nama_Masakapai;
    string Alamat_Maskapai;
    int Telp_maskapai;
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

void createList(List_parent &L);
void insertLast(List_parent &L, adr_parent P);
void deleteFirst(List_parent &L, adr_parent &P);
void deleteLast(List_parent &L, adr_parent &P);
void deleteAfter(List_parent &L, adr_parent Prec, adr_parent &P);

adr_parent findElm(List_parent L, int ID_Maskapai);
adr_parent createElm(infotype_parent X);
bool duplicateP(List_parent L, int ID_Maskapai);
// printInfo(List_parent L,bool kondisi);
void deletefirstchild(List_parent L,int id);

#endif // PARENT-MASKAPAI_H_INCLUDED
