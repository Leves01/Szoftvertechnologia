#include "includes.h"
#include "user.h"
#include "database.h"

int main()
{
    
    //main változók

    int chosenNumber = 0;
    User currentUser;

    //valami login dolog, hogy a worker be tudjon jelentkezni, de a például a rendelés mûködjön anélkül is

    cout << "Üdvözöljük a raktár rendszerünkben, kérem válasszon a kilistázott opciók közül." << endl;
    cout << "1. Termékek kilistázása" << endl;
    cout << "2. Termék rendelése" << endl;
    cout << "3. Bejelentkezés" << endl;
    cout << "4. Felhasználók kilistázása" << endl;
    cout << "5. Felhasználó hozzáadása" << endl;

    cin >> chosenNumber;

    switch (chosenNumber)
    {
    case 1: {

    }

    case 2: {

    }

    case 3: {

    }

    case 4: {

    }

    case 5: {

    }

    default:
        break;
    }

}