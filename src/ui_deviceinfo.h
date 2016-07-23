/********************************************************************************
** Form generated from reading UI file 'deviceinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEINFO_H
#define UI_DEVICEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_deviceInfo
{
public:
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QProgressBar *progressBar;

    void setupUi(QDialog *deviceInfo)
    {
        if (deviceInfo->objectName().isEmpty())
            deviceInfo->setObjectName(QStringLiteral("deviceInfo"));
        deviceInfo->resize(400, 367);
        pushButton = new QPushButton(deviceInfo);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 320, 341, 22));
        textBrowser = new QTextBrowser(deviceInfo);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(35, 21, 331, 281));
        progressBar = new QProgressBar(deviceInfo);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(130, 140, 118, 23));
        progressBar->setValue(24);

        retranslateUi(deviceInfo);

        QMetaObject::connectSlotsByName(deviceInfo);
    } // setupUi

    void retranslateUi(QDialog *deviceInfo)
    {
        deviceInfo->setWindowTitle(QApplication::translate("deviceInfo", "Dialog", 0));
        pushButton->setText(QApplication::translate("deviceInfo", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class deviceInfo: public Ui_deviceInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEINFO_H
