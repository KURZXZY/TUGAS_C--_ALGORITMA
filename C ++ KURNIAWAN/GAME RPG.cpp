/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Character {
public:
    string name;
    int health;
    int experience;
    int energy;
    int level;
    int attackPower;

    Character(string n, int h, int exp, int en, int lvl, int atk)
        : name(n), health(h), experience(exp), energy(en), level(lvl), attackPower(atk) {}
        //nama   //Kesehatan //Pengalaman   //energi      //level    //Kekuatan Menyerang
    // Fungsi untuk menampilkan status karakter
    void displayStatus() {
        cout << "Nama: " << name << "\n";
        cout << "Level: " << level << "\n";
        cout << "Kesehatan: " << health << "\n";
        cout << "Energi: " << energy << "\n";
        cout << "Pengalaman: " << experience << "\n";
        cout << endl;
    }

    // Fungsi untuk menyerang
    void attack(Character &target) {
        cout << name << " menyerang! -" << attackPower << " Darah\n";
        target.health -= attackPower;
        increaseExperience(10);//meningkatkan Pengalaman
        increaseEnergy(-5);//meningkatkan Energi
        displayAfterAttackStatus(); //Menampilkan status setelah menyerang
    }   

    // Fungsi untuk memulihkan
    virtual void heal() {
        cout << name << " memulihkan diri. +10XP\n";
        increaseExperience(10);//meningkatkan Pengalaman
        increaseEnergy(-5);//meningkatkan Energi
    }

    // Fungsi untuk menampilkan status setelah menyerang
    void displayAfterAttackStatus() {//menampilkan status setelah menyerang
        cout << "Status setelah menyerang:\n";
        displayStatus();//menampilkan Status
        cout << "\n";
    }

    // Fungsi untuk menaikkan level
    void levelUp() {
        cout << name << " naik level! +50XP\n";
        level++;
        increaseExperience(50);//meningkatkan pengalaman
        energy = 100; // Reset energi setelah naik level
        attackPower += 5; // Tambahkan kekuatan serangan setiap naik level
    }

    // Fungsi untuk menambah pengalaman
    void increaseExperience(int value) {//meningkatkan pengalaman
        experience += value;
    }

    // Fungsi untuk menambah energi
    void increaseEnergy(int value) {//meningkatkan energi
        energy += value;
        if (energy > 100) {
            energy = 100; // Batasi energi maksimum menjadi 100
        }
    }
};

class Medic : public Character {
public:
    Medic(string n, int h, int exp, int en, int lvl, int atk) : Character(n, h, exp, en, lvl, atk) {}

    // Override fungsi penyembuhan untuk memulihkan semua pahlawan
    void heal() override {
        cout << name << " Menambahkan +10XP untuk semua!\n";
        increaseExperience(10);//meningkatkan pengalaman
        increaseEnergy(-5);//meningkatkan energi

        // Memulihkan semua pahlawan
        // Catatan: Implementasikan sesuai kebutuhan permainan
        // Pada contoh ini, hanya menambahkan darah semua pahlawan sebanyak 20
        health += 20;
    }

    // Fungsi untuk memulihkan karakter tertentu
    void heal(Character &target) {
        cout << name << " memulihkan " << target.name << ". +20 Darah\n";
        target.health += 20;
    }
};

class Enemy : public Character {
public:
    Enemy(string n, int h, int exp, int en, int lvl, int atk) : Character(n, h, exp, en, lvl, atk) {}

    // Fungsi untuk menaikkan level musuh
    void levelUp() {
        cout << name << " naik level!\n";
        level++;
        health += 20; // Tambahkan darah setiap naik level
        attackPower += 5; // Tambahkan kekuatan serangan musuh setiap naik level
    }

    // Fungsi untuk menampilkan status musuh
    void displayStatus() {
        cout << "Musuh " << name << " - Level: " << level << "\n";
        cout << "Kesehatan: " << health << "\n";
        cout << "Serangan: " << attackPower << "\n";
        cout << endl;
    }

    // Fungsi untuk menyerang pahlawan
    void attack(Character &target) {
        cout << name << " menyerang " << target.name << "! -" << attackPower << " Darah\n";
        target.health -= attackPower;
        target.displayStatus(); // Menampilkan status pahlawan setelah diserang
    }
};

// Fungsi untuk memilih karakter atau musuh
Character& chooseCharacter(Character &knight, Character &archer, Medic &medic, Enemy &monster) {
    int choice;
    cout << "<===========>";
    cout << endl;
    cout << "Kodingan Jawa";
    cout << endl;
    cout << "<===========>";
    cout << endl;
    cout << "Pilih karakter\n";
    cout << "1. Kesatria\n";
    cout << "2. Pemanah\n";
    cout << "3. Medis\n";
    cout << "0. Keluar\n";
    cout << "Pilihan: ";
    cin >> choice;

    switch (choice) {
        case 1:
            return knight;
        case 2:
            return archer;
        case 3:
            return medic;
        case 0:
            exit(0);
        default:
            cout << "Pilihan tidak valid. Memilih secara default Kesatria.\n";
            return knight;
    }
}

int main() {
    Character knight("Kesatria", 100, 0, 100, 1, 10);
    Character archer("Pemanah", 80, 0, 100, 1, 15);
    Medic medic("Medis", 90, 0, 100, 1, 8);
    Enemy monster("Monster", 50, 0, 100, 1, 12);

    int choice;

    do {
        Character &selectedCharacter = chooseCharacter(knight, archer, medic, monster);
        selectedCharacter.displayStatus();

        cout << "Opsi:\n";
        cout << "1. Serang\n";
        cout << "2. Memulihkan\n";
        cout << "3. Level Musuh\n";
        cout << "4. Item\n";
        cout << "5. Status Musuh\n";  // Opsi status musuh ditambahkan
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (selectedCharacter.health > 0) {
                monster.attack(selectedCharacter);
                selectedCharacter.attack(monster);
                selectedCharacter.displayStatus();
            } else {
                cout << selectedCharacter.name << " sudah mati!\n";
            }

            if (monster.health <= 0) {
                cout << "Monster dikalahkan! +50XP\n";
                knight.increaseExperience(50);
                archer.increaseExperience(50);
                medic.increaseExperience(50);
                monster = Enemy("Monster", 50, 0, 100, 1, 12);
                if (knight.experience >= 100) {
                    knight.levelUp();
                }
                if (archer.experience >= 100) {
                    archer.levelUp();
                }
                if (medic.experience >= 100) {
                    medic.levelUp();
                }
            }
            break;
        case 2:
            if (choice == 2) {
                medic.heal(knight);
                medic.heal(archer);
                medic.heal();
                selectedCharacter.displayStatus();
            }
            break;
        case 3:
            monster.levelUp();
            cout << "Level musuh dinaikkan!\n";
            cout << endl;
            selectedCharacter.increaseExperience(20);
            selectedCharacter.displayStatus();
            break;
        case 4:
            cout << "Pilih item:\n";
            cout << "1. Peningkatan Darah (+20 Darah)\n";
            cout << "2. Peningkatan Serangan (+5 Serangan)\n";
            cout << "3. Menambahkan Exp (+10 EXP)\n";
            cout << "Pilihan: ";
            cin >> choice;
            switch (choice) {
            case 1:
                cout << "Menggunakan item: Peningkatan Darah (+20 Darah)\n";
                knight.health += 20;
                archer.health += 20;
                medic.health += 20;
                selectedCharacter.increaseExperience(10);
                selectedCharacter.increaseEnergy(-5);
                selectedCharacter.displayStatus();
                break;
            case 2:
                cout << "Menggunakan item: Peningkatan Serangan (+5 Serangan)\n";
                knight.attackPower += 5;
                archer.attackPower += 5;
                medic.attackPower += 5;
                selectedCharacter.increaseExperience(10);
                selectedCharacter.increaseEnergy(-5);
                selectedCharacter.displayStatus();
                break;
            case 3:
                cout << "Menggunakan item: Menambahkan Exp (+10 EXP)\n";
                if (medic.health > 0) {
                    medic.heal();
                } else {
                    cout << "Medis sudah mati!\n";
                }
                selectedCharacter.increaseExperience(10);
                selectedCharacter.increaseEnergy(-5);
                selectedCharacter.displayStatus();
                break;
            default:
                cout << "Pilihan tidak valid.\n";
            }
            break;
        case 5:
            monster.displayStatus();  // Menampilkan status musuh
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }

    } while (choice != 0);

    return 0;
}



