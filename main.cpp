#include <iostream>
#include <sstream>
#include <fstream>
#include "Estudante.h"
#include "Aula.h"
#include <vector>

using namespace std;

void readData() {
    ifstream in1("classes.csv");
    ifstream in2("classes_per_uc.csv");
    ifstream in3("students_classes.csv");

    vector<Estudante> students;
    vector<UCTurma> ucs;
    vector<UCTurma> turmas;
    vector<Aula> aulas;

    string line;
    getline(in1, line);

    while (getline(in1, line)) {
        string ClassCode, UcCode, Weekday, StartHour, Duration, Type;
        float start, d;
        istringstream iss(line);
        iss >>ClassCode  >> UcCode >> Weekday >> StartHour;
        istringstream ss (StartHour);
        ss >> start;
        getline(iss, Duration, ',');
        ss.str(Duration);
        ss >> d;

        aulas.push_back(Aula(ClassCode, UcCode, Weekday,start, d, Type));
    }
}

int main() {
    readData();
    return 0;
}
