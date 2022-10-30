//
// Created by andre on 19-10-2022.
//

#include "Aula.h"
#include <string>
#include <iostream>
using namespace std;
Aula::Aula(string dia, float inicio, float duracao, string tipo) {
    dia_=dia;
    inicio_=inicio;
    duracao_=duracao;
    tipo_=tipo;

}

void Aula::print() {
    cout<< dia_ << ','<< duracao_<<',' <<tipo_;

}