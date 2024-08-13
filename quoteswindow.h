#ifndef QUOTESWINDOW_H
#define QUOTESWINDOW_H

#include <QDialog>
#include <QVector>
#include <QPixmap>
#include <QGridLayout>
#include <QLabel>
#include <QString>

namespace Ui {
class QuotesWindow;
}

class QuotesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit QuotesWindow(QWidget *parent = nullptr);
    ~QuotesWindow();

private slots:

    void quotesGenerate();

    void on_exitButton_clicked();

    void on_backToMenuButton_clicked();

private:
    Ui::QuotesWindow *ui;
    QVector<QString> quotesTexts;
};

#endif // QUOTESWINDOW_H
