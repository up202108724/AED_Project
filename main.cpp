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
    vector <Estudante> StudentsUC;
    for (Estudante a: gestor.getEstudantes()){
        for (UCTurma turma: a.getturmasEstudante()){
            if (turma.getUC()==code){
                StudentsUC.push_back(a);
            }
        }
    }
    sort(StudentsUC.begin(),StudentsUC.end(), sortEstudantesNome);
    for (Estudante a: StudentsUC){
        cout << a.getCode() << ',' << a.getName() << endl;
    }

}
void Option2(GestaoHorarios gestor, string turma){
    vector <Estudante> StudentsUC;
    for (Estudante a: gestor.getEstudantes()){
        for (UCTurma turmas: a.getturmasEstudante()){
            if (turmas.getClassCode()==turma){
                StudentsUC.push_back(a);
            }
        }
    }
    sort(StudentsUC.begin(),StudentsUC.end(), sortEstudantesNome);
    for (Estudante a: StudentsUC){
        cout << a.getCode() << ',' << a.getName() << endl;
    }
}
int main() {
    bool flag=true;
    GestaoHorarios gestor = GestaoHorarios();
    for (string c: gestor.getCodes()) {
        cout << c << endl;
    }        // test
    while(flag) {
        cout << "Gestor de Horários de Estudantes L.EIC" << endl;
        cout << "1 - Ver estudantes de uma cadeira" << endl;
        cout << "2 - Ver estudantes inscritos em n UCs" << endl;
        cout << "Selecione uma opção: ";
        int selection = 0;

        cin >> selection;
        if (selection == 1) {
            string code;
            cout << "Insira o código da UC: ";
            cin >> code;

            while (!(cin >> code) or find(gestor.getCodes().begin(), gestor.getCodes().end(), code) == gestor.getCodes().end()) {
                    cout << "Opção inválida!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << endl << "Insira o código da UC: ";
                    cin >> code;

            }

            Option1(gestor, code);

        }
        if (selection == 2){
            string turma;
            cout << "Insira o nome da Turma: ";
            cin >> turma;
            if(find(gestor.getTurmas().begin(), gestor.getTurmas().end(), turma) == gestor.getCodes().end()){
                cout << "Opção inválida!"<< endl;

            }
            Option2(gestor,turma);
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