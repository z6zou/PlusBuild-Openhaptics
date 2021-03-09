/********************************************************************************
** Form generated from reading UI file 'QPlusDeviceSetSelectorWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPLUSDEVICESETSELECTORWIDGET_H
#define UI_QPLUSDEVICESETSELECTORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceSetSelectorWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_ConfigurationDirectory;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_ConfigurationDirectory;
    QPushButton *pushButton_OpenConfigurationDirectory;
    QPushButton *pushButton_RefreshFolder;
    QLabel *label_DeviceSet;
    QHBoxLayout *horizontalLayout_DeviceSetContainer;
    QComboBox *comboBox_DeviceSet;
    QPushButton *pushButton_EditConfiguration;
    QTextEdit *textEdit_Description;
    QHBoxLayout *horizontalLayout_Buttons;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Connect;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ResetTracker;

    void setupUi(QWidget *DeviceSetSelectorWidget)
    {
        if (DeviceSetSelectorWidget->objectName().isEmpty())
            DeviceSetSelectorWidget->setObjectName(QStringLiteral("DeviceSetSelectorWidget"));
        verticalLayout = new QVBoxLayout(DeviceSetSelectorWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_ConfigurationDirectory = new QLabel(DeviceSetSelectorWidget);
        label_ConfigurationDirectory->setObjectName(QStringLiteral("label_ConfigurationDirectory"));

        verticalLayout->addWidget(label_ConfigurationDirectory);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_ConfigurationDirectory = new QLineEdit(DeviceSetSelectorWidget);
        lineEdit_ConfigurationDirectory->setObjectName(QStringLiteral("lineEdit_ConfigurationDirectory"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(8);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_ConfigurationDirectory->sizePolicy().hasHeightForWidth());
        lineEdit_ConfigurationDirectory->setSizePolicy(sizePolicy);
        lineEdit_ConfigurationDirectory->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit_ConfigurationDirectory);

        pushButton_OpenConfigurationDirectory = new QPushButton(DeviceSetSelectorWidget);
        pushButton_OpenConfigurationDirectory->setObjectName(QStringLiteral("pushButton_OpenConfigurationDirectory"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_OpenConfigurationDirectory->sizePolicy().hasHeightForWidth());
        pushButton_OpenConfigurationDirectory->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/Resources/icon_OpenFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_OpenConfigurationDirectory->setIcon(icon);

        horizontalLayout->addWidget(pushButton_OpenConfigurationDirectory);

        pushButton_RefreshFolder = new QPushButton(DeviceSetSelectorWidget);
        pushButton_RefreshFolder->setObjectName(QStringLiteral("pushButton_RefreshFolder"));
        sizePolicy1.setHeightForWidth(pushButton_RefreshFolder->sizePolicy().hasHeightForWidth());
        pushButton_RefreshFolder->setSizePolicy(sizePolicy1);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/Resources/icon_Refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_RefreshFolder->setIcon(icon1);

        horizontalLayout->addWidget(pushButton_RefreshFolder);


        verticalLayout->addLayout(horizontalLayout);

        label_DeviceSet = new QLabel(DeviceSetSelectorWidget);
        label_DeviceSet->setObjectName(QStringLiteral("label_DeviceSet"));

        verticalLayout->addWidget(label_DeviceSet);

        horizontalLayout_DeviceSetContainer = new QHBoxLayout();
        horizontalLayout_DeviceSetContainer->setSpacing(0);
        horizontalLayout_DeviceSetContainer->setObjectName(QStringLiteral("horizontalLayout_DeviceSetContainer"));
        comboBox_DeviceSet = new QComboBox(DeviceSetSelectorWidget);
        comboBox_DeviceSet->setObjectName(QStringLiteral("comboBox_DeviceSet"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(9);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox_DeviceSet->sizePolicy().hasHeightForWidth());
        comboBox_DeviceSet->setSizePolicy(sizePolicy2);
        comboBox_DeviceSet->setMaxVisibleItems(35);

        horizontalLayout_DeviceSetContainer->addWidget(comboBox_DeviceSet);

        pushButton_EditConfiguration = new QPushButton(DeviceSetSelectorWidget);
        pushButton_EditConfiguration->setObjectName(QStringLiteral("pushButton_EditConfiguration"));
        sizePolicy1.setHeightForWidth(pushButton_EditConfiguration->sizePolicy().hasHeightForWidth());
        pushButton_EditConfiguration->setSizePolicy(sizePolicy1);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/Resources/icon_Edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_EditConfiguration->setIcon(icon2);

        horizontalLayout_DeviceSetContainer->addWidget(pushButton_EditConfiguration);


        verticalLayout->addLayout(horizontalLayout_DeviceSetContainer);

        textEdit_Description = new QTextEdit(DeviceSetSelectorWidget);
        textEdit_Description->setObjectName(QStringLiteral("textEdit_Description"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(textEdit_Description->sizePolicy().hasHeightForWidth());
        textEdit_Description->setSizePolicy(sizePolicy3);
        textEdit_Description->setFrameShadow(QFrame::Plain);
        textEdit_Description->setReadOnly(true);

        verticalLayout->addWidget(textEdit_Description);

        horizontalLayout_Buttons = new QHBoxLayout();
        horizontalLayout_Buttons->setSpacing(0);
        horizontalLayout_Buttons->setObjectName(QStringLiteral("horizontalLayout_Buttons"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Buttons->addItem(horizontalSpacer_2);

        pushButton_Connect = new QPushButton(DeviceSetSelectorWidget);
        pushButton_Connect->setObjectName(QStringLiteral("pushButton_Connect"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/Resources/icon_Connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Connect->setIcon(icon3);

        horizontalLayout_Buttons->addWidget(pushButton_Connect);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Buttons->addItem(horizontalSpacer);

        pushButton_ResetTracker = new QPushButton(DeviceSetSelectorWidget);
        pushButton_ResetTracker->setObjectName(QStringLiteral("pushButton_ResetTracker"));

        horizontalLayout_Buttons->addWidget(pushButton_ResetTracker);


        verticalLayout->addLayout(horizontalLayout_Buttons);


        retranslateUi(DeviceSetSelectorWidget);

        QMetaObject::connectSlotsByName(DeviceSetSelectorWidget);
    } // setupUi

    void retranslateUi(QWidget *DeviceSetSelectorWidget)
    {
        DeviceSetSelectorWidget->setWindowTitle(QApplication::translate("DeviceSetSelectorWidget", "Plus Device Set Selector", Q_NULLPTR));
        label_ConfigurationDirectory->setText(QApplication::translate("DeviceSetSelectorWidget", "Device set configuration directory:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_OpenConfigurationDirectory->setToolTip(QApplication::translate("DeviceSetSelectorWidget", "Select other device set configuration directory", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_OpenConfigurationDirectory->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_RefreshFolder->setToolTip(QApplication::translate("DeviceSetSelectorWidget", "Refresh device set list from currently selected configuration directory", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_RefreshFolder->setText(QString());
        label_DeviceSet->setText(QApplication::translate("DeviceSetSelectorWidget", "Device set:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_EditConfiguration->setToolTip(QApplication::translate("DeviceSetSelectorWidget", "Edit configuration file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_EditConfiguration->setText(QString());
        pushButton_Connect->setText(QApplication::translate("DeviceSetSelectorWidget", "Connect", Q_NULLPTR));
        pushButton_ResetTracker->setText(QApplication::translate("DeviceSetSelectorWidget", "Reset Tracker", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DeviceSetSelectorWidget: public Ui_DeviceSetSelectorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPLUSDEVICESETSELECTORWIDGET_H
