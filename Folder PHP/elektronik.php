<?php
class Elektronik {
    private $id;
    private $nama;
    private $jenis;
    private $lokasi;
    private $rating;
    private $komen;
    private $gambar; // path file lokal

    public function __construct($id, $nama, $jenis, $lokasi, $rating, $komen, $gambar = '') {
        $this->id = $id;
        $this->nama = $nama;
        $this->jenis = $jenis;
        $this->lokasi = $lokasi;
        $this->rating = $rating;
        $this->komen = $komen;
        $this->gambar = $gambar;
    }

    // Getter
    public function getId() { return $this->id; }
    public function getNama() { return $this->nama; }
    public function getJenis() { return $this->jenis; }
    public function getLokasi() { return $this->lokasi; }
    public function getRating() { return $this->rating; }
    public function getKomen() { return $this->komen; }
    public function getGambar() { return $this->gambar; }

    // Setter
    public function setNama($nama) { $this->nama = $nama; }
    public function setJenis($jenis) { $this->jenis = $jenis; }
    public function setLokasi($lokasi) { $this->lokasi = $lokasi; }
    public function setRating($rating) { $this->rating = $rating; }
    public function setKomen($komen) { $this->komen = $komen; }
    public function setGambar($gambar) { $this->gambar = $gambar; }
}
?>
