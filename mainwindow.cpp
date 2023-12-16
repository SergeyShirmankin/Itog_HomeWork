#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)//Конструктор
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    reg = new Registration;
    timer =new QTimer(this);
    connect(reg,&Registration::showWindow,this,&MainWindow::showObject);
    connect(reg,&Registration::sign_addLogPass,this,&MainWindow::addLogPass);
    connect(timer,SIGNAL(timeout()),this,SLOT(TimerSlot()));
    timer->start(1000);//Стартуем таймер раз 1секунду
    initisObject();//инициализация наличия обьектов (выставляются false)
}

void MainWindow::convertQstToStr(QString &qLogin, QString &qPassword)//Преобразование Qstring  в строку
{
    pSt->login=qLogin.toStdString();
    pSt->password=qPassword.toStdString();
}

void MainWindow::initisObject()
{
    for (unsigned i{};i<maxNumUsers;i++)
    {
        isObjects[i]=false;
        mess[i]=nullptr;
    }
}
MainWindow::~MainWindow()//деструктор
{
    delete ui;
}

void MainWindow::showObject()
{
    show();
}

//=================================================================
//------ В 1 секунду считываем данные и отправляем сигнал----------
void MainWindow::TimerSlot()
{
    int cointUsers=-1;
//----------------------------------------------------------------------------------------
    for (int a=0;a<maxNumUsers;a++)
    {
        objUsers[a]="Null"; //инициализация строк для передачи users в сигналы
    }
    objUsers[maxNumUsers]="end";
 //-----------------------------------------------------------------------------------------
    for (auto it = pSt->_log_pass.begin(); it != pSt->_log_pass.end(); ++it)// опрашиваем таблицу
    {
        ++cointUsers;
        objUsers[cointUsers]=it->first;//записываем данные в массив
    }
    if (isObjects[0]==true)
        if (mess[0]!=nullptr)
    {
        emit signUsers1(objUsers,isObjects);
    }
    if (isObjects[1]==true)
        if (mess[1]!=nullptr)
    {
        emit signUsers2(objUsers,isObjects);
    }
    if (isObjects[2]==true)
        if (mess[2]!=nullptr)
    {
        emit signUsers3(objUsers,isObjects);
    }
    if (isObjects[3]==true)
        if (mess[3]!=nullptr)
    {
        emit signUsers4(objUsers,isObjects);
    }
    if (isObjects[4]==true)
        if (mess[4]!=nullptr)
    {
        emit signUsers5(objUsers,isObjects);
    }
}
//=================================================================
void MainWindow::on_pushButtonCancel_clicked()
{
     hide();
}

//=============== Авторизация и создание окна с сообщениями ================================
void MainWindow::on_pushButtonAutorization_clicked()
{
//-----------------------преобразованпие QString  в строку  ---------------------------------
    QString autoLogin =ui->lineEditLogin->text();
    QString autoPassword = ui->lineEditPassword->text();
    std::string login=autoLogin.toStdString();//поле логина
    std::string password=autoPassword.toStdString();// поле пароля
    bool  isAuto =false;//выставляется в true  при успешной авторитазации
    int cointUsers=-1;
    std::string tempStr;
//----------------------------------------------------------------------------------------
   for (int b=0; b<(maxNumUsers+1);b++)
   {
      tempStr=Logins[b];
      if(!tempStr.compare(login))
      {
          QMessageBox::warning(this,"Авторизация","Такой логин  уже авторизирован или Пустое поле логина!!!. Выберите другой логин или заполните поле");
          return;
      }
   }
//----------------------------------------------------------------------------------------
             for (int a=0;a<maxNumUsers;a++)
             {
               objUsers[a]="Null"; //инициализация строк для передачи users в сигналы
             }
             objUsers[maxNumUsers]="end";
//-----------------------------------------------------------------------------------------
         i++;// счетчик пользоваткелей
         for (auto it = pSt->_log_pass.begin(); it != pSt->_log_pass.end(); ++it)
            {
             ++cointUsers;
             curSession=i;
             objUsers[cointUsers]=it->first;
             currUser = it->first;

                if (!(login.compare(it->first))&& !(password.compare(it->second)))// поиск логина и пароля
                {
                    mess[i] = new MessageBox;                  
                     switch(i)
                     {
                           case 0:
                               connect(this,&MainWindow::signCurrUsers1,mess[0],&MessageBox::writeCurrUser);
                               connect(this,&MainWindow::signUsers1,mess[0],&MessageBox::objUsers);
                               connect(mess[0],&MessageBox::signSendMess,this,&MainWindow::addRecvMess);
                               connect(mess[0],&MessageBox::signZapros,this,&MainWindow::zaprosBase);
                               connect(this,&MainWindow::signOtwet,mess[0],&MessageBox::slotOtwet);
                               connect (mess[0],&MessageBox::signShowStartWin,this,&MainWindow::showStartWin);
                               emit signCurrUsers1(currUser);
                               isObjects[0]=true;
                               Logins[0]=currUser;
                               break;
                           case 1:
                               connect(this,&MainWindow::signCurrUsers2,mess[1],&MessageBox::writeCurrUser);
                               connect(this,&MainWindow::signUsers2,mess[1],&MessageBox::objUsers);
                               connect(mess[1],&MessageBox::signSendMess,this,&MainWindow::addRecvMess);
                               connect(mess[1],&MessageBox::signZapros,this,&MainWindow::zaprosBase);
                               connect(this,&MainWindow::signOtwet,mess[1],&MessageBox::slotOtwet);
                               connect (mess[1],&MessageBox::signShowStartWin,this,&MainWindow::showStartWin);
                               emit signCurrUsers2(currUser);
                               isObjects[1]=true;
                               Logins[1]=currUser;
                               break;
                           case 2:
                               connect(this,&MainWindow::signCurrUsers3,mess[2],&MessageBox::writeCurrUser);
                               connect(this,&MainWindow::signUsers3,mess[2],&MessageBox::objUsers);
                               connect(mess[2],&MessageBox::signSendMess,this,&MainWindow::addRecvMess);
                               connect(mess[2],&MessageBox::signZapros,this,&MainWindow::zaprosBase);
                               connect(this,&MainWindow::signOtwet,mess[2],&MessageBox::slotOtwet);
                               connect (mess[2],&MessageBox::signShowStartWin,this,&MainWindow::showStartWin);
                               emit signCurrUsers3(currUser);
                               isObjects[2]=true;
                               Logins[2]=currUser;
                               break;
                           case 3:
                               connect(this,&MainWindow::signCurrUsers4,mess[3],&MessageBox::writeCurrUser);
                               connect(this,&MainWindow::signUsers4,mess[3],&MessageBox::objUsers);
                               connect(mess[3],&MessageBox::signSendMess,this,&MainWindow::addRecvMess);
                               connect(mess[3],&MessageBox::signZapros,this,&MainWindow::zaprosBase);
                               connect(this,&MainWindow::signOtwet,mess[3],&MessageBox::slotOtwet);
                               connect (mess[3],&MessageBox::signShowStartWin,this,&MainWindow::showStartWin);
                               emit signCurrUsers4(currUser);
                               isObjects[3]=true;
                               Logins[3]=currUser;
                               break;
                            case 5:
                                connect(this,&MainWindow::signCurrUsers5,mess[4],&MessageBox::writeCurrUser);
                                connect(this,&MainWindow::signUsers5,mess[4],&MessageBox::objUsers);
                                connect(mess[4],&MessageBox::signSendMess,this,&MainWindow::addRecvMess);
                                connect(mess[4],&MessageBox::signZapros,this,&MainWindow::zaprosBase);
                                connect(this,&MainWindow::signOtwet,mess[4],&MessageBox::slotOtwet);
                                connect (mess[4],&MessageBox::signShowStartWin,this,&MainWindow::showStartWin);
                                emit signCurrUsers5(currUser);
                                isObjects[4]=true;
                                Logins[4]=currUser;
                                break;
                     }
                     mess[i]->show();
                     QMessageBox::information(this,"Ура","Вы успешно авторизовались");
                     isAuto =true;
                }

            }
          if(!isAuto)
                {
                    QMessageBox::warning(this,"авторизация ","Вы  не зарегестрированы");
                    i--;
                }
          ui->lineEditLogin->setText("");
          ui->lineEditPassword->setText("");
}
//==============================================================================================================
void MainWindow::on_pushButtonRegistration_clicked()//кнопка регистрации
{
        hide();
        reg->show();
}

void MainWindow::addLogPass(QString qLogin,QString qPassword) //занесение логина и пароля в структуру данных
{
    convertQstToStr(qLogin,qPassword);
    auto it = pSt->_log_pass.find(pSt->login);
    if (it != pSt->_log_pass.end())
    {
        QMessageBox::warning(this,"Регистрация ","Такой Логин уже есть. Выберите другой");
        return;
    }

         pSt->_log_pass.emplace(pSt->login, pSt->password);
         QMessageBox::information(this,"Регистрация ","Регитрация прошла успешно");
}
//=======================Приемник сообщения (слот) от формы =========================
void MainWindow::addRecvMess(string *txtRecvMess)
{
   std::string tempOwn = txtRecvMess[0];
   std::string tempReciver = txtRecvMess[1];
   std::string tempMessage = txtRecvMess[2];
   std::string tTempOwn,tTempReciver,tTempMessage;
//-----------------------------------------------------------------------------------
   for (auto it = pSt->_log_pass.begin(); it !=pSt-> _log_pass.end(); ++it)//проверка получателя сообщения
           {
               if (!(tempReciver.compare(it->first)))
               {
                   for (int i = 0; i < maxMess; ++i)
                   {
                       if (!Null.compare(pSt->_messages[i].getOwn()))
                       {
                           pSt->_messages[i].setOwn(tempOwn);
                           pSt->_messages[i].setReceiver(tempReciver);
                           pSt->_messages[i].setMessage(tempMessage);
                           break;
                       }
                   }
               }
   }
   tTempOwn=pSt->_messages[i].getOwn();
   tTempReciver=pSt->_messages[i].getReceiver();
   tTempMessage=pSt->_messages[i].getMessage();
}

void MainWindow::zaprosBase(int *id, string *ownRecv)
{
    std::string tempOwn = ownRecv[0];
    std::string tempReciver = ownRecv[1];
    std::string tempMessage = ownRecv[2];
    std::string tTemp;

    for (auto it = pSt->_log_pass.begin(); it !=pSt-> _log_pass.end(); ++it)//проверка получателя сообщения
            {
                if (!(tempReciver.compare(it->first)))
                {
                    for (int i = 0; i < maxMess; ++i)
                    {
                        tTemp = pSt->_messages[i].getOwn();
                        if (!Null.compare(pSt->_messages[i].getOwn()))
                        {
                            if(i==0){break;}
                            else
                           {

                                if ((curIdReady+1)==i){ break;}
                                if (curIdReady<i)
                             {
                                ownRecv[0]=pSt->_messages[i-1].getOwn();
                                ownRecv[1]=pSt->_messages[i-1].getReceiver();
                                ownRecv[2]=pSt->_messages[i-1].getMessage();
                                emit signOtwet(id,ownRecv);
                                curIdReady=i;
                                break;
                             }
                           }
                        }
                    }
                }
    }



}

void MainWindow::showStartWin()
{
  show();//показать текущий обьект
}
//===================================================================================
int MainWindow::InstedMain::createNullMap()//Создание пустых сообщений в структуре данных
{
    int size;
    Log_pass* pSt = new Log_pass;
    Log_pass& st = *pSt;
    for (int i = 0; i < maxMess; ++i) {
            Messages* pMess = new Messages;
            Messages& mess = *pMess; //преобразование указателя в ссылку
            size=st.AddScore(i, mess);
    }
    return size;
}

MainWindow::InstedMain::InstedMain()  // псевдо main функция
{
   int sizeMess = createNullMap();
}
int MainWindow::Log_pass::AddScore(int idNumber, Messages score)// добавление сообщений в структуру данных
{
        auto it = _messages.find(idNumber);
        if (it != _messages.end())
        {
            score = it->second;
        }
        else
            _messages.emplace(idNumber, score);
        return _messages.size();
}

MainWindow::Log_pass::Log_pass()
{
    //конструктор по умолчанию
}
//===============================Методы сообщения=========================================
MainWindow::Messages::Messages()
{
        this->own = "Null";
        this->receiver = "Null";
        ptrMess = this;
}

string MainWindow::Messages::getOwn()
{
    return this->own;
}

string MainWindow::Messages::getReceiver()
{
    return this->receiver;
}

string MainWindow::Messages::getMessage()
{
    return this->message;
}

MainWindow::Messages *MainWindow::Messages::getPtrMess()
{
    return this->ptrMess;
}

void MainWindow::Messages::setOwn(string _own)
{
    this->own = _own;
}

void MainWindow::Messages::setReceiver(string _received)
{
    this->receiver = _received;
}

void MainWindow::Messages::setMessage(string _message)
{
    this->message = _message;
}


