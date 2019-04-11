// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

/********************************************************************************
** Form generated from reading UI file 'ms_prod_mainwindow.ui'
**
** Created: Tue Jan 29 16:25:09 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MS_PROD_MAINWINDOW_H
#define UI_MS_PROD_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include <QGroupBox>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QRadioButton>
#include <QStatusBar>
#include <QTabWidget>
#include <QTextBrowser>
#include <QToolBar>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_MS_PROD_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabMainWidget;
    QWidget *tabMain;
    QLabel *imageMain;
    QWidget *tabModelForm;
    QCheckBox *cb_modelOpts_GC;
    QCheckBox *cb_ModelOpts_SC;
    QCheckBox *cb_ModelOpts_Pred;
    QCheckBox *cb_ModelOpts_Clim;
    QCheckBox *cb_ModelOpts_Expl;
    QCheckBox *cb_ModelOpts_SO;
    QGroupBox *gb_Forms_Predation;
    QRadioButton *rb_Pred_Form_Type1;
    QRadioButton *rb_Pred_Form_Type2;
    QRadioButton *rb_Pred_Form_Type3;
    QGroupBox *rb_Expl_Forms_Harvest;
    QRadioButton *rb_Expl_Form_F;
    QRadioButton *rb_Expl_Form_qE;
    QGroupBox *gb_Forms_Stochastic;
    QRadioButton *rb_stochastic_none;
    QRadioButton *rb_stochastic_white_noise;
    QRadioButton *rb_stochastic_annual;
    QRadioButton *rb_stochastic2_once_at_start;
    QRadioButton *radioButton_6;
    QWidget *tabParams;
    QTabWidget *tabParamsSubPage;
    QWidget *tabSystem;
    QLineEdit *leSystemK;
    QLabel *labelSystemK;
    QLineEdit *leUnits;
    QLabel *labelUnits;
    QWidget *tabBiology;
    QWidget *tabWGC_2;
    QWidget *tabBGC_2;
    QWidget *tabPredation_2;
    QWidget *tabSpatialOverlap;
    QWidget *tabHarvest;
    QWidget *tabFitting;
    QTextBrowser *textBrowser;
    QRadioButton *rb_Fitting_LSE;
    QRadioButton *rb_Fitting_ML;
    QRadioButton *rb_Fitting_GA;
    QPushButton *pb_fit;
    QWidget *tabOutputs;
    QPushButton *pb_Load;
    QPushButton *pb_Run;
    QMenuBar *menuBar;
    QMenu *menuKRAKEN_1_0;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MS_PROD_MainWindow)
    {
        if (MS_PROD_MainWindow->objectName().isEmpty())
            MS_PROD_MainWindow->setObjectName(QString::fromUtf8("MS_PROD_MainWindow"));
        MS_PROD_MainWindow->resize(802, 694);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MS_PROD_MainWindow->sizePolicy().hasHeightForWidth());
        MS_PROD_MainWindow->setSizePolicy(sizePolicy);
        MS_PROD_MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(232, 232, 232);"));
        centralWidget = new QWidget(MS_PROD_MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabMainWidget = new QTabWidget(centralWidget);
        tabMainWidget->setObjectName(QString::fromUtf8("tabMainWidget"));
        tabMainWidget->setGeometry(QRect(10, 10, 781, 571));
        tabMainWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);"));
        tabMain = new QWidget();
        tabMain->setObjectName(QString::fromUtf8("tabMain"));
        imageMain = new QLabel(tabMain);
        imageMain->setObjectName(QString::fromUtf8("imageMain"));
        imageMain->setGeometry(QRect(10, 10, 751, 521));
        imageMain->setPixmap(QPixmap(QString::fromUtf8(":/new/MyImages/MS_PROD_MAIN_IMAGE.jpg")));
        imageMain->setScaledContents(true);
        tabMainWidget->addTab(tabMain, QString());
        tabModelForm = new QWidget();
        tabModelForm->setObjectName(QString::fromUtf8("tabModelForm"));
        cb_modelOpts_GC = new QCheckBox(tabModelForm);
        cb_modelOpts_GC->setObjectName(QString::fromUtf8("cb_modelOpts_GC"));
        cb_modelOpts_GC->setGeometry(QRect(20, 10, 111, 17));
        cb_modelOpts_GC->setChecked(true);
        cb_ModelOpts_SC = new QCheckBox(tabModelForm);
        cb_ModelOpts_SC->setObjectName(QString::fromUtf8("cb_ModelOpts_SC"));
        cb_ModelOpts_SC->setGeometry(QRect(170, 10, 121, 17));
        cb_ModelOpts_SC->setChecked(true);
        cb_ModelOpts_Pred = new QCheckBox(tabModelForm);
        cb_ModelOpts_Pred->setObjectName(QString::fromUtf8("cb_ModelOpts_Pred"));
        cb_ModelOpts_Pred->setGeometry(QRect(340, 10, 70, 17));
        cb_ModelOpts_Pred->setChecked(true);
        cb_ModelOpts_Clim = new QCheckBox(tabModelForm);
        cb_ModelOpts_Clim->setObjectName(QString::fromUtf8("cb_ModelOpts_Clim"));
        cb_ModelOpts_Clim->setGeometry(QRect(570, 10, 70, 17));
        cb_ModelOpts_Clim->setChecked(true);
        cb_ModelOpts_Expl = new QCheckBox(tabModelForm);
        cb_ModelOpts_Expl->setObjectName(QString::fromUtf8("cb_ModelOpts_Expl"));
        cb_ModelOpts_Expl->setGeometry(QRect(460, 10, 81, 17));
        cb_ModelOpts_Expl->setChecked(true);
        cb_ModelOpts_SO = new QCheckBox(tabModelForm);
        cb_ModelOpts_SO->setObjectName(QString::fromUtf8("cb_ModelOpts_SO"));
        cb_ModelOpts_SO->setGeometry(QRect(660, 10, 101, 17));
        cb_ModelOpts_SO->setChecked(true);
        gb_Forms_Predation = new QGroupBox(tabModelForm);
        gb_Forms_Predation->setObjectName(QString::fromUtf8("gb_Forms_Predation"));
        gb_Forms_Predation->setGeometry(QRect(20, 50, 311, 131));
        rb_Pred_Form_Type1 = new QRadioButton(gb_Forms_Predation);
        rb_Pred_Form_Type1->setObjectName(QString::fromUtf8("rb_Pred_Form_Type1"));
        rb_Pred_Form_Type1->setGeometry(QRect(20, 30, 82, 17));
        rb_Pred_Form_Type1->setChecked(true);
        rb_Pred_Form_Type2 = new QRadioButton(gb_Forms_Predation);
        rb_Pred_Form_Type2->setObjectName(QString::fromUtf8("rb_Pred_Form_Type2"));
        rb_Pred_Form_Type2->setGeometry(QRect(20, 60, 82, 17));
        rb_Pred_Form_Type2->setChecked(false);
        rb_Pred_Form_Type3 = new QRadioButton(gb_Forms_Predation);
        rb_Pred_Form_Type3->setObjectName(QString::fromUtf8("rb_Pred_Form_Type3"));
        rb_Pred_Form_Type3->setGeometry(QRect(20, 90, 82, 17));
        rb_Expl_Forms_Harvest = new QGroupBox(tabModelForm);
        rb_Expl_Forms_Harvest->setObjectName(QString::fromUtf8("rb_Expl_Forms_Harvest"));
        rb_Expl_Forms_Harvest->setGeometry(QRect(350, 50, 401, 131));
        rb_Expl_Form_F = new QRadioButton(rb_Expl_Forms_Harvest);
        rb_Expl_Form_F->setObjectName(QString::fromUtf8("rb_Expl_Form_F"));
        rb_Expl_Form_F->setGeometry(QRect(20, 30, 101, 17));
        rb_Expl_Form_F->setChecked(true);
        rb_Expl_Form_qE = new QRadioButton(rb_Expl_Forms_Harvest);
        rb_Expl_Form_qE->setObjectName(QString::fromUtf8("rb_Expl_Form_qE"));
        rb_Expl_Form_qE->setGeometry(QRect(20, 90, 131, 17));
        gb_Forms_Stochastic = new QGroupBox(tabModelForm);
        gb_Forms_Stochastic->setObjectName(QString::fromUtf8("gb_Forms_Stochastic"));
        gb_Forms_Stochastic->setGeometry(QRect(80, 190, 541, 171));
        rb_stochastic_none = new QRadioButton(gb_Forms_Stochastic);
        rb_stochastic_none->setObjectName(QString::fromUtf8("rb_stochastic_none"));
        rb_stochastic_none->setGeometry(QRect(30, 40, 82, 17));
        rb_stochastic_none->setChecked(true);
        rb_stochastic_white_noise = new QRadioButton(gb_Forms_Stochastic);
        rb_stochastic_white_noise->setObjectName(QString::fromUtf8("rb_stochastic_white_noise"));
        rb_stochastic_white_noise->setGeometry(QRect(30, 80, 82, 17));
        rb_stochastic_annual = new QRadioButton(gb_Forms_Stochastic);
        rb_stochastic_annual->setObjectName(QString::fromUtf8("rb_stochastic_annual"));
        rb_stochastic_annual->setGeometry(QRect(190, 40, 82, 17));
        rb_stochastic2_once_at_start = new QRadioButton(gb_Forms_Stochastic);
        rb_stochastic2_once_at_start->setObjectName(QString::fromUtf8("rb_stochastic2_once_at_start"));
        rb_stochastic2_once_at_start->setGeometry(QRect(190, 80, 82, 17));
        radioButton_6 = new QRadioButton(gb_Forms_Stochastic);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        radioButton_6->setGeometry(QRect(30, 120, 82, 17));
        tabMainWidget->addTab(tabModelForm, QString());
        tabParams = new QWidget();
        tabParams->setObjectName(QString::fromUtf8("tabParams"));
        tabParamsSubPage = new QTabWidget(tabParams);
        tabParamsSubPage->setObjectName(QString::fromUtf8("tabParamsSubPage"));
        tabParamsSubPage->setGeometry(QRect(0, 10, 771, 531));
        tabParamsSubPage->setTabPosition(QTabWidget::West);
        tabSystem = new QWidget();
        tabSystem->setObjectName(QString::fromUtf8("tabSystem"));
        leSystemK = new QLineEdit(tabSystem);
        leSystemK->setObjectName(QString::fromUtf8("leSystemK"));
        leSystemK->setGeometry(QRect(270, 70, 113, 31));
        QFont font;
        font.setPointSize(16);
        leSystemK->setFont(font);
        labelSystemK = new QLabel(tabSystem);
        labelSystemK->setObjectName(QString::fromUtf8("labelSystemK"));
        labelSystemK->setGeometry(QRect(190, 80, 71, 16));
        QFont font1;
        font1.setPointSize(12);
        labelSystemK->setFont(font1);
        leUnits = new QLineEdit(tabSystem);
        leUnits->setObjectName(QString::fromUtf8("leUnits"));
        leUnits->setGeometry(QRect(270, 120, 61, 31));
        leUnits->setFont(font);
        labelUnits = new QLabel(tabSystem);
        labelUnits->setObjectName(QString::fromUtf8("labelUnits"));
        labelUnits->setGeometry(QRect(220, 130, 46, 13));
        labelUnits->setFont(font1);
        tabParamsSubPage->addTab(tabSystem, QString());
        tabBiology = new QWidget();
        tabBiology->setObjectName(QString::fromUtf8("tabBiology"));
        tabParamsSubPage->addTab(tabBiology, QString());
        tabWGC_2 = new QWidget();
        tabWGC_2->setObjectName(QString::fromUtf8("tabWGC_2"));
        tabParamsSubPage->addTab(tabWGC_2, QString());
        tabBGC_2 = new QWidget();
        tabBGC_2->setObjectName(QString::fromUtf8("tabBGC_2"));
        tabParamsSubPage->addTab(tabBGC_2, QString());
        tabPredation_2 = new QWidget();
        tabPredation_2->setObjectName(QString::fromUtf8("tabPredation_2"));
        tabParamsSubPage->addTab(tabPredation_2, QString());
        tabSpatialOverlap = new QWidget();
        tabSpatialOverlap->setObjectName(QString::fromUtf8("tabSpatialOverlap"));
        tabParamsSubPage->addTab(tabSpatialOverlap, QString());
        tabHarvest = new QWidget();
        tabHarvest->setObjectName(QString::fromUtf8("tabHarvest"));
        tabParamsSubPage->addTab(tabHarvest, QString());
        tabMainWidget->addTab(tabParams, QString());
        tabFitting = new QWidget();
        tabFitting->setObjectName(QString::fromUtf8("tabFitting"));
        textBrowser = new QTextBrowser(tabFitting);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 40, 711, 441));
        rb_Fitting_LSE = new QRadioButton(tabFitting);
        rb_Fitting_LSE->setObjectName(QString::fromUtf8("rb_Fitting_LSE"));
        rb_Fitting_LSE->setGeometry(QRect(40, 10, 211, 17));
        rb_Fitting_LSE->setChecked(false);
        rb_Fitting_ML = new QRadioButton(tabFitting);
        rb_Fitting_ML->setObjectName(QString::fromUtf8("rb_Fitting_ML"));
        rb_Fitting_ML->setGeometry(QRect(310, 10, 181, 17));
        rb_Fitting_GA = new QRadioButton(tabFitting);
        rb_Fitting_GA->setObjectName(QString::fromUtf8("rb_Fitting_GA"));
        rb_Fitting_GA->setGeometry(QRect(570, 10, 171, 20));
        rb_Fitting_GA->setChecked(true);
        pb_fit = new QPushButton(tabFitting);
        pb_fit->setObjectName(QString::fromUtf8("pb_fit"));
        pb_fit->setGeometry(QRect(340, 490, 101, 41));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        pb_fit->setFont(font2);
        pb_fit->setStyleSheet(QString::fromUtf8("background-color: rgb(86, 6, 3);\n"
"color: rgb(255, 255, 255);"));
        tabMainWidget->addTab(tabFitting, QString());
        tabOutputs = new QWidget();
        tabOutputs->setObjectName(QString::fromUtf8("tabOutputs"));
        tabMainWidget->addTab(tabOutputs, QString());
        pb_Load = new QPushButton(centralWidget);
        pb_Load->setObjectName(QString::fromUtf8("pb_Load"));
        pb_Load->setGeometry(QRect(280, 590, 111, 41));
        pb_Load->setFont(font2);
        pb_Load->setStyleSheet(QString::fromUtf8("background-color: rgb(219, 239, 241);\n"
"border-color: rgb(0, 0, 127);"));
        pb_Run = new QPushButton(centralWidget);
        pb_Run->setObjectName(QString::fromUtf8("pb_Run"));
        pb_Run->setGeometry(QRect(410, 590, 111, 41));
        pb_Run->setFont(font2);
        pb_Run->setStyleSheet(QString::fromUtf8("background-color: rgb(219, 239, 241);\n"
"border-color: rgb(0, 0, 127);"));
        MS_PROD_MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MS_PROD_MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 802, 25));
        menuKRAKEN_1_0 = new QMenu(menuBar);
        menuKRAKEN_1_0->setObjectName(QString::fromUtf8("menuKRAKEN_1_0"));
        MS_PROD_MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MS_PROD_MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MS_PROD_MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MS_PROD_MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MS_PROD_MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuKRAKEN_1_0->menuAction());

        retranslateUi(MS_PROD_MainWindow);
        QObject::connect(pb_Load, SIGNAL(clicked()), MS_PROD_MainWindow, SLOT(setFocus()));

        tabMainWidget->setCurrentIndex(0);
        tabParamsSubPage->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MS_PROD_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MS_PROD_MainWindow)
    {
        MS_PROD_MainWindow->setWindowTitle(QApplication::translate("MS_PROD_MainWindow", "KRAKEN (1.1)", 0));
        imageMain->setText(QString());
        tabMainWidget->setTabText(tabMainWidget->indexOf(tabMain), QApplication::translate("MS_PROD_MainWindow", "Main", 0));
        cb_modelOpts_GC->setText(QApplication::translate("MS_PROD_MainWindow", "Guild Competition", 0));
        cb_ModelOpts_SC->setText(QApplication::translate("MS_PROD_MainWindow", "Species Competition", 0));
        cb_ModelOpts_Pred->setText(QApplication::translate("MS_PROD_MainWindow", "Predation", 0));
        cb_ModelOpts_Clim->setText(QApplication::translate("MS_PROD_MainWindow", "Climate", 0));
        cb_ModelOpts_Expl->setText(QApplication::translate("MS_PROD_MainWindow", "Exploitation",0));
        cb_ModelOpts_SO->setText(QApplication::translate("MS_PROD_MainWindow", "Spatial Overlap", 0));
        gb_Forms_Predation->setTitle(QApplication::translate("MS_PROD_MainWindow", "Predation Functional Forms", 0));
        rb_Pred_Form_Type1->setText(QApplication::translate("MS_PROD_MainWindow", "Type I", 0));
        rb_Pred_Form_Type2->setText(QApplication::translate("MS_PROD_MainWindow", "Type II", 0));
        rb_Pred_Form_Type3->setText(QApplication::translate("MS_PROD_MainWindow", "Type III", 0));
        rb_Expl_Forms_Harvest->setTitle(QApplication::translate("MS_PROD_MainWindow", "Exploitation Forms", 0));
        rb_Expl_Form_F->setText(QApplication::translate("MS_PROD_MainWindow", "Fishing mortality", 0));
        rb_Expl_Form_qE->setText(QApplication::translate("MS_PROD_MainWindow", "Effort and catchability", 0));
        gb_Forms_Stochastic->setTitle(QApplication::translate("MS_PROD_MainWindow", "Stochastic Form", 0));
        rb_stochastic_none->setText(QApplication::translate("MS_PROD_MainWindow", "None", 0));
        rb_stochastic_white_noise->setText(QApplication::translate("MS_PROD_MainWindow", "White Noise", 0));
        rb_stochastic_annual->setText(QApplication::translate("MS_PROD_MainWindow", "Annual", 0));
        rb_stochastic2_once_at_start->setText(QApplication::translate("MS_PROD_MainWindow", "Once at Start", 0));
        radioButton_6->setText(QApplication::translate("MS_PROD_MainWindow", "Red Noise", 0));
        tabMainWidget->setTabText(tabMainWidget->indexOf(tabModelForm), QApplication::translate("MS_PROD_MainWindow", "Model Options", 0));
        leSystemK->setText(QApplication::translate("MS_PROD_MainWindow", "0", 0));
        labelSystemK->setText(QApplication::translate("MS_PROD_MainWindow", "System K", 0));
        leUnits->setText(QApplication::translate("MS_PROD_MainWindow", "mt", 0));
        labelUnits->setText(QApplication::translate("MS_PROD_MainWindow", "Units", 0));
        tabParamsSubPage->setTabText(tabParamsSubPage->indexOf(tabSystem), QApplication::translate("MS_PROD_MainWindow", "System", 0));
        tabParamsSubPage->setTabText(tabParamsSubPage->indexOf(tabBiology), QApplication::translate("MS_PROD_MainWindow", "Biology", 0));
        tabParamsSubPage->setTabText(tabParamsSubPage->indexOf(tabWGC_2), QApplication::translate("MS_PROD_MainWindow", "WGC", 0));
        tabParamsSubPage->setTabText(tabParamsSubPage->indexOf(tabBGC_2), QApplication::translate("MS_PROD_MainWindow", "BGC", 0));
        tabParamsSubPage->setTabText(tabParamsSubPage->indexOf(tabPredation_2), QApplication::translate("MS_PROD_MainWindow", "Predation", 0));
        tabParamsSubPage->setTabText(tabParamsSubPage->indexOf(tabSpatialOverlap), QApplication::translate("MS_PROD_MainWindow", "Spatial Overlap", 0));
        tabParamsSubPage->setTabText(tabParamsSubPage->indexOf(tabHarvest), QApplication::translate("MS_PROD_MainWindow", "Exploitation", 0));
        tabMainWidget->setTabText(tabMainWidget->indexOf(tabParams), QApplication::translate("MS_PROD_MainWindow", "Parameters", 0));
        rb_Fitting_LSE->setText(QApplication::translate("MS_PROD_MainWindow", "Least Squares Estimation", 0));
        rb_Fitting_ML->setText(QApplication::translate("MS_PROD_MainWindow", "Maximum Likelihood", 0));
        rb_Fitting_GA->setText(QApplication::translate("MS_PROD_MainWindow", "Genetic Algorithm", 0));
        pb_fit->setText(QApplication::translate("MS_PROD_MainWindow", "FIT", 0));
        tabMainWidget->setTabText(tabMainWidget->indexOf(tabFitting), QApplication::translate("MS_PROD_MainWindow", "Fitting", 0));
        tabMainWidget->setTabText(tabMainWidget->indexOf(tabOutputs), QApplication::translate("MS_PROD_MainWindow", "Outputs", 0));
        pb_Load->setText(QApplication::translate("MS_PROD_MainWindow", "LOAD", 0));
#ifndef QT_NO_ACCESSIBILITY
        pb_Run->setAccessibleName(QApplication::translate("MS_PROD_MainWindow", "RUN", 0));
#endif // QT_NO_ACCESSIBILITY
        pb_Run->setText(QApplication::translate("MS_PROD_MainWindow", "RUN", 0));
        menuKRAKEN_1_0->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MS_PROD_MainWindow: public Ui_MS_PROD_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MS_PROD_MAINWINDOW_H
