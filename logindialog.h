#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = nullptr);
    ~loginDialog();
    void InitUi();

private slots:

    void on_loginBtn_clicked();

    void on_quitBtn_clicked();

private:
    Ui::loginDialog *ui;
};

#endif // LOGINDIALOG_H
