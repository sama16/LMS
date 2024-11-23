// userview.h
#ifndef USERVIEW_H
#define USERVIEW_H

#include <QWidget>

class UserView : public QWidget {
    Q_OBJECT

public:
    explicit UserView(QWidget *parent = nullptr);
};

#endif // USERVIEW_H
