#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QMessageBox>
#include <QString>
#include <QDir>
#include <QAbstractItemView>
#include <QTableWidget>
 #include <QTableWidgetItem>
#include "mgmt.h"
#include "algo.h"
#include "wiiuse.h"
#include <qmutex.h>
#include <qfile.h>
#include <QThread>

extern QString GetMajorName(QString& FileName);
extern wiimote** wiimotes;
extern int WiimoteInit();
#define MAX_WIIMOTES				4

extern int PointNum;
extern FLOAT AccX[];
extern FLOAT AccY[];
extern FLOAT AccZ[];
extern void Quantize(int InNum, FLOAT *inx, FLOAT *iny, FLOAT *inz, CMotion& out);
extern MainWindow *w;
extern FILE *LogFile;
extern int static_gesture_flag;

QFile *result;
CAlgo *algo;
QMutex mutex;

CDataPro *wm;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //Initialization

    ui->setupUi(this);

    InitUmgmt();
    algo = new CAlgo;

    ListUser();
    ListTemplate();
    InitGestureList();


    ui->libUserList->setSelectionMode(QAbstractItemView::MultiSelection);   //Set multiselection
    //ui->libUserList->setCurrentRow(0);

    StatusBar = statusBar();
    StatusText1 = new QLabel();
    StatusBar->addWidget(StatusText1);
    StatusText2 = new QLabel();
    StatusBar->addWidget(StatusText2);
    //StatusText->setText("adfadfa");

    ui->buttonAdd->setCheckable(TRUE);
    ui->buttonAdd->setEnabled(FALSE);   //Set Button Add gray

    ui->userList->setCurrentRow(0);

    //SLOTs
    connect(ui->buttonAdd, SIGNAL(clicked()), this, SLOT(buttonAddClicked()));
    connect(ui->lineEditNewUser, SIGNAL(textChanged(const QString &)),
            this, SLOT(enableButtonAdd(const QString &)));
    connect(ui->buttonSelect, SIGNAL(clicked()), this, SLOT(buttonSelectClicked()));
    connect(ui->radioButtonMethodA, SIGNAL(clicked()), this, SLOT(buttonMethodAClicked()));
    connect(ui->radioButtonMethodR, SIGNAL(clicked()), this, SLOT(buttonMethodRClicked()));
    connect(ui->buttonStart, SIGNAL(clicked()), this, SLOT(buttonStartClicked()));
    connect(ui->buttonSort, SIGNAL(clicked()), this, SLOT(buttonSortClicked()));
    connect(ui->GestureSelectButton, SIGNAL(clicked()), this, SLOT(GestureSelectButtonClicked()));
    connect(ui->GestureSaveButton, SIGNAL(clicked()), this, SLOT(GestureSaveButtonClicked()));
    connect(ui->NextButton, SIGNAL(clicked()), this, SLOT(NextButtonClicked()));
    connect(ui->LastButton, SIGNAL(clicked()), this, SLOT(LastButtonClicked()));
    connect(ui->LoadButton, SIGNAL(clicked()), this, SLOT(LoadButtonClicked()));


    // Wiimote
    WiimoteInitStatus = WiimoteInit();
    //CDataPro wm;
    wm = new CDataPro;
    wm->start();


    // for test
//    ui->buttonAdd->setText("Ha");
//    ui->userList->addItem("111111111111111");
//    ui->userList->addItem("2222222222222");
    StatusText1->setText("Hello");
    if (WiimoteInitStatus == 0)
        StatusText2->setText(QString(" "));
    else
        StatusText2->setText(QString("Wiimote connecting Failed!"));
}

void MainWindow::InitUmgmt()
{
    mgmt = new CMgmt("./");
    //mgmt = new CMgmt();
    mgmt->GenUserList();
}

void MainWindow::ListUser()
{
    ui->userList->addItems(mgmt->GetUserList());
    ui->libUserList->addItems(mgmt->GetUserList());
}

void MainWindow::InitGestureList()
{
    int k, GestureCount;

    QDir GestureDir = mgmt->GetGestureDir();
    if (!GestureDir.cd(GestureDir.absolutePath()))
        qDebug("Error: Can't go into GestureDir!");

    mgmt->GestureImageList = GestureDir.entryList(QDir::Files);
    GestureCount = mgmt->GestureImageList.count();


    QGroupBox *groupBox1 = new QGroupBox();
    QVBoxLayout *layout1 = new QVBoxLayout(groupBox1);
    //layout1->setMargin(10);
    layout1->setAlignment(Qt::AlignHCenter);
    ui->GestureBoxRecog->removeItem(0);
    ui->GestureBoxRecog->removeItem(0);
    ui->GestureBoxRecog->addItem( ( QWidget* )groupBox1 , tr("Gestures" ));

    GestureButton = new QToolButton*[GestureCount];
    for (k = 0; k < mgmt->GestureImageList.count(); k++)
    {
        GestureButton[k] = new QToolButton(ui->GestureBoxRecog);
        GestureButton[k]->setIconSize(QSize(64,64));
        GestureButton[k]->setIcon(QPixmap(GestureDir.absolutePath()+"/"+mgmt->GestureImageList[k]).scaled(64,64));
        GestureButton[k]->setText(QString("%1").arg(12345.6));
        //GestureButton[k]->setText(QString("%1").arg(algo->RefMot[k].SimDist));
        GestureButton[k]->setToolButtonStyle( Qt::ToolButtonTextUnderIcon);
        GestureButton[k]->setCheckable(TRUE);

        layout1->addWidget(GestureButton[k]);
    }

    ui->MajorImageBox->setTitle("Smile");
    ui->MajorImageText->setText("Smile");
    ui->MajorImageLabel->setPixmap(GestureDir.absolutePath()+"/"+"smile.png");

    ui->MajorImageBox_tr->setTitle(GetMajorName(mgmt->GestureImageList[0]));
    ui->MajorImageLabel_tr->setPixmap(mgmt->GetGestureDir().absolutePath()+"/"+mgmt->GestureImageList[0]);


}

void MainWindow::ListGesture()
{
    int k;
    QDir GestureDir = mgmt->GetGestureDir();

    k = algo->GestureList.count();

    for (k = 0; k < algo->GestureList.count(); k++)
    {
        GestureButton[k]->setIconSize(QSize(64,64));
        QString aaa = GestureDir.absolutePath()+"/"+algo->GestureList[k].name+".png";
        GestureButton[k]->setIcon(QPixmap(GestureDir.absolutePath()+"/"+algo->GestureList[k].name+".png").scaled(64,64));
        //GestureButton[k]->setText(QString("%1").arg(12345.6));
        GestureButton[k]->setText(QString("%1").arg(algo->GestureList[k].SimDist));
        GestureButton[k]->setToolButtonStyle( Qt::ToolButtonTextUnderIcon);
        GestureButton[k]->setCheckable(TRUE);
        GestureButton[k]->setChecked(FALSE);

    }
    ui->MajorImageBox->setTitle(algo->GestureList[0].name);
    ui->MajorImageText->setText(QString("%1").arg(algo->GestureList[0].SimDist));
    ui->MajorImageLabel->setPixmap(GestureDir.absolutePath()+"/"+algo->GestureList[0].name+".png");

    algo->MatchedGesture.name = algo->GestureList[0].name;
}

void MainWindow::ListTemplate()
{
    QDir Tdir = mgmt->GetTemplateDir();

    QStringList DirList = Tdir.entryList(QDir::Dirs);

    // Remove . and ..
    DirList.removeAt(0);
    DirList.removeAt(0);

    ui->TemplateList->addItems(DirList);
}

MainWindow::~MainWindow()
{
    int k;

    for (k = 0; k < mgmt->GestureImageList.count(); k++)
    {
        delete GestureButton[k];
    }
    delete GestureButton;

    delete ui;

    delete wm;
    delete result;

    //wm.exit();

    //Disconnect the wiimotes
    wiiuse_cleanup(wiimotes, MAX_WIIMOTES);
}

void MainWindow::buttonAddClicked()
{
    bool dFlag = false; //Duplicate flag

//    if (ui->buttonAdd->isChecked() == TRUE)
//        ui->buttonAdd->setText("Haha");
//    else
//        ui->buttonAdd->setText("Wow");

    if (!(ui->lineEditNewUser->text().isEmpty()))
    {

        // Check dupicate
        for (int k = 0; k < ui->userList->count(); k++)
        {
            if (ui->lineEditNewUser->text() == ui->userList->item(k)->text())
            {
                dFlag = true;
                break;
            }
        }

        if (dFlag == false)
        {
            ui->userList->addItem(ui->lineEditNewUser->text());
            //ui->userList->sortItems();
            mgmt->AddUser(ui->lineEditNewUser->text());
        }
        else
        {
            QMessageBox::warning(this, tr("Name duplicated!"),
                                           "This name has been used, please choose another name!\n",
                                           QMessageBox::Ok,
                                           QMessageBox::Ok);
        }

        // Clear lineEdit
        ui->lineEditNewUser->clear();

    }

}

void MainWindow::enableButtonAdd(const QString &text)
{
    ui->buttonAdd->setEnabled(!text.isEmpty());
}

void MainWindow::buttonSelectClicked()
{
    //StatusText->setText("coooool");
    //if (!ui->userList->currentItem().isEmpty())
    StatusText1->setText("Current user: " + ui->userList->currentItem()->text() + "     ");
    mgmt->SetCurUser(ui->userList->currentItem()->text());


    // open log file
    QDateTime CurTime = QDateTime::currentDateTime();
    QString TimeStr = CurTime.toString("yyyy-MM-dd_hh.mm.ss");
    QString FileName = mgmt->GetUserDir().absolutePath() + "/recognizing/" + mgmt->GetCurUser() + "_" + TimeStr + ".log";

    result = new QFile(FileName);
    if (!result->open(QIODevice::WriteOnly | QIODevice::Text))
        return;


}

void MainWindow::buttonMethodAClicked()
{
    algo->MethodCreLib = 1;   // Using averaging method
}

void MainWindow::buttonMethodRClicked()
{
    algo->MethodCreLib = 2;   // using rescaling method
}

void MainWindow::buttonStartClicked()
{
    if (ui->libUserList->selectedItems().count() == 0)
    {
        QMessageBox::warning(this, tr("No user selected"),
                                       "Pleae select user(s) to create reference library!\n",
                                       QMessageBox::Ok,
                                       QMessageBox::Ok);
    }
    else
    {
        algo->CreateLibPro(ui->libUserList->selectedItems(), mgmt->GetUserDir(), mgmt->GetTemplateDir());
        ui->TemplateList->clear();
        ListTemplate();
        //TmpPro();
    }
}

void MainWindow::buttonSortClicked()
{
    if (ui->buttonSort->isChecked())
    {
        algo->Sort(2);
    }
    else
    {
        algo->Sort(1);
    }
    ListGesture();
}

void MainWindow::GestureSelectButtonClicked()
{
    int k = 0;
    QDir GestureDir = mgmt->GetGestureDir();

    for (k = 0; k < algo->GestureList.count(); k++)
    {
        if (GestureButton[k]->isChecked() == TRUE)
            break;
    }

    // Write to result log
    QTextStream out(result);
    out << ui->MajorImageBox->title() <<"  >>>>>   "<<algo->GestureList[k].name;

    ui->MajorImageBox->setTitle(algo->GestureList[k].name);
    ui->MajorImageText->setText(QString("%1").arg(algo->GestureList[k].SimDist));
    ui->MajorImageLabel->setPixmap(GestureDir.absolutePath()+"/"+algo->GestureList[k].name+".png");

    algo->MatchedGesture.name = algo->GestureList[k].name;


}

void MainWindow::GestureSaveButtonClicked()
{
    QDateTime CurTime = QDateTime::currentDateTime();
    QString TimeStr = CurTime.toString("yyyy-MM-dd_hh.mm.ss");

    QString FileName = mgmt->GetUserDir().absolutePath() + "/" + mgmt->GetCurUser() +
                       "/recognizing/" + algo->MatchedGesture.name + "_" + mgmt->GetCurUser() + "_" + TimeStr + ".dat";
    //QString FileName = "haha";
    QByteArray ba2 = FileName.toLatin1();
    const char *cstr2 = ba2.data();

    FILE *fp = fopen(cstr2, "w");

    int k = PointNum;
    for (k = 0; k < PointNum; k++)
    {
        fprintf(fp, "%10f%10f%10f\n", AccX[k], AccY[k], AccZ[k]);
    }

    fclose(fp);
    PointNum = 0;
}

void MainWindow::LastButtonClicked()
{
    if (ui->MajorImageBox_tr->title() != "Smile")
    {
        if (mgmt->TrIdx > 0)
            mgmt->TrIdx--;
    }

    PointNum = 0;

    ui->MajorImageBox_tr->setTitle(GetMajorName(mgmt->GestureImageList[mgmt->TrIdx]));
    ui->MajorImageLabel_tr->setPixmap(mgmt->GetGestureDir().absolutePath()+"/"+mgmt->GestureImageList[mgmt->TrIdx]);

}

void MainWindow::NextButtonClicked()
{
    // save current gesture
    int k = PointNum;

    if (ui->MajorImageBox_tr->title() == "Smile")
    {
        if (PointNum)
        {
            QDateTime CurTime = QDateTime::currentDateTime();
            QString TimeStr = CurTime.toString("yyyy-MM-dd_hh.mm.ss");

            QString FileName = mgmt->GetUserDir().absolutePath() + "/" + GetMajorName(mgmt->GetCurUser()) +
                               "/training/" + GetMajorName(mgmt->GestureImageList[mgmt->TrIdx]) + "_" + TimeStr + ".dat";

            QByteArray ba2 = FileName.toLatin1();
            const char *cstr2 = ba2.data();

            FILE *fp = fopen(cstr2, "w");

            for (k = 0; k < PointNum; k++)
            {
                fprintf(fp, "%10f%10f%10f\n", AccX[k], AccY[k], AccZ[k]);
            }

            fclose(fp);
            PointNum = 0;
        }
    }

    // for next gesture
    if (mgmt->TrIdx >= mgmt->GestureImageList.count() - 1)  //Last gesture
    {
        ui->MajorImageBox_tr->setTitle("End");
        //ui->MajorImageLabel_tr->setText("OVER");
        ui->MajorImageLabel_tr->setPixmap(mgmt->GetImageDir().absolutePath()+"/end.png");
    }
    else
    {
        mgmt->TrIdx++;

        ui->MajorImageBox_tr->setTitle(GetMajorName(mgmt->GestureImageList[mgmt->TrIdx]));
        ui->MajorImageLabel_tr->setPixmap(mgmt->GetGestureDir().absolutePath()+"/"+mgmt->GestureImageList[mgmt->TrIdx]);
    }
}

void MainWindow::LoadButtonClicked()
{
    QDir TemplateDir(mgmt->GetTemplateDir().absolutePath() + "/" + ui->TemplateList->currentItem()->text());
    TemplateDir.cd(TemplateDir.absolutePath());
    QStringList FileList = TemplateDir.entryList(QDir::Files);
    QString fn;
    FILE *fp;
    int k, p;
    CMotion TmpTmpMot;

    // Clear the Template List
    algo->TemplateMot.clear();

    for (k = 0; k < FileList.count(); k++)
    {
        if (FileList[k] == "readme.txt")
            continue;

        fn = TemplateDir.absolutePath() + "/" + FileList[k];
        QByteArray ba = fn.toLatin1();
        const char *cstr = ba.data();
        fp = fopen(cstr, "r");  //QString -> char*

        // Read file
        p = 0;
        while(fscanf(fp,"%f%f%f", &(TmpTmpMot.x[p]), &(TmpTmpMot.y[p]), &(TmpTmpMot.z[p])) != EOF)
        {
            p++;
        }
        TmpTmpMot.name = GetMajorName(FileList[k]);

        algo->TemplateMot.append(TmpTmpMot);

        //fprintf(LogFile, "%d\n", k);
        fclose(fp);
    }

    // Write to GestureList
    algo->GestureList.clear();
    CGesture tmp;
    for (p = 0; p < algo->TemplateMot.count(); p++)
    {
        tmp.name = algo->TemplateMot[p].name;
        tmp.SimDist = algo->TemplateMot[p].SimDist;
        algo->GestureList.append(tmp);
    }

}

int MainWindow::GetCurrentTab()
{
    return ui->tabWidget->currentIndex();
}

void MainWindow::StaticGestureDisp(int& gesture)
{
    if (gesture == TILT_UP && ui->verticalSlider->value() < ui->verticalSlider->maximum()-1)
    {
        ui->spinBox_v->setValue(ui->spinBox_v->value()+1);
        ui->verticalSlider->setValue(ui->verticalSlider->value()+1);
    }

    if (gesture == TILT_DOWN && ui->verticalSlider->value() > ui->verticalSlider->minimum()+1)
    {
        ui->spinBox_v->setValue(ui->spinBox_v->value()-1);
        ui->verticalSlider->setValue(ui->verticalSlider->value()-1);
    }

    if (gesture == TILT_LEFT && ui->horizontalSlider->value() > ui->horizontalSlider->minimum()+1)
    {
        ui->spinBox_h->setValue(ui->spinBox_h->value()-1);
        ui->horizontalSlider->setValue(ui->horizontalSlider->value()-1);
    }

    if (gesture == TILT_RIGHT && ui->horizontalSlider->value() < ui->horizontalSlider->maximum()-1)
    {
        ui->spinBox_h->setValue(ui->spinBox_h->value()+1);
        ui->horizontalSlider->setValue(ui->horizontalSlider->value()+1);
    }

    if (gesture == STATIC)
    {
        if (ui->pushButtonNomove->text() != "hello")
            ui->pushButtonNomove->setText("hello");
        else if (ui->pushButtonNomove->text() != "world")
            ui->pushButtonNomove->setText("world");
    }

    gesture = 0;

}

void MainWindow::StaticGesturePro(const gforce_t *acc)
{
    int gesture;

    gesture = algo->StaticGestureRecognize(acc);
    StaticGestureDisp(gesture);
    //QTest::qSleep(250);
    //QThread::msleep(250);
}

void MainWindow::DataPro()
{
    CMotion MotSample;
/*
    // Static gesture
    if (static_gesture_flag)
    {
        static_gesture_flag = 0;
        return;
    }
*/
    //mutex.lock();
    Quantize(PointNum, AccX, AccY, AccZ, MotSample);
    //mutex.unlock();

    if (w->GetCurrentTab() == RECOGNITION)
    {
        algo->Recognize(MotSample);
        algo->Sort(1);
        ListGesture();
    }

    if (w->GetCurrentTab() == TRAINING)
    {
        ui->MajorImageBox_tr->setTitle("Smile");
        ui->MajorImageLabel_tr->setPixmap(mgmt->GetImageDir().absolutePath()+"/smile.png");
    }
}

void MainWindow::TmpPro()
{
    CMotion MotSample;

    int k;

    FILE *fp = fopen("D:/mywork/ms/lib/tst/g1.tst", "r");

    BEGIN:
    // Read file
    k = 0;
    while(fscanf(fp,"%f %f %f", &(AccX[k]), &(AccY[k]), &(AccZ[k])) != EOF)
    {
        //tmpMotion.acc.append(tmpAcc);

        //AccZ[k] -= 1.0;
        k++;
    }
    fclose(fp);


    Quantize(k, AccX, AccY, AccZ, MotSample);

    //if (w->GetCurrentTab() == RECOGNITION)
    {
        algo->Recognize(MotSample);
        algo->Sort(1);
        ListGesture();
    }

    fp = fopen("D:/mywork/ms/lib/tst/1.tst", "r");

    // Read file
    k = 0;
    while(fscanf(fp,"%f %f %f", &(AccX[k]), &(AccY[k]), &(AccZ[k])) != EOF)
    {
        //tmpMotion.acc.append(tmpAcc);

        //AccZ[k] -= 1.0;
        k++;
    }

    fclose(fp);

    Quantize(k, AccX, AccY, AccZ, MotSample);

    //if (w->GetCurrentTab() == RECOGNITION)
    {
        algo->Recognize(MotSample);
        algo->Sort(1);
        ListGesture();
    }

    goto BEGIN;
}

