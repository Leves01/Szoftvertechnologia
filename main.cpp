#include "includes.h"
#include "user.h"
#include "database.h"

int main()
{
    
    //main v�ltoz�k
    Database db;
    int chosenNumber = 0;
    User currentUser;
    int productId = 1;

    std::cout << "Udvozoljuk a raktar rendszerunkben, kerem valasszon a kilistazott opciok kozul." << std::endl;

    switch (currentUser.checkType())
    {
        case 1:
        {
            std::cout << "1. Bejelentkezes" << std::endl;
            std::cout << "2. Kijelentkezes" << std::endl;
            std::cout << "3. Termekek kilistazasa" << std::endl;
            std::cout << "4. Termek rendelese" << std::endl;
            std::cout << "5. Termek hozz�adasa" << std::endl;
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
            std::cout << "7. Felhasznalo hozzaadasa" << std::endl;
            break;
        }

        default:
            std::cout << "1. Bejelentkezes" << std::endl;
            std::cout << "2. Kijelentkezes" << std::endl;
            std::cout << "3. Termekek kilistazasa" << std::endl;
            std::cout << "4. Termek rendelese" << std::endl;
            break;
    }

    std::cin >> chosenNumber;

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
            std::cout << "Adja meg a termek nevet: (szoveg)" << std::endl;
            std::cin >> name;
            std::cout << "Adja meg a termek szektorat: (szam)" << std::endl;
            std::cin >> sector;
            std::cout << "Adja meg a termek polcat: (szam)" << std::endl;
            std::cin >> shelf;
            std::cout << "Adja meg a termek sorat: (szam)" << std::endl;
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

            std::cout << "Adja meg a kitorlendo termek kodjat: (szam)" << std::endl;
            std::cin >> id;

            db.deleteProduct(id);

        }
        else {
            std::cout << "Nem rendelkezik megfelelo jogokkal" << std::endl;
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
            std::cout << "3. Osszes listazasa" << std::endl;
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
            
            std::cout << "Kerem adja meg a kitorlend� kodot" << std::endl;
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

    return 0;
}