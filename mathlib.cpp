/**
 * 
 * Kolekce matematických funkcí. Obsahuje operace +, -, *, /, mod, faktoriál 
 * a umocnění čísla přirozeným exponentem. I pro základní funkce +, -, *, / je 
 * vytvořena samostatná funkce pro vytvoření jednotného rozhraní.
 * 
 * Funkce neošetřují některé kritické vstupy, ty musí být ošetřeny o úroveň výše.
 * 
 * @file mathlib.cpp
 * @date 15. 4. 2013
 * @author David Kovařík ( xkovar66 )
 * @brief Základní matematická knihovna obsahující funkce +, -, *, /, modulo, 
 *      factoriál a umocňování přirozeným exponentem.
 * 
 */

#include <stdio.h>
#include <limits.h>
#include <math.h>

/**
 * @brief Operace sčítání
 * @param opA První operand
 * @param opB Druhý operand
 * @return Výsledek sčítání
 */
double plus(double opA, double opB) {
  //DBL_MAX
  return opA + opB;
}
 /**
  * @brief operace odčítání
  * @param opA První operand
  * @param opB Druhý operand
  * @return Výsledek odčítání
  */
double minus(double opA, double opB) {
  //DBL_MAX
  return opA - opB;
}

/**
 * @brief Operace násobení
 * @param opA Násobenec
 * @param opB Násobilel
 * @return Výsledek násobení
 */
double mul(double opA, double opB) {
  //DBL_MAX
  if (opB == 0 || opA == 0) 
    return 0;
  else if (opB == 1)
    return opA;
  else if (opA == 1)
    return opB;

  return opA * opB;
}

/**
 * @brief Operace modulo - zbytek po celočíselném dělení
 * @param opA První operand
 * @param opB Druhý operand
 * @return Zbytek po celočíselném dělení
 */
int mod(int opA, int opB){
  return opA % opB;
}

/**
 * @brief Operace dělení. Pokud je dělitel roven 0 nastane chyba
 * @param opA Dělenec
 * @param opB Dělitel
 * @return Konstanta NAN pokud je hodnota dělitele 0, jinak výsledek operace
 */
double div(double opA, double opB) {
  if( opB == 0 )
    return NAN;
  
  if (opA == opB)
    return 1;
  else if (opB == 1)
    return opA;
  else if (opA == 0)
    return 0;
  
  return opA / opB;
}

/**
 * @brief Operace faktoriál
 * @param x Operand operace pro x >= 0
 * @return Výsledek operace
 */
unsigned int fact(unsigned int x) {
   unsigned int sum = 1;
    for(unsigned int i = 1; i <= x; ++i)
        sum *= i;

    return sum;
}

/**
 * @brief Operace umocňování čísla přirozeným exponentem.
 * @param base Základ operace
 * @param exp Přirozený exponent
 * @return Výsledek operace
 */
double pow(double base, unsigned int exp) {
  
  double sum = 1;
  
  if (exp == 0) { //pokud je epxonent roven 0, vysledek je vzdy 1
    return 1;
  } else if (exp == 1){ //exponent je roven 1, vysledek je nezmeneny operand
    return base;
  } else if (base == 0) { //zaklad je roven 0, vysledek je 0
    return 0;
  } else if (base == 1){ //zaklad je roven 1, vysledek 1
    return 1;
  }
  
  //umocneni
  for (unsigned int i = 0; i < exp; ++i){
    sum *= base;
  }

  return sum;
}

/*** Konec souboru matlib.cpp ***/