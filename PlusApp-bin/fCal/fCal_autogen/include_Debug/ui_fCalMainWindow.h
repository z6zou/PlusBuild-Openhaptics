/********************************************************************************
** Form generated from reading UI file 'fCalMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCALMAINWINDOW_H
#define UI_FCALMAINWINDOW_H

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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fCalMainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *widget_toolboxContainer;
    QVBoxLayout *verticalLayout_toolboxContainer;
    QFrame *frame_Toolbar;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_SaveConfiguration;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ImageOrientation;
    QPushButton *pushButton_ShowDevices;
    QPushButton *pushButton_Tools;
    QToolBox *toolbox;
    QWidget *toolbox_Configuration;
    QWidget *toolbox_Capturing;
    QWidget *toolbox_StylusCalibration;
    QWidget *toolbox_PhantomRegistration;
    QWidget *toolbox_TemporalCalibration;
    QWidget *toolbox_SpatialCalibration;
    QWidget *toolbox_VolumeReconstruction;
    QWidget *widget_viewingContainer;
    QVBoxLayout *verticalLayout_viewingContainer;
    QVTKWidget *canvas;
    QWidget *widget_sliceNumberContainer;
    QHBoxLayout *horizontalLayout_SliceNumber;
    QLabel *label_SliceNumber;
    QSpinBox *spinBox_SliceNumber;
    QSlider *horizontalSlider_SliceNumber;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *fCalMainWindow)
    {
        if (fCalMainWindow->objectName().isEmpty())
            fCalMainWindow->setObjectName(QStringLiteral("fCalMainWindow"));
        fCalMainWindow->resize(950, 677);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/Resources/icon_fCal.png"), QSize(), QIcon::Normal, QIcon::Off);
        fCalMainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(fCalMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget_toolboxContainer = new QWidget(centralWidget);
        widget_toolboxContainer->setObjectName(QStringLiteral("widget_toolboxContainer"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_toolboxContainer->sizePolicy().hasHeightForWidth());
        widget_toolboxContainer->setSizePolicy(sizePolicy1);
        verticalLayout_toolboxContainer = new QVBoxLayout(widget_toolboxContainer);
        verticalLayout_toolboxContainer->setSpacing(0);
        verticalLayout_toolboxContainer->setContentsMargins(11, 11, 11, 11);
        verticalLayout_toolboxContainer->setObjectName(QStringLiteral("verticalLayout_toolboxContainer"));
        verticalLayout_toolboxContainer->setContentsMargins(0, 0, 0, 0);
        frame_Toolbar = new QFrame(widget_toolboxContainer);
        frame_Toolbar->setObjectName(QStringLiteral("frame_Toolbar"));
        frame_Toolbar->setFrameShape(QFrame::StyledPanel);
        frame_Toolbar->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_Toolbar);
        horizontalLayout->setSpacing(4);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(4, 2, 4, 2);
        pushButton_SaveConfiguration = new QPushButton(frame_Toolbar);
        pushButton_SaveConfiguration->setObjectName(QStringLiteral("pushButton_SaveConfiguration"));
        pushButton_SaveConfiguration->setFocusPolicy(Qt::ClickFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/Resources/icon_Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SaveConfiguration->setIcon(icon1);

        horizontalLayout->addWidget(pushButton_SaveConfiguration);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_ImageOrientation = new QPushButton(frame_Toolbar);
        pushButton_ImageOrientation->setObjectName(QStringLiteral("pushButton_ImageOrientation"));
        pushButton_ImageOrientation->setEnabled(false);
        pushButton_ImageOrientation->setFocusPolicy(Qt::ClickFocus);
        pushButton_ImageOrientation->setContextMenuPolicy(Qt::DefaultContextMenu);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/Resources/icon_ImageControl.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ImageOrientation->setIcon(icon2);

        horizontalLayout->addWidget(pushButton_ImageOrientation);

        pushButton_ShowDevices = new QPushButton(frame_Toolbar);
        pushButton_ShowDevices->setObjectName(QStringLiteral("pushButton_ShowDevices"));
        pushButton_ShowDevices->setFocusPolicy(Qt::ClickFocus);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/Resources/icon_ObjectMode.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ShowDevices->setIcon(icon3);
        pushButton_ShowDevices->setCheckable(true);

        horizontalLayout->addWidget(pushButton_ShowDevices);

        pushButton_Tools = new QPushButton(frame_Toolbar);
        pushButton_Tools->setObjectName(QStringLiteral("pushButton_Tools"));
        pushButton_Tools->setFocusPolicy(Qt::NoFocus);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/Resources/icon_Tools.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Tools->setIcon(icon4);

        horizontalLayout->addWidget(pushButton_Tools);


        verticalLayout_toolboxContainer->addWidget(frame_Toolbar);

        toolbox = new QToolBox(widget_toolboxContainer);
        toolbox->setObjectName(QStringLiteral("toolbox"));
        toolbox->setFrameShape(QFrame::Panel);
        toolbox->setFrameShadow(QFrame::Raised);
        toolbox_Configuration = new QWidget();
        toolbox_Configuration->setObjectName(QStringLiteral("toolbox_Configuration"));
        toolbox_Configuration->setGeometry(QRect(0, 0, 230, 419));
        toolbox_Configuration->setMinimumSize(QSize(230, 0));
        toolbox->addItem(toolbox_Configuration, QStringLiteral("Configuration"));
        toolbox_Capturing = new QWidget();
        toolbox_Capturing->setObjectName(QStringLiteral("toolbox_Capturing"));
        toolbox_Capturing->setGeometry(QRect(0, 0, 230, 419));
        toolbox_Capturing->setMinimumSize(QSize(230, 0));
        toolbox->addItem(toolbox_Capturing, QStringLiteral("Capturing"));
        toolbox_StylusCalibration = new QWidget();
        toolbox_StylusCalibration->setObjectName(QStringLiteral("toolbox_StylusCalibration"));
        toolbox_StylusCalibration->setGeometry(QRect(0, 0, 230, 419));
        toolbox_StylusCalibration->setMinimumSize(QSize(230, 0));
        toolbox->addItem(toolbox_StylusCalibration, QStringLiteral("Stylus calibration"));
        toolbox_PhantomRegistration = new QWidget();
        toolbox_PhantomRegistration->setObjectName(QStringLiteral("toolbox_PhantomRegistration"));
        toolbox_PhantomRegistration->setGeometry(QRect(0, 0, 230, 419));
        toolbox_PhantomRegistration->setMinimumSize(QSize(230, 0));
        toolbox->addItem(toolbox_PhantomRegistration, QStringLiteral("Phantom registration"));
        toolbox_TemporalCalibration = new QWidget();
        toolbox_TemporalCalibration->setObjectName(QStringLiteral("toolbox_TemporalCalibration"));
        toolbox_TemporalCalibration->setGeometry(QRect(0, 0, 230, 419));
        toolbox_TemporalCalibration->setMinimumSize(QSize(230, 0));
        toolbox->addItem(toolbox_TemporalCalibration, QStringLiteral("Temporal calibration"));
        toolbox_SpatialCalibration = new QWidget();
        toolbox_SpatialCalibration->setObjectName(QStringLiteral("toolbox_SpatialCalibration"));
        toolbox_SpatialCalibration->setGeometry(QRect(0, 0, 230, 419));
        toolbox_SpatialCalibration->setMinimumSize(QSize(230, 0));
        toolbox->addItem(toolbox_SpatialCalibration, QStringLiteral("Spatial calibration"));
        toolbox_VolumeReconstruction = new QWidget();
        toolbox_VolumeReconstruction->setObjectName(QStringLiteral("toolbox_VolumeReconstruction"));
        toolbox_VolumeReconstruction->setGeometry(QRect(0, 0, 230, 419));
        toolbox_VolumeReconstruction->setMinimumSize(QSize(230, 0));
        toolbox->addItem(toolbox_VolumeReconstruction, QStringLiteral("Volume reconstruction"));

        verticalLayout_toolboxContainer->addWidget(toolbox);


        gridLayout->addWidget(widget_toolboxContainer, 0, 0, 2, 1);

        widget_viewingContainer = new QWidget(centralWidget);
        widget_viewingContainer->setObjectName(QStringLiteral("widget_viewingContainer"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(8);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_viewingContainer->sizePolicy().hasHeightForWidth());
        widget_viewingContainer->setSizePolicy(sizePolicy2);
        verticalLayout_viewingContainer = new QVBoxLayout(widget_viewingContainer);
        verticalLayout_viewingContainer->setSpacing(0);
        verticalLayout_viewingContainer->setContentsMargins(11, 11, 11, 11);
        verticalLayout_viewingContainer->setObjectName(QStringLiteral("verticalLayout_viewingContainer"));
        verticalLayout_viewingContainer->setContentsMargins(0, 0, 0, 0);
        canvas = new QVTKWidget(widget_viewingContainer);
        canvas->setObjectName(QStringLiteral("canvas"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(canvas->sizePolicy().hasHeightForWidth());
        canvas->setSizePolicy(sizePolicy3);
        canvas->setMinimumSize(QSize(640, 480));
        canvas->setSizeIncrement(QSize(4, 3));
        canvas->setFocusPolicy(Qt::ClickFocus);

        verticalLayout_viewingContainer->addWidget(canvas);

        widget_sliceNumberContainer = new QWidget(widget_viewingContainer);
        widget_sliceNumberContainer->setObjectName(QStringLiteral("widget_sliceNumberContainer"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget_sliceNumberContainer->sizePolicy().hasHeightForWidth());
        widget_sliceNumberContainer->setSizePolicy(sizePolicy4);
        horizontalLayout_SliceNumber = new QHBoxLayout(widget_sliceNumberContainer);
        horizontalLayout_SliceNumber->setSpacing(3);
        horizontalLayout_SliceNumber->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_SliceNumber->setObjectName(QStringLiteral("horizontalLayout_SliceNumber"));
        horizontalLayout_SliceNumber->setContentsMargins(3, 0, 3, 0);
        label_SliceNumber = new QLabel(widget_sliceNumberContainer);
        label_SliceNumber->setObjectName(QStringLiteral("label_SliceNumber"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_SliceNumber->sizePolicy().hasHeightForWidth());
        label_SliceNumber->setSizePolicy(sizePolicy5);

        horizontalLayout_SliceNumber->addWidget(label_SliceNumber);

        spinBox_SliceNumber = new QSpinBox(widget_sliceNumberContainer);
        spinBox_SliceNumber->setObjectName(QStringLiteral("spinBox_SliceNumber"));
        spinBox_SliceNumber->setEnabled(false);

        horizontalLayout_SliceNumber->addWidget(spinBox_SliceNumber);

        horizontalSlider_SliceNumber = new QSlider(widget_sliceNumberContainer);
        horizontalSlider_SliceNumber->setObjectName(QStringLiteral("horizontalSlider_SliceNumber"));
        horizontalSlider_SliceNumber->setEnabled(false);
        horizontalSlider_SliceNumber->setOrientation(Qt::Horizontal);

        horizontalLayout_SliceNumber->addWidget(horizontalSlider_SliceNumber);


        verticalLayout_viewingContainer->addWidget(widget_sliceNumberContainer);


        gridLayout->addWidget(widget_viewingContainer, 0, 1, 1, 1);

        fCalMainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(fCalMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setSizeGripEnabled(true);
        fCalMainWindow->setStatusBar(statusBar);

        retranslateUi(fCalMainWindow);

        toolbox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(fCalMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *fCalMainWindow)
    {
        fCalMainWindow->setWindowTitle(QApplication::translate("fCalMainWindow", "fCal", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_SaveConfiguration->setToolTip(QApplication::translate("fCalMainWindow", "Save current device set configuration", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_SaveConfiguration->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_ImageOrientation->setToolTip(QApplication::translate("fCalMainWindow", "Image (2D) Controls", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_ImageOrientation->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_ShowDevices->setToolTip(QApplication::translate("fCalMainWindow", "Show all devices / Show content for current toolbox", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_ShowDevices->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Tools->setToolTip(QApplication::translate("fCalMainWindow", "Tools menu", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_Tools->setText(QString());
        toolbox->setItemText(toolbox->indexOf(toolbox_Configuration), QApplication::translate("fCalMainWindow", "Configuration", Q_NULLPTR));
        toolbox->setItemText(toolbox->indexOf(toolbox_Capturing), QApplication::translate("fCalMainWindow", "Capturing", Q_NULLPTR));
        toolbox->setItemText(toolbox->indexOf(toolbox_StylusCalibration), QApplication::translate("fCalMainWindow", "Stylus calibration", Q_NULLPTR));
        toolbox->setItemText(toolbox->indexOf(toolbox_PhantomRegistration), QApplication::translate("fCalMainWindow", "Phantom registration", Q_NULLPTR));
        toolbox->setItemText(toolbox->indexOf(toolbox_TemporalCalibration), QApplication::translate("fCalMainWindow", "Temporal calibration", Q_NULLPTR));
        toolbox->setItemText(toolbox->indexOf(toolbox_SpatialCalibration), QApplication::translate("fCalMainWindow", "Spatial calibration", Q_NULLPTR));
        toolbox->setItemText(toolbox->indexOf(toolbox_VolumeReconstruction), QApplication::translate("fCalMainWindow", "Volume reconstruction", Q_NULLPTR));
        label_SliceNumber->setText(QApplication::translate("fCalMainWindow", "Slice:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class fCalMainWindow: public Ui_fCalMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCALMAINWINDOW_H
