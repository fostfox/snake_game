#ifndef PAGE_FIELD_H
#define PAGE_FIELD_H

#include <QWidget>

namespace Ui {
class page_field;
}

class page_field : public QWidget
{
    Q_OBJECT

public:
    explicit page_field(QWidget *parent = 0);
    ~page_field();

//private:
    Ui::page_field *ui;
};

#endif // PAGE_FIELD_H
