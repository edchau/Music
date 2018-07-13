#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QDialog>
#include <QString>
#include "musicengine.h"

namespace Ui {
class playlist;
}

class playlist : public QDialog
{
    Q_OBJECT

public:
    explicit playlist(QWidget *parent = 0);
    ~playlist();

signals:
    void closed();

public slots:
    void saveLibrary();
    void updatePlayList();
    void moveUp();
    void moveDown();
    void clearAllEntries();
    void deleteSong();


private:
    Ui::playlist *in;
    QString theCurrentList;
    QStringList listOfSongs, songData, listOfPlayLists ;
    QString path;
    irrklang::ISoundEngine* engine;


   void setupSignalsSlots();
   void loadPlayLists();
   void loadSelectedLibrary(const QString &name);
   void updatePlayListItems(const QString &songName,
                            const QString &artist, const QString &album, const QString &genre);
   void updateLibraryItems(const QString &songName,
                            const QString &artist, const QString &album, const QString &genre);

   void setupWindow();
   void loadAllSongs();
   void rewriteThePlayList();


};

#endif // PLAYLIST_H
