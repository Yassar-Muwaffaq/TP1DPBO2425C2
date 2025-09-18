#include <iostream>
#include <string>
using namespace std;

class Elektronik {
private:
    int id;
    string nama;
    string jenis;
    string lokasi;
    int rating;
    string komen;

public:
    Elektronik(int id, string nama, string jenis, string lokasi, int rating, string komen) {
        this->id = id;
        this->nama = nama;
        this->jenis = jenis;
        this->lokasi = lokasi;
        this->rating = rating;
        this->komen = komen;
    }

    int getId() const { return id; }
    string getNama() const { return nama; }
    string getJenis() const { return jenis; }
    string getLokasi() const { return lokasi; }
    int getRating() const { return rating; }
    string getKomen() const { return komen; }

    void setNama(string nama) { this->nama = nama; }
    void setJenis(string jenis) { this->jenis = jenis; }
    void setLokasi(string lokasi) { this->lokasi = lokasi; }
    void setRating(int rating) { this->rating = rating; }
    void setKomen(string komen) { this->komen = komen; }

    void display() {
        cout << "ID: " << id
             << " | Nama: " << nama
             << " | Jenis: " << jenis
             << " | Lokasi: " << lokasi
             << " | Rating: " << rating
             << " | Komen: " << komen << endl;
    }
};
