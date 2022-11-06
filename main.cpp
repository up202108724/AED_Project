#include "GestaoHorarios.h"
using namespace std;
bool ordenarporUCDescendente(const Estudante& a, const Estudante& b) {return a.getnumUC_()>b.getnumUC_();}
bool ordenarporUCAscendente(const Estudante& a, const Estudante& b) {return a.getnumUC_()<b.getnumUC_();}
bool codigoDescendente(const Estudante& a, const Estudante& b) {return a.getCode()>b.getCode();}
bool codigoAscendente(const Estudante& a, const Estudante& b) {return a.getCode()<b.getCode();}
bool nomeDescendente(const Estudante& a, const Estudante& b) {return a.getName()>b.getName();}
bool nomeAscendente(const Estudante& a, const Estudante& b) {return a.getName()<b.getName();}
bool ucDescendente(const string& a, const string& b) {return a>b;}
bool ucAscendente(const string& a, const string& b) {return a<b;}

void mini2(const GestaoHorarios& gestor, const string& turma, const string& code){
    int size = 0;
    for (Estudante a: gestor.getEstudantes()){
        for (const UCTurma& turmas: a.getturmasEstudante()){
            if (turmas.getUC()==code && turmas.getClassCode()==turma) size++;
        }
    }
    cout << " : " << size << " alunos" << endl;
}
void option1(const GestaoHorarios& gestor){
    vector<string > ucsprocessadas;
    for (const UCTurma& uc : gestor.getUCTurmas()){
        if (find(ucsprocessadas.begin(),ucsprocessadas.end(),uc.getUC()) == ucsprocessadas.end()){
            cout << uc.getUC() << endl;
            ucsprocessadas.push_back(uc.getUC());
        }
        else continue;
        for(const UCTurma& turma : gestor.getUCTurmas()){
            if (turma.getUC()==uc.getUC()) {
                cout << "*\t" << turma.getClassCode();
                mini2(gestor,turma.getClassCode(),turma.getUC());
            }
        }
    }
}

void Option2(const GestaoHorarios& gestor, const string& code, int sort_){
    vector <Estudante> StudentsUC;
    for (Estudante a: gestor.getEstudantes()){
        for (const UCTurma& turma: a.getturmasEstudante()){
            if (turma.getUC()==code) StudentsUC.push_back(a);
        }
    }
    if (sort_==1) sort(StudentsUC.begin(),StudentsUC.end(), codigoDescendente);
    else if (sort_==2) sort(StudentsUC.begin(),StudentsUC.end(), codigoAscendente);
    else if (sort_==3) sort(StudentsUC.begin(),StudentsUC.end(), nomeDescendente);
    else if (sort_==4) sort(StudentsUC.begin(),StudentsUC.end(), nomeAscendente);
    for (const Estudante& a: StudentsUC){
        cout << a.getCode() << ',' << a.getName() << endl;
    }
    cout << "Estão inscritos " << StudentsUC.size() << " alunos nesta disciplina.";
}
void Option3(const GestaoHorarios& gestor, const string& turma, const string& code, int sort_){
    vector<Estudante> StudentsTurma;
    for (Estudante a: gestor.getEstudantes()){
        for (const UCTurma& turmas: a.getturmasEstudante()){
            if (turmas.getUC()==code && turmas.getClassCode()==turma) StudentsTurma.push_back(a);
        }
    }
    if (sort_==1) sort(StudentsTurma.begin(),StudentsTurma.end(), codigoDescendente);
    else if (sort_==2) sort(StudentsTurma.begin(),StudentsTurma.end(), codigoAscendente);
    else if (sort_==3) sort(StudentsTurma.begin(),StudentsTurma.end(), nomeDescendente);
    else if (sort_==4) sort(StudentsTurma.begin(),StudentsTurma.end(), nomeAscendente);
    for (const Estudante& a: StudentsTurma){
        cout << a.getCode() << ',' << a.getName() << endl;
    }
    if (StudentsTurma.empty()) cout << "Nenhum estudante está inscrito na turma " << turma << " da UC " << code << "." << endl;
    else cout << "Estão inscritos " << StudentsTurma.size() << " alunos na turma " << turma << " da UC " << code << "." << endl;
}
void Option4(const GestaoHorarios& gestor, string ano, int sort_){
    vector<Estudante> estudantes;
    if (ano=="3"){
        for (Estudante a: gestor.getEstudantes()){
            for(const UCTurma& turma: a.getturmasEstudante()){
                if (turma.getClassCode().at(0)==ano.at(0)){
                    estudantes.push_back(a);
                    break;
                }
            }
        }
    }
    if (ano=="2"){
        for (Estudante a: gestor.getEstudantes()){
            for(const UCTurma& turma: a.getturmasEstudante()){
                if (turma.getClassCode().at(0)==ano.at(0)){
                    estudantes.push_back(a);
                    break;
                }
            }
        }
    }
    if (ano=="1"){
        for (Estudante a: gestor.getEstudantes()){
            for(const UCTurma& turma: a.getturmasEstudante()){
                if (turma.getClassCode().at(0)==ano.at(0)){
                    estudantes.push_back(a);
                    break;
                }
            }
        }
    }
    if (sort_==1) sort(estudantes.begin(),estudantes.end(), codigoDescendente);
    else if (sort_==2) sort(estudantes.begin(),estudantes.end(), codigoAscendente);
    else if (sort_==3) sort(estudantes.begin(),estudantes.end(), nomeDescendente);
    else if (sort_==4) sort(estudantes.begin(),estudantes.end(), nomeAscendente);
    for (const Estudante& e: estudantes){
        cout << e.getCode() << ", " << e.getName() << endl;
    }
    if (estudantes.empty()) cout << "Nenhum aluno está inscrito em cadeiras do " << ano << "º ano letivo.";
    else cout << "Estão inscritos " << estudantes.size() << " alunos em cadeiras do " << ano << "º ano letivo.";
}
void Option5(const GestaoHorarios& gestor, int n, int sort_){
    vector<Estudante> totalEstudantes;
    for (Estudante estudante: gestor.getEstudantes()){
        if(estudante.getturmasEstudante().size()>n) totalEstudantes.push_back(estudante);
    }
    if (sort_==1) sort(totalEstudantes.begin(),totalEstudantes.end(), codigoDescendente);
    else if (sort_==2) sort(totalEstudantes.begin(),totalEstudantes.end(), codigoAscendente);
    else if (sort_==3) sort(totalEstudantes.begin(),totalEstudantes.end(), nomeDescendente);
    else if (sort_==4) sort(totalEstudantes.begin(),totalEstudantes.end(), nomeAscendente);
    else if (sort_==5) sort(totalEstudantes.begin(),totalEstudantes.end(), ordenarporUCDescendente);
    else if (sort_==6) sort(totalEstudantes.begin(),totalEstudantes.end(), ordenarporUCAscendente);
    for(Estudante student: totalEstudantes){
        cout << student.getCode() << "," << student.getName() << " : " << student.getturmasEstudante().size()<< " UCs" << endl;
    }
}
void Option6(const GestaoHorarios& gestor, int code) {
    vector<Estudante> estudantes = gestor.getEstudantes();
    vector<UCTurma> bigturmas = gestor.getUCTurmas();
    vector<UCTurma> turmas = find(estudantes.begin(),estudantes.end(),code)->getturmasEstudante();
    vector<Aula> horario;
    for (const UCTurma& t: turmas) {
        if (t.getClassCode()=="N/A") continue;
        for (const Aula& a: find(bigturmas.begin(),bigturmas.end(),t)->getHorarioUCTurma()) horario.push_back(a);
    }
    sort(horario.begin(), horario.end());
    int counter = 0;
    while (counter!=7){
        if (counter==0) cout << "Monday:" << endl;
        else if (counter==1) cout << "Tuesday:" << endl;
        else if (counter==2) cout << "Wednesday:" << endl;
        else if (counter==3) cout << "Thursday:" << endl;
        else if (counter==4) cout << "Friday:" << endl;
        else if (counter==5) cout << "Sunday:" << endl;
        else if (counter==6) cout << "Saturday:" << endl;

        for(Aula a: horario){
            if (a.getDay()=="Monday" && counter==0) a.print();
            else if (a.getDay()=="Tuesday" && counter==1) a.print();
            else if (a.getDay()=="Wednesday" && counter==2) a.print();
            else if (a.getDay()=="Thursday" && counter==3) a.print();
            else if (a.getDay()=="Friday" && counter==4) a.print();
            else if (a.getDay()=="Saturday" && counter==5) a.print();
            else if (a.getDay()=="Sunday" && counter==6) a.print();
        }
        counter++;
    }
}

int main() {
    GestaoHorarios gestor = GestaoHorarios();
    int quit;
    int sort;
    while(true) {
        cout << endl << "Gestor de Horários de Estudantes L.EIC" << endl;
        cout << "Digite 0 a qualquer momento para fechar o programa" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "1 - Ver todas as turmas da L.EIC" << endl;
        cout << "2 - Ver estudantes de uma cadeira" << endl;
        cout << "3 - Ver estudantes de uma turma" << endl;
        cout << "4 - Ver estudantes de um ano letivo" << endl;
        cout << "5 - Ver estudantes com mais de n UCs" << endl;
        cout << "6 - Ver horário de um estudante" << endl;
        cout << "7 - Adicionar pedidos" << endl;
        cout << "8 - Ver fila de pedidos" << endl;
        cout << "9 - Processar pedidos em fila" << endl;
        cout << "0 - Sair do programa" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "Selecione uma opção: ";
        int selection = 0;
        while (!(cin >> selection) or selection > 9 or selection < 0) {
            cout << "Opção inválida!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Selecione uma opção: ";
        }
        if (selection==0) break;
        if (selection==1){
            option1(gestor);
            cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            while (!(cin >> quit) or (quit != 0 and quit != 1)) {
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            }
            if (quit==0) break;
        }
        if (selection == 2) {
            string code;
            vector<string> codigos = gestor.getCodes();
            cout << "Insira o código da UC: ";
            while (cin>>code and find(codigos.begin(), codigos.end(), code) == codigos.end()) {
                if (code=="0") break;
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Insira o código da UC: ";
            }
            if (code=="0") break;
            cout << "---------------------------------------------------------" << endl;
            cout << "1 - Ordenar por código de estudante descendente" << endl;
            cout << "2 - Ordenar por código de estudante ascendente" << endl;
            cout << "3 - Ordenar por nome de estudante descendente" << endl;
            cout << "4 - Ordenar por nome de estudante ascendente" << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << "Escolha uma opção de ordenação: ";
            while (!(cin>>sort) or sort<0 or sort>4){
                if (sort==0) break;
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Escolha uma opção de ordenação: ";
            }
            if (sort==0) break;
            Option2(gestor, code, sort);
            cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            while (!(cin >> quit) or (quit != 0 and quit != 1)) {
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            }
            if (quit==0) break;
        }
        if (selection == 3){
            string code;
            string turma;
            vector<string> codigos = gestor.getCodes();
            vector<string> turmas = gestor.getTurmas();
            cout << "Insira o código da UC: ";
            while (cin>>code and find(codigos.begin(), codigos.end(), code) == codigos.end()) {
                if (code=="0") break;
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Insira o código da UC: ";
            }
            if (code=="0") break;
            cout << "Insira a turma: ";
            while (cin>>turma and find(turmas.begin(), turmas.end(), turma) == turmas.end()) {
                if (turma=="0") break;
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Insira a turma: ";
            }
            if (turma=="0") break;
            cout << "---------------------------------------------------------" << endl;
            cout << "1 - Ordenar por código de estudante descendente" << endl;
            cout << "2 - Ordenar por código de estudante ascendente" << endl;
            cout << "3 - Ordenar por nome de estudante descendente" << endl;
            cout << "4 - Ordenar por nome de estudante ascendente" << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << "Escolha uma opção de ordenação: ";
            while (!(cin>>sort) or sort<0 or sort>4){
                if (sort==0) break;
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Escolha uma opção de ordenação: ";
            }
            if (sort==0) break;
            Option3(gestor,turma,code,sort);
            cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            while (!(cin >> quit) or (quit != 0 and quit != 1)) {
                cout << "Opção inválida!" << endl;
                cin.clear();while(!gestor.getPedidos().empty()) gestor.processarPedido();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            }
            if (quit==0) break;
        }
        if (selection==4){
            string year;
            cout << "Insira o ano letivo: ";
            while(!(cin>>year) or (year!="1" and year!="2" and year!="3")){
                if (year=="0") break;
                cout << "Opção inválida!" << endl;
                cin.clear();
                cout << endl << "Insira o ano letivo: ";
            }
            if (year=="0") break;
            cout << "---------------------------------------------------------" << endl;
            cout << "1 - Ordenar por código de estudante descendente" << endl;
            cout << "2 - Ordenar por código de estudante ascendente" << endl;
            cout << "3 - Ordenar por nome de estudante descendente" << endl;
            cout << "4 - Ordenar por nome de estudante ascendente" << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << "Escolha uma opção de ordenação: ";
            while (!(cin>>sort) or sort<0 or sort>4){
                if (sort==0) break;
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Escolha uma opção de ordenação: ";
            }
            if (sort==0) break;
            Option4(gestor, year, sort);
            cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            while (!(cin >> quit) or (quit != 0 and quit != 1)) {
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            }
            if (quit==0) break;
        }
        if (selection==5){
            int min;
            cout << "Insira o número de UCs mínimo: ";
            while(!(cin>>min) or min<0){
                if (min==0) break;
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Insira o número de UCs mínimo: ";
            }
            if (min==0) break;
            cout << "---------------------------------------------------------" << endl;
            cout << "1 - Ordenar por código de estudante descendente" << endl;
            cout << "2 - Ordenar por código de estudante ascendente" << endl;
            cout << "3 - Ordenar por nome de estudante descendente" << endl;
            cout << "4 - Ordenar por nome de estudante ascendente" << endl;
            cout << "5 - Ordenar por nº descendente de UC's inscritas" << endl;
            cout << "6 - Ordenar por nº ascendente de UC's inscritas" << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << "Escolha uma opção de ordenação: ";
            while (!(cin>>sort) or sort<0 or sort>6){
                if (sort==0) break;
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Escolha uma opção de ordenação: ";
            }
            if (sort==0) break;
            Option5(gestor, min, sort);
            cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            while (!(cin >> quit) or (quit != 0 and quit != 1)) {
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            }
            if (quit==0) break;
        }
        if (selection==6){
            int code;
            cout << "Insira o código mecanógrafico do estudante: ";
            vector<string> Turmas= gestor.getTurmas();
            vector<Estudante> estudantes = gestor.getEstudantes();
            while (!(cin>>code) or find(estudantes.begin(), estudantes.end(), code) == estudantes.end()) {
                if (code==0) break;
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Insira o código mecanógrafico do estudante: ";
            }
            if (code==0) break;
            Option6(gestor,code);
            cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            while (!(cin >> quit) or (quit != 0 and quit != 1)) {
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            }
            if (quit==0) break;
        }
        if (selection==7){
            cout << endl << "---------------------------------------------------------" << endl;
            cout << "1 - Adicionar aluno a uma turma" << endl;
            cout << "2 - Remover aluno de uma turma" << endl;
            cout << "3 - Adicionar aluno a uma UC" << endl;
            cout << "4 - Remover aluno de uma UC" << endl;
            cout << "5 - Alterar turma de um estudante" << endl;
            cout << "---------------------------------------------------------" << endl;
            int choice = 0;
            cout << "Selecione uma opção: ";
            while (!(cin >> choice) or choice > 5 or choice < 0) {
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Selecione uma opção: ";
            }
            if (choice==0) break;
            if (choice==1){
                int code;
                string uccode;
                string turma;
                cout << "Insira o código mecanógrafico do estudante: ";
                vector<string> turmas= gestor.getTurmas();
                vector<Estudante> estudantes = gestor.getEstudantes();
                vector<string> codigos = gestor.getCodes();
                while (!(cin>>code) or code<0) {
                    cout << "Opção inválida!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << endl << "Insira o código mecanógrafico do estudante: ";
                }
                cout << "Insira o código da UC: ";
                while (!(cin>>uccode)) {
                    if (uccode=="0") break;
                    cout << "Opção inválida!" << endl;
                    cin.clear();
                    cout << endl << "Insira o código da UC: ";
                }
                if (uccode=="0") break;
                cout << "Insira a turma destino: ";
                while (!(cin >> turma)) {
                    if (turma == "0") break;
                    cout << "Opção inválida!" << endl;
                    cin.clear();
                    cout << endl << "Insira a turma destino: ";
                }
                if (turma=="0") break;
                gestor.addPedido(Pedido(code,uccode,"null",uccode,turma,"addClass"));
            }
            if (choice==2){
                int code;
                string uccode;
                cout << "Insira o código mecanógrafico do estudante: ";
                vector<Estudante> estudantes = gestor.getEstudantes();
                vector<string> codigos = gestor.getCodes();
                while (!(cin>>code)) {
                    if (code==0) break;
                    cout << "Opção inválida!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << endl << "Insira o código mecanógrafico do estudante: ";
                }
                if (code==0) break;
                cout << "Insira o código da UC: ";
                while (!(cin>>uccode)) {
                    if (uccode=="0") break;
                    cout << "Opção inválida!" << endl;
                    cin.clear();
                    cout << endl << "Insira o código da UC: ";
                }
                if (uccode=="0") break;
                gestor.addPedido(Pedido(code,uccode,"null",uccode,"null","removeClass"));
            }
            if (choice==3){
                int code;
                string uccode;
                cout << "Insira o código mecanógrafico do estudante: ";
                vector<Estudante> estudantes = gestor.getEstudantes();
                vector<string> codigos = gestor.getCodes();
                while (!(cin>>code)) {
                    if (code==0) break;
                    cout << "Opção inválida!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << endl << "Insira o código mecanógrafico do estudante: ";
                }
                if (code==0) break;
                cout << "Insira o código da UC: ";
                while (!(cin>>uccode)) {
                    if (uccode=="0") break;
                    cout << "Opção inválida!" << endl;
                    cin.clear();
                    cout << endl << "Insira o código da UC: ";
                }
                if (uccode=="0") break;
                gestor.addPedido(Pedido(code,"null","null",uccode,"null","addUC"));
            }
            if (choice==4){
                int code;
                string uccode;
                cout << "Insira o código mecanógrafico do estudante: ";
                vector<Estudante> estudantes = gestor.getEstudantes();
                vector<string> codigos = gestor.getCodes();
                while (!(cin>>code)) {
                    if (code==0) break;
                    cout << "Opção inválida!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << endl << "Insira o código mecanógrafico do estudante: ";
                }
                if (code==0) break;
                cout << "Insira o código da UC: ";
                while (!(cin>>uccode)) {
                    if (uccode=="0") break;
                    cout << "Opção inválida!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << endl << "Insira o código da UC: ";
                }
                if (uccode=="0") break;
                gestor.addPedido(Pedido(code,uccode,"null","null","null","removeUC"));
            }
            if (choice==5){
                int code;
                string uccode;
                string turma;
                cout << "Insira o código mecanógrafico do estudante: ";
                vector<string> turmas= gestor.getTurmas();
                vector<Estudante> estudantes = gestor.getEstudantes();
                vector<string> codigos = gestor.getCodes();
                while (!(cin>>code)) {
                    if (code==0) break;
                    cout << "Opção inválida!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << endl << "Insira o código mecanógrafico do estudante: ";
                }
                if (code==0) break;
                cout << "Insira o código da UC: ";
                while (!(cin>>uccode)) {
                    if (uccode=="0") break;
                    cout << "Opção inválida!" << endl;
                    cin.clear();
                    cout << endl << "Insira o código da UC: ";
                }
                if (uccode=="0") break;
                cout << "Insira a turma destino: ";
                while (!(cin >> turma)) {
                    if (turma == "0") break;
                    cout << "Opção inválida!" << endl;
                    cin.clear();
                    cout << endl << "Insira a turma destino: ";
                }
                if (turma=="0") break;
                gestor.addPedido(Pedido(code,uccode,"null",uccode,turma,"changeClass"));
            }
            cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            while (!(cin >> quit) or (quit != 0 and quit != 1)) {
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            }
            if (quit==0) break;
        }
        if (selection==8){
            queue<Pedido> temp = gestor.getPedidos();
            cout << endl << "Pedidos em fila:" << endl;
            while(!temp.empty()){
                temp.front().print();
                cout << endl;
                temp.pop();
            }
            cout << endl << "Pedidos satisfeitos:" << endl;
            for (const Pedido& c : gestor.getSuccessos()){
                c.print();
                cout << endl;
            }
            cout << endl << "Pedidos não satisfeitos:" << endl;
            for (const Pedido& c : gestor.getFails()){
                c.print();
                cout << endl;
            }
            cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            while (!(cin >> quit) or (quit != 0 and quit != 1)) {
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            }
            if (quit==0) break;
        }
        if (selection==9){
            if (gestor.getPedidos().empty()) cout << "Não existem pedidos em fila para processar!" << endl;
            else {
                while (!gestor.getPedidos().empty()) gestor.processarPedido();
                gestor.output();
                gestor.outputFails();
                gestor.outputSucessos();
            }
            cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            while (!(cin >> quit) or (quit != 0 and quit != 1)) {
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            }
            if (quit==0) break;
        }
    }
    return 0;
}