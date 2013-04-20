#include <QString>
#include <QMessageBox>
#include <QtDebug>
#include <QDir>
#include "mgmt.h"
#include <qdatetime.h>

extern void WiimoteRun();

CMgmt::CMgmt(QString HomeDir)
{
    //CMgmt();

    TrIdx = 0;

    UserDirName = "user/";
    UserDirPath = HomeDir + UserDirName;
    UserDir = QDir(UserDirPath);
    if (!UserDir.exists())
        UserDir.mkpath(UserDir.absolutePath());

    TemplateDir = QDir(HomeDir + "template");
    if (!TemplateDir.exists())
        TemplateDir.mkpath(TemplateDir.absolutePath());

    ImageDir = QDir(HomeDir + "image");
    if (!ImageDir.exists())
        ImageDir.mkpath(ImageDir.absolutePath());

    GestureDir = QDir(HomeDir + "gesture");
    if (!GestureDir.exists())
        GestureDir.mkpath(GestureDir.absolutePath());

}

void CMgmt::GenUserList()
{
    //qDebug("into GenUserList");

    //if (!UserDir.exists())
        //UserDir.mkpath(UserDir.absolutePath());

    if (!UserDir.cd(UserDir.absolutePath()))
        qDebug("Error: Can't go into UserDir!");

    UserList = UserDir.entryList(QDir::Dirs);

    // Remove '.' and '..'
    UserList.removeAt(0);
    UserList.removeAt(0);


    //return UserList;

    //UserDir =

    //qDebug("UserDirName = %s", UserDirName);
    //qDebug()<<"UserDirName ="<<UserDirName;
    /*
    QMessageBox::warning(this, "Message!",
                                   UserDirName,
                                   QMessageBox::Ok,
                                   QMessageBox::Ok);*/
    //QMessageBox::information(this,"Quit...","Really Quit?",QMessageBox::Ok,QMessageBox::Cancel);
}

QStringList& CMgmt::GetUserList()
{
    return UserList;
}

void CMgmt::AddUser(const QString& UserName)
{
    UserDir.cd(UserDir.absolutePath());
    UserDir.mkdir(UserName);
    UserDir.cd(UserName);
    UserDir.mkdir("training");
    UserDir.mkdir("recognizing");
    UserDir.cdUp();
}

void CMgmt::SetCurUser(QString User)
{
    CurUser = User;
}

QString& CMgmt::GetCurUser()
{
    return CurUser;
}

QDir& CMgmt::GetUserDir()
{
    return UserDir;
}

QDir& CMgmt::GetTemplateDir()
{
    return TemplateDir;
}

QDir& CMgmt::GetImageDir()
{
    return ImageDir;
}

QDir& CMgmt::GetGestureDir()
{
    return GestureDir;
}

void CDataPro::run()
{
    WiimoteRun();
}
