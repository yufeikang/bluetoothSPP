#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qbluetoothaddress.h>
#include <qbluetoothservicediscoveryagent.h>
#include <qbluetoothserviceinfo.h>
#include <qbluetoothlocaldevice.h>
#include <qbluetoothuuid.h>
#include <qbluetoothsocket.h>
#include "chatclient.h"

static const QLatin1String serviceUuid("e8e10f95-1a70-4b27-9ccf-02010264e9c8");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mIsSearchFinish(false),
    mIsConnected(false)
{
    ui->setupUi(this);
    setWindowTitle("蓝牙SPP By Kang");
    ui->pushButton_connect->setEnabled(false);
    ui->pushButton_send->setEnabled(false);
    localDevice = new QBluetoothLocalDevice();
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent(localDevice->address());
    connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
                this, SLOT(addDevice(QBluetoothDeviceInfo)));
    connect(discoveryAgent, SIGNAL(finished()), this, SLOT(scanFinished()));
    connect(ui->pushButton_search, SIGNAL(clicked()), this, SLOT(startScan()));
    connect(ui->comboBox_device,SIGNAL(activated(int)),this,SLOT(deviceSelected(int)));
    connect(ui->pushButton_clean_rx,SIGNAL(clicked(bool)),this,SLOT(cleanRx()));
    connect(ui->pushButton_clean_tx,SIGNAL(clicked(bool)),this,SLOT(cleanTx()));
    connect(ui->pushButton_device_info,SIGNAL(clicked(bool)),this,SLOT(deviceinfo()));
    connect(ui->pushButton_connect,SIGNAL(clicked(bool)),this,SLOT(connectDevice()));
    connect(ui->pushButton_send,SIGNAL(clicked(bool)),this,SLOT(sendMessageClicked()));
    client = new ChatClient(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete discoveryAgent;
    delete localDevice;
}

void MainWindow::startScan(){
    ui->pushButton_search->setEnabled(false);
    mDeviceList.clear();
    ui->comboBox_device->clear();
    discoveryAgent->start();
}

void MainWindow::scanFinished(){
    ui->pushButton_search->setEnabled(true);
    mIsSearchFinish=true;
}

void MainWindow::deviceSelected(int idx)
{
    QBluetoothDeviceInfo info = mDeviceList[idx];
    QString coreConfigStr;
    getCoreConfigStr(coreConfigStr,info);
    setWindowTitle("蓝牙SPP By Kang | "+info.name()+":"+coreConfigStr);
    if(info.coreConfigurations()==info.BaseRateAndLowEnergyCoreConfiguration
            ||info.coreConfigurations()==info.BaseRateCoreConfiguration){
        ui->pushButton_connect->setText("连接");
        if(mIsSearchFinish){
            ui->pushButton_connect->setEnabled(true);
        }
    }
    else{
        ui->pushButton_connect->setText("不支持");
    }

}

void MainWindow::cleanTx()
{
     ui->textEdit_tx->clear();
}

void MainWindow::cleanRx()
{
    ui->textBrowser_rx->clear();
}

void MainWindow::connectDevice()
{
    if(!mIsConnected){
        QBluetoothDeviceInfo info =mDeviceList[ui->comboBox_device->currentIndex()];


        qDebug() << "Connecting...";

        connect(client, SIGNAL(messageReceived(QString,QByteArray)),
                this, SLOT(showMessage(QString,QByteArray)));
        connect(client, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
        connect(client, SIGNAL(connected(QString)), this, SLOT(connected(QString)));
        connect(this, SIGNAL(sendMessage(QByteArray)), client, SLOT(sendMessage(QByteArray)));
        qDebug() << "Start client";
        QBluetoothServiceInfo server;
        server.setDevice(info);
        QBluetoothUuid uuid(QString("00001101-0000-1000-8000-00805F9B34FB"));
        server.setServiceUuid(uuid);
        client->startClient(server);
        ui->pushButton_connect->setEnabled(false);
    }
    else{
        client->stopClient();
        ui->pushButton_connect->setEnabled(false);
    }



}

void MainWindow::deviceinfo()
{
    if(!mIsSearchFinish){
        return;
    }
    QBluetoothDeviceInfo info =mDeviceList[ui->comboBox_device->currentIndex()];
    deviceInfo* deviceInfoDlg =new deviceInfo(this,info);
    deviceInfoDlg->show();
}

void MainWindow::showMessage(QString sender, QByteArray data)
{
    ui->textBrowser_rx->insertHtml(QString::fromLocal8Bit("<br><font color=\"#00FF00\">================= </font> \
                                    <font color=\"#FF0000\">Send:</font>  \
                                   <font color=\"#0000FF\">")+sender+QString::fromLocal8Bit("</font><font color=\"#00FF00\"> =================</font><br>"));
    QString data_str;
    data_str=QString::fromUtf8(data.data(),data.length());
    if(ui->checkBox_auto_new_line->isChecked()){
        data_str+="\n";
    }
    ui->textBrowser_rx->insertPlainText(data_str);
}

void MainWindow::clientDisconnected()
{
    ui->pushButton_send->setEnabled(false);
    ui->pushButton_connect->setText("连接");
    ui->pushButton_connect->setEnabled(true);
    mIsConnected=false;
    qDebug("clientDisconnected");
}

void MainWindow::connected(QString)
{
    ui->pushButton_send->setEnabled(true);
    ui->pushButton_connect->setEnabled(true);
    ui->pushButton_connect->setText("断开");
    mIsConnected=true;
    qDebug("connected");
}

void MainWindow::sendMessageClicked()
{
    QString text = ui->textEdit_tx->toPlainText();
    if(text.length()>0){
        emit sendMessage(text.toUtf8());
    }
}


void MainWindow::referenceDeviceList()
{
    ui->comboBox_device->clear();
    for(int idx=0;idx<mDeviceList.size();idx++){
        ui->comboBox_device->addItem(mDeviceList[idx].name()+"|"+mDeviceList[idx].address().toString());
    }
}

void MainWindow::getCoreConfigStr(QString& str, const QBluetoothDeviceInfo info)
{
    switch (info.coreConfigurations()) {
    case info.UnknownCoreConfiguration:
        str="UnknownCoreConfiguration";
        break;
    case info.BaseRateCoreConfiguration:
        str="BaseRateCoreConfiguration";
        break;
    case info.BaseRateAndLowEnergyCoreConfiguration:
        str="BaseRateAndLowEnergyCoreConfiguration";
        break;
    case info.LowEnergyCoreConfiguration:
        str="LowEnergyCoreConfiguration";
        break;
    default:
        break;
    }
}


void MainWindow::addDevice(const QBluetoothDeviceInfo &deviceinfo){
    qDebug("new device:%s  %s",deviceinfo.name().toStdString().c_str(),deviceinfo.address().toString().toStdString().c_str());
    QString codeConfig_str;
    switch (deviceinfo.coreConfigurations()) {
    case deviceinfo.UnknownCoreConfiguration:
        codeConfig_str="UnknownCoreConfiguration";
        break;
    case deviceinfo.BaseRateCoreConfiguration:
        codeConfig_str="BaseRateCoreConfiguration";
        break;
    case deviceinfo.BaseRateAndLowEnergyCoreConfiguration:
        codeConfig_str="BaseRateAndLowEnergyCoreConfiguration";
        break;
    case deviceinfo.LowEnergyCoreConfiguration:
        codeConfig_str="LowEnergyCoreConfiguration";
        break;
    default:
        break;
    }
    qDebug("coreConfigurations:%s",codeConfig_str.toStdString().c_str());
    mDeviceList.push_back(deviceinfo);
    referenceDeviceList();

}
