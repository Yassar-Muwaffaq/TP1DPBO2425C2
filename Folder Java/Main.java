import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Elektronik> daftar = new ArrayList<>();

        // Data awal
        daftar.add(new Elektronik(1, "Laptop Gaming", "Laptop", "Rak A", 5, "Mantap performanya"));
        daftar.add(new Elektronik(2, "Smartphone", "HP", "Rak B", 4, "Bagus tapi baterai boros"));
        daftar.add(new Elektronik(3, "Smart TV", "TV", "Rak C", 5, "Kualitas gambar oke banget"));

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

                    if (daftar.stream().anyMatch(e -> e.getId() == id)) {
                        System.out.println("ID sudah ada!");
                        break;
                    }

                    System.out.print("Nama: ");
                    String nama = sc.nextLine();
                    System.out.print("Jenis: ");
                    String jenis = sc.nextLine();
                    System.out.print("Lokasi: ");
                    String lokasi = sc.nextLine();
                    System.out.print("Rating: ");
                    int rating = Integer.parseInt(sc.nextLine());
                    System.out.print("Komen: ");
                    String komen = sc.nextLine();

                    daftar.add(new Elektronik(id, nama, jenis, lokasi, rating, komen));
                    break;

                case "2":
                    if (daftar.isEmpty())
                        System.out.println("Tidak ada barang.");
                    else
                        daftar.forEach(Elektronik::display);
                    break;

                case "3":
                    System.out.print("Masukkan ID barang yang ingin diupdate: ");
                    int uid = Integer.parseInt(sc.nextLine());
                    Elektronik update = daftar.stream().filter(e -> e.getId() == uid).findFirst().orElse(null);
                    if (update == null) {
                        System.out.println("Barang tidak ditemukan.");
                    } else {
                        System.out.print("Nama baru (skip=Enter): ");
                        String nnama = sc.nextLine();
                        if (!nnama.isEmpty())
                            update.setNama(nnama);

                        System.out.print("Jenis baru (skip=Enter): ");
                        String njenis = sc.nextLine();
                        if (!njenis.isEmpty())
                            update.setJenis(njenis);

                        System.out.print("Lokasi baru (skip=Enter): ");
                        String nlokasi = sc.nextLine();
                        if (!nlokasi.isEmpty())
                            update.setLokasi(nlokasi);

                        System.out.print("Rating baru (0=skip): ");
                        String rs = sc.nextLine();
                        if (!rs.isEmpty())
                            update.setRating(Integer.parseInt(rs));

                        System.out.print("Komen baru (skip=Enter): ");
                        String nkomen = sc.nextLine();
                        if (!nkomen.isEmpty())
                            update.setKomen(nkomen);

                        System.out.println("Barang berhasil diupdate!");
                    }
                    break;

                case "4":
                    System.out.print("Masukkan ID barang yang ingin dihapus: ");
                    int did = Integer.parseInt(sc.nextLine());
                    boolean removed = daftar.removeIf(e -> e.getId() == did);
                    System.out.println(removed ? "Barang dihapus!" : "Barang tidak ditemukan.");
                    break;

                case "5":
                    System.out.print("Masukkan kata kunci pencarian: ");
                    String keyword = sc.nextLine().toLowerCase();

                    boolean found = false;
                    for (Elektronik e : daftar) {
                        if (String.valueOf(e.getId()).contains(keyword) ||
                                e.getNama().toLowerCase().contains(keyword) ||
                                e.getJenis().toLowerCase().contains(keyword) ||
                                e.getLokasi().toLowerCase().contains(keyword) ||
                                e.getKomen().toLowerCase().contains(keyword)) {
                            e.display();
                            found = true;
                        }
                    }
                    if (!found) {
                        System.out.println("❌ Tidak ada data yang cocok.");
                    }
                break;

            }

        } while (!menu.equals("6"));
        sc.close();
    }
}
