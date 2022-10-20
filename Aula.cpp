//
// Created by andre on 19-10-2022.
//

#include "Aula.h"
#include <string>
using namespace std;
Aula::Aula(string classcode,string uccode,string dia, float inicio, float duracao, std::string tipo) {
    dia_=dia;
    inicio_=inicio;
    duracao_=duracao;
    tipo_=tipo;
    classcode_=classcode;
    uccode_=uccode;
}