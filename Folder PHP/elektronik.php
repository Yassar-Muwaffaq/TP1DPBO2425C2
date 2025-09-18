<?php
class Elektronik {
    private $id, $nama, $jenis, $lokasi, $rating, $komen;

    public function __construct($id, $nama, $jenis, $lokasi, $rating, $komen) {
        $this->id = $id;
        $this->nama = $nama;
        $this->jenis = $jenis;
        $this->lokasi = $lokasi;
        $this->rating = $rating;
        $this->komen = $komen;
    }

    public function getId() { return $this->id; }
    public function getNama() { return $this->nama; }
    public function getJenis() { return $this->jenis; }
    public function getLokasi() { return $this->lokasi; }
    public function getRating() { return $this->rating; }
    public function getKomen() { return $this->komen; }

    public function setNama($v) { $this->nama = $v; }
    public function setJenis($v) { $this->jenis = $v; }
    public function setLokasi($v) { $this->lokasi = $v; }
    public function setRating($v) { $this->rating = $v; }
    public function setKomen($v) { $this->komen = $v; }
}
?>
