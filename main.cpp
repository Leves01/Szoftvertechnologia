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

    cout << "Üdvözöljük a raktár rendszerünkben, kérem válasszon a kilistázott opciók közül." << endl;

    switch (currentUser.checkType())
    {
        case 1:
        {
            cout << "1. Bejelentkezés" << endl;
            cout << "2. Kijelentkezés" << endl;
            cout << "3. Termékek kilistázása" << endl;
            cout << "4. Termék rendelése" << endl;
            cout << "5. Termék hozzáadása" << endl;
            break;
        }

        case 2:
        {
            cout << "1. Bejelentkezés" << endl;
            cout << "2. Kijelentkezés" << endl;
            cout << "3. Termékek kilistázása" << endl;
            cout << "4. Termék rendelése" << endl;
            cout << "5. Termék hozzáadása" << endl;
            cout << "6. Felhasználók kilistázása" << endl;
            cout << "7. Felhasználó hozzáadása" << endl;
            break;
        }

        default:
            cout << "1. Bejelentkezés" << endl;
            cout << "2. Kijelentkezés" << endl;
            cout << "3. Termékek kilistázása" << endl;
            cout << "4. Termék rendelése" << endl;
            break;
    }

    cin >> chosenNumber;

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
            string name;
            int sector = 0, shelf = 0, row = 0;

            //maga a lefutás
            cout << "Adja meg a termék nevét: (szöveg)" << endl;
            cin >> name;
            cout << "Adja meg a termék szektorát: (szám)" << endl;
            cin >> sector;
            cout << "Adja meg a termék polcát: (szám)" << endl;
            cin >> shelf;
            cout << "Adja meg a termék sorát: (szám)" << endl;
            cin >> row;

            db.addProduct(name, sector, shelf, row, productId);
            productId++;
            
        }
        else {
            cout << "Nem rendelkezik megfelelõ jogokkal" << endl;
        }
        
        break;
    }

    //Termék törlése
    case 6: {

        if (currentUser.checkType() >= 1) {

            int id;

            cout << "Adja meg a kitörlendõ termék kódját: (szám)" << endl;
            cin >> id;

            db.deleteProduct(id);

        }
        else {
            cout << "Nem rendelkezik megfelelõ jogokkal" << endl;
        }
        
        break;
    }

    //Felhasználók kilistázása
    case 7: {

        if (currentUser.checkType() >= 2) {

            int toBeListed;

            cout << "-------------------------------------" << endl;
            cout << "1. Dolgozók listázása" << endl;
            cout << "2. Vásárlók listázása" << endl;
            cout << "3. Összes listázása" << endl;
            cin >> toBeListed;

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
                    cout << "Helytelen számot adott meg" << endl;
                    break;
                }
                    break;
            }

        }
        else {
            cout << "Nem rendelkezik megfelelõ jogokkal" << endl;
        }
        break;
    }
    
    //Felhasználó hozzáadása
    case 8: {

        if (currentUser.checkType() >= 2) {

        }
        else {
        cout << "Nem rendelkezik megfelelõ jogokkal" << endl;
    }
        break;
    }

    //Felhasználó törlése
    case 9: {

        if (currentUser.checkType() >= 2) {
            
            string codeWantDeleted;
            
            cout << "Kérem adja meg a kitörlendõ kódot" << endl;
            cin >> codeWantDeleted;

            db.deleteUser(codeWantDeleted);
        }
        else {
            cout << "Nem rendelkezik megfelelõ jogokkal" << endl;
        }
        break;
    }

    default:
        cout << "Helytelen számot adott meg" << endl;
        break;
    }

}