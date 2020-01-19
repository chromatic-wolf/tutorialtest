#include "xsysinfo.h"
#include <QString>
#include <thread>
#include <qdebug.h>

QString currentCpuArchitecture;
QString buildCpuArchitecture;
QByteArray bootUniqueID;
QString buildAbi;
QString hostBitness;
QString buildBitness;
bool bigEndian;
QString kernalType;
QString kernalVersion;
QString machineHostName;
QByteArray machineUniqueId;
QString prettyProductName;
QString productType;
QString productVersion;

void setCurrentCpuArchitecture();
void setBuildCpuArchitecture();
void setBootUnuqueID();
void setBuildAbi();
void setHostBitness();
void setBuildBitness();
void setEndianess();
void setKernalType();
void setKernalVersion();
void setMachineHostName();
void setMachineUniqueId();
void setPrettyProductName();
void setProductType();
void setProductVersion();


sysInfo::sysInfo()
{
    getAllData(false);
}

sysInfo::sysInfo(bool useThreading)
{
    if(useThreading)
    {
        getAllData(true);
    }else
    {
        getAllData(false);
    }
}

void sysInfo::getAllData()
{
    getAllData(false);
}

void sysInfo::getAllData(bool useThreading)
{
    if(useThreading)
    {
        std::thread t1(setProductVersion);
        std::thread t2(setProductType);
        std::thread t3(setPrettyProductName);
        std::thread t4(setMachineUniqueId);
        std::thread t5(setMachineHostName);
        std::thread t6(setKernalVersion);
        std::thread t7(setKernalType);
        std::thread t8(setCurrentCpuArchitecture);
        std::thread t9(setBuildCpuArchitecture);
        std::thread t10(setBootUnuqueID);
        std::thread t11(setBuildAbi);
        std::thread t12(setHostBitness);
        std::thread t13(setBuildBitness);
        std::thread t14(setEndianess);
    }else
    {
        setProductVersion();
        setProductType();
        setPrettyProductName();
        setMachineUniqueId();
        setMachineHostName();
        setKernalVersion();
        setKernalType();
        setCurrentCpuArchitecture();
        setBuildCpuArchitecture();
        setBootUnuqueID();
        setBuildAbi();
        setHostBitness();
        setBuildBitness();
        setEndianess();
    }
}

void sysInfo::printAll()
{
    qDebug() << "current cpu architecture: " << getCurrentCpuArchitecture();
    qDebug() << "build cpu architecture: " << getBuildCpuArchitecture();
    qDebug() << "boot unique id: " << getBootUniqueID();
    qDebug() << "build Abi: " << getBuildAbi();
    qDebug() << "host bitness " << getHostBitness();
    qDebug() << "build bitness " << getBuildBitness();
    qDebug() << "is bigendian " << isBigEndian();
    qDebug() << "kernal type: " << getKernalType();
    qDebug() << "kernal version: " << getKernalVersion();
    qDebug() << "machine host name: " << getMachineHostName();
    qDebug() << "machine unique ID: " << getMachineUniqueId();
    qDebug() << "pretty product name: " << getPrettyProductName();
    qDebug() << "product type: " << getProductType();
    qDebug() << "product version: " << getProductVersion();
}

void setProductVersion()
{
    productVersion = QSysInfo::productVersion();
}

void setProductType()
{
    productType = QSysInfo::productType();
}

void setPrettyProductName()
{
    prettyProductName = QSysInfo::prettyProductName();
}

void setMachineUniqueId()
{
    machineUniqueId = QSysInfo::machineUniqueId();
}

void setMachineHostName()
{
    machineHostName = QSysInfo::machineHostName();
}

void setKernalVersion()
{
    kernalVersion = QSysInfo::kernelVersion();
}

void setKernalType()
{
    kernalType = QSysInfo::kernelType();
}


void setCurrentCpuArchitecture()
{
    currentCpuArchitecture = QSysInfo::currentCpuArchitecture();
}

void setBuildCpuArchitecture()
{
    buildCpuArchitecture = QSysInfo::buildCpuArchitecture();
}

void setBootUnuqueID()
{
    bootUniqueID = QSysInfo::bootUniqueId();
}

void setBuildAbi()
{
    buildAbi = QSysInfo::buildAbi();
}

void setHostBitness()
{
    if(QSysInfo::currentCpuArchitecture().contains(QLatin1String("64")))
    {
        hostBitness = "64";
    }
    hostBitness = "32";
}

void setBuildBitness()
{
    if(QSysInfo::buildCpuArchitecture().contains(QLatin1String("64")))
    {
        buildBitness = "64";
    }
    buildBitness = "32";
}

void setEndianess()
{
    if(QSysInfo::BigEndian)
    {
        bigEndian = true;
    } else if(QSysInfo::LittleEndian)
    {
        bigEndian = false;
    }
}


bool sysInfo::isHost64Bit() {
    if(currentCpuArchitecture.contains(QLatin1String("64")))
    {
        return true;
    }
    return false;
}
bool sysInfo::isBuild64Bit() {
    if(buildCpuArchitecture.contains(QLatin1String("64")))
    {
        return true;
    }
    return false;
}

bool sysInfo::isBigEndian()
{
    if(bigEndian == true)
    {
        return true;
    }
    return false;
}

bool sysInfo::isLittleEndian()
{
    if(bigEndian == false)
    {
        return true;
    }
    return false;
}

QByteArray sysInfo::getBootUniqueID()
{
    return bootUniqueID;
}

bool sysInfo::compareBootUniqueID(QByteArray id1, QByteArray id2)
{
    if(id1 == id2)
    {
        return true;
    }
    return false;
}

bool sysInfo::compareBootUniqueID(QByteArray id)
{
    if(bootUniqueID == id)
    {
        return true;
    }
    return false;
}

QString sysInfo::getBuildAbi()
{
    return buildAbi;
}

bool sysInfo::compareBuildAbi(QString Abi1, QString Abi2)
{
    if(Abi1 == Abi2)
    {
        return true;
    }
    return false;
}

bool sysInfo::compareBuildAbi(QString Abi)
{
    if(buildAbi == Abi)
    {
        return true;
    }
    return false;
}

QString sysInfo::getBuildCpuArchitecture()
{
    return buildCpuArchitecture;
}

bool sysInfo::compareBuildCpuArchitecture(QString arch1, QString arch2)
{
    if (arch1 == arch2)
    {
        return true;
    }
    return false;
}

bool sysInfo::compareBuildCpuArchitecture(QString arch)
{
    if(buildCpuArchitecture == arch)
    {
        return true;
    }
    return false;
}

QString sysInfo::getCurrentCpuArchitecture()
{
    return currentCpuArchitecture;
}

bool sysInfo::compareCurrentCpuArchitecture(QString arch1, QString arch2)
{
    if(arch1 == arch2)
    {
        return true;
    }
    return false;
}

bool sysInfo::compareCurrentCpuArchitecture(QString arch)
{
    if(arch == currentCpuArchitecture)
    {
        return true;
    }
    return false;
}

QString sysInfo::getKernalType()
{
    return kernalType;
}

bool sysInfo::compareKernalType(QString kernal1, QString kernal2)
{
    if(kernal1 == kernal2)
    {
        return true;
    }
    return false;
}

bool sysInfo::compareKernalType(QString kernal)
{
    if(kernal == kernalType)
    {
        return true;
    }
    return false;
}

QString sysInfo::getKernalVersion()
{
    return kernalVersion;
}

bool sysInfo::compareKernalVersion(QString kernal1, QString kernal2)
{
    if(kernal1 == kernal2)
    {
        return true;
    }
    return false;
}

bool sysInfo::cmpareKernalVersion(QString kernal)
{
    if(kernalVersion == kernal)
    {
        return true;
    }
    return false;
}

QString sysInfo::getMachineHostName()
{
    return machineHostName;
}

bool sysInfo::compareMachineHostName(QString hostName1, QString hostName2)
{
    if(hostName1 == hostName2)
    {
        return true;
    }
    return false;
}

bool sysInfo::compareMachineHostName(QString hostName)
{
    if(machineHostName == hostName)
    {
        return true;
    }
    return false;
}

QByteArray sysInfo::getMachineUniqueId()
{
    return machineUniqueId;
}

bool sysInfo::compareMachineUniqueId(QByteArray uniqueID1, QByteArray uniqueID2)
{
    if (uniqueID1 == uniqueID2)
    {
        return true;
    }
    return false;
}

bool sysInfo::compareMachineUniqueId(QByteArray uniqueID)
{
    if (machineUniqueId == uniqueID)
    {
        return true;
    }
    return false;
}

QString sysInfo::getPrettyProductName()
{
    return prettyProductName;
}

bool sysInfo::comparePrettyProductName(QString prettyProductName1, QString prettyProductName2)
{
    if (prettyProductName1 == prettyProductName2)
    {
        return true;
    }
    return false;
}

bool sysInfo::comparePrettyProductName(QString PrettyProductName)
{
    if (PrettyProductName == prettyProductName)
    {
        return true;
    }
    return false;
}

QString sysInfo::getProductType()
{
    return productType;
}

bool sysInfo::compareProductType(QString productType1, QString productType2)
{
    if(productType1 == productType2)
    {
        return true;
    }
    return false;
}

bool sysInfo::compareProductType(QString ProductType)
{
    if (productType == ProductType)
    {
        return true;
    }
    return false;
}

QString sysInfo::getProductVersion()
{
    return productVersion;
}

bool sysInfo::compareProductVersion(QString productVersion1, QString productVersion2)
{
    if(productVersion1 == productVersion2)
    {
        return true;
    }
    return false;
}

bool sysInfo::compareProductVersion(QString ProductVersion)
{
    if(ProductVersion == productVersion)
    {
        return true;
    }
    return false;
}

QString sysInfo::getHostBitness()
{
    return hostBitness;
}

bool sysInfo::compareHostBitness(QString bitness1, QString bitness2)
{
    if(bitness1 == bitness2)
    {
        return true;
    }
    return false;
}

bool sysInfo::compareHostBitness(QString bitness)
{
    if (hostBitness == bitness)
    {
        return true;
    }
    return false;

}

QString sysInfo::getBuildBitness()
{
    return buildBitness;
}

bool sysInfo::compareBuildBitness(QString bitness1, QString bitness2)
{
    if(bitness1 == bitness2)
    {
        return true;
    }
    return false;
}

bool sysInfo::compareBuildBitness(QString bitness)
{
    if (hostBitness == bitness)
    {
        return true;
    }
    return false;
}







