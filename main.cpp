#include <iostream>
#include <iomanip>
#include <chrono>
#include <bits/stdc++.h>
#include <stdlib.h>
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
        cout << "               Selamat datang di Data Penerbangan TOMAD \n";
        cout << "======================================================================\n";
        cout << "1.  Menambahkan Maskapai \n"; //1
        cout << "2.  Menambahkan Penerbangan\n"; //6
        cout << "3.  Mencari jadwal penerbangan dari Maskapai X\n"; //9
        cout << "4.  Mencari Data Maskapai X, kemudian menampilkan jumlah penerbangan\n"; //4 & 11
        cout << "5.  Menampilkan semua data Maskapai \n"; //2
        cout << "6.  Menampilkan Data Maskapai berserta Data Penerbangan\n"; //8
        cout << "7.  Menghapus Penerbangan \n"; //10
        cout << "8.  Menghapus Maskapai \n"; //3
        cout << "9.  Memindahkan Jadwal penerbangan"; //5
        cout << "\n";
        cout << "0.  Exit\n";
        cout << "======================================================================\n";
        cout << "Enter your selection: ";
        cin >> selection;
        cout << endl;

        switch (selection){
            case '1':{
                cout << "\033[2J\033[1;1H";
                cout << "================== Menambah Maskapai ==================" << endl;
                infotype_parent datasubmaskapai;
                cout << "Masukkan ID Maskapai: ";
                cin >> datasubmaskapai.Id_Maskapai;
                if (!duplicateP(data_maskapai,datasubmaskapai.Id_Maskapai)){
                    cout << "Masukkan Nama Maskapai: ";
                    // string str;
                    // getline(cin,str);
                    getline(cin,datasubmaskapai.Nama_Masakapai);
                    getline(cin,datasubmaskapai.Nama_Masakapai);
                    //str = datasubmaskapai.Nama_Masakapai;
                    cout << "Masukkan Alamat Maskapai: ";
                    getline(cin,datasubmaskapai.Alamat_Maskapai);
                    cout << "Masukkan No.Telp Maskapai: ";
                    cin >>  datasubmaskapai.Telp_maskapai;
                    P = createElm(datasubmaskapai);
                    if (P->child == NULL){
                        cout << "sadasdsada" << endl;
                    } else {
                        cout << P->child << endl;
                    }
                    cout << P->info.Nama_Masakapai << endl;
                    cout << P->info.Id_Maskapai << endl;
                    cout << P->info.Alamat_Maskapai << endl;
                    cout << P->info.Telp_maskapai << endl;
                    insertLast(data_maskapai,P);
                    cout << "\nData Berhasil ditambah!!! \n";
                } else {
                    cout << "Data Maskapai dengan ID "<<datasubmaskapai.Id_Maskapai<<" Telah Ada \n";
                }
                cout << endl;
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
                cout << "\033[2J\033[1;1H";
                cout << "============= Menambah Jadwal Penerbangan =============" << endl;
                infotype_child datapenerbangan;
                string namapenu;
                adr_parent cariMask;
                cout << "Masukkan ID Penerbangan: ";
                getline(cin,datapenerbangan.Kode);
                getline(cin,datapenerbangan.Kode);
                if (!duplicateC(data_penerbangan,datapenerbangan.Kode)){
                    cout << "Masukkan Nama Maskapai: ";
                    getline(cin,datapenerbangan.nama_maskapai);
                    cariMask = findElm(data_maskapai,datapenerbangan.nama_maskapai);
                    if (cariMask != NULL){
                        cout << "Masukkan Jenis Flight: ";
                        getline(cin,datapenerbangan.Jenis);
                        cout << "Masukkan Waktu dan Tanggal (YYYY-MM-DD HH:MM): ";
                        cin >> get_time(&datapenerbangan.date_time, "%Y-%m-%d %H:%M");
                        cout << "Masukkan Asal Penerbangan: ";
                        getline(cin,datapenerbangan.Asal);
                        getline(cin,datapenerbangan.Asal);
                        cout << "Masukkan Tujuan Penerbangan: ";
                        getline(cin,datapenerbangan.Tujuan);
                        cout << "Masukkan Nama Penumpang (Apabila sudah selesai ketika '-'): "; 
                        for (int i = 0; i < 100; i++){
                            cin >> namapenu;
                            if (namapenu != "-"){
                                datapenerbangan.Nama_Penumpang[i] = namapenu;
                                datapenerbangan.jumlah++;
                            } else {
                                i = 999;
                            }
                        }
                        cout << "apaiya"<< endl;
                        C = createElm(datapenerbangan);
                        cout << "apaiya1"<< endl;
                        insertAsc(data_penerbangan,C);
                        cout << "apaiya2"<< endl;
                        insertrelasi(cariMask,C);
                        cout << "apaiya3"<< endl;
                        cout << "\nData Berhasil ditambah!!! \n";
                    } else {
                     cout << "Tidak ada penerbangan dengan maskapai "<< datapenerbangan.nama_maskapai << "\n";
                    }
                } else {
                    cout << "Penerbangan dengan ID "<< datapenerbangan.Kode << " Telah ada \n";
                }
                cout << endl;
                cout << "Back to main menu? [Y/N]: ";
                cin >> selection;
                if (selection == 'Y'){
                    cout << "\033[2J\033[1;1H";
                } else {
                    selection = 0;
                }
            }
            break;
            case '3':{
                cout << "\033[2J\033[1;1H";
                cout << "==== Mencari Jadwal Penerbangan dari sebuah Maskapai ====" << endl;
                string namamaskapai;
                adr_parent cariMask;
                infotype_child subpenerbangan;
                adr_child P;
                cout << "Masukkan Nama Maskapai: ";
                getline(cin,namamaskapai);
                getline(cin,namamaskapai);
                cariMask = findElm(data_maskapai,namamaskapai);
                if (cariMask != NULL){
                    cout << "Masukkan Waktu dan Tanggal (YYYY-MM-DD HH:MM): ";
                    cin >> get_time(&subpenerbangan.date_time, "%Y-%m-%d %H:%M");
                    cout << "Masukkan Asal Penerbangan: ";
                    getline(cin,subpenerbangan.Asal);
                    getline(cin,subpenerbangan.Asal);
                    cout << "Masukkan Tujuan Penerbangan: ";
                    getline(cin,subpenerbangan.Tujuan);
                    P = findjadwal (cariMask, subpenerbangan.date_time,subpenerbangan.Asal,subpenerbangan.Tujuan);
                    if (P != NULL){
                        cout << "Jadwal yang dicari ditemukan" << "\n";
                    } else {
                        cout << "Jadwal tidak ditemukan" << "\n";
                    }
                } else {
                    cout << "Tidak ada maskapai dengan nama "<< namamaskapai << "\n";
                }
                cout << endl;
                cout << "Back to main menu? [Y/N]: ";
                cin >> selection;
                if (selection == 'Y'){
                    cout << "\033[2J\033[1;1H";
                } else {
                    selection = 0;
                }
            }
            break;
            case '4':{
                cout << "\033[2J\033[1;1H";
                cout << "=== Mencari Data Maskapai berserta jumlah penerbangan ===" << endl;
                string namamaskapai;
                int jumlahpenerbangan;
                cout << "Masukkan Nama Maskapai: ";
                getline(cin,namamaskapai);
                getline(cin,namamaskapai);
                adr_parent P = findElm(data_maskapai,namamaskapai);
                if (P != NULL){
                    jumlahpenerbangan = jmlhchild(P);
                    cout << "Nama Maskapai :" << P->info.Nama_Masakapai << "\n";
                    cout << "Alamat Maskapai :" << P->info.Alamat_Maskapai << "\n";
                    cout << "No-Telp Maskapai :" << P->info.Telp_maskapai << "\n";
                    cout << "Jumlah Penerbangan :" << jumlahpenerbangan << "\n";
                } else {
                    cout << "Nama Maskapai " << namamaskapai << " tidak ditemukan.\n";
                }
                cout << endl;
                cout << "Back to main menu? [Y/N]: ";
                cin >> selection;
                if (selection == 'Y'){
                    cout << "\033[2J\033[1;1H";
                } else {
                    selection = 0;
                }
            }
            break;
            case '5':{
                cout << "\033[2J\033[1;1H";
                cout << "=============== Menampilkan Data Maskapai ===============" << endl;
                printInfo(data_maskapai,false);
                cout << endl;
                cout << "Back to main menu? [Y/N]: ";
                cin >> selection;
                if (selection == 'Y'){
                    cout << "\033[2J\033[1;1H";
                } else {
                    selection = 0;
                }
            }
            break;
            case '6':{
                cout << "\033[2J\033[1;1H";
                cout << "===== Menampilkan Data Maskapai berserta Penerbangan =====" << endl;
                printInfo(data_maskapai,true);
                cout << endl;
                cout << "Back to main menu? [Y/N]: ";
                cin >> selection;
                if (selection == 'Y'){
                    cout << "\033[2J\033[1;1H";
                } else {
                    selection = 0;
                }
            }
            break;
            case '7':{
                cout << "\033[2J\033[1;1H";
                cout << "============== Menghapus Jadwal Penerbangan ==============" << endl;
                infotype_child subpenerbangan;
                cout << "Masukkan Jenis Penerbangan yang mau dihapus: ";
                getline(cin,subpenerbangan.Jenis);
                getline(cin,subpenerbangan.Jenis);
                cout << "Masukkan Waktu dan Tanggal (YYYY-MM-DD HH:MM): ";
                cin >> get_time(&subpenerbangan.date_time, "%Y-%m-%d %H:%M");
                cout << "Asal Penerbangan: ";
                getline(cin, subpenerbangan.Asal);
                getline(cin,subpenerbangan.Asal);
                cout << "Masukkan Tujuan Penerbangan: ";
                getline(cin,subpenerbangan.Tujuan);
                adr_child P = NULL;
                deletePenerbaganX(data_penerbangan,subpenerbangan.Jenis,subpenerbangan.date_time,subpenerbangan.Asal,subpenerbangan.Tujuan,P);
                cout << "testing" << endl;
                if (P == NULL){
                    cout << "Jadwal Penerbangan tidak ditemukan" << endl;
                } else {
                    adr_parent cariMask = findElm(data_maskapai,P->info.nama_maskapai);
                    delete_x(cariMask,subpenerbangan.Jenis,subpenerbangan.date_time,subpenerbangan.Asal,subpenerbangan.Tujuan);
                    cout << "Jadwal Penerbangan berhasil dihapus" << endl;
                }
                cout << endl;
                cout << "Back to main menu? [Y/N]: ";
                cin >> selection;
                if (selection == 'Y'){
                    cout << "\033[2J\033[1;1H";
                } else {
                    selection = 0;
                }
            }
            break;
            case '8':{
                cout << "\033[2J\033[1;1H";
                cout << "================ Menghapus Data Maskapai ================" << endl;
            }
            break;
            case '9':{
                cout << "\033[2J\033[1;1H";
                cout << "============= Pemindahan Jadwal Penerbangan =============" << endl;
                cout << endl;
                cout << "Menginput data penerbangan yang mau pindah" << endl;
                infotype_child subpenerbangan;
                cout << "Masukkan Jenis Penerbangan yang mau dipindah: ";
                getline(cin,subpenerbangan.Jenis);
                getline(cin,subpenerbangan.Jenis);
                cout << "Masukkan Waktu dan Tanggal (YYYY-MM-DD HH:MM): ";
                cin >> get_time(&subpenerbangan.date_time, "%Y-%m-%d %H:%M");
                cout << "Asal Penerbangan: ";
                getline(cin, subpenerbangan.Asal);
                getline(cin,subpenerbangan.Asal);
                cout << "Masukkan Tujuan Penerbangan: ";
                getline(cin,subpenerbangan.Tujuan);
                adr_child P = NULL;
                deletePenerbaganX(data_penerbangan,subpenerbangan.Jenis,subpenerbangan.date_time,subpenerbangan.Asal,subpenerbangan.Tujuan,P);
                if (P != NULL){
                    cout << endl;
                    cout << "Masukkan Perubahan Waktu dan Tanggal (YYYY-MM-DD HH:MM):";
                    cin >> get_time(&P->info.date_time, "%Y-%m-%d %H:%M");
                    insertAsc(data_penerbangan,P);
                    cout << "Pemindahan jawdal berhasil" << endl;
                } else {
                    cout << "Jadwal yang ingin dirubah tidak ditemukan" << endl;
                }
                cout << endl;
                cout << "Back to main menu? [Y/N]: ";
                cin >> selection;
                if (selection == 'Y'){
                    cout << "\033[2J\033[1;1H";
                } else {
                    selection = 0;
                }
            }
            break;
            case '0':{
                return 0;
            }
            break;
        }

    }while (selection != 0);
}
