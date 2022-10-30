//
// Created by andre on 19-10-2022.
//
#ifndef AED_PROJECT_ESTUDANTE_H
#define AED_PROJECT_ESTUDANTE_H

#include <string>
#include <vector>
#include "UCTurma.h"

class Estudante {
public:
    Estudante(int studentcode, string name);
    int getCode() const;
    string getName() const;
    void print() const;




private:
    int studentcode_;
    string name_;
    vector<UCTurma> turmas;

};


#endif //AED_PROJECT_ESTUDANTE_H
