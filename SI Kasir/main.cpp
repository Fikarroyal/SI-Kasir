#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

struct Product {
    int id;
    string name;
    double price;
    int stock;
};

class KasirStore {
private:
    vector<Product> products;
    vector<string> transactions;
    string username = "admin";
    string password = "1234";

    // Fungsi untuk login
    bool login() {
        string user, pass;
        cout << "================== Login Sistem ==================" << endl;
        cout << "Username: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;

        if (user == username && pass == password) {
            cout << "Login berhasil!\n" << endl;
            return true;
        } else {
            cout << "Login gagal. Silakan coba lagi.\n" << endl;
            return false;
        }
    }

    // Fungsi untuk menambah produk
    void addProduct() {
        Product p;
        cout << "================== Tambah Produk =================" << endl;
        cout << "ID Produk: ";
        cin >> p.id;
        cout << "Nama Produk: ";
        cin.ignore();
        getline(cin, p.name);
        cout << "Harga Produk: ";
        cin >> p.price;
        cout << "Stok Produk: ";
        cin >> p.stock;
        products.push_back(p);
        cout << "Produk berhasil ditambahkan!\n" << endl;
    }

    // Fungsi untuk menampilkan produk
    void displayProducts() {
        cout << "================== Daftar Produk =================" << endl;
        cout << setw(10) << "ID" << setw(20) << "Nama" << setw(10) << "Harga" << setw(10) << "Stok" << endl;
        for (const auto &p : products) {
            cout << setw(10) << p.id << setw(20) << p.name << setw(10) << p.price << setw(10) << p.stock << endl;
        }
        cout << endl;
    }

    // Fungsi untuk transaksi
    void processTransaction() {
        int id, qty;
        double total = 0.0;
        string transaction = "Struk Belanja:\n";
        cout << "==================== Transaksi ===================" << endl;

        while (true) {
            cout << "Masukkan ID Produk (0 untuk selesai): ";
            cin >> id;
            if (id == 0) break;

            bool found = false;
            for (auto &p : products) {
                if (p.id == id) {
                    found = true;
                    cout << "Nama Produk: " << p.name << endl;
                    cout << "Stok tersedia: " << p.stock << endl;
                    cout << "Masukkan jumlah: ";
                    cin >> qty;

                    if (qty > p.stock) {
                        cout << "Stok tidak mencukupi!\n" << endl;
                    } else {
                        double subtotal = p.price * qty;
                        total += subtotal;
                        p.stock -= qty;

                        transaction += p.name + " x" + to_string(qty) + " = " + to_string(subtotal) + "\n";
                        cout << "Subtotal: " << subtotal << endl;
                    }
                }
            }

            if (!found) {
                cout << "Produk dengan ID tersebut tidak ditemukan!\n" << endl;
            }
        }

        transaction += "Total: " + to_string(total) + "\n";
        transactions.push_back(transaction);

        cout << "Transaksi selesai. Total belanja: " << total << "\n" << endl;
    }

    // Fungsi untuk laporan penjualan
    void generateReport() {
        cout << fixed << setprecision(2);
        cout << "================ Laporan Penjualan ===============" << endl;
        for (const auto &t : transactions) {
            cout << t << endl;
        }

        ofstream reportFile("sales_report.txt");
        if (reportFile.is_open()) {
            for (const auto &t : transactions) {
                reportFile << t << endl;
            }
            reportFile.close();
            cout << "Laporan berhasil disimpan ke 'sales_report.txt'\n" << endl;
        } else {
            cout << "Gagal menyimpan laporan ke file.\n" << endl;
        }
    }

public:
    // Fungsi utama untuk menjalankan sistem
    void run() {
        if (!login()) return;

        int choice;
        do {
            cout << "=================== Menu Utama ===================" << endl;
            cout << "1. Tambah Produk\n";
            cout << "2. Tampilkan Produk\n";
            cout << "3. Proses Transaksi\n";
            cout << "4. Laporan Penjualan\n";
            cout << "5. Keluar\n";
            cout << "Pilih menu: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addProduct();
                    break;
                case 2:
                    displayProducts();
                    break;
                case 3:
                    processTransaction();
                    break;
                case 4:
                    generateReport();
                    break;
                case 5:
                    cout << "Terima kasih telah menggunakan sistem ini.\n";
                    break;
                default:
                    cout << "Pilihan tidak valid. Coba lagi.\n" << endl;
            }
        } while (choice != 5);
    }
};

int main() {
    KasirStore store;
    store.run();
    return 0;
}
