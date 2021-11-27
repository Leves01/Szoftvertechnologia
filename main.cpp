#include "includes.h"
#include "user.h"
#include "database.h"
#include <fstream>

void fileWrite(const std::string& filename,const std::string& text)
{
    std::ofstream file(filename);
    file << text;
    file.close();
}

void fileRead(const std::string& filename)
{
    std::string line;
    std::ifstream file(filename);
    if (file.is_open())
    {
        while (std::getline(file, line))
            std::cout << line << '\n';
    }
    file.close();
}

int main()
{
    
    //main változók
    Database db;
    int chosenNumber = 0;
    User currentUser;
    int productId = 1;

    //ezzel amúgy annyi a baj, hogy ha akarunk valamit csinálni a fájllal a mainen belül
    //akkor konkrétan nem tudunk mert bezárja a függvény a fájlt
    //még a függvényen belül

    //fileRead("users.txt");

    //konstruktorral?, fogalmam sincs hogyan kéne ezt megoldani, magában a txt-ben valami ilyesmi lenne:
    //
    //Hurut Ferenc; 2004.05.14; Budapest Kobanyai utca 4; asd123; ab12; 2;
    //Jozsi Jozsi; 1993.11.02; Kolozsvár Tulipan negyed R / 2; szeretemakakaot; 22er; 1;
    //
    //; elválasztó, és így konstruktorral be tudja baszni a listába a dolgokat?
    //vagy lehet nem konstruktor kell hanem írni kell egy ilyen függvényt, ötletem sincs

    std::cout << "Udvozoljuk a raktar rendszerunkben, kerem valasszon a kilistazott opciok kozul." << std::endl;
    
    //txt iras olvasas mukodik de nem hiszem hasznat tudjuk venni a fuggvenyeknek mindenhol xd
    //fileWrite("proba.txt", "Tokeletesen mukodik.\nMasodik sor.\n");
    //fileRead("proba.txt");

    switch (currentUser.checkType())
    {
        case 1:
        {
            std::cout << "1. Bejelentkezes" << std::endl;
            std::cout << "2. Kijelentkezes" << std::endl;
            std::cout << "3. Termekek kilistazasa" << std::endl;
            std::cout << "4. Termek rendelese" << std::endl;
            std::cout << "5. Termek hozzáadasa";
            break;
        }

        case 2:
        {
            std::cout << "1. Bejelentkezes" << std::endl;
            std::cout << "2. Kijelentkezes" << std::endl;
            std::cout << "3. Termekek kilistazasa" << std::endl;
            std::cout << "4. Termek rendelese" << std::endl;
            std::cout << "5. Termek hozzaadasa" << std::endl;
            std::cout << "6. Felhasznalok kilistazasa" << std::endl;
            std::cout << "7. Felhasznalo hozzaadasa";
            break;
        }

        default:
            std::cout << "1. Bejelentkezes" << std::endl;
            std::cout << "2. Kijelentkezes" << std::endl;
            std::cout << "3. Termekek kilistazasa" << std::endl;
            std::cout << "4. Termek rendelese";
            break;
    }

    std::cin >> chosenNumber;

    //std::cout << "teszt2" << std::endl;

    switch (chosenNumber)
    {

    //Bejelentkezés
    case 1: {
        std::string loginUser;
        std::string loginPassword;

        std::cout << "Adja meg a felhasznalonevet: ";
        std::cin >> loginUser;
        std::cout << "Adja meg a jelszavat: ";
        std::cin >> loginPassword;

        db.login(loginUser, loginPassword, currentUser);

        //cpp még nincs kész

        break;
    }

    //Kijelentkezés
    case 2: {

        break;
    }
    
    //Termékek kilistázása
    case 3: {
        std::cout << "Ende3" << std::endl;
        break;
    }

    //Termék rendelése
    case 4: {

        break;
    }

    //Termék hozzáadása
    case 5: {

        if (currentUser.checkType() >= 1) {

            std::string name;
            int sector = 0, shelf = 0, row = 0;

            std::cout << "Adja meg a termek nevet: (szoveg)";
            std::cin >> name;
            std::cout << "Adja meg a termek szektorat: (szam)";
            std::cin >> sector;
            std::cout << "Adja meg a termek polcat: (szam)";
            std::cin >> shelf;
            std::cout << "Adja meg a termek sorat: (szam)";
            std::cin >> row;

            db.addProduct(name, sector, shelf, row, productId);
            productId++;
            
        }
        else {
            std::cout << "Nem rendelkezik megfelelo jogokkal" << std::endl;
        }
        
        break;
    }

    //Termék törlése
    case 6: {

        if (currentUser.checkType() >= 1) {

            int id;

            std::cout << "Adja meg a kitorlendo termek kodjat: (szam)";
            std::cin >> id;

            db.deleteProduct(id);

        }
        else {
            std::cout << "Nem rendelkezik megfelelo jogokkal";
        }
        
        break;
    }

    //Felhasználók kilistázása
    case 7: {

        if (currentUser.checkType() >= 2) {

            int toBeListed;

            std::cout << "-------------------------------------" << std::endl;
            std::cout << "1. Dolgozok listazasa" << std::endl;
            std::cout << "2. Vasarlok listazasa" << std::endl;
            std::cout << "3. Osszes listazasa";
            std::cin >> toBeListed;

            switch (toBeListed)
            {
                case 1:
                {
                    db.listWorkers();
                    break;
                }

                case 2:
                {
                    db.listBuyers();
                    break;
                }

                case 3:
                {
                    db.listAll();
                    break;
                }

                default: 
                {
                    std::cout << "Helytelen szamot adott meg" << std::endl;
                    break;
                }
                break;
            }

        }
        else {
            std::cout << "Nem rendelkezik megfelelo jogokkal" << std::endl;
        }
        break;
    }
    
    //Felhasználó hozzáadása
    case 8: {

        if (currentUser.checkType() >= 2) {

            std::string newFullName;
            std::string newDateOfBirth;
            std::string newAddress;
            std::string newPassword;
            int newType;

            std::cout << "Adja meg a teljes nevet";
            std::cin >> newFullName;
            std::cout << "Adja meg a szuletesi evet";
            std::cin >> newDateOfBirth;
            std::cout << "Adja meg a lakcimet";
            std::cin >> newAddress;
            std::cout << "Adja meg a jelszot";
            std::cin >> newPassword;
            std::cout << "Adja meg a felhasznalo tipusat";
            std::cin >> newType;

            db.addUser(newFullName, newDateOfBirth, newAddress, newPassword, newType);

        }
        else {
            std::cout << "Nem rendelkezik megfelelo jogokkal" << std::endl;
        }

        break;
    }

    //Felhasználó törlése
    case 9: {

        if (currentUser.checkType() >= 2) {
            
            std::string codeWantDeleted;
            
            std::cout << "Kerem adja meg a kitorlendõ kodot";
            std::cin >> codeWantDeleted;

            db.deleteUser(codeWantDeleted);
        }
        else {
            std::cout << "Nem rendelkezik megfelelo jogokkal" << std::endl;
        }
        break;
    }

    default:
        std::cout << "Helytelen szamot adott meg" << std::endl;
        break;
    }

    //std::cout << "teszt3" << std::endl;

    return 0;
}