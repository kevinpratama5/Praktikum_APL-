#include <iostream>
#include <string>
#include <limits>

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
        cout << "6. Sorting Crypto berdasarkan nama(Ascending)" << endl;
        cout << "7. Sorting Crypto berdasarkan harga (Descending)" << endl;
        cout << "8. Sorting Crypto berdasarkan jumlah (Ascending)" << endl;
        cout << "9. Binary Search berdasarkan nama (Ascending)" << endl;
        cout << "10. Insertion Search Crypto berdasarkan nama (Descending)" << endl;
        cout << "11. Keluar" << endl;
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


void sortCryptoByName(Crypto *cryptoList, int numCrypto) {
    for (int i = 0; i < numCrypto - 1; ++i) {
        for (int j = 0; j < numCrypto - i - 1; ++j) {
            if (cryptoList[j].name > cryptoList[j + 1].name) {
                swap(cryptoList[j], cryptoList[j + 1]);
            }
        }
    }
}

void sortCryptoByPrice(Crypto *cryptoList, int numCrypto) {
    for (int i = 0; i < numCrypto - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < numCrypto; ++j) {
            if (cryptoList[j].price > cryptoList[maxIndex].price) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(cryptoList[i], cryptoList[maxIndex]);
        }
    }
}

void quickSort(Crypto *cryptoList, int low, int high);

int partition(Crypto *cryptoList, int low, int high) {
    double pivot = cryptoList[high].quantity;
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (cryptoList[j].quantity < pivot) {
            i++;
            swap(cryptoList[i], cryptoList[j]);
        }
    }
    swap(cryptoList[i + 1], cryptoList[high]);
    return i + 1;
}

void quickSort(Crypto *cryptoList, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(cryptoList, low, high);
        quickSort(cryptoList, low, pivotIndex - 1);
        quickSort(cryptoList, pivotIndex + 1, high);
    }
}


int binarySearchAscending(Crypto *cryptoList, int numCrypto, string key) {
    int low = 0, high = numCrypto - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (cryptoList[mid].name == key) {
            return mid;
        } else if (cryptoList[mid].name < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int insertionSearchDescending(Crypto *cryptoList, int numCrypto, string key) {
    for (int i = numCrypto - 1; i >= 0; --i) {
        if (cryptoList[i].name == key) {
            return i;
        }
        if (cryptoList[i].name < key) {
            return -1;
        }
    }
    return -1;
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
                sortCryptoByName(cryptoList, numCrypto);
                cout << "Crypto berhasil diurutkan berdasarkan nama (Ascending)!" << endl;
                break;
            case 7:
                sortCryptoByPrice(cryptoList, numCrypto);
                cout << "Crypto berhasil diurutkan berdasarkan harga (Descending)!" << endl;
                break;
            case 8:
                quickSort(cryptoList, 0, numCrypto - 1);
                cout << "Crypto berhasil diurutkan berdasarkan jumlah (Ascending)!" << endl;
                break;
            case 9:
                {
                    string key;
                    cout << "Masukkan nama crypto yang ingin dicari: ";
                    cin >> key;
                    sortCryptoByName(cryptoList, numCrypto);
                    int result = binarySearchAscending(cryptoList, numCrypto, key);
                    if (result != -1) {
                        cout << "Crypto dengan nama " << key << " ditemukan pada indeks " << result << endl;
                    } else {
                        cout << "Crypto dengan nama " << key << " tidak ditemukan." << endl;
                    }
                }
                break;
            case 10:
                {
                    string key2;
                    cout << "Masukkan nama crypto yang ingin dicari: ";
                    cin >> key2;
                    sortCryptoByName(cryptoList, numCrypto);
                    int result2 = insertionSearchDescending(cryptoList, numCrypto, key2);
                    if (result2 != -1) {
                        cout << "Crypto dengan nama " << key2 << " ditemukan pada indeks " << result2 << endl;
                    } else {
                        cout << "Crypto dengan nama " << key2 << " tidak ditemukan." << endl;
                    }
                }
                break;
            case 11:
                cout << "Program selesai." << endl;
                return 0;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
