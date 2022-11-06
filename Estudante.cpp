//
// Created by andre on 19-10-2022.
//

#include "Estudante.h"

Estudante::Estudante(int studentcode, const string& name) {
    studentcode_=studentcode;
    name_=name;
}

int Estudante::getCode() const {
    return studentcode_;
}

string Estudante::getName() const {
    return name_;
}

void Estudante::print() const {
    cout << studentcode_ << ',' << name_ << endl;
    for (const UCTurma& turma : turmasEstudante) turma.print();
}

bool Estudante::operator==(const Estudante &aluno) const{
    if (studentcode_==aluno.getCode()) return true;
    else return false;
}

bool Estudante::operator==(int x) const {
    return studentcode_==x;
}

bool Estudante::operator<(const Estudante &aluno) const{
    return name_<aluno.getName();
}

void Estudante::adicionarTurma(const UCTurma &turma){
    turmasEstudante.push_back(turma);
}
vector<UCTurma> Estudante::getturmasEstudante() {
    return turmasEstudante;
}

void Estudante::removerTurma(const string& uc){
    removerUC(uc);
    turmasEstudante.emplace_back(UCTurma(uc,"N/A"));
}

void Estudante::removerUC(const string& uc) {
    auto itr = turmasEstudante.begin();
    for (const UCTurma& t : turmasEstudante){
        if (uc==t.getUC()) turmasEstudante.erase(itr);
        itr++;
    }
}
int Estudante::getnumUC_() const {
    return turmasEstudante.size();
}