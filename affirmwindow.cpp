#include "affirmwindow.h"
#include "ui_affirmwindow.h"
#include "wellnesswindow.h"
#include <QMessageBox>
#include <QDebug>

AffirmWindow::AffirmWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AffirmWindow)
{
    ui->setupUi(this);
}

AffirmWindow::~AffirmWindow()
{
    delete ui;
}

void AffirmWindow::on_exitButton_clicked()
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


void AffirmWindow::on_backToMenuButton_clicked()
{
    hide();
    WellnessWindow *wellness = new WellnessWindow();
    wellness->show();
}

