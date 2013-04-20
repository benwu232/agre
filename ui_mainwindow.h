/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Aug 4 01:07:03 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QToolBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tabUser;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QPushButton *buttonSelect;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditNewUser;
    QPushButton *buttonAdd;
    QListWidget *userList;
    QWidget *tab;
    QGroupBox *MajorImageBox_tr;
    QLabel *MajorImageLabel_tr;
    QPushButton *LastButton;
    QPushButton *NextButton;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *tabCreateLib;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox;
    QFormLayout *formLayout_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonMethodA;
    QRadioButton *radioButtonMethodR;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QListWidget *libUserList;
    QPushButton *buttonStart;
    QGroupBox *groupBox_4;
    QListWidget *TemplateList;
    QPushButton *LoadButton;
    QWidget *Recognition;
    QGroupBox *MajorImageBox;
    QLabel *MajorImageLabel;
    QLabel *MajorImageText;
    QToolBox *GestureBoxRecog;
    QWidget *page_5;
    QWidget *page_6;
    QPushButton *buttonSort;
    QPushButton *GestureSaveButton;
    QLabel *label_3;
    QLabel *label_5;
    QPushButton *GestureSelectButton;
    QPushButton *pushButton_3;
    QSlider *horizontalSlider;
    QSlider *verticalSlider;
    QSpinBox *spinBox_h;
    QSpinBox *spinBox_v;
    QPushButton *pushButtonNomove;
    QWidget *tab_2;
    QLabel *AboutLabel;
    QLabel *MajorImageText_2;
    QLabel *MajorImageText_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(822, 631);
        QFont font;
        font.setPointSize(9);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        tabWidget->setFont(font1);
        tabUser = new QWidget();
        tabUser->setObjectName(QString::fromUtf8("tabUser"));
        label = new QLabel(tabUser);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 52, 81, 16));
        label_2 = new QLabel(tabUser);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 110, 81, 16));
        label_4 = new QLabel(tabUser);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 10, 511, 21));
        QFont font2;
        font2.setPointSize(16);
        label_4->setFont(font2);
        buttonSelect = new QPushButton(tabUser);
        buttonSelect->setObjectName(QString::fromUtf8("buttonSelect"));
        buttonSelect->setGeometry(QRect(280, 140, 91, 23));
        layoutWidget = new QWidget(tabUser);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 70, 331, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEditNewUser = new QLineEdit(layoutWidget);
        lineEditNewUser->setObjectName(QString::fromUtf8("lineEditNewUser"));

        horizontalLayout->addWidget(lineEditNewUser);

        buttonAdd = new QPushButton(layoutWidget);
        buttonAdd->setObjectName(QString::fromUtf8("buttonAdd"));

        horizontalLayout->addWidget(buttonAdd);

        userList = new QListWidget(tabUser);
        userList->setObjectName(QString::fromUtf8("userList"));
        userList->setGeometry(QRect(20, 140, 251, 221));
        tabWidget->addTab(tabUser, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        MajorImageBox_tr = new QGroupBox(tab);
        MajorImageBox_tr->setObjectName(QString::fromUtf8("MajorImageBox_tr"));
        MajorImageBox_tr->setGeometry(QRect(340, 40, 341, 331));
        MajorImageLabel_tr = new QLabel(MajorImageBox_tr);
        MajorImageLabel_tr->setObjectName(QString::fromUtf8("MajorImageLabel_tr"));
        MajorImageLabel_tr->setGeometry(QRect(20, 20, 256, 256));
        LastButton = new QPushButton(tab);
        LastButton->setObjectName(QString::fromUtf8("LastButton"));
        LastButton->setGeometry(QRect(400, 400, 75, 23));
        NextButton = new QPushButton(tab);
        NextButton->setObjectName(QString::fromUtf8("NextButton"));
        NextButton->setGeometry(QRect(530, 400, 75, 23));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 60, 281, 31));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 110, 281, 31));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 140, 281, 31));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(50, 180, 191, 31));
        tabWidget->addTab(tab, QString());
        tabCreateLib = new QWidget();
        tabCreateLib->setObjectName(QString::fromUtf8("tabCreateLib"));
        groupBox_3 = new QGroupBox(tabCreateLib);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 10, 301, 421));
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 219, 81));
        formLayout_2 = new QFormLayout(groupBox);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButtonMethodA = new QRadioButton(groupBox);
        radioButtonMethodA->setObjectName(QString::fromUtf8("radioButtonMethodA"));
        radioButtonMethodA->setChecked(true);

        verticalLayout->addWidget(radioButtonMethodA);

        radioButtonMethodR = new QRadioButton(groupBox);
        radioButtonMethodR->setObjectName(QString::fromUtf8("radioButtonMethodR"));
        radioButtonMethodR->setEnabled(true);

        verticalLayout->addWidget(radioButtonMethodR);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, verticalLayout);

        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 130, 282, 231));
        formLayout = new QFormLayout(groupBox_2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        libUserList = new QListWidget(groupBox_2);
        libUserList->setObjectName(QString::fromUtf8("libUserList"));

        formLayout->setWidget(0, QFormLayout::LabelRole, libUserList);

        buttonStart = new QPushButton(groupBox_3);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));
        buttonStart->setGeometry(QRect(40, 380, 75, 23));
        groupBox_4 = new QGroupBox(tabCreateLib);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(460, 10, 291, 401));
        TemplateList = new QListWidget(groupBox_4);
        TemplateList->setObjectName(QString::fromUtf8("TemplateList"));
        TemplateList->setGeometry(QRect(20, 20, 256, 311));
        LoadButton = new QPushButton(groupBox_4);
        LoadButton->setObjectName(QString::fromUtf8("LoadButton"));
        LoadButton->setGeometry(QRect(190, 360, 75, 23));
        tabWidget->addTab(tabCreateLib, QString());
        Recognition = new QWidget();
        Recognition->setObjectName(QString::fromUtf8("Recognition"));
        MajorImageBox = new QGroupBox(Recognition);
        MajorImageBox->setObjectName(QString::fromUtf8("MajorImageBox"));
        MajorImageBox->setGeometry(QRect(350, 30, 341, 331));
        MajorImageLabel = new QLabel(MajorImageBox);
        MajorImageLabel->setObjectName(QString::fromUtf8("MajorImageLabel"));
        MajorImageLabel->setGeometry(QRect(20, 20, 256, 256));
        MajorImageText = new QLabel(MajorImageBox);
        MajorImageText->setObjectName(QString::fromUtf8("MajorImageText"));
        MajorImageText->setGeometry(QRect(30, 290, 221, 21));
        GestureBoxRecog = new QToolBox(Recognition);
        GestureBoxRecog->setObjectName(QString::fromUtf8("GestureBoxRecog"));
        GestureBoxRecog->setGeometry(QRect(20, 20, 141, 451));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        page_5->setGeometry(QRect(0, 0, 98, 28));
        GestureBoxRecog->addItem(page_5, QString::fromUtf8("Page 1"));
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        page_6->setGeometry(QRect(0, 0, 141, 399));
        GestureBoxRecog->addItem(page_6, QString::fromUtf8("Page 2"));
        buttonSort = new QPushButton(Recognition);
        buttonSort->setObjectName(QString::fromUtf8("buttonSort"));
        buttonSort->setGeometry(QRect(40, 492, 91, 31));
        buttonSort->setCheckable(true);
        GestureSaveButton = new QPushButton(Recognition);
        GestureSaveButton->setObjectName(QString::fromUtf8("GestureSaveButton"));
        GestureSaveButton->setGeometry(QRect(410, 390, 75, 23));
        label_3 = new QLabel(Recognition);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(250, 470, 521, 31));
        label_5 = new QLabel(Recognition);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(240, 490, 511, 31));
        GestureSelectButton = new QPushButton(Recognition);
        GestureSelectButton->setObjectName(QString::fromUtf8("GestureSelectButton"));
        GestureSelectButton->setGeometry(QRect(220, 60, 75, 23));
        GestureSelectButton->setCheckable(false);
        pushButton_3 = new QPushButton(Recognition);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(560, 390, 81, 23));
        horizontalSlider = new QSlider(Recognition);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(190, 430, 161, 21));
        horizontalSlider->setValue(50);
        horizontalSlider->setOrientation(Qt::Horizontal);
        verticalSlider = new QSlider(Recognition);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(250, 220, 21, 160));
        verticalSlider->setValue(50);
        verticalSlider->setOrientation(Qt::Vertical);
        spinBox_h = new QSpinBox(Recognition);
        spinBox_h->setObjectName(QString::fromUtf8("spinBox_h"));
        spinBox_h->setGeometry(QRect(360, 430, 42, 22));
        spinBox_h->setValue(50);
        spinBox_v = new QSpinBox(Recognition);
        spinBox_v->setObjectName(QString::fromUtf8("spinBox_v"));
        spinBox_v->setGeometry(QRect(240, 190, 42, 22));
        spinBox_v->setValue(50);
        pushButtonNomove = new QPushButton(Recognition);
        pushButtonNomove->setObjectName(QString::fromUtf8("pushButtonNomove"));
        pushButtonNomove->setGeometry(QRect(230, 140, 75, 23));
        pushButtonNomove->setCheckable(true);
        tabWidget->addTab(Recognition, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        AboutLabel = new QLabel(tab_2);
        AboutLabel->setObjectName(QString::fromUtf8("AboutLabel"));
        AboutLabel->setGeometry(QRect(130, 90, 551, 41));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        AboutLabel->setFont(font3);
        MajorImageText_2 = new QLabel(tab_2);
        MajorImageText_2->setObjectName(QString::fromUtf8("MajorImageText_2"));
        MajorImageText_2->setGeometry(QRect(220, 320, 281, 21));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setItalic(true);
        font4.setWeight(75);
        MajorImageText_2->setFont(font4);
        MajorImageText_3 = new QLabel(tab_2);
        MajorImageText_3->setObjectName(QString::fromUtf8("MajorImageText_3"));
        MajorImageText_3->setGeometry(QRect(270, 230, 281, 21));
        MajorImageText_3->setFont(font4);
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 822, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);
        GestureBoxRecog->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "New user:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "User list:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Select your user name or create a new one.", 0, QApplication::UnicodeUTF8));
        buttonSelect->setText(QApplication::translate("MainWindow", "Select", 0, QApplication::UnicodeUTF8));
        lineEditNewUser->setText(QString());
        buttonAdd->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabUser), QApplication::translate("MainWindow", "User", 0, QApplication::UnicodeUTF8));
        MajorImageBox_tr->setTitle(QApplication::translate("MainWindow", "GroupBox", 0, QApplication::UnicodeUTF8));
        MajorImageLabel_tr->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        LastButton->setText(QApplication::translate("MainWindow", "<<<", 0, QApplication::UnicodeUTF8));
        NextButton->setText(QApplication::translate("MainWindow", ">>>", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Please draw the gesture with your wiimote. ", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "NOTE:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "1. When drawing gestures, press button 1.", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "When drawing over, release it.", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Train", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Create template from users", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Creating template methods", 0, QApplication::UnicodeUTF8));
        radioButtonMethodA->setText(QApplication::translate("MainWindow", "Method A", 0, QApplication::UnicodeUTF8));
        radioButtonMethodR->setText(QApplication::translate("MainWindow", "Method R", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "User list", 0, QApplication::UnicodeUTF8));
        buttonStart->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Template list", 0, QApplication::UnicodeUTF8));
        LoadButton->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabCreateLib), QApplication::translate("MainWindow", "Template", 0, QApplication::UnicodeUTF8));
        MajorImageBox->setTitle(QApplication::translate("MainWindow", "GroupBox", 0, QApplication::UnicodeUTF8));
        MajorImageLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        MajorImageText->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        GestureBoxRecog->setItemText(GestureBoxRecog->indexOf(page_5), QApplication::translate("MainWindow", "Page 1", 0, QApplication::UnicodeUTF8));
        GestureBoxRecog->setItemText(GestureBoxRecog->indexOf(page_6), QApplication::translate("MainWindow", "Page 2", 0, QApplication::UnicodeUTF8));
        buttonSort->setText(QApplication::translate("MainWindow", "Sort", 0, QApplication::UnicodeUTF8));
        GestureSaveButton->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "If the gesture above is not what you want,", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", " please select it from left gesture list.", 0, QApplication::UnicodeUTF8));
        GestureSelectButton->setText(QApplication::translate("MainWindow", ">>>", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Finish", 0, QApplication::UnicodeUTF8));
        pushButtonNomove->setText(QApplication::translate("MainWindow", "nomove", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Recognition), QApplication::translate("MainWindow", "Recognize", 0, QApplication::UnicodeUTF8));
        AboutLabel->setText(QApplication::translate("MainWindow", "Accelerometer based Gesture Recognition Engine", 0, QApplication::UnicodeUTF8));
        MajorImageText_2->setText(QApplication::translate("MainWindow", "Proudly present by: Wu, Bin", 0, QApplication::UnicodeUTF8));
        MajorImageText_3->setText(QApplication::translate("MainWindow", "Version: 0.80", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
