#include <QCoreApplication>
#include <QDebug>
#include "xnetbasiclibstatic.h"
#include "xnetbasiclibstatic.cpp"
#include "xsysinfo.h"
#include "xsysinfo.cpp"
#include <QTime>
#include <QCache>
#include <QFile>
#include <QRandomGenerator>
#include <QVector>
#include <QScopedPointer>
#include <QElapsedTimer>
#include "qpointertest.h"
#include "qscopedptrtest.h"
#include <qmutex.h>
#include <QIODevice>
#include <QBuffer>

QRandomGenerator64 randomGenerator;

void qpointertestfunct()
{
    QObject *obj = new QObject(nullptr);
    obj->setObjectName("My Object");

    QPointer<QObject> p(obj);

    qpointertest t;
    t.widget = p;
    t.useWidget();

    if(p.data()) qInfo() << p.data();

    delete  obj;
    t.useWidget();
}

void hashTests()
{
    QHash<qint64, qint64> hash;

    qint64 i = 0;
    while(i < 10)
    {
        hash.insert(i, randomGenerator.generate64());
        i++;
    }

    hash.clear();

}


void cacheTests()
{
    QCache<int, quint64> cache;
    QCache<int, sysInfo> cache2;
    QVector<quint64> vector1;
    QVector<sysInfo> vector2;


    sysInfo* myPc = new sysInfo;
    sysInfo* myPc2 = new sysInfo;


    int i = 0;
    while(i < 10)
    {
        quint64* value = new quint64(QRandomGenerator::global()->generate64());
        cache.insert(i, value);
        vector1.push_back(quint64(*value));
        i++;

    }
    cache2.insert(1, myPc);
    cache2.insert(2, myPc2);

    vector2.push_back(*myPc);
    vector2.push_back(*myPc2);

    qDebug() << "size of 1000 int cache is" << sizeof (cache);
    qDebug() << "size of sysinfo object cache is" << sizeof ( cache2);
    qDebug() << "size of vector of ints" << sizeof ( vector1);
    qDebug() << "size of vector of sysinfo objects" << sizeof ( vector2);

    QString filename="Data.txt";
    QFile file( filename );
    if (file.open(QIODevice::WriteOnly))
    {
        QDataStream fileStream (&file);
        fileStream.setVersion(QDataStream::Qt_5_12);
        qint64 i2 = 0;
        qDebug() << "size of cache" << cache.size();
        while(i2 < cache.size())
        {
            fileStream << cache.take(i);
            i2++;
        }

        file.flush();
        file.close();
    }else
    {
        qDebug() << "error cant open file";
    }
}

void testComputerInfo()
{
    QTime threadedTimer;
    QTime nonThreadedTimer;

    nonThreadedTimer.start();
    sysInfo* myPc = new sysInfo;
    qDebug() <<"Non Threaded: " << nonThreadedTimer.elapsed();

    threadedTimer.start();
    //sysInfo* myPc2 = new sysInfo(true);
    qDebug() << "Threaded: " << threadedTimer.elapsed();

    myPc->printAll();
    delete myPc;
    //delete myPc2;
    qDebug() << "Creating 64 bit number 999999999999999999";
    qint64 value = Q_INT64_C(999999999999999999);
    qint32 value2 = 2147483647;
    qint16 value3 = 32767;
    qint8 value4 = 127;
    qDebug() << "int64" << value;
    qDebug() << "int32" << value2;
    qDebug() << "int16" << value3;
    qDebug() << "int8" << value4;
}

void usescopedptr(qscopedptrtest* obj)
{
    if(!obj)
    {
        return;
    }
    // qInfo() << "Using" << obj;
}

void scopedptrdostuff()
{
    //    qscopedptrtest *t = new qscopedptrtest(); // creates dangling pointer
    QScopedPointer<qscopedptrtest> mypointer(new qscopedptrtest());
    usescopedptr(mypointer.data());
    //pointer gets deleted out of scope
}

void qbuffertest()
{
    QBuffer buffer;
    if(buffer.open(QIODevice::ReadWrite))
    {
        QByteArray data("Hello test");

        for(int i = 0; i < 5; i++)
        {
            buffer.write(data);
            buffer.write("\r\n");
        }
        //moved to first position
        buffer.seek(0);
        buffer.close();

    }else {
        qInfo() << "Error buffer could not be opened";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QElapsedTimer timer;

    timer.start();
    qpointertestfunct();
    cacheTests();
    for(int i = 0; i < 100; i++)
    {
        scopedptrdostuff();
    }
    qbuffertest();
    hashTests();

    qDebug() << "The slow operation took" << timer.elapsed() << "milliseconds";
    system("pause");
    exit(EXIT_SUCCESS);
    return a.exec();
}
