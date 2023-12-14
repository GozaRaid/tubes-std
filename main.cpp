#include <iostream>
#include <iomanip>
#include <chrono>
#include <bits/stdc++.h>
#include <stdlib.h>
#include "Parent-Maskapai.h"
#include "Child-Penerbangan.h"
#include "RelasiorFitur.h"
using namespace std;

int main(){
    List_parent data_maskapai;
    List_child data_penerbangan;
    adr_parent P;
    adr_child C;
    createList(data_maskapai);
    createList(data_penerbangan);

    char selection;

    do{
        cout << "     Selamat datang di Data Penerbangan TOMAD \n";
        cout << "=====================================================\n";
        cout << "1.  Menambahkan Maskapai \n"; //1
        cout << "2.  Menambahkan Penerbangan\n"; //6
        cout << "3.  Mencari jadwal penerbangan dari Maskapai X\n"; //9
        cout << "4.  Mencari Data Maskapai X dan Menampilkannya\n"; //4
        cout << "5.  Menampilkan semua data Maskapai \n"; //2
        cout << "6.  Menampilkan semua data Penerbangan \n"; //tambahan
        cout << "7.  Menampilkan jumlah penerbangan berserta Data Penerbangan dari Maskapai X \n"; //8 & 11
        cout << "8.  Menghapus Penerbangan \n"; //10
        cout << "9.  Menghapus Maskapai \n"; //3
        cout << "10. Memindahkan Jadwal penerbangan"; //5
        cout << "\n";
        cout << "0.  Exit\n";
        cout << "=====================================================\n";
        cout << "Enter your selection: ";
        cin >> selection;
        cout << endl;

        switch (selection){
            case '1':{
                infotype_parent datasubmaskapai;
                cout << "Masukkan ID Maskapai: ";
                cin >> datasubmaskapai.Id_Maskapai;
                if (!duplicateP(data_maskapai,datasubmaskapai.Id_Maskapai)){
                    cout << "Masukkan Nama Maskapai: ";
                    string str;
                    // getline(cin,str);
                    getline(cin,datasubmaskapai.Nama_Masakapai);
                    getline(cin,datasubmaskapai.Nama_Masakapai);
                    //str = datasubmaskapai.Nama_Masakapai;
                    cout << "Masukkan Alamat Maskapai: ";
                    getline(cin,datasubmaskapai.Alamat_Maskapai);
                    cout << "Masukkan No.Telp Maskapai: ";
                    cin >> datasubmaskapai.Telp_maskapai;
                    P = createElm(datasubmaskapai);
                    insertLast(data_maskapai,P);
                    cout << "\nData Berhasil ditambah!!! \n";
                } else {
                    cout << "Data Maskapai dengan ID "<<datasubmaskapai.Id_Maskapai<<" Telah Ada \n";
                }
                cout << "Back to main menu? [Y/N]: ";
                cin >> selection;
                if (selection == 'Y'){
                    cout << "\033[2J\033[1;1H";
                } else {
                    selection = 0;
                }
            }
            break;
            case '2':{

            }
        }

    }while (selection != 0);
}
