#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "welcomeview.h"
#include "loginview.h"
#include "adminview.h"
#include "userpanel.h"  // Include UserPanel
#include "userview.h"   // Include UserView
#include "logindialog.h" // Include LoginDialog
#include "registerdialog.h" // Include RegisterDialog

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showAdminPanel();
    void loginSuccessful();
    void showUserPanel();        // Slot to show the user panel
    void handleUserLogin();      // Slot to handle user login
    void handleUserRegistration(); // Slot to handle user registration

private:
    QStackedWidget *stackedWidget;
    WelcomeView *welcomeView;
    LoginView *loginView;
    AdminView *adminView;
    UserPanel *userPanel;       // UserPanel instance
    UserView *userView;         // UserView instance
};

#endif // MAINWINDOW_H
