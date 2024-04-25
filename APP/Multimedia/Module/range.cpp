#include "range.h"
#include "ui_range.h"

Range::Range(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Range)
{
    ui->setupUi(this);

}

Range::~Range()
{
    delete ui;
}

void Range::init(QPair<int, int> x, QPair<int, int> y)
{
    ui->x_min->setValue(x.first);
    ui->x_max->setValue(x.second);
    ui->y_min->setValue(y.first);
    ui->y_max->setValue(y.second);
}

QPair<int, int> Range::get_X()
{
    return m_x;
}

QPair<int, int> Range::get_Y()
{
    return m_y;
}

void Range::on_okBtn_clicked()
{
    m_x.first = ui->x_min->value();
    m_x.second = ui->x_max->value();
    m_y.first = ui->y_min->value();
    m_y.second = ui->y_max->value();
    this->accept();
    close();
}
