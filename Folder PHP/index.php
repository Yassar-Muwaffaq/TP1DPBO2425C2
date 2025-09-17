<?php
class Elektronik {
    private $id;
    private $nama;
    private $kategori;
    private $merk;
    private $spesifikasi;

    public function __construct($id, $nama, $kategori, $merk, $spesifikasi) {
        $this->id = $id;
        $this->nama = $nama;
        $this->kategori = $kategori;
        $this->merk = $merk;
        $this->spesifikasi = $spesifikasi;
    }

    // Getter
    public function getId() { return $this->id; }
    public function getNama() { return $this->nama; }
    public function getKategori() { return $this->kategori; }
    public function getMerk() { return $this->merk; }
    public function getSpesifikasi() { return $this->spesifikasi; }

    // Setter
    public function setNama($nama) { $this->nama = $nama; }
    public function setKategori($kategori) { $this->kategori = $kategori; }
    public function setMerk($merk) { $this->merk = $merk; }
    public function setSpesifikasi($spesifikasi) { $this->spesifikasi = $spesifikasi; }

    public function viewBarang() {
        echo "<tr>
                <td>{$this->id}</td>
                <td>{$this->nama}</td>
                <td>{$this->kategori}</td>
                <td>{$this->merk}</td>
                <td>{$this->spesifikasi}</td>
              </tr>";
    }
}
?>
