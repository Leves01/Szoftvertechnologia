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
void readUsers(Database &B) //EZZEL A GECIVEL LEHET BETOLTENI A USER.TXT-BOL A FOSOKAT main-ben  a database db-re kell megh�vni na csa megyek kocsmazni
{
    std::ifstream file;
    file.open("users.txt");
    if (!file.is_open()) std::cout << "GECIRE NEMJO XD";

    std::string line, word, vezetek, kereszt, szul, cimxd=".", pw,kode;
    int clap=0;
    
    while(std::getline(file,line))
    {
        int tag = 0;
        while (file >> word && tag != 12)
        {
            
            if (word == ";")
                tag++;
            if (tag == 0) {
                vezetek = word;
                tag++;
            }
            else if (tag == 1)
            {
                kereszt = word;
                tag++;
            }
            else if (tag == 3)
            {
                szul = word;
                tag++;
            }
            else if(tag == 5)
            {
                if (cimxd == ".")
                    cimxd = word;
                else
                {
                    cimxd+= " " + word;

                }
            }
            else if (tag == 7)
            {
                pw = word;
                tag++;
            }
            else if (tag == 9)
            {
                kode = word;
                tag++;
                
            }
            else if (tag == 11)
            {
                clap = stoi(word);
                tag++;
            }



        }
        std::string teljesnev = vezetek + " " + kereszt;
        User A(teljesnev,szul,cimxd,pw,kode,clap);
        
        B.loadUsers(A);
        tag = 0;
    }
}
int main()
{
    
    //main v�ltoz�k
    Database db;
    char chosenChar = '0';
    User defaultUser = User("default", "2000.01.01", "defaultstreet", "123", "d3f4", 2); //ez majd 0 lesz csak teszteltem
    User currentUser = defaultUser;

    

    //ezt lehet hogy ki k�ne rakni egy f�jlba, hogy a program �jraind�t�skor ne az 1-es idre
    //pr�b�ljon mindig term�ket berakni
    int productId = 1;



    //fileRead("users.txt");

    
    
    //Hurut Ferenc; 2004.05.14; Budapest Kobanyai utca 4; asd123; ab12; 2;
    //Jozsi Jozsi; 1993.11.02; Kolozsv�r Tulipan negyed R / 2; szeretemakakaot; 22er; 1;
    
   

    std::cout << "Udvozoljuk a raktar rendszerunkben, kerem valasszon a kilistazott opciok kozul:" << std::endl;
    
    //txt iras olvasas mukodik de nem hiszem hasznat tudjuk venni a fuggvenyeknek mindenhol xd
    //fileWrite("proba.txt", "Tokeletesen mukodik.\nMasodik sor.\n");
    //fileRead("proba.txt");



    while (chosenChar != 'x') {

        switch (currentUser.checkType())
        {
        case 1:
        {
            std::cout << "1: Bejelentkezes" << std::endl;
            std::cout << "2: Kijelentkezes" << std::endl;
            std::cout << "3: Termekek kilistazasa" << std::endl;
            std::cout << "4: Termek rendelese" << std::endl;
            std::cout << "5: Termek hozz�adasa" << std::endl;
            std::cout << "6: Termek torlese" << std::endl;
            std::cout << "x Kilepes \n" << std::endl;
            break;
        }

        case 2:
        {
            std::cout << "1: Bejelentkezes" << std::endl;
            std::cout << "2: Kijelentkezes" << std::endl;
            std::cout << "3: Termekek kilistazasa" << std::endl;
            std::cout << "4: Termek rendelese" << std::endl;
            std::cout << "5: Termek hozzaadasa" << std::endl;
            std::cout << "6: Termek torlese" << std::endl;
            std::cout << "7: Felhasznalok kilistazasa" << std::endl;
            std::cout << "8: Felhasznalo hozzaadasa" << std::endl;
            std::cout << "9: Felhasznalo torlese" << std::endl;
            std::cout << "x: Kilepes \n";
            break;
        }

        default:
            std::cout << "1: Bejelentkezes" << std::endl;
            std::cout << "2: Kijelentkezes" << std::endl;
            std::cout << "3: Termekek kilistazasa" << std::endl;
            std::cout << "4: Termek rendelese" << std::endl;
            std::cout << "x: Kilepes \n";
            break;
        }

        std::cin >> chosenChar;

        switch (chosenChar)
        {

            //Bejelentkez�s
            case '1': {
            std::string loginUser;
            std::string loginPassword;

            std::cout << "Adja meg a felhasznalonevet: \n";
            std::cin >> loginUser;
            std::cout << "Adja meg a jelszavat: \n";
            std::cin >> loginPassword;

            db.login(loginUser, loginPassword, currentUser);

            break;
        }

            //Kijelentkez�s
            case '2': {

            currentUser = defaultUser;
            std::cout << "Sikeres kijelentkezes\n" << std::endl;

            break;
        }

            //Term�kek kilist�z�sa
            case '3': {

            break;
        }

            //Term�k rendel�se
            case '4': {

            break;
        }

            //Term�k hozz�ad�sa
            case '5': {

            if (currentUser.checkType() >= 1) {

                std::string name;
                int sector = 0, shelf = 0, row = 0;

                std::cout << "Adja meg a termek nevet: (szoveg) \n";
                std::cin >> name;
                std::cout << "Adja meg a termek szektorat: (szam) \n";
                std::cin >> sector;
                std::cout << "Adja meg a termek polcat: (szam) \n";
                std::cin >> shelf;
                std::cout << "Adja meg a termek sorat: (szam) \n";
                std::cin >> row;

                db.addProduct(name, sector, shelf, row, productId);
                productId++;

            }
            else {
                std::cout << "Nem rendelkezik megfelelo jogokkal \n" << std::endl;
            }

            break;
        }

            //Term�k t�rl�se
            case '6': {

            if (currentUser.checkType() >= 1) {

                int id;

                std::cout << "Adja meg a kitorlendo termek kodjat: (szam) \n";
                std::cin >> id;

                db.deleteProduct(id);

            }
            else {
                std::cout << "Nem rendelkezik megfelelo jogokkal \n";
            }

            break;
        }

            //Felhaszn�l�k kilist�z�sa
            case '7': {

            if (currentUser.checkType() >= 2) {

                int toBeListed;

                std::cout << "-------------------------------------" << std::endl;
                std::cout << "1. Dolgozok listazasa" << std::endl;
                std::cout << "2. Vasarlok listazasa" << std::endl;
                std::cout << "3. Osszes listazasa \n";
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
                    std::cout << "Helytelen karaktert adott meg \n" << std::endl;
                    break;
                }
                break;
                }

            }
            else {
                std::cout << "Nem rendelkezik megfelelo jogokkal \n" << std::endl;
            }
            break;
        }

            //Felhaszn�l� hozz�ad�sa
            case '8': {

            if (currentUser.checkType() >= 2) {

                std::string newFullName;
                std::string newDateOfBirth;
                std::string newAddress;
                std::string newPassword;
                int newType;

                std::cout << "Adja meg a teljes nevet: \n";
                std::cin >> newFullName;
                std::cout << "Adja meg a szuletesi evet: \n";
                std::cin >> newDateOfBirth;
                std::cout << "Adja meg a lakcimet: \n";
                std::cin >> newAddress;
                std::cout << "Adja meg a jelszot: \n";
                std::cin >> newPassword;
                std::cout << "Adja meg a felhasznalo tipusat: \n";
                std::cin >> newType;

                db.addUser(newFullName, newDateOfBirth, newAddress, newPassword, newType);

            }
            else {
                std::cout << "Nem rendelkezik megfelelo jogokkal" << std::endl;
            }

            break;
        }

            //Felhaszn�l� t�rl�se
            case '9': {

            if (currentUser.checkType() >= 2) {

                std::string codeWantDeleted;

                std::cout << "Kerem adja meg a kitorlend� kodot: \n";
                std::cin >> codeWantDeleted;

                db.deleteUser(codeWantDeleted);
            }
            else {
                std::cout << "Nem rendelkezik megfelelo jogokkal" << std::endl;
            }
            break;
        }

        default:
            std::cout << "Helytelen karaktert adott meg" << std::endl;
            break;
        }

        //std::cout << "teszt3" << std::endl;


    }

    //std::cout << "teszt2" << std::endl;
 
    return 0;
}