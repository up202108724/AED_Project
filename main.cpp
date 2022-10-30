#include <iostream>
#include <sstream>
#include <fstream>
#include "Estudante.h"
#include "Aula.h"
#include <vector>

using namespace std;

void readData() {
    ifstream in1("../Tests/classes.csv");
    ifstream in2("../Tests/classes_per_uc.csv");
    ifstream in3("../Tests/students_classes.csv");

    if(!in1.is_open()){
        cout << "error_category";
    }

    vector<Estudante> students;
    vector<UCTurma> turmas;
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
        aulas.push_back(Aula(ClassCode, UcCode, Weekday,start, d, Type));
    }
    cout << aulas.size();
    getline(in2,line);
    while(getline(in2,line)){
        int i=0;
        string ClassCode,UCCode;
        istringstream iss(line);
        while (iss.good()){
            string substr;
            getline (iss,substr, ',');
            if (i==0){
                UCCode=substr;
            }
            if (i==1){
                ClassCode=substr;
            }
        i++;
        }
        turmas.push_back(UCTurma(UCCode,ClassCode));
    }

}

int main() {
    readData();
    return 0;
}
