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

    cout << "�dv�z�lj�k a rakt�r rendszer�nkben, k�rem v�lasszon a kilist�zott opci�k k�z�l." << endl;

    switch (currentUser.checkType())
    {
        case 1:
        {
            cout << "1. Bejelentkez�s" << endl;
            cout << "2. Kijelentkez�s" << endl;
            cout << "3. Term�kek kilist�z�sa" << endl;
            cout << "4. Term�k rendel�se" << endl;
            cout << "5. Term�k hozz�ad�sa" << endl;
            break;
        }

        case 2:
        {
            cout << "1. Bejelentkez�s" << endl;
            cout << "2. Kijelentkez�s" << endl;
            cout << "3. Term�kek kilist�z�sa" << endl;
            cout << "4. Term�k rendel�se" << endl;
            cout << "5. Term�k hozz�ad�sa" << endl;
            cout << "6. Felhaszn�l�k kilist�z�sa" << endl;
            cout << "7. Felhaszn�l� hozz�ad�sa" << endl;
            break;
        }

        default:
            cout << "1. Bejelentkez�s" << endl;
            cout << "2. Kijelentkez�s" << endl;
            cout << "3. Term�kek kilist�z�sa" << endl;
            cout << "4. Term�k rendel�se" << endl;
            break;
    }

    cin >> chosenNumber;

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
            string name;
            int sector = 0, shelf = 0, row = 0;

            //maga a lefut�s
            cout << "Adja meg a term�k nev�t: (sz�veg)" << endl;
            cin >> name;
            cout << "Adja meg a term�k szektor�t: (sz�m)" << endl;
            cin >> sector;
            cout << "Adja meg a term�k polc�t: (sz�m)" << endl;
            cin >> shelf;
            cout << "Adja meg a term�k sor�t: (sz�m)" << endl;
            cin >> row;

            db.addProduct(name, sector, shelf, row, productId);
            productId++;
            
        }
        else {
            cout << "Nem rendelkezik megfelel� jogokkal" << endl;
        }
        
        break;
    }

    //Term�k t�rl�se
    case 6: {

        if (currentUser.checkType() >= 1) {

            int id;

            cout << "Adja meg a kit�rlend� term�k k�dj�t: (sz�m)" << endl;
            cin >> id;

            db.deleteProduct(id);

        }
        else {
            cout << "Nem rendelkezik megfelel� jogokkal" << endl;
        }
        
        break;
    }

    //Felhaszn�l�k kilist�z�sa
    case 7: {

        if (currentUser.checkType() >= 2) {

            int toBeListed;

            cout << "-------------------------------------" << endl;
            cout << "1. Dolgoz�k list�z�sa" << endl;
            cout << "2. V�s�rl�k list�z�sa" << endl;
            cout << "3. �sszes list�z�sa" << endl;
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
                    cout << "Helytelen sz�mot adott meg" << endl;
                    break;
                }
                    break;
            }

        }
        else {
            cout << "Nem rendelkezik megfelel� jogokkal" << endl;
        }
        break;
    }
    
    //Felhaszn�l� hozz�ad�sa
    case 8: {

        if (currentUser.checkType() >= 2) {

        }
        else {
        cout << "Nem rendelkezik megfelel� jogokkal" << endl;
    }
        break;
    }

    //Felhaszn�l� t�rl�se
    case 9: {

        if (currentUser.checkType() >= 2) {
            
            string codeWantDeleted;
            
            cout << "K�rem adja meg a kit�rlend� k�dot" << endl;
            cin >> codeWantDeleted;

            db.deleteUser(codeWantDeleted);
        }
        else {
            cout << "Nem rendelkezik megfelel� jogokkal" << endl;
        }
        break;
    }

    default:
        cout << "Helytelen sz�mot adott meg" << endl;
        break;
    }

}