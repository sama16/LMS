// registerdialog.h
#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>

class RegisterDialog : public QDialog {
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);

private slots:
    void handleRegisterClicked();

private:
         // Add UI elements for the registration dialog
};

#endif // REGISTERDIALOG_H
