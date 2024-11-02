#include "mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    welcomeView = new WelcomeView(this);
    loginView = new LoginView(this);
    adminView = new AdminView(this);


    stackedWidget->addWidget(welcomeView);
        stackedWidget->addWidget(loginView);
    stackedWidget->addWidget(adminView);
    connect(welcomeView, &WelcomeView::adminRequested, this, &MainWindow::showAdminPanel);

    connect(loginView, &LoginView::loginSuccessful, this, &MainWindow::loginSuccessful);



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
