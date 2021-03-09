/********************************************************************************
** Form generated from reading UI file 'QPlusSegmentationParameterDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPLUSSEGMENTATIONPARAMETERDIALOG_H
#define UI_QPLUSSEGMENTATIONPARAMETERDIALOG_H

#include <QVTKWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SegmentationParameterDialog
{
public:
    QHBoxLayout *horizontalLayout_4;
    QFrame *leftFrame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_FreezeImage;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_Export;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox_ROI;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_RegionX;
    QLabel *label_From;
    QSpinBox *spinBox_XMin;
    QLabel *label_To;
    QSpinBox *spinBox_XMax;
    QLabel *label_RegionY;
    QSpinBox *spinBox_YMin;
    QSpinBox *spinBox_YMax;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_Spacing;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Reference;
    QLabel *label_Green;
    QDoubleSpinBox *doubleSpinBox_ReferenceWidth;
    QLabel *label_Blue;
    QDoubleSpinBox *doubleSpinBox_ReferenceHeight;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Spacing;
    QLabel *label_SpacingResult;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_Morphology;
    QGridLayout *gridLayout_4;
    QLabel *label_OpeningCircleRadius;
    QLabel *label_OpeningBarSize;
    QDoubleSpinBox *doubleSpinBox_OpeningBarSize;
    QDoubleSpinBox *doubleSpinBox_OpeningCircleRadius;
    QLabel *label_ImageThreshold;
    QDoubleSpinBox *doubleSpinBox_ImageThreshold;
    QCheckBox *checkBox_OriginalIntensityForDots;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_Tolerance;
    QGridLayout *gridLayout_5;
    QLabel *label_LinePairDistanceError;
    QDoubleSpinBox *doubleSpinBox_LinePairDistanceError;
    QLabel *label_AngleDifference;
    QDoubleSpinBox *doubleSpinBox_AngleDifference;
    QLabel *label_MinTheta;
    QDoubleSpinBox *doubleSpinBox_MinTheta;
    QLabel *label_MaxTheta;
    QDoubleSpinBox *doubleSpinBox_MaxTheta;
    QLabel *label_CollinearPointsMaxDistanceFromLine;
    QDoubleSpinBox *doubleSpinBox_CollinearPointsMaxDistanceFromLine;
    QLabel *label_AngleTolerance;
    QDoubleSpinBox *doubleSpinBox_AngleTolerance;
    QLabel *label_MaxLineShift;
    QDoubleSpinBox *doubleSpinBox_MaxLineShiftMm;
    QLabel *label_MaxCandidates;
    QDoubleSpinBox *doubleSpinBox_MaxCandidates;
    QFrame *line;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_Feedback;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ApplyAndClose;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_SaveAndClose;
    QSpacerItem *horizontalSpacer_5;
    QVTKWidget *canvas;

    void setupUi(QDialog *SegmentationParameterDialog)
    {
        if (SegmentationParameterDialog->objectName().isEmpty())
            SegmentationParameterDialog->setObjectName(QStringLiteral("SegmentationParameterDialog"));
        SegmentationParameterDialog->resize(998, 590);
        SegmentationParameterDialog->setMinimumSize(QSize(998, 590));
        horizontalLayout_4 = new QHBoxLayout(SegmentationParameterDialog);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        leftFrame = new QFrame(SegmentationParameterDialog);
        leftFrame->setObjectName(QStringLiteral("leftFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftFrame->sizePolicy().hasHeightForWidth());
        leftFrame->setSizePolicy(sizePolicy);
        leftFrame->setMinimumSize(QSize(275, 0));
        leftFrame->setFrameShape(QFrame::StyledPanel);
        leftFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(leftFrame);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(4);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        pushButton_FreezeImage = new QPushButton(leftFrame);
        pushButton_FreezeImage->setObjectName(QStringLiteral("pushButton_FreezeImage"));
        pushButton_FreezeImage->setMinimumSize(QSize(100, 0));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/Resources/icon_Pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_FreezeImage->setIcon(icon);
        pushButton_FreezeImage->setCheckable(true);

        horizontalLayout_6->addWidget(pushButton_FreezeImage);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        pushButton_Export = new QPushButton(leftFrame);
        pushButton_Export->setObjectName(QStringLiteral("pushButton_Export"));
        pushButton_Export->setEnabled(false);
        pushButton_Export->setMinimumSize(QSize(100, 0));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/Resources/icon_Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Export->setIcon(icon1);

        horizontalLayout_7->addWidget(pushButton_Export);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_7);

        verticalSpacer_4 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        groupBox_ROI = new QGroupBox(leftFrame);
        groupBox_ROI->setObjectName(QStringLiteral("groupBox_ROI"));
        groupBox_ROI->setFlat(true);
        groupBox_ROI->setCheckable(true);
        gridLayout_3 = new QGridLayout(groupBox_ROI);
        gridLayout_3->setSpacing(4);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(4, 4, 4, 4);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(4);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_RegionX = new QLabel(groupBox_ROI);
        label_RegionX->setObjectName(QStringLiteral("label_RegionX"));
        label_RegionX->setMinimumSize(QSize(35, 0));

        gridLayout->addWidget(label_RegionX, 0, 0, 1, 1);

        label_From = new QLabel(groupBox_ROI);
        label_From->setObjectName(QStringLiteral("label_From"));
        label_From->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_From, 0, 1, 2, 1);

        spinBox_XMin = new QSpinBox(groupBox_ROI);
        spinBox_XMin->setObjectName(QStringLiteral("spinBox_XMin"));
        spinBox_XMin->setMinimumSize(QSize(55, 0));
        spinBox_XMin->setMinimum(0);
        spinBox_XMin->setMaximum(2000);
        spinBox_XMin->setSingleStep(10);
        spinBox_XMin->setValue(100);

        gridLayout->addWidget(spinBox_XMin, 0, 2, 1, 1);

        label_To = new QLabel(groupBox_ROI);
        label_To->setObjectName(QStringLiteral("label_To"));
        label_To->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_To, 0, 3, 2, 1);

        spinBox_XMax = new QSpinBox(groupBox_ROI);
        spinBox_XMax->setObjectName(QStringLiteral("spinBox_XMax"));
        spinBox_XMax->setMinimumSize(QSize(55, 0));
        spinBox_XMax->setMinimum(1);
        spinBox_XMax->setMaximum(2000);
        spinBox_XMax->setSingleStep(10);
        spinBox_XMax->setValue(500);

        gridLayout->addWidget(spinBox_XMax, 0, 4, 1, 1);

        label_RegionY = new QLabel(groupBox_ROI);
        label_RegionY->setObjectName(QStringLiteral("label_RegionY"));
        label_RegionY->setMinimumSize(QSize(35, 0));

        gridLayout->addWidget(label_RegionY, 1, 0, 1, 1);

        spinBox_YMin = new QSpinBox(groupBox_ROI);
        spinBox_YMin->setObjectName(QStringLiteral("spinBox_YMin"));
        spinBox_YMin->setMinimumSize(QSize(55, 0));
        spinBox_YMin->setMinimum(0);
        spinBox_YMin->setMaximum(2000);
        spinBox_YMin->setSingleStep(10);
        spinBox_YMin->setValue(100);

        gridLayout->addWidget(spinBox_YMin, 1, 2, 1, 1);

        spinBox_YMax = new QSpinBox(groupBox_ROI);
        spinBox_YMax->setObjectName(QStringLiteral("spinBox_YMax"));
        spinBox_YMax->setMinimumSize(QSize(55, 0));
        spinBox_YMax->setMinimum(1);
        spinBox_YMax->setMaximum(2000);
        spinBox_YMax->setSingleStep(10);
        spinBox_YMax->setValue(500);

        gridLayout->addWidget(spinBox_YMax, 1, 4, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_ROI);

        verticalSpacer = new QSpacerItem(28, 4, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        groupBox_Spacing = new QGroupBox(leftFrame);
        groupBox_Spacing->setObjectName(QStringLiteral("groupBox_Spacing"));
        groupBox_Spacing->setFlat(true);
        groupBox_Spacing->setCheckable(true);
        groupBox_Spacing->setChecked(false);
        gridLayout_2 = new QGridLayout(groupBox_Spacing);
        gridLayout_2->setSpacing(4);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(4, 4, 4, 4);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 4, -1);
        label_Reference = new QLabel(groupBox_Spacing);
        label_Reference->setObjectName(QStringLiteral("label_Reference"));

        horizontalLayout->addWidget(label_Reference);

        label_Green = new QLabel(groupBox_Spacing);
        label_Green->setObjectName(QStringLiteral("label_Green"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_Green->sizePolicy().hasHeightForWidth());
        label_Green->setSizePolicy(sizePolicy1);
        label_Green->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_Green);

        doubleSpinBox_ReferenceWidth = new QDoubleSpinBox(groupBox_Spacing);
        doubleSpinBox_ReferenceWidth->setObjectName(QStringLiteral("doubleSpinBox_ReferenceWidth"));
        doubleSpinBox_ReferenceWidth->setAlignment(Qt::AlignCenter);
        doubleSpinBox_ReferenceWidth->setDecimals(1);
        doubleSpinBox_ReferenceWidth->setMinimum(1);
        doubleSpinBox_ReferenceWidth->setMaximum(200);
        doubleSpinBox_ReferenceWidth->setSingleStep(5);
        doubleSpinBox_ReferenceWidth->setValue(30);

        horizontalLayout->addWidget(doubleSpinBox_ReferenceWidth);

        label_Blue = new QLabel(groupBox_Spacing);
        label_Blue->setObjectName(QStringLiteral("label_Blue"));
        sizePolicy1.setHeightForWidth(label_Blue->sizePolicy().hasHeightForWidth());
        label_Blue->setSizePolicy(sizePolicy1);
        label_Blue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_Blue);

        doubleSpinBox_ReferenceHeight = new QDoubleSpinBox(groupBox_Spacing);
        doubleSpinBox_ReferenceHeight->setObjectName(QStringLiteral("doubleSpinBox_ReferenceHeight"));
        doubleSpinBox_ReferenceHeight->setAlignment(Qt::AlignCenter);
        doubleSpinBox_ReferenceHeight->setDecimals(1);
        doubleSpinBox_ReferenceHeight->setMinimum(1);
        doubleSpinBox_ReferenceHeight->setMaximum(200);
        doubleSpinBox_ReferenceHeight->setSingleStep(5);
        doubleSpinBox_ReferenceHeight->setValue(20);

        horizontalLayout->addWidget(doubleSpinBox_ReferenceHeight);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_Spacing = new QLabel(groupBox_Spacing);
        label_Spacing->setObjectName(QStringLiteral("label_Spacing"));

        horizontalLayout_2->addWidget(label_Spacing);

        label_SpacingResult = new QLabel(groupBox_Spacing);
        label_SpacingResult->setObjectName(QStringLiteral("label_SpacingResult"));

        horizontalLayout_2->addWidget(label_SpacingResult);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox_Spacing);

        verticalSpacer_3 = new QSpacerItem(28, 4, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        groupBox_Morphology = new QGroupBox(leftFrame);
        groupBox_Morphology->setObjectName(QStringLiteral("groupBox_Morphology"));
        groupBox_Morphology->setFlat(true);
        gridLayout_4 = new QGridLayout(groupBox_Morphology);
        gridLayout_4->setSpacing(4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(4, 4, 4, 4);
        label_OpeningCircleRadius = new QLabel(groupBox_Morphology);
        label_OpeningCircleRadius->setObjectName(QStringLiteral("label_OpeningCircleRadius"));

        gridLayout_4->addWidget(label_OpeningCircleRadius, 0, 0, 1, 1);

        label_OpeningBarSize = new QLabel(groupBox_Morphology);
        label_OpeningBarSize->setObjectName(QStringLiteral("label_OpeningBarSize"));

        gridLayout_4->addWidget(label_OpeningBarSize, 2, 0, 1, 1);

        doubleSpinBox_OpeningBarSize = new QDoubleSpinBox(groupBox_Morphology);
        doubleSpinBox_OpeningBarSize->setObjectName(QStringLiteral("doubleSpinBox_OpeningBarSize"));
        doubleSpinBox_OpeningBarSize->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_OpeningBarSize->setMinimum(0.01);
        doubleSpinBox_OpeningBarSize->setMaximum(10);
        doubleSpinBox_OpeningBarSize->setSingleStep(0.1);
        doubleSpinBox_OpeningBarSize->setValue(1);

        gridLayout_4->addWidget(doubleSpinBox_OpeningBarSize, 2, 2, 1, 1);

        doubleSpinBox_OpeningCircleRadius = new QDoubleSpinBox(groupBox_Morphology);
        doubleSpinBox_OpeningCircleRadius->setObjectName(QStringLiteral("doubleSpinBox_OpeningCircleRadius"));
        doubleSpinBox_OpeningCircleRadius->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_OpeningCircleRadius->setMinimum(0.01);
        doubleSpinBox_OpeningCircleRadius->setMaximum(10);
        doubleSpinBox_OpeningCircleRadius->setSingleStep(0.1);
        doubleSpinBox_OpeningCircleRadius->setValue(0.5);

        gridLayout_4->addWidget(doubleSpinBox_OpeningCircleRadius, 0, 2, 1, 1);

        label_ImageThreshold = new QLabel(groupBox_Morphology);
        label_ImageThreshold->setObjectName(QStringLiteral("label_ImageThreshold"));

        gridLayout_4->addWidget(label_ImageThreshold, 3, 0, 1, 1);

        doubleSpinBox_ImageThreshold = new QDoubleSpinBox(groupBox_Morphology);
        doubleSpinBox_ImageThreshold->setObjectName(QStringLiteral("doubleSpinBox_ImageThreshold"));
        doubleSpinBox_ImageThreshold->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_ImageThreshold->setDecimals(1);
        doubleSpinBox_ImageThreshold->setMinimum(0.1);
        doubleSpinBox_ImageThreshold->setMaximum(99.9);
        doubleSpinBox_ImageThreshold->setSingleStep(1);
        doubleSpinBox_ImageThreshold->setValue(10);

        gridLayout_4->addWidget(doubleSpinBox_ImageThreshold, 3, 2, 1, 1);

        checkBox_OriginalIntensityForDots = new QCheckBox(groupBox_Morphology);
        checkBox_OriginalIntensityForDots->setObjectName(QStringLiteral("checkBox_OriginalIntensityForDots"));
        checkBox_OriginalIntensityForDots->setLayoutDirection(Qt::LeftToRight);

        gridLayout_4->addWidget(checkBox_OriginalIntensityForDots, 4, 0, 1, 3);


        verticalLayout->addWidget(groupBox_Morphology);

        verticalSpacer_2 = new QSpacerItem(28, 4, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        groupBox_Tolerance = new QGroupBox(leftFrame);
        groupBox_Tolerance->setObjectName(QStringLiteral("groupBox_Tolerance"));
        groupBox_Tolerance->setFlat(true);
        gridLayout_5 = new QGridLayout(groupBox_Tolerance);
        gridLayout_5->setSpacing(4);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(4, 4, 4, 4);
        label_LinePairDistanceError = new QLabel(groupBox_Tolerance);
        label_LinePairDistanceError->setObjectName(QStringLiteral("label_LinePairDistanceError"));

        gridLayout_5->addWidget(label_LinePairDistanceError, 0, 0, 1, 1);

        doubleSpinBox_LinePairDistanceError = new QDoubleSpinBox(groupBox_Tolerance);
        doubleSpinBox_LinePairDistanceError->setObjectName(QStringLiteral("doubleSpinBox_LinePairDistanceError"));
        doubleSpinBox_LinePairDistanceError->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_LinePairDistanceError->setMinimum(0.01);
        doubleSpinBox_LinePairDistanceError->setMaximum(99.99);
        doubleSpinBox_LinePairDistanceError->setValue(10);

        gridLayout_5->addWidget(doubleSpinBox_LinePairDistanceError, 0, 1, 1, 1);

        label_AngleDifference = new QLabel(groupBox_Tolerance);
        label_AngleDifference->setObjectName(QStringLiteral("label_AngleDifference"));

        gridLayout_5->addWidget(label_AngleDifference, 1, 0, 1, 1);

        doubleSpinBox_AngleDifference = new QDoubleSpinBox(groupBox_Tolerance);
        doubleSpinBox_AngleDifference->setObjectName(QStringLiteral("doubleSpinBox_AngleDifference"));
        doubleSpinBox_AngleDifference->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_AngleDifference->setDecimals(1);
        doubleSpinBox_AngleDifference->setMinimum(0.1);
        doubleSpinBox_AngleDifference->setMaximum(99.9);
        doubleSpinBox_AngleDifference->setSingleStep(1);
        doubleSpinBox_AngleDifference->setValue(11);

        gridLayout_5->addWidget(doubleSpinBox_AngleDifference, 1, 1, 1, 1);

        label_MinTheta = new QLabel(groupBox_Tolerance);
        label_MinTheta->setObjectName(QStringLiteral("label_MinTheta"));

        gridLayout_5->addWidget(label_MinTheta, 2, 0, 1, 1);

        doubleSpinBox_MinTheta = new QDoubleSpinBox(groupBox_Tolerance);
        doubleSpinBox_MinTheta->setObjectName(QStringLiteral("doubleSpinBox_MinTheta"));
        doubleSpinBox_MinTheta->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_MinTheta->setDecimals(1);
        doubleSpinBox_MinTheta->setMinimum(-180);
        doubleSpinBox_MinTheta->setMaximum(180);
        doubleSpinBox_MinTheta->setSingleStep(10);
        doubleSpinBox_MinTheta->setValue(-70);

        gridLayout_5->addWidget(doubleSpinBox_MinTheta, 2, 1, 1, 1);

        label_MaxTheta = new QLabel(groupBox_Tolerance);
        label_MaxTheta->setObjectName(QStringLiteral("label_MaxTheta"));

        gridLayout_5->addWidget(label_MaxTheta, 3, 0, 1, 1);

        doubleSpinBox_MaxTheta = new QDoubleSpinBox(groupBox_Tolerance);
        doubleSpinBox_MaxTheta->setObjectName(QStringLiteral("doubleSpinBox_MaxTheta"));
        doubleSpinBox_MaxTheta->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_MaxTheta->setDecimals(1);
        doubleSpinBox_MaxTheta->setMinimum(-180);
        doubleSpinBox_MaxTheta->setMaximum(180);
        doubleSpinBox_MaxTheta->setSingleStep(10);
        doubleSpinBox_MaxTheta->setValue(70);

        gridLayout_5->addWidget(doubleSpinBox_MaxTheta, 3, 1, 1, 1);

        label_CollinearPointsMaxDistanceFromLine = new QLabel(groupBox_Tolerance);
        label_CollinearPointsMaxDistanceFromLine->setObjectName(QStringLiteral("label_CollinearPointsMaxDistanceFromLine"));

        gridLayout_5->addWidget(label_CollinearPointsMaxDistanceFromLine, 5, 0, 1, 1);

        doubleSpinBox_CollinearPointsMaxDistanceFromLine = new QDoubleSpinBox(groupBox_Tolerance);
        doubleSpinBox_CollinearPointsMaxDistanceFromLine->setObjectName(QStringLiteral("doubleSpinBox_CollinearPointsMaxDistanceFromLine"));
        doubleSpinBox_CollinearPointsMaxDistanceFromLine->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_CollinearPointsMaxDistanceFromLine->setDecimals(1);
        doubleSpinBox_CollinearPointsMaxDistanceFromLine->setMinimum(0.1);
        doubleSpinBox_CollinearPointsMaxDistanceFromLine->setMaximum(99.9);
        doubleSpinBox_CollinearPointsMaxDistanceFromLine->setSingleStep(0.5);
        doubleSpinBox_CollinearPointsMaxDistanceFromLine->setValue(5.3);

        gridLayout_5->addWidget(doubleSpinBox_CollinearPointsMaxDistanceFromLine, 5, 1, 1, 1);

        label_AngleTolerance = new QLabel(groupBox_Tolerance);
        label_AngleTolerance->setObjectName(QStringLiteral("label_AngleTolerance"));

        gridLayout_5->addWidget(label_AngleTolerance, 4, 0, 1, 1);

        doubleSpinBox_AngleTolerance = new QDoubleSpinBox(groupBox_Tolerance);
        doubleSpinBox_AngleTolerance->setObjectName(QStringLiteral("doubleSpinBox_AngleTolerance"));
        doubleSpinBox_AngleTolerance->setMinimum(0.1);
        doubleSpinBox_AngleTolerance->setMaximum(99.9);
        doubleSpinBox_AngleTolerance->setValue(10);

        gridLayout_5->addWidget(doubleSpinBox_AngleTolerance, 4, 1, 1, 1);

        label_MaxLineShift = new QLabel(groupBox_Tolerance);
        label_MaxLineShift->setObjectName(QStringLiteral("label_MaxLineShift"));

        gridLayout_5->addWidget(label_MaxLineShift, 6, 0, 1, 1);

        doubleSpinBox_MaxLineShiftMm = new QDoubleSpinBox(groupBox_Tolerance);
        doubleSpinBox_MaxLineShiftMm->setObjectName(QStringLiteral("doubleSpinBox_MaxLineShiftMm"));
        doubleSpinBox_MaxLineShiftMm->setDecimals(1);
        doubleSpinBox_MaxLineShiftMm->setValue(10);

        gridLayout_5->addWidget(doubleSpinBox_MaxLineShiftMm, 6, 1, 1, 1);

        label_MaxCandidates = new QLabel(groupBox_Tolerance);
        label_MaxCandidates->setObjectName(QStringLiteral("label_MaxCandidates"));

        gridLayout_5->addWidget(label_MaxCandidates, 7, 0, 1, 1);

        doubleSpinBox_MaxCandidates = new QDoubleSpinBox(groupBox_Tolerance);
        doubleSpinBox_MaxCandidates->setObjectName(QStringLiteral("doubleSpinBox_MaxCandidates"));
        doubleSpinBox_MaxCandidates->setDecimals(0);
        doubleSpinBox_MaxCandidates->setMaximum(250);
        doubleSpinBox_MaxCandidates->setValue(20);

        gridLayout_5->addWidget(doubleSpinBox_MaxCandidates, 7, 1, 1, 1);


        verticalLayout->addWidget(groupBox_Tolerance);

        line = new QFrame(leftFrame);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalSpacer_5 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        label_Feedback = new QLabel(leftFrame);
        label_Feedback->setObjectName(QStringLiteral("label_Feedback"));
        label_Feedback->setIndent(8);

        verticalLayout->addWidget(label_Feedback);

        verticalSpacer_6 = new QSpacerItem(28, 6, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(4);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButton_ApplyAndClose = new QPushButton(leftFrame);
        pushButton_ApplyAndClose->setObjectName(QStringLiteral("pushButton_ApplyAndClose"));
        pushButton_ApplyAndClose->setMinimumSize(QSize(110, 0));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/Resources/icon_Apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ApplyAndClose->setIcon(icon2);

        horizontalLayout_5->addWidget(pushButton_ApplyAndClose);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        pushButton_SaveAndClose = new QPushButton(leftFrame);
        pushButton_SaveAndClose->setObjectName(QStringLiteral("pushButton_SaveAndClose"));
        pushButton_SaveAndClose->setMinimumSize(QSize(110, 0));
        pushButton_SaveAndClose->setIcon(icon1);

        horizontalLayout_3->addWidget(pushButton_SaveAndClose);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addWidget(leftFrame);

        canvas = new QVTKWidget(SegmentationParameterDialog);
        canvas->setObjectName(QStringLiteral("canvas"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(7);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(canvas->sizePolicy().hasHeightForWidth());
        canvas->setSizePolicy(sizePolicy2);
        canvas->setMinimumSize(QSize(773, 0));
        canvas->setSizeIncrement(QSize(4, 3));

        horizontalLayout_4->addWidget(canvas);


        retranslateUi(SegmentationParameterDialog);

        QMetaObject::connectSlotsByName(SegmentationParameterDialog);
    } // setupUi

    void retranslateUi(QDialog *SegmentationParameterDialog)
    {
        SegmentationParameterDialog->setWindowTitle(QApplication::translate("SegmentationParameterDialog", "Segmentation Parameter Settings", Q_NULLPTR));
        pushButton_FreezeImage->setText(QApplication::translate("SegmentationParameterDialog", "Freeze", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_Export->setToolTip(QApplication::translate("SegmentationParameterDialog", "Export frozen image into a single-frame metafile", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_Export->setText(QApplication::translate("SegmentationParameterDialog", "Save Image", Q_NULLPTR));
        groupBox_ROI->setTitle(QApplication::translate("SegmentationParameterDialog", "Region of Interest", Q_NULLPTR));
        label_RegionX->setText(QApplication::translate("SegmentationParameterDialog", "X:", Q_NULLPTR));
        label_From->setText(QApplication::translate("SegmentationParameterDialog", "from", Q_NULLPTR));
        label_To->setText(QApplication::translate("SegmentationParameterDialog", "to", Q_NULLPTR));
        label_RegionY->setText(QApplication::translate("SegmentationParameterDialog", "Y:", Q_NULLPTR));
        groupBox_Spacing->setTitle(QApplication::translate("SegmentationParameterDialog", "Spacing", Q_NULLPTR));
        label_Reference->setText(QApplication::translate("SegmentationParameterDialog", "References (mm):", Q_NULLPTR));
        label_Green->setText(QApplication::translate("SegmentationParameterDialog", "Green", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        doubleSpinBox_ReferenceWidth->setToolTip(QApplication::translate("SegmentationParameterDialog", "Length of the  that is represented by green line", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_Blue->setText(QApplication::translate("SegmentationParameterDialog", "Blue", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        doubleSpinBox_ReferenceHeight->setToolTip(QApplication::translate("SegmentationParameterDialog", "Length of the  that is represented by blue line", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_Spacing->setText(QApplication::translate("SegmentationParameterDialog", "Spacing (mm per pixel):", Q_NULLPTR));
        label_SpacingResult->setText(QApplication::translate("SegmentationParameterDialog", "?", Q_NULLPTR));
        groupBox_Morphology->setTitle(QApplication::translate("SegmentationParameterDialog", "Morphology", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_OpeningCircleRadius->setToolTip(QApplication::translate("SegmentationParameterDialog", "This is called OpeningCircleRadius in configuration file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_OpeningCircleRadius->setText(QApplication::translate("SegmentationParameterDialog", "Minimum dot size (mm):", Q_NULLPTR));
        label_OpeningBarSize->setText(QApplication::translate("SegmentationParameterDialog", "Opening bar size (mm):", Q_NULLPTR));
        label_ImageThreshold->setText(QApplication::translate("SegmentationParameterDialog", "Image threshold (%):", Q_NULLPTR));
        checkBox_OriginalIntensityForDots->setText(QApplication::translate("SegmentationParameterDialog", "Use original intensity for dots", Q_NULLPTR));
        groupBox_Tolerance->setTitle(QApplication::translate("SegmentationParameterDialog", "Tolerances", Q_NULLPTR));
        label_LinePairDistanceError->setText(QApplication::translate("SegmentationParameterDialog", "Line pair distance (%):", Q_NULLPTR));
        label_AngleDifference->setText(QApplication::translate("SegmentationParameterDialog", "Angle difference (\302\260):", Q_NULLPTR));
        label_MinTheta->setText(QApplication::translate("SegmentationParameterDialog", "Minimum \316\270 (\302\260):", Q_NULLPTR));
        label_MaxTheta->setText(QApplication::translate("SegmentationParameterDialog", "Maximum \316\270 (\302\260):", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_CollinearPointsMaxDistanceFromLine->setToolTip(QApplication::translate("SegmentationParameterDialog", "Collinear points maximum distance from line in mm", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_CollinearPointsMaxDistanceFromLine->setText(QApplication::translate("SegmentationParameterDialog", "Collinear max distance (mm):", Q_NULLPTR));
        label_AngleTolerance->setText(QApplication::translate("SegmentationParameterDialog", "Angle tolerance (\302\260):", Q_NULLPTR));
        label_MaxLineShift->setText(QApplication::translate("SegmentationParameterDialog", "Max line shift (mm)", Q_NULLPTR));
        label_MaxCandidates->setText(QApplication::translate("SegmentationParameterDialog", "Max Candidates", Q_NULLPTR));
        label_Feedback->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_ApplyAndClose->setToolTip(QApplication::translate("SegmentationParameterDialog", "Save changes into device set configuration data for the application", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_ApplyAndClose->setText(QApplication::translate("SegmentationParameterDialog", "Apply and Close", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_SaveAndClose->setToolTip(QApplication::translate("SegmentationParameterDialog", "Save changes in a new file and into device set configuration data", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_SaveAndClose->setText(QApplication::translate("SegmentationParameterDialog", "Save and Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SegmentationParameterDialog: public Ui_SegmentationParameterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPLUSSEGMENTATIONPARAMETERDIALOG_H
