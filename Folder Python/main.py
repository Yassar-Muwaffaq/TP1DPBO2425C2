from elektronik import Elektronik

def main():
    daftar = [
        Elektronik(1, "Laptop Gaming", "Laptop", "Asus", "Ryzen 7, 16GB RAM"),
        Elektronik(2, "Smartphone", "HP", "Samsung", "8GB RAM, 256GB Storage"),
        Elektronik(3, "TV LED", "Televisi", "LG", "42 inch, Full HD")
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
            nama = input("Masukkan Nama: ")
            kategori = input("Masukkan Kategori: ")
            merk = input("Masukkan Merk: ")
            spesifikasi = input("Masukkan Spesifikasi: ")
            daftar.append(Elektronik(id, nama, kategori, merk, spesifikasi))

        elif menu == "2":
            if not daftar:
                print("Tidak ada barang.")
            else:
                for e in daftar:
                    e.view_barang()

        elif menu == "3":
            uid = int(input("Masukkan ID barang yang ingin diupdate: "))
            update = next((e for e in daftar if e.id == uid), None)
            if not update:
                print("Barang tidak ditemukan.")
            else:
                nnama = input("Nama baru (kosong=skip): ")
                if nnama: update.nama = nnama
                nkategori = input("Kategori baru (kosong=skip): ")
                if nkategori: update.kategori = nkategori
                nmerk = input("Merk baru (kosong=skip): ")
                if nmerk: update.merk = nmerk
                nspesifikasi = input("Spesifikasi baru (kosong=skip): ")
                if nspesifikasi: update.spesifikasi = nspesifikasi
                print("Barang berhasil diupdate!")

        elif menu == "4":
            did = int(input("Masukkan ID barang yang ingin dihapus: "))
            daftar = [e for e in daftar if e.id != did]
            print(f"Barang dengan ID {did} berhasil dihapus.")

        elif menu == "5":
            sid = int(input("Masukkan ID barang yang dicari: "))
            cari = next((e for e in daftar if e.id == sid), None)
            if not cari:
                print("Barang tidak ditemukan.")
            else:
                cari.view_barang()

        elif menu == "6":
            break

if __name__ == "__main__":
    main()
