/**
 * Obsahuje definice funkcí obsluhy grafického rozhraní
 * a nastavení obsluhy tlačítek a kláves
 *
 * @file mainwindow.cpp
 * @author Martin Očenáš (xocena04)
 * @date 10.4.2013
 * @brief Konfigurační a řídící soubor grafického rozhranní
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controller.h"
#include "math.h"
#include <QKeyEvent>

// vytvoření objektu grafického rozhraní
GSCalculator::GSCalculator(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::GSCalculator)
{
  ui->setupUi(this);

  /*
   * Oveření, jestli systém chce desetinou tečku, nebo čárku
   *
   */
  int errcode;
  double result=execute("1.0", &errcode); // výpočet
  if (!(isnan(result) && errcode != 0))
  {
    this->decimal_delimiter='.';
  }
  else
  {
    this->decimal_delimiter=',';
  }

  // nastavení obsluhy tlačítek
  connect(ui->ukoncit,SIGNAL(triggered()),this,SLOT(quit()));
  connect(ui->help,SIGNAL(triggered()),this,SLOT(open_help()));
  connect(ui->Button_clear,SIGNAL(pressed()),this,SLOT(Button_clear()));
  connect(ui->Button_0,SIGNAL(pressed()),this,SLOT(Button_0()));
  connect(ui->Button_1,SIGNAL(pressed()),this,SLOT(Button_1()));
  connect(ui->Button_2,SIGNAL(pressed()),this,SLOT(Button_2()));
  connect(ui->Button_3,SIGNAL(pressed()),this,SLOT(Button_3()));
  connect(ui->Button_4,SIGNAL(pressed()),this,SLOT(Button_4()));
  connect(ui->Button_5,SIGNAL(pressed()),this,SLOT(Button_5()));
  connect(ui->Button_6,SIGNAL(pressed()),this,SLOT(Button_6()));
  connect(ui->Button_7,SIGNAL(pressed()),this,SLOT(Button_7()));
  connect(ui->Button_8,SIGNAL(pressed()),this,SLOT(Button_8()));
  connect(ui->Button_9,SIGNAL(pressed()),this,SLOT(Button_9()));
  connect(ui->Button_plus,SIGNAL(pressed()),this,SLOT(Button_plus()));
  connect(ui->Button_minus,SIGNAL(pressed()),this,SLOT(Button_minus()));
  connect(ui->Button_divide,SIGNAL(pressed()),this,SLOT(Button_divide()));
  connect(ui->Button_multiply,SIGNAL(pressed()),this,SLOT(Button_multiply()));
  connect(ui->Button_power,SIGNAL(pressed()),this,SLOT(Button_power()));
  connect(ui->Button_factorial,SIGNAL(pressed()),this,SLOT(Button_factorial()));
  connect(ui->Button_modulo,SIGNAL(pressed()),this,SLOT(Button_modulo()));
  connect(ui->Button_comma,SIGNAL(pressed()),this,SLOT(Button_comma()));
  connect(ui->Button_solve,SIGNAL(pressed()),this,SLOT(solve()));
}

/**
 * Nastavení odchycení stisknutých kláves a jejich obsluha
 *
 * @brief Zpracování stisknutých kláves
 * @param event událost, generovaná grafickým rozhraním
 */
void GSCalculator::keyPressEvent(QKeyEvent *event)
{
  switch (event->key())
  {
    // nastavení tlačítka "Enter (Return)" na provedení výpočtu
    case Qt::Key_Return:
    this->solve();
    break;
  }
}

/**
 * @brief Otevření nápovědy
 */
void GSCalculator::open_help()
{
  help = new Help(); // vytvoření okna nápovědy
  help->show(); // zobrazení okna nápovědy
}

GSCalculator::~GSCalculator()
{
  delete ui;
}

/**
 * @brief Ukončení aplikace
 */
void GSCalculator::quit()
{
  QApplication::quit();
}

/**
 * @brief Obsluha stisknutí tlačítka
 * @param znak Znak, který se má přídat na display
 */
void GSCalculator::Button_handle(char znak)
{
  this->displayed_string=ui->Display->text();
  this->displayed_string+=znak;
  this->display();
}

/**
 * @brief Zobrazení řetězce na display
 */
void GSCalculator::display()
{
  // pokud daný stroj používá jiný desetinný oddělovač než tečku, nahradit tečky tímto oddělovačem
  if (this->decimal_delimiter != '.')
  {
    this->displayed_string=this->displayed_string.replace('.',this->decimal_delimiter);
  }
  ui->Display->setText(this->displayed_string);
}

/**
 * Funkce pro provedení výpočtu
 * @brief Provedení výpočtu
 */
void GSCalculator::solve()
{
  int errcode; // vracený chybový stav výpočetní funkce
  double result=execute(qPrintable(ui->Display->text()), &errcode); // výpočet

  /*
   * Pro chybuje potřeba testovat jak result, tak errcode.
   * (result == NAN && errcode == 0), nemusí implikovat neplatný matematický
   * výraz (například ln(-1) == NAN, přesto výraz je platný)
   */
  if (isnan(result) && errcode != 0)
  {
    this->displayed_string="Neplatny matematicky vyraz\n";
  }
  else
  {
    this->displayed_string=QString::number(result);
  }
  this->display();
}

/**
 * @brief Obsluha tlačítka vymazaní display
 */
void GSCalculator::Button_clear()
{
  this->displayed_string.clear();
  this->display();
}

/**
 * @brief Obsluha tlačítka 0
 */
void GSCalculator::Button_0()
{
  Button_handle('0');
}

/**
 * @brief Obsluha tlačítka 1
 */
void GSCalculator::Button_1()
{
  Button_handle('1');
}

/**
 * @brief Obsluha tlačítka 2
 */
void GSCalculator::Button_2()
{
  Button_handle('2');
}

/**
 * @brief Obsluha tlačítka 3
 */
void GSCalculator::Button_3()
{
  Button_handle('3');
}

/**
 * @brief Obsluha tlačítka 4
 */
void GSCalculator::Button_4()
{
  Button_handle('4');
}

/**
 * @brief Obsluha tlačítka 5
 */
void GSCalculator::Button_5()
{
  Button_handle('5');
}

/**
 * @brief Obsluha tlačítka 6
 */
void GSCalculator::Button_6()
{
  Button_handle('6');
}

/**
 * @brief Obsluha tlačítka 7
 */
void GSCalculator::Button_7()
{
  Button_handle('7');
}

/**
 * @brief Obsluha tlačítka 8
 */
void GSCalculator::Button_8()
{
  Button_handle('8');
}

/**
 * @brief Obsluha tlačítka 9
 */
void GSCalculator::Button_9()
{
  Button_handle('9');
}

/**
 * @brief Obsluha tlačítka plus(+)
 */
void GSCalculator::Button_plus()
{
  Button_handle('+');
}

/**
 * @brief Obsluha tlačítka mínus(-)
 */
void GSCalculator::Button_minus()
{
  Button_handle('-');
}

/**
 * @brief Obsluha tlačítka dělení(/)
 */
void GSCalculator::Button_divide()
{
  Button_handle('/');
}

/**
 * @brief Obsluha tlačítka násobení(*)
 */
void GSCalculator::Button_multiply()
{
  Button_handle('*');
}

/**
 * @brief Obsluha tlačítka mocniny(^)
 */
void GSCalculator::Button_power()
{
  Button_handle('^');
}

/**
 * @brief Obsluha tlačítka faktoriál(!)
 */
void GSCalculator::Button_factorial()
{
  Button_handle('!');
}

/**
 * @brief Obsluha tlačítka modulo(mod)
 */
void GSCalculator::Button_modulo()
{
  Button_handle('%');
}

/**
 * @brief Obsluha tlačítka desetinné tečky(.)
 */
void GSCalculator::Button_comma()
{
  Button_handle(this->decimal_delimiter);
}
/*** konec souboru mainwindow.cpp ***/
