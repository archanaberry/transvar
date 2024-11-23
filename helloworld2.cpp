#include <iostream>
#include "transvar.hpp"

int main() {
    // Memuat file bahasa (misalnya "halodunia.id" untuk bahasa Indonesia)
    TRANSVAR.loadFileLang("halodunia.id");

    // Menampilkan nilai variabel bahasa
    std::cout << TRANSVAR["halo_dunia"] << std::endl;

    return 0;
}
