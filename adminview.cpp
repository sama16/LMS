#include "adminview.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

AdminView::AdminView(QWidget *parent) : QWidget(parent) {
    setupUI();
    loadBooks();  // Load books when initializing
    loadUsers();  // Load users when initializing
     loadSeminars();
}

AdminView::~AdminView() {
    saveBooks();  // Save books when destroying
    saveUsers();  // Save users when destroying
    saveSeminars();
}

void AdminView::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Book management
    QLabel *bookLabel = new QLabel("Manage Books", this);
    layout->addWidget(bookLabel);

    bookTitleInput = new QLineEdit(this);
    bookTitleInput->setPlaceholderText("Enter Book Title");
    layout->addWidget(bookTitleInput);

    bookAuthorInput = new QLineEdit(this);
    bookAuthorInput->setPlaceholderText("Enter Author Name");
    layout->addWidget(bookAuthorInput);

    // Buttons for adding, editing, and deleting
    QPushButton *addButton = new QPushButton("Add Book", this);
    connect(addButton, &QPushButton::clicked, this, &AdminView::addBook);
    layout->addWidget(addButton);

    QPushButton *editButton = new QPushButton("Edit Book", this);
    connect(editButton, &QPushButton::clicked, this, &AdminView::editBook);
    layout->addWidget(editButton);

    QPushButton *deleteButton = new QPushButton("Delete Book", this);
    connect(deleteButton, &QPushButton::clicked, this, &AdminView::deleteBook);
    layout->addWidget(deleteButton);

    // User management
    QLabel *userLabel = new QLabel("Manage Users", this);
    layout->addWidget(userLabel);

    userInput = new QLineEdit(this);
    userInput->setPlaceholderText("Enter Username");
    layout->addWidget(userInput);

    QPushButton *addUserButton = new QPushButton("Add User", this);
    connect(addUserButton, &QPushButton::clicked, this, &AdminView::addUser);
    layout->addWidget(addUserButton);

    QPushButton *deleteUserButton = new QPushButton("Delete User", this);
    connect(deleteUserButton, &QPushButton::clicked, this, &AdminView::deleteUser);
    layout->addWidget(deleteUserButton);
    // Seminar management
    QLabel *seminarLabel = new QLabel("Manage Seminars", this);
    layout->addWidget(seminarLabel);

    seminarTitleInput = new QLineEdit(this);
    seminarTitleInput->setPlaceholderText("Enter Seminar Title");
    layout->addWidget(seminarTitleInput);

    seminarDateInput = new QLineEdit(this);
    seminarDateInput->setPlaceholderText("Enter Seminar Date");
    layout->addWidget(seminarDateInput);

    QPushButton *addSeminarButton = new QPushButton("Add Seminar", this);
    connect(addSeminarButton, &QPushButton::clicked, this, &AdminView::addSeminar);
    layout->addWidget(addSeminarButton);

    QPushButton *editSeminarButton = new QPushButton("Edit Seminar", this);
    connect(editSeminarButton, &QPushButton::clicked, this, &AdminView::editSeminar);
    layout->addWidget(editSeminarButton);

    QPushButton *deleteSeminarButton = new QPushButton("Delete Seminar", this);
    connect(deleteSeminarButton, &QPushButton::clicked, this, &AdminView::deleteSeminar);
    layout->addWidget(deleteSeminarButton);
}



void AdminView::loadBooks() {
    QFile file("C:/Users/hp/Documents/LibraryManagementSystem/bookList.txt"); // Path to your books file
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open books file.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        bookList.append(line);
    }

    file.close();
}

void AdminView::saveBooks() {
    QFile file("C:/Users/hp/Documents/LibraryManagementSystem/bookList.txt"); // Path to your books file
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open books file for writing.");
        return;
    }

    QTextStream out(&file);
    for (const QString &book : bookList) {
        out << book << "\n"; // Write each book on a new line
    }

    file.close();
}

void AdminView::loadUsers() {
    QFile file("C:/Users/hp/Documents/LibraryManagementSystem/users.txt"); // Path to your users file
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open users file.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        userList.append(line);
    }

    file.close();
}

void AdminView::saveUsers() {
    QFile file("C:/Users/hp/Documents/LibraryManagementSystem/users.txt"); // Path to your users file
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open users file for writing.");
        return;
    }

    QTextStream out(&file);
    for (const QString &user : userList) {
        out << user << "\n"; // Write each user on a new line
    }

    file.close();
}

void AdminView::addBook() {
    QString title = bookTitleInput->text();
    QString author = bookAuthorInput->text();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a book title.");
        return;
    }

    bookList.append(title + (author.isEmpty() ? "" : " by " + author));
    saveBooks(); // Save the updated list after adding
    QMessageBox::information(this, "Add Book", "Book added: " + title + (author.isEmpty() ? "" : " by " + author));
    bookTitleInput->clear();
    bookAuthorInput->clear(); // Clear input fields after adding
}

void AdminView::editBook() {
    QString title = bookTitleInput->text();
    QString author = bookAuthorInput->text();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a book title to edit.");
        return;
    }

    bool bookFound = false;
    for (int i = 0; i < bookList.size(); ++i) {
        if (bookList[i].startsWith(title)) {
            bookList[i] = title + (author.isEmpty() ? "" : " by " + author);
            bookFound = true;
            saveBooks(); // Save the updated list after editing
            QMessageBox::information(this, "Edit Book", "Book updated: " + bookList[i]);
            break;
        }
    }

    if (!bookFound) {
        QMessageBox::warning(this, "Edit Error", "Book not found.");
    }
    bookTitleInput->clear();
    bookAuthorInput->clear(); // Clear input fields after editing
}

void AdminView::deleteBook() {
    QString title = bookTitleInput->text();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a book title to delete.");
        return;
    }

    bool bookFound = false;
    for (int i = 0; i < bookList.size(); ++i) {
        if (bookList[i].startsWith(title)) {
            bookList.removeAt(i);
            bookFound = true;
            saveBooks(); // Save the updated list after deleting
            QMessageBox::information(this, "Delete Book", "Book deleted: " + title);
            break;
        }
    }

    if (!bookFound) {
        QMessageBox::warning(this, "Delete Error", "Book not found.");
    }
    bookTitleInput->clear(); // Clear input field after deleting
}

void AdminView::addUser() {
    QString username = userInput->text();

    if (username.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a username to add.");
        return;
    }

    // Check if user already exists
    if (userList.contains(username)) {
        QMessageBox::warning(this, "Add User Error", "User already exists.");
        return;
    }

    userList.append(username);
    saveUsers(); // Save the updated user list after adding
    QMessageBox::information(this, "Add User", "User added: " + username);
    userInput->clear(); // Clear input field after adding
}

void AdminView::deleteUser() {
    QString username = userInput->text();

    if (username.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a username to delete.");
        return;
    }

    bool userFound = false;
    for (int i = 0; i < userList.size(); ++i) {
        if (userList[i] == username) {
            userList.removeAt(i);
            userFound = true;
            saveUsers(); // Save the updated user list after deleting
            QMessageBox::information(this, "Delete User", "User deleted: " + username);
            break;
        }
    }

    if (!userFound) {
        QMessageBox::warning(this, "Delete Error", "User not found.");
    }
    userInput->clear(); // Clear input field after deleting
}

void AdminView::manageUsers() {
    QString username = userInput->text(); // Ensure userInput is initialized

    // Here, add logic to manage user accounts (e.g., add or remove users)
    QMessageBox::information(this, "Manage User", "User action on: " + username);
}
void AdminView::loadSeminars() {
    QFile file("C:/Users/hp/Documents/LibraryManagementSystem/seminar.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open seminars file.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        seminarList.append(line);
    }

    file.close();
}

void AdminView::saveSeminars() {
    QFile file("C:/Users/hp/Documents/LibraryManagementSystem/seminar.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open seminars file for writing.");
        return;
    }

    QTextStream out(&file);
    for (const QString &seminar : seminarList) {
        out << seminar << "\n"; // Write each seminar on a new line
    }

    file.close();
}

void AdminView::addSeminar() {
    QString title = seminarTitleInput->text();
    QString date = seminarDateInput->text();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a seminar title.");
        return;
    }

    seminarList.append(title + " on " + date);
    saveSeminars(); // Save the updated list after adding
    QMessageBox::information(this, "Add Seminar", "Seminar added: " + title);
    seminarTitleInput->clear();
    seminarDateInput->clear(); // Clear input fields after adding
}

void AdminView::editSeminar() {
    QString title = seminarTitleInput->text();
    QString date = seminarDateInput->text();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a seminar title to edit.");
        return;
    }

    bool seminarFound = false;
    for (int i = 0; i < seminarList.size(); ++i) {
        if (seminarList[i].startsWith(title)) {
            seminarList[i] = title + " on " + date;
            seminarFound = true;
            saveSeminars(); // Save the updated list after editing
            QMessageBox::information(this, "Edit Seminar", "Seminar updated: " + seminarList[i]);
            break;
        }
    }

    if (!seminarFound) {
        QMessageBox::warning(this, "Edit Error", "Seminar not found.");
    }
    seminarTitleInput->clear();
    seminarDateInput->clear(); // Clear input fields after editing
}

void AdminView::deleteSeminar() {
    QString title = seminarTitleInput->text();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a seminar title to delete.");
        return;
    }

    bool seminarFound = false;
    for (int i = 0; i < seminarList.size(); ++i) {
        if (seminarList[i].startsWith(title)) {
            seminarList.removeAt(i);
            seminarFound = true;
            saveSeminars(); // Save the updated list after deleting
            QMessageBox::information(this, "Delete Seminar", "Seminar deleted: " + title);
            break;
        }
    }

    if (!seminarFound) {
        QMessageBox::warning(this, "Delete Error", "Seminar not found.");
    }
    seminarTitleInput->clear(); // Clear input field after deleting
}
