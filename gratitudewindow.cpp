#include "gratitudewindow.h"
#include "ui_gratitudewindow.h"
#include "wellnesswindow.h"
#include <QMessageBox>
#include <QDebug>

GratitudeWindow::GratitudeWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GratitudeWindow)
{
    ui->setupUi(this);
}

GratitudeWindow::~GratitudeWindow()
{
    delete ui;
}

void GratitudeWindow::on_exitButton_clicked()
{
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Title");
    msgBox.setText("Are you sure you want to quit?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setStyleSheet(
        "QMessageBox { background-color: white; color: black; }"
        "QPushButton { background-color: white; color: black; }"
        );
    if (msgBox.exec() == QMessageBox::Yes) {
        QApplication::quit();
    } else {
        qDebug() << "Button is not pushed";
    }
}


void GratitudeWindow::on_backToMenuButton_clicked()
{
    WellnessWindow *wellness = new WellnessWindow();
    wellness->show();
}


