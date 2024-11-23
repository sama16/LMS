#ifndef USERPANEL_H
#define USERPANEL_H

#include <QWidget>

class UserPanel : public QWidget {
    Q_OBJECT

public:
    explicit UserPanel(QWidget *parent = nullptr);

signals:
    void loginRequested();
    void registerRequested();

private slots:
    void handleLoginClicked();
    void handleRegisterClicked();

private:
         // Add UI elements here, e.g., buttons
};

#endif // USERPANEL_H
