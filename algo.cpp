#include "algo.h"
#include "stdio.h"
#include "math.h"
#include "qdatetime.h"
#include <QMessageBox>
#include <QString>

extern int PointNum;
extern int static_gesture_flag;

QString GetMajorName(QString& FileName)
{
    int k;
    QString major;

    for (k = 0; k < FileName.count(); k++)
    {
        if (FileName[k] == '.')
            break;
        else
        {
            major[k] = FileName[k];
        }
    }

    return major;
}

//********************************************************************
// Name: Resample
// Description: Quantize the input sequence to the output sequence,
//              including resampling and rescaling
// Input:
//      in: input sequence
//      LenIn: length of input sequence
//      LenOut: length of output sequence
// Output:
//      out: output sequence
// Type:
//      void
//********************************************************************
void Quantize(FLOAT *in, int LenIn, FLOAT *out, int LenOut)
{
    int k = 0, IdxInt;
    FLOAT rFac, IdxFrac, step, idx, max = 0;

    rFac = (LenIn-1) / (LenOut-0.5);     // avoid overflow

    out[0] = in[0];
    max = fabs(out[0]);

    idx = 0;
    for (k = 1; k < LenOut; k++)
    {
        // Resample
        idx += rFac;
        IdxInt = floor(idx);
        IdxFrac = idx - IdxInt;
        step = in[IdxInt+1] - in[IdxInt];
        out[k] = in[IdxInt] + IdxFrac * step;   // linear interpolation

        // Find max
        if (max < fabs(out[k]))
            max = fabs(out[k]);
    }

    // Rescale
    for (k = 0; k < LenOut; k++)
        out[k] /= max;
}

void Quantize(int InNum, FLOAT *inx, FLOAT *iny, FLOAT *inz, CMotion& out)
{
    Quantize(inx, InNum, out.x, RefPointNum);
    Quantize(iny, InNum, out.y, RefPointNum);
    Quantize(inz, InNum, out.z, RefPointNum);

}


void Rescale(CMotion& mot)
{
    int k;
    FLOAT MaxX = 0, MaxY = 0, MaxZ = 0;

    // Find MaxX
    for (k = 0; k < RefPointNum; k++)
    {
        if (MaxX < fabs(mot.x[k]))
            MaxX = fabs(mot.x[k]);

        if (MaxY < fabs(mot.y[k]))
            MaxY = fabs(mot.y[k]);

        if (MaxZ < fabs(mot.z[k]))
            MaxZ = fabs(mot.z[k]);

    }

    // Rescale
    for (k = 0; k < RefPointNum; k++)
    {
        mot.x[k] /= MaxX;
        mot.y[k] /= MaxY;
        mot.z[k] /= MaxZ;
    }
}

inline FLOAT CalDist_Euclid_2D(const FLOAT& x1, const FLOAT& y1, const FLOAT& z1, const FLOAT& x2, const FLOAT& y2, const FLOAT& z2)
{
    FLOAT d;

    d = (x2-x1)*(x2-x1) + (z2-z1)*(z2-z1);

    return d;
}

inline FLOAT CalDist_Euclid_3D(const FLOAT& x1, const FLOAT& y1, const FLOAT& z1, const FLOAT& x2, const FLOAT& y2, const FLOAT& z2)
{
    FLOAT d;

    d = (x2-x1)*(x2-x1) + (z2-z1)*(z2-z1) + (y2-y1)*(y2-y1);

    return d;
}

inline FLOAT CalDist_Manhattan_2D(const FLOAT& x1, const FLOAT& y1, const FLOAT& z1, const FLOAT& x2, const FLOAT& y2, const FLOAT& z2)
{
    FLOAT d;

    d = abs(x2-x1) + abs(z2-z1);

    return d;
}

inline FLOAT CalDist_Manhattan_3D(const FLOAT& x1, const FLOAT& y1, const FLOAT& z1, const FLOAT& x2, const FLOAT& y2, const FLOAT& z2)
{
    FLOAT d;

    d = abs(x2-x1) + abs(z2-z1) + abs(y2-y1);

    return d;
}

FLOAT (*CalDist)(const FLOAT& x1, const FLOAT& y1, const FLOAT& z1, const FLOAT& x2, const FLOAT& y2, const FLOAT& z2);

// Calculate DTW
FLOAT CalDtw(const FLOAT *x1, const FLOAT *y1, const FLOAT *z1, const FLOAT *x2, const FLOAT *y2, const FLOAT *z2)
{
    int p, k, IdxP, IdxK;
    FLOAT d[RefPointNum+1][RefPointNum+1], MinDist, cost;

    for (p = 0; p < RefPointNum+1; p++)
    for (k = 0; k < RefPointNum+1; k++)
        d[p][k] = 0.0;

    d[0][0] = 0.0;
    for (k = 1; k < RefPointNum+1; k++)
    {
        d[k][0] = INF;
        d[0][k] = INF;
    }

    for (p = 1; p < RefPointNum+1; p++)
    for (k = 1; k < RefPointNum+1; k++)
    {
        cost = CalDist(x1[p-1], y1[p-1], z1[p-1], x2[k-1], y2[k-1], z2[k-1]);

        if (d[p-1][k] < d[p][k-1])
        {
            MinDist = d[p-1][k];
            IdxP = p - 1;
            IdxK = k;
        }
        else
        {
            MinDist = d[p][k-1];
            IdxP = p;
            IdxK = k - 1;
        }

        if (d[p-1][k-1] < MinDist)
        {
            MinDist = d[p-1][k-1];
            IdxP = p - 1;
            IdxK = k - 1;
        }

        d[p][k] = cost + MinDist;
    }

    return d[RefPointNum][RefPointNum];

}

FLOAT CalDtw(const CMotion& s, const CMotion& t)
{
    return CalDtw(s.x, s.y, s.z, t.x, t.y, t.z);
}


CGesture& CGesture::operator= (const CGesture& t)
{
    this->name = t.name;
    this->SimDist = t.SimDist;
    return *this;
}


///////////////////////////////////////////////////////////////
CAlgo::CAlgo()
{
    MethodCreLib = AVERAGE;
    CalDist = CalDist_Euclid_2D;
    MatchedGesture.name = "noname";
};

CMotion& CMotion::operator += (const CMotion& mot)
{
    int k;
    
    for (k = 0; k < RefPointNum; k++)
    {
        x[k] += mot.x[k];
        y[k] += mot.y[k];
        z[k] += mot.z[k];
    }

    return *this;
}

void CAlgo::CreateLibPro(QList<QListWidgetItem *> UserList, const QDir& UDir, const QDir& RDir)
{
    int q = 0, p = 0, k = 0, DupIdx = 0;
    QString RelativePath, FileName, MotionName, PathFileName;
    QDir UserDir = UDir, TemplateDir = RDir;
    QString UserHomeDir = UserDir.absolutePath();
    QStringList FileList;
    FILE *fp;
    stVecMotion tmpMotion;
    CMotion QuantizeMotion;
    bool IsDuplicate = FALSE;
    FLOAT AccX[MaxPointNum], AccY[MaxPointNum], AccZ[MaxPointNum];

    UserDir.cd(UserDir.absolutePath());

    // Clear the Template List
    TemplateMot.clear();

    for (q = 0; q < UserList.count(); q++)
    {
        // go into the user subdirectory
        RelativePath = UserList[q]->text() + "/training";

        if (!UserDir.cd(RelativePath))
            qDebug("Error: Can't go into UserDir!");

        FileList = UserDir.entryList(QDir::Files);

        for (p = 0; p < FileList.count(); p++)
        {
            PathFileName = UserDir.absolutePath() + "/" + FileList[p];
            FileName = FileList[p];

            // Get motion name
            MotionName.clear();
            for (k = 0; k < FileName.count(); k++)
            {
                if (FileName[k] == '_')
                    break;
                else
                {
                    MotionName[k] = FileName[k];
                }
            }

            // Check if MotionName is existed
            IsDuplicate = FALSE;
            for (k = 0; k < TemplateMot.count(); k++)
            {
                if (MotionName == TemplateMot[k].name)
                {
                    IsDuplicate = TRUE;
                    DupIdx = k;
                    break;
                }
            }

            //
            
            QByteArray ba = PathFileName.toLatin1();
            const char *cstr = ba.data();
            fp = fopen(cstr, "r");  //QString -> char*

            // Read file
            k = 0;
            while(fscanf(fp,"%f %f %f", &(AccX[k]), &(AccY[k]), &(AccZ[k])) != EOF)
            {
                //tmpMotion.acc.append(tmpAcc);

                //AccZ[k] -= 1.0;
                k++;
            }


            // Quantization, 
            Quantize(k, AccX, AccY, AccZ, QuantizeMotion);

            if (IsDuplicate)
            {
                TemplateMot[DupIdx] += QuantizeMotion;
                TemplateMot[DupIdx].DupNum++;
            }
            else
            {
                QuantizeMotion.name = MotionName;
                TemplateMot.append(QuantizeMotion);
            }

            fclose(fp);
        }

        UserDir.cd(UserHomeDir);
    }

    if (MethodCreLib == RESCALE)
    {
        // Rescaling
        for (p = 0; p < TemplateMot.count(); p++)
        {
            Rescale(TemplateMot[p]);
        }
    }

    if (MethodCreLib == AVERAGE)
    {
        // Averaging
        for (p = 0; p < TemplateMot.count(); p++)
        for (q = 0; q < RefPointNum; q++)
        {
            TemplateMot[p].x[q] /= TemplateMot[p].DupNum;
            TemplateMot[p].y[q] /= TemplateMot[p].DupNum;
            TemplateMot[p].z[q] /= TemplateMot[p].DupNum;
        }
    }

    QDateTime CurTime = QDateTime::currentDateTime();
    QString TimeStr = CurTime.toString("yyyy-MM-dd_hh.mm.ss");

    TemplateDir.cd(TemplateDir.absolutePath());
    TemplateDir.mkdir(TimeStr);
    TemplateDir.cd(TimeStr);

    //TemplateMot.clear();
    // Write template files
    for (p = 0; p < TemplateMot.count(); p++)
    {
        PathFileName = TemplateDir.absolutePath() + "/" + TemplateMot[p].name + ".ref";
        QByteArray ba1 = PathFileName.toLatin1();
        const char *cstr1 = ba1.data();

        fp = fopen(cstr1, "w");

        for (q = 0; q < RefPointNum; q++)
        {
            fprintf(fp, "%10f%10f%10f\n", TemplateMot[p].x[q], TemplateMot[p].y[q], TemplateMot[p].z[q]);
        }

        fclose(fp);
    }

    // Write readme file
    PathFileName = TemplateDir.absolutePath() + "/" + "readme.txt";
    QByteArray ba2 = PathFileName.toLatin1();
    const char *cstr2 = ba2.data();

    fp = fopen(cstr2, "w");

    fprintf(fp, "Create template method: %d\n\n", MethodCreLib);
    fprintf(fp, "From user:\n");
    for (p = 0; p < UserList.count(); p++)
        fprintf(fp, "%s\n", UserList[p]->text().toLatin1().data());

    fclose(fp);

    GestureList.clear();
    // Write to GestureList
    CGesture tmp;
    for (p = 0; p < TemplateMot.count(); p++)
    {
        tmp.name = TemplateMot[p].name;
        tmp.SimDist = TemplateMot[p].SimDist;
        GestureList.append(tmp);
    }
    //p = GestureList.count();
}

QString CAlgo::Recognize(const CMotion& mot, QList<CMotion>& TemplateMot)
{
    int k, MinIdx = 0;
    FLOAT MinDist = 1000000.0;

    for (k = 0; k < TemplateMot.count(); k++)
    {
        TemplateMot[k].SimDist = CalDtw(mot, TemplateMot[k]);

        if (MinDist > TemplateMot[k].SimDist)
        {
            MinIdx = k;
            MinDist = TemplateMot[k].SimDist;
        }

        printf ("%f\n", TemplateMot[k].SimDist);
    }

    return TemplateMot[MinIdx].name;
}

int CAlgo::StaticGestureRecognize(const gforce_t *acc)
{
    int k, gesture=0;
    float avx = 0, avy = 0, avz = 0, square;
    
    if (PointNum < WIN_SIZE)
        return 0;

    // Calculate average x, y, z
    for (k = PointNum - WIN_SIZE; k < PointNum; k++)
    {
        avx += acc[k].x;
        avy += acc[k].y;
        avz += acc[k].z;
    }

    avx /= WIN_SIZE;
    avy /= WIN_SIZE;
    avz /= WIN_SIZE;

    square = avx*avx + avy*avy +avz*avz;

    // Out of static state
    if (square > 1 + STATIC_THRESGOLD)
        return 0;

    //if (fabs(avx) <= TILT_THRESGOLD && fabs(avy) <= TILT_THRESGOLD && fabs(avz) <= 1+TILT_THRESGOLD)
      //  gesture = STATIC;
    else if (avx > TILT_THRESGOLD && fabs(avy) <= TILT_THRESGOLD && fabs(avz) <= 1+TILT_THRESGOLD)
        gesture = TILT_RIGHT;
    else if (avx <= 0 - TILT_THRESGOLD && fabs(avy) <= TILT_THRESGOLD && fabs(avz) <= 1+TILT_THRESGOLD)
        gesture = TILT_LEFT;
    else if (fabs(avx) <= TILT_THRESGOLD && avy > TILT_THRESGOLD && fabs(avz) <= 1+TILT_THRESGOLD)
        gesture = TILT_DOWN;
    else if (fabs(avx) <= TILT_THRESGOLD && avy <= 0 - TILT_THRESGOLD && fabs(avz) <= 1+TILT_THRESGOLD)
        gesture = TILT_UP;

    if (gesture)
        static_gesture_flag = gesture;

    return gesture;
}

void CAlgo::Sort(int type)
{
    FLOAT MinValue;
    QString MinStr;
    int k, p, MinIdx = 0;
    CGesture MinGest;

    for (k = 0; k < TemplateMot.count(); k++)
    {
        GestureList[k].name = TemplateMot[k].name;
        GestureList[k].SimDist = TemplateMot[k].SimDist;
    }

    for (k = 0; k < GestureList.count(); k++)
    {
        MinValue = GestureList[k].SimDist;
        MinStr = GestureList[k].name;
        MinIdx = k;

        for (p = k+1; p < GestureList.count(); p++)
        {
            if (type == 1 && (GestureList[p].SimDist < MinValue))
            {
                MinValue = GestureList[p].SimDist;
                MinIdx = p;
            }

            if (type == 2 && (GestureList[p].name < MinStr))
            {
                MinStr = GestureList[p].name;
                MinIdx = p;
            }
        }

        MinGest = GestureList[k];
        GestureList[k] = GestureList[MinIdx];
        GestureList[MinIdx] = MinGest;

    }
}
