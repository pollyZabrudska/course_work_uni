#ifndef POSITIVEWINDOW_H
#define POSITIVEWINDOW_H

#include <QDialog>

namespace Ui {
class PositiveWindow;
}

class PositiveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PositiveWindow(QWidget *parent = nullptr);
    ~PositiveWindow();

private slots:
    void on_backToMenuButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::PositiveWindow *ui;
};

#endif // POSITIVEWINDOW_H
