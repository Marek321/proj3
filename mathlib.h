#include <stdio.h>
#include <float.h>

#ifndef _MATHLIB_H_
#define _MATHLIB_H_


/**
 * @brief Operace sčítání
 * @param opA První operand
 * @param opB Druhý operand
 * @return Výsledek sčítání
 */
double plus(double opA, double opB);

 /**
  * @brief operace odčítání
  * @param opA První operand
  * @param opB Druhý operand
  * @return Výsledek odčítání
  */
double minus(double opA, double opB);

/**
 * @brief Operace násobení
 * @param opA Násobenec
 * @param opB Násobilel
 * @return Výsledek násobení
 */
double mul(double opA, double opB);

/**
 * @brief Operace modulo - zbytek po celočíselném dělení
 * @param opA První operand
 * @param opB Druhý operand
 * @return Zbytek po celočíselném dělení
 */
int mod(int opA, int opB);

/**
 * @brief Operace dělení. Pokud je dělitel roven 0 nastane chyba
 * @param opA Dělenec
 * @param opB Dělitel
 * @return Konstanta NAN pokud je hodnota dělitele 0, jinak výsledek operace
 */
double div(double opA, double opB);

/**
 * @brief Operace faktoriál
 * @param x Operand operace pro x >= 0
 * @return Výsledek operace
 */
unsigned int fact(unsigned int x);

/**
 * @brief Operace umocňování čísla přirozeným exponentem.
 * @param base Základ operace
 * @param exp Přirozený exponent
 * @return Výsledek operace
 */
double pow(double base, unsigned int exp);




#endif

/*** Konec souboru matlib.cpp ***/
