#include "includes.h"
#include "user.h"
#include "database.h"
#include <fstream>
#include "listofproducts.h"

    
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
void readUsers(Database &B) //EZZEL A GECIVEL LEHET BETOLTENI A USER.TXT-BOL A FOSOKAT main-ben  a database db-re kell meghívni na csa megyek kocsmazni
{
    std::ifstream file;
    file.open("users.txt");
    if (!file.is_open()) std::cout << "GECIRE NEMJO XD";

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

        
    //}
}
void readProducts(Database &B)
{
    std::ifstream file;
    file.open("products.txt");
    if (!file.is_open()) std::cout << "GECIRE NEMJO XD";
   
    std::string word, nev;
    int szektor, polc, sor, ID;
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
            ID = std::stoi(word);
            tag++;
        }
        else if (tag == 5)
        {
            B.addProduct(nev,szektor,polc,sor,ID);
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
    
    //main változók
    Database db;
    char chosenChar = '0';
    User defaultUser = User("default", "2000.01.01", "defaultstreet", "123", "d3f4", 0); //ez majd 0 lesz csak teszteltem
    User currentUser = defaultUser;
    
    readUsers(db);
    //db.listAll();

    readProducts(db);
    //db.listProducts();
    //db.listProducts("Tegla");

    //ezt lehet hogy ki kéne rakni egy fájlba, hogy a program újraindításkor ne az 1-es idre
    //próbáljon mindig terméket berakni
    int productId = db.productArraySize();

    //fileRead("users.txt");
    
    //Hurut Ferenc; 2004.05.14; Budapest Kobanyai utca 4; asd123; ab12; 2;
    //Jozsi Jozsi; 1993.11.02; Kolozsvár Tulipan negyed R / 2; szeretemakakaot; 22er; 1;
    
   

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
            std::cout << "5: Termek hozzáadasa" << std::endl;
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

            //Bejelentkezés
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

            //Kijelentkezés
            case '2': {

            currentUser = defaultUser;
            std::cout << "Sikeres kijelentkezes \n" << std::endl;

            break;
            }

            //Termékek kilistázása
            case '3': {

                std::cout << "\n";
                std::cout << "Lista kezdete:\n";
                
                if (currentUser.checkType() > 0) {
                    db.listProductsInfo();
                }
                else {
                    db.listProducts();
                }

                std::cout << "Lista vege:\n";

            break;
            }

            //Termék rendelése
            case '4': {

            break;
            }

            //Termék hozzáadása
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

            //Termék törlése
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

            //Felhasználók kilistázása
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

            //Felhasználó hozzáadása
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
                    std::cout << "Egy felhasznalo tipusa csak 0, 1 vagy 2 erteku lehet \n";
                    std::cin >> newType;
                }

                db.addUser(newFullName, newDateOfBirth, newAddress, newPassword, newType);
                
              
            }
            else {
                std::cout << "Nem rendelkezik megfelelo jogokkal" << std::endl;
            }

            break;
            }

            //Felhasználó törlése
            case '9': {

            if (currentUser.checkType() >= 2) {

                std::string codeWantDeleted;

                std::cout << "Kerem adja meg a kitorlendõ kodot: \n";
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

    //ide írd a fájlmentést vagy mit akarsz
    db.saveProducts();
    db.saveUsers();
    return 0;
}