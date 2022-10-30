//
// Created by andre on 19-10-2022.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include "Estudante.h"
#include "Aula.h"
#include <vector>
#ifndef AED_PROJECT_GESTAOHORARIOS_H
#define AED_PROJECT_GESTAOHORARIOS_H


class GestaoHorarios {
public:
    void readAulas();
    void readTurmas();


private:
    vector<Aula> aulas;
    vector<UCTurma> turmas;
};


#endif //AED_PROJECT_GESTAOHORARIOS_H
