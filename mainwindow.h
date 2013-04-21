#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string.h>

namespace Ui {
  class GSCalculator;
}

class GSCalculator : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit GSCalculator(QWidget *parent = 0);
  ~GSCalculator();
  QString displayed_string;
  
private:
  Ui::GSCalculator *ui;

protected:
  void keyPressEvent(QKeyEvent *event);

private slots:
  void quit();
  void display();
  void Button_handle(char znak);
  void solve();
  void Button_0();
  void Button_1();
  void Button_2();
  void Button_3();
  void Button_4();
  void Button_5();
  void Button_6();
  void Button_7();
  void Button_8();
  void Button_9();
  void Button_clear();
  void Button_plus();
  void Button_minus();
  void Button_divide();
  void Button_multiply();
  void Button_power();
  void Button_factorial();
  void Button_modulo();
  void Button_comma();
};

#endif // MAINWINDOW_H
