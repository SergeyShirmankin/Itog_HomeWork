#include "registration.h"
#include "ui_registration.h"
#include <QDebug>
#include <QMessageBox>
//#include "log_pass.h"

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_PushButtonOK_clicked()
{
  bool loginEmty=ui->lineEditLogin->displayText().isEmpty();
  if (loginEmty==true)
  {
     QMessageBox::warning(this," Регистрация  "," Пустое поле Логина  ");
     return;
  }

  bool passwordEmty = ui->lineEditPassword->displayText().isEmpty();
  if (passwordEmty==true)
  {
      QMessageBox::warning(this," Регистрация  "," Пустое поле пароля  ");
       return;
  }

    QString newLogin = ui->lineEditLogin->text();
    QString newPassword = ui->lineEditPassword->text();
    QString confirmPasword = ui->lineEditConfrmPass->text();

    if (newPassword == confirmPasword)
    {
       emit sign_addLogPass(newLogin,newPassword);
       emit  showWindow();
       hide();
       ui->lineEditLogin->setText("");
       ui->lineEditPassword->setText("");
       ui->lineEditConfrmPass->setText("");
    }
    else
    {
        QMessageBox::warning(this," Регистрация  ","Вы  не зарегестрировались");
    }
}


void Registration::on_pushButtonCancel_clicked()
{
    emit  showWindow();
    hide();
}

