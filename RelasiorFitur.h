#ifndef RELASIORFITUR_H_INCLUDED
#define RELASIORFITUR_H_INCLUDED

#include "Parent-Maskapai.h"
#include "Child-Penerbangan.h"


#include "Child-Penerbangan.h"
#include "Parent-Maskapai.h" 
#include <iostream>
using namespace std;

typedef struct relasi *adr_relasi;
struct relasi {
    adr_child Penerbangan;
    adr_relasi next;
};

adr_relasi addrelasi(adr_parent maskapai, adr_child Penerbangan);
void deleteall(adr_parent &maskapai);
void delete_x(adr_parent &maskapai, tm jadwal);
void printInfo(List_parent L, List_child Z, int pilihan);

#endif // RELASIORFITUR_H_INCLUDED
