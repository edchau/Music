#include "playlist.h"
#include "ui_playlist.h"
#include "QListWidgetItem"
#include <iostream>
#include <QDropEvent>
#include <string>
#include <QString>
#include <QDir>
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QDebug>
#include <QStandardItem>



playlist::playlist(QWidget *parent) :
    QDialog(parent),
    in(new Ui::playlist)
{
    in->setupUi(this);
    setupSignalsSlots();     //order is important, it loads then changes homeDir
    setupWindow();
    loadPlayLists();
    loadAllSongs();

}

playlist::~playlist()
{
    delete in;
}

//  ///////// Here the path need to be changed if used on mac (Ed, Wes) ////////////////////////////////////////

void playlist::setupWindow()
{
    QDir finder;                  // uncomment all this for mac to work
    QString beg;                  // and comment out qstring path
    finder.cdUp();

    beg = finder.path();
    QString fileName;
    fileName.append(beg);
    fileName.append("/playlist");
    path = fileName;
    qDebug() << "SETUP" << fileName;
    //    QString path = "C:\\Users\\panfi\\Dropbox\\CS 003A (Spring_2018 Wilkinson)\\final\\myMusic_for_Mac_with_irrklang\\playlist";
    //QDir::setCurrent(path);
    cout<<"playlist: "<<fileName.toStdString()<<endl;
    songData <<"name"<<"artist"<<"album"<<"genre";
    in->playListScr->setRowCount(0);
    in->library->setRowCount(0);
    in->playListScr->verticalHeader()->setStretchLastSection(false);
    in->library->verticalHeader()->setStretchLastSection(false);
    in->library->setSelectionMode(QAbstractItemView::SingleSelection);
    in->library->setDragEnabled(true);
    in->library->setDropIndicatorShown(true);
    in->library->setDragDropMode(QAbstractItemView::InternalMove);
    in->library->setSelectionBehavior(in->library->SelectRows);

}
void playlist::setupSignalsSlots()
{
    connect(in->cancelButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    //connect(in->library,SIGNAL(doubleClicked(QListWidgetItem*)),this,SLOT(addToTheList(QListWidgetItem*)));
    connect(in->saveButton, SIGNAL(clicked(bool)), this, SLOT(saveLibrary()));
    connect(in->comboBox,SIGNAL(currentIndexChanged(QString)), this, SLOT(updatePlayList()));
    connect(in->upButton, SIGNAL(clicked(bool)), this, SLOT(moveUp()));
    connect(in->downButton, SIGNAL(clicked(bool)), this, SLOT(moveDown()));
    connect(in->clearAllButton, SIGNAL(clicked(bool)), this, SLOT(clearAllEntries()));
    connect(in->deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteSong()));

}

//  ///////// Here the path need to be changed if used on mac (Ed, Wes) ////////////////////////////////////////

void playlist::loadPlayLists()
{
    QString emptyStr;
    QDir pathList(path);
    listOfPlayLists.clear();
    in->comboBox->clear();
    listOfPlayLists =  pathList.entryList(QDir::Files);
    listOfPlayLists.push_front(emptyStr);                      // add an empty guy
    listOfPlayLists.removeAt(listOfPlayLists.indexOf("library.playlist"));
    in->comboBox->addItems(listOfPlayLists);
}

void playlist::updatePlayList()
{
    QString selectedFile = in->comboBox->currentText();
    loadSelectedLibrary(selectedFile);
}

void playlist::loadSelectedLibrary(const QString& name)
{

    QFile input(name);
    QXmlStreamReader reader;
    QMap<QString, QString> items;
    if(name.isEmpty())
        return;
    if(!input.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("File Input Error");
        msgBox.setText("File cannot be read.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        qDebug() << "Cannot read file" << input.errorString();
        return;
    }
    reader.setDevice(&input);
    if(name == "library.playlist")
        in->library->setRowCount(0);
    else
        in->playListScr->setRowCount(0);
    while(!reader.atEnd())
    {
        reader.readNextStartElement();
        if(reader.name() == "song")
        {
            do
            {
                reader.readNext() ;
                if(reader.tokenType() == QXmlStreamReader::EndElement)
                    break;
                items[reader.name().toString()] = reader.readElementText();
            }while(true);
            if(!(name == "library.playlist"))
                updatePlayListItems(items["name"], items["artist"], items["album"], items["genre"]);
            else
                updateLibraryItems(items["name"], items["artist"], items["album"], items["genre"]);
        }
    }
    input.close();

}

void playlist::updatePlayListItems(const QString &songName,
                                   const QString &artist, const QString &album,
                                   const QString &genre)
{
    int row = in->playListScr->rowCount();
    in->playListScr->insertRow(row);
    in->playListScr->setItem(row,0, new QTableWidgetItem(songName));
    //in->playListScr->setItem(row,1, new QTableWidgetItem(time));
    in->playListScr->setItem(row, 1, new QTableWidgetItem(artist));
    in->playListScr->setItem(row,2, new QTableWidgetItem(album));
    in->playListScr->setItem(row,3, new QTableWidgetItem(genre));
}
void playlist::saveLibrary()
{
    QString fileName = in->textEdit->text();
    if(fileName.isEmpty())
        fileName = in->comboBox->currentText();
    QXmlStreamWriter writer;
    if (QFileInfo(fileName).suffix().isEmpty())
      fileName.append(".playlist");
    QFile out(fileName);
    out.open(QFile::WriteOnly);
    writer.setDevice(&out);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("playlist");
    for(int i = 0; i < in->playListScr->rowCount(); ++i)
    {
        writer.writeStartElement("song");
        for(int j = 0; j < songData.size(); ++j)
            writer.writeTextElement(songData[j],in->playListScr->item(i,j)->text());
        writer.writeEndElement();
    }
    writer.writeEndElement();
    writer.writeEndDocument();
    out.close();
    in->textEdit->clear();
    in->playListScr->setRowCount(0);
    this->close();
    loadPlayLists();
}

void playlist::loadAllSongs()
{
    loadSelectedLibrary("library.playlist");
}

void playlist::updateLibraryItems(const QString &songName,
                                  const QString &artist, const QString &album,
                                  const QString &genre)
{
    int row = in->library->rowCount();
    in->library->insertRow(row);
    in->library->setItem(row,0, new QTableWidgetItem(songName));
    //in->library->setItem(row,1, new QTableWidgetItem(time));
    in->library->setItem(row,1, new QTableWidgetItem(artist));
    in->library->setItem(row,2, new QTableWidgetItem(album));
    in->library->setItem(row,3, new QTableWidgetItem(genre));

}

void playlist::moveUp()
{
    int currentRow = in->playListScr->currentIndex().row();
    if(in->playListScr->currentIndex().row()<=0)
        return;
    QList<QTableWidgetItem*> movedRow,destination;
    for(size_t i = 0; i < in->playListScr->columnCount(); ++i)
    {
        movedRow << in->playListScr->takeItem(currentRow,i);
        destination<< in->playListScr->takeItem(currentRow-1,i);
    }
    for(size_t j = 0; j < in->playListScr->columnCount(); ++j)
        for(size_t k = 0; k < destination.size(); ++k)
        {
            in->playListScr->setItem(currentRow,j,destination.at(j));
            in->playListScr->setItem(currentRow-1,j,movedRow.at(j));
        }
    in->playListScr->selectRow(currentRow-1);
}

void playlist::moveDown()
{
    int currentRow = in->playListScr->currentIndex().row();
    if(in->playListScr->rowCount() - 1 <= currentRow)
        return;
    QList<QTableWidgetItem*> movedRow,destination;
    for(size_t i = 0; i < in->playListScr->columnCount(); ++i)
    {
        movedRow << in->playListScr->takeItem(currentRow,i);
        destination<< in->playListScr->takeItem(currentRow+1,i);
    }
    for(size_t j = 0; j < in->playListScr->columnCount(); ++j)
        for(size_t k = 0; k < destination.size(); ++k)
        {
            in->playListScr->setItem(currentRow,j,destination.at(j));
            in->playListScr->setItem(currentRow+1,j,movedRow.at(j));
        }
    in->playListScr->selectRow(currentRow+1);
}

void playlist::clearAllEntries()
{
    in->playListScr->setRowCount(0);
}

void playlist::deleteSong()
{
    in->playListScr->removeRow(in->playListScr->currentRow());
    in->playListScr->selectRow(in->playListScr->currentRow());
}
