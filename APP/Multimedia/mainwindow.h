#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Module/algorithmDesign.h>
#include "Send/serialprot.h"
#include "smoothsetdlg.h"
#include "helpdlg.h"
#include "LodeQss.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum STACKWIG {
    GATHER = 0,
    ADGUST,
    SEND
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_actionfreqChart_triggered(bool checked);

    void on_actionphaseChart_triggered(bool checked);

    void on_actionGather_triggered();

    void on_actionAdgust_triggered();

    void on_actionSend_triggered();

    void on_actionSmooth_triggered();

    void on_actionbnb_triggered();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionOne_triggered();

    void on_actiontwo_triggered();

private:

    Ui::MainWindow *ui;
    SmoothSetDlg *m_smoothdlg = nullptr;
    void init();
};
#endif // MAINWINDOW_H
