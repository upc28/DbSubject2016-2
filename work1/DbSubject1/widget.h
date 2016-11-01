#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QDataStream"
#include "QCloseEvent"
#include "qstandarditemmodel.h"
#include "QStandardItem"

namespace Ui {
class Widget;
}

struct Student{
    QString name,subject;
    int num;
    bool male;

    Student(int c,QString a,QString b,bool d){
        name = a;subject = b;num = c;male = d;
    }
};




class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_Btn_load_clicked();

    void on_Btn_insert_clicked();

    void on_Btn_query_clicked();

    void deleteStudent();

private:
    Ui::Widget *ui;
    QList<Student*> *list;
    QString fileName;
    QStandardItemModel *caseModel;
    bool saveFile();
    void closeEvent(QCloseEvent *event);
};

#endif // WIDGET_H
