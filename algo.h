#ifndef ALGO_H
#define ALGO_H

#include <qlistwidget.h>
#include <qdir.h>
#include "wiiuse.h"

typedef float FLOAT;
const int RefPointNum = 50;
const int MaxPointNum = 300;

const int AVERAGE = 1;
const int RESCALE = 2;

const FLOAT INF = 100000.0;

const int WIN_SIZE = 16;
const FLOAT STATIC_THRESGOLD = 0.2;
const FLOAT TILT_THRESGOLD = 0.3;

const int TILT_UP = 1;
const int TILT_DOWN = 2;
const int TILT_LEFT = 3;
const int TILT_RIGHT = 4;
const int STATIC = 5;



struct stAcc
{
    double x;
    double y;
    double z;
};

struct stVecMotion
{
    QString name;
    QVector<stAcc> acc;
};

class CMotion
{
public:
    QString name;
    FLOAT x[RefPointNum];
    FLOAT y[RefPointNum];
    FLOAT z[RefPointNum];

    int DupNum;     //duplicated number, used in calculation
    FLOAT SimDist;

    CMotion& operator += (const CMotion& mot);
    CMotion(){DupNum = 1;}
};

struct stGesture
{
    char name[10];
    FLOAT x[RefPointNum];
    FLOAT y[RefPointNum];
    FLOAT z[RefPointNum];

};

class CGesture
{
public:
    QString name;
    FLOAT SimDist;
    CGesture& operator= (const CGesture& t);
};

class CAlgo
{


public:
    int MethodCreLib;
    //QList<stVecMotion> TemplateMot;
    QList<CMotion> TemplateMot;
    QList<CGesture> GestureList;
    CGesture MatchedGesture;

    CAlgo();
    void CreateLibPro(QList<QListWidgetItem *> UserList, const QDir& UDir, const QDir& RDir);
    QString Recognize(const CMotion& mot, QList<CMotion>& LibMot);
    QString Recognize(const CMotion& mot){return Recognize(mot, TemplateMot);};
    int StaticGestureRecognize(const gforce_t *acc);
    void Sort(int type);
    //void Sort(int type){Sort(type, TemplateMot);}
};

#endif // ALGO_H
