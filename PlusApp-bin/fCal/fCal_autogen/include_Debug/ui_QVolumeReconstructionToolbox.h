/********************************************************************************
** Form generated from reading UI file 'QVolumeReconstructionToolbox.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QVOLUMERECONSTRUCTIONTOOLBOX_H
#define UI_QVOLUMERECONSTRUCTIONTOOLBOX_H

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
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VolumeReconstructionToolbox
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_Import;
    QLabel *label_VolumeReconstructionConfig;
    QPushButton *pushButton_OpenVolumeReconstructionConfig;
    QLabel *label_InputImage;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_InputImage;
    QPushButton *pushButton_OpenInputImage;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Reconstruct;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_Instructions;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_Save;
    QSpacerItem *horizontalSpacer_4;
    QSlider *horizontalSlider_ContouringThreshold;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_ContouringThresholdText;
    QLabel *label_ContouringThreshold;
    QLabel *label_State;
    QFrame *line;

    void setupUi(QWidget *VolumeReconstructionToolbox)
    {
        if (VolumeReconstructionToolbox->objectName().isEmpty())
            VolumeReconstructionToolbox->setObjectName(QStringLiteral("VolumeReconstructionToolbox"));
        VolumeReconstructionToolbox->resize(236, 307);
        gridLayout = new QGridLayout(VolumeReconstructionToolbox);
        gridLayout->setSpacing(4);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 4, 0, 4);
        horizontalLayout_Import = new QHBoxLayout();
        horizontalLayout_Import->setObjectName(QStringLiteral("horizontalLayout_Import"));
        label_VolumeReconstructionConfig = new QLabel(VolumeReconstructionToolbox);
        label_VolumeReconstructionConfig->setObjectName(QStringLiteral("label_VolumeReconstructionConfig"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(9);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_VolumeReconstructionConfig->sizePolicy().hasHeightForWidth());
        label_VolumeReconstructionConfig->setSizePolicy(sizePolicy);

        horizontalLayout_Import->addWidget(label_VolumeReconstructionConfig);

        pushButton_OpenVolumeReconstructionConfig = new QPushButton(VolumeReconstructionToolbox);
        pushButton_OpenVolumeReconstructionConfig->setObjectName(QStringLiteral("pushButton_OpenVolumeReconstructionConfig"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_OpenVolumeReconstructionConfig->sizePolicy().hasHeightForWidth());
        pushButton_OpenVolumeReconstructionConfig->setSizePolicy(sizePolicy1);
        pushButton_OpenVolumeReconstructionConfig->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/Resources/icon_Import.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_OpenVolumeReconstructionConfig->setIcon(icon);
        pushButton_OpenVolumeReconstructionConfig->setIconSize(QSize(16, 16));

        horizontalLayout_Import->addWidget(pushButton_OpenVolumeReconstructionConfig);


        gridLayout->addLayout(horizontalLayout_Import, 2, 0, 1, 1);

        label_InputImage = new QLabel(VolumeReconstructionToolbox);
        label_InputImage->setObjectName(QStringLiteral("label_InputImage"));

        gridLayout->addWidget(label_InputImage, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        comboBox_InputImage = new QComboBox(VolumeReconstructionToolbox);
        comboBox_InputImage->setObjectName(QStringLiteral("comboBox_InputImage"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(9);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox_InputImage->sizePolicy().hasHeightForWidth());
        comboBox_InputImage->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(comboBox_InputImage);

        pushButton_OpenInputImage = new QPushButton(VolumeReconstructionToolbox);
        pushButton_OpenInputImage->setObjectName(QStringLiteral("pushButton_OpenInputImage"));
        sizePolicy1.setHeightForWidth(pushButton_OpenInputImage->sizePolicy().hasHeightForWidth());
        pushButton_OpenInputImage->setSizePolicy(sizePolicy1);
        pushButton_OpenInputImage->setMinimumSize(QSize(23, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/Resources/icon_OpenFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_OpenInputImage->setIcon(icon1);
        pushButton_OpenInputImage->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(pushButton_OpenInputImage);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_Reconstruct = new QPushButton(VolumeReconstructionToolbox);
        pushButton_Reconstruct->setObjectName(QStringLiteral("pushButton_Reconstruct"));
        pushButton_Reconstruct->setMinimumSize(QSize(120, 0));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/Resources/icon_Play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Reconstruct->setIcon(icon2);

        horizontalLayout_2->addWidget(pushButton_Reconstruct);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 11, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(177, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 13, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 8, 0, 1, 1);

        label_Instructions = new QLabel(VolumeReconstructionToolbox);
        label_Instructions->setObjectName(QStringLiteral("label_Instructions"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_Instructions->setFont(font);
        label_Instructions->setWordWrap(true);

        gridLayout->addWidget(label_Instructions, 9, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 10, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButton_Save = new QPushButton(VolumeReconstructionToolbox);
        pushButton_Save->setObjectName(QStringLiteral("pushButton_Save"));
        pushButton_Save->setMinimumSize(QSize(120, 0));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/Resources/icon_Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Save->setIcon(icon3);

        horizontalLayout_4->addWidget(pushButton_Save);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_4, 12, 0, 1, 1);

        horizontalSlider_ContouringThreshold = new QSlider(VolumeReconstructionToolbox);
        horizontalSlider_ContouringThreshold->setObjectName(QStringLiteral("horizontalSlider_ContouringThreshold"));
        horizontalSlider_ContouringThreshold->setMaximum(255);
        horizontalSlider_ContouringThreshold->setValue(64);
        horizontalSlider_ContouringThreshold->setOrientation(Qt::Horizontal);
        horizontalSlider_ContouringThreshold->setTickPosition(QSlider::NoTicks);

        gridLayout->addWidget(horizontalSlider_ContouringThreshold, 7, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_ContouringThresholdText = new QLabel(VolumeReconstructionToolbox);
        label_ContouringThresholdText->setObjectName(QStringLiteral("label_ContouringThresholdText"));

        horizontalLayout_5->addWidget(label_ContouringThresholdText);

        label_ContouringThreshold = new QLabel(VolumeReconstructionToolbox);
        label_ContouringThreshold->setObjectName(QStringLiteral("label_ContouringThreshold"));

        horizontalLayout_5->addWidget(label_ContouringThreshold);


        gridLayout->addLayout(horizontalLayout_5, 6, 0, 1, 1);

        label_State = new QLabel(VolumeReconstructionToolbox);
        label_State->setObjectName(QStringLiteral("label_State"));
        label_State->setFont(font);
        label_State->setWordWrap(true);

        gridLayout->addWidget(label_State, 0, 0, 1, 1);

        line = new QFrame(VolumeReconstructionToolbox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 1);


        retranslateUi(VolumeReconstructionToolbox);

        QMetaObject::connectSlotsByName(VolumeReconstructionToolbox);
    } // setupUi

    void retranslateUi(QWidget *VolumeReconstructionToolbox)
    {
        VolumeReconstructionToolbox->setWindowTitle(QApplication::translate("VolumeReconstructionToolbox", "Volume reconstruction", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_VolumeReconstructionConfig->setToolTip(QApplication::translate("VolumeReconstructionToolbox", "Also overwrites probe calibration", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_VolumeReconstructionConfig->setText(QApplication::translate("VolumeReconstructionToolbox", "Import volume reconstruction settings:", Q_NULLPTR));
        pushButton_OpenVolumeReconstructionConfig->setText(QString());
        label_InputImage->setText(QApplication::translate("VolumeReconstructionToolbox", "Input image sequence file:", Q_NULLPTR));
        pushButton_OpenInputImage->setText(QString());
        pushButton_Reconstruct->setText(QApplication::translate("VolumeReconstructionToolbox", "Reconstruct", Q_NULLPTR));
        label_Instructions->setText(QApplication::translate("VolumeReconstructionToolbox", "Instructions", Q_NULLPTR));
        pushButton_Save->setText(QApplication::translate("VolumeReconstructionToolbox", "Save volume...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        horizontalSlider_ContouringThreshold->setToolTip(QApplication::translate("VolumeReconstructionToolbox", "Voxel value based on which the displayed surface is created", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_ContouringThresholdText->setToolTip(QApplication::translate("VolumeReconstructionToolbox", "Voxel value based on which the displayed surface is created", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_ContouringThresholdText->setText(QApplication::translate("VolumeReconstructionToolbox", "Contouring threshold:", Q_NULLPTR));
        label_ContouringThreshold->setText(QApplication::translate("VolumeReconstructionToolbox", "64", Q_NULLPTR));
        label_State->setText(QApplication::translate("VolumeReconstructionToolbox", "ImageToProge transform is absent, spatial calibration needs to be performed.", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VolumeReconstructionToolbox: public Ui_VolumeReconstructionToolbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QVOLUMERECONSTRUCTIONTOOLBOX_H
