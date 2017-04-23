#ifndef DIALOG_PROPERTY_H
#define DIALOG_PROPERTY_H

#include <QDialog>
#include <QSize>

namespace Ui {
class dialog_property;
}

class dialog_property : public QDialog
{
    Q_OBJECT

signals:
    void button_setResolution_pressed(int w, int h);


private slots:
    void readResolution();

public:
    explicit dialog_property(QWidget *parent = 0);
    ~dialog_property();

    QSize getResolution();

private:
    Ui::dialog_property *ui;
};

#endif // DIALOG_PROPERTY_H
