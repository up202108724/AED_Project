#include <iostream>
#include <sstream>
#include <fstream>
#include "Estudante.h"
#include "Aula.h"
#include "GestaoHorarios.h"
#include "UCTurma.h"
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;
bool sortEstudantesNome(const Estudante &Estudante1, const Estudante &Estudante2 ){
    if(Estudante1.getName()< Estudante2.getName()){
        return true;
    }
    return false;
}
void Option1(GestaoHorarios gestor, string code){
    vector <Estudante> Estudantes;
    for (Estudante a: gestor.getEstudantes()){
        for (UCTurma turma: a.getturmasEstudante()){
            if (turma.getUC()==code){
                Estudantes.push_back(a);
            } else{ continue;}
        }
    }
    sort(Estudantes.begin(),Estudantes.end(), sortEstudantesNome);
    for (Estudante a: Estudantes){
        cout << a.getCode() << ',' << a.getName() << endl;
    }

}
int main() {
    bool flag=true;
    while(flag) {
        GestaoHorarios gestor = GestaoHorarios();

        int selection = 0;
        cout << "Gestor de Horários de Estudantes L.EIC" << endl;
        cout << "1 - Ver estudantes de uma cadeira" << endl;
        cout << "2 - Ver estudantes inscritos em n UCs" << endl;
        cout << "Selecione uma opção: ";

        cin >> selection;
        if (selection == 1) {
            string code;
            cout << "Insira o código da UC: ";
            cin >> code;
            if(find(gestor.getCodes().begin(), gestor.getCodes().end(), code) == gestor.getCodes().end()&& ) {
                cout << "Opção inválida!" << endl;
                while (!(cin >> code) or find(gestor.getCodes().begin(), gestor.getCodes().end(), code) == gestor.getCodes().end()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << endl << "Insira o código da UC: ";
                    cin >> code;

                }
            }
            Option1(gestor, code);

        }
        if (selection=='q'){
            flag=false;
        }
        while (!(cin >> selection) or selection > 9 or selection < 0) {
            cout << "Opção inválida!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Selecione uma opção: ";
        }

//    for (UCTurma c : gestor.getUCTurmas()) c.print();           // test
//    for (Estudante c: gestor.getEstudantes()) c.print();        // test
    }
    return 0;
}