#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

struct Student{
    QString name,subject;
    int num;
    bool male;
    Information(int c,QString a,QString b,bool d){
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

private:
    Ui::Widget *ui;
    QLinkedList<Student> *linklist;
    QString filename;
};

#endif // WIDGET_H
