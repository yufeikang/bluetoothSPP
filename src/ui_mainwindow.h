/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *pushButton_search;
    QPushButton *pushButton_connect;
    QComboBox *comboBox_device;
    QPushButton *pushButton_device_info;
    QTextBrowser *textBrowser_rx;
    QTextEdit *textEdit_tx;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_clean_rx;
    QPushButton *pushButton_clean_tx;
    QCheckBox *checkBox_auto_new_line;
    QCheckBox *checkBox_show_hex;
    QCheckBox *checkBox_hex_send;
    QPushButton *pushButton_send;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(728, 445);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(29, 9, 181, 171));
        pushButton_search = new QPushButton(groupBox);
        pushButton_search->setObjectName(QStringLiteral("pushButton_search"));
        pushButton_search->setGeometry(QRect(10, 60, 161, 22));
        pushButton_connect = new QPushButton(groupBox);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setGeometry(QRect(10, 90, 161, 22));
        comboBox_device = new QComboBox(groupBox);
        comboBox_device->setObjectName(QStringLiteral("comboBox_device"));
        comboBox_device->setGeometry(QRect(10, 30, 161, 22));
        pushButton_device_info = new QPushButton(groupBox);
        pushButton_device_info->setObjectName(QStringLiteral("pushButton_device_info"));
        pushButton_device_info->setGeometry(QRect(10, 120, 161, 22));
        textBrowser_rx = new QTextBrowser(centralWidget);
        textBrowser_rx->setObjectName(QStringLiteral("textBrowser_rx"));
        textBrowser_rx->setGeometry(QRect(230, 10, 481, 271));
        textEdit_tx = new QTextEdit(centralWidget);
        textEdit_tx->setObjectName(QStringLiteral("textEdit_tx"));
        textEdit_tx->setGeometry(QRect(230, 310, 401, 70));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 190, 181, 191));
        pushButton_clean_rx = new QPushButton(groupBox_2);
        pushButton_clean_rx->setObjectName(QStringLiteral("pushButton_clean_rx"));
        pushButton_clean_rx->setGeometry(QRect(10, 30, 80, 22));
        pushButton_clean_tx = new QPushButton(groupBox_2);
        pushButton_clean_tx->setObjectName(QStringLiteral("pushButton_clean_tx"));
        pushButton_clean_tx->setGeometry(QRect(90, 30, 80, 22));
        checkBox_auto_new_line = new QCheckBox(groupBox_2);
        checkBox_auto_new_line->setObjectName(QStringLiteral("checkBox_auto_new_line"));
        checkBox_auto_new_line->setGeometry(QRect(10, 60, 85, 20));
        checkBox_show_hex = new QCheckBox(groupBox_2);
        checkBox_show_hex->setObjectName(QStringLiteral("checkBox_show_hex"));
        checkBox_show_hex->setGeometry(QRect(10, 90, 85, 20));
        checkBox_hex_send = new QCheckBox(groupBox_2);
        checkBox_hex_send->setObjectName(QStringLiteral("checkBox_hex_send"));
        checkBox_hex_send->setGeometry(QRect(10, 120, 85, 20));
        pushButton_send = new QPushButton(centralWidget);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setGeometry(QRect(640, 311, 80, 71));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 728, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\350\256\276\345\244\207", 0));
        pushButton_search->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", 0));
        pushButton_connect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", 0));
        pushButton_device_info->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\344\277\241\346\201\257", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\223\215\344\275\234", 0));
        pushButton_clean_rx->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266", 0));
        pushButton_clean_tx->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\345\217\221\351\200\201", 0));
        checkBox_auto_new_line->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\346\215\242\350\241\214", 0));
        checkBox_show_hex->setText(QApplication::translate("MainWindow", "16\350\277\233\345\210\266\346\230\276\347\244\272", 0));
        checkBox_hex_send->setText(QApplication::translate("MainWindow", "16\350\277\233\345\210\266\345\217\221\351\200\201", 0));
        pushButton_send->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
