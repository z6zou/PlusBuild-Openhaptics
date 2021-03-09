/********************************************************************************
** Form generated from reading UI file 'QCapturingToolbox.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCAPTURINGTOOLBOX_H
#define UI_QCAPTURINGTOOLBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CapturingToolbox
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_State;
    QFrame *line;
    QHBoxLayout *horizontalLayout_fCalCapture;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Record;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Snapshot;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *label_NumberOfRecordedFramesText;
    QLabel *label_NumberOfRecordedFrames;
    QLabel *label;
    QLabel *label_ActualRecordingFrameRateText;
    QLabel *label_ActualRecordingFrameRate;
    QLabel *label_RequestedRecordingFrameRate;
    QSlider *horizontalSlider_SamplingRate;
    QLabel *label_RequestedRecordingFrameRateText;
    QLabel *label_MaximumRecordingFrameRateText;
    QLabel *label_MaximumRecordingFrameRate;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_Actions;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_Save;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_ClearRecordedFrames;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_SaveAs;
    QSpacerItem *horizontalSpacer_7;
    QPlainTextEdit *plainTextEdit_saveResult;
    QHBoxLayout *horizontalLayout_CaptureDeviceGlobalActions;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_StartStopAll;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_SaveAll;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_ClearAll;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *collapsingVerticalSpacer;

    void setupUi(QWidget *CapturingToolbox)
    {
        if (CapturingToolbox->objectName().isEmpty())
            CapturingToolbox->setObjectName(QStringLiteral("CapturingToolbox"));
        CapturingToolbox->resize(402, 540);
        CapturingToolbox->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(CapturingToolbox);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 4, 0, 4);
        label_State = new QLabel(CapturingToolbox);
        label_State->setObjectName(QStringLiteral("label_State"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_State->setFont(font);
        label_State->setWordWrap(true);

        verticalLayout->addWidget(label_State);

        line = new QFrame(CapturingToolbox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_fCalCapture = new QHBoxLayout();
        horizontalLayout_fCalCapture->setSpacing(0);
        horizontalLayout_fCalCapture->setObjectName(QStringLiteral("horizontalLayout_fCalCapture"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_fCalCapture->addItem(horizontalSpacer_2);

        pushButton_Record = new QPushButton(CapturingToolbox);
        pushButton_Record->setObjectName(QStringLiteral("pushButton_Record"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_Record->sizePolicy().hasHeightForWidth());
        pushButton_Record->setSizePolicy(sizePolicy);
        pushButton_Record->setMinimumSize(QSize(80, 23));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/Resources/icon_Record.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Record->setIcon(icon);

        horizontalLayout_fCalCapture->addWidget(pushButton_Record);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_fCalCapture->addItem(horizontalSpacer);

        pushButton_Snapshot = new QPushButton(CapturingToolbox);
        pushButton_Snapshot->setObjectName(QStringLiteral("pushButton_Snapshot"));
        sizePolicy.setHeightForWidth(pushButton_Snapshot->sizePolicy().hasHeightForWidth());
        pushButton_Snapshot->setSizePolicy(sizePolicy);
        pushButton_Snapshot->setMinimumSize(QSize(90, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/Resources/icon_Snapshot.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Snapshot->setIcon(icon1);

        horizontalLayout_fCalCapture->addWidget(pushButton_Snapshot);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_fCalCapture->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_fCalCapture);

        verticalSpacer = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_NumberOfRecordedFramesText = new QLabel(CapturingToolbox);
        label_NumberOfRecordedFramesText->setObjectName(QStringLiteral("label_NumberOfRecordedFramesText"));
        label_NumberOfRecordedFramesText->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(label_NumberOfRecordedFramesText, 0, 0, 1, 1);

        label_NumberOfRecordedFrames = new QLabel(CapturingToolbox);
        label_NumberOfRecordedFrames->setObjectName(QStringLiteral("label_NumberOfRecordedFrames"));
        label_NumberOfRecordedFrames->setFont(font);
        label_NumberOfRecordedFrames->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_NumberOfRecordedFrames, 0, 1, 1, 1);

        label = new QLabel(CapturingToolbox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_ActualRecordingFrameRateText = new QLabel(CapturingToolbox);
        label_ActualRecordingFrameRateText->setObjectName(QStringLiteral("label_ActualRecordingFrameRateText"));
        label_ActualRecordingFrameRateText->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(label_ActualRecordingFrameRateText, 3, 0, 1, 1);

        label_ActualRecordingFrameRate = new QLabel(CapturingToolbox);
        label_ActualRecordingFrameRate->setObjectName(QStringLiteral("label_ActualRecordingFrameRate"));
        label_ActualRecordingFrameRate->setFont(font);
        label_ActualRecordingFrameRate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_ActualRecordingFrameRate, 3, 1, 1, 1);

        label_RequestedRecordingFrameRate = new QLabel(CapturingToolbox);
        label_RequestedRecordingFrameRate->setObjectName(QStringLiteral("label_RequestedRecordingFrameRate"));
        label_RequestedRecordingFrameRate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_RequestedRecordingFrameRate, 2, 1, 1, 1);

        horizontalSlider_SamplingRate = new QSlider(CapturingToolbox);
        horizontalSlider_SamplingRate->setObjectName(QStringLiteral("horizontalSlider_SamplingRate"));
        horizontalSlider_SamplingRate->setMaximum(10);
        horizontalSlider_SamplingRate->setSingleStep(1);
        horizontalSlider_SamplingRate->setValue(10);
        horizontalSlider_SamplingRate->setSliderPosition(10);
        horizontalSlider_SamplingRate->setOrientation(Qt::Horizontal);
        horizontalSlider_SamplingRate->setInvertedAppearance(false);
        horizontalSlider_SamplingRate->setInvertedControls(false);
        horizontalSlider_SamplingRate->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_SamplingRate->setTickInterval(1);

        gridLayout->addWidget(horizontalSlider_SamplingRate, 1, 1, 1, 1);

        label_RequestedRecordingFrameRateText = new QLabel(CapturingToolbox);
        label_RequestedRecordingFrameRateText->setObjectName(QStringLiteral("label_RequestedRecordingFrameRateText"));
        label_RequestedRecordingFrameRateText->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(label_RequestedRecordingFrameRateText, 2, 0, 1, 1);

        label_MaximumRecordingFrameRateText = new QLabel(CapturingToolbox);
        label_MaximumRecordingFrameRateText->setObjectName(QStringLiteral("label_MaximumRecordingFrameRateText"));
        label_MaximumRecordingFrameRateText->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(label_MaximumRecordingFrameRateText, 4, 0, 1, 1);

        label_MaximumRecordingFrameRate = new QLabel(CapturingToolbox);
        label_MaximumRecordingFrameRate->setObjectName(QStringLiteral("label_MaximumRecordingFrameRate"));
        label_MaximumRecordingFrameRate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_MaximumRecordingFrameRate, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer_4 = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_Actions = new QHBoxLayout();
        horizontalLayout_Actions->setSpacing(0);
        horizontalLayout_Actions->setObjectName(QStringLiteral("horizontalLayout_Actions"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Actions->addItem(horizontalSpacer_6);

        pushButton_Save = new QPushButton(CapturingToolbox);
        pushButton_Save->setObjectName(QStringLiteral("pushButton_Save"));
        pushButton_Save->setMinimumSize(QSize(60, 0));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/Resources/icon_Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Save->setIcon(icon2);

        horizontalLayout_Actions->addWidget(pushButton_Save);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Actions->addItem(horizontalSpacer_4);

        pushButton_ClearRecordedFrames = new QPushButton(CapturingToolbox);
        pushButton_ClearRecordedFrames->setObjectName(QStringLiteral("pushButton_ClearRecordedFrames"));
        pushButton_ClearRecordedFrames->setMinimumSize(QSize(55, 0));

        horizontalLayout_Actions->addWidget(pushButton_ClearRecordedFrames);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Actions->addItem(horizontalSpacer_5);

        pushButton_SaveAs = new QPushButton(CapturingToolbox);
        pushButton_SaveAs->setObjectName(QStringLiteral("pushButton_SaveAs"));
        pushButton_SaveAs->setMinimumSize(QSize(90, 23));
        pushButton_SaveAs->setIcon(icon2);

        horizontalLayout_Actions->addWidget(pushButton_SaveAs);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Actions->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_Actions);

        plainTextEdit_saveResult = new QPlainTextEdit(CapturingToolbox);
        plainTextEdit_saveResult->setObjectName(QStringLiteral("plainTextEdit_saveResult"));
        plainTextEdit_saveResult->setReadOnly(true);

        verticalLayout->addWidget(plainTextEdit_saveResult);

        horizontalLayout_CaptureDeviceGlobalActions = new QHBoxLayout();
        horizontalLayout_CaptureDeviceGlobalActions->setSpacing(0);
        horizontalLayout_CaptureDeviceGlobalActions->setObjectName(QStringLiteral("horizontalLayout_CaptureDeviceGlobalActions"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_CaptureDeviceGlobalActions->addItem(horizontalSpacer_8);

        pushButton_StartStopAll = new QPushButton(CapturingToolbox);
        pushButton_StartStopAll->setObjectName(QStringLiteral("pushButton_StartStopAll"));
        pushButton_StartStopAll->setMinimumSize(QSize(80, 0));
        pushButton_StartStopAll->setIcon(icon);

        horizontalLayout_CaptureDeviceGlobalActions->addWidget(pushButton_StartStopAll);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_CaptureDeviceGlobalActions->addItem(horizontalSpacer_9);

        pushButton_SaveAll = new QPushButton(CapturingToolbox);
        pushButton_SaveAll->setObjectName(QStringLiteral("pushButton_SaveAll"));
        pushButton_SaveAll->setMinimumSize(QSize(75, 0));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/Resources/icon_SaveAll.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SaveAll->setIcon(icon3);

        horizontalLayout_CaptureDeviceGlobalActions->addWidget(pushButton_SaveAll);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_CaptureDeviceGlobalActions->addItem(horizontalSpacer_10);

        pushButton_ClearAll = new QPushButton(CapturingToolbox);
        pushButton_ClearAll->setObjectName(QStringLiteral("pushButton_ClearAll"));

        horizontalLayout_CaptureDeviceGlobalActions->addWidget(pushButton_ClearAll);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_CaptureDeviceGlobalActions->addItem(horizontalSpacer_11);


        verticalLayout->addLayout(horizontalLayout_CaptureDeviceGlobalActions);

        collapsingVerticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(collapsingVerticalSpacer);


        retranslateUi(CapturingToolbox);

        QMetaObject::connectSlotsByName(CapturingToolbox);
    } // setupUi

    void retranslateUi(QWidget *CapturingToolbox)
    {
        CapturingToolbox->setWindowTitle(QApplication::translate("CapturingToolbox", "Capturing", Q_NULLPTR));
        label_State->setText(QApplication::translate("CapturingToolbox", "ImageToProge transform is absent, spatial calibration needs to be performed.", Q_NULLPTR));
        pushButton_Record->setText(QApplication::translate("CapturingToolbox", "Record", Q_NULLPTR));
        pushButton_Snapshot->setText(QApplication::translate("CapturingToolbox", "Snapshot", Q_NULLPTR));
        label_NumberOfRecordedFramesText->setText(QApplication::translate("CapturingToolbox", "Number of recorded frames:", Q_NULLPTR));
        label_NumberOfRecordedFrames->setText(QApplication::translate("CapturingToolbox", "0", Q_NULLPTR));
        label->setText(QApplication::translate("CapturingToolbox", "Sampling rate:", Q_NULLPTR));
        label_ActualRecordingFrameRateText->setText(QApplication::translate("CapturingToolbox", "Actual recording frame rate (FPS): ", Q_NULLPTR));
        label_ActualRecordingFrameRate->setText(QApplication::translate("CapturingToolbox", "0.0", Q_NULLPTR));
        label_RequestedRecordingFrameRate->setText(QApplication::translate("CapturingToolbox", "0.0", Q_NULLPTR));
        label_RequestedRecordingFrameRateText->setText(QApplication::translate("CapturingToolbox", "Requested recording frame rate (FPS):", Q_NULLPTR));
        label_MaximumRecordingFrameRateText->setText(QApplication::translate("CapturingToolbox", "Maximum recording frame rate (FPS):", Q_NULLPTR));
        label_MaximumRecordingFrameRate->setText(QApplication::translate("CapturingToolbox", "0.0", Q_NULLPTR));
        pushButton_Save->setText(QApplication::translate("CapturingToolbox", "Save", Q_NULLPTR));
        pushButton_ClearRecordedFrames->setText(QApplication::translate("CapturingToolbox", "Clear", Q_NULLPTR));
        pushButton_SaveAs->setText(QApplication::translate("CapturingToolbox", "Save As...", Q_NULLPTR));
        pushButton_StartStopAll->setText(QApplication::translate("CapturingToolbox", "Record All", Q_NULLPTR));
        pushButton_SaveAll->setText(QApplication::translate("CapturingToolbox", "Save All", Q_NULLPTR));
        pushButton_ClearAll->setText(QApplication::translate("CapturingToolbox", "Clear All", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CapturingToolbox: public Ui_CapturingToolbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCAPTURINGTOOLBOX_H
