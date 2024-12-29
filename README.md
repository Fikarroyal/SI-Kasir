# SI-Kasir
Cashier information system

## Hasil Output

```yaml
program: "Kasir Store: Sistem Informasi Kasir"
fitur:
  - login:
      deskripsi: "Pengguna masuk ke sistem dengan username dan password."
      contoh_tampilan:
        - "===== Login Sistem ====="
        - "Username: admin"
        - "Password: ****"
        - "Login berhasil!"
  - manajemen_produk:
      deskripsi: "Menambah dan menampilkan produk di sistem."
      contoh_tampilan:
        - "===== Tambah Produk ====="
        - "ID Produk: 1"
        - "Nama Produk: Susu UHT"
        - "Harga Produk: 15000"
        - "Stok Produk: 20"
        - "Produk berhasil ditambahkan!"
        - "===== Daftar Produk ====="
        - "| ID       | Nama             | Harga     | Stok    |"
        - "| 1        | Susu UHT         | 15000     | 20      |"
  - transaksi:
      deskripsi: "Melakukan transaksi kasir, menghitung total, dan mencetak struk."
      contoh_tampilan:
        - "===== Transaksi ====="
        - "Masukkan ID Produk (0 untuk selesai): 1"
        - "Nama Produk: Susu UHT"
        - "Stok tersedia: 20"
        - "Masukkan jumlah: 2"
        - "Subtotal: 30000"
        - "Masukkan ID Produk (0 untuk selesai): 0"
        - "Transaksi selesai. Total belanja: 30000"
  - laporan_penjualan:
      deskripsi: "Membuat laporan penjualan dan menyimpannya ke file."
      contoh_tampilan:
        - "===== Laporan Penjualan ====="
        - "Struk Belanja:"
        - "Susu UHT x2 = 30000"
        - "Total: 30000"
        - "Laporan berhasil disimpan ke 'sales_report.txt'"
langkah_eksekusi:
  - "Login ke sistem dengan username dan password."
  - "Pilih menu utama (1: Tambah Produk, 2: Tampilkan Produk, 3: Proses Transaksi, 4: Laporan Penjualan, 5: Keluar)."
  - "Lakukan manajemen produk, transaksi, atau lihat laporan."
  - "Keluar dari sistem."
file_output:
  - "sales_report.txt"
