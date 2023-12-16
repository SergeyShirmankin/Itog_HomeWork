//#include "log_pass.h"
//#include "MapMess.h"
//#include "RunLogPass.h"
//#include <iostream>
//#include <QDebug>
//#include "mainwindow.h"
//std::string currUser = "Null";
//int resultCompFindUser;
//int resultCompFindReceiver;
//int convIngTempRec;
//std::string tempReceiver;
//std::string tempMessage;
//std::string tempCin;
//std::string Null = "Null";



//Log_pass::Log_pass()//конструктор по умолчанию
//{
//   int a = 1; // пустая операция, чтобы не было ошибок
////connect(reg,&Registration::sign_addLogPass,this,&Log_pass::addLogPass(QString qLogin, QString qPassword))
// //connect (this,SIGNAL(test1()),this,SLOT(test2()));
// //connect (this,SIGNAL(test1()),this,SLOT(addLogPass(QString qLogin, QString qPassword)));
//  //connect (reg,SIGNAL(test1()),this,SLOT(addLogPass(QString qLogin, QString qPassword)));
//}

//Log_pass::~Log_pass()
//{
//    int b = 2;
//}

//void Log_pass::convertQstToStr(QString &qLogin, QString &qPassword)
//{
//    login=qLogin.toStdString();
//    password=qPassword.toStdString();
//    qDebug()<<"convert";
//}



//void Log_pass::test2()
//{
////fgdsfargfd;
//}

//int Log_pass::addLogPass(QString qLogin, QString qPassword)
//{
//    convertQstToStr(qLogin,qPassword);
//    return 0;
//}


//  std::cout << " Введите логин нового пользователя: " << std::endl;
//	std::cout << ">> ";
//	std::cin >> login;//Вводим новый логин
//	auto it = _log_pass.find(login);
//	if (it != _log_pass.end())
//	{
//		std::cout << std::endl;
//		std::cout << ">> Логин уже есть. Выберите другой" << std::endl;
//	}
//	else
//	{
//		std::cout << "Введите нового пароля: " << std::endl;
//		std::cout << ">> ";
//		std::cin >> password;
//		_log_pass.emplace(login, password);
//	}
//	       	countObject++;
    //	return _log_pass.size();


//int Log_pass::AddScore(int idNumber, Messages score)
//{
//    auto it = _messages.find(idNumber);
//    if (it != _messages.end())
//    {
//        score = it->second;
//    }
//    else
//        _messages.emplace(idNumber, score);
//    return _messages.size();
//}

