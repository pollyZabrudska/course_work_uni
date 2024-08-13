#ifndef WELLNESSWINDOW_H
#define WELLNESSWINDOW_H
#include "gratitudewindow.h"
#include "affirmwindow.h"
#include "positivewindow.h"
#include <QDialog>
#include <QWidget>

namespace Ui {
class WellnessWindow;
}

class WellnessWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WellnessWindow(QWidget *parent = nullptr);
    ~WellnessWindow();

private slots:
    void on_backToMenuButton_clicked();

    void on_exitButton_clicked();

    void on_gratitudeButton_clicked();

    void on_positiveButton_clicked();

    void on_affirmationsButton_clicked();

private:
    Ui::WellnessWindow *ui;
    WellnessWindow* wellness;
    GratitudeWindow* gratitude;
    PositiveWindow* positive;
    AffirmWindow* affirm;
};

#endif // WELLNESSWINDOW_H
