//
// Created by andre on 19-10-2022.
//
/**
 * @brief Class que exprime os métodos necessários para encontrar e gerir horários
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <limits>
#include "Estudante.h"
#include "Aula.h"
#include "Pedido.h"
#ifndef AED_PROJECT_GESTAOHORARIOS_H
#define AED_PROJECT_GESTAOHORARIOS_H


class GestaoHorarios {
public:
    /**
     * @brief Um construtor default que invoca todos os métodos do tipo Read quando chamado
     * @brief Complexidade-O (6n²)
     */
    GestaoHorarios();
    /**
     * @brief A partir de um ficheiro escolhido( Classes.csv), armazena todas as aulas possíveis no curso de L.EIC, bem como organiza as suas caractísticas
     * @brief Complexidade-O (2n²)
     */
    void readAulas();
    /**
    * @brief A partir de um ficheiro escolhido( students_classes.csv), armazena todas os estudantes inscritos no curso de L.EIC, e armazena em cada estudante todas as turmas em que está inscrito.
    * @brief Complexidade-O (2n²)
    */
    void readEstudantes();
    /**
    * @brief Abre e imprime num ficheiro a lista de todos os pedidos mal-sucedidos, após estes tiverem sido processados
    * @brief Complexidade- O(n)
    */
    void outputFails()const;
    /**
     * @brief Obtêm a lista de todos os estudantes inscritos no curso de L.EIC
     * @brief Complexidade- O(1)
     * @return estudantes
     */
    vector<Estudante> getEstudantes() const;
    /**
     * @brief Obtêm a lista de todas as Turmas e cadeiras respetivas no curso
     * @brief Complexidade- O(1)
     * @return horario
     */
    vector<UCTurma> getUCTurmas() const;
    /**
     * @brief Obtêm a lista dos códigos de todas as cadeiras do curso
     * @brief Complexidade- O(1)
     * @return codes
     */
    vector<string> getCodes() const;
    /**
    * @brief Obtêm a lista de todas as turmas existentes do curso de L.EIC
    * @brief Complexidade- O(1)
    * @return turmas
    */
    vector<string> getTurmas() const;
    /**
    * @brief Obtêm a fila de todos os pedidos feitos por estudantes do curso de L.EIC
    * @brief Complexidade- O(1)
    * @return pedidos
    */
    queue<Pedido> getPedidos() const;
    /**
    * @brief De todos os pedidos realizados por estudantes do curso de L.EIC, obtêm o conjunto de todos os qeu foram concedidos
    * @brief Complexidade- O(1)
    * @return sucesso
    */
    vector<Pedido> getSuccessos() const {return sucesso;};
    /**
    * @brief De todos os pedidos realizados por estudantes do curso de L.EIC, obtêm o conjunto de todos os que falharam
    * @brief Complexidade- O(1)
    * @return fail
    */
    vector<Pedido> getFails() const {return fail;};
    /**
    * @brief Abre e imprime num ficheiro a lista de todos os pedidos que tiveram sucesso, após estes tiverem sido processados
    * @brief Complexidade- O(n)
    */
    void outputSucessos() const;

    /**
    * @brief A partir de um ficheiro escolhido( students_classes.csv), armazena todas os códigos de todas as cadeiras existentes no curso de L.EIC
    * Complexidade- O(n²)
    */
    void readCodes();
    /**
    * @brief A partir de um ficheiro escolhido( students_classes.csv), armazena todas os códigos de todas as turmas existentes no curso de L.EIC.
    *  Complexidade- O(n²)
    */
    void readTurmas();

    /**
    * @brief Adiciona um pedido x feito por um estudante
    * @brief Complexidade- O(1)
    * @param x
    */
    void addPedido(const Pedido& x);
    /**
    * @brief Processa sucessivamente todos os pedidos feitos até esta chamada, separando em vetores os pedidos que tiveram sucesso, e os que falharam
    * @brief Complexidade- O(n²)
    * @param x
    */
    void processarPedido();
    /**
     * @brief Replica uma listagem de todos os estudantes, com todas as suas turmas correspondentes
     * @brief Complexidade- O(1)
     */
    void output() const;


private:
    vector<Estudante> estudantes;/*! Conjunto de estudantes */
    vector<UCTurma> horario;/*! Conjunto de disciplinas e turmas */
    vector<string> codes;/*! Conjuntos de códigos de cadeiras (uccodes) */
    vector<string> turmas;/*! Conjuntos de códigos de turmas (classcodes) */
    queue<Pedido> pedidos;/*! Conjuntos de pedidos feitos por estudantes */
    vector<Pedido> sucesso;/*! Conjuntos de pedidos feitos que tiveram sucesso */
    vector<Pedido> fail;/*! Conjuntos de pedidos feitos que falharam */
};


#endif //AED_PROJECT_GESTAOHORARIOS_H