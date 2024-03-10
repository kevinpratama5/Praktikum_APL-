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

void printMenu() {
    cout << "\nM E N U" << endl;
    cout << "1. Tambah Crypto" << endl;
    cout << "2. Tampilkan Data Crypto" << endl;
    cout << "3. Update Data Crypto" << endl;
    cout << "4. Hapus Data Crypto" << endl;
    cout << "5. Keluar" << endl;
}

void tambahCrypto(Crypto cryptoList[], int &numCrypto) {
    if (numCrypto < MAX_CRYPTO) {
        cout << "Masukkan nama crypto: ";
        cin >> cryptoList[numCrypto].name;
        cout << "Masukkan simbol crypto: ";
        cin >> cryptoList[numCrypto].symbol;
        cout << "Masukkan harga crypto: ";
        cin >> cryptoList[numCrypto].price;
        cout << "Masukkan jumlah crypto: ";
        cin >> cryptoList[numCrypto].quantity;
        numCrypto++;
        cout << "Crypto berhasil ditambahkan!" << endl;
    } else {
        cout << "Maaf, sudah mencapai batas maksimal crypto yang dapat ditambahkan." << endl;
    }
}

void tampilkanDataCrypto(Crypto cryptoList[], int numCrypto) {
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

void updateDataCrypto(Crypto cryptoList[], int numCrypto) {
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
                cout << "Masukkan jumlah baru: ";
                cin >> cryptoList[i].quantity;
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

void deleteDataCrypto(Crypto cryptoList[], int &numCrypto) {
    if (numCrypto == 0) {
        cout << "Tidak ada data crypto yang tersedia." << endl;
    } else {
        string symbol;
        cout << "Masukkan simbol crypto yang ingin dihapus: ";
        cin >> symbol;
        bool found = false;
        for (int i = 0; i < numCrypto; ++i) {
            if (cryptoList[i].symbol == symbol) {
                for (int j = i; j < numCrypto - 1; ++j) {
                    cryptoList[j] = cryptoList[j + 1];
                }
                numCrypto--;
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

int main() {
    Crypto cryptoList[MAX_CRYPTO];
    int numCrypto = 0;

    int counter_login = 0;
    while (true) {
        string nama, nim;
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;

        if (nama == "kevin" && nim == "2309106089") {
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

    while (true) {
        printMenu();
        int Pilihan;
        cout << "Menu : ";
        cin >> Pilihan;

        switch (Pilihan) {
            case 1:
                tambahCrypto(cryptoList, numCrypto);
                break;
            case 2:
                tampilkanDataCrypto(cryptoList, numCrypto);
                break;
            case 3:
                updateDataCrypto(cryptoList, numCrypto);
                break;
            case 4:
                deleteDataCrypto(cryptoList, numCrypto);
                break;

            case 5:
                cout << "Program selesai." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
        }
    }

    return 0;
}