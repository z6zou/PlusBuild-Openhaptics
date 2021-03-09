/********************************************************************************
** Form generated from reading UI file 'QStylusCalibrationToolbox.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSTYLUSCALIBRATIONTOOLBOX_H
#define UI_QSTYLUSCALIBRATIONTOOLBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StylusCalibrationToolbox
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_State;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelNumberOfStylusCalibrationPoints;
    QSpinBox *spinBox_NumberOfStylusCalibrationPoints;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_1;
    QLabel *label_NumberOfPoints;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_CurrentPositionText;
    QLabel *label_CurrentPosition;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_StylusTipTransformText;
    QLabel *label_StylusTipTransform;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_CalibrationErrorText;
    QLabel *label_CalibrationError;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_Instructions;
    QSpacerItem *verticalSpacer_8;
    QFrame *line;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_StartStop;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *StylusCalibrationToolbox)
    {
        if (StylusCalibrationToolbox->objectName().isEmpty())
            StylusCalibrationToolbox->setObjectName(QStringLiteral("StylusCalibrationToolbox"));
        verticalLayout = new QVBoxLayout(StylusCalibrationToolbox);
        verticalLayout->setSpacing(4);
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 4, 0, 4);
        label_State = new QLabel(StylusCalibrationToolbox);
        label_State->setObjectName(QStringLiteral("label_State"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_State->setFont(font);
        label_State->setWordWrap(true);

        verticalLayout->addWidget(label_State);

        line_2 = new QFrame(StylusCalibrationToolbox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(4);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelNumberOfStylusCalibrationPoints = new QLabel(StylusCalibrationToolbox);
        labelNumberOfStylusCalibrationPoints->setObjectName(QStringLiteral("labelNumberOfStylusCalibrationPoints"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(8);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelNumberOfStylusCalibrationPoints->sizePolicy().hasHeightForWidth());
        labelNumberOfStylusCalibrationPoints->setSizePolicy(sizePolicy);
        labelNumberOfStylusCalibrationPoints->setWordWrap(true);

        horizontalLayout_7->addWidget(labelNumberOfStylusCalibrationPoints);

        spinBox_NumberOfStylusCalibrationPoints = new QSpinBox(StylusCalibrationToolbox);
        spinBox_NumberOfStylusCalibrationPoints->setObjectName(QStringLiteral("spinBox_NumberOfStylusCalibrationPoints"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox_NumberOfStylusCalibrationPoints->sizePolicy().hasHeightForWidth());
        spinBox_NumberOfStylusCalibrationPoints->setSizePolicy(sizePolicy1);
        spinBox_NumberOfStylusCalibrationPoints->setMaximum(2000);
        spinBox_NumberOfStylusCalibrationPoints->setSingleStep(50);
        spinBox_NumberOfStylusCalibrationPoints->setValue(0);

        horizontalLayout_7->addWidget(spinBox_NumberOfStylusCalibrationPoints);


        verticalLayout->addLayout(horizontalLayout_7);

        verticalSpacer_9 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_9);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_1 = new QLabel(StylusCalibrationToolbox);
        label_1->setObjectName(QStringLiteral("label_1"));
        sizePolicy.setHeightForWidth(label_1->sizePolicy().hasHeightForWidth());
        label_1->setSizePolicy(sizePolicy);
        label_1->setWordWrap(true);

        horizontalLayout_2->addWidget(label_1);

        label_NumberOfPoints = new QLabel(StylusCalibrationToolbox);
        label_NumberOfPoints->setObjectName(QStringLiteral("label_NumberOfPoints"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(2);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_NumberOfPoints->sizePolicy().hasHeightForWidth());
        label_NumberOfPoints->setSizePolicy(sizePolicy2);
        label_NumberOfPoints->setFrameShape(QFrame::NoFrame);
        label_NumberOfPoints->setFrameShadow(QFrame::Plain);
        label_NumberOfPoints->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_NumberOfPoints);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(4);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_CurrentPositionText = new QLabel(StylusCalibrationToolbox);
        label_CurrentPositionText->setObjectName(QStringLiteral("label_CurrentPositionText"));
        sizePolicy.setHeightForWidth(label_CurrentPositionText->sizePolicy().hasHeightForWidth());
        label_CurrentPositionText->setSizePolicy(sizePolicy);
        label_CurrentPositionText->setWordWrap(true);

        horizontalLayout_6->addWidget(label_CurrentPositionText);

        label_CurrentPosition = new QLabel(StylusCalibrationToolbox);
        label_CurrentPosition->setObjectName(QStringLiteral("label_CurrentPosition"));
        sizePolicy2.setHeightForWidth(label_CurrentPosition->sizePolicy().hasHeightForWidth());
        label_CurrentPosition->setSizePolicy(sizePolicy2);
        label_CurrentPosition->setMinimumSize(QSize(0, 0));
        label_CurrentPosition->setFrameShape(QFrame::NoFrame);
        label_CurrentPosition->setFrameShadow(QFrame::Plain);
        label_CurrentPosition->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_CurrentPosition);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_7 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(4);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_StylusTipTransformText = new QLabel(StylusCalibrationToolbox);
        label_StylusTipTransformText->setObjectName(QStringLiteral("label_StylusTipTransformText"));
        sizePolicy.setHeightForWidth(label_StylusTipTransformText->sizePolicy().hasHeightForWidth());
        label_StylusTipTransformText->setSizePolicy(sizePolicy);
        label_StylusTipTransformText->setWordWrap(true);

        horizontalLayout_5->addWidget(label_StylusTipTransformText);

        label_StylusTipTransform = new QLabel(StylusCalibrationToolbox);
        label_StylusTipTransform->setObjectName(QStringLiteral("label_StylusTipTransform"));
        sizePolicy2.setHeightForWidth(label_StylusTipTransform->sizePolicy().hasHeightForWidth());
        label_StylusTipTransform->setSizePolicy(sizePolicy2);
        label_StylusTipTransform->setMinimumSize(QSize(0, 0));
        label_StylusTipTransform->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_StylusTipTransform);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_6 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_CalibrationErrorText = new QLabel(StylusCalibrationToolbox);
        label_CalibrationErrorText->setObjectName(QStringLiteral("label_CalibrationErrorText"));
        sizePolicy.setHeightForWidth(label_CalibrationErrorText->sizePolicy().hasHeightForWidth());
        label_CalibrationErrorText->setSizePolicy(sizePolicy);
        label_CalibrationErrorText->setWordWrap(true);

        horizontalLayout_4->addWidget(label_CalibrationErrorText);

        label_CalibrationError = new QLabel(StylusCalibrationToolbox);
        label_CalibrationError->setObjectName(QStringLiteral("label_CalibrationError"));
        sizePolicy2.setHeightForWidth(label_CalibrationError->sizePolicy().hasHeightForWidth());
        label_CalibrationError->setSizePolicy(sizePolicy2);
        label_CalibrationError->setMinimumSize(QSize(0, 26));
        label_CalibrationError->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_CalibrationError);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_3 = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        label_Instructions = new QLabel(StylusCalibrationToolbox);
        label_Instructions->setObjectName(QStringLiteral("label_Instructions"));
        label_Instructions->setFont(font);
        label_Instructions->setWordWrap(true);

        verticalLayout->addWidget(label_Instructions);

        verticalSpacer_8 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_8);

        line = new QFrame(StylusCalibrationToolbox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalSpacer_2 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_StartStop = new QPushButton(StylusCalibrationToolbox);
        pushButton_StartStop->setObjectName(QStringLiteral("pushButton_StartStop"));
        pushButton_StartStop->setEnabled(false);
        pushButton_StartStop->setMinimumSize(QSize(80, 23));

        horizontalLayout->addWidget(pushButton_StartStop);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(StylusCalibrationToolbox);

        QMetaObject::connectSlotsByName(StylusCalibrationToolbox);
    } // setupUi

    void retranslateUi(QWidget *StylusCalibrationToolbox)
    {
        StylusCalibrationToolbox->setWindowTitle(QApplication::translate("StylusCalibrationToolbox", "Stylus calibration", Q_NULLPTR));
        label_State->setText(QApplication::translate("StylusCalibrationToolbox", "StylusTipToStylus transform is absent, calibration needs to be performed.", Q_NULLPTR));
        labelNumberOfStylusCalibrationPoints->setText(QApplication::translate("StylusCalibrationToolbox", "Number of points for stylus calibration:", Q_NULLPTR));
        label_1->setText(QApplication::translate("StylusCalibrationToolbox", "Number of aquired points:", Q_NULLPTR));
        label_NumberOfPoints->setText(QApplication::translate("StylusCalibrationToolbox", "N/A", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_CurrentPositionText->setToolTip(QApplication::translate("StylusCalibrationToolbox", "In reference tool coordinate system", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_CurrentPositionText->setText(QApplication::translate("StylusCalibrationToolbox", "Current stylus position (mm):", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_CurrentPosition->setToolTip(QApplication::translate("StylusCalibrationToolbox", "In reference tool coordinate system", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_CurrentPosition->setText(QApplication::translate("StylusCalibrationToolbox", "N/A", Q_NULLPTR));
        label_StylusTipTransformText->setText(QApplication::translate("StylusCalibrationToolbox", "Stylus tip translation (mm):", Q_NULLPTR));
        label_StylusTipTransform->setText(QApplication::translate("StylusCalibrationToolbox", "N/A", Q_NULLPTR));
        label_CalibrationErrorText->setText(QApplication::translate("StylusCalibrationToolbox", "Calibration error:", Q_NULLPTR));
        label_CalibrationError->setText(QApplication::translate("StylusCalibrationToolbox", "N/A", Q_NULLPTR));
        label_Instructions->setText(QApplication::translate("StylusCalibrationToolbox", "Instructions", Q_NULLPTR));
        pushButton_StartStop->setText(QApplication::translate("StylusCalibrationToolbox", "Start", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StylusCalibrationToolbox: public Ui_StylusCalibrationToolbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSTYLUSCALIBRATIONTOOLBOX_H
