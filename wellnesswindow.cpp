#include "wellnesswindow.h"
#include "ui_wellnesswindow.h"
#include "menuwindow.h"
#include "gratitudewindow.h"
#include "affirmwindow.h"
#include <QMessageBox>
#include <QDebug>

WellnessWindow::WellnessWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WellnessWindow)
{
    ui->setupUi(this);
    this->setStyleSheet(
        "QWidget {"
        "background: qradialgradient (spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.495, fy:0.5, stop:0.185366 rgba(255, 181, 181, 255), stop:0.639024 rgba(226, 199, 216, 255), stop:1 rgba(207, 255, 206, 255));"
        "}"
        );
}

WellnessWindow::~WellnessWindow()
{
    delete ui;
}

void WellnessWindow::on_backToMenuButton_clicked()
{
    hide();
    MenuWindow *menuWindow = new MenuWindow();
    menuWindow->show();
}


void WellnessWindow::on_exitButton_clicked()
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

void WellnessWindow::on_gratitudeButton_clicked()
{
    hide();
    gratitude = new GratitudeWindow(this);
    gratitude->show();
}


void WellnessWindow::on_positiveButton_clicked()
{
    hide();
    positive = new PositiveWindow(this);
    positive->show();
}


void WellnessWindow::on_affirmationsButton_clicked()
{
    hide();
    affirm = new AffirmWindow(this);
    affirm->show();
}

