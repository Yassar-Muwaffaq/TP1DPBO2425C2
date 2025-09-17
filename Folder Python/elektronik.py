class Elektronik:
    def __init__(self, id, nama, kategori, merk, spesifikasi):
        self.id = id
        self.nama = nama
        self.kategori = kategori
        self.merk = merk
        self.spesifikasi = spesifikasi

    def get_id(self):
        return self.id

    def get_nama(self):
        return self.nama

    def get_kategori(self):
        return self.kategori

    def get_merk(self):
        return self.merk

    def get_spesifikasi(self):
        return self.spesifikasi

    def set_nama(self, nama):
        self.nama = nama

    def set_kategori(self, kategori):
        self.kategori = kategori

    def set_merk(self, merk):
        self.merk = merk

    def set_spesifikasi(self, spesifikasi):
        self.spesifikasi = spesifikasi

    def view_barang(self):
        print(
            f"ID: {self.id}, Nama: {self.nama}, "
            f"Kategori: {self.kategori}, Merk: {self.merk}, "
            f"Spesifikasi: {self.spesifikasi}"
        )
