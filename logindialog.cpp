#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QPushButton>
#include <QString>

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
    InitUi();
}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::InitUi()
{
    ui->pwdlineEdit->setEchoMode(QLineEdit::Password);
}

void loginDialog::on_loginBtn_clicked()
{
    if(!QString::compare(ui->userNamelineEdit->text().trimmed(),tr("QT"),Qt::CaseInsensitive) && ui->pwdlineEdit->text().trimmed() == tr("123456"))
    {
        this->accept();
    }
    else
    {
        QMessageBox *box = new QMessageBox(this);
        box->setIcon(QMessageBox::Warning);
        box->setWindowTitle(tr("警告"));
        box->setText(tr("您的输入有错误!"));
        QPushButton* ok = new QPushButton(this);
        ok = box->addButton(tr("确定"),QMessageBox::AcceptRole);
        box->exec();

        ui->userNamelineEdit->clear();
        ui->pwdlineEdit->clear();
        ui->userNamelineEdit->setFocus();
    }
}

void loginDialog::on_quitBtn_clicked()
{
    this->close();
}
