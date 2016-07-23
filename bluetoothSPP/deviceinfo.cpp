#include "deviceinfo.h"
#include "ui_deviceinfo.h"

deviceInfo::deviceInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deviceInfo)
{
    ui->setupUi(this);
    setWindowTitle("设备信息");
}

deviceInfo::deviceInfo(QWidget *parent, QBluetoothDeviceInfo info):
    QDialog(parent),
    ui(new Ui::deviceInfo)
{
    //deviceInfo(parent);
    device = info;
    ui->setupUi(this);

    setWindowTitle("设备信息");
    serverAgent = new QBluetoothServiceDiscoveryAgent();
    connect(serverAgent,SIGNAL(finished()),this,SLOT(discoveredFinished()));
    connect(serverAgent,SIGNAL(serviceDiscovered(QBluetoothServiceInfo)),
            this,SLOT(serviceDiscovered(QBluetoothServiceInfo)));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(closeSelf()));
    serverAgent->setRemoteAddress(info.address());

    ui->textBrowser->insertHtml("<h4>设备信息</h4><br>");
    ui->textBrowser->insertPlainText("=========================\r");
    ui->textBrowser->insertHtml("<b>设备名字:</b>"+info.name()+"<br>");
    ui->textBrowser->insertHtml("<b>设备地址:</b>"+info.address().toString()+"<br>");
    serverAgent->start();
}

deviceInfo::~deviceInfo()
{
    delete ui;
    delete serverAgent;
}

void deviceInfo::closeSelf()
{
    close();
    delete this;
}

void deviceInfo::discoveredFinished()
{
    ui->progressBar->hide();
}

void deviceInfo::serviceDiscovered(const QBluetoothServiceInfo &info)
{
    ui->textBrowser->insertHtml("<b>服务：</b>"+info.serviceName()+"<br>");
    ui->textBrowser->insertHtml("<b>服务Provider：</b>"+info.serviceProvider()+"<br>");
    ui->textBrowser->insertHtml("<b>服务Description：</b>"+info.serviceDescription()+"<br>");
    ui->textBrowser->insertHtml("<b>服务UUID：</b>"+info.serviceUuid().toString()+"<br>");
    ui->progressBar->setValue(ui->progressBar->value()+1);
}
