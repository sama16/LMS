#ifndef USERVIEW_H
#define USERVIEW_H

#include <QWidget>
#include <QString>
#include <QStringList>
#include <QLineEdit>
#include <QVector>
#include <QMap>

class UserView : public QWidget {
    Q_OBJECT

public:
    explicit UserView(QWidget *parent = nullptr);
    ~UserView();

private:
    void setupUI();
    void loadBooks();
    void loadUserData();
    void loadSeminars();
    void saveFeedback();

    // Book-related data and functions
    QLineEdit *searchInput;
    QStringList availableBooks; // List of books
    QMap<QString, QString> borrowedBooks; // Book title -> due date
    void searchBooks();
    void borrowBook();

    // Seminar-related data and functions
    QStringList seminarList; // Seminar details
    void registerForSeminar();
    void submitFeedback();

    // History
    QStringList borrowingHistory; // Track borrowing details
    void viewHistory();
};

#endif // USERVIEW_H
