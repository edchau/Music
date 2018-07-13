/********************************************************************************
** Form generated from reading UI file 'playlist.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLIST_H
#define UI_PLAYLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_playlist
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QTableWidget *library;
    QTableWidget *playListScr;
    QPushButton *upButton;
    QPushButton *downButton;
    QPushButton *deleteButton;
    QPushButton *clearAllButton;
    QLineEdit *textEdit;

    void setupUi(QDialog *playlist)
    {
        if (playlist->objectName().isEmpty())
            playlist->setObjectName(QStringLiteral("playlist"));
        playlist->resize(624, 471);
        label = new QLabel(playlist);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 10, 60, 16));
        label_2 = new QLabel(playlist);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(330, 10, 60, 16));
        label_3 = new QLabel(playlist);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(510, 270, 60, 16));
        comboBox = new QComboBox(playlist);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(483, 300, 121, 26));
        saveButton = new QPushButton(playlist);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(460, 400, 81, 32));
        cancelButton = new QPushButton(playlist);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(540, 400, 81, 32));
        library = new QTableWidget(playlist);
        if (library->columnCount() < 4)
            library->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        library->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        library->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        library->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        library->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        library->setObjectName(QStringLiteral("library"));
        library->setGeometry(QRect(20, 40, 201, 361));
        library->setEditTriggers(QAbstractItemView::NoEditTriggers);
        library->setDragEnabled(true);
        library->setDragDropMode(QAbstractItemView::DragDrop);
        library->setDefaultDropAction(Qt::CopyAction);
        library->setAlternatingRowColors(true);
        library->setRowCount(0);
        library->setColumnCount(4);
        playListScr = new QTableWidget(playlist);
        if (playListScr->columnCount() < 4)
            playListScr->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        playListScr->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        playListScr->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        playListScr->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        playListScr->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        playListScr->setObjectName(QStringLiteral("playListScr"));
        playListScr->setGeometry(QRect(240, 40, 221, 361));
        playListScr->setEditTriggers(QAbstractItemView::NoEditTriggers);
        playListScr->setDragEnabled(true);
        playListScr->setDragDropMode(QAbstractItemView::DragDrop);
        playListScr->setAlternatingRowColors(true);
        playListScr->setSelectionMode(QAbstractItemView::ExtendedSelection);
        playListScr->setSelectionBehavior(QAbstractItemView::SelectRows);
        playListScr->setColumnCount(4);
        upButton = new QPushButton(playlist);
        upButton->setObjectName(QStringLiteral("upButton"));
        upButton->setGeometry(QRect(480, 70, 71, 32));
        downButton = new QPushButton(playlist);
        downButton->setObjectName(QStringLiteral("downButton"));
        downButton->setGeometry(QRect(540, 70, 71, 32));
        deleteButton = new QPushButton(playlist);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(480, 100, 131, 32));
        clearAllButton = new QPushButton(playlist);
        clearAllButton->setObjectName(QStringLiteral("clearAllButton"));
        clearAllButton->setGeometry(QRect(480, 130, 131, 32));
        textEdit = new QLineEdit(playlist);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(490, 350, 113, 21));

        retranslateUi(playlist);

        QMetaObject::connectSlotsByName(playlist);
    } // setupUi

    void retranslateUi(QDialog *playlist)
    {
        playlist->setWindowTitle(QApplication::translate("playlist", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("playlist", "Library", Q_NULLPTR));
        label_2->setText(QApplication::translate("playlist", "Playlist", Q_NULLPTR));
        label_3->setText(QApplication::translate("playlist", "Playlist", Q_NULLPTR));
        saveButton->setText(QApplication::translate("playlist", "Save", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("playlist", "Cancel", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = library->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("playlist", "Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = library->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("playlist", "Artist", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = library->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("playlist", "Album", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = library->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("playlist", "Genre", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = playListScr->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("playlist", "Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = playListScr->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("playlist", "Artist", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = playListScr->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("playlist", "Album", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = playListScr->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("playlist", "Genre", Q_NULLPTR));
        upButton->setText(QApplication::translate("playlist", "Up", Q_NULLPTR));
        downButton->setText(QApplication::translate("playlist", "Down", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("playlist", "Delete Song", Q_NULLPTR));
        clearAllButton->setText(QApplication::translate("playlist", "Clear All", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class playlist: public Ui_playlist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLIST_H
