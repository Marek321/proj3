/**
 * Zajištění spuštění grafické aplikace
 *
 * @file main.cpp
 * @author Martin Očenáš (xocena04)
 * @date 10.4.2013
 * @brief Spouštěcí soubor grafické aplikace
 */

#include "mainwindow.h"
#include <QApplication>

/**
 * @brief main Spouštějící funkce programu
 * @param argc Počet argumentů - aplikace je nevyužívá
 * @param argv Znění arugmentů - aplkace je nevyužívá
 * @return Návratová hodnota programu 0 - bez chyby
 */
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  GSCalculator w;
  w.show();
  
  return a.exec();
}
/*** konec souboru main.cpp ***/
