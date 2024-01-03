/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int total = 0;
    int jumlahTiket;
    double Diskon = 0.0;

    int Ekonomi = 100000;
    int Bisnis = 200000;
    int Eksekutif = 300000;
    
    //ini arraynya yah ka tres
    int discountHarga[] = {500000, 300000, 200000};
    double discountPersentasi[] = {0.90, 0.95, 0.98};

    string jenistiket;
    string input;
    
    awal:
    cout << "SELAMAT DATANG DI PEMESANAN TIKET KERETA API INDONESIA" << endl;
    cout << "<====================================================>" << endl;
    cout << "JENIS TIKET KERETA API INDONESIA:" << endl << endl;
    cout << "1. EKONOMI (Rp. 100.000)" << endl;
    cout << "2. BISNIS (Rp. 200.000)" << endl;
    cout << "3. EKSEKUTIF (Rp. 300.000)" << endl << endl;
    
    printf("\033[0;31m"); //mengubah warna teks menjadi merah
    printf("PROMOO BESAR BESARAN !!! \n");
    printf("\033[0m"); // kembali ke asalnya dong
    cout << "1. Rp. 500000 DISKON 10%" << endl;
    cout << "2. Rp. 300000 DISKON 5%" << endl;
    cout << "3. RP. 200000 DISKON 2%" << endl << endl;
    
    int pilihan;
    cout << "Masukkan pilihan tiket (1 untuk kelas Ekonomi/2 untuk kelas Bisnis/3 untuk kelas Eksekutif): ";
    cin >> pilihan;

    cout << "Masukan Jumlah Tiket Yang Ingin Di Pesan : ";
    cin >> jumlahTiket;

    switch (pilihan)
    {
    case 1:
        jenistiket = "EKONOMI";
        total = Ekonomi * jumlahTiket;
        break;

    case 2:
        jenistiket = "BISNIS";
        total = Bisnis * jumlahTiket;
        break;

    case 3:
        jenistiket = "EKSEKUTIF";
        total = Eksekutif * jumlahTiket;
        break;
    }

    cout << endl;
    cout << "TIKET YANG ANDA PESAN: " << jenistiket << endl
         << "JUMLAH TIKET YANG ANDA PESAN: " << jumlahTiket << endl
         << "DENGAN TOTAL: RP. " << total << endl;

    //menerapkan  array diskonnya yah ka tres
    for (int i = 0; i < sizeof(discountHarga) / sizeof(discountHarga[0]); ++i)
    //sizeof merupakan ukuran atau jumlah byte pada tipe data yah kak tres
    {
        if (total >= discountHarga[i])
        {
            Diskon = total * (1 - discountPersentasi[i]);
            cout << "ANDA DAPAT DISKON " << (1 - discountPersentasi[i]) * 100 << "%" << endl << "POTONGAN SAAT INI RP. " << Diskon << endl;
            cout << endl;
            break;
        }
    }

    cout << "DENGAN HARGA : " << total << endl;
    cout << "TIKET : " << jenistiket << endl
         << "JUMLAH TIKET YANG ANDA PESAN : " << jumlahTiket << endl
         << "DENGAN HARGA SEBELUM DISKON : RP." << total<< endl
         << "ANDA BAYAR DENGAN JUMLAH : Rp. " << total - Diskon<< endl;
         
    cout << "Mau beli tiket lagi [Y/N]: ";
    cin >> input;
    if (input == "y" || input == "Y"){
        goto awal;
    } else{
    return 0;
    }
}


