#include "includes.h"
#include "user.h"
#include "database.h"
#include <fstream>
#include "listofproducts.h"
#include "buyer.h"
    
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
//Adatok betoltese a txt-bol:
void readUsers(Database &B) 
{
    std::ifstream file;
    file.open("users.txt");
    if (!file.is_open()) std::cout << "Users.txt nem toltott be";

    std::string line, word, vezetek, kereszt, szul, cimxd=".", pw,kode;
    int clap=0;
    
    //while(std::getline(file,line))
    //{
        int tag = 0;
        while (file >> word)
        { 
            
            
            if (word == ";")
                tag++;
            else if (tag == 0) {
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
            else if (tag == 6)
            {
                pw = word;
                tag++;
            }
            else if (tag == 8)
            {
                kode = word;
                tag++;
                
            }
            else if (tag == 10)
            {
                clap = stoi(word);
                std::string teljesnev = vezetek + " " + kereszt;
                User A(teljesnev, szul, cimxd, pw, kode, clap);
                B.loadUsers(A);
                cimxd = ".";
                tag = 0;
                
            }




        }

        
    
}
//MIVAN HA VALAKINEK 3 NEVE VAN
void readProducts(Database &B)
{
    std::ifstream file;
    file.open("products.txt");
    if (!file.is_open()) std::cout << "Products.tx nem toltott be";
   
    std::string word, nev, ID;
    int szektor, polc, sor;
    int tag = 0;

    while (file >> word)
    {
        if (tag == 0)
        {
            nev = word;
            tag++;
        }
        else if (tag == 1)
        {
            szektor = std::stoi(word);
            tag++;
        }
        else if (tag == 2)
        {
            polc = std::stoi(word);
            tag++;
        }
        else if (tag == 3)
        {
            sor = std::stoi(word);
            tag++;
        }
        else if (tag == 4)
        {
            ID = word;
            tag++;
        }
        else if (tag == 5)
        {
            Product C(nev, szektor, polc, sor, ID);
            B.loadProduct(C);
            tag = 0;
        }
            


    }
}



//std::string name;0
//int sector;1
//int shelf;2
//int row;3
//int id;4
//Cserep 1 2 3 1 ; 

int main()
{
    
    //main v�ltoz�k
    Database db;
    char chosenChar = '0';
    User defaultUser = User("default", "2000.01.01", "defaultstreet", "123", "d3f4", 0); //ez majd 0 lesz csak teszteltem
    User currentUser = defaultUser;
    
    readUsers(db);
    //db.listAll();

    readProducts(db);
    //db.listProducts();
    //db.listProducts("Tegla");
    //asd

    //ezt lehet hogy ki k�ne rakni egy f�jlba, hogy a program �jraind�t�skor ne az 1-es idre
    //pr�b�ljon mindig term�ket berakni
    
    //int productId = (db.productArraySize() + 1);

    //fileRead("users.txt");
    
    //Hurut Ferenc; 2004.05.14; Budapest Kobanyai utca 4; asd123; ab12; 2;
    //Jozsi Jozsi; 1993.11.02; Kolozsv�r Tulipan negyed R / 2; szeretemakakaot; 22er; 1;
    
   

    std::cout << "Udvozoljuk a raktar rendszerunkben, kerem valasszon a kilistazott opciok kozul:" << std::endl;
    
    
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
            std::cout << "~~Sikeres kijelentkezes~~ \n" << std::endl;

            break;
            }

            //Term�kek kilist�z�sa
            case '3': {

                std::cout << "\n";
                std::cout << "~~Lista kezdete~~\n";
                
                if (currentUser.checkType() > 0) {
                    db.listProductsInfo();
                }
                else {
                    db.listProducts();
                }

                std::cout << "~~Lista vege~~\n"; 
                std::cout << "\n";
            break;
            }

            //Term�k rendel�se
                    //BUGOS 
            case '4': {
                std::string input;
                Buyer A(currentUser.getCodeOfUser());
                while (input != "Kuldes")
                {
                    std::cout << "Adja meg a megrendelni kivant termek nevet, ha vegzett gepelje be: Kuldes\n";
                    std::cin >> input;

                    if (input != "Kuldes") {
                        if (db.searchForProduct(input) != " "){     
                        
                            A.addToBasket(db.searchForProduct(input));
                        
                        }
                    }
                    else
                    {
                        std::cout << "Nincs ilyen termek!\n";
                    }
                
                }
                std::string megye;
                std::cout << "Milyen megyebol rendel?\n";
                std::cin >> megye;
                std::cout << "~~~Kosara tartalma~~~" << std::endl;
                A.listMyBasket(); 
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                if (currentUser.getFullName() == "default")
                {

                    int defaultType = 0;

                    //linet k�ne olvasnia nem csak stringet
                    std::string fullName, pw, szuldat, cime;
                    std::cout << "On meg nincs regisztralva,regisztraljon be most.\n";
                    std::cout << "Teljes neve:\n";
                    std::cin >> fullName;
                    std::cout <<"Jelszava:\n";
                    std::cin >> pw;
                    std::cout << "Szuletesidatum (ev.ho.nap formatum)\n";
                    std::cin >> szuldat;
                    std::cout << "Cim varos, utca, hazszam\n";
                    std::cin >> cime;
                                      
                    db.addUser(fullName, szuldat, cime, pw, defaultType);
                    std::string kod = db.getCodeFromArray(fullName, szuldat);
                    if (kod != "Hiba") {
                        std::cout << "Az On belepesi azonositoja: " << kod << std::endl;
                    }
                    else {
                        std::cout << " " << std::endl;
                    }
                    
                }
 
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

                db.addProduct(name, sector, shelf, row);

            }
            else {
                std::cout << "~~Nem rendelkezik megfelelo jogokkal~~ \n" << std::endl;
            }

            break;
            }

            //Term�k t�rl�se
            case '6': {

            if (currentUser.checkType() >= 1) {

                std::string id;

                std::cout << "Adja meg a kitorlendo termek kodjat: (szam) \n";
                std::cin >> id;

                db.deleteProduct(id);

            }
            else {
                std::cout << "~~Nem rendelkezik megfelelo jogokkal~~ \n";
            }

            break;
            }

            //Felhaszn�l�k kilist�z�sa
            case '7': {

            if (currentUser.checkType() >= 2) {

                int toBeListed;

                std::cout << "\n";
                std::cout << "1. Dolgozok listazasa" << std::endl;
                std::cout << "2. Vasarlok listazasa" << std::endl;
                std::cout << "3. Osszes listazasa \n";
                std::cin >> toBeListed;
                std::cout << "\n";

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
                    std::cout << "~~Helytelen karaktert adott meg~~ \n" << std::endl;
                    break;
                }
                break;
                }

            }
            else {
                std::cout << "~~Nem rendelkezik megfelelo jogokkal~~ \n" << std::endl;
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

                while (newType < 0 || newType > 2) {
                    std::cout << "~~Egy felhasznalo tipusa csak 0, 1 vagy 2 erteku lehet~~ \n";
                    std::cin >> newType;
                }

                db.addUser(newFullName, newDateOfBirth, newAddress, newPassword, newType);
                
              
            }
            else {
                std::cout << "~~Nem rendelkezik megfelelo jogokkal~~" << std::endl;
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
                std::cout << "~~Nem rendelkezik megfelelo jogokkal~~" << std::endl;
            }
            break;
            }

        default:
            std::cout << "~~Helytelen karaktert adott meg~~" << std::endl;
            break;
        }

        //std::cout << "teszt3" << std::endl;


    }

    //ide �rd a f�jlment�st vagy mit akarsz
    db.saveProducts();
    db.saveUsers();
    return 0;
}