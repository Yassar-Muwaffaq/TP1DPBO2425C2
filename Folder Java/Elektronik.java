public class Elektronik {
    private int id;
    private String nama;
    private String kategori;
    private String merk;
    private String spesifikasi;

    public Elektronik(int id, String nama, String kategori, String merk, String spesifikasi) {
        this.id = id;
        this.nama = nama;
        this.kategori = kategori;
        this.merk = merk;
        this.spesifikasi = spesifikasi;
    }

    public int getId() { return id; }
    public String getNama() { return nama; }
    public String getKategori() { return kategori; }
    public String getMerk() { return merk; }
    public String getSpesifikasi() { return spesifikasi; }

    public void setNama(String nama) { this.nama = nama; }
    public void setKategori(String kategori) { this.kategori = kategori; }
    public void setMerk(String merk) { this.merk = merk; }
    public void setSpesifikasi(String spesifikasi) { this.spesifikasi = spesifikasi; }

    public void viewBarang() {
        System.out.println("ID: " + id + ", Nama: " + nama + ", Kategori: " + kategori +
                ", Merk: " + merk + ", Spesifikasi: " + spesifikasi);
    }
}
