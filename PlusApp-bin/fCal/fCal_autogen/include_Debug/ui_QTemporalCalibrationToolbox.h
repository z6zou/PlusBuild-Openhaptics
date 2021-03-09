/********************************************************************************
** Form generated from reading UI file 'QTemporalCalibrationToolbox.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTEMPORALCALIBRATIONTOOLBOX_H
#define UI_QTEMPORALCALIBRATIONTOOLBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TemporalCalibrationToolbox
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_State;
    QFrame *line_2;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_InstructionsTemporal;
    QSpacerItem *verticalSpacer_5;
    QGridLayout *gridLayout;
    QLabel *label_FixedSeries;
    QLabel *label_MovingSeries;
    QComboBox *comboBox_FixedSourceValue;
    QComboBox *comboBox_MovingSourceValue;
    QComboBox *comboBox_FixedChannelValue;
    QComboBox *comboBox_MovingChannelValue;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_StartCancelTemporal;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ShowPlots;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *TemporalCalibrationToolbox)
    {
        if (TemporalCalibrationToolbox->objectName().isEmpty())
            TemporalCalibrationToolbox->setObjectName(QStringLiteral("TemporalCalibrationToolbox"));
        TemporalCalibrationToolbox->setMinimumSize(QSize(230, 150));
        verticalLayout = new QVBoxLayout(TemporalCalibrationToolbox);
        verticalLayout->setSpacing(4);
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 4, 0, 4);
        label_State = new QLabel(TemporalCalibrationToolbox);
        label_State->setObjectName(QStringLiteral("label_State"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_State->setFont(font);
        label_State->setWordWrap(true);

        verticalLayout->addWidget(label_State);

        line_2 = new QFrame(TemporalCalibrationToolbox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        verticalSpacer_6 = new QSpacerItem(158, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_6);

        label_InstructionsTemporal = new QLabel(TemporalCalibrationToolbox);
        label_InstructionsTemporal->setObjectName(QStringLiteral("label_InstructionsTemporal"));
        label_InstructionsTemporal->setFont(font);
        label_InstructionsTemporal->setWordWrap(true);

        verticalLayout->addWidget(label_InstructionsTemporal);

        verticalSpacer_5 = new QSpacerItem(158, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(4);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_FixedSeries = new QLabel(TemporalCalibrationToolbox);
        label_FixedSeries->setObjectName(QStringLiteral("label_FixedSeries"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_FixedSeries->sizePolicy().hasHeightForWidth());
        label_FixedSeries->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_FixedSeries, 0, 0, 1, 1);

        label_MovingSeries = new QLabel(TemporalCalibrationToolbox);
        label_MovingSeries->setObjectName(QStringLiteral("label_MovingSeries"));
        sizePolicy.setHeightForWidth(label_MovingSeries->sizePolicy().hasHeightForWidth());
        label_MovingSeries->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_MovingSeries, 2, 0, 1, 1);

        comboBox_FixedSourceValue = new QComboBox(TemporalCalibrationToolbox);
        comboBox_FixedSourceValue->setObjectName(QStringLiteral("comboBox_FixedSourceValue"));
        comboBox_FixedSourceValue->setEnabled(false);

        gridLayout->addWidget(comboBox_FixedSourceValue, 1, 1, 1, 1);

        comboBox_MovingSourceValue = new QComboBox(TemporalCalibrationToolbox);
        comboBox_MovingSourceValue->setObjectName(QStringLiteral("comboBox_MovingSourceValue"));
        comboBox_MovingSourceValue->setEnabled(false);

        gridLayout->addWidget(comboBox_MovingSourceValue, 3, 1, 1, 1);

        comboBox_FixedChannelValue = new QComboBox(TemporalCalibrationToolbox);
        comboBox_FixedChannelValue->setObjectName(QStringLiteral("comboBox_FixedChannelValue"));

        gridLayout->addWidget(comboBox_FixedChannelValue, 1, 0, 1, 1);

        comboBox_MovingChannelValue = new QComboBox(TemporalCalibrationToolbox);
        comboBox_MovingChannelValue->setObjectName(QStringLiteral("comboBox_MovingChannelValue"));

        gridLayout->addWidget(comboBox_MovingChannelValue, 3, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(4);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        pushButton_StartCancelTemporal = new QPushButton(TemporalCalibrationToolbox);
        pushButton_StartCancelTemporal->setObjectName(QStringLiteral("pushButton_StartCancelTemporal"));

        horizontalLayout_5->addWidget(pushButton_StartCancelTemporal);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButton_ShowPlots = new QPushButton(TemporalCalibrationToolbox);
        pushButton_ShowPlots->setObjectName(QStringLiteral("pushButton_ShowPlots"));
        pushButton_ShowPlots->setCheckable(true);

        horizontalLayout_5->addWidget(pushButton_ShowPlots);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(158, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(TemporalCalibrationToolbox);

        QMetaObject::connectSlotsByName(TemporalCalibrationToolbox);
    } // setupUi

    void retranslateUi(QWidget *TemporalCalibrationToolbox)
    {
        TemporalCalibrationToolbox->setWindowTitle(QApplication::translate("TemporalCalibrationToolbox", "Temporal Calibration", Q_NULLPTR));
        label_State->setText(QApplication::translate("TemporalCalibrationToolbox", "Temporal calibration is 0.0ms", Q_NULLPTR));
        label_InstructionsTemporal->setText(QApplication::translate("TemporalCalibrationToolbox", "Instructions", Q_NULLPTR));
        label_FixedSeries->setText(QApplication::translate("TemporalCalibrationToolbox", "Fixed (offset=0)", Q_NULLPTR));
        label_MovingSeries->setText(QApplication::translate("TemporalCalibrationToolbox", "Moving (offset=x)", Q_NULLPTR));
        pushButton_StartCancelTemporal->setText(QApplication::translate("TemporalCalibrationToolbox", "Start", Q_NULLPTR));
        pushButton_ShowPlots->setText(QApplication::translate("TemporalCalibrationToolbox", "Show Plots", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TemporalCalibrationToolbox: public Ui_TemporalCalibrationToolbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTEMPORALCALIBRATIONTOOLBOX_H
