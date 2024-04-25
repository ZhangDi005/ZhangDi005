#ifndef RANGE_H
#define RANGE_H

#include <QDialog>

namespace Ui {
class Range;
}

class Range : public QDialog
{
    Q_OBJECT

public:
    explicit Range(QWidget *parent = nullptr);
    ~Range();
    void init(QPair<int, int> x, QPair<int, int> y);
    QPair<int, int> get_X();
    QPair<int, int> get_Y();

private slots:
    void on_okBtn_clicked();

private:
    Ui::Range *ui;
    QPair<int, int> m_x;
    QPair<int, int> m_y;
};

#endif // RANGE_H
