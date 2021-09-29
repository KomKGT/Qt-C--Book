#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class FindDialog; }
QT_END_NAMESPACE

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    FindDialog(QWidget *parent = nullptr);
    ~FindDialog();

signals:
    void findNext(const QString &str,Qt::CaseSensitivity cs);
    void findPrevious(const QString &str,Qt::CaseSensitivity cs);

private slots:
    void findClicked();
    void enableFindButton(const QString &text);

private:
    Ui::FindDialog *ui;
};
#endif // FINDDIALOG_H
