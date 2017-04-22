#ifndef PAGE_SCORE_H
#define PAGE_SCORE_H

#include <QWidget>

namespace Ui {
class page_score;
}

class page_score : public QWidget
{
    Q_OBJECT

public:
    explicit page_score(QWidget *parent = 0);
    ~page_score();

private:
    Ui::page_score *ui;
};

#endif // PAGE_SCORE_H
