#ifndef AFFIRMWINDOW_H
#define AFFIRMWINDOW_H

#include <QDialog>

namespace Ui {
class AffirmWindow;
}

class AffirmWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AffirmWindow(QWidget *parent = nullptr);
    ~AffirmWindow();

private slots:
    void on_exitButton_clicked();

    void on_backToMenuButton_clicked();

private:
    Ui::AffirmWindow *ui;
};

#endif // AFFIRMWINDOW_H
