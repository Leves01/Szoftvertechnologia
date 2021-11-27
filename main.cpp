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
    
    //main v�ltoz�k
    Database db;
    int chosenNumber = 0;
    User currentUser;
    int productId = 1;

    //ezzel am�gy annyi a baj, hogy ha akarunk valamit csin�lni a f�jllal a mainen bel�l
    //akkor konkr�tan nem tudunk mert bez�rja a f�ggv�ny a f�jlt
    //m�g a f�ggv�nyen bel�l
    fileRead("users.txt");

    //konstruktorral?, fogalmam sincs hogyan k�ne ezt megoldani, mag�ban a txt-ben valami ilyesmi lenne:
    //
    //Hurut Ferenc; 2004.05.14; Budapest Kobanyai utca 4; asd123; ab12; 2;
    //Jozsi Jozsi; 1993.11.02; Kolozsv�r Tulipan negyed R / 2; szeretemakakaot; 22er; 1;
    //
    //; elv�laszt�, �s �gy konstruktorral be tudja baszni a list�ba a dolgokat?
    //vagy lehet nem konstruktor kell hanem �rni kell egy ilyen f�ggv�nyt, �tletem sincs

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
            std::cout << "5. Termek hozz�adasa";
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
    std::cout << "gyorsende" << std::endl;

    switch (chosenNumber)
    {

    //Bejelentkez�s
    case 1: {


        break;
    }

    //Kijelentkez�s
    case 2: {

        break;
    }
    
    //Term�kek kilist�z�sa
    case 3: {
        std::cout << "Ende3" << std::endl;
        break;
    }

    //Term�k rendel�se
    case 4: {

        break;
    }

    //Term�k hozz�ad�sa
    case 5: {

        if (currentUser.checkType() >= 1) {

            //lok�lis v�ltoz�k
            std::string name;
            int sector = 0, shelf = 0, row = 0;

            //maga a lefut�s
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

    //Term�k t�rl�se
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

    //Felhaszn�l�k kilist�z�sa
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
    
    //Felhaszn�l� hozz�ad�sa
    case 8: {

        if (currentUser.checkType() >= 2) {

            /*cout <<
            cin >>

            db.addUser*/
        }
        else {
        std::cout << "Nem rendelkezik megfelelo jogokkal" << std::endl;
    }
        break;
    }

    //Felhaszn�l� t�rl�se
    case 9: {

        if (currentUser.checkType() >= 2) {
            
            std::string codeWantDeleted;
            
            std::cout << "Kerem adja meg a kitorlend� kodot";
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

    std::cout << "Ende" << std::endl;

    return 0;
}