#ifndef DIALOG_PROPERTY_H
#define DIALOG_PROPERTY_H

#include <QDialog>
#include <QSize>
#include <QVector>

namespace Ui {
class dialog_property;
}

class dialog_property : public QDialog
{
    Q_OBJECT

signals:
    void button_setResolution_pressed(int w, int h);
    void button_close_pressed();

private slots:
    void readResolution();

public:
    explicit dialog_property(QWidget *parent = 0);
    ~dialog_property();

    QSize getResolution();

private:
    Ui::dialog_property *ui;

    QVector<QSize> allResolutions;
    QVector<QSize> allowedResolutions;
};

#endif // DIALOG_PROPERTY_H
