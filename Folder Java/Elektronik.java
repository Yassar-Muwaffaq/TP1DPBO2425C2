public class Elektronik {
    private int id;
    private String nama;
    private String jenis;
    private String lokasi;
    private int rating;
    private String komen;

    public Elektronik(int id, String nama, String jenis, String lokasi, int rating, String komen) {
        this.id = id;
        this.nama = nama;
        this.jenis = jenis;
        this.lokasi = lokasi;
        this.rating = rating;
        this.komen = komen;
    }

    public int getId() { return id; }
    public String getNama() { return nama; }
    public String getJenis() { return jenis; }
    public String getLokasi() { return lokasi; }
    public int getRating() { return rating; }
    public String getKomen() { return komen; }

    public void setNama(String nama) { this.nama = nama; }
    public void setJenis(String jenis) { this.jenis = jenis; }
    public void setLokasi(String lokasi) { this.lokasi = lokasi; }
    public void setRating(int rating) { this.rating = rating; }
    public void setKomen(String komen) { this.komen = komen; }

    public void display() {
        System.out.println("ID: " + id +
                           " | Nama: " + nama +
                           " | Jenis: " + jenis +
                           " | Lokasi: " + lokasi +
                           " | Rating: " + rating +
                           " | Komen: " + komen);
    }
}
