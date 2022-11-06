//
// Created by andre on 02-11-2022.
//

#ifndef AED_PROJECT_PEDIDO_H
#define AED_PROJECT_PEDIDO_H
#include <string>
#include <iostream>
using namespace std;
//! Uma classe Pedido
/**
 * @brief Classe Pedido para manipulação de pedidos
 */

class Pedido {
public:
    /**
     * Create um pedido com diversas características.
     * @brief Constructor.
     * @brief Complexidade O(1)
     * @param studentcode
     * @param uccode
     * @param classcode
     * @param uccode2
     * @param classcode2
     * @param type
     */
    Pedido(int studentcode, const string& uccode, const string& classcode, const string& uccode2, const string& classcode2, const string& type);
    /**
     * @brief Devolve o codigo do estudante que faz o pedido
     * @brief Complexidade O(1)
     * @return Codigo do estudante
     */

    int getStudent() const {return studentcode_;};
    /**
     * @brief Devolve o codigo da UC
     * @brief Complexidade O(1)
     * @return Codigo da UC
     */
    string getUC() const {return uccode_;};
    /**
     * @brief Devolve o codigo da turma do estudante
     * @brief Complexidade O(1)
     * @return Codigo da turma
     */
    string getClass() const {return classcode_;};
    /**
     * @brief Devolve o codigo da UC
     * @brief Complexidade O(1)
     * @return Codigo da UC
     */
    string getUC2() const {return uccode2_;};
    /**
     * @brief Devolve o codigo da turma para a qual o estudante pretende ir
     * @brief Complexidade O(1)
     * @return Codigo da turma
     */
    string getClass2() const {return classcode2_;};
    /**
     * @brief Devolve o tipo de pedido
     * @brief Complexidade O(1)
     * @return Tipo de pedido
     */
    string getType() const {return type_;};
    /**
     * @brief Imprimir informação sobre o pedido dependendo do tipo de pedido
     * @brief Complexidade O(1)
     */
    void print() const;

private:
    int studentcode_; /*! Código do estudante */
    string uccode_; /*! Código da UC */
    string classcode_; /*! Código da turma do estudante */
    string uccode2_; /*! Código da UC */
    string classcode2_; /*! Código da turma pretendida pelo estudante */
    string type_; /*! Tipo de pedido */
};


#endif //AED_PROJECT_PEDIDO_H