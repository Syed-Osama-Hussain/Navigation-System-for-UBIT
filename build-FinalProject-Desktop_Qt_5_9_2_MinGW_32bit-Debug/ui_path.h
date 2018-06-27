/********************************************************************************
** Form generated from reading UI file 'path.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATH_H
#define UI_PATH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Path
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *Path_Display;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Path)
    {
        if (Path->objectName().isEmpty())
            Path->setObjectName(QStringLiteral("Path"));
        Path->resize(369, 249);
        centralwidget = new QWidget(Path);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 160, 75, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(26, 19, 321, 41));
        label->setStyleSheet(QLatin1String("color: rgb(0, 85, 0);\n"
"font: 14pt \"Times New Roman\";\n"
"font: 75 italic 14pt \"Times New Roman\";"));
        Path_Display = new QLabel(centralwidget);
        Path_Display->setObjectName(QStringLiteral("Path_Display"));
        Path_Display->setGeometry(QRect(10, 60, 351, 71));
        Path_Display->setStyleSheet(QStringLiteral("font: 75 10pt \"MS Shell Dlg 2\";"));
        Path->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Path);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 369, 18));
        Path->setMenuBar(menubar);
        statusbar = new QStatusBar(Path);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Path->setStatusBar(statusbar);

        retranslateUi(Path);

        QMetaObject::connectSlotsByName(Path);
    } // setupUi

    void retranslateUi(QMainWindow *Path)
    {
        Path->setWindowTitle(QApplication::translate("Path", "Path Displayer", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Path", "OK", Q_NULLPTR));
        label->setText(QApplication::translate("Path", "         The Path to the Destination is", Q_NULLPTR));
        Path_Display->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Path: public Ui_Path {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATH_H
