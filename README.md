Langkah untuk Menjalankan Program

1. Instal OpenSSL:
Pastikan pustaka OpenSSL terinstal di sistem Anda.
Pada Linux, gunakan: sudo apt-get install libssl-dev.
Pada Windows, pastikan Anda sudah mengonfigurasi OpenSSL dan menyertakan file header-nya.

2. Kompilasi:
Gunakan compiler seperti g++ untuk mengompilasi kode:
g++ -o file_checker file_checker.cpp -lssl -lcrypto

3. Jalankan
Jalankan program:
./file_checker

4. Uji Program:
Berikan path file yang ingin diperiksa.
Masukkan hash referensi untuk memverifikasi integritas (opsional).
