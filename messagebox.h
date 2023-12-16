#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QWidget>
#include <iostream>
#include <QTimer>

namespace Ui {
class MessageBox;
}

class MessageBox : public QWidget
{
    Q_OBJECT

public:
    explicit MessageBox(QWidget *parent = nullptr);
    ~MessageBox();
class Messages;
private:
    Ui::MessageBox *ui;
//------------------------------------------------------------------------
public slots:
  void writeCurrUser(std::string);
  void objUsers(std::string*,bool*);
  void TimerSlot();
  void slotOtwet(int* id,std::string* ownRecv);
//------------------------------------------------------------------------
signals:
  void signSendMess(std::string* txtSendMess);//для отправки сообщения
  void signZapros(int* id,std::string* ownRecv);//запрос с базы данных
  void signShowStartWin();
public:
//========================================================================
  std::string gCurrUser;
  std::string* txtSendMess= new std::string[3];//формируем сообщение
  std::string* txtOwnRecv= new std::string[2];//формируем владельца и приемника
  std::string* prevUsers= new std::string[6];
  QTimer *timer;
  int* idMessage=new int[100]{};//id сообщений обьекта;
  void initIdObject();
private slots:
  void on_SendMess_clicked();
  void on_pushButton_clicked();
};

#endif // MESSAGEBOX_H
