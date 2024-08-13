#ifndef MENUWINDOW_H
#define MENUWINDOW_H
#include "planswindow.h"
#include "quoteswindow.h"
#include "wellnesswindow.h"
#include <QDialog>

class HabitsWindow;

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

private slots:
    void on_exitButton_clicked();

    void on_habitsButton_clicked();

    void on_todayPlansButton_clicked();

    void on_quotesButton_clicked();

    void on_wellnessPracticeButton_clicked();

private:
    Ui::MenuWindow *ui;
    MenuWindow *window;
    HabitsWindow* habit;
    PlansWindow* plan;
    WellnessWindow* wellness;
    QuotesWindow* quotes;
};

#endif // MENUWINDOW_H
