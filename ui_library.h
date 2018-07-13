/********************************************************************************
** Form generated from reading UI file 'library.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARY_H
#define UI_LIBRARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_library
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *okButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *artistLabel;
    QPushButton *selectFile;
    QLineEdit *artist;
    QLabel *nameLabel;
    QLineEdit *album;
    QLabel *file;
    QLabel *genreLabel;
    QLineEdit *name;
    QLineEdit *genre;
    QLabel *albumLabel;
    QTableWidget *playlistItems;

    void setupUi(QDialog *library)
    {
        if (library->objectName().isEmpty())
            library->setObjectName(QStringLiteral("library"));
        library->resize(475, 450);
        horizontalLayoutWidget = new QWidget(library);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(210, 340, 228, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cancelButton = new QPushButton(horizontalLayoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        okButton = new QPushButton(horizontalLayoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);

        gridLayoutWidget = new QWidget(library);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 30, 391, 291));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        artistLabel = new QLabel(gridLayoutWidget);
        artistLabel->setObjectName(QStringLiteral("artistLabel"));

        gridLayout->addWidget(artistLabel, 2, 1, 1, 1);

        selectFile = new QPushButton(gridLayoutWidget);
        selectFile->setObjectName(QStringLiteral("selectFile"));

        gridLayout->addWidget(selectFile, 0, 3, 1, 1);

        artist = new QLineEdit(gridLayoutWidget);
        artist->setObjectName(QStringLiteral("artist"));

        gridLayout->addWidget(artist, 2, 2, 1, 1);

        nameLabel = new QLabel(gridLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout->addWidget(nameLabel, 1, 1, 1, 1);

        album = new QLineEdit(gridLayoutWidget);
        album->setObjectName(QStringLiteral("album"));

        gridLayout->addWidget(album, 3, 2, 1, 1);

        file = new QLabel(gridLayoutWidget);
        file->setObjectName(QStringLiteral("file"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(file->sizePolicy().hasHeightForWidth());
        file->setSizePolicy(sizePolicy);

        gridLayout->addWidget(file, 0, 1, 1, 2);

        genreLabel = new QLabel(gridLayoutWidget);
        genreLabel->setObjectName(QStringLiteral("genreLabel"));

        gridLayout->addWidget(genreLabel, 4, 1, 1, 1);

        name = new QLineEdit(gridLayoutWidget);
        name->setObjectName(QStringLiteral("name"));

        gridLayout->addWidget(name, 1, 2, 1, 1);

        genre = new QLineEdit(gridLayoutWidget);
        genre->setObjectName(QStringLiteral("genre"));

        gridLayout->addWidget(genre, 4, 2, 1, 1);

        albumLabel = new QLabel(gridLayoutWidget);
        albumLabel->setObjectName(QStringLiteral("albumLabel"));

        gridLayout->addWidget(albumLabel, 3, 1, 1, 1);

        playlistItems = new QTableWidget(library);
        playlistItems->setObjectName(QStringLiteral("playlistItems"));
        playlistItems->setGeometry(QRect(540, 400, 20, 20));

        retranslateUi(library);

        QMetaObject::connectSlotsByName(library);
    } // setupUi

    void retranslateUi(QDialog *library)
    {
        library->setWindowTitle(QApplication::translate("library", "Dialog", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("library", "Cancel", Q_NULLPTR));
        okButton->setText(QApplication::translate("library", "Ok", Q_NULLPTR));
        artistLabel->setText(QApplication::translate("library", "Artist", Q_NULLPTR));
        selectFile->setText(QApplication::translate("library", "Select File", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("library", "Name", Q_NULLPTR));
        file->setText(QApplication::translate("library", "File Name", Q_NULLPTR));
        genreLabel->setText(QApplication::translate("library", "Genre", Q_NULLPTR));
        albumLabel->setText(QApplication::translate("library", "Album", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class library: public Ui_library {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARY_H
