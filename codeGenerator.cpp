#include "codeGenerator.h"

string CodeGenerator::generateCode(int lenght) 
{
    for(int i = 0; i < lenght; i++) {
        code = code + alphaNums[rand() % 35];
    }

    return code;
}

//mainbe valami ilyesmi
// int main()
// {
//    srand(time(NULL));
//    int n = 10;
//    cout << printRandomString(n);
//    return 0;
// }