<?php
include "Elektronik.php";
session_start();

// buat folder uploads kalau belum ada
if (!is_dir("uploads")) {
    mkdir("uploads");
}

// Data awal
if (!isset($_SESSION['barang'])) {
    $_SESSION['barang'] = [
        new Elektronik(1, "Laptop Gaming", "Laptop", "Rak A", 5, "Mantap performanya", "uploads/laptop.jpeg"),
        new Elektronik(2, "Smartphone", "HP", "Rak B", 4, "Bagus tapi baterai boros", "uploads/hp.jpeg"),
        new Elektronik(3, "Smart TV", "TV", "Rak C", 5, "Kualitas gambar oke banget", "uploads/tv.jpeg")
    ];
}

// Fungsi upload file
function uploadGambar($file) {
    if ($file['error'] === UPLOAD_ERR_OK) {
        $ext = pathinfo($file['name'], PATHINFO_EXTENSION);
        $filename = uniqid("img_") . "." . $ext;
        $path = "uploads/" . $filename;
        move_uploaded_file($file['tmp_name'], $path);
        return $path;
    }
    return '';
}

// Tambah Barang
if (isset($_POST['add'])) {
    $id = intval($_POST['id']);
    $nama = $_POST['nama'];
    $jenis = $_POST['jenis'];
    $lokasi = $_POST['lokasi'];
    $rating = intval($_POST['rating']);
    $komen = $_POST['komen'];

    $gambar = '';
    if (!empty($_FILES['gambar']['name'])) {
        $gambar = uploadGambar($_FILES['gambar']);
    }

    // cek ID unik
    $exists = false;
    foreach ($_SESSION['barang'] as $b) {
        if ($b->getId() == $id) {
            $exists = true;
            break;
        }
    }

    if (!$exists) {
        $_SESSION['barang'][] = new Elektronik($id, $nama, $jenis, $lokasi, $rating, $komen, $gambar);
    } else {
        echo "<p style='color:red;'>❌ ID $id sudah ada, gunakan ID lain!</p>";
    }
}

// Hapus Barang
if (isset($_GET['delete'])) {
    $deleteId = intval($_GET['delete']);
    foreach ($_SESSION['barang'] as $key => $b) {
        if ($b->getId() == $deleteId) {
            if (!empty($b->getGambar()) && file_exists($b->getGambar())) {
                unlink($b->getGambar()); // hapus file gambar juga
            }
            unset($_SESSION['barang'][$key]);
            $_SESSION['barang'] = array_values($_SESSION['barang']);
            break;
        }
    }
}

// Update Barang
if (isset($_POST['update'])) {
    $updateId = intval($_POST['id']);
    foreach ($_SESSION['barang'] as $b) {
        if ($b->getId() == $updateId) {
            $b->setNama($_POST['nama']);
            $b->setJenis($_POST['jenis']);
            $b->setLokasi($_POST['lokasi']);
            $b->setRating(intval($_POST['rating']));
            $b->setKomen($_POST['komen']);

            if (!empty($_FILES['gambar']['name'])) {
                if (!empty($b->getGambar()) && file_exists($b->getGambar())) {
                    unlink($b->getGambar()); // hapus gambar lama
                }
                $b->setGambar(uploadGambar($_FILES['gambar']));
            }
            break;
        }
    }
}

// Search filter
$search = $_GET['search'] ?? '';
$barangFiltered = array_filter($_SESSION['barang'], function($b) use ($search) {
    if ($search === '') return true;
    return stripos($b->getNama(), $search) !== false ||
           stripos($b->getJenis(), $search) !== false ||
           stripos($b->getLokasi(), $search) !== false ||
           stripos($b->getKomen(), $search) !== false;
});
?>
<!DOCTYPE html>
<html>
<head>
    <title>Toko Elektronik</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 20px; }
        .tambah-barang{
            width: 90%;
            text-align: center;
            display: flex;
            justify-items: center;
            align-items: center;
            border: 2px solid black;
            padding: 5px;
            gap: 5px;
        }
        .tambah-barang .i{
            flex: 1;
            padding: 5px;
            border-right:2px solid black;
        }
        table {
            border-collapse: collapse;
            width: 95%;
            margin-top: 20px;
        }
        th, td {
            border: 1px solid #aaa;
            padding: 6px 10px;
            text-align: center;
        }
        input[type=text], input[type=number] {
            border: none;
            background: transparent;
            width: 100%;
            text-align: center;
        }
        input[type=text]:focus, input[type=number]:focus {
            outline: none;
            background: #f0f8ff;
        }
        .search-box { margin: 15px 0; }
        .search-box input { width: 250px; padding: 5px; }
    </style>
</head>
<body>
    <h1>Toko Elektronik</h1>

    <!-- Tambah Barang -->
    <h2>Tambah Barang</h2>
    <form method="POST" enctype="multipart/form-data">
        <div class="tambah-barang">
            <input class="i" type="number" name="id" placeholder="ID" required>
            <input class="i" type="text" name="nama" placeholder="Nama" required>
            <input class="i" type="text" name="jenis" placeholder="Jenis" required>
            <input class="i" type="text" name="lokasi" placeholder="Lokasi" required>
            <input class="i" type="number" name="rating" placeholder="Rating (1-5)" required>
            <input class="i" type="text" name="komen" placeholder="Komentar" required>
            <input class="i" type="file" name="foto" accept="image/*" required>
            <button type="submit" name="add">Tambah</button>
        </div>
    </form>

    <!-- Search -->
    <div class="search-box">
        <form method="GET">
            <input type="text" name="search" placeholder="Cari barang..." value="<?= htmlspecialchars($search) ?>">
            <button type="submit">Cari</button>
            <a href="index.php">Reset</a>
        </form>
    </div>

    <!-- Daftar Barang -->
    <h2>Daftar Barang</h2>
    <table>
        <tr>
            <th>ID</th>
            <th>Nama</th>
            <th>Jenis</th>
            <th>Lokasi</th>
            <th>Rating</th>
            <th>Komen</th>
            <th>Gambar</th>
            <th>Aksi</th>
        </tr>
        <?php if (count($barangFiltered) === 0): ?>
            <tr><td colspan="8">Tidak ada data ditemukan.</td></tr>
        <?php else: ?>
            <?php foreach ($barangFiltered as $b): ?>
                <tr>
                    <form method="POST" enctype="multipart/form-data">
                        <td>
                            <?= $b->getId(); ?>
                            <input type="hidden" name="id" value="<?= $b->getId(); ?>">
                        </td>
                        <td><input type="text" name="nama" value="<?= $b->getNama(); ?>"></td>
                        <td><input type="text" name="jenis" value="<?= $b->getJenis(); ?>"></td>
                        <td><input type="text" name="lokasi" value="<?= $b->getLokasi(); ?>"></td>
                        <td><input type="number" name="rating" value="<?= $b->getRating(); ?>"></td>
                        <td><input type="text" name="komen" value="<?= $b->getKomen(); ?>"></td>
                        <td>
                            <?php if (!empty($b->getGambar()) && file_exists($b->getGambar())): ?>
                                <img src="<?= $b->getGambar(); ?>" width="80"><br>
                            <?php else: ?>
                                [tidak ada gambar]<br>
                                <input type="file" name="gambar" accept="image/*">
                                <?php endif; ?>
                        </td>
                        <td>
                            <button type="submit" name="update">Update</button> |
                            <a href="?delete=<?= $b->getId(); ?>" onclick="return confirm('Yakin hapus?')">Hapus</a>
                        </td>
                    </form>
                </tr>
            <?php endforeach; ?>
        <?php endif; ?>
    </table>
</body>
</html>
