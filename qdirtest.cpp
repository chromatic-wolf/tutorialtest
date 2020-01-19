#include "qdirtest.h"
#include <QDir>
#include <QDebug>

qdirtest::qdirtest()
{

}

bool qdirtest::createDir(QString path)
{
    QDir dir(path);
    if(dir.exists())
    {
        qInfo() << "Dir allready exists";
        return true;
    }

    if(dir.mkpath(path))
    {

        return true;
    }else {

        return false;
    }
}

bool qdirtest::renameDir(QString path, QString name)
{
    QDir dir (path);
    if(!dir.exists())
    {
        qInfo() << "Path doesnt exist";
        return false;
    }

    int pos = path.lastIndexOf(QDir::separator());
    QString parent = path.mid(0,pos);
    QString newpath = parent + QDir::separator() + name;
    return dir.rename(path,newpath);
}

bool qdirtest::removeDirRecursive(QString path)
{
    QDir dir(path);
    if(!dir.exists())
    {
        qInfo() << "Path doesnt exist";
        return false;
    }
    return dir.removeRecursively();
}

bool qdirtest::removeDir(QString path)
{
    QDir dir(path);
    if(!dir.exists())
    {
        qInfo() << "Path doesnt exist";
        return false;
    }
    return dir.remove(path);
}
