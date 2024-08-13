#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "menuwindow.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_authoriseButton_clicked();

    void on_exitButton_clicked();

    void on_menuButton_clicked();

private:
    Ui::MainWindow *ui;
    MenuWindow *window;
};
#endif // MAINWINDOW_H
