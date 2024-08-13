#ifndef PLANSWINDOW_H
#define PLANSWINDOW_H
#include <QDialog>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QStringList>

namespace Ui {
class PlansWindow;
}

class PlansWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PlansWindow(QWidget *parent = nullptr);
    ~PlansWindow();
    QStringList getArchivedPlans() const;

private slots:
    void on_backToMenuButton_clicked();

    void on_exitButton_clicked();

    void addPlan();

    void deletePlan();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_archivButton_clicked();

    void deleteArchivedPlan();

    void on_archivDeleteButton_clicked();

private:
    Ui::PlansWindow *ui;
    QStringList archivedPlans; // Список для збереження планів
};

#endif // PLANSWINDOW_H
