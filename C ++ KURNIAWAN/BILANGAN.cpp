/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
int A,B;


std::cout << "MASUKAN BILANGAN GANJIL:";
std::cin >> A;

std::cout <<"MASUKAN BILANGAN GENAP:";
std::cin >> B;

if(A % 2 !=0 && B % 2 ==0){
    std::cout << "BENAR," << A << "BILANGAN GANJIL DAN " << B << "BILANGAN GENAP" <<std::endl;
} else if ( A % 2 ==0 && B % 2 !=0){
    std::cout << "MAAF SALAH," << A << " BILANGAN GENAP DAN " << B<< "BILANGAN GANJIL"<< std::endl;
} else if (A % 2 ==0){
    std::cout << "MAAF SALAH," << A<< " BILANGAN GENAP";
} else if ( B % 2 !=0){
    std::cout << "MAAF SALAH," << B << " BILANGAN GANJIL";
}

    return 0;
}

