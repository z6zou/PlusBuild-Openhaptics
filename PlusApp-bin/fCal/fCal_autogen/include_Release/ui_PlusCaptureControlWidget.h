/********************************************************************************
** Form generated from reading UI file 'PlusCaptureControlWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLUSCAPTURECONTROLWIDGET_H
#define UI_PLUSCAPTURECONTROLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CaptureControlWidget
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QSlider *samplingRateSlider;
    QLabel *actualFrameRateLabel;
    QLabel *numberOfRecordedFramesLabel;
    QLabel *requestedFrameRateValueLabel;
    QPushButton *saveButton;
    QLabel *requestedSamplingRate;
    QPushButton *saveAsButton;
    QPushButton *snapshotButton;
    QPushButton *clearRecordedFramesButton;
    QLabel *numberOfRecordedFramesValueLabel;
    QPushButton *startStopButton;
    QLabel *requestedFrameRateLabel;
    QLabel *actualFrameRateValueLabel;
    QLabel *channelIdentifierLabel;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *CaptureControlWidget)
    {
        if (CaptureControlWidget->objectName().isEmpty())
            CaptureControlWidget->setObjectName(QStringLiteral("CaptureControlWidget"));
        CaptureControlWidget->setMinimumSize(QSize(215, 90));
        gridLayout_2 = new QGridLayout(CaptureControlWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(CaptureControlWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(215, 90));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(3);
        gridLayout->setContentsMargins(2, 2, 2, 2);
        samplingRateSlider = new QSlider(frame);
        samplingRateSlider->setObjectName(QStringLiteral("samplingRateSlider"));
        samplingRateSlider->setMaximum(10);
        samplingRateSlider->setSingleStep(1);
        samplingRateSlider->setValue(10);
        samplingRateSlider->setSliderPosition(10);
        samplingRateSlider->setOrientation(Qt::Horizontal);
        samplingRateSlider->setInvertedAppearance(false);
        samplingRateSlider->setInvertedControls(false);
        samplingRateSlider->setTickPosition(QSlider::TicksBelow);
        samplingRateSlider->setTickInterval(1);

        gridLayout->addWidget(samplingRateSlider, 2, 2, 1, 5);

        actualFrameRateLabel = new QLabel(frame);
        actualFrameRateLabel->setObjectName(QStringLiteral("actualFrameRateLabel"));
        actualFrameRateLabel->setMinimumSize(QSize(55, 0));

        gridLayout->addWidget(actualFrameRateLabel, 0, 4, 1, 1);

        numberOfRecordedFramesLabel = new QLabel(frame);
        numberOfRecordedFramesLabel->setObjectName(QStringLiteral("numberOfRecordedFramesLabel"));
        numberOfRecordedFramesLabel->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(numberOfRecordedFramesLabel, 1, 4, 1, 1);

        requestedFrameRateValueLabel = new QLabel(frame);
        requestedFrameRateValueLabel->setObjectName(QStringLiteral("requestedFrameRateValueLabel"));
        requestedFrameRateValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(requestedFrameRateValueLabel, 1, 2, 1, 1);

        saveButton = new QPushButton(frame);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setMinimumSize(QSize(0, 21));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/Resources/icon_Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon);

        gridLayout->addWidget(saveButton, 3, 4, 1, 1);

        requestedSamplingRate = new QLabel(frame);
        requestedSamplingRate->setObjectName(QStringLiteral("requestedSamplingRate"));
        requestedSamplingRate->setMinimumSize(QSize(75, 0));

        gridLayout->addWidget(requestedSamplingRate, 2, 0, 1, 1);

        saveAsButton = new QPushButton(frame);
        saveAsButton->setObjectName(QStringLiteral("saveAsButton"));
        saveAsButton->setMinimumSize(QSize(0, 21));
        saveAsButton->setMaximumSize(QSize(40, 16777215));
        saveAsButton->setIcon(icon);

        gridLayout->addWidget(saveAsButton, 3, 5, 1, 1);

        snapshotButton = new QPushButton(frame);
        snapshotButton->setObjectName(QStringLiteral("snapshotButton"));
        snapshotButton->setMinimumSize(QSize(0, 21));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/Resources/icon_Snapshot.png"), QSize(), QIcon::Normal, QIcon::Off);
        snapshotButton->setIcon(icon1);

        gridLayout->addWidget(snapshotButton, 3, 2, 1, 1);

        clearRecordedFramesButton = new QPushButton(frame);
        clearRecordedFramesButton->setObjectName(QStringLiteral("clearRecordedFramesButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(clearRecordedFramesButton->sizePolicy().hasHeightForWidth());
        clearRecordedFramesButton->setSizePolicy(sizePolicy);
        clearRecordedFramesButton->setMinimumSize(QSize(0, 21));
        clearRecordedFramesButton->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(clearRecordedFramesButton, 3, 6, 1, 1);

        numberOfRecordedFramesValueLabel = new QLabel(frame);
        numberOfRecordedFramesValueLabel->setObjectName(QStringLiteral("numberOfRecordedFramesValueLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        numberOfRecordedFramesValueLabel->setFont(font);
        numberOfRecordedFramesValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(numberOfRecordedFramesValueLabel, 1, 6, 1, 1);

        startStopButton = new QPushButton(frame);
        startStopButton->setObjectName(QStringLiteral("startStopButton"));
        startStopButton->setMinimumSize(QSize(40, 21));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/Resources/icon_Record.png"), QSize(), QIcon::Normal, QIcon::Off);
        startStopButton->setIcon(icon2);

        gridLayout->addWidget(startStopButton, 3, 0, 1, 1);

        requestedFrameRateLabel = new QLabel(frame);
        requestedFrameRateLabel->setObjectName(QStringLiteral("requestedFrameRateLabel"));
        requestedFrameRateLabel->setMinimumSize(QSize(75, 0));

        gridLayout->addWidget(requestedFrameRateLabel, 1, 0, 1, 1);

        actualFrameRateValueLabel = new QLabel(frame);
        actualFrameRateValueLabel->setObjectName(QStringLiteral("actualFrameRateValueLabel"));
        actualFrameRateValueLabel->setFont(font);
        actualFrameRateValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(actualFrameRateValueLabel, 0, 6, 1, 1);

        channelIdentifierLabel = new QLabel(frame);
        channelIdentifierLabel->setObjectName(QStringLiteral("channelIdentifierLabel"));
        channelIdentifierLabel->setMinimumSize(QSize(110, 0));
        QFont font1;
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        channelIdentifierLabel->setFont(font1);

        gridLayout->addWidget(channelIdentifierLabel, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 3, 1, 1);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(CaptureControlWidget);

        QMetaObject::connectSlotsByName(CaptureControlWidget);
    } // setupUi

    void retranslateUi(QWidget *CaptureControlWidget)
    {
        CaptureControlWidget->setWindowTitle(QApplication::translate("CaptureControlWidget", "Form", Q_NULLPTR));
        actualFrameRateLabel->setText(QApplication::translate("CaptureControlWidget", "Actual FPS:", Q_NULLPTR));
        numberOfRecordedFramesLabel->setText(QApplication::translate("CaptureControlWidget", "Frames:", Q_NULLPTR));
        requestedFrameRateValueLabel->setText(QApplication::translate("CaptureControlWidget", "0.0", Q_NULLPTR));
        saveButton->setText(QString());
        requestedSamplingRate->setText(QApplication::translate("CaptureControlWidget", "Sampling Rate:", Q_NULLPTR));
        saveAsButton->setText(QApplication::translate("CaptureControlWidget", "...", Q_NULLPTR));
        snapshotButton->setText(QString());
        clearRecordedFramesButton->setText(QApplication::translate("CaptureControlWidget", "Clear", Q_NULLPTR));
        numberOfRecordedFramesValueLabel->setText(QApplication::translate("CaptureControlWidget", "0", Q_NULLPTR));
        startStopButton->setText(QApplication::translate("CaptureControlWidget", "Record", Q_NULLPTR));
        requestedFrameRateLabel->setText(QApplication::translate("CaptureControlWidget", "Requested FPS:", Q_NULLPTR));
        actualFrameRateValueLabel->setText(QApplication::translate("CaptureControlWidget", "0.0", Q_NULLPTR));
        channelIdentifierLabel->setText(QApplication::translate("CaptureControlWidget", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CaptureControlWidget: public Ui_CaptureControlWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUSCAPTURECONTROLWIDGET_H
