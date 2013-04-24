/**
 * Nastavení nápovědy
 *
 * @file help.cpp
 * @author Martin Očenáš (xocena04)
 * @date 20.4.2013
 * @brief Konfigurační soubor nápovědy
 */

#include "help.h"
#include "ui_help.h"

// vytvoření objektu nápovědy
Help::Help(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Help)
{
  ui->setupUi(this);
  connect(ui->close,SIGNAL(pressed()),this,SLOT(close())); //nastavení tlačítka close na ukončení okna
  ui->Image->setStyleSheet("background-image: url(veverka.png);"); //nastavení loga do prvku v nápovědě
}

Help::~Help()
{
  delete ui;
}

/*** konec souboru help.cpp ***
