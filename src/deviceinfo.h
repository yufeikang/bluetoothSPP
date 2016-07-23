#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <QDialog>
#include <qbluetoothaddress.h>
#include <qbluetoothservicediscoveryagent.h>
#include <qbluetoothserviceinfo.h>
#include <qbluetoothlocaldevice.h>
#include <qbluetoothuuid.h>

namespace Ui {
class deviceInfo;
}

class deviceInfo : public QDialog
{
    Q_OBJECT

public:
    explicit deviceInfo(QWidget *parent = 0);
    deviceInfo(QWidget *parent,QBluetoothDeviceInfo deviceinfo);
    ~deviceInfo();

public slots:
    void closeSelf();
    void discoveredFinished();
    void serviceDiscovered(const QBluetoothServiceInfo &info);

private:
    Ui::deviceInfo *ui;
    QBluetoothDeviceInfo device;
    QBluetoothServiceDiscoveryAgent* serverAgent;
};

#endif // DEVICEINFO_H
