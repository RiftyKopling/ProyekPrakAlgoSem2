#include <iostream>
#include "fungsi.h"
using namespace std;

int main(){
    int kembali = 1, menu;
    char ulang = 'y';
    int n = sizeof(daftarguru) / sizeof(daftarguru[0]);

    do{
        system("cls");
        cout << "PROGRAM MANAJEMEN SEKOLAH" << endl;
        cout << "1. Tampilkan Data Guru" << endl;
        cout << "2. Tampilkan Data Siswa" << endl;
        cout << "3. Tambah Data Guru" << endl;
        cout << "4. Tambah Data Siswa" << endl;
        cout << "5. Cari Data Guru" << endl;
        cout << "6. Cari Data Siswa" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilih Menu : "; cin >> menu;
        cin.ignore();

        switch(menu){
            case 1 :
            do{
                system("cls");
                tampilkandataguru(daftarguru, jumlahguru);
                cout << "Apakah anda ingin kembali? y/n "; cin >> ulang;
                cin.ignore();
            }while(ulang == 'n');
            break;
            
            case 2 :
            do{
            system("cls");
            tampilkandatasiswa(daftarsiswa, jumlahsiswa);
                cout << "Apakah anda ingin kembali? y/n "; cin >> ulang;
                cin.ignore();
            }while(ulang == 'n');
            break;

            case 3 :
            do{
            system("cls");
            tambahguru();
                cout << "Apakah anda ingin kembali? y/n "; cin >> ulang;
                cin.ignore();
            }while(ulang == 'n');
            break;

            case 4 :
            do{
            system("cls");
            tambahsiswa();
                cout << "Apakah anda ingin kembali? y/n "; cin >> ulang;
                cin.ignore();
            }while(ulang == 'n');
            break; 


            case 5 :
            do{
                system("cls");
                cariguru();
                    cout << "Apakah anda ingin kembali? y/n "; cin >> ulang;
                    cin.ignore();
                }while(ulang == 'n');
            break;

            case 6 :
            do{
                system("cls");
                carisiswa();
                    cout << "Apakah anda ingin kembali? y/n "; cin >> ulang;
                    cin.ignore();
                }while(ulang == 'n');
            break;

            case 7 :
            kembali = 7;
            break;

            default :
            kembali = 1;
            break;

        }
    }while(kembali != 7);
}


