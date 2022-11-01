//
// Created by andre on 19-10-2022.
//

#include "GestaoHorarios.h"
#include<algorithm>
GestaoHorarios::GestaoHorarios() {
    readAulas();
    readEstudantes();
    readCodes();
}

void GestaoHorarios::readEstudantes(){
    ifstream in("../Tests/students_classes.csv");
    int i=0;
    string line;
    getline(in,line);
    while (getline(in,line)){
        string StudentCode,StudentName,UcCode,ClassCode;
        istringstream iss(line);
        while(iss.good()){
            string substr;
            getline(iss,substr, ',');
            if (i==0){
                StudentCode=substr;
            }
            if (i==1){
                StudentName=substr;
            }
            if (i==2){
                UcCode=substr;
            }
            if (i==3){
                ClassCode=substr;
            }
            i++;
        }
        i=0;
        int StudentCodeInt= stoi(StudentCode);
        UCTurma turma= UCTurma(UcCode,ClassCode);
        Estudante estudante= Estudante(StudentCodeInt, StudentName);
        for (Estudante c : estudantes){
            if (c==estudante){
                c.adicionarTurma(turma);
                break;
            }
            else if (c==estudantes.back()){
                estudantes.push_back(estudante);
                estudantes.back().adicionarTurma(turma);
                break;
            }
        }
        if (estudantes.empty()){
            estudantes.push_back(estudante);          
            estudantes.back().adicionarTurma(turma);
        }
    }
}

void GestaoHorarios::readAulas() {
    ifstream in1("../Tests/classes.csv");
    string line;
    getline(in1, line);
    int i=0;
    while (getline(in1, line)) {
        string ClassCode, UcCode, Weekday, StartHour, Duration, Type;
        istringstream iss(line);
        while (iss.good()) {
            string substr;
            getline(iss, substr, ',');
            if (i==0){
                ClassCode=substr;
            }
            if (i==1){
                UcCode=substr;
            }
            if (i==2){
                Weekday=substr;
            }
            if (i==3){
                StartHour=substr;
            }
            if (i==4){
                Duration=substr;
            }
            if (i==5){
                Type=substr;
            }
            i++;
        }
        i=0;
        float start = stof(StartHour);
        float d = stof(Duration);
        Aula aula= Aula(Weekday, start, d, Type);
        UCTurma turma = UCTurma(UcCode, ClassCode);
        for (UCTurma c : horario){
            if (c==turma){
                c.adicionarAula(aula);
                break;
            }
            else if (c==horario.back()){
                horario.push_back(turma);
                horario.back().adicionarAula(aula);
                break;
            }
        }
        if (horario.empty()){
            horario.push_back(turma);
            horario.back().adicionarAula(aula);
        }
    }
}
void GestaoHorarios::readCodes() {
    ifstream in1("../Tests/classes_per_uc.csv");
    string line;
    getline(in1, line);
    int i=0;
    while (getline(in1, line)) {
        string Uccode;
        Uccode = line.substr(0,line.find_first_of(",",0));
        for (string c: codes){
            if (Uccode==c){
                break;
            }
            if (c==codes.back()) {
                codes.push_back(Uccode);
                break;
            }
        }
        if (codes.empty()){
            codes.push_back(Uccode);
        }
        /*if( find(codes.begin(), codes.end(), Uccode) == codes.end() ){
            codes.push_back(Uccode);
        }*/
    }
}
vector<Estudante> GestaoHorarios::getEstudantes() const {
    return estudantes;
}

vector<UCTurma> GestaoHorarios::getUCTurmas() const {
    return horario;
}
vector<string> GestaoHorarios::getCodes() const{
    return codes;
}

vector<string> GestaoHorarios::getTurmas() const {
    return turmas;
}
void GestaoHorarios::readTurmas() {
    ifstream in1("../Tests/classes_per_uc.csv");
    string line;
    getline(in1, line);

    while (getline(in1, line)) {
        string turma;
        turma = line.substr(line.find_first_of(",")+1,line.length()-1);
        for (string t: turmas){
            if (turma==t){
                break;
            }
            if (t==turmas.back()) {
                turmas.push_back(turma);
                break;
            }
        }
        if (turmas.empty()){
            turmas.push_back(turma);
        }

    }

}