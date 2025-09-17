#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include "Elektronik.cpp"
using namespace std;

int main() {
    vector<Elektronik> barang = {
        Elektronik(1, "Laptop Gaming", "Laptop", "Asus", "Ryzen 7, RTX 3060, 16GB RAM"),
        Elektronik(2, "Smartphone", "HP", "Samsung", "Snapdragon 888, 8GB RAM, 128GB"),
        Elektronik(3, "Smart TV", "TV", "LG", "4K UHD, 55 Inch, HDR")
    };

    string menu;
    do {
        cout << "\n=== Menu Toko Elektronik ===\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Lihat Semua Barang\n";
        cout << "3. Update Barang\n";
        cout << "4. Hapus Barang by ID\n";
        cout << "5. Cari Barang by ID\n";
        cout << "6. Exit\n";
        cout << "Pilih menu: ";
        cin >> menu;

        if (menu == "1") {
            int newId;
            string newNama, newKategori, newMerk, newSpesifikasi;

            cout << "Masukkan ID: ";
            cin >> newId;

            // cek id unik
            bool valid = false;
            while (!valid) {
                auto it = find_if(barang.begin(), barang.end(),
                                  [newId](const Elektronik &b) { return b.getId() == newId; });
                if (it != barang.end()) {
                    cout << "ID " << newId << " sudah ada! Masukkan ID lain: ";
                    cin >> newId;
                } else {
                    valid = true;
                }
            }

            cin.ignore();
            cout << "Masukkan Nama: ";
            getline(cin, newNama);
            cout << "Masukkan Kategori: ";
            getline(cin, newKategori);
            cout << "Masukkan Merk: ";
            getline(cin, newMerk);
            cout << "Masukkan Spesifikasi: ";
            getline(cin, newSpesifikasi);

            barang.push_back(Elektronik(newId, newNama, newKategori, newMerk, newSpesifikasi));
            cout << "Barang berhasil ditambahkan!\n";
        }
        else if (menu == "2") {
            if (barang.empty()) {
                cout << "Tidak ada data barang.\n";
            } else {
                for (auto &b : barang) {
                    b.viewBarang();
                }
            }
        }
        else if (menu == "3") {
            int updateId;
            cout << "Masukkan ID barang yang ingin diupdate: ";
            cin >> updateId;

            auto it = find_if(barang.begin(), barang.end(),
                              [updateId](const Elektronik &b) { return b.getId() == updateId; });
            if (it != barang.end()) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string newNama, newKategori, newMerk, newSpesifikasi;

                cout << "Biarkan kosong jika tidak ingin diubah.\n";
                cout << "Masukkan Nama baru: ";
                getline(cin, newNama);
                cout << "Masukkan Kategori baru: ";
                getline(cin, newKategori);
                cout << "Masukkan Merk baru: ";
                getline(cin, newMerk);
                cout << "Masukkan Spesifikasi baru: ";
                getline(cin, newSpesifikasi);

                if (!newNama.empty()) it->setNama(newNama);
                if (!newKategori.empty()) it->setKategori(newKategori);
                if (!newMerk.empty()) it->setMerk(newMerk);
                if (!newSpesifikasi.empty()) it->setSpesifikasi(newSpesifikasi);

                cout << "Barang dengan ID " << updateId << " berhasil diupdate!\n";
            } else {
                cout << "Barang dengan ID " << updateId << " tidak ditemukan.\n";
            }
        }
        else if (menu == "4") {
            int deleteId;
            cout << "Masukkan ID barang yang ingin dihapus: ";
            cin >> deleteId;

            auto it = find_if(barang.begin(), barang.end(),
                              [deleteId](const Elektronik &b) { return b.getId() == deleteId; });
            if (it != barang.end()) {
                barang.erase(it);
                cout << "Barang dengan ID " << deleteId << " berhasil dihapus!\n";
            } else {
                cout << "Barang dengan ID " << deleteId << " tidak ditemukan.\n";
            }
        }
        else if (menu == "5") {
            int searchId;
            cout << "Masukkan ID barang yang ingin dicari: ";
            cin >> searchId;

            auto it = find_if(barang.begin(), barang.end(),
                              [searchId](const Elektronik &b) { return b.getId() == searchId; });
            if (it != barang.end()) {
                it->viewBarang();
            } else {
                cout << "Barang dengan ID " << searchId << " tidak ditemukan.\n";
            }
        }

    } while (menu != "6");

    return 0;
}

