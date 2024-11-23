#ifndef TRANSVAR_HPP
#define TRANSVAR_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "parsing_string.hpp" // Menggunakan parsing_string.hpp untuk pencocokan pola

// Kelas utama TransVar untuk menangani terjemahan
class TransVar {
private:
    std::unordered_map<std::string, std::string> translations; // Map variabel ke string terjemahan

public:
    // Singleton agar mudah diakses global
    static TransVar& instance() {
        static TransVar instance;
        return instance;
    }

    // Fungsi untuk memuat file bahasa
    bool loadFile(const std::string& filename) {
        std::ifstream infile(filename);
        if (!infile) {
            std::cerr << "Gagal membuka file: " << filename << "\n";
            return false;
        }

        std::string line;
        const std::string pattern = "⮀"; // Simbol untuk memisahkan bagian
        while (std::getline(infile, line)) {
            std::vector<std::string> matches;
            if (parsing_string::match_pattern(line, pattern, matches)) {
                if (matches.size() >= 2) {
                    translations[matches[0]] = matches[1]; // Simpan ke map
                }
            }
        }

        infile.close();
        return true;
    }

    // Operator [] untuk mendapatkan terjemahan langsung
    const std::string& operator[](const std::string& variable) const {
        static const std::string not_found = "Terjemahan tidak ditemukan";
        auto it = translations.find(variable);
        if (it != translations.end()) {
            return it->second;
        }
        return not_found;
    }
};

// Makro untuk mempermudah akses
#define TRANSVAR TransVar::instance()

#endif // TRANSVAR_HPP
