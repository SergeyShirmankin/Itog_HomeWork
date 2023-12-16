#include "messagebox.h"
#include "ui_messagebox.h"
#include <QDebug>

MessageBox::MessageBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageBox)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->start(1000);//Стартуем таймер раз 1секунду
    connect(timer,SIGNAL(timeout()),this,SLOT(TimerSlot()));
    initIdObject();
    ui->SendMess->setToolTip("Два раза кликните для передачи сообщенимя");
}

MessageBox::~MessageBox()
{
    delete ui;
}

void MessageBox::writeCurrUser(std::string currUser )// Запись пользователя в поле label
{
    QString qCurrUser=QString::fromStdString(currUser);
    std::string temp;
     ui->User->setText(qCurrUser);
     gCurrUser=currUser;

}

void MessageBox::objUsers(std::string *objUsers,bool* isObjects)
{
         int currInd;
         int i=-1;
         std::string temp;
         ui->comboBox->setDuplicatesEnabled(true);
         do
         {
         ++i;
         temp=objUsers[i];
          if (temp.compare("end"))
              if (temp.compare("Null"))
                     if (isObjects[i]==true)
              {
                        ui->comboBox->setItemText(i,QString::fromStdString(temp)); //добавление Users  в ComboBox
              }
         }
         while(temp.compare("end"));
}

void MessageBox::TimerSlot()
{
    QString qOwn=ui->User->text();
    txtSendMess[0]=qOwn.toStdString();
    QString qReciver=ui->comboBox->currentText();
    txtSendMess[1]=qReciver.toStdString();
    txtSendMess[2]="Null";
    emit signZapros(idMessage,txtSendMess);
}

void MessageBox::slotOtwet(int *id, std::string *ownRecv)
{
   QString qSend=QString::fromStdString(ownRecv[0]);
   QString qResv=QString::fromStdString(ownRecv[1]);
   QString qMess=QString::fromStdString(ownRecv[2]);
   if (!gCurrUser.compare(ownRecv[1]))
      ui->textEdit->append(">> "+qSend+"->"+qResv+" : "+qMess);
   else if (!gCurrUser.compare(ownRecv[0]))
      ui->textEdit->append(">> "+qSend+"->"+qResv+" : "+qMess);

}

void MessageBox::initIdObject()
{
    int i=-1;
    do
    {
      ++i;
      ui->comboBox->addItem(QString::fromStdString(""));
    }
    while(i<6);



 for (int i=0; i<100;i++)
 {
     idMessage[i]=-1;
 }
}


void MessageBox::on_SendMess_clicked()
{
    QString strOwn=ui->User->text();
    txtSendMess[0]=strOwn.toStdString();//own
    QString strReciver=ui->comboBox->currentText();
    txtSendMess[1]=strReciver.toStdString();//reciver
    QString _message=ui->lineEdit->text();
    txtSendMess[2]= _message.toStdString();//message
    emit signSendMess(txtSendMess);
}


void MessageBox::on_pushButton_clicked()
{
    emit signShowStartWin();
}

