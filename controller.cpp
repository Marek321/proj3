/**
 * Kolekce funkcí určených pro vyhodnocení řetezce jako matematický výraz
 * obsahující binární či unární operace.
 *
 * @file controller.cpp
 * @author David Kovařík ( xkovar66 )
 * @date 19. 4. 2013
 * @brief Kolekce funcí pro vyhodnocení matematického výrazu.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include "mathlib.h"


/**
 * Struktura popisující matematickou operaci (binární | unární)
 */
typedef struct operation {
    int operation; /**< Identifikátor operace */
    double operandA; /**< První operand operace*/
    double operandB; /**< Druhý operand operace (pokud není potřeba, měl by být nastaven na NAN) */
} TOperation;

/**
 * Zpracuje předaný řetezec jako matematický výraz, vyhodnotí jej a vrácí
 * číselnou hodnotu výsledku.
 * @param expression Řetezec obsahující matematický výraz
 * @param errcode Chybový kód vyhodnocování operacew
 * @return Výsledek výrazu
 */
double execute(const char* expression, int *errcode);

/**
 * Chybové stavy
 */
enum eCodes {
    EOK = 0,
    ZERO_DIVISION,
    INVALID_MATHEXP
};


/**
 * Zpracuje předaný řetezec jako matematický výraz, vyhodnotí jej a vrácí
 * číselnou hodnotu výsledku.
 * @param expression Řetezec obsahující matematický výraz
 * @param errcode Chybový kód vyhodnocování operacew
 * @return Výsledek výrazu
 */
double execute(const char* expression, int *errcode);

/**
 * @brief Vyhodnotí matematickou operaci rozdělenou ve struktuře typu TOperation
 * @param op Ukazatel na sturkturu popisující operaci
 * @param result Ukazatel, kam se uloží výsledek
 * @return Vrací EOK pokud se operace podařila jinak číslo větší než 0
 */
int eval(TOperation *op, double *result);

/**
 * Kontroluje, zda znak (jeho ascii hodnota) může reprezentovat matematickou
 * operaci
 * @param operation Znak identifikující operaci
 * @return Vrací 1 pokud znaku odpovídá matematická operace, jinak 0
 */
int isValidOperation(char operation);

/**
 * Zkontroluje, zda číslo obsahje desetinnou část (různou od 0)
 * @param x Hodnota, která se má ověřit
 * @return Vrací 1, pokud se číslo skládá jen z celé části, jinak 0.
 */
int isIntiger(double x);

/*
int main(int argc, char** argv) {

    if (argc == 1)
        return 1;


    int errcode;

    double result = execute(argv[1], &errcode);


    // Pro chybuje potřeba testovat jak result, tak errcode.
    // (result == NAN && errcode == 0), nemusí implikovat neplatný matematický
    // výraz (například ln(-1) == NAN, přesto výraz je platný)

    if (isnan(result) && errcode != 0) {
        printf("Neplatny matematicky vyraz\n");
        return errcode;
    }

    printf("vyraz: %s\n", argv[1]);
    printf("vysledek %lf\n-------\n", result);
}

 */

double execute(const char* expression, int *errcode) {
    //nastaviit lokali
    setlocale(LC_ALL, "C");

    TOperation op; //struktura popisujici operaci
    int strlenght; //delka (zbytku) vyrazu

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
    if (isValidOperation(op.operation) == 0) {
        return NAN;
    }
    pEnd++; //preskoc jiz prectenou operaci


    if (strlen(pEnd) > 0) { //pokud je za operaci jeste nejaky znak, nacti je jako cislo
        op.operandB = strtod(pEnd, &pEnd);
    } else {
        op.operandB = NAN; //jinak vyhodnot operandB jako NAN
    }

    if (strlen(pEnd) > 0) //nekorektni vyraz
        return NAN;


    double result;

    *errcode = eval(&op, &result);

    return result;
}

int isValidOperation(char op) {
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%'
            || op == '!' || op == '^') {
        return 1;
    } else {
        return EOK;
    }

    return EOK;
}

int isIntiger(double x) {
    if (x != (((int) x))) // hodnota x a pouze jeho cela cast je rozdilna
        return 0;

    return 1;
}

int eval(TOperation *op, double *result) {

    /* rozpoznani operace a provedeni patrickych kroku */
    switch (op->operation) {
        case '+': *result = plus(op->operandA, op->operandB);
            break;
        case '-': *result = minus(op->operandA, op->operandB);
            break;
        case '*': *result = mul(op->operandA, op->operandB);
            break;
        case '/': *result = div(op->operandA, op->operandB);
            if (isnan(*result))
                return ZERO_DIVISION;
            break;
        case '%':
        {
            //otestuje, zda jsou operandy cela cisla
            if (!isIntiger(op->operandA)) { //otestuje operandA
                *result = NAN;
                return INVALID_MATHEXP;
            } else if (!isIntiger(op->operandB)) {//otestuje operandB
                *result = NAN;
                return INVALID_MATHEXP;
            } else if (op->operandB == 0) {
                *result = NAN;
                return INVALID_MATHEXP;
            }

            *result = mod(op->operandA, op->operandB); //uloz vysledek
        }
            break;
        case '!':
        {
            if (op->operandA < 0) { //faktorial je definovan pro n > 0;
                *result = NAN;
                return INVALID_MATHEXP;
            }

            if (!isnan(op->operandB)) { //operandB neni NAN => neplatny vyraz
                *result = NAN;
                return INVALID_MATHEXP;
            }
            
            //otestuje, zda jsou operandy cela cisla
            if (!isIntiger(op->operandA)) { //otestuje operandA
                *result = NAN;
                return INVALID_MATHEXP;
            }
            
            
            *result = fact(op->operandA);

        }
            break;
        case '^': *result = pow(op->operandA, op->operandB);
            break;
        default: return INVALID_MATHEXP;
    }

    return EOK;

}
/*** Konec souboru controller.cpp ***/
