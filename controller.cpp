#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mathlib.h"

typedef struct operation {
    int operation;
    double operandA;
    double operandB;
} TOperation;


/**
 * Zpracuje předaný řetezec jako matematický výraz, vyhodnotí jej a vrácí
 * číselnou hodnotu výsledku
 * @param expression Řetezec obsahující matematický výraz
 * @return Výsledek výrazu
 */
double execute(const char* expression);

/**
 * @brief Vyhodnotí matematickou operaci rozdělenou ve struktuře typu TOperation
 * @param op Ukazatel na sturkturu popisující operaci
 * @param result Ukazatel, kam se uloží výsledek
 * @return 0 pokude se operace podařila jinak číslo větší než 0
 */
int eval(TOperation *op, double *result);

/**
 * Kontroluje, zda znak (jeho ascii hodnota) může reprezentovat matematickou
 * operaci
 * @param operation Znak identifikující operaci
 * @return Vrací 1 pokud znaku odpovídá matematická operace, jinak 0 
 */
int isValidOperation(char operation);

int main(void) {

    execute("1    + 2");
    execute("     1 -    2");
    execute("1   1  + 2");
    execute("3.3    * 4");
    execute("1    / 0");
    execute("1    % 2");
    execute("1   !");
    execute("1    ! 2");
    execute("1    ^ 2");
    execute("1    ^");
    execute("1.1");
    execute("1daf");
    execute("1! 2 3");
}

double execute(const char* expression) {

    TOperation op; //struktura popisujici operaci
    int strlenght; //delka (zbytku) vyrazu

    printf("Vyraz: %s\n", expression);

    char *pEnd; //pocatek vyrazu, ktery jeste nebyl vyhodnocen    
    op.operandA = strtod(expression, &pEnd);
    strlenght = strlen(pEnd);

    if (strlenght == 0)
        return op.operandA; //pokud neni zadana operaci, vrat hodnotu ze vstupu

    for (int i = 0; i < strlenght; ++i) { //projdi cely retezec
        if (pEnd[i] != ' ') { //preskoc mezery pred znakem operace 
            pEnd += i;
            break;
        }
    }

    op.operation = pEnd[0]; //nacti operaci (ascii hodnotu znaku)
    if (isValidOperation(op.operation) == 0){
        return NAN;
    }
    pEnd++; //preskoc jiz prectenou operaci


    if (strlen(pEnd) > 0) { //pokud je za operaci jeste nejaky znak, nacti je jako cislo
        op.operandB = strtod(pEnd, &pEnd);
    } else {
        op.operandB = NAN; //jinak vyhodnot operandB jako NAN
    }
    
    if(strlen(pEnd) > 0) //nekorektni vyraz
        return NAN;

    /*
    printf("operand A: %lf\n", op.operandA);
    printf("operation: %c\n", op.operation);
    printf("operand B: %lf\n", op.operandB);
    printf("-------------\n");
     */

    double result;
    
    int errcode = eval(&op, &result);
    
    return result;
}

int isValidOperation(char op) {
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%'
            || op == '!' || op == '^') {
        return 1;
    } else {
        return 0;
    }

    return 0;
}


int eval(TOperation *op, double *result){
    
    
    
    return 0;
}