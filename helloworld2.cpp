#include "transvar.hpp"

int main() {
    // Memuat file bahasa
    if (!TRANSVAR.loadFileLang("halodunia.id")) {
        return 1; // Keluar jika file bahasa tidak ditemukan
    }

    // Mendapatkan terjemahan
    std::cout << TRANSVAR["halo"] << std::endl;

    return 0;
}
