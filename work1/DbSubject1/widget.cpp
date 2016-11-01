#include "widget.h"
#include "ui_widget.h"
#include "QFileDialog"
#include "QDebug"
#include "qmessagebox.h"



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    list = new QList<Student*>();
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(deleteStudent()));
    caseModel = new QStandardItemModel();
    caseModel->setHorizontalHeaderItem(0,new QStandardItem("学号"));
    caseModel->setHorizontalHeaderItem(1,new QStandardItem("姓名"));
    caseModel->setHorizontalHeaderItem(2,new QStandardItem("性别"));
    caseModel->setHorizontalHeaderItem(3,new QStandardItem("专业"));
    QTableView *tableView = ui->tableView;
    tableView->setModel(caseModel);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->setColumnWidth(0,150);
    tableView->setColumnWidth(1,150);
    tableView->setColumnWidth(2,150);
    tableView->setColumnWidth(3,150);
   // QValidator *validator=
    //QIntegerForSize *validator = new QIntegerForSize(10,10);
    //new QIntValidator(999999999,19999999999,this);
      // 0-100 only accept number

    //ui->Ledit_num->setValidator(validator);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Btn_load_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("open file"), "",tr("DataFile(*.data)"));
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    int a;QString b,c;bool d;
    while(!in.atEnd())
    {
        in>>a>>b>>c>>d;
        list->push_back(new Student(a,b,c,d));
    }
    file.close();
    ui->Lab_path->setText(fileName);
}

bool Widget::saveFile()
{
    if(fileName.isEmpty())
    {
        fileName = QFileDialog::getSaveFileName(this,tr("save file"), "",tr("DataFiles (*.data)"));
    }
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    file.resize(0);
    QDataStream out(&file);
    Student *stu;
    for(int i=0;i<list->count();i++)
    {
        stu=list->at(i);
        out<<stu->num<<stu->name<<stu->subject<<stu->male;
    }
    file.flush();
    file.close();
}



void Widget::on_Btn_insert_clicked()
{
    int num = ui->Ledit_num->text().toInt();
    if(num<1000000000||num>9999999999)
    {
        QMessageBox::about(this,"插入错误","请输入10位学号");
        return;
    }
    if(ui->Ledit_name->text().isEmpty()||ui->Ledit_name->text().contains(" "))
    {
        QMessageBox::about(this,"插入错误","请输入姓名，请勿包含空格");
        return;
    }
    if(ui->Ledit_major->text().isEmpty()||ui->Ledit_major->text().contains(" "))
    {
        QMessageBox::about(this,"插入错误","请输入专业，请勿包含空格");
        return;
    }
    bool t;
    if(ui->Ledit_gender->text()=="男")
    {
        t = true;
    }
    else if(ui->Ledit_gender->text()=="女")
    {
        t = false;
    }
    else {
        QMessageBox::about(this,"插入错误","请输入正确性别");
        return;}
    for(int i=0;i<list->count();i++)
    {
        if(list->at(i)->num==num)
        {
            QMessageBox::about(this,"插入错误","学号已存在");
            return;
        }
    }
    list->push_back(new Student(num,ui->Ledit_name->text(),ui->Ledit_major->text(),t));
}

void Widget::on_Btn_query_clicked()
{
    caseModel->clear();
    caseModel->setHorizontalHeaderItem(0,new QStandardItem("学号"));
    caseModel->setHorizontalHeaderItem(1,new QStandardItem("姓名"));
    caseModel->setHorizontalHeaderItem(2,new QStandardItem("性别"));
    caseModel->setHorizontalHeaderItem(3,new QStandardItem("专业"));
    int r = 0;
    for(int i=0;i<list->count();i++)
    {
        if(((ui->Ledit_num->text().isEmpty())||list->at(i)->num==ui->Ledit_num->text().toInt())&&((ui->Ledit_name->text().isEmpty())||list->at(i)->name==ui->Ledit_name->text())&&
                (ui->Ledit_major->text().isEmpty()||list->at(i)->subject==ui->Ledit_major->text())&&(ui->Ledit_num->text().isEmpty()||list->at(i)->male==(ui->Ledit_gender->text()=="男"?true:false)))
        {
            qDebug()<<r;
            caseModel->setItem(r,0,new QStandardItem(QString::number(list->at(i)->num)));
            caseModel->setItem(r,1,new QStandardItem(list->at(i)->name));
            caseModel->setItem(r,2,new QStandardItem(list->at(i)->male==true?"男":"女"));
            caseModel->setItem(r,3,new QStandardItem(list->at(i)->subject));
            r++;
        }

    }
}

void Widget::deleteStudent()
{
    if(QMessageBox::question(NULL, "删除记录", "确定删除记录", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes)==QMessageBox::Yes)
    {

        int num = caseModel->index(ui->tableView->currentIndex().row(),0).data().toString().toInt();
        for(int i=0;i<list->count();i++)
        {
            if(list->at(i)->num==num)
            {
                list->removeAt(i);
                break;
            }
        }
        on_Btn_query_clicked();
    }
}

void Widget::closeEvent(QCloseEvent *event)
{
    saveFile();
}



