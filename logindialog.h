// logindialog.h
#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

class LoginDialog : public QDialog {
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);

private slots:
    void handleLoginClicked();

private:
         // Add UI elements for the login dialog
};

#endif // LOGINDIALOG_H
