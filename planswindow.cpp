#include "planswindow.h"
#include "ui_planswindow.h"
#include "menuwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QLabel>
#include <QStringList>

PlansWindow::PlansWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PlansWindow)
{
    ui->setupUi(this);

}

PlansWindow::~PlansWindow()
{
    delete ui;
}

void PlansWindow::on_backToMenuButton_clicked()
{
    MenuWindow *menuWindow = new MenuWindow();
    menuWindow->show();
}

void PlansWindow::on_exitButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Title", "Are you sure you want to quit?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    } else {
        qDebug() << "Button is not pushed";
    }
}

void PlansWindow::addPlan() {
    QString planText = ui->planLineEdit->text();

    QWidget *planWidget = new QWidget();
    QHBoxLayout *planLayout = new QHBoxLayout(planWidget);
    QCheckBox *planCheckbox = new QCheckBox();
    QLabel *planLabel = new QLabel(planText);

    planLayout->addWidget(planCheckbox);
    planLayout->addWidget(planLabel);

    ui->plansLayout->addWidget(planWidget);

    connect(planCheckbox, &QCheckBox::stateChanged, [=](int state) {
        if (state == Qt::Checked) {
            planLabel->setStyleSheet("QLabel { color: green; }");
        } else {
            planLabel->setStyleSheet("QLabel { color: black; }");
        }
    });
}

void PlansWindow::deletePlan() {
    QString planTextToRemove = ui->planLineEdit->text();

    for (int i = 0; i < ui->plansLayout->count(); ++i) {
        QWidget *planWidget = ui->plansLayout->itemAt(i)->widget();
        QLabel *planLabel = planWidget->findChild<QLabel*>();
        if (planLabel && planLabel->text() == planTextToRemove) {
            ui->plansLayout->removeWidget(planWidget);
            delete planWidget;
            return;
        }
    }
}


void PlansWindow::on_addButton_clicked()
{
    addPlan();
    ui->planLineEdit->clear();
}

void PlansWindow::on_deleteButton_clicked()
{
    deletePlan();
    ui->planLineEdit->clear();
}

void PlansWindow::on_archivButton_clicked()
{
    QString planNameToArchive = ui->planLineEdit->text().trimmed();
    if (!planNameToArchive.isEmpty()) {
        for (int i = 0; i < ui->plansLayout->count(); ++i) {
            QWidget *planWidget = ui->plansLayout->itemAt(i)->widget();
            QLabel *planLabel = planWidget->findChild<QLabel*>();
            if (planLabel && planLabel->text() == planNameToArchive) {
                ui->plansLayout->removeWidget(planWidget);
                archivedPlans.append(planNameToArchive);

                QWidget *archivedPlanWidget = new QWidget;
                QHBoxLayout *archivedPlanWidgetLayout = new QHBoxLayout(archivedPlanWidget);
                QCheckBox *archivedCheckBox = new QCheckBox(planNameToArchive);
                archivedPlanWidgetLayout->addWidget(archivedCheckBox);
                ui->archivLayout->addWidget(archivedPlanWidget);

                delete planWidget;
                ui->planLineEdit->clear();
                qDebug() << "Plan archived: " << planNameToArchive;
                return;
            }
        }
    }
}

void PlansWindow::deleteArchivedPlan() {
    QString planTextToRemove = ui->archivLineEdit->text();

    for (int i = 0; i < ui->archivLayout->count(); ++i) {
        QWidget *planWidget = ui->archivLayout->itemAt(i)->widget();
        QCheckBox *planCheckbox = planWidget->findChild<QCheckBox*>();
        if (planCheckbox && planCheckbox->text() == planTextToRemove) {
            ui->archivLayout->removeWidget(planWidget);
            delete planWidget;
            archivedPlans.removeAll(planTextToRemove);
            return;
        }
    }
}



QStringList PlansWindow::getArchivedPlans() const
{
    return archivedPlans;
}

void PlansWindow::on_archivDeleteButton_clicked()
{
    deleteArchivedPlan();
    ui->archivLineEdit->clear();
}

