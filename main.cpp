#include "includes.h"
#include "users.h"

int main()
{
    
    //valamilyen user tömböt kéne ide csinálni, hogy eltároja az eddig hozzáadott felhasználókat
    //nem biztos hogy Users* típusú mert meg kell hívnia azt a sok szart ami benne vagy a workerbe
    //+ lehet list jobb lenne mert memóriakezelés
    Users* userArray;

    //valami login dolog, hogy a worker be tudjon jelentkezni, de a például a rendelés mûködjön anélkül is

    cout << "Üdvözöljük a raktár rendszerünkben, kérem válasszon a kilistázott opciók közül." << endl;
    cout << "Termékek kilistázása" << endl;
    cout << "Termék rendelése" << endl;
    cout << "Bejelentkezés" << endl;
    cout << "Felhasználók kilistázása" << endl;

}