#ifndef HABITSWINDOW_H
#define HABITSWINDOW_H

#include <QDialog>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include "menuwindow.h"

namespace Ui {
class HabitsWindow;
}

class HabitsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HabitsWindow(QWidget *parent = nullptr);
    ~HabitsWindow();

private slots:
    void on_backToMenuButton_clicked();

    void on_exitButton_clicked();

    void addHabit();

    void removeHabitByName();

    void on_addHabitButton_clicked();

    void on_deleteHabitButton_clicked();

private:
    Ui::HabitsWindow *ui;
    QGridLayout *habitLayout;
    QLineEdit *lineHabitEdit;

};

#endif // HABITSWINDOW_H
