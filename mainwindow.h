#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QApplication>
#include <QDesktopWidget>
#include <QMainWindow>
#include <QRect>
#include <QStringList>
#include "musicengine.h"
#include "playlist.h"
#include <fstream>
#include <QDir>
#include <QString>
#include <iostream>
#include <time.h>
#include <library.h>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    public slots:
        void endProgram();
        void musicPlaying(size_t volume, size_t time);
        void play();
        void pause();
        void next();
        void prev();
        void slide(float time);
        void sliderChanged();
        void playlist_editor();
        void playlist_select();
        void reseter();
        void looped();
        void shuffle();
        void openMusicFile();
        void doubled(int row, int col);
        void updateLists();

    private:
        QString sameSong;
        int lastSong;
        int songCount;
        bool loop = false;
        Ui::MainWindow *ui;
        musicEngine *engine;
        QString currentList;
        ifstream in;
        bool shuffling=false;
        vector<string> vec;
        library lib;
        QTimer *timer;


        void setupSignalsSlots();
        void setupUI();
        void setDeviceList();
        void setupLibrary();
        void setTable();
        int shuffleValue();


};

#endif // MAINWINDOW_H
