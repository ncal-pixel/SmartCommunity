#ifndef ADDPROPERTY_H
#define ADDPROPERTY_H

#include <QDialog>

namespace Ui {
class AddProperty;
}

class AddProperty : public QDialog
{
    Q_OBJECT

public:
    explicit AddProperty(QWidget *parent = nullptr);
    explicit AddProperty(int id,QWidget *parent = nullptr);
    int m_selectedId;
    void refreshTable();
    void initComboBoxes();
    ~AddProperty();

private:
    Ui::AddProperty *ui;
    QPushButton *btnOK;
    QPushButton *btnCancle;

private slots:
    void onOK();
    void onCancle();
};

#endif // ADDPROPERTY_H
