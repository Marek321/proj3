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

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  GSCalculator w;
  w.show();
  
  return a.exec();
}
/*** konec souboru main.cpp ***/
