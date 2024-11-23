#include <iostream>
#include "transvar.hpp"

void displayUsage() {
    std::cout << "Penggunaan:\n";
    std::cout << "./program <kode_bahasa>\n";
    std::cout << "Contoh:\n";
    std::cout << "./program id   # Untuk Indonesia\n";
    std::cout << "./program en   # Untuk Inggris\n";
    std::cout << "./program jks   # Untuk Jaksel (Jakarta Selatan)\n";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Kesalahan: Harap berikan kode bahasa sebagai argumen.\n";
        displayUsage();
        return 1;
    }

    // Mendapatkan kode bahasa dari argumen
    std::string language_code = argv[1];
    std::string filename = "halodunia." + language_code;

    // Memuat file bahasa berdasarkan kode
    if (!TRANSVAR.loadFileLang(filename)) {
        std::cerr << "Kesalahan: Gagal memuat file bahasa: " << filename << "\n";
        return 1;
    }

    // Menampilkan terjemahan untuk beberapa variabel
    std::cout << TRANSVAR["halo_dunia"] << std::endl;
    std::cout << TRANSVAR["aku_makan"] << std::endl;
    std::cout << TRANSVAR["saya_tinggi"] << std::endl;

  return 0;
}
