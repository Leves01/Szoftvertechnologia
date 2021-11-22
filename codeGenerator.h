#ifndef __CODEGENERATOR_H__
#define __CODEGENERATOR_H__

#include "includes.h"

class CodeGenerator {

    private: 
        char alphaNums[35] = {  'a', 'b', 'c', 'd', 'e', 'f', 'g',
                            'h', 'i', 'j', 'k', 'l', 'm', 'n',
                            'o', 'p', 'q', 'r', 's', 't', 'u',
                            'v', 'w', 'x', 'y', 'z', 
                            '1', '2', '3', '4', '5', '6', '7', 
                            '8', '9',                           };

        string code = "";

    public:
        string generateCode(int lenght);
};


#endif // __CODEGENERATOR_H__