#ifndef SYSINFO_H
#define SYSINFO_H
#include <qbytearray.h>

class sysInfo
{
public:
    sysInfo();
    sysInfo(bool useThreading);
    void getAllData();
    void getAllData(bool useThreading);
    void printAll();
    //check build type
    bool isHost64Bit();
    bool isBuild64Bit();
    bool isBigEndian();
    bool isLittleEndian();
    QByteArray getBootUniqueID();
    bool compareBootUniqueID(QByteArray id1, QByteArray id2);
    bool compareBootUniqueID(QByteArray id);
    QString getBuildAbi();
    bool compareBuildAbi(QString Abi1, QString Abi2);
    bool compareBuildAbi(QString Abi);
    QString getBuildCpuArchitecture();
    bool compareBuildCpuArchitecture(QString arch1, QString arch2);
    bool compareBuildCpuArchitecture(QString arch);
    QString getCurrentCpuArchitecture();
    bool compareCurrentCpuArchitecture(QString arch1, QString arch2);
    bool compareCurrentCpuArchitecture(QString arch);
    QString getKernalType();
    bool compareKernalType(QString kernal1, QString kernal2);
    bool compareKernalType(QString kernal);
    QString getKernalVersion();
    bool compareKernalVersion(QString kernal1, QString kernal2);
    bool cmpareKernalVersion(QString kernal);
    QString getMachineHostName();
    bool compareMachineHostName(QString hostName1, QString hostName2);
    bool compareMachineHostName(QString hostName);
    QByteArray getMachineUniqueId();
    bool compareMachineUniqueId(QByteArray uniqueID1, QByteArray uniqueID2);
    bool compareMachineUniqueId(QByteArray uniqueID);
    QString getPrettyProductName();
    bool comparePrettyProductName(QString prettyProductName1, QString prettyProductName2);
    bool comparePrettyProductName(QString prettyProductName);
    QString getProductType();
    bool compareProductType(QString productType1, QString productType2);
    bool compareProductType(QString ProductType);
    QString getProductVersion();
    bool compareProductVersion(QString productVersion1, QString productVersion2);
    bool compareProductVersion(QString ProductVersion);
    QString getHostBitness();
    bool compareHostBitness(QString bitness1, QString bitness2);
    bool compareHostBitness(QString bitness);
    QString getBuildBitness();
    bool compareBuildBitness(QString bitness1, QString bitness2);
    bool compareBuildBitness(QString bitness);

};

#endif // SYSINFO_H
