/**
 * @file help.h
 * @author Martin Očenáš (xocena04)
 * @date 20.4.2013
 * @brief Definice třídy grafického rozhraní nápovědy
 */

#ifndef HELP_H
#define HELP_H

#include <QWidget>

namespace Ui {
  class Help;
}

/**
 * @brief Třída grafického rozhaní nápovědy
 */
class Help : public QWidget
{
  Q_OBJECT
  
public:
  explicit Help(QWidget *parent = 0);
  ~Help();
  
private:
  Ui::Help *ui;
};


#endif // HELP_H

/*** konec souboru help.h ***/
