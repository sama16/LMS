#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "adminview.h"
#include "welcomeview.h"
#include "loginview.h"


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showAdminPanel();
    void loginSuccessful();

private:
    QStackedWidget *stackedWidget;
    AdminView *adminView;
    WelcomeView *welcomeView;
    LoginView *loginView;

};

#endif // MAINWINDOW_H
