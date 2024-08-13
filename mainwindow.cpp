#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/img/logo.png");
    int width = ui->logo->width();
    int height = ui->logo->height();

    ui->logo->setPixmap(pix.scaled(width,height, Qt::KeepAspectRatio));
    ui->menuButton->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_authoriseButton_clicked()
{
    QString login = ui->login->text();
    QString password = ui->password->text();
    if(login == "Polina Zabrudska" && password == "136"){
        ui->statusbar->showMessage("Success, you are authorised now!");
        ui->menuButton->show();
    } else {
        ui->statusbar->showMessage("The authorization is not successful");
    }
}



void MainWindow::on_exitButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Title", "Are you sure you want to quit?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    } else {
        qDebug() << "Button is not pushed";
    }
}

void MainWindow::on_menuButton_clicked()
{
    hide();
    window = new MenuWindow(this);
    window->show();
}

