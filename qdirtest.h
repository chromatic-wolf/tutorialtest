#ifndef QDIRTEST_H
#define QDIRTEST_H
#include <QString>

class qdirtest
{
public:
    qdirtest();
    bool createDir(QString path);
    bool renameDir(QString path, QString name);
    bool removeDirRecursive(QString path);
    bool removeDir(QString path);

};

#endif // QDIRTEST_H
