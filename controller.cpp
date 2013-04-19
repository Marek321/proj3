#include <stdio.h>
#include <stdlib.h>


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

int main(void) {
    
    execute("1+1");
    
}

double execute(const char* expression) {
   
    printf("Vyraz: %s\n", expression);
    
   return 0.0; 
}
