//
// Created by andre on 19-10-2022.
//

#ifndef AED_PROJECT_AULA_H
#define AED_PROJECT_AULA_H

#include <string>
#include "UCTurma.h"

using namespace std;
class Aula {

    public:
        Aula(string classcode,string uccode,string dia, float inicio, float duracao, string tipo);


private:
        string dia_;
        float inicio_;
        float duracao_;
        string tipo_;
        string classcode_;
        string uccode_;
};


#endif //AED_PROJECT_AULA_H
