#ifndef RELASIORFITUR_H_INCLUDED
#define RELASIORFITUR_H_INCLUDED

#include "Child_Penerbangan.h"
#include "Parent_Maskapai.h"

adr_relasi addrelasi(adr_child penerbangan);
void insertrelasi(adr_parent &P, adr_child Q);
void deleteall(adr_parent &maskapai);
void delete_x(adr_parent &maskapai, tm jadwal);
void printInfo(List_parent L, List_child Z, int pilihan);

#endif // RELASIORFITUR_H_INCLUDED
