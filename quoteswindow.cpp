#include "quoteswindow.h"
#include "ui_quoteswindow.h"
#include "menuwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QRandomGenerator>

QuotesWindow::QuotesWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QuotesWindow)
{
    ui->setupUi(this);
    QPixmap pix1(":/img/lotus1.png");
    int width1 = ui->img->width();
    int height1 = ui->img->height();
    ui->img->setPixmap(pix1.scaled(width1,height1, Qt::KeepAspectRatio));

    quotesTexts.append("BE A SUNFLOWER AND TURN TO THE LIGHT");
    quotesTexts.append("FOCUS ON GOOD AND IT BECOMES EVEN BETTER");
    quotesTexts.append("BELIEVE IN MIRACLES AND THEY WILL HAPPEN!");
    quotesTexts.append("EVERYTHING WILL BE OKAY");
    quotesTexts.append("TRUST YOURSELF");
    quotesTexts.append("EVERYTHING HAPPENS FOR YOUR GOOD");
    quotesGenerate();

}

QuotesWindow::~QuotesWindow()
{
    delete ui;
}

void QuotesWindow::quotesGenerate()
{
    int randomIndex = QRandomGenerator::global()->bounded(quotesTexts.size());
    ui->quoteText->setText(quotesTexts[randomIndex]);
}

void QuotesWindow::on_exitButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Title", "Are you sure you want to quit?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    } else {
        qDebug() << "Button is not pushed";
    }
}


void QuotesWindow::on_backToMenuButton_clicked()
{
    hide();
    MenuWindow *menuWindow = new MenuWindow();
    menuWindow->show();
}
