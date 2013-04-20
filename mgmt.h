#ifndef UMGMT_H
#define UMGMT_H

#include <QString>
#include <QMessageBox>
#include <QtDebug>
#include <QDir>
 #include <QThread>
// Class for user management

class CMgmt
{
    QString UserDirName;
    QString UserDirPath;
    QDir UserDir;
    QStringList UserList;
    QString CurUser;

    QDir TemplateDir;
    QDir ImageDir;
    QDir GestureDir;

public:
    QStringList GestureImageList;
    //QList<QLabel> GestureList;
    int TrIdx;


    CMgmt(QString HomeDir);
    CMgmt(){TrIdx = 0;};
    void GenUserList();
    QStringList& GetUserList();
    void AddUser(const QString& UserNume);
    void SetCurUser(QString User);
    QDir& GetUserDir();
    QDir& GetTemplateDir();
    QDir& GetImageDir();
    QDir& GetGestureDir();
    QString& GetCurUser();

};

class CDataPro : public QThread
{
public:
    CDataPro(){};
    void run();
};

#endif // UMGMT_H
