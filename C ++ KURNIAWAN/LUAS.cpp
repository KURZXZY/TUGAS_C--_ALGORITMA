/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

double luasPersegi(double sisi, double sisi2) {
    return sisi * sisi2;
}

double luasLingkaran(double jariJari) {
    return M_PI * pow(jariJari, 2); //M_PI sebagai matematika costanta
}

double luasPersegiPanjang(double panjang, double lebar) {
    return panjang * lebar;
}

int main() {
    double sisi, sisi2, jariJari, panjang, lebar;
    string input;

    awal:
    std::cout << "Masukkan panjang sisi persegi 1: ";
    std::cin >> sisi;
    std::cout << "Masukkan panjang sisi persegi 2: ";
    std::cin >> sisi2;
    std::cout << "Masukkan jari-jari lingkaran: ";
    std::cin >> jariJari;
    std::cout << "Masukkan panjang persegi panjang: ";
    std::cin >> panjang;
    std::cout << "Masukkan lebar persegi panjang: ";
    std::cin >> lebar;
    std::cout << std::endl;

    double luasP = luasPersegi(sisi, sisi2);
    double luasL = luasLingkaran(jariJari);
    double luasPP = luasPersegiPanjang(panjang, lebar);

    std::cout << "Luas Persegi: " << luasP << std::endl;
    std::cout << "Luas Lingkaran: " << luasL << std::endl;
    std::cout << "Luas Persegi Panjang: " << luasPP << std::endl;
    
    std::cout << "Mau hitung luas lagi [Y/N]: ";
    std::cin >> input;
    
    if (input == "y" || input == "Y"){
        goto awal;
    } else{

    return 0;
}

}


