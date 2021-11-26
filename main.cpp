#include "includes.h"
#include "user.h"
#include "database.h"

int main()
{
    
    //main változók
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
            std::cout << "5. Termek hozzáadasa" << std::endl;
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

    //Bejelentkezés
    case 1: {


        break;
    }

    //Kijelentkezés
    case 2: {

        break;
    }
    
    //Termékek kilistázása
    case 3: {

        break;
    }

    //Termék rendelése
    case 4: {

        break;
    }

    //Termék hozzáadása
    case 5: {

        if (currentUser.checkType() >= 1) {

            //lokális változók
            std::string name;
            int sector = 0, shelf = 0, row = 0;

            //maga a lefutás
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

    //Termék törlése
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

    //Felhasználók kilistázása
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
    
    //Felhasználó hozzáadása
    case 8: {

        if (currentUser.checkType() >= 2) {

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
            
            std::cout << "Kerem adja meg a kitorlendõ kodot" << std::endl;
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