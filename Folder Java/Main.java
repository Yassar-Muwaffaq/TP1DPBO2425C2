import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Elektronik> daftar = new ArrayList<>();

        // Data awal
        daftar.add(new Elektronik(1, "Laptop Gaming", "Laptop", "Asus", "Ryzen 7, 16GB RAM"));
        daftar.add(new Elektronik(2, "Smartphone", "HP", "Samsung", "8GB RAM, 256GB Storage"));
        daftar.add(new Elektronik(3, "TV LED", "Televisi", "LG", "42 inch, Full HD"));

        String menu;
        do {
            System.out.println("\nMenu:");
            System.out.println("1. Tambah Barang");
            System.out.println("2. Lihat Barang");
            System.out.println("3. Update Barang");
            System.out.println("4. Hapus Barang");
            System.out.println("5. Cari Barang");
            System.out.println("6. Exit");
            System.out.print("Pilih menu: ");
            menu = sc.nextLine();

            switch (menu) {
                case "1":
                    System.out.print("Masukkan ID: ");
                    int id = Integer.parseInt(sc.nextLine());

                    // Cek ID unik
                    boolean exists = daftar.stream().anyMatch(e -> e.getId() == id);
                    if (exists) {
                        System.out.println("ID sudah ada!");
                        break;
                    }

                    System.out.print("Masukkan Nama: ");
                    String nama = sc.nextLine();
                    System.out.print("Masukkan Kategori: ");
                    String kategori = sc.nextLine();
                    System.out.print("Masukkan Merk: ");
                    String merk = sc.nextLine();
                    System.out.print("Masukkan Spesifikasi: ");
                    String spesifikasi = sc.nextLine();

                    daftar.add(new Elektronik(id, nama, kategori, merk, spesifikasi));
                    break;

                case "2":
                    if (daftar.isEmpty()) {
                        System.out.println("Tidak ada barang.");
                    } else {
                        daftar.forEach(Elektronik::viewBarang);
                    }
                    break;

                case "3":
                    System.out.print("Masukkan ID barang yang ingin diupdate: ");
                    int uid = Integer.parseInt(sc.nextLine());
                    Elektronik update = daftar.stream().filter(e -> e.getId() == uid).findFirst().orElse(null);
                    if (update == null) {
                        System.out.println("Barang tidak ditemukan.");
                    } else {
                        System.out.print("Nama baru (kosong=skip): ");
                        String nnama = sc.nextLine();
                        if (!nnama.isEmpty()) update.setNama(nnama);

                        System.out.print("Kategori baru (kosong=skip): ");
                        String nkategori = sc.nextLine();
                        if (!nkategori.isEmpty()) update.setKategori(nkategori);

                        System.out.print("Merk baru (kosong=skip): ");
                        String nmerk = sc.nextLine();
                        if (!nmerk.isEmpty()) update.setMerk(nmerk);

                        System.out.print("Spesifikasi baru (kosong=skip): ");
                        String nspesifikasi = sc.nextLine();
                        if (!nspesifikasi.isEmpty()) update.setSpesifikasi(nspesifikasi);

                        System.out.println("Barang berhasil diupdate!");
                    }
                    break;

                case "4":
                    System.out.print("Masukkan ID barang yang ingin dihapus: ");
                    int did = Integer.parseInt(sc.nextLine());
                    daftar.removeIf(e -> e.getId() == did);
                    System.out.println("Barang dengan ID " + did + " berhasil dihapus.");
                    break;

                case "5":
                    System.out.print("Masukkan ID barang yang dicari: ");
                    int sid = Integer.parseInt(sc.nextLine());
                    Elektronik cari = daftar.stream().filter(e -> e.getId() == sid).findFirst().orElse(null);
                    if (cari == null) {
                        System.out.println("Barang tidak ditemukan.");
                    } else {
                        cari.viewBarang();
                    }
                    break;
            }

        } while (!menu.equals("6"));
        sc.close();
    }
}
