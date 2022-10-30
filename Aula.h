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
        Aula(string dia, float inicio, float duracao, string tipo);
        string getClasscode();
        string getUCcode();
        void print();

private:
        string dia_;
        float inicio_;
        float duracao_;
        string tipo_;

};


#endif //AED_PROJECT_AULA_H
