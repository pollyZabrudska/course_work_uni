#include "habitswindow.h"
#include "ui_habitswindow.h"
#include "menuwindow.h"
#include <QMessageBox>
#include <QDebug>

HabitsWindow::HabitsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HabitsWindow)
{
    ui->setupUi(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    habitLayout = findChild<QGridLayout*>("habitLayout");
    lineHabitEdit = findChild<QLineEdit*>("lineHabitEdit");
    QPushButton *addHabitButton = findChild<QPushButton*>("addHabitButton");
    connect(lineHabitEdit, &QLineEdit::returnPressed, this, &HabitsWindow::removeHabitByName);
}

HabitsWindow::~HabitsWindow()
{
    delete ui;
}

void HabitsWindow::on_backToMenuButton_clicked()
{
    MenuWindow *menuWindow = new MenuWindow();
    menuWindow->show();
}


void HabitsWindow::on_exitButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Title", "Are you sure you want to quit?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    } else {
        qDebug() << "Button is not pushed";
    }
}

void HabitsWindow::addHabit() {
    QString habitName = lineHabitEdit->text();

    QWidget *habitWidget = new QWidget();
    QVBoxLayout *habitWidgetLayout = new QVBoxLayout();
    QHBoxLayout *rowLayout;

    habitWidgetLayout->addWidget(new QLabel(habitName));

    for(int i = 0; i < 21; ++i) {
        if(i % 7 == 0) {
            rowLayout = new QHBoxLayout();
            habitWidgetLayout->addLayout(rowLayout);
        }
        QCheckBox *checkbox = new QCheckBox();
        rowLayout->addWidget(checkbox);
    }

    habitWidget->setLayout(habitWidgetLayout);
    habitLayout->addWidget(habitWidget);
}


void HabitsWindow::on_addHabitButton_clicked()
{
    addHabit();
    ui->lineHabitEdit->clear();
}

void HabitsWindow::removeHabitByName() {
    QString habitNameToRemove = lineHabitEdit->text();

    for (int i = 0; i < habitLayout->count(); ++i) {
        QWidget *habitWidget = habitLayout->itemAt(i)->widget();
        QLabel *habitLabel = habitWidget->findChild<QLabel*>();
        if (habitLabel && habitLabel->text() == habitNameToRemove) {
            habitLayout->removeWidget(habitWidget);
            delete habitWidget;
            return;
        }
    }
}


void HabitsWindow::on_deleteHabitButton_clicked()
{
    removeHabitByName();
    ui->lineHabitEdit->clear();
}

