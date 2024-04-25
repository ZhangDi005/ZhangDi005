#include "smoothsetdlg.h"
#include "ui_smoothsetdlg.h"

SmoothSetDlg::SmoothSetDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SmoothSetDlg)
{
    ui->setupUi(this);
    init();
}

SmoothSetDlg::~SmoothSetDlg()
{
    delete ui;
}

void SmoothSetDlg::init()
{
    this->setWindowTitle("setSmooth");
    speaker = new QButtonGroup(this);
    speaker->setExclusive(true);
    speaker->addButton(ui->noSmoothBtn, 0);
    speaker->addButton(ui->oneThirdBtn, 3);
    speaker->addButton(ui->onesixthBtn, 6);
    speaker->addButton(ui->onetwelfthBtn, 12);
    speaker->addButton(ui->oneTwenty_fourthBtn, 24);
    speaker->addButton(ui->oneForty_eighthBtn, 48);
    speaker->button(m_smooth)->setChecked(true);
}

int SmoothSetDlg::getSmoothBtnId()
{
    return m_smooth_BtnId;
}

void SmoothSetDlg::closeEvent(QCloseEvent *event)
{
    speaker->button(m_smooth)->setChecked(true);
    close();
}

void SmoothSetDlg::on_okBtn_clicked()
{
    this->accept();
    m_smooth_BtnId = speaker->checkedId();
    m_smooth = SMOOTH(m_smooth_BtnId);
    close();
}
