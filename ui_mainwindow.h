/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *play;
    QComboBox *playlist_finder;
    QPushButton *create_playlist;
    QPushButton *next;
    QPushButton *prev;
    QSlider *time_slider;
    QSlider *volume;
    QLabel *volume_label;
    QLabel *currentTime_label;
    QLabel *totalTime_label;
    QComboBox *deviceList;
    QLabel *deviceListLabel;
    QTableWidget *table;
    QPushButton *pause;
    QPushButton *addMusicButton;
    QPushButton *shuffle_button;
    QPushButton *loop_button;
    QMenuBar *menuBar;
    QMenu *menuMusic_Player;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(648, 484);
        MainWindow->setMouseTracking(true);
        MainWindow->setFocusPolicy(Qt::ClickFocus);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::ForceTabbedDocks|QMainWindow::GroupedDragging|QMainWindow::VerticalTabs);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(530, 380, 81, 31));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);
        play = new QPushButton(centralWidget);
        play->setObjectName(QStringLiteral("play"));
        play->setGeometry(QRect(210, 360, 61, 51));
        playlist_finder = new QComboBox(centralWidget);
        playlist_finder->setObjectName(QStringLiteral("playlist_finder"));
        playlist_finder->setGeometry(QRect(463, 10, 151, 26));
        create_playlist = new QPushButton(centralWidget);
        create_playlist->setObjectName(QStringLiteral("create_playlist"));
        create_playlist->setGeometry(QRect(480, 40, 121, 32));
        next = new QPushButton(centralWidget);
        next->setObjectName(QStringLiteral("next"));
        next->setGeometry(QRect(280, 360, 61, 51));
        prev = new QPushButton(centralWidget);
        prev->setObjectName(QStringLiteral("prev"));
        prev->setGeometry(QRect(140, 360, 61, 51));
        time_slider = new QSlider(centralWidget);
        time_slider->setObjectName(QStringLiteral("time_slider"));
        time_slider->setGeometry(QRect(90, 310, 311, 22));
        time_slider->setOrientation(Qt::Horizontal);
        volume = new QSlider(centralWidget);
        volume->setObjectName(QStringLiteral("volume"));
        volume->setGeometry(QRect(530, 210, 20, 91));
        volume->setOrientation(Qt::Vertical);
        volume_label = new QLabel(centralWidget);
        volume_label->setObjectName(QStringLiteral("volume_label"));
        volume_label->setGeometry(QRect(520, 180, 60, 16));
        currentTime_label = new QLabel(centralWidget);
        currentTime_label->setObjectName(QStringLiteral("currentTime_label"));
        currentTime_label->setGeometry(QRect(210, 330, 51, 21));
        totalTime_label = new QLabel(centralWidget);
        totalTime_label->setObjectName(QStringLiteral("totalTime_label"));
        totalTime_label->setGeometry(QRect(240, 330, 41, 20));
        deviceList = new QComboBox(centralWidget);
        deviceList->setObjectName(QStringLiteral("deviceList"));
        deviceList->setGeometry(QRect(490, 300, 111, 21));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deviceList->sizePolicy().hasHeightForWidth());
        deviceList->setSizePolicy(sizePolicy);
        deviceList->setFocusPolicy(Qt::ClickFocus);
        deviceList->setEditable(true);
        deviceListLabel = new QLabel(centralWidget);
        deviceListLabel->setObjectName(QStringLiteral("deviceListLabel"));
        deviceListLabel->setGeometry(QRect(510, 330, 71, 16));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(deviceListLabel->sizePolicy().hasHeightForWidth());
        deviceListLabel->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        deviceListLabel->setFont(font1);
        deviceListLabel->setAlignment(Qt::AlignCenter);
        table = new QTableWidget(centralWidget);
        if (table->columnCount() < 5)
            table->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        table->setObjectName(QStringLiteral("table"));
        table->setGeometry(QRect(40, 10, 411, 291));
        table->setColumnCount(5);
        pause = new QPushButton(centralWidget);
        pause->setObjectName(QStringLiteral("pause"));
        pause->setEnabled(true);
        pause->setGeometry(QRect(210, 360, 61, 51));
        addMusicButton = new QPushButton(centralWidget);
        addMusicButton->setObjectName(QStringLiteral("addMusicButton"));
        addMusicButton->setGeometry(QRect(472, 80, 151, 32));
        shuffle_button = new QPushButton(centralWidget);
        shuffle_button->setObjectName(QStringLiteral("shuffle_button"));
        shuffle_button->setGeometry(QRect(0, 310, 91, 32));
        loop_button = new QPushButton(centralWidget);
        loop_button->setObjectName(QStringLiteral("loop_button"));
        loop_button->setGeometry(QRect(400, 310, 91, 32));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 648, 22));
        menuMusic_Player = new QMenu(menuBar);
        menuMusic_Player->setObjectName(QStringLiteral("menuMusic_Player"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMusic_Player->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "myTunes", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
        play->setText(QApplication::translate("MainWindow", "Play", Q_NULLPTR));
        create_playlist->setText(QApplication::translate("MainWindow", "Playlist Options", Q_NULLPTR));
        next->setText(QApplication::translate("MainWindow", "Next", Q_NULLPTR));
        prev->setText(QApplication::translate("MainWindow", "Prev", Q_NULLPTR));
        volume_label->setText(QApplication::translate("MainWindow", "Volume", Q_NULLPTR));
        currentTime_label->setText(QApplication::translate("MainWindow", "Current", Q_NULLPTR));
        totalTime_label->setText(QApplication::translate("MainWindow", "/ 0:00", Q_NULLPTR));
        deviceListLabel->setText(QApplication::translate("MainWindow", "Device List", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Time", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Artist", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Album", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Genre", Q_NULLPTR));
        pause->setText(QApplication::translate("MainWindow", "Pause", Q_NULLPTR));
        addMusicButton->setText(QApplication::translate("MainWindow", "Add Music", Q_NULLPTR));
        shuffle_button->setText(QApplication::translate("MainWindow", "Shuffle", Q_NULLPTR));
        loop_button->setText(QApplication::translate("MainWindow", "Loop", Q_NULLPTR));
        menuMusic_Player->setTitle(QApplication::translate("MainWindow", "Music Player", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
