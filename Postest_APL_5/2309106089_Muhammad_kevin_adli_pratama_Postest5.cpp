#include <iostream>
#include <string>
using namespace std;

const int MAX_CRYPTO = 10;

struct Crypto {
    string name;
    string symbol;
    double price;
    int quantity;
};

struct User {
    string nama;
    string nim;
};

struct Menu {
    void print() {
        cout << "\nM E N U" << endl;
        cout << "1. Tambah Crypto" << endl;
        cout << "2. Tampilkan Data Crypto" << endl;
        cout << "3. Update Data Crypto" << endl;
        cout << "4. Hapus Data Crypto" << endl;
        cout << "5. Hitung Total Nilai Crypto" << endl;
        cout << "6. Keluar" << endl;
        cout << "JIKA SALAH MEMASUKAN JENIS INPUTAN MAKA PROGRAM AKAN MATI!!!\n";
    }
};

void tambahCrypto(Crypto *cryptoList, int *numCrypto) {
    if (*numCrypto < MAX_CRYPTO) {
        cout << "Masukkan nama crypto: ";
        cin >> cryptoList[*numCrypto].name;
        cout << "Masukkan simbol crypto: ";
        cin >> cryptoList[*numCrypto].symbol;
        cout << "Masukkan harga crypto: ";
        cin >> cryptoList[*numCrypto].price;
        if (cryptoList[*numCrypto].price <= 0) {
            cout << "Harga crypto harus lebih dari 0." << endl;
            return;
        }
        cout << "Masukkan jumlah crypto: ";
        cin >> cryptoList[*numCrypto].quantity;
        if (cryptoList[*numCrypto].quantity < 0) {
            cout << "Jumlah crypto tidak boleh negatif." << endl;
            return;
        }
        (*numCrypto)++;
        cout << "Crypto berhasil ditambahkan!" << endl;
    } else {
        cout << "Maaf, sudah mencapai batas maksimal crypto yang dapat ditambahkan." << endl;
    }
}

void tampilkanDataCrypto(Crypto *cryptoList, int numCrypto) {
    if (numCrypto == 0) {
        cout << "Tidak ada data crypto yang tersedia." << endl;
    } else {
        cout << "Data Crypto:" << endl;
        for (int i = 0; i < numCrypto; ++i) {
            cout << "Crypto ke-" << i+1 << endl;
            cout << "Nama: " << cryptoList[i].name << endl;
            cout << "Simbol: " << cryptoList[i].symbol << endl;
            cout << "Harga: " << cryptoList[i].price << endl;
            cout << "Jumlah: " << cryptoList[i].quantity << endl;
        }
    }
}

void updateDataCrypto(Crypto *cryptoList, int numCrypto) {
    if (numCrypto == 0) {
        cout << "Tidak ada data crypto yang tersedia." << endl;
    } else {
        string symbol;
        cout << "Masukkan simbol crypto yang ingin diupdate: ";
        cin >> symbol;
        bool found = false;
        for (int i = 0; i < numCrypto; ++i) {
            if (cryptoList[i].symbol == symbol) {
                cout << "Masukkan harga baru: ";
                cin >> cryptoList[i].price;
                if (cryptoList[i].price <= 0) {
                    cout << "Harga crypto harus lebih dari 0." << endl;
                    return;
                }
                cout << "Masukkan jumlah baru: ";
                cin >> cryptoList[i].quantity;
                if (cryptoList[i].quantity < 0) {
                    cout << "Jumlah crypto tidak boleh negatif." << endl;
                    return;
                }
                found = true;
                cout << "Data crypto berhasil diupdate!" << endl;
                break;
            }
        }
        if (!found) {
            cout << "Crypto dengan simbol " << symbol << " tidak ditemukan." << endl;
        }
    }
}

void deleteDataCrypto(Crypto *cryptoList, int *numCrypto) {
    if (*numCrypto == 0) {
        cout << "Tidak ada data crypto yang tersedia." << endl;
    } else {
        string symbol;
        cout << "Masukkan simbol crypto yang ingin dihapus: ";
        cin >> symbol;
        bool found = false;
        for (int i = 0; i < *numCrypto; ++i) {
            if (cryptoList[i].symbol == symbol) {
                for (int j = i; j < *numCrypto - 1; ++j) {
                    cryptoList[j] = cryptoList[j + 1];
                }
                (*numCrypto)--;
                found = true;
                cout << "Data crypto berhasil dihapus!" << endl;
                break;
            }
        }
        if (!found) {
            cout << "Crypto dengan simbol " << symbol << " tidak ditemukan." << endl;
        }
    }
}

double totalNilaiCrypto(Crypto *cryptoList, int numCrypto, int index = 0) {
    if (index >= numCrypto) {
        return 0.0;
    }
    return (cryptoList[index].price * cryptoList[index].quantity) + totalNilaiCrypto(cryptoList, numCrypto, index + 1);
}

int main() {
    Crypto cryptoList[MAX_CRYPTO];
    int numCrypto = 0;

    int counter_login = 0;
    while (true) {
        User user;
        cout << "Masukkan Nama: ";
        cin >> user.nama;
        cout << "Masukkan NIM: ";
        cin >> user.nim;

        if (user.nama == "kevin" && user.nim == "2309106089") {
            cout << "Login berhasil!\n\n";
            break;
        } else {
            counter_login++;
            if (counter_login == 3) {
                cout << "Anda telah gagal login 3 kali. Program berhenti.\n";
                return 0;
            } else {
                cout << "Login gagal. Silakan coba lagi.\n\n";
            }
        }
    }

    Menu menu;
    while (true) {
        menu.print();
        int Pilihan;
        cout << "Menu No: ";
        cin >> Pilihan;

        switch (Pilihan) {
            case 1:
                tambahCrypto(cryptoList, &numCrypto);
                break;
            case 2:
                tampilkanDataCrypto(cryptoList, numCrypto);
                break;
            case 3:
                updateDataCrypto(cryptoList, numCrypto);
                break;
            case 4:
                deleteDataCrypto(cryptoList, &numCrypto);
                break;
            case 5:
                cout << "Total nilai semua crypto: $" << totalNilaiCrypto(cryptoList, numCrypto) << endl;
                break;
            case 6:
                cout << "Program selesai." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Mematikan program" << endl;
                exit(0);
        }
    }
}
