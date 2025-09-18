#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include "Elektronik.cpp"
using namespace std;

int main()
{
    vector<Elektronik> barang = {
        Elektronik(1, "Laptop Gaming", "Laptop", "Rak A", 5, "Mantap performanya"),
        Elektronik(2, "Smartphone", "HP", "Rak B", 4, "Bagus tapi baterai boros"),
        Elektronik(3, "Smart TV", "TV", "Rak C", 5, "Kualitas gambar oke banget")};

    string menu;
    do
    {
        cout << "\n=== Menu Toko Elektronik ===\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Lihat Semua Barang\n";
        cout << "3. Update Barang\n";
        cout << "4. Hapus Barang by ID\n";
        cout << "5. Cari Barang by ID\n";
        cout << "6. Exit\n";
        cout << "Pilih menu: ";
        cin >> menu;

        if (menu == "1")
        {
            int newId, rating;
            string newNama, newJenis, newLokasi, newKomen;

            cout << "Masukkan ID: ";
            cin >> newId;

            // cek id unik
            while (any_of(barang.begin(), barang.end(),
                          [newId](const Elektronik &b)
                          { return b.getId() == newId; }))
            {
                cout << "ID " << newId << " sudah ada! Masukkan ID lain: ";
                cin >> newId;
            }

            cin.ignore();
            cout << "Masukkan Nama: ";
            getline(cin, newNama);
            cout << "Masukkan Jenis: ";
            getline(cin, newJenis);
            cout << "Masukkan Lokasi: ";
            getline(cin, newLokasi);
            cout << "Masukkan Rating: ";
            cin >> rating;
            cin.ignore();
            cout << "Masukkan Komen: ";
            getline(cin, newKomen);

            barang.push_back(Elektronik(newId, newNama, newJenis, newLokasi, rating, newKomen));
            cout << "Barang berhasil ditambahkan!\n";
        }
        else if (menu == "2")
        {
            if (barang.empty())
                cout << "Tidak ada data barang.\n";
            else
                for (auto &b : barang)
                    b.display();
        }
        else if (menu == "3")
        {
            int updateId;
            cout << "Masukkan ID barang yang ingin diupdate: ";
            cin >> updateId;

            auto it = find_if(barang.begin(), barang.end(),
                              [updateId](const Elektronik &b)
                              { return b.getId() == updateId; });
            if (it != barang.end())
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string newNama, newJenis, newLokasi, newKomen;

                cout << "Biarkan kosong jika tidak ingin diubah.\n";
                cout << "Nama baru: ";
                getline(cin, newNama);
                cout << "Jenis baru: ";
                getline(cin, newJenis);
                cout << "Lokasi baru: ";
                getline(cin, newLokasi);

                cout << "Masukkan Rating baru: ";
                string ratingInput;
                getline(cin, ratingInput);
                if (!ratingInput.empty())
                {
                    int newRating = stoi(ratingInput);
                    it->setRating(newRating);
                }

                cout << "Komen baru: ";
                getline(cin, newKomen);

                if (!newNama.empty())
                    it->setNama(newNama);
                if (!newJenis.empty())
                    it->setJenis(newJenis);
                if (!newLokasi.empty())
                    it->setLokasi(newLokasi);
                if (!newKomen.empty())
                    it->setKomen(newKomen);

                cout << "Barang berhasil diupdate!\n";
            }
            else
                cout << "Barang tidak ditemukan.\n";
        }

        else if (menu == "4")
        {
            int deleteId;
            cout << "Masukkan ID barang yang ingin dihapus: ";
            cin >> deleteId;
            auto it = find_if(barang.begin(), barang.end(),
                              [deleteId](const Elektronik &b)
                              { return b.getId() == deleteId; });
            if (it != barang.end())
            {
                barang.erase(it);
                cout << "Barang berhasil dihapus!\n";
            }
            else
                cout << "Barang tidak ditemukan.\n";
        }
        else if (menu == "5")
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string keyword;
            cout << "Masukkan kata kunci pencarian: ";
            getline(cin, keyword);

            // ubah ke lowercase keyword
            string keyLower = keyword;
            transform(keyLower.begin(), keyLower.end(), keyLower.begin(), ::tolower);

            bool found = false;
            for (auto &b : barang)
            {
                string idStr = to_string(b.getId());
                string nama = b.getNama();
                string jenis = b.getJenis();
                string lokasi = b.getLokasi();
                string ratingStr = to_string(b.getRating());
                string komen = b.getKomen();

                // ubah semua ke lowercase
                transform(nama.begin(), nama.end(), nama.begin(), ::tolower);
                transform(jenis.begin(), jenis.end(), jenis.begin(), ::tolower);
                transform(lokasi.begin(), lokasi.end(), lokasi.begin(), ::tolower);
                transform(komen.begin(), komen.end(), komen.begin(), ::tolower);

                if (idStr.find(keyLower) != string::npos ||
                    nama.find(keyLower) != string::npos ||
                    jenis.find(keyLower) != string::npos ||
                    lokasi.find(keyLower) != string::npos ||
                    ratingStr.find(keyLower) != string::npos ||
                    komen.find(keyLower) != string::npos)
                {
                    b.display();
                    found = true;
                }
            }

            if (!found)
            {
                cout << "❌ Tidak ada data yang cocok.\n";
            }
        }

    } while (menu != "6");

    return 0;
}
