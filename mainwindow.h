#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "registration.h"
#include <iostream>
#include <string>
#include <map>
#include <QApplication>
#include "Messages.h"
#include <QDialog>
#include "messagebox.h"
#include <QTimer>

using namespace std;
const int maxNumUsers = 5 ;//максимальное количество обьектов которые можно создать
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void showObject();
    void TimerSlot();
private slots:
    void on_pushButtonCancel_clicked();
    void on_pushButtonAutorization_clicked();
    void on_pushButtonRegistration_clicked();
private:
    Ui::MainWindow *ui;
    Registration *reg;
    MessageBox *mess[maxNumUsers];
    QTimer *timer;
public:
 //=======================================================================================
    class InstedMain
    {
       public:
        int sizeMap;
         int sizePassLog = 0;
         int countObject = 0; // количество созданых обьектов или количество элементов в массиве
         int countMessage = 0;//порядковый номер сообщения
         char* op;//запись символа операции
         const int maxPerson = maxNumUsers;//максимальное количество людей которое можно работать в чате
         const int maxMess = 100;//максимальное количество сообщений в чате
         std::string tempOP;
         InstedMain (); //Конструктор
         int createNullMap();
    };
//===============================================================================
    class Messages
    {
    public:
        Messages();
        std::string getOwn();
        std::string getReceiver();
        std::string getMessage();
        Messages* getPtrMess();
        void setOwn(std::string);
        void setReceiver(std::string);
        void setMessage(std::string);
        int resultCompFindUser;
    private:
        std::string own;//владелец сообщения
        std::string receiver;//получатель сообщения
        std::string message;//сообщения
        Messages* ptrMess;//указатель на сообщение;
    };
 //=================================================================================
        class Log_pass
        {
        public:
            int AddScore(int idNumber, Messages score);
            Log_pass();//Конструктор по умолчанию
            ~Log_pass();//деструктор
            std::string getLog();//геттеры
            std::string getPass();
            Log_pass* getPtrObject();
            bool enterLogPass();
            void showMessages();
            void printLogPass();

            Log_pass* ptrObject;// Указатель на обьект
                std::string login;//поле логина
                std::string password;// поле пароля
                std::map<string,string> _log_pass;
                std::map<int, Messages> _messages;
                QString qlog_pass;

        };

//---------------на каждого окна с соощениями по сигналу----------------------------
signals:
        void signCurrUsers1(std::string textCurrUser);
        void signCurrUsers2(std::string textCurrUser);
        void signCurrUsers3(std::string textCurrUser);
        void signCurrUsers4(std::string textCurrUser);
        void signCurrUsers5(std::string textCurrUser);
        void signUsers1(std::string* textUsers,bool*);
        void signUsers2(std::string* textUsers,bool*);
        void signUsers3(std::string* textUsers,bool*);
        void signUsers4(std::string* textUsers,bool*);
        void signUsers5(std::string* textUsers,bool*);
        void signOtwet(int* ,std::string*);//ответ  с базы данных

//==================================================================================
public:
    const int maxMess = 100;
    int curIdReady =-1;
    std::string Null ="Null";//Нулевой владалец
    std::string currUser;
    std::string* objUsers= new std::string[maxNumUsers+1];
    std::string* Logins= new std::string[maxNumUsers+1];
    int curSession;//активная сессия
    int i=-1;
    InstedMain *instedMain = new InstedMain;
    Log_pass* pSt = new Log_pass;// Создаем обьект логина и пароля
    Messages* ptrMess = new Messages;
    void convertQstToStr(QString &qLogin, QString &qPassword);
    bool* isObjects=new bool[maxNumUsers]{};//массив наличия обьекта (окна сообщения)
    void initisObject();//инициализация массива наличия обьектов
public slots:
     void addLogPass(QString qLogin,QString qPassword);//добавить логин и пароль
     void addRecvMess(std::string* txtRecvMess);
     void zaprosBase(int* id,std::string* ownRecv);
     void showStartWin();
};
#endif // MAINWINDOW_H
