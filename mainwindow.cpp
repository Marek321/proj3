#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controller.h"
#include "math.h"
#include <QKeyEvent>

GSCalculator::GSCalculator(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::GSCalculator)
{
  ui->setupUi(this);
  connect(ui->ukoncit,SIGNAL(triggered()),this,SLOT(quit()));
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

void GSCalculator::keyPressEvent(QKeyEvent *event)
{
  switch (event->key())
  {
    case Qt::Key_Return:
    this->solve();
    break;
  }
}

GSCalculator::~GSCalculator()
{
  delete ui;
}

void GSCalculator::quit()
{
  QApplication::quit();
}

void GSCalculator::Button_handle(char znak)
{
  this->displayed_string=ui->Display->text();
  this->displayed_string+=znak;
  this->display();
}

void GSCalculator::display()
{
  ui->Display->setText(this->displayed_string);
}

void GSCalculator::solve()
{
  int errcode;
  double result=execute(qPrintable(ui->Display->text()), &errcode);

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

void GSCalculator::Button_clear()
{
  this->displayed_string.clear();
  this->display();
}

void GSCalculator::Button_0()
{
  Button_handle('0');
}

void GSCalculator::Button_1()
{
  Button_handle('1');
}

void GSCalculator::Button_2()
{
  Button_handle('2');
}

void GSCalculator::Button_3()
{
  Button_handle('3');
}

void GSCalculator::Button_4()
{
  Button_handle('4');
}

void GSCalculator::Button_5()
{
  Button_handle('5');
}

void GSCalculator::Button_6()
{
  Button_handle('6');
}

void GSCalculator::Button_7()
{
  Button_handle('7');
}

void GSCalculator::Button_8()
{
  Button_handle('8');
}

void GSCalculator::Button_9()
{
  Button_handle('9');
}

void GSCalculator::Button_plus()
{
  Button_handle('+');
}

void GSCalculator::Button_minus()
{
  Button_handle('-');
}

void GSCalculator::Button_divide()
{
  Button_handle('/');
}

void GSCalculator::Button_multiply()
{
  Button_handle('*');
}

void GSCalculator::Button_power()
{
  Button_handle('^');
}

void GSCalculator::Button_factorial()
{
  Button_handle('!');
}

void GSCalculator::Button_modulo()
{
  Button_handle('%');
}

void GSCalculator::Button_comma()
{
  Button_handle('.');
}
