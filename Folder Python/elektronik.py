class Elektronik:
    def __init__(self, id, nama, jenis, lokasi, rating, komen):
        self.id = id
        self.nama = nama
        self.jenis = jenis
        self.lokasi = lokasi
        self.rating = rating
        self.komen = komen

    def get_id(self):
        return self.id
    
    def get_nama(self):
        return self.nama
    
    def get_jenis(self):
        return self.jenis
    
    def get_lokasi(self):
        return self.lokasi
    
    def get_rating(self):
        return self.rating
    
    def get_komen(self):
        return self.komen
    
    def set_nama(self, nama):
        self.nama = nama
    
    def set_jenis(self, jenis):
        self.jenis = jenis
    
    def set_lokasi(self, lokasi):
        self.lokasi = lokasi
    
    def set_rating(self, rating):
        self.rating = rating
    
    def set_komen(self, komen):
        self.komen = komen

    def display(self):
        print(f"ID: {self.id} | Nama: {self.nama} | Jenis: {self.jenis} | Lokasi: {self.lokasi} | Rating: {self.rating} | Komen: {self.komen}")
