/********************************************************************************
** Form generated from reading UI file 'playlists.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLISTS_H
#define UI_PLAYLISTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_playlists
{
public:
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEdit;
    QPushButton *savePlaylist;
    QLabel *label_3;
    QComboBox *comboBox;
    QPushButton *pushButton;

    void setupUi(QWidget *playlists)
    {
        if (playlists->objectName().isEmpty())
            playlists->setObjectName(QStringLiteral("playlists"));
        playlists->resize(728, 433);
        listWidget = new QListWidget(playlists);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(30, 40, 221, 331));
        listWidget_2 = new QListWidget(playlists);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(280, 40, 221, 331));
        label = new QLabel(playlists);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 10, 60, 16));
        label_2 = new QLabel(playlists);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(370, 10, 60, 16));
        textEdit = new QTextEdit(playlists);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(510, 200, 211, 31));
        savePlaylist = new QPushButton(playlists);
        savePlaylist->setObjectName(QStringLiteral("savePlaylist"));
        savePlaylist->setGeometry(QRect(510, 250, 101, 32));
        label_3 = new QLabel(playlists);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(560, 120, 101, 16));
        comboBox = new QComboBox(playlists);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(510, 160, 211, 26));
        pushButton = new QPushButton(playlists);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(620, 250, 101, 32));

        retranslateUi(playlists);

        QMetaObject::connectSlotsByName(playlists);
    } // setupUi

    void retranslateUi(QWidget *playlists)
    {
        playlists->setWindowTitle(QApplication::translate("playlists", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("playlists", "Library", Q_NULLPTR));
        label_2->setText(QApplication::translate("playlists", "Playlist", Q_NULLPTR));
        savePlaylist->setText(QApplication::translate("playlists", "Save", Q_NULLPTR));
        label_3->setText(QApplication::translate("playlists", "Playlist Name", Q_NULLPTR));
        pushButton->setText(QApplication::translate("playlists", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class playlists: public Ui_playlists {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLISTS_H
