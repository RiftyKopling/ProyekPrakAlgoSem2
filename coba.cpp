#include <iostream>
using namespace std;
const int maksguru = 10, makssiswa = 20;
int jumlahtambah, jumlahguru = 5, jumlahsiswa = 2;

struct guru{
    string nama;
    int nip;
    string mapel;
};

struct siswa{
    string nama;
    int nis;
    string kelas;
};

guru daftarguru[maksguru] =   {
    {"Hisyam L Baihaqi S.Pd., M.Pd.", 123456789, "Agama Katolik"},
    {"Fiernaz Ingga Pratamai S.Pd., M.Pd.", 123456788, "Agama Hindu"},
    {"Aushaf Fathin Irsyad Nabil S.Pd., M.Pd.", 123456787, "Agama Buddha"},
    {"Raihan Natawangsa S.Pd., M.Pd.", 123456786, "Agama Konghucu"},
    {"Timothy Brian Megaranto Padang S.Pd., M.Pd.", 123456789, "Agama Islam"}
    };


siswa daftarsiswa[makssiswa] = {
    {"Muhammad Rifty Alfattah", 123240093, "VII A"},
    {"Utia Fajriatul Arofah", 123240096, "VII B"}
    };

void tampilkandataguru(guru daftarguru[], int jumlahguru, int index = 0 ){
    if(index == jumlahguru) return;
        cout << "Guru ke-" << index + 1 << " : " << daftarguru[index].nama << endl;
        cout << "NIP       : " << daftarguru[index].nip << endl;
        cout << "Mapel     : " << daftarguru[index].mapel << endl;
        cout << endl;
    tampilkandataguru(daftarguru, jumlahguru, index + 1);
}

void tampilkandatasiswa(siswa daftarsiswa[], int n, int index = 0 ){
    if(index == n) return;
        cout << "Siswa ke-" << index + 1 << " : " << daftarsiswa[index].nama << endl;
        cout << "NIS        : " << daftarsiswa[index].nis << endl;
        cout << "Kelas      : " << daftarsiswa[index].kelas << endl;
        cout << endl;
    tampilkandatasiswa(daftarsiswa, n, index + 1);
}

void tambahguru(){
    cout << "Berapa banyak data guru yang ingin ditambahkan : ";
    cin >> jumlahtambah;
    cin.ignore();

    for (int i = 0; i < jumlahtambah; i++) {
        if (jumlahguru >= maksguru) {
            cout << "Maaf, kapasitas data guru sudah penuh!" << endl;
            break;
        }
        cout << endl;
        cout << "Nama Guru  : ";
        getline(cin, daftarguru[jumlahguru].nama);
        cout << "NIP Guru   : ";
        cin >> daftarguru[jumlahguru].nip;
        cin.ignore();
        cout << "Mapel      : ";
        getline(cin, daftarguru[jumlahguru].mapel);
        jumlahguru++;
    }
}

void tambahsiswa(){
    cout << "Berapa banyak siswa yang ingin ditambahkan : ";
    cin >> jumlahtambah;
    cin.ignore();

    for (int i = 0; i < jumlahtambah; i++) {
        if (jumlahsiswa >= makssiswa) {
            cout << "Maaf, kapasitas data siswa sudah penuh!" << endl;
            break;
        }
        cout << endl;
        cout << "Nama Siswa  : ";
        getline(cin, daftarsiswa[jumlahsiswa].nama);
        cout << "NIS Siswa   : ";
        cin >> daftarsiswa[jumlahsiswa].nis;
        cin.ignore();
        cout << "Kelas Siswa : ";
        getline(cin, daftarsiswa[jumlahsiswa].kelas);
        jumlahsiswa++;
    }   
}

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
        cout << "5. Keluar" << endl;
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
            kembali = 5;
            break;

            default :
            kembali = 1;
            break;

        }
    }while(kembali != 5);
}


