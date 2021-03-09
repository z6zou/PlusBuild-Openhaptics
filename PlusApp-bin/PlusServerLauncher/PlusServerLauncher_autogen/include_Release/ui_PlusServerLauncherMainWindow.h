/********************************************************************************
** Form generated from reading UI file 'PlusServerLauncherMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLUSSERVERLAUNCHERMAINWINDOW_H
#define UI_PLUSSERVERLAUNCHERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlusServerLauncherMainWindow
{
public:
    QWidget *mainWidget;
    QVBoxLayout *mainLayout;
    QTabWidget *tabWidget;
    QWidget *localControl_tab;
    QVBoxLayout *localControlTabLayout;
    QWidget *centralWidget;
    QVBoxLayout *centralLayout;
    QWidget *placeholder;
    QWidget *widget_LogLevelContainer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_LogLevel;
    QComboBox *comboBox_LogLevel;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *compressingSpacer;
    QWidget *remoteControl_tab;
    QVBoxLayout *remoteControlTabLayout;
    QWidget *remoteControlWidget;
    QVBoxLayout *remoteControlLayout;
    QTableWidget *serverTable;
    QGroupBox *groupBox_RemoteSettings;
    QGridLayout *gridLayout;
    QLabel *label_networkDetails;
    QCheckBox *checkBox_overwritePermission;
    QCheckBox *checkBox_writePermission;
    QLabel *label_networkDetailsCaption;
    QFrame *statusBarSeparator;
    QFrame *statusBarFrame;
    QHBoxLayout *statusBarLayout;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *PlusServerLauncherMainWindow)
    {
        if (PlusServerLauncherMainWindow->objectName().isEmpty())
            PlusServerLauncherMainWindow->setObjectName(QStringLiteral("PlusServerLauncherMainWindow"));
        PlusServerLauncherMainWindow->resize(480, 366);
        PlusServerLauncherMainWindow->setMinimumSize(QSize(480, 320));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/Resources/icon_ConnectLarge.ico"), QSize(), QIcon::Normal, QIcon::Off);
        PlusServerLauncherMainWindow->setWindowIcon(icon);
        mainWidget = new QWidget(PlusServerLauncherMainWindow);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainWidget->sizePolicy().hasHeightForWidth());
        mainWidget->setSizePolicy(sizePolicy);
        mainLayout = new QVBoxLayout(mainWidget);
        mainLayout->setSpacing(0);
        mainLayout->setContentsMargins(11, 11, 11, 11);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        mainLayout->setContentsMargins(4, 4, 4, 4);
        tabWidget = new QTabWidget(mainWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setAutoFillBackground(true);
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Rounded);
        localControl_tab = new QWidget();
        localControl_tab->setObjectName(QStringLiteral("localControl_tab"));
        localControl_tab->setAutoFillBackground(true);
        localControlTabLayout = new QVBoxLayout(localControl_tab);
        localControlTabLayout->setSpacing(0);
        localControlTabLayout->setContentsMargins(11, 11, 11, 11);
        localControlTabLayout->setObjectName(QStringLiteral("localControlTabLayout"));
        localControlTabLayout->setContentsMargins(0, 0, 0, 0);
        centralWidget = new QWidget(localControl_tab);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(0, 0));
        centralLayout = new QVBoxLayout(centralWidget);
        centralLayout->setSpacing(0);
        centralLayout->setContentsMargins(11, 11, 11, 11);
        centralLayout->setObjectName(QStringLiteral("centralLayout"));
        centralLayout->setContentsMargins(4, 4, 4, 4);
        placeholder = new QWidget(centralWidget);
        placeholder->setObjectName(QStringLiteral("placeholder"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(placeholder->sizePolicy().hasHeightForWidth());
        placeholder->setSizePolicy(sizePolicy1);

        centralLayout->addWidget(placeholder);

        widget_LogLevelContainer = new QWidget(centralWidget);
        widget_LogLevelContainer->setObjectName(QStringLiteral("widget_LogLevelContainer"));
        horizontalLayout = new QHBoxLayout(widget_LogLevelContainer);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 8, 0, 8);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_LogLevel = new QLabel(widget_LogLevelContainer);
        label_LogLevel->setObjectName(QStringLiteral("label_LogLevel"));
        label_LogLevel->setMaximumSize(QSize(400, 30));

        horizontalLayout->addWidget(label_LogLevel);

        comboBox_LogLevel = new QComboBox(widget_LogLevelContainer);
        comboBox_LogLevel->setObjectName(QStringLiteral("comboBox_LogLevel"));
        comboBox_LogLevel->setMinimumSize(QSize(100, 0));
        comboBox_LogLevel->setMaximumSize(QSize(1200, 30));

        horizontalLayout->addWidget(comboBox_LogLevel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(3, 1);

        centralLayout->addWidget(widget_LogLevelContainer);

        compressingSpacer = new QSpacerItem(0, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        centralLayout->addItem(compressingSpacer);


        localControlTabLayout->addWidget(centralWidget);

        tabWidget->addTab(localControl_tab, QString());
        remoteControl_tab = new QWidget();
        remoteControl_tab->setObjectName(QStringLiteral("remoteControl_tab"));
        remoteControl_tab->setAutoFillBackground(true);
        remoteControlTabLayout = new QVBoxLayout(remoteControl_tab);
        remoteControlTabLayout->setSpacing(0);
        remoteControlTabLayout->setContentsMargins(11, 11, 11, 11);
        remoteControlTabLayout->setObjectName(QStringLiteral("remoteControlTabLayout"));
        remoteControlTabLayout->setContentsMargins(0, 0, 0, 0);
        remoteControlWidget = new QWidget(remoteControl_tab);
        remoteControlWidget->setObjectName(QStringLiteral("remoteControlWidget"));
        sizePolicy.setHeightForWidth(remoteControlWidget->sizePolicy().hasHeightForWidth());
        remoteControlWidget->setSizePolicy(sizePolicy);
        remoteControlLayout = new QVBoxLayout(remoteControlWidget);
        remoteControlLayout->setSpacing(6);
        remoteControlLayout->setContentsMargins(11, 11, 11, 11);
        remoteControlLayout->setObjectName(QStringLiteral("remoteControlLayout"));
        serverTable = new QTableWidget(remoteControlWidget);
        serverTable->setObjectName(QStringLiteral("serverTable"));

        remoteControlLayout->addWidget(serverTable);

        groupBox_RemoteSettings = new QGroupBox(remoteControlWidget);
        groupBox_RemoteSettings->setObjectName(QStringLiteral("groupBox_RemoteSettings"));
        gridLayout = new QGridLayout(groupBox_RemoteSettings);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_networkDetails = new QLabel(groupBox_RemoteSettings);
        label_networkDetails->setObjectName(QStringLiteral("label_networkDetails"));
        label_networkDetails->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_networkDetails, 1, 1, 1, 1);

        checkBox_overwritePermission = new QCheckBox(groupBox_RemoteSettings);
        checkBox_overwritePermission->setObjectName(QStringLiteral("checkBox_overwritePermission"));
        checkBox_overwritePermission->setChecked(true);

        gridLayout->addWidget(checkBox_overwritePermission, 3, 0, 1, 1);

        checkBox_writePermission = new QCheckBox(groupBox_RemoteSettings);
        checkBox_writePermission->setObjectName(QStringLiteral("checkBox_writePermission"));
        checkBox_writePermission->setChecked(true);

        gridLayout->addWidget(checkBox_writePermission, 2, 0, 1, 1);

        label_networkDetailsCaption = new QLabel(groupBox_RemoteSettings);
        label_networkDetailsCaption->setObjectName(QStringLiteral("label_networkDetailsCaption"));

        gridLayout->addWidget(label_networkDetailsCaption, 1, 0, 1, 1);


        remoteControlLayout->addWidget(groupBox_RemoteSettings);


        remoteControlTabLayout->addWidget(remoteControlWidget);

        tabWidget->addTab(remoteControl_tab, QString());

        mainLayout->addWidget(tabWidget);

        statusBarSeparator = new QFrame(mainWidget);
        statusBarSeparator->setObjectName(QStringLiteral("statusBarSeparator"));
        statusBarSeparator->setFrameShape(QFrame::HLine);
        statusBarSeparator->setFrameShadow(QFrame::Sunken);

        mainLayout->addWidget(statusBarSeparator);

        statusBarFrame = new QFrame(mainWidget);
        statusBarFrame->setObjectName(QStringLiteral("statusBarFrame"));
        statusBarFrame->setMaximumSize(QSize(1200, 30));
        statusBarFrame->setLayoutDirection(Qt::RightToLeft);
        statusBarLayout = new QHBoxLayout(statusBarFrame);
        statusBarLayout->setSpacing(0);
        statusBarLayout->setContentsMargins(11, 11, 11, 11);
        statusBarLayout->setObjectName(QStringLiteral("statusBarLayout"));
        statusBarLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        statusBarLayout->addItem(horizontalSpacer);


        mainLayout->addWidget(statusBarFrame);

        PlusServerLauncherMainWindow->setCentralWidget(mainWidget);

        retranslateUi(PlusServerLauncherMainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PlusServerLauncherMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PlusServerLauncherMainWindow)
    {
        PlusServerLauncherMainWindow->setWindowTitle(QApplication::translate("PlusServerLauncherMainWindow", "Plus Server Launcher", Q_NULLPTR));
        label_LogLevel->setText(QApplication::translate("PlusServerLauncherMainWindow", "Server log level: ", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(localControl_tab), QApplication::translate("PlusServerLauncherMainWindow", "Local control", Q_NULLPTR));
        groupBox_RemoteSettings->setTitle(QApplication::translate("PlusServerLauncherMainWindow", "Remote Server Settings", Q_NULLPTR));
        label_networkDetails->setText(QString());
        checkBox_overwritePermission->setText(QApplication::translate("PlusServerLauncherMainWindow", "Allow overwrite?", Q_NULLPTR));
        checkBox_writePermission->setText(QApplication::translate("PlusServerLauncherMainWindow", "Allow write?", Q_NULLPTR));
        label_networkDetailsCaption->setText(QApplication::translate("PlusServerLauncherMainWindow", "Server running on:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(remoteControl_tab), QApplication::translate("PlusServerLauncherMainWindow", "Remote control", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlusServerLauncherMainWindow: public Ui_PlusServerLauncherMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUSSERVERLAUNCHERMAINWINDOW_H
