#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "mgmt.h"
#include "algo.h"
#include <qtoolbutton.h>

const int USER = 0;
const int TRAINING = 1;
const int LIB = 2;
const int RECOGNITION = 3;

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CAlgo *algo;

    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void InitUmgmt();
    void ListUser();
    void InitGestureList();
    void ListGesture();
    void ListTemplate();
    int WiimoteInitStatus;
    int GetCurrentTab();
    void DataPro();
    void TmpPro();
    void StaticGestureDisp(int& gesture);
    void StaticGesturePro(const gforce_t *acc);

private:
    Ui::MainWindow *ui;
    CMgmt *mgmt;
    QStatusBar *StatusBar;
    QLabel *StatusText1;
    QLabel *StatusText2;
    QToolButton **GestureButton;


private slots:
    void buttonAddClicked();
    void buttonSelectClicked();
    void enableButtonAdd(const QString &text);
    void buttonMethodAClicked();
    void buttonMethodRClicked();
    void buttonStartClicked();
    void buttonSortClicked();
    void GestureSelectButtonClicked();
    void GestureSaveButtonClicked();
    void LastButtonClicked();
    void NextButtonClicked();
    void LoadButtonClicked();
};

#endif // MAINWINDOW_H
