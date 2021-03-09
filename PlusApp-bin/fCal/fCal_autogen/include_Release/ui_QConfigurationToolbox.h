/********************************************************************************
** Form generated from reading UI file 'QConfigurationToolbox.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCONFIGURATIONTOOLBOX_H
#define UI_QCONFIGURATIONTOOLBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigurationToolbox
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *deviceSetSelectionWidget;
    QSpacerItem *verticalSpacer_9;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_PopOut;
    QWidget *toolStateDisplayWidget;
    QFrame *line_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_logLevel;
    QLabel *labelLogLevel;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *comboBox_LogLevel;
    QLabel *label_ImageDirectory;
    QHBoxLayout *horizontalLayout_ImageDirectory;
    QLineEdit *lineEdit_ImageDirectory;
    QPushButton *pushButton_SelectImageDirectory;

    void setupUi(QWidget *ConfigurationToolbox)
    {
        if (ConfigurationToolbox->objectName().isEmpty())
            ConfigurationToolbox->setObjectName(QStringLiteral("ConfigurationToolbox"));
        ConfigurationToolbox->resize(166, 257);
        verticalLayout = new QVBoxLayout(ConfigurationToolbox);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 4, 0, 4);
        deviceSetSelectionWidget = new QWidget(ConfigurationToolbox);
        deviceSetSelectionWidget->setObjectName(QStringLiteral("deviceSetSelectionWidget"));
        deviceSetSelectionWidget->setMinimumSize(QSize(0, 48));

        verticalLayout->addWidget(deviceSetSelectionWidget);

        verticalSpacer_9 = new QSpacerItem(158, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_9);

        line = new QFrame(ConfigurationToolbox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_PopOut = new QPushButton(ConfigurationToolbox);
        pushButton_PopOut->setObjectName(QStringLiteral("pushButton_PopOut"));
        pushButton_PopOut->setMinimumSize(QSize(23, 23));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/Resources/icon_PopOut.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_PopOut->setIcon(icon);
        pushButton_PopOut->setCheckable(true);

        horizontalLayout->addWidget(pushButton_PopOut);


        verticalLayout->addLayout(horizontalLayout);

        toolStateDisplayWidget = new QWidget(ConfigurationToolbox);
        toolStateDisplayWidget->setObjectName(QStringLiteral("toolStateDisplayWidget"));
        toolStateDisplayWidget->setMinimumSize(QSize(0, 48));

        verticalLayout->addWidget(toolStateDisplayWidget);

        line_2 = new QFrame(ConfigurationToolbox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        verticalSpacer_2 = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_logLevel = new QHBoxLayout();
        horizontalLayout_logLevel->setObjectName(QStringLiteral("horizontalLayout_logLevel"));
        labelLogLevel = new QLabel(ConfigurationToolbox);
        labelLogLevel->setObjectName(QStringLiteral("labelLogLevel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelLogLevel->sizePolicy().hasHeightForWidth());
        labelLogLevel->setSizePolicy(sizePolicy);

        horizontalLayout_logLevel->addWidget(labelLogLevel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_logLevel->addItem(horizontalSpacer_2);

        comboBox_LogLevel = new QComboBox(ConfigurationToolbox);
        comboBox_LogLevel->setObjectName(QStringLiteral("comboBox_LogLevel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_LogLevel->sizePolicy().hasHeightForWidth());
        comboBox_LogLevel->setSizePolicy(sizePolicy1);

        horizontalLayout_logLevel->addWidget(comboBox_LogLevel);


        verticalLayout->addLayout(horizontalLayout_logLevel);

        label_ImageDirectory = new QLabel(ConfigurationToolbox);
        label_ImageDirectory->setObjectName(QStringLiteral("label_ImageDirectory"));

        verticalLayout->addWidget(label_ImageDirectory);

        horizontalLayout_ImageDirectory = new QHBoxLayout();
        horizontalLayout_ImageDirectory->setSpacing(0);
        horizontalLayout_ImageDirectory->setObjectName(QStringLiteral("horizontalLayout_ImageDirectory"));
        lineEdit_ImageDirectory = new QLineEdit(ConfigurationToolbox);
        lineEdit_ImageDirectory->setObjectName(QStringLiteral("lineEdit_ImageDirectory"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(9);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_ImageDirectory->sizePolicy().hasHeightForWidth());
        lineEdit_ImageDirectory->setSizePolicy(sizePolicy2);
        lineEdit_ImageDirectory->setReadOnly(true);

        horizontalLayout_ImageDirectory->addWidget(lineEdit_ImageDirectory);

        pushButton_SelectImageDirectory = new QPushButton(ConfigurationToolbox);
        pushButton_SelectImageDirectory->setObjectName(QStringLiteral("pushButton_SelectImageDirectory"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_SelectImageDirectory->sizePolicy().hasHeightForWidth());
        pushButton_SelectImageDirectory->setSizePolicy(sizePolicy3);
        pushButton_SelectImageDirectory->setMinimumSize(QSize(23, 23));
        pushButton_SelectImageDirectory->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/Resources/icon_OpenFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SelectImageDirectory->setIcon(icon1);
        pushButton_SelectImageDirectory->setIconSize(QSize(16, 16));

        horizontalLayout_ImageDirectory->addWidget(pushButton_SelectImageDirectory);


        verticalLayout->addLayout(horizontalLayout_ImageDirectory);


        retranslateUi(ConfigurationToolbox);

        comboBox_LogLevel->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ConfigurationToolbox);
    } // setupUi

    void retranslateUi(QWidget *ConfigurationToolbox)
    {
        ConfigurationToolbox->setWindowTitle(QApplication::translate("ConfigurationToolbox", "Configuration", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_PopOut->setToolTip(QApplication::translate("ConfigurationToolbox", "Pop out (or back) tool state window", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_PopOut->setText(QString());
        labelLogLevel->setText(QApplication::translate("ConfigurationToolbox", "Log level:", Q_NULLPTR));
        comboBox_LogLevel->clear();
        comboBox_LogLevel->insertItems(0, QStringList()
         << QApplication::translate("ConfigurationToolbox", "Error", Q_NULLPTR)
         << QApplication::translate("ConfigurationToolbox", "Warning", Q_NULLPTR)
         << QApplication::translate("ConfigurationToolbox", "Info", Q_NULLPTR)
         << QApplication::translate("ConfigurationToolbox", "Debug", Q_NULLPTR)
         << QApplication::translate("ConfigurationToolbox", "Trace", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_LogLevel->setToolTip(QApplication::translate("ConfigurationToolbox", "Level of log entries that are displayed", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_ImageDirectory->setToolTip(QApplication::translate("ConfigurationToolbox", "Directory that contains the usually used input images (to act as home for relative paths in device set configuration files)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_ImageDirectory->setText(QApplication::translate("ConfigurationToolbox", "Image directory:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        lineEdit_ImageDirectory->setToolTip(QApplication::translate("ConfigurationToolbox", "Directory that contains the usually used input images (to act as home for relative paths in device set configuration files)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButton_SelectImageDirectory->setToolTip(QApplication::translate("ConfigurationToolbox", "Select other device set configuration directory", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_SelectImageDirectory->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ConfigurationToolbox: public Ui_ConfigurationToolbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCONFIGURATIONTOOLBOX_H
