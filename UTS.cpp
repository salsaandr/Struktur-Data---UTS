#include <iostream>
using namespace std;

struct Pengunjung {
    int nomorKamar;
    string nama;
    int lamaMenginap;
    string tipeKamar;
    long totalHarga;
    bool statusPembayaran; 
    Pengunjung* next;
};

void garis() 
{
    for (int i=0; i<73; i++) 
    {
        cout << "=";
    }
    cout << "\n";
}

class Hotel {
private:
    Pengunjung* head;

public:
    Hotel() {
        head = NULL;
    }

    // Fungsi untuk menambahkan pengunjung baru
    void tambahPengunjung(int nomorKamar, string nama, int lamaMenginap) {
    Pengunjung* baru = new Pengunjung;
    baru->nomorKamar = nomorKamar;
    baru->nama = nama;
    baru->lamaMenginap = lamaMenginap;

    if (nomorKamar >= 1 && nomorKamar <= 5) {
        baru->tipeKamar = "classic";
        baru->totalHarga = 900000 * lamaMenginap;
    } else if (nomorKamar >= 6 && nomorKamar <= 10) {
        baru->tipeKamar = "deluxe";
        baru->totalHarga = 1400000 * lamaMenginap;
    } else {
        cout << "Nomor kamar tidak valid." << endl;
        delete baru;
        return;
    }

    baru->statusPembayaran = false; // defaultnya belum dibayar

    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Pengunjung* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Total yang harus dibayar: Rp." << baru->totalHarga << endl;
    garis();
	}

    // Fungsi untuk menampilkan semua pengunjung yang terdaftar
    void tampilkanPengunjung() {
    	cout << "=========================== DAFTAR PENGUNJUNG ===========================\n\n";
        Pengunjung* temp = head;
        while (temp != NULL) {
            cout << "Nomor Kamar: " << temp->nomorKamar << endl;
            cout << "Nama Pengunjung: " << temp->nama << endl;
            cout << "Lama Menginap: " << temp->lamaMenginap << " hari" << endl;
            cout << "Tipe Kamar: " << temp->tipeKamar << endl;
            cout << "Total Harga: Rp." << temp->totalHarga << endl;
            cout << "Status Pembayaran: " << (temp->statusPembayaran ? "Lunas" : "Belum Dibayar") << endl;
            garis();
            temp = temp->next;
        }
    }
    
    // Fungsi untuk mencari pengunjung berdasarkan nomor kamar
void cariPengunjung(int nomorKamar) {
    Pengunjung* temp = head;
    bool ditemukan = false;
    while (temp != NULL) {
        if (temp->nomorKamar == nomorKamar) {
        	garis();
            cout << "Nomor Kamar: " << temp->nomorKamar << endl;
            cout << "Nama Pengunjung: " << temp->nama << endl;
            cout << "Lama Menginap: " << temp->lamaMenginap << " hari" << endl;
            cout << "Tipe Kamar: " << temp->tipeKamar << endl;
            cout << "Total Harga: Rp" << temp->totalHarga << endl;
            cout << "Status Pembayaran: " << (temp->statusPembayaran ? "Lunas" : "Belum Dibayar") << endl << endl;
            garis();
            ditemukan = true;
            break;
        }
        temp = temp->next;
    }
    if (!ditemukan) {
        cout << "Pengunjung dengan nomor kamar tersebut tidak ditemukan." << endl;
    }
}

     // Fungsi untuk menghapus pengunjung berdasarkan nomor kamar
    void hapusPengunjung(int nomorKamar) {
        Pengunjung* temp = head;
        Pengunjung* prev = NULL;

        if (temp != NULL && temp->nomorKamar == nomorKamar) {
            head = temp->next;
            delete temp;
            cout << "Pengunjung dengan nomor kamar " << nomorKamar << " telah dihapus." << endl;
            return;
        }
        while (temp != NULL && temp->nomorKamar != nomorKamar) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Nomor kamar tidak ditemukan." << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
        cout << "Pengunjung dengan nomor kamar " << nomorKamar << " telah dihapus." << endl;
    }

    // Fungsi untuk menampilkan kamar yang tersedia
	void tampilkanKamarTersedia() {
		cout << "====================== PILIHAN KAMAR YANG TERSEDIA ======================" << endl << endl;
	    // Tampilkan kamar Classic Room
	    cout << "Classic Room\n===============\n";
	    bool classicTersedia = false;
	    for (int i = 1; i <= 5; i++) {
	        bool tersedia = true;
	        Pengunjung* temp = head;
	        while (temp != NULL) {
	            if (temp->nomorKamar == i) {
	                tersedia = false;
	                break;
	            }
	            temp = temp->next;
	        }
	        if (tersedia) {
	            cout << "Kamar " << i << endl;
	            classicTersedia = true;
	        }
	    }
	    if (!classicTersedia) {
	        cout << "Tidak ada kamar Classic yang tersedia.\n";
	    }
	
	    cout << endl;

	    // Tampilkan kamar Deluxe Room
	    cout << "Deluxe Room\n=============\n";
	    bool deluxeTersedia = false;
	    for (int i = 6; i <= 10; i++) {
	        bool tersedia = true;
	        Pengunjung* temp = head;
	        while (temp != NULL) {
	            if (temp->nomorKamar == i) {
	                tersedia = false;
	                break;
	            }
	            temp = temp->next;
	        }
	        if (tersedia) {
	            cout << "Kamar " << i << endl;
	            deluxeTersedia = true;
	        }
	    }
	    if (!deluxeTersedia) {
	        cout << "Tidak ada kamar Deluxe yang tersedia.\n";
	    }
	    garis();
	}




    // Fungsi untuk melakukan pembayaran
    void bayarPembayaran(int nomorKamar) {
        Pengunjung* temp = head;
        int uangBayar;
        while (temp != NULL) {
            if (temp->nomorKamar == nomorKamar) {
                temp->statusPembayaran = true;
                garis();
                cout << "TOTAL YANG HARUS DIBAYAR: Rp." << temp->totalHarga << endl;
                
                
            do {
            cout << "Masukkan jumlah uang yang dibayarkan: Rp.";
            cin >> uangBayar;
            	if (uangBayar >= temp->totalHarga) {
            	int kembalian = uangBayar - temp->totalHarga;
           		cout << "Kembalian: Rp." << kembalian << endl;
            	} else cout << "Pembayaran tidak cukup. Silakan bayar dengan jumlah yang sesuai.\n" << endl;
        	} while (uangBayar < temp->totalHarga);
                
                
                cout << "Pembayaran telah diterima. Pengunjung berhasil ditambahkan." << endl;
                garis();
                return;
            }
            temp = temp->next;
        }
    }
    
    
    
};



void header() //function untuk mencetak header
{
	garis();
    cout << "                                 SJW HOTEL                                "<< endl;
	cout << "     Jalan HS.Ronggo Waluyo, Puseurjaya, Kecamatan Telukjambe Timur,      "<< endl;
	cout << "                    Kabupaten Karawang, Jawa Barat 41361.                 "<< endl;
    garis();
}



int main() {
    Hotel hotel;
    int pilihan;

    do {
    	header();
    	cout << endl << endl;
		cout << " _______________________________________________________________________ \n";
        cout << "|                         MENU PEMESANAN HOTEL                          |\n";
        cout << "|_______________________________________________________________________|\n";
        cout << "| 1. Pesan Kamar                                                        |\n";
        cout << "| 2. Tampilkan Kamar Tersedia                                           |\n";
        cout << "| 3. Tampilkan Pengunjung                                               |\n";
        cout << "| 4. Hapus Pengunjung                                                   |\n";
        cout << "| 5. Keluar                                                             |\n"; 
		cout << "|_______________________________________________________________________|\n";
        cout << "Pilih menu [1-5] : ";
        cin >> pilihan;

        system("cls"); // Membersihkan layar

        switch (pilihan) {
           case 1: {
           		header();
           		cout << endl;
           		int nomorKamar, lamaMenginap;
			    string nama;
				hotel.tampilkanKamarTersedia();
				cout << endl;
				cout << "========================= DATA PEMESANAN KAMAR ========================== \n";
				cout << "Masukkan nomor kamar yang ingin dipesan: ";
			    cin >> nomorKamar;
			    	if (nomorKamar < 1 || nomorKamar > 10) {
			        cout << "Nomor kamar tidak valid." << endl;
			        break;
			   		}
			    cout << "Masukkan nama pengunjung: ";
			    cin.ignore();
			    getline(cin, nama);
			    cout << "Masukkan lama menginap (hari): ";
			    cin >> lamaMenginap;
			    hotel.tambahPengunjung(nomorKamar, nama, lamaMenginap);
				system("pause");
			    cout << "Tekan Tombol apapun untuk melanjutkan ke proses pembayaran!\n";
			    system("cls"); 
			    hotel.bayarPembayaran(nomorKamar);
			    system("pause");
				system("cls"); 
			    break;
			}
            case 2: {
            	header();
           		cout << endl;
            	hotel.tampilkanKamarTersedia();
                system("pause");
                system("cls");
				break;
			} 
            case 3: {
				header();
           		cout << endl;
            	hotel.tampilkanPengunjung();
				system("pause");
				system("cls"); 
				break;
			}
            case 4:{
            	header();
           		cout << endl;
                int nomorKamar;
                char yn;
                cout << "========================= HAPUS DATA PENGUNJUNG =========================\n\n";
                cout << "Masukkan nomor kamar yang akan dihapus: ";
                cin >> nomorKamar;
                hotel.cariPengunjung(nomorKamar);
                cout << "Hapus data pengunjung tersebut? [Y/N] : "; cin >> yn;
                	if ( yn == 'Y' | yn == 'y'){
                	hotel.hapusPengunjung(nomorKamar);
                	system("pause");
                	system("cls");
                 	break;
                }else 
                cout << "Anda tidak menghapus pengunjung manapun." << endl;
                system("pause");
                system("cls");
                break;
            } 
            case 5: {
            	header();
           		cout << endl;
            	cout << "Anda telah keluar dari program!" << endl;
                cout << "Terima kasih!" << endl;
				break;
			} 
            default:{
            	header();
           		cout << endl;
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
                system("pause");
				system("cls"); 
				break;
			} 
        }

    } while (pilihan != 5);

    return 0;
}
