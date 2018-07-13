#ifndef LIBRARY_H
#define LIBRARY_H

#include <QDialog>
#include <QString>
#include <QStringList>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <QMap>
#include <QList>
#include <QWidget>
#include <QMessageBox>
#include <QFileDialog>
#include "ui_library.h"

namespace Ui {
class library;
}

class library : public QDialog
{
    Q_OBJECT

public:
    explicit library(QWidget *parent = 0);
    ~library();

    QString getName();
    QString getArtist();
    QString getAlbum();
    QString getGenre();
    QString getFile();
    void reset();
    QString sanitizeFileName(const QString& fileNames);
    void setNameFile(const QString fileNames);

private slots:
    void updateFileLabel();
    void entryDone();
    void cancel();

private:
    Ui::library *in;
    QStringList songData;
    //QMap<QString, QString> items;
    QString fileName;
    void connectSignalsAndSlots();
    void openPlaylist();
    void updatePlayListItems(const QString &name, const QString &artist,
                             const QString &album, const QString &genre);
};

#endif // LIBRARY_H
