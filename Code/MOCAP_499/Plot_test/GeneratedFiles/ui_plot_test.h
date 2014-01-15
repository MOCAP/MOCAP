/********************************************************************************
** Form generated from reading UI file 'plot_test.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOT_TEST_H
#define UI_PLOT_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Plot_testClass
{
public:
    QAction *actionBegin_Update;
    QWidget *centralWidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuCommands;

    void setupUi(QMainWindow *Plot_testClass)
    {
        if (Plot_testClass->objectName().isEmpty())
            Plot_testClass->setObjectName(QStringLiteral("Plot_testClass"));
        Plot_testClass->resize(600, 413);
        actionBegin_Update = new QAction(Plot_testClass);
        actionBegin_Update->setObjectName(QStringLiteral("actionBegin_Update"));
        centralWidget = new QWidget(Plot_testClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Plot_testClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(Plot_testClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Plot_testClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Plot_testClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Plot_testClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(Plot_testClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuCommands = new QMenu(menuBar);
        menuCommands->setObjectName(QStringLiteral("menuCommands"));
        Plot_testClass->setMenuBar(menuBar);

        menuBar->addAction(menuCommands->menuAction());
        menuCommands->addAction(actionBegin_Update);

        retranslateUi(Plot_testClass);

        QMetaObject::connectSlotsByName(Plot_testClass);
    } // setupUi

    void retranslateUi(QMainWindow *Plot_testClass)
    {
        Plot_testClass->setWindowTitle(QApplication::translate("Plot_testClass", "Plot_test", 0));
        actionBegin_Update->setText(QApplication::translate("Plot_testClass", "Begin Update", 0));
        menuCommands->setTitle(QApplication::translate("Plot_testClass", "Commands", 0));
    } // retranslateUi

};

namespace Ui {
    class Plot_testClass: public Ui_Plot_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOT_TEST_H
