#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FindDialog)
{
    ui->setupUi(this);

    ui->label->setBuddy(ui->lineEdit); //https://www.youtube.com/watch?v=_GiKLzggMPQ

    ui->findButton->setDefault(true);
    ui->findButton->setEnabled(false);

    connect(ui->lineEdit,&QLineEdit::textChanged,this,&FindDialog::enableFindButton);
    connect(ui->findButton,&QPushButton::clicked,this,&FindDialog::findClicked);
    connect(ui->closeButton,&QPushButton::clicked,this,&FindDialog::close);
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::findClicked()
{
    QString text = ui->lineEdit->text();
    Qt::CaseSensitivity cs =
            ui->caseCheckBox->isChecked() ? Qt::CaseSensitive
                                          : Qt::CaseInsensitive; //มันคือ if(ui->caseCheckBox->isChecked())
                                                                 //         Qt::CaseSensitiveQt::CaseSensitive;
                                                                 //    else
                                                                 //         Qt::CaseInsensitive;

    if(ui->backwardCheckBox->isChecked())
        emit findPrevious(text,cs);
    else
        emit findNext(text,cs);
}

void FindDialog::enableFindButton(const QString &text)
{
    ui->findButton->setEnabled(!text.isEmpty());
}

