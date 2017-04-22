#ifndef DIALOG_PROPERTY_H
#define DIALOG_PROPERTY_H

#include <QDialog>

namespace Ui {
class dialog_property;
}

class dialog_property : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_property(QWidget *parent = 0);
    ~dialog_property();

private:
    Ui::dialog_property *ui;
};

#endif // DIALOG_PROPERTY_H
