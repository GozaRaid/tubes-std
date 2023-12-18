#ifndef RELASIORFITUR_H_INCLUDED
#define RELASIORFITUR_H_INCLUDED

#include "Child_Penerbangan.h"
#include "Parent_Maskapai.h"

adr_relasi addrelasi(adr_child penerbangan);
void insertrelasi(adr_parent &P, adr_child Q);
adr_child findjadwal(adr_parent P, tm jadwal, string asal, string tujuan);
int jmlhchild(adr_parent P);
void deleteall(adr_parent &maskapai);
void delete_x(adr_parent &maskapai, string jenis ,tm jadwal, string asal, string tujuan);
void printInfo(List_parent L,bool kondisi);
void dlteallPenerbagan(List_child &L, string maskapai);

#endif // RELASIORFITUR_H_INCLUDED
