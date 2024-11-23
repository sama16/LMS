// logindialog.cpp
#include "logindialog.h"
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent) {
    auto* layout = new QVBoxLayout(this);

    auto* usernameEdit = new QLineEdit(this);
    auto* passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);

    auto* loginButton = new QPushButton("Login", this);

    layout->addWidget(usernameEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(loginButton);

    connect(loginButton, &QPushButton::clicked, this, &LoginDialog::handleLoginClicked);
}

void LoginDialog::handleLoginClicked() {
    // Validate user credentials and emit accepted() if successful
    accept();
}
