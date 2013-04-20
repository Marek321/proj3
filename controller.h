/**
 * 
 * Zpřístupňuje vyšším vrstvám rozhraní pro vyhodnocení matematického výrazu
 * z řetězce. Nabízí pouze funkci pro spuštění celé operace vyhodnocení. Další
 * funkce z knihovny jsou privátní a vyšším vrstvám není možněno k nim 
 * přistupovat.
 * 
 * @brief Rozhraní poskytující vyšším vrstvám službu vyhodnocení matematického výrazu.
 * 
 * @file controller.h
 * @author David Kovařík ( xkovar66 )
 * @date 20. 4. 2013
 */

#include <stdio.h>
#include <float.h>

#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

/**
 * Zpracuje předaný řetezec jako matematický výraz, vyhodnotí jej a vrácí
 * číselnou hodnotu výsledku
 * @param expression Řetezec obsahující matematický výraz
 * @param errcode Chybový kód vyhodnocování operacew
 * @return Výsledek výrazu
 */
double execute(const char* expression, int *errcode);


#endif