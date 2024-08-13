#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "habitswindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QDebug>

MenuWindow::MenuWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/img/mindfulness_img.png");
    ui->image->setPixmap(pix);
}

MenuWindow::~MenuWindow()
{
    delete ui;
}


void MenuWindow::on_exitButton_clicked()
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

void MenuWindow::on_habitsButton_clicked()
{
    hide();
    habit = new HabitsWindow(this);
    habit->show();
}


void MenuWindow::on_todayPlansButton_clicked()
{
    hide();
    plan = new PlansWindow(this);
    plan->show();
}

void MenuWindow::on_quotesButton_clicked()
{
    hide();
    quotes = new QuotesWindow(this);
    quotes->show();
}


void MenuWindow::on_wellnessPracticeButton_clicked()
{
    hide();
    wellness = new WellnessWindow(this);
    wellness->show();
}

