#include "userpanel.h"
#include <QPushButton>
#include <QVBoxLayout>

UserPanel::UserPanel(QWidget *parent) : QWidget(parent) {
    auto* layout = new QVBoxLayout(this);

    auto* loginButton = new QPushButton("Login", this);
    auto* registerButton = new QPushButton("Register", this);

    layout->addWidget(loginButton);
    layout->addWidget(registerButton);

    connect(loginButton, &QPushButton::clicked, this, &UserPanel::handleLoginClicked);
    connect(registerButton, &QPushButton::clicked, this, &UserPanel::handleRegisterClicked);
}

void UserPanel::handleLoginClicked() {
    emit loginRequested();
}

void UserPanel::handleRegisterClicked() {
    emit registerRequested();
}

