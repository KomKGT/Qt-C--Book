#include "gotocelldialog.h"
#include "ui_gotocelldialog.h"
#include <QRegExpValidator>
GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GoToCellDialog)
{
    ui->setupUi(this);

    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}"); //[A-Za-z] คือ ตัวอักษรหลักแรก ,[1-9] คือเลขหน้าสุด ,[0-9] คือเลขถัดมา , {0,2} คือเลขหลักที่ใส่ได้ คือ 3 หลัก
    ui->lineEdit->setValidator(new QRegExpValidator(regExp,this));

    connect(ui->okButton,&QPushButton::clicked,this,&GoToCellDialog::accept);
    connect(ui->cancelButton,&QPushButton::clicked,this,&GoToCellDialog::rejected);
    //connect(ui->lineEdit,SIGNAL(textChanged(const QString &)),this,SLOT(on_lineEdit_textChange())); //ใช้ได้เหมือนกัน
    connect(ui->lineEdit,&QLineEdit::textChanged,this,&GoToCellDialog::on_lineEdit_textChange); //ใช้ได้เหมือนกัน
}

GoToCellDialog::~GoToCellDialog()
{
    delete ui;
}

void GoToCellDialog::on_lineEdit_textChange()
{
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}

