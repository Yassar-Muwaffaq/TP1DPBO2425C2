Saya Yassar Muwaffaq dengan NIM 2410896 mengerjakan
TP1 mata kuliah Praktikum Desain dan Pemrograman Berorientasi Objek
Untuk keberkahan-Nya maka saya tidak akan
melakukan kecurangan seperti yang telah di spesifikasikan
                Aamiin

# Sistem CRUD Toko Elektronik

Project ini adalah implementasi sederhana **CRUD (Create, Read, Update, Delete)**  
untuk data barang elektronik.  
Dibuat dalam 4 bahasa pemrograman berbeda: **C++**, **Java**, **Python**, dan **PHP**.

---

## 📂 Struktur Project

.
├── cpp/
│ ├── Elektronik.cpp
│ └── main.cpp
├── java/
│ ├── Elektronik.java
│ └── Main.java
├── python/
│ ├── elektronik.py
│ └── main.py
├── php/
│ ├── Elektronik.php
│ └── index.php
└── README.md


---

## 🚀 Cara Menjalankan

### 🔹 1. C++
1. Masuk ke folder `cpp/`
2. Compile:
   ```bash
   g++ main.cpp Elektronik.cpp -o toko
   ./toko
3. Akan muncul menu CRUD di terminal.
2. Java

Masuk ke folder java/

Compile:

javac Main.java
java Main


Jalankan di terminal.

🔹 3. Python

Masuk ke folder python/

Jalankan:

python3 main.py


Program akan menampilkan menu CRUD di terminal.

🔹 4. PHP (dengan HTML Form)

Copy folder php/ ke dalam folder server web (misalnya htdocs di XAMPP).

Jalankan Apache dari XAMPP.

Buka browser:

http://localhost/index.php


Gunakan form HTML untuk tambah, lihat, hapus barang.

📖 Cara Menggunakan Menu (C++, Java, Python)

Setelah dijalankan, akan muncul menu seperti ini:

Menu:
1. Tambah Barang
2. Lihat Barang
3. Update Barang
4. Hapus Barang
5. Cari Barang
6. Exit

Penjelasan:

1. Tambah Barang → Masukkan data barang elektronik baru (ID, nama, merek, spesifikasi).
⚠️ ID harus unik. Jika ID sudah ada, akan diminta masukkan ulang.

2. Lihat Barang → Menampilkan seluruh barang elektronik yang tersimpan. Jika kosong akan muncul pesan.

3. Update Barang → Masukkan ID barang yang ingin diperbarui, lalu isi data baru. Biarkan kosong jika tidak ingin mengubah value.

4. Hapus Barang → Masukkan ID untuk menghapus barang dari list.

5. Cari Barang → Masukkan ID untuk mencari data spesifik.

6. Exit → Keluar dari program.

⚠️ Warning & Catatan

Input ID harus angka → Jika salah input (misalnya huruf), program bisa error/crash di C++ dan Java.

Gunakan Enter dengan benar → Di C++/Java, setelah input angka gunakan cin.ignore() / scanner.nextLine() agar string bisa terbaca dengan benar.

Data tidak permanen → Semua data hanya disimpan sementara (di memori). Jika program ditutup, data hilang.

Versi PHP hanya mendukung Tambah, Lihat, Hapus. Update & cari bisa ditambahkan manual.

📌 Contoh Data Default

Beberapa contoh barang elektronik:

Laptop Gaming – Asus – Ryzen 7, RTX 3060

Smartphone – Samsung – Snapdragon 888

Smart TV – LG – 4K UHD 55"

Dibuat sebagai latihan pemrograman multi-bahasa

Menggunakan pendekatan Object-Oriented Programming (OOP) di semua bahasa

Kurang Aestetik kang teh maaf kepepet waktu ini baru ngerjain dari jam 12 Siang sekarang jam 14:31 
hp rusak tidak dapat notif ada TP minggu kemarin sakit tidak bisa datang 17 september sore ini jam 5 
pulang ke garut ada lagi tugas baru dan tugas kelompok seadanya saja ya kang teh 