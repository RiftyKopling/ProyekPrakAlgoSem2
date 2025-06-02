#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
const int maksguru = 20, makssiswa = 30, jumlahMapel = 10;
int jumlahtambah, jumlahguru = 5, jumlahsiswa = 2, percobaan = 3;

struct nilai
{
    string mapel[jumlahMapel] = {"Matematika", "Bahasa Indonesia", "IPA", "IPS", "Bahasa Inggris",
                                 "Agama", "Seni Budaya", "PJOK", "PKN", "Prakarya"};
    int nilaiMapel[jumlahMapel];

    nilai()
    {
        for (int i = 0; i < jumlahMapel; i++)
        {
            nilaiMapel[i] = 0;
        }
    }
};

struct guru
{
    string nama;
    int nip;
    string kodeMapel;
    string mapel;
};

struct siswa
{
    string nama;
    int nis;
    string kelas;
    string tanggalLahir;
    nilai nilai;
};

guru daftarguru[maksguru]; // = {
//     {"Hisyam L Baihaqi S.Pd., M.Pd.", 123456789, "12345", "Agama Katolik"},
//     {"Fiernaz Ingga Pratama S.Pd., M.Pd.", 123456788, "11111", "Agama Hindu"},
//     {"Aushaf Fathin Irsyad Nabil S.Pd., M.Pd.", 123456787, "12121", "Agama Buddha"},
//     {"Raihan Natawangsa S.Pd., M.Pd.", 123456786, "22334", "Agama Konghucu"},
//     {"Timothy Brian Megaranto Padang S.Pd., M.Pd.", 123456789, "88990", "Agama Islam"}};

siswa daftarsiswa[makssiswa]; // = {
                              // {"Muhammad Rifty Alfattah", 123240093, "VII A", "121205"},
                              // {"Utia Fajriatul Arofah", 123240096, "VII B", "280104"}};

nilai daftarNilai[jumlahMapel];

void muatguru(const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "Gagal membuka file guru\n";
        return;
    }

    file >> jumlahguru;
    file.ignore();
    for (int i = 0; i < jumlahguru; i++)
    {
        getline(file, daftarguru[i].nama);
        file >> daftarguru[i].nip;
        file.ignore();
        getline(file, daftarguru[i].kodeMapel);
        getline(file, daftarguru[i].mapel);
    }
    file.close();
}

void muatsiswa(const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "Gagal membuka file siswa\n";
        return;
    }

    file >> jumlahsiswa;
    file.ignore();
    for (int i = 0; i < jumlahsiswa; i++)
    {
        getline(file, daftarsiswa[i].nama);
        file >> daftarsiswa[i].nis;
        file.ignore();
        getline(file, daftarsiswa[i].kelas);
        getline(file, daftarsiswa[i].tanggalLahir);
    }
    file.close();
}

void muatnilai(const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "Gagal membuka file nilai\n";
        return;
    }

    int jumlah;
    file >> jumlah;
    for (int i = 0; i < jumlah; i++)
    {
        for (int j = 0; j < jumlahMapel; j++)
        {
            file >> daftarsiswa[i].nilai.nilaiMapel[j];
        }
    }
    file.close();
}

void simpanguru(const string &filename)
{
    ofstream file(filename);
    file << jumlahguru << endl;
    for (int i = 0; i < jumlahguru; i++)
    {
        file << daftarguru[i].nama << endl;
        file << daftarguru[i].nip << endl;
        file << daftarguru[i].kodeMapel << endl;
        file << daftarguru[i].mapel << endl;
    }
    file.close();
}

void simpansiswa(const string &filename)
{
    ofstream file(filename);
    file << jumlahsiswa << endl;
    for (int i = 0; i < jumlahsiswa; i++)
    {
        file << daftarsiswa[i].nama << endl;
        file << daftarsiswa[i].nis << endl;
        file << daftarsiswa[i].kelas << endl;
        file << daftarsiswa[i].tanggalLahir << endl;
    }
    file.close();
}

void simpannilai(const string &filename)
{
    ofstream file(filename);
    file << jumlahsiswa << endl;
    for (int i = 0; i < jumlahsiswa; i++)
    {
        for (int j = 0; j < jumlahMapel; j++)
        {
            file << daftarsiswa[i].nilai.nilaiMapel[j] << " ";
        }
        file << endl;
    }
    file.close();
}

void tampilkandataguru(guru* daftarguru, int jumlahguru, int index = 0)
{
    if (index == jumlahguru)
        return;
    cout << left;
    cout << setw(8) << "Guru ke-" << setw(5) << index + 1 << setw(3) << "  : " << daftarguru[index].nama << endl;
    cout << "NIP            : " << daftarguru[index].nip << endl;
    cout << "Mapel          : " << daftarguru[index].mapel << endl;
    cout << endl;
    tampilkandataguru(daftarguru, jumlahguru, index + 1);
}

void tampilkandatasiswa(siswa* daftarsiswa, int n, int index = 0)
{
    if (index == n)
        return;
    cout << setw(8) << "Siswa ke-" << setw(3) << index + 1 << setw(3) << "  : " << daftarsiswa[index].nama << endl;
    cout << "NIS           : " << daftarsiswa[index].nis << endl;
    cout << "Kelas         : " << daftarsiswa[index].kelas << endl;
    cout << endl;
    tampilkandatasiswa(daftarsiswa, n, index + 1);
}

void tambahguru()
{
    cout << "Berapa banyak data guru yang ingin ditambahkan : ";
    cin >> jumlahtambah;
    cin.ignore();

    for (int i = 0; i < jumlahtambah; i++)
    {
        if (jumlahguru >= maksguru)
        {
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
    simpanguru("guru.txt");
}

void tambahsiswa()
{
    cout << "Berapa banyak siswa yang ingin ditambahkan : ";
    cin >> jumlahtambah;
    cin.ignore();

    for (int i = 0; i < jumlahtambah; i++)
    {
        if (jumlahsiswa >= makssiswa)
        {
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
    simpansiswa("siswa.txt");
}

void cariguru()
{
    string inputnip;
    cout << "Masukkan sebagian NIP: ";
    cin >> inputnip;

    cout << "Hasil pencarian: " << endl;
    bool ditemukan = false;

    for (int i = 0; i < jumlahguru; i++)
    {
        string nipstr = to_string(daftarguru[i].nip);
        int lenMain = nipstr.length();
        int lenSub = inputnip.length();

        for (int j = 0; j <= lenMain - lenSub; j++)
        {
            if (nipstr.substr(j, lenSub) == inputnip)
            {
                cout << "Nama       : " << daftarguru[i].nama << endl;
                cout << "NIP        : " << daftarguru[i].nip << endl;
                cout << "Mapel      : " << daftarguru[i].mapel << endl;
                cout << endl;
                ditemukan = true;
                break;
            }
        }
    }

    if (!ditemukan)
    {
        cout << "Tidak ada guru dengan NIP yang mengandung \"" << inputnip << "\".\n";
    }
}

void carisiswa()
{
    string inputnis;
    cout << "Masukkan sebagian NIS: ";
    cin >> inputnis;

    cout << "Hasil pencarian: " << endl;
    bool ditemukan = false;

    for (int i = 0; i < jumlahsiswa; i++)
    {
        string nisstr = to_string(daftarsiswa[i].nis);
        int lenMain = nisstr.length();
        int lenSub = inputnis.length();

        for (int j = 0; j <= lenMain - lenSub; j++)
        {
            if (nisstr.substr(j, lenSub) == inputnis)
            {
                cout << "Nama       : " << daftarsiswa[i].nama << endl;
                cout << "NIS        : " << daftarsiswa[i].nis << endl;
                cout << "Kelas      : " << daftarsiswa[i].kelas << endl;
                cout << endl;
                ditemukan = true;
                break;
            }
        }
    }

    if (!ditemukan)
    {
        cout << "Tidak ada siswa dengan NIS yang mengandung \"" << inputnis << "\".\n";
    }
}

void inputNilai()
{
    string inputnis;
    cout << "Masukkan sebagian NIS: ";
    cin >> inputnis;

    cout << "Hasil pencarian: " << endl;
    bool ditemukan = false;

    cout << "Input nilai" << endl;
    for (int i = 0; i < jumlahsiswa; i++)
    {
        string nisstr = to_string(daftarsiswa[i].nis);
        int lenMain = nisstr.length();
        int lenSub = inputnis.length();

        for (int j = 0; j <= lenMain - lenSub; j++)
        {
            if (nisstr.substr(j, lenSub) == inputnis)
            {
                cout << "\nSiswa ke-" << i + 1 << endl;
                cout << "Nama       : " << daftarsiswa[i].nama << endl;
                cout << "NIS        : " << daftarsiswa[i].nis << endl;
                cout << "Kelas      : " << daftarsiswa[i].kelas << endl;
                cout << "Masukkan Nilai :" << endl;
                for (int j = 0; j < jumlahMapel; j++)
                {
                    cout << daftarsiswa[i].nilai.mapel[j] << " : ";
                    cin >> daftarsiswa[i].nilai.nilaiMapel[j];
                }
                ditemukan = true;
                break;
            }
        } 
    }cout << "Nilai berhasil ditambahkan!" << endl;
        cout << "=====================================================" << endl;
    simpannilai("nilai.txt");
}

void daftarNilaiSiswa()
{
    cout << "==================== DAFTAR NILAI ====================" << endl;
    for (int i = 0; i < jumlahsiswa; i++)
    {
        cout << "\nSiswa ke-" << i + 1 << endl;
        cout << "Nama       : " << daftarsiswa[i].nama << endl;
        cout << "NIS        : " << daftarsiswa[i].nis << endl;
        cout << "Kelas      : " << daftarsiswa[i].kelas << endl;
        cout << "Nilai      :" << endl;
        for (int j = 0; j < jumlahMapel; j++)
        {
            cout << left << setw(18) << daftarsiswa[i].nilai.mapel[j] << " : " << daftarsiswa[i].nilai.nilaiMapel[j] << endl;
        }
        cout << "\n=====================================================" << endl;
    }
}

bool loginGuru(int username, string password, guru daftarguru[], int jumlahguru)
{
    for (int i = 0; i < jumlahguru; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((daftarguru[i].nip == username) && (daftarguru[i].kodeMapel == password))
            {
                return true;
            }
        }
    }
    return false;
}

bool loginSiswa(int username, string password, siswa daftarsiswa[], int jumlahsiswa)
{
    for (int i = 0; i < jumlahsiswa; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((daftarsiswa[i].nis == username) && (daftarsiswa[i].tanggalLahir == password))
            {
                return true;
            }
        }
    }
    return false;
}

void sortingNilaiPerMapel()
{
    cout << "=== Pilih Mata Pelajaran ===" << endl;
    for (int i = 0; i < jumlahMapel; i++)
    {
        cout << i + 1 << ". " << daftarsiswa[0].nilai.mapel[i] << endl;
    }

    int pilihan;
    cout << "Masukkan nomor mapel yang ingin dicari: ";
    cin >> pilihan;
    cin.ignore();

    if (pilihan < 1 || pilihan > jumlahMapel)
    {
        cout << "Pilihan tidak valid!" << endl;
        return;
    }

    int indexMapel = pilihan - 1;

    siswa temp[makssiswa];
    for (int i = 0; i < jumlahsiswa; i++)
    {
        temp[i] = daftarsiswa[i];
    }

    for (int i = 0; i < jumlahsiswa - 1; i++)
    {
        for (int j = 0; j < jumlahsiswa - i - 1; j++)
        {
            if (temp[j].nilai.nilaiMapel[indexMapel] < temp[j + 1].nilai.nilaiMapel[indexMapel])
            {
                swap(temp[j], temp[j + 1]);
            }
        }
    }

    cout << "\n========== Daftar Nilai Siswa (Mapel: " << daftarsiswa[0].nilai.mapel[indexMapel] << ") ==========" << endl;
    for (int i = 0; i < jumlahsiswa; i++)
    {
        cout << left 
             << setw(5) << i + 1 
             << setw(25) << temp[i].nama
             << setw(15) << temp[i].nis 
             << setw(10) << temp[i].kelas 
             << setw(8) << temp[i].nilai.nilaiMapel[indexMapel] 
             << endl;
    }
}

void menuguru()
{
    int kembali = 1, menu, pilihRole;
    char ulang = 'y';
    int n = sizeof(daftarguru) / sizeof(daftarguru[0]);

    do
    {
        system("cls");
        cout << "PROGRAM MANAJEMEN SEKOLAH" << endl;
        cout << "1. Tampilkan Data Guru" << endl;
        cout << "2. Tampilkan Data Siswa" << endl;
        cout << "3. Tambah Data Guru" << endl;
        cout << "4. Tambah Data Siswa" << endl;
        cout << "5. Input nilai" << endl;
        cout << "6. Daftar nilai" << endl;
        cout << "7. Cari guru" << endl;
        cout << "8. Cari siswa" << endl;
        cout << "9. Ranking Nilai Siswa" << endl;
        cout << "10. Keluar" << endl;
        cout << "Pilih Menu : ";
        cin >> menu;
        cin.ignore();

        switch (menu)
        {
        case 1:
            do
            {
                system("cls");
                tampilkandataguru(daftarguru, jumlahguru);
                cout << "Apakah anda ingin kembali? y/n ";
                cin >> ulang;
                cin.ignore();
            } while (ulang == 'n');
            break;

        case 2:
            do
            {
                system("cls");
                tampilkandatasiswa(daftarsiswa, jumlahsiswa);
                cout << "Apakah anda ingin kembali? y/n ";
                cin >> ulang;
                cin.ignore();
            } while (ulang == 'n');
            break;

        case 3:
            do
            {
                system("cls");
                tambahguru();
                cout << "Apakah anda ingin kembali? y/n ";
                cin >> ulang;
                cin.ignore();
            } while (ulang == 'n');
            break;

        case 4:
            do
            {
                system("cls");
                tambahsiswa();
                cout << "Apakah anda ingin kembali? y/n ";
                cin >> ulang;
                cin.ignore();
            } while (ulang == 'n');
            break;

        case 5:
            do
            {
                system("cls");
                inputNilai();
                cout << "Apakah anda ingin kembali? y/n ";
                cin >> ulang;
                cin.ignore();
            } while (ulang == 'n');
            break;

        case 6:
            do
            {
                system("cls");
                daftarNilaiSiswa();
                cout << "Apakah anda ingin kembali? y/n ";
                cin >> ulang;
                cin.ignore();
            } while (ulang == 'n');
            break;

        case 7:
            do
            {
                system("cls");
                cariguru();
                cout << "Apakah anda ingin kembali? y/n ";
                cin >> ulang;
                cin.ignore();
            } while (ulang == 'n');
            break;

        case 8:
            do
            {
                system("cls");
                carisiswa();
                cout << "Apakah anda ingin kembali? y/n ";
                cin >> ulang;
                cin.ignore();
            } while (ulang == 'n');
            break;

        case 9:
            do
            {
                system("cls");
                sortingNilaiPerMapel();
                cout << "Apakah anda ingin kembali? y/n ";
                cin >> ulang;
                cin.ignore();
            } while (ulang == 'n');
            break;

        case 10:
            return;

        default:
            kembali = 1;
            break;
        }
    } while (kembali != 9);
}

void menumurid()
{
    int kembali = 1, menu, pilihRole;
    char ulang = 'y';
    int n = sizeof(daftarguru) / sizeof(daftarguru[0]);

    do
    {
        system("cls");
        cout << "PROGRAM MANAJEMEN SEKOLAH" << endl;
        cout << "1. Tampilkan Data Guru" << endl;
        cout << "2. Tampilkan Data Siswa" << endl;
        cout << "3. Daftar nilai" << endl;
        cout << "4. Cari guru" << endl;
        cout << "5. Cari siswa" << endl;
        cout << "6. Ranking Nilai Siswa" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilih Menu : ";
        cin >> menu;
        cin.ignore();

        switch (menu)
        {
        case 1:
            do
            {
                system("cls");
                tampilkandataguru(daftarguru, jumlahguru);
                cout << "Apakah anda ingin kembali? y/n ";
                cin >> ulang;
                cin.ignore();
            } while (ulang == 'n');
            break;

        case 2:
            do
            {
                system("cls");
                tampilkandatasiswa(daftarsiswa, jumlahsiswa);
                cout << "Apakah anda ingin kembali? y/n ";
                cin >> ulang;
                cin.ignore();
            } while (ulang == 'n');
            break;

        case 3:
            do
            {
                system("cls");
                daftarNilaiSiswa();
                cout << "Apakah anda ingin kembali? y/n ";
                cin >> ulang;
                cin.ignore();
            } while (ulang == 'n');
            break;

        case 4:
            do
            {
                system("cls");
                cariguru();
                cout << "Apakah anda ingin kembali? y/n ";
                cin >> ulang;
                cin.ignore();
            } while (ulang == 'n');
            break;

        case 5:
            do
            {
                system("cls");
                carisiswa();
                cout << "Apakah anda ingin kembali? y/n ";
                cin >> ulang;
                cin.ignore();
            } while (ulang == 'n');
            break;

        case 6:
            do
            {
                system("cls");
                sortingNilaiPerMapel();
                cout << "Apakah anda ingin kembali? y/n ";
                cin >> ulang;
                cin.ignore();
            } while (ulang == 'n');
            break;

        case 7:
            return;

        default:
            kembali = 1;
            break;
        }
    } while (kembali != 7);
}

int main()
{
    int kembali = 1, pilih;
    char ulang = 'y';
    bool suksesLogin = false;
    int n = sizeof(daftarguru) / sizeof(daftarguru[0]);
    int username;
    string password;
    muatguru("guru.txt");
    muatsiswa("siswa.txt");
    muatnilai("nilai.txt");

    do
    {
        system("cls");
        cout << "========= LOGIN ==========" << endl;
        cout << "1. Login sebagai Guru" << endl;
        cout << "2. Login sebagai Siswa" << endl;
        cout << "3. keluar" << endl;
        cout << "> pilih 1/2 : ";
        cin >> pilih;

        if (pilih == 3)
            break;

        system("cls");

        suksesLogin = false;
        percobaan = 3;

        while (percobaan > 0 && !suksesLogin)
        {
            cout << "Username : ";
            cin >> username;
            cout << "Password : ";
            cin >> password;

            switch (pilih)
            {
            case 1:
                if (loginGuru(username, password, daftarguru, jumlahguru))
                {
                    menuguru();
                    suksesLogin = true;
                }
                else
                {
                    percobaan--;
                    system("cls");
                    cout << "Login gagal! Username atau password salah." << endl;
                    cout << "Kesempatan anda tersisa " << percobaan << " kali lagi." << endl;
                }
                break;
            case 2:
                if (loginSiswa(username, password, daftarsiswa, jumlahsiswa))
                {
                    menumurid();
                    suksesLogin = true;
                }
                else
                {
                    percobaan--;
                    system("cls");
                    cout << "Login gagal! Username atau password salah." << endl;
                    cout << "Kesempatan anda tersisa " << percobaan << " kali lagi." << endl;
                }
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
            }
        }

        if (percobaan == 0)
        {
            cout << "Anda telah melebihi batas percobaan login." << endl;
            system("pause");
        }

    } while (true);
    return 0;
}
// Rest in Peace 02/05/25
