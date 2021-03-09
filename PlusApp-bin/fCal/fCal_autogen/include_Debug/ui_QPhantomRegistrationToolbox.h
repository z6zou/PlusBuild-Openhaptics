/********************************************************************************
** Form generated from reading UI file 'QPhantomRegistrationToolbox.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPHANTOMREGISTRATIONTOOLBOX_H
#define UI_QPHANTOMREGISTRATIONTOOLBOX_H

#include <QVTKWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhantomRegistrationToolbox
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_State;
    QFrame *line_3;
    QHBoxLayout *gridLayout_Import;
    QLabel *label_StylusCalibration;
    QPushButton *pushButton_OpenStylusCalibration;
    QFrame *line;
    QVTKWidget *canvasPhantom;
    QFrame *line_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_Instructions;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_StylusPositionText;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab_Landmark;
    QGridLayout *gridLayout;
    QPushButton *pushButton_StartStop_LandmarkDetection;
    QPushButton *pushButton_Landmark_Reset;
    QPushButton *pushButton_Undo;
    QPushButton *pushButton_RecordPoint;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_9;
    QWidget *tab_LinearObject;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_StartStop;
    QPushButton *pushButton_LinearObject_Reset;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *PhantomRegistrationToolbox)
    {
        if (PhantomRegistrationToolbox->objectName().isEmpty())
            PhantomRegistrationToolbox->setObjectName(QStringLiteral("PhantomRegistrationToolbox"));
        PhantomRegistrationToolbox->resize(230, 420);
        verticalLayout = new QVBoxLayout(PhantomRegistrationToolbox);
        verticalLayout->setSpacing(4);
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 4, 0, 4);
        label_State = new QLabel(PhantomRegistrationToolbox);
        label_State->setObjectName(QStringLiteral("label_State"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_State->setFont(font);
        label_State->setWordWrap(true);

        verticalLayout->addWidget(label_State);

        line_3 = new QFrame(PhantomRegistrationToolbox);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        gridLayout_Import = new QHBoxLayout();
        gridLayout_Import->setSpacing(4);
        gridLayout_Import->setObjectName(QStringLiteral("gridLayout_Import"));
        label_StylusCalibration = new QLabel(PhantomRegistrationToolbox);
        label_StylusCalibration->setObjectName(QStringLiteral("label_StylusCalibration"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(8);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_StylusCalibration->sizePolicy().hasHeightForWidth());
        label_StylusCalibration->setSizePolicy(sizePolicy);

        gridLayout_Import->addWidget(label_StylusCalibration);

        pushButton_OpenStylusCalibration = new QPushButton(PhantomRegistrationToolbox);
        pushButton_OpenStylusCalibration->setObjectName(QStringLiteral("pushButton_OpenStylusCalibration"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_OpenStylusCalibration->sizePolicy().hasHeightForWidth());
        pushButton_OpenStylusCalibration->setSizePolicy(sizePolicy1);
        pushButton_OpenStylusCalibration->setMinimumSize(QSize(23, 23));
        pushButton_OpenStylusCalibration->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/Resources/icon_Import.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_OpenStylusCalibration->setIcon(icon);
        pushButton_OpenStylusCalibration->setIconSize(QSize(16, 16));

        gridLayout_Import->addWidget(pushButton_OpenStylusCalibration);


        verticalLayout->addLayout(gridLayout_Import);

        line = new QFrame(PhantomRegistrationToolbox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        canvasPhantom = new QVTKWidget(PhantomRegistrationToolbox);
        canvasPhantom->setObjectName(QStringLiteral("canvasPhantom"));
        canvasPhantom->setMinimumSize(QSize(218, 156));
        canvasPhantom->setSizeIncrement(QSize(4, 3));

        verticalLayout->addWidget(canvasPhantom);

        line_2 = new QFrame(PhantomRegistrationToolbox);
        line_2->setObjectName(QStringLiteral("line_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy2);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        verticalSpacer_3 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        label_Instructions = new QLabel(PhantomRegistrationToolbox);
        label_Instructions->setObjectName(QStringLiteral("label_Instructions"));
        label_Instructions->setFont(font);
        label_Instructions->setWordWrap(true);

        verticalLayout->addWidget(label_Instructions);

        verticalSpacer_4 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        label_StylusPositionText = new QLabel(PhantomRegistrationToolbox);
        label_StylusPositionText->setObjectName(QStringLiteral("label_StylusPositionText"));

        verticalLayout->addWidget(label_StylusPositionText);

        verticalSpacer = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        tabWidget = new QTabWidget(PhantomRegistrationToolbox);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_Landmark = new QWidget();
        tab_Landmark->setObjectName(QStringLiteral("tab_Landmark"));
        gridLayout = new QGridLayout(tab_Landmark);
        gridLayout->setSpacing(4);
        gridLayout->setContentsMargins(4, 4, 4, 4);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_StartStop_LandmarkDetection = new QPushButton(tab_Landmark);
        pushButton_StartStop_LandmarkDetection->setObjectName(QStringLiteral("pushButton_StartStop_LandmarkDetection"));

        gridLayout->addWidget(pushButton_StartStop_LandmarkDetection, 0, 1, 1, 1);

        pushButton_Landmark_Reset = new QPushButton(tab_Landmark);
        pushButton_Landmark_Reset->setObjectName(QStringLiteral("pushButton_Landmark_Reset"));

        gridLayout->addWidget(pushButton_Landmark_Reset, 1, 3, 1, 1);

        pushButton_Undo = new QPushButton(tab_Landmark);
        pushButton_Undo->setObjectName(QStringLiteral("pushButton_Undo"));

        gridLayout->addWidget(pushButton_Undo, 1, 1, 1, 1);

        pushButton_RecordPoint = new QPushButton(tab_Landmark);
        pushButton_RecordPoint->setObjectName(QStringLiteral("pushButton_RecordPoint"));
        pushButton_RecordPoint->setEnabled(false);

        gridLayout->addWidget(pushButton_RecordPoint, 0, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 4, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 1, 4, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 0, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 1, 0, 1, 1);

        tabWidget->addTab(tab_Landmark, QString());
        tab_LinearObject = new QWidget();
        tab_LinearObject->setObjectName(QStringLiteral("tab_LinearObject"));
        gridLayout_2 = new QGridLayout(tab_LinearObject);
        gridLayout_2->setSpacing(4);
        gridLayout_2->setContentsMargins(4, 4, 4, 4);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        pushButton_StartStop = new QPushButton(tab_LinearObject);
        pushButton_StartStop->setObjectName(QStringLiteral("pushButton_StartStop"));

        gridLayout_2->addWidget(pushButton_StartStop, 0, 1, 1, 1);

        pushButton_LinearObject_Reset = new QPushButton(tab_LinearObject);
        pushButton_LinearObject_Reset->setObjectName(QStringLiteral("pushButton_LinearObject_Reset"));

        gridLayout_2->addWidget(pushButton_LinearObject_Reset, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        tabWidget->addTab(tab_LinearObject, QString());

        verticalLayout->addWidget(tabWidget);

        verticalSpacer_2 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(PhantomRegistrationToolbox);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PhantomRegistrationToolbox);
    } // setupUi

    void retranslateUi(QWidget *PhantomRegistrationToolbox)
    {
        PhantomRegistrationToolbox->setWindowTitle(QApplication::translate("PhantomRegistrationToolbox", "Phantom registration", Q_NULLPTR));
        label_State->setText(QApplication::translate("PhantomRegistrationToolbox", "PhantomToReference transform is absent, registration needs to be performed.", Q_NULLPTR));
        label_StylusCalibration->setText(QApplication::translate("PhantomRegistrationToolbox", "Import stylus calibration result:", Q_NULLPTR));
        pushButton_OpenStylusCalibration->setText(QString());
        label_Instructions->setText(QApplication::translate("PhantomRegistrationToolbox", "Instructions", Q_NULLPTR));
        label_StylusPositionText->setText(QApplication::translate("PhantomRegistrationToolbox", "Stylus tip position:", Q_NULLPTR));
        pushButton_StartStop_LandmarkDetection->setText(QApplication::translate("PhantomRegistrationToolbox", "Start Landmark Detection", Q_NULLPTR));
        pushButton_Landmark_Reset->setText(QApplication::translate("PhantomRegistrationToolbox", "Reset", Q_NULLPTR));
        pushButton_Undo->setText(QApplication::translate("PhantomRegistrationToolbox", "Undo", Q_NULLPTR));
        pushButton_RecordPoint->setText(QApplication::translate("PhantomRegistrationToolbox", "Record point", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_Landmark), QApplication::translate("PhantomRegistrationToolbox", "Landmark", Q_NULLPTR));
        pushButton_StartStop->setText(QApplication::translate("PhantomRegistrationToolbox", "Start", Q_NULLPTR));
        pushButton_LinearObject_Reset->setText(QApplication::translate("PhantomRegistrationToolbox", "Reset", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_LinearObject), QApplication::translate("PhantomRegistrationToolbox", "Linear Object", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PhantomRegistrationToolbox: public Ui_PhantomRegistrationToolbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPHANTOMREGISTRATIONTOOLBOX_H
