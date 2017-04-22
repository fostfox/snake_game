#ifndef PAGE_CONFIGURATION_H
#define PAGE_CONFIGURATION_H

#include <QWidget>

namespace Ui {
class page_configuration;
}

class page_configuration : public QWidget
{
    Q_OBJECT

public:
    explicit page_configuration(QWidget *parent = 0);
    ~page_configuration();

private:
    Ui::page_configuration *ui;
};

#endif // PAGE_CONFIGURATION_H
