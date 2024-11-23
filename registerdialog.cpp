// registerdialog.cpp
#include "registerdialog.h"
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

RegisterDialog::RegisterDialog(QWidget *parent) : QDialog(parent) {
    auto* layout = new QVBoxLayout(this);

    auto* usernameEdit = new QLineEdit(this);
    auto* emailEdit = new QLineEdit(this);
    auto* passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);

    auto* registerButton = new QPushButton("Register", this);

    layout->addWidget(usernameEdit);
    layout->addWidget(emailEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(registerButton);

    connect(registerButton, &QPushButton::clicked, this, &RegisterDialog::handleRegisterClicked);
}

void RegisterDialog::handleRegisterClicked() {
    // Validate and register the user, then emit accepted() if successful
    accept();
}
