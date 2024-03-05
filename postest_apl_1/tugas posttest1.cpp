#include <iostream>
using namespace std;

int main() {
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

    char ulangi;
    do {
        int konversi;
        double km, cm, m, mil;

        cout << "Pilih menu yang ingin dilakukan: " << endl;
        cout << "1. Konversi Kilometer/jam ke (Centimeter/detik, Meter/detik, Mil/jam)" << endl;
        cout << "2. Konversi Centimeter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)" << endl;
        cout << "3. Konversi Meter/detik ke (Kilometer/jam, Centimeter/detik, Mil/jam)" << endl;
        cout << "4. Konversi Mil/jam ke (Kilometer/jam, Centimeter/detik, Meter/detik): ";
        cin >> konversi;

        switch (konversi) {
            case 1:
                cout << "Masukkan kecepatan dalam Kilometer/jam: ";
                cin >> km;
                cm = km * 100000 / 3600;
                m = km * 1000 / 3600;
                mil = km * 0.621371;
                cout << "Hasil konversi:" << endl;
                cout << cm << " cm/detik" << endl;
                cout << m << " m/detik" << endl;
                cout << mil << " mil/jam" << endl;
                break;
            case 2:
                cout << "Masukkan kecepatan dalam Centimeter/detik: ";
                cin >> cm;
                km = cm * 0.00001 * 3600;
                m = cm * 0.01;
                mil = cm * 0.0000062137 * 3600;
                cout << "Hasil konversi:" << endl;
                cout << km << " km/jam" << endl;
                cout << m << " m/detik" << endl;
                cout << mil << " mil/jam" << endl;
                break;
            case 3:
                cout << "Masukkan kecepatan dalam Meter/detik: ";
                cin >> m;
                km = m * 0.001 * 3600;
                cm = m * 100;
                mil = m * 0.00062137 * 3600;
                cout << "Hasil konversi:" << endl;
                cout << km << " km/jam" << endl;
                cout << cm << " cm/detik" << endl;
                cout << mil << " mil/jam" << endl;
                break;
            case 4:
                cout << "Masukkan kecepatan dalam Mil/jam: ";
                cin >> mil;
                km = mil * 1.60934;
                cm = mil * 160934;
                m = mil * 1609.34 / 3600;
                cout << "Hasil konversi:" << endl;
                cout << km << " km/jam" << endl;
                cout << cm << " cm/detik" << endl;
                cout << m << " m/detik" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

        cout << "Apakah Anda ingin mengulangi? (y/n): ";
        cin >> ulangi;
    } while (ulangi == 'y' || ulangi == 'Y');

    return 0;
}
