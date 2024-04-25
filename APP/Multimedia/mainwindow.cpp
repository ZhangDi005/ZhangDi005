#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Multimedia");
    this->resize(1700,1400*0.618);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    on_actionphaseChart_triggered(ui->actionphaseChart->isChecked());
}

void MainWindow::closeEvent(QCloseEvent *event)
{
//    ui->sendFile->closeThread();
    return QMainWindow::closeEvent(event);
}

void MainWindow::on_actionfreqChart_triggered(bool checked)
{

}

void MainWindow::on_actionphaseChart_triggered(bool checked)
{
//    ui->calculatemag->setPhaseChartIsVis(checked);
}

void MainWindow::on_actionAdgust_triggered()
{
    ui->stackedWidget->setCurrentIndex(STACKWIG::ADGUST);
    ui->adgustMag->upData();
}

void MainWindow::on_actionGather_triggered()
{
    ui->stackedWidget->setCurrentIndex(STACKWIG::GATHER);
}

void MainWindow::on_actionSend_triggered()
{
    ui->stackedWidget->setCurrentIndex(STACKWIG::SEND);
}

void MainWindow::on_actionSmooth_triggered()
{
    if (m_smoothdlg == nullptr)
        m_smoothdlg = new SmoothSetDlg(this);
    if (m_smoothdlg->exec() == QDialog::Accepted) {
        int id = m_smoothdlg->getSmoothBtnId();
        static_cast<AdgustMag*>(ui->stackedWidget->widget(1))->setSmooth(SMOOTH(id));
    }
}

void MainWindow::on_actionbnb_triggered()
{
    HelpDlg help;
    help.exec();
}

void MainWindow::on_actionSave_triggered()
{
    QSettings setting("./setting/imPort.ini", QSettings::IniFormat);
    QString lastPath = setting.value("LastSavePath").toString();
    QString fileName = QFileDialog::getSaveFileName(this, "save file", lastPath, "(*.bin)");
    if (fileName == "")
        return;
    setting.setValue("LastSavePath", fileName);
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream out(&file);
        out<<App::instance();
        QMessageBox::information(this, "提示", "保存成功");
    } else
        QMessageBox::warning(this, "提示", "保存失败");
}

void MainWindow::on_actionOpen_triggered()
{
    QSettings setting("./setting/imPort.ini", QSettings::IniFormat);
    QString lastPath = setting.value("LastOpenPath").toString();
    QString fileName = QFileDialog::getOpenFileName(this, "open file", lastPath, "(*.bin)");
    if (fileName == "")
        return;
    setting.setValue("LastOpenPath", fileName);
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        in>>App::instance();
        on_actionAdgust_triggered();
    } else
        QMessageBox::warning(this, "提示", "打开失败");
}


void MainWindow::on_actionOne_triggered()
{
    LoadQss::loadQss(":/qss/givenStyle.qss");
}

void MainWindow::on_actiontwo_triggered()
{
    LoadQss::loadQss(":/qss/two.qss");
}
