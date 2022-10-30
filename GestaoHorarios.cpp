//
// Created by andre on 19-10-2022.
//

#include "GestaoHorarios.h"

void GestaoHorarios::readAulas() {
    ifstream in1("../Tests/classes.csv");
    ifstream in2("../Tests/classes_per_uc.csv");
    ifstream in3("../Tests/students_classes.csv");

    if(!in1.is_open()){
        cout << "error_category";
    }

    vector<Estudante> students;

    vector<Aula> aulas;

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
        cout<< ClassCode << UcCode << Weekday << StartHour << Duration<< Type;
        float start = stof(StartHour);
        float d = stof(Duration);
        Aula aula= Aula( Weekday, start, d, Type);
        UCTurma turma= UCTurma(UcCode,ClassCode);
    }
    cout << aulas.size();
}


