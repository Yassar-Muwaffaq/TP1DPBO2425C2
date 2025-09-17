#include <iostream>
#include <string>
using namespace std;

class Elektronik {
private:
    int id;
    string nama;
    string kategori;
    string merk;
    string spesifikasi;

public:
    // constructor
    Elektronik(int id, string nama, string kategori, string merk, string spesifikasi) {
        this->id = id;
        this->nama = nama;
        this->kategori = kategori;
        this->merk = merk;
        this->spesifikasi = spesifikasi;
    }

    // getter
    int getId() const { return id; }
    string getNama() const { return nama; }
    string getKategori() const { return kategori; }
    string getMerk() const { return merk; }
    string getSpesifikasi() const { return spesifikasi; }

    // setter
    void setId(int id) { this->id = id; }
    void setNama(string nama) { this->nama = nama; }
    void setKategori(string kategori) { this->kategori = kategori; }
    void setMerk(string merk) { this->merk = merk; }
    void setSpesifikasi(string spesifikasi) { this->spesifikasi = spesifikasi; }

    // view data
    void viewBarang() const {
        cout << "ID: " << id
             << ", Nama: " << nama
             << ", Kategori: " << kategori
             << ", Merk: " << merk
             << ", Spesifikasi: " << spesifikasi << endl;
    }

    ~Elektronik() {}
};
