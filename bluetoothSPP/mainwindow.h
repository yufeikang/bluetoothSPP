#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qbluetoothglobal.h>
#include <qbluetoothlocaldevice.h>
#include <qbluetoothserviceinfo.h>
#include <vector>
#include "deviceinfo.h"

QT_FORWARD_DECLARE_CLASS(QBluetoothDeviceDiscoveryAgent)
QT_FORWARD_DECLARE_CLASS(ChatClient)

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void addDevice(const QBluetoothDeviceInfo&);

private slots:
    void startScan();
    void scanFinished();
    void deviceSelected(int idx);
    void cleanTx();
    void cleanRx();
    void connectDevice();
    void deviceinfo();
    void showMessage(QString s1,QByteArray s2);
    void clientDisconnected();
    void connected(QString);
    void sendMessageClicked();
signals:
    void sendMessage(QByteArray);

private:
    void referenceDeviceList();
    void getCoreConfigStr(QString& str,const QBluetoothDeviceInfo info);
private:
    Ui::MainWindow *ui;
    bool mIsSearchFinish;
    bool mIsConnected;
    ChatClient *client ;
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QBluetoothLocalDevice *localDevice;
    std::vector<QBluetoothDeviceInfo> mDeviceList;
};

#endif // MAINWINDOW_H
