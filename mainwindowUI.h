/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionAbout;
    QAction *actionInput;
    QAction *actionPng;
    QAction *actionJpg;
    QAction *actionHif;
    QAction *actionQuit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *SquareBtn;
    QPushButton *polygonButton;
    QLabel *label_10;
    QPushButton *DragBtn;
    QPushButton *textColor;
    QPushButton *pencilButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *lineButton;
    QPushButton *PenColorButton;
    QLabel *label_2;
    QPushButton *BrushColorButton_2;
    QPushButton *roundSquareButton;
    QPushButton *textButton;
    QSlider *brushAlpha;
    QPushButton *EllipseButton;
    QLabel *label;
    QPushButton *scaleButton;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QLabel *label_5;
    QFrame *line_2;
    QSlider *penAlpha;
    QLabel *label_17;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QPushButton *moveToTop;
    QGraphicsView *brushPreview;
    QFrame *line_4;
    QFontComboBox *font;
    QGraphicsView *penPreview;
    QLabel *label_13;
    QSlider *textSize;
    QComboBox *comboBox;
    QLabel *label_3;
    QPushButton *moveToBottom;
    QLabel *label_14;
    QLabel *label_16;
    QFrame *line;
    QLabel *label_6;
    QLabel *label_15;
    QFrame *line_3;
    QPushButton *clearButton;
    QSlider *penThickness;
    QComboBox *penStyle;
    QLabel *label_11;
    QLabel *information;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *label_18;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_3;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(928, 634);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setBaseSize(QSize(1200, 600));
        MainWindow->setMouseTracking(true);
        MainWindow->setStyleSheet(QStringLiteral("border-image: url(:/icons/background.png);"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionInput = new QAction(MainWindow);
        actionInput->setObjectName(QStringLiteral("actionInput"));
        actionPng = new QAction(MainWindow);
        actionPng->setObjectName(QStringLiteral("actionPng"));
        actionJpg = new QAction(MainWindow);
        actionJpg->setObjectName(QStringLiteral("actionJpg"));
        actionHif = new QAction(MainWindow);
        actionHif->setObjectName(QStringLiteral("actionHif"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(150, 0));
        groupBox->setMaximumSize(QSize(15, 16777215));
        groupBox->setStyleSheet(QStringLiteral("border-image: NULL;"));
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        SquareBtn = new QPushButton(groupBox);
        SquareBtn->setObjectName(QStringLiteral("SquareBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(SquareBtn->sizePolicy().hasHeightForWidth());
        SquareBtn->setSizePolicy(sizePolicy2);
        SquareBtn->setStyleSheet(QStringLiteral(""));
        SquareBtn->setIconSize(QSize(30, 30));
        SquareBtn->setCheckable(false);
        SquareBtn->setAutoDefault(false);
        SquareBtn->setFlat(false);

        gridLayout_2->addWidget(SquareBtn, 2, 1, 1, 1);

        polygonButton = new QPushButton(groupBox);
        polygonButton->setObjectName(QStringLiteral("polygonButton"));
        sizePolicy2.setHeightForWidth(polygonButton->sizePolicy().hasHeightForWidth());
        polygonButton->setSizePolicy(sizePolicy2);
        polygonButton->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(polygonButton, 4, 1, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFrameShape(QFrame::StyledPanel);
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_10, 8, 1, 1, 2);

        DragBtn = new QPushButton(groupBox);
        DragBtn->setObjectName(QStringLiteral("DragBtn"));
        sizePolicy1.setHeightForWidth(DragBtn->sizePolicy().hasHeightForWidth());
        DragBtn->setSizePolicy(sizePolicy1);
        DragBtn->setMaximumSize(QSize(16777215, 16777215));
        DragBtn->setStyleSheet(QStringLiteral("border-image: NULL;"));
        DragBtn->setIconSize(QSize(40, 40));
        DragBtn->setCheckable(false);
        DragBtn->setAutoRepeat(false);
        DragBtn->setAutoDefault(false);
        DragBtn->setFlat(false);

        gridLayout_2->addWidget(DragBtn, 1, 1, 1, 2);

        textColor = new QPushButton(groupBox);
        textColor->setObjectName(QStringLiteral("textColor"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(textColor->sizePolicy().hasHeightForWidth());
        textColor->setSizePolicy(sizePolicy3);
        textColor->setMinimumSize(QSize(60, 10));
        textColor->setMaximumSize(QSize(16777215, 15));

        gridLayout_2->addWidget(textColor, 14, 2, 1, 1);

        pencilButton = new QPushButton(groupBox);
        pencilButton->setObjectName(QStringLiteral("pencilButton"));
        sizePolicy2.setHeightForWidth(pencilButton->sizePolicy().hasHeightForWidth());
        pencilButton->setSizePolicy(sizePolicy2);
        pencilButton->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(pencilButton, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 6, 1, 1, 1);

        lineButton = new QPushButton(groupBox);
        lineButton->setObjectName(QStringLiteral("lineButton"));
        sizePolicy2.setHeightForWidth(lineButton->sizePolicy().hasHeightForWidth());
        lineButton->setSizePolicy(sizePolicy2);
        lineButton->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(lineButton, 4, 2, 1, 1);

        PenColorButton = new QPushButton(groupBox);
        PenColorButton->setObjectName(QStringLiteral("PenColorButton"));
        sizePolicy3.setHeightForWidth(PenColorButton->sizePolicy().hasHeightForWidth());
        PenColorButton->setSizePolicy(sizePolicy3);
        PenColorButton->setMinimumSize(QSize(60, 0));
        PenColorButton->setMaximumSize(QSize(16777215, 15));

        gridLayout_2->addWidget(PenColorButton, 12, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 12, 1, 1, 1);

        BrushColorButton_2 = new QPushButton(groupBox);
        BrushColorButton_2->setObjectName(QStringLiteral("BrushColorButton_2"));
        sizePolicy3.setHeightForWidth(BrushColorButton_2->sizePolicy().hasHeightForWidth());
        BrushColorButton_2->setSizePolicy(sizePolicy3);
        BrushColorButton_2->setMinimumSize(QSize(60, 0));
        BrushColorButton_2->setMaximumSize(QSize(16777215, 15));
        BrushColorButton_2->setBaseSize(QSize(20, 0));
        BrushColorButton_2->setStyleSheet(QStringLiteral("/*background-color: rgb(128, 0, 128);*/"));

        gridLayout_2->addWidget(BrushColorButton_2, 9, 2, 1, 1);

        roundSquareButton = new QPushButton(groupBox);
        roundSquareButton->setObjectName(QStringLiteral("roundSquareButton"));
        sizePolicy2.setHeightForWidth(roundSquareButton->sizePolicy().hasHeightForWidth());
        roundSquareButton->setSizePolicy(sizePolicy2);
        roundSquareButton->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(roundSquareButton, 3, 2, 1, 1);

        textButton = new QPushButton(groupBox);
        textButton->setObjectName(QStringLiteral("textButton"));
        sizePolicy2.setHeightForWidth(textButton->sizePolicy().hasHeightForWidth());
        textButton->setSizePolicy(sizePolicy2);
        textButton->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(textButton, 5, 2, 1, 1);

        brushAlpha = new QSlider(groupBox);
        brushAlpha->setObjectName(QStringLiteral("brushAlpha"));
        brushAlpha->setMaximum(255);
        brushAlpha->setSliderPosition(255);
        brushAlpha->setOrientation(Qt::Horizontal);
        brushAlpha->setInvertedAppearance(false);
        brushAlpha->setInvertedControls(false);

        gridLayout_2->addWidget(brushAlpha, 10, 2, 1, 1);

        EllipseButton = new QPushButton(groupBox);
        EllipseButton->setObjectName(QStringLiteral("EllipseButton"));
        sizePolicy2.setHeightForWidth(EllipseButton->sizePolicy().hasHeightForWidth());
        EllipseButton->setSizePolicy(sizePolicy2);
        EllipseButton->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(EllipseButton, 3, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 9, 1, 1, 1);

        scaleButton = new QPushButton(groupBox);
        scaleButton->setObjectName(QStringLiteral("scaleButton"));
        sizePolicy2.setHeightForWidth(scaleButton->sizePolicy().hasHeightForWidth());
        scaleButton->setSizePolicy(sizePolicy2);
        scaleButton->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(scaleButton, 5, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 14, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 6, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 10, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 13, 1, 1, 1);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy4);
        line_2->setLineWidth(1);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 7, 1, 1, 2);

        penAlpha = new QSlider(groupBox);
        penAlpha->setObjectName(QStringLiteral("penAlpha"));
        penAlpha->setMaximum(255);
        penAlpha->setValue(255);
        penAlpha->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(penAlpha, 13, 2, 1, 1);

        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setStyleSheet(QStringLiteral("border-image: NULL;"));
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_17, 0, 1, 1, 2);


        horizontalLayout_2->addWidget(groupBox);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        sizePolicy2.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy2);
        graphicsView->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(graphicsView);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy5);
        groupBox_2->setMaximumSize(QSize(200, 16777215));
        groupBox_2->setStyleSheet(QStringLiteral("border-image: NULL;"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        groupBox_2->setFlat(false);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        moveToTop = new QPushButton(groupBox_2);
        moveToTop->setObjectName(QStringLiteral("moveToTop"));

        gridLayout_3->addWidget(moveToTop, 16, 0, 1, 1);

        brushPreview = new QGraphicsView(groupBox_2);
        brushPreview->setObjectName(QStringLiteral("brushPreview"));
        brushPreview->setMaximumSize(QSize(16777215, 20));

        gridLayout_3->addWidget(brushPreview, 9, 1, 1, 1);

        line_4 = new QFrame(groupBox_2);
        line_4->setObjectName(QStringLiteral("line_4"));
        sizePolicy4.setHeightForWidth(line_4->sizePolicy().hasHeightForWidth());
        line_4->setSizePolicy(sizePolicy4);
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_4, 14, 0, 1, 2);

        font = new QFontComboBox(groupBox_2);
        font->setObjectName(QStringLiteral("font"));

        gridLayout_3->addWidget(font, 12, 1, 1, 1);

        penPreview = new QGraphicsView(groupBox_2);
        penPreview->setObjectName(QStringLiteral("penPreview"));
        penPreview->setMaximumSize(QSize(16777215, 20));

        gridLayout_3->addWidget(penPreview, 5, 1, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 13, 0, 1, 1);

        textSize = new QSlider(groupBox_2);
        textSize->setObjectName(QStringLiteral("textSize"));
        textSize->setMinimum(5);
        textSize->setMaximum(80);
        textSize->setPageStep(1);
        textSize->setValue(10);
        textSize->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(textSize, 13, 1, 1, 1);

        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_3->addWidget(comboBox, 8, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        moveToBottom = new QPushButton(groupBox_2);
        moveToBottom->setObjectName(QStringLiteral("moveToBottom"));

        gridLayout_3->addWidget(moveToBottom, 16, 1, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFrameShape(QFrame::NoFrame);
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_14, 1, 0, 1, 2);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFrameShape(QFrame::NoFrame);
        label_16->setFrameShadow(QFrame::Sunken);
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_16, 11, 0, 1, 2);

        line = new QFrame(groupBox_2);
        line->setObjectName(QStringLiteral("line"));
        sizePolicy4.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy4);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 6, 0, 1, 2);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 3, 0, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFrameShape(QFrame::NoFrame);
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_15, 7, 0, 1, 2);

        line_3 = new QFrame(groupBox_2);
        line_3->setObjectName(QStringLiteral("line_3"));
        sizePolicy4.setHeightForWidth(line_3->sizePolicy().hasHeightForWidth());
        line_3->setSizePolicy(sizePolicy4);
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_3, 10, 0, 1, 2);

        clearButton = new QPushButton(groupBox_2);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        gridLayout_3->addWidget(clearButton, 15, 0, 1, 2);

        penThickness = new QSlider(groupBox_2);
        penThickness->setObjectName(QStringLiteral("penThickness"));
        penThickness->setMaximum(10);
        penThickness->setPageStep(1);
        penThickness->setValue(1);
        penThickness->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(penThickness, 3, 1, 1, 1);

        penStyle = new QComboBox(groupBox_2);
        penStyle->setObjectName(QStringLiteral("penStyle"));
        penStyle->setEditable(false);

        gridLayout_3->addWidget(penStyle, 2, 1, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_3->addWidget(label_11, 5, 0, 1, 1);

        information = new QLabel(groupBox_2);
        information->setObjectName(QStringLiteral("information"));
        information->setMinimumSize(QSize(0, 0));
        information->setFrameShape(QFrame::NoFrame);
        information->setLineWidth(1);
        information->setTextFormat(Qt::RichText);
        information->setScaledContents(false);
        information->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(information, 17, 0, 1, 2);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 8, 0, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 12, 0, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_3->addWidget(label_12, 9, 0, 1, 1);

        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_18, 0, 0, 1, 2);


        horizontalLayout_2->addWidget(groupBox_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 928, 25));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_3 = new QMenu(menu);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        mainToolBar->setMaximumSize(QSize(16777215, 0));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionNew);
        menu->addAction(actionInput);
        menu->addAction(menu_3->menuAction());
        menu->addAction(actionQuit);
        menu_3->addAction(actionPng);
        menu_3->addAction(actionJpg);
        menu_3->addAction(actionHif);
        menu_2->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNew->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272", 0));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "\344\275\234\350\200\205\344\277\241\346\201\257", 0));
        actionInput->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245\345\233\276\345\203\217", 0));
        actionInput->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionPng->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\344\270\272PNG", 0));
        actionJpg->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\344\270\272JPG", 0));
        actionHif->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\344\270\272GIF", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0));
        groupBox->setTitle(QString());
        SquareBtn->setText(QString());
        polygonButton->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262\350\256\276\347\275\256", 0));
        DragBtn->setText(QString());
        textColor->setText(QString());
        pencilButton->setText(QString());
        lineButton->setText(QString());
        PenColorButton->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\347\272\277\346\235\241\351\242\234\350\211\262", 0));
        BrushColorButton_2->setText(QString());
        roundSquareButton->setText(QString());
        textButton->setText(QString());
        EllipseButton->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\345\241\253\345\205\205\351\242\234\350\211\262", 0));
        scaleButton->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "\346\226\207\345\255\227\351\242\234\350\211\262", 0));
        label_4->setText(QApplication::translate("MainWindow", "\351\200\217\346\230\216\345\272\246", 0));
        label_5->setText(QApplication::translate("MainWindow", "\351\200\217\346\230\216\345\272\246", 0));
        label_17->setText(QApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217", 0));
        groupBox_2->setTitle(QString());
        moveToTop->setText(QApplication::translate("MainWindow", "\347\247\273\350\207\263\351\241\266\345\261\202", 0));
        label_13->setText(QApplication::translate("MainWindow", "\346\226\207\345\255\227\345\244\247\345\260\217", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "SolidPattern", 0)
         << QApplication::translate("MainWindow", "Dense1 Pattern", 0)
         << QApplication::translate("MainWindow", "Dense2 Pattern", 0)
         << QApplication::translate("MainWindow", "Dense3 Pattern", 0)
         << QApplication::translate("MainWindow", "Dense4 Pattern", 0)
         << QApplication::translate("MainWindow", "Dense5 Pattern", 0)
         << QApplication::translate("MainWindow", "Dense6 Pattern", 0)
         << QApplication::translate("MainWindow", "Dense7 Pattern", 0)
         << QApplication::translate("MainWindow", "Hor Pattern", 0)
         << QApplication::translate("MainWindow", "Ver Pattern", 0)
         << QApplication::translate("MainWindow", "Cross Pattern", 0)
         << QApplication::translate("MainWindow", "BDiagPattern", 0)
         << QApplication::translate("MainWindow", "FDiagPattern", 0)
         << QApplication::translate("MainWindow", "DiagCrossPattern", 0)
        );
        label_3->setText(QApplication::translate("MainWindow", "\347\272\277\346\235\241\346\240\267\345\274\217", 0));
        moveToBottom->setText(QApplication::translate("MainWindow", "\347\247\273\350\207\263\345\272\225\345\261\202", 0));
        label_14->setText(QApplication::translate("MainWindow", "\347\272\277\346\235\241\350\256\276\347\275\256", 0));
        label_16->setText(QApplication::translate("MainWindow", "\346\226\207\345\255\227\350\256\276\347\275\256", 0));
        label_6->setText(QApplication::translate("MainWindow", "\347\272\277\346\235\241\347\262\227\347\273\206", 0));
        label_15->setText(QApplication::translate("MainWindow", "\345\241\253\345\205\205\350\256\276\347\275\256", 0));
        clearButton->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\347\224\273\345\270\203", 0));
        penStyle->clear();
        penStyle->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "SolidLine", 0)
         << QApplication::translate("MainWindow", "DashLine", 0)
         << QApplication::translate("MainWindow", "DotLine", 0)
         << QApplication::translate("MainWindow", "DashDotLine", 0)
         << QApplication::translate("MainWindow", "DashDotDotLine", 0)
        );
        penStyle->setCurrentText(QApplication::translate("MainWindow", "SolidLine", 0));
        label_11->setText(QApplication::translate("MainWindow", "\347\272\277\346\235\241\351\242\204\350\247\210", 0));
        information->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-style:italic;\">Designed by </span></p><p><span style=\" font-size:10pt; font-style:italic;\">Li Zhihao, Jin Peng, A Wenxin</span></p><p><span style=\" font-size:10pt; font-style:italic;\">Copyright(2016) all right reserved</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("MainWindow", "\345\241\253\345\205\205\346\240\267\345\274\217", 0));
        label_8->setText(QApplication::translate("MainWindow", "\346\226\207\345\255\227\345\255\227\344\275\223", 0));
        label_12->setText(QApplication::translate("MainWindow", "\345\241\253\345\205\205\351\242\204\350\247\210", 0));
        label_18->setText(QApplication::translate("MainWindow", "\344\270\252\346\200\247\345\214\226", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "\344\277\235\345\255\230\345\233\276\345\203\217", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
