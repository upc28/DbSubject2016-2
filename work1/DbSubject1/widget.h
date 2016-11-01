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
    QString reward;
    Student(int c,QString a,QString b,bool d,QString e){
        name = a;subject = b;num = c;male = d;reward = e;
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

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QList<Student*> *list;
    QString fileName;
    QStandardItemModel *caseModel;
    bool saveFile();
    void closeEvent(QCloseEvent *event);
};

#endif // WIDGET_H
