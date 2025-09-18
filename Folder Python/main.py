from Elektronik import Elektronik

def main():
    daftar = [
        Elektronik(1, "Laptop Gaming", "Laptop", "Rak A", 5, "Mantap performanya"),
        Elektronik(2, "Smartphone", "HP", "Rak B", 4, "Bagus tapi baterai boros"),
        Elektronik(3, "Smart TV", "TV", "Rak C", 5, "Kualitas gambar oke banget")
    ]

    while True:
        print("\nMenu:")
        print("1. Tambah Barang")
        print("2. Lihat Barang")
        print("3. Update Barang")
        print("4. Hapus Barang")
        print("5. Cari Barang")
        print("6. Exit")

        menu = input("Pilih menu: ")

        if menu == "1":
            id = int(input("Masukkan ID: "))
            if any(e.id == id for e in daftar):
                print("ID sudah ada!")
                continue
            nama = input("Nama: ")
            jenis = input("Jenis: ")
            lokasi = input("Lokasi: ")
            rating = int(input("Rating: "))
            komen = input("Komen: ")
            daftar.append(Elektronik(id, nama, jenis, lokasi, rating, komen))

        elif menu == "2":
            if not daftar:
                print("Tidak ada barang.")
            else:
                for e in daftar: e.display()

        elif menu == "3":
            uid = int(input("Masukkan ID barang yang ingin diupdate: "))
            update = next((e for e in daftar if e.id == uid), None)
            if not update:
                print("Barang tidak ditemukan.")
            else:
                nnama = input("Nama baru (skip=Enter): ")
                if nnama: update.nama = nnama
                njenis = input("Jenis baru (skip=Enter): ")
                if njenis: update.jenis = njenis
                nlokasi = input("Lokasi baru (skip=Enter): ")
                if nlokasi: update.lokasi = nlokasi
                try:
                    nrating = input("Rating baru (0=skip): ")
                    if nrating and int(nrating) > 0: update.rating = int(nrating)
                except ValueError:
                    pass
                nkomen = input("Komen baru (skip=Enter): ")
                if nkomen: update.komen = nkomen
                print("Barang berhasil diupdate!")

        elif menu == "4":
            did = int(input("Masukkan ID barang yang ingin dihapus: "))
            daftar = [e for e in daftar if e.id != did]
            print(f"Barang dengan ID {did} berhasil dihapus.")

        elif menu == "5":
            keyword = input("Masukkan kata kunci pencarian: ").lower()
            hasil = []

            for e in daftar:
                if (keyword in str(e.get_id()).lower() or
                    keyword in e.get_nama().lower() or
                    keyword in e.get_jenis().lower() or
                    keyword in e.get_lokasi().lower() or
                    keyword in e.get_komen().lower() or
                    keyword in str(e.get_rating()).lower()):
                    hasil.append(e)

            if hasil:
                print("\nHasil Pencarian:")
                for e in hasil:
                    e.display()
            else:
                print("❌ Tidak ada data yang cocok.")
                    
        elif menu == "6":
            break

if __name__ == "__main__":
    main()
