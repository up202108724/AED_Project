//
// Created by andre on 19-10-2022.
//
#ifndef AED_PROJECT_ESTUDANTE_H
#define AED_PROJECT_ESTUDANTE_H

#include <string>
#include <vector>
#include <iostream>
#include "UCTurma.h"
//! Uma Classe Estudante
/**
 * @brief Class Estudante para manipulação de Estudantes
 */

class Estudante {
public:
    /**
    * Cria um estudante, definido pelo seu nome e código de estudante
    * @brief Constructor.
     * @brief Complexidade O(1)
    *@param studentcode
    *@param name
    */
    Estudante(int studentcode, const string& name);
    /**
     * @brief obtẽm o código do estudante
     * @brief Complexidade O(1)
     * @return studentcode
     */
    int getCode() const;
    /**
     * @brief obtẽm o nome do estudante
     * @brief Complexidade O(1)
     * @return name
     */
    string getName() const;
    /**
     * @brief devolve o conjunto de turmas e disciplinas respetivas (UCTURMAS) em que o estudante está inscrito
     * @brief Complexidade O(1)
     * @return turmasEstudante
     */

    vector<UCTurma> getturmasEstudante();
    /**
     * @brief imprime sequencialmente  o código e nome do estudante, bem como cada turma e disciplina correspondente a que o estudante está inscrito
     * @brief Complexidade O(1)
    */
    void print() const;
    /**
     * @brief define a igualdade de estudantes pela comparação entre os seus códigos de estudante
     * @brief Complexidade O(1)
     * @param aluno
     * @return studentcode==aluno.getCode()
    */
    bool operator==(const Estudante &aluno) const;
    /**
     * @brief recebe como parâmetro um inteiro, e compara este com o código de estudante do objeto
     * @brief Complexidade O(1)
     * @param x
     * @return studentcode==x
     */
    bool operator==(int x) const;
    /**
     * @brief relaciona os estudantes pela comparação entre os seus códigos de estudante ( códigos de estudante inferiores definem posições anteriores em vetores de estudante ordenados)
     * @brief Complexidade O(1)
     * @param aluno
     * @return studentcode.getCode()==x
     */
    bool operator<(const Estudante& aluno) const;
    /**
     * @brief recebe um código de uma disciplina e remova o estudante da turma correspondente a essa disciplina
     * @brief Complexidade O(n)
     * @param uc
     *
     */
    void removerTurma(const string& uc);
    /**
     * @brief recebe um código de uma disciplina e remova o estudante da disiciplina correspondente ao código recebido
     * @brief Complexidade O(n)
     * @param uc
     */
    void removerUC(const string& uc);
    /**
     * @brief adiciona um aluno a uma turma , e à sua disciplina correspondente.
     * @brief Complexidade O(1)
     * @param turma
     */
    void adicionarTurma(const UCTurma &turma);//! Complexidade O(1)
    /**
     * @brief devolve o número de cadeiras em que um estudante está inscrito
     * @brief Complexidade O(1)
     * @return turmasEstudante.size()
     */

    int getnumUC_() const;
private:
    int studentcode_; /*! Código de estudante do estudante */
    string name_; /*! Nome do estudante */
    vector<UCTurma> turmasEstudante;/*! Vetor que representa o conjunto de todos as turmas e disciplinas correspondentes nas quais o estudante está inscrito */

};


#endif //AED_PROJECT_ESTUDANTE_H
