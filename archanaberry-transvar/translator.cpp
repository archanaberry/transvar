#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 6) {
        std::cerr << "Penggunaan: ./transvar <variabel> -in <string_terjemahan> -out <file_output>\n";
        return 1;
    }

    std::string variable = argv[1];
    std::string option_in = argv[2];
    std::string translation = argv[3];
    std::string option_out = argv[4];
    std::string output_file = argv[5];

    // Validasi argumen
    if (option_in != "-in" || option_out != "-out") {
        std::cerr << "Argumen tidak valid. Gunakan -in untuk input string dan -out untuk file output.\n";
        return 1;
    }

    // Format string untuk ditulis ke file
    std::string formatted_line = "\u2B80" + variable + "\u2B80 = \u2B80" + translation + "\u2B80\n";

    // Membuka file dalam mode append
    std::ofstream out_file(output_file, std::ios::app);
    if (!out_file) {
        std::cerr << "Gagal membuka file output: " << output_file << "\n";
        return 1;
    }

    // Menulis ke file
    out_file << formatted_line;

    std::cout << "Baris ditambahkan ke file: " << output_file << "\n";
    return 0;
}
