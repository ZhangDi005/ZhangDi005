#ifndef SMOOTHSETDIG_H
#define SMOOTHSETDIG_H

#include <QDialog>
#include <QButtonGroup>
#include "Module/algorithmDesign.h"

namespace Ui {
class SmoothSetDlg;
}

class SmoothSetDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SmoothSetDlg(QWidget *parent = nullptr);
    ~SmoothSetDlg();
    void init();
    int getSmoothBtnId();
protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_okBtn_clicked();

private:
    Ui::SmoothSetDlg *ui;
    QButtonGroup *speaker;
    int m_smooth_BtnId;
    SMOOTH m_smooth = SMOOTH::noSmooth;
};

#endif // SMOOTHSETDIG_H
