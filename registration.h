#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>


namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();
signals:
    void showWindow();
    void sign_addLogPass(QString qLogin,QString qPassword);
private slots:
    void on_PushButtonOK_clicked();
    void on_pushButtonCancel_clicked();

private:
    Ui::Registration *ui;
};

#endif // REGISTRATION_H
