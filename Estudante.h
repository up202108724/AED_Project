//
// Created by andre on 19-10-2022.
//

#ifndef AED_PROJECT_ESTUDANTE_H
#define AED_PROJECT_ESTUDANTE_H


#include "UCTurma.h"

class Estudante {
    public:
            Estudante(int studentcode, int name, UCTurma h ){studentcode_=studentcode;name_=name; h_=h;}




    private:
            int studentcode_;
            int name_;
            UCTurma h_;
};


#endif //AED_PROJECT_ESTUDANTE_H
