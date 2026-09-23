#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Libraly.db");

    if (db.open()){
        qDebug() << "база даних успішно підключена";

        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS Books ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT,  "
                   "title TEXT NOT NULL, "
                   "author TEXT NOT NULL, "
                   "year INTEGER)");

        qDebug() << "таблиці" << db.tables();
    } else {
        qDebug() << "помилка підключення бази даних" << db.lastError().text();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
