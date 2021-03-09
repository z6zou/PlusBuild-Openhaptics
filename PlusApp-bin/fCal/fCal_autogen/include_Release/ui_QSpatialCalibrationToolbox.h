/********************************************************************************
** Form generated from reading UI file 'QSpatialCalibrationToolbox.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSPATIALCALIBRATIONTOOLBOX_H
#define UI_QSPATIALCALIBRATIONTOOLBOX_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpatialCalibrationToolbox
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_State;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_PhantomRegistration;
    QPushButton *pushButton_OpenPhantomRegistration;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_SegmentationParameters;
    QPushButton *pushButton_OpenSegmentationParameters;
    QPushButton *pushButton_EditSegmentationParameters;
    QSpacerItem *verticalSpacer;
    QLabel *label_InstructionsSpatial;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_StartCancelSpatial;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_Warning;
    QLabel *label_Results;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *SpatialCalibrationToolbox)
    {
        if (SpatialCalibrationToolbox->objectName().isEmpty())
            SpatialCalibrationToolbox->setObjectName(QStringLiteral("SpatialCalibrationToolbox"));
        SpatialCalibrationToolbox->resize(236, 265);
        verticalLayout = new QVBoxLayout(SpatialCalibrationToolbox);
        verticalLayout->setSpacing(4);
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 4, 0, 4);
        label_State = new QLabel(SpatialCalibrationToolbox);
        label_State->setObjectName(QStringLiteral("label_State"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_State->sizePolicy().hasHeightForWidth());
        label_State->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_State->setFont(font);
        label_State->setWordWrap(true);

        verticalLayout->addWidget(label_State);

        line = new QFrame(SpatialCalibrationToolbox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_PhantomRegistration = new QLabel(SpatialCalibrationToolbox);
        label_PhantomRegistration->setObjectName(QStringLiteral("label_PhantomRegistration"));

        horizontalLayout_3->addWidget(label_PhantomRegistration);

        pushButton_OpenPhantomRegistration = new QPushButton(SpatialCalibrationToolbox);
        pushButton_OpenPhantomRegistration->setObjectName(QStringLiteral("pushButton_OpenPhantomRegistration"));
        pushButton_OpenPhantomRegistration->setMinimumSize(QSize(23, 23));
        pushButton_OpenPhantomRegistration->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/Resources/icon_Import.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_OpenPhantomRegistration->setIcon(icon);
        pushButton_OpenPhantomRegistration->setIconSize(QSize(16, 16));

        horizontalLayout_3->addWidget(pushButton_OpenPhantomRegistration);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_SegmentationParameters = new QLabel(SpatialCalibrationToolbox);
        label_SegmentationParameters->setObjectName(QStringLiteral("label_SegmentationParameters"));

        horizontalLayout_6->addWidget(label_SegmentationParameters);

        pushButton_OpenSegmentationParameters = new QPushButton(SpatialCalibrationToolbox);
        pushButton_OpenSegmentationParameters->setObjectName(QStringLiteral("pushButton_OpenSegmentationParameters"));
        pushButton_OpenSegmentationParameters->setMinimumSize(QSize(23, 23));
        pushButton_OpenSegmentationParameters->setFocusPolicy(Qt::NoFocus);
        pushButton_OpenSegmentationParameters->setIcon(icon);
        pushButton_OpenSegmentationParameters->setIconSize(QSize(16, 16));

        horizontalLayout_6->addWidget(pushButton_OpenSegmentationParameters);

        pushButton_EditSegmentationParameters = new QPushButton(SpatialCalibrationToolbox);
        pushButton_EditSegmentationParameters->setObjectName(QStringLiteral("pushButton_EditSegmentationParameters"));
        pushButton_EditSegmentationParameters->setMinimumSize(QSize(23, 23));
        pushButton_EditSegmentationParameters->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/Resources/icon_Edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_EditSegmentationParameters->setIcon(icon1);

        horizontalLayout_6->addWidget(pushButton_EditSegmentationParameters);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(158, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        label_InstructionsSpatial = new QLabel(SpatialCalibrationToolbox);
        label_InstructionsSpatial->setObjectName(QStringLiteral("label_InstructionsSpatial"));
        label_InstructionsSpatial->setFont(font);
        label_InstructionsSpatial->setWordWrap(true);

        verticalLayout->addWidget(label_InstructionsSpatial);

        verticalSpacer_7 = new QSpacerItem(158, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_StartCancelSpatial = new QPushButton(SpatialCalibrationToolbox);
        pushButton_StartCancelSpatial->setObjectName(QStringLiteral("pushButton_StartCancelSpatial"));

        horizontalLayout_2->addWidget(pushButton_StartCancelSpatial);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        label_Warning = new QLabel(SpatialCalibrationToolbox);
        label_Warning->setObjectName(QStringLiteral("label_Warning"));
        label_Warning->setFont(font);
        label_Warning->setWordWrap(true);

        verticalLayout->addWidget(label_Warning);

        label_Results = new QLabel(SpatialCalibrationToolbox);
        label_Results->setObjectName(QStringLiteral("label_Results"));

        verticalLayout->addWidget(label_Results);

        verticalSpacer_2 = new QSpacerItem(158, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(SpatialCalibrationToolbox);

        QMetaObject::connectSlotsByName(SpatialCalibrationToolbox);
    } // setupUi

    void retranslateUi(QWidget *SpatialCalibrationToolbox)
    {
        SpatialCalibrationToolbox->setWindowTitle(QApplication::translate("SpatialCalibrationToolbox", "Spatial calibration", Q_NULLPTR));
        label_State->setText(QApplication::translate("SpatialCalibrationToolbox", "ImageToProge transform is absent, spatial calibration needs to be performed.", Q_NULLPTR));
        label_PhantomRegistration->setText(QApplication::translate("SpatialCalibrationToolbox", "Import phantom registration result:", Q_NULLPTR));
        pushButton_OpenPhantomRegistration->setText(QString());
        label_SegmentationParameters->setText(QApplication::translate("SpatialCalibrationToolbox", "Pattern recognition parameters:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_OpenSegmentationParameters->setToolTip(QApplication::translate("SpatialCalibrationToolbox", "Import segmentation parameters", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_OpenSegmentationParameters->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_EditSegmentationParameters->setToolTip(QApplication::translate("SpatialCalibrationToolbox", "Show segmentation parameter editing dialog, in which segmentation parameters can be tested and changed", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_EditSegmentationParameters->setText(QString());
        label_InstructionsSpatial->setText(QApplication::translate("SpatialCalibrationToolbox", "Instructions", Q_NULLPTR));
        pushButton_StartCancelSpatial->setText(QApplication::translate("SpatialCalibrationToolbox", "Start", Q_NULLPTR));
        label_Warning->setText(QString());
        label_Results->setText(QApplication::translate("SpatialCalibrationToolbox", "Results", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SpatialCalibrationToolbox: public Ui_SpatialCalibrationToolbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSPATIALCALIBRATIONTOOLBOX_H
