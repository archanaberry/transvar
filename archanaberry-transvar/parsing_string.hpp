#ifndef PARSING_STRING_HPP
#define PARSING_STRING_HPP

#include <string>
#include <vector>
#include <queue>
#include <iostream>

namespace parsing_string {

// Algoritma Knuth-Morris-Pratt (KMP) untuk pencocokan pola
std::vector<int> compute_lps_array(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Fungsi pencocokan pola
bool match_pattern(const std::string& input, const std::string& pattern, std::vector<std::string>& matches) {
    size_t start = input.find("⮀");
    while (start != std::string::npos) {
        size_t end = input.find("⮀", start + 3); // Cari simbol "⮀" kedua
        if (end == std::string::npos) break;

        // Ambil bagian antara simbol "⮀"
        std::string match = input.substr(start + 3, end - start - 3);
        matches.push_back(match);

        // Lanjutkan pencarian
        start = input.find("⮀", end + 1);
    }

    return !matches.empty(); // Return true jika ada kecocokan
}

} // namespace parsing_string

#endif // PARSING_STRING_HPP
