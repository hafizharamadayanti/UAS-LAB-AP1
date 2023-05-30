#include <iostream>
#include <vector>
#include <string>

// Struktur untuk menyimpan catatan
struct Note {
    std::string judul;
    std::string isi;
    std::string waktu;
};

// Fungsi untuk menambah catatan baru
void MembuatCatatanBaru(std::vector<Note>& notes) {
    Note newNote;
    std::cout << "Masukkan judul catatan Anda = ";
    std::cin.ignore();
    std::getline(std::cin, newNote.judul);
    std::cout << "Masukkan isi catatan Anda = ";
    std::getline(std::cin, newNote.isi);
    
    // Mendapatkan tanggal saat ini dan menyimpannya ke dalam catatan
    time_t now = time(0);
    newNote.waktu = ctime(&now);
    notes.push_back(newNote);
    std::cout << "Catatan baru berhasil dibuat." << std::endl;
}

// Fungsi untuk menampilkan semua catatan
void MenampilkanSemuaCatatan(const std::vector<Note>& notes) {
    std::cout <<"\nDaftar Semua Catatan Yang Anda Miliki\n";
    for (const auto& note : notes) {
        std::cout << "Judul catatan = " << note.judul << std::endl;
        std::cout << "Isi catatan = " << note.isi << std::endl;
        std::cout << "Waktu pembuatan = " << note.waktu;
        std::cout << "-------------------------" << std::endl;
    }
}

// Fungsi untuk mencari indeks catatan berdasarkan judul
int MencariIndeksCatatan(const std::vector<Note>& notes, const std::string& judul) {
    for (size_t i = 0; i < notes.size(); ++i) {
        if (notes[i].judul == judul) {
            return i;
        }
    }
    return 1; // Return 1 jika catatan tidak ditemukan
}

// Fungsi untuk menampilkan catatan berdasarkan judul
void MenampilkanCatatan(const std::vector<Note>& notes) {
    std::cout << "Masukkan judul catatan yang ingin ditampilkan = ";
    std::cin.ignore();
    std::string judul;
    std::getline(std::cin, judul);
    int index = MencariIndeksCatatan(notes, judul);
    
    if (index != 1) {
        std::cout << "\nDaftar Catatan\n";
        std::cout << "Judul catatan = " << notes[index].judul << std::endl;
        std::cout << "Isi catatan  = " << notes[index].isi << std::endl;
        std::cout << "Waktu pembuatan = " << notes[index].waktu;
    } else {
        std::cout << "Catatan tidak ditemukan.";
    }
}

// Fungsi untuk mengedit catatan berdasarkan judul
void MengeditCatatan(std::vector<Note>& notes) {
    std::cout << "Masukkan judul catatan yang ingin diedit = ";
    std::cin.ignore();
    std::string judul;
    std::getline(std::cin, judul);
    int index = MencariIndeksCatatan(notes, judul);
    
    if (index != -1) {
        std::cout << "Masukkan isi catatan baru = ";
        std::getline(std::cin, notes[index].isi);
        std::cout << "Catatan berhasil diubah." << std::endl;
    } else {
        std::cout << "Catatan tidak ditemukan." << std::endl;
    }
}

// Fungsi untuk menghapus catatan berdasarkan judul
void MenghapusCatatan(std::vector<Note>& notes) {
    std::cout << "Masukkan judul catatan yang ingin dihapus = ";
    std::cin.ignore();
    std::string judul;
    std::getline(std::cin, judul);
    int index = MencariIndeksCatatan(notes, judul);
    
    if (index != -1) {
        notes.erase(notes.begin() + index);
        std::cout << "Catatan berhasil dihapus." << std::endl;
    } else {
        std::cout << "Catatan tidak ditemukan." << std::endl;
    }
}

// Fungsi untuk menampilkan menu dan menerima input dari pengguna
int PengelolaCatatan() {
    int menu;
    std::cout << "\n=== Pengelola Catatan ===\n"    ;
    std::cout << "1. Membuat catatan baru\n"        ;
    std::cout << "2. Menampilkan semua catatan\n"   ;
    std::cout << "3. Menampilkan catatan\n"         ;
    std::cout << "4. Mengedit catatan\n"            ;
    std::cout << "5. Menghapus catatan\n"           ;
    std::cout << "6. Exit"; 
    std::cout << "\n========================\n"     ;
    std::cout << "Masukkan pilihan anda = "         ;
    std::cin >> menu;
    return menu;
}


int main() {
    std::vector<Note> notes;
    int menu;

    do {
        menu = PengelolaCatatan();

        switch (menu) {
            case 1:
                MembuatCatatanBaru(notes);
                break;
            case 2:
                MenampilkanSemuaCatatan(notes);
                break;
            case 3:
                MenampilkanCatatan(notes);
                break;
            case 4:
                MengeditCatatan(notes);
                break;
            case 5:
                MenghapusCatatan(notes);
                break;
            case 6:
                std::cout << "Terima kasih telah menggunakan program ini. Good Bye!\n";
                break;
            default:
                std::cout << "Pilihan tidak ditemukan. Please try again.\n";
        }
        
        std::cout << std::endl;
    } while (menu != 6);

    return 0;
}