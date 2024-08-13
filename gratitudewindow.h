#ifndef GRATITUDEWINDOW_H
#define GRATITUDEWINDOW_H

#include <QDialog>

namespace Ui {
class GratitudeWindow;
}

class GratitudeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GratitudeWindow(QWidget *parent = nullptr);
    ~GratitudeWindow();

private slots:
    void on_exitButton_clicked();

    void on_backToMenuButton_clicked();

private:
    Ui::GratitudeWindow *ui;
};

#endif // GRATITUDEWINDOW_H
