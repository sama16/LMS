#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    // Instantiate views
    welcomeView = new WelcomeView(this);
    loginView = new LoginView(this);
    adminView = new AdminView(this);
    userPanel = new UserPanel(this);
    userView = new UserView(this);

    // Add all views to the stacked widget
    stackedWidget->addWidget(welcomeView);
    stackedWidget->addWidget(loginView);
    stackedWidget->addWidget(adminView);
    stackedWidget->addWidget(userPanel);
    stackedWidget->addWidget(userView);

    // Connect signals for navigation
    connect(welcomeView, &WelcomeView::adminRequested, this, &MainWindow::showAdminPanel);
    connect(welcomeView, &WelcomeView::userRequested, this, &MainWindow::showUserPanel);
    connect(loginView, &LoginView::loginSuccessful, this, &MainWindow::loginSuccessful);

    // Connect user panel signals to slots
    connect(userPanel, &UserPanel::loginRequested, this, &MainWindow::handleUserLogin);
    connect(userPanel, &UserPanel::registerRequested, this, &MainWindow::handleUserRegistration);
}

MainWindow::~MainWindow() {
    // Cleanup if necessary
}

void MainWindow::showAdminPanel() {
    stackedWidget->setCurrentWidget(loginView);
}

void MainWindow::loginSuccessful() {
    stackedWidget->setCurrentWidget(adminView);
}

void MainWindow::showUserPanel() {
    stackedWidget->setCurrentWidget(userPanel); // Show the user panel
}

void MainWindow::handleUserLogin() {
    LoginDialog loginDialog(this); // Assume you have a LoginDialog class
    if (loginDialog.exec() == QDialog::Accepted) {
        stackedWidget->setCurrentWidget(userView); // Show user view on successful login
    }
}

void MainWindow::handleUserRegistration() {
    RegisterDialog registerDialog(this); // Assume you have a RegisterDialog class
    if (registerDialog.exec() == QDialog::Accepted) {
        stackedWidget->setCurrentWidget(userView); // Show user view on successful registration
    }
}
