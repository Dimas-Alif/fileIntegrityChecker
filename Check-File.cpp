#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h> // Library OpenSSL untuk SHA-256
#include <string>

// Fungsi untuk menghitung hash SHA-256 dari sebuah file
std::string calculateSHA256(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Gagal membuka file: " + filePath);
    }

    SHA256_CTX sha256;
    SHA256_Init(&sha256);

    const size_t bufferSize = 4096;
    char buffer[bufferSize];
    while (file.good()) {
        file.read(buffer, bufferSize);
        SHA256_Update(&sha256, buffer, file.gcount());
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_Final(hash, &sha256);

    std::stringstream hashString;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        hashString << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }

    return hashString.str();
}

// Fungsi utama
int main() {
    std::string filePath;
    std::string referenceHash;

    std::cout << "=== File Integrity Checker ===\n";
    std::cout << "Masukkan path file: ";
    std::getline(std::cin, filePath);

    try {
        // Hitung hash SHA-256 dari file
        std::string computedHash = calculateSHA256(filePath);
        std::cout << "Hash file (SHA-256): " << computedHash << "\n";

        // Bandingkan dengan hash referensi (jika tersedia)
        std::cout << "Masukkan hash referensi untuk verifikasi (atau tekan ENTER untuk melewati): ";
        std::getline(std::cin, referenceHash);

        if (!referenceHash.empty()) {
            if (computedHash == referenceHash) {
                std::cout << "Hasil: File tidak dimodifikasi (hash cocok).\n";
            } else {
                std::cout << "Hasil: File telah dimodifikasi (hash tidak cocok).\n";
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
