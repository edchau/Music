#include "library.h"

library::library(QWidget *parent) :
    QDialog(parent),
    in(new Ui::library)
{
    in->setupUi(this);
    reset();
    QDir finder;
    QString beg;
    finder.cdUp();
    finder.cdUp();
    finder.cdUp();
    beg = finder.path();
    fileName.append(beg);
    fileName.append("/playlist/library.playlist");
    qDebug() << "path: " << fileName;
    in->playlistItems->setColumnCount(4);
    connectSignalsAndSlots();
    songData <<"name"<<"artist"<<"album"<<"genre";
}

library::~library()
{
    delete in;
}

void library::connectSignalsAndSlots()
{
    connect(in->cancelButton,SIGNAL(clicked(bool)),this,SLOT(cancel()));
    connect(in->okButton,SIGNAL(clicked(bool)),this,SLOT(entryDone()));
    connect(in->selectFile,SIGNAL(clicked(bool)),this,SLOT(updateFileLabel()));
}

void library::cancel(){
    reset();
    close();
}

QString library::getName()
{
    return in->name->text();
}

/*
QString library::getTime()
{
    return in->time->text();
}*/

QString library::getArtist()
{
    return in->artist->text();
}

QString library::getAlbum()
{
    return in->album->text();
}

QString library::getGenre()
{
    return in->genre->text();
}

QString library::getFile()
{
    return in->file->text();
}

void library::reset()
{
    in->file->setText("File Name");
    in->name->clear();
    //in->time->clear();
    in->artist->clear();
    in->album->clear();
    in->genre->clear();
}

void library::updateFileLabel()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Music File", QString(), "*.mp3");
    if(fileName.isNull())
        return;
    in->file->setText(fileName);
    setNameFile(fileName);
}

void library::entryDone()
{
    openPlaylist();
    updatePlayListItems(getName(), getArtist(), getAlbum(), getGenre());
    QXmlStreamWriter writer;
    QFile out(fileName);
    out.open(QFile::WriteOnly);
    writer.setDevice(&out);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("playlist");
    qDebug() << "Table" << in->playlistItems->rowCount();
    qDebug() << "Data" << songData.size();
    for(int i = 0; i < in->playlistItems->rowCount(); ++i)
    {
        writer.writeStartElement("song");
        for(int j = 0; j < songData.size(); ++j){
            qDebug() << in->playlistItems->item(i,j)->text();
            writer.writeTextElement(songData[j],in->playlistItems->item(i,j)->text());
        }
        writer.writeEndElement();
    }
    writer.writeEndElement();
    writer.writeEndDocument();
    out.close();
    qDebug() << "COMPLETE";
    reset();
    close();
}

void library::openPlaylist()
{
    QFile input(fileName);
    qDebug() <<" fileName: "<<fileName;
    QXmlStreamReader reader;
    QMap<QString, QString> items;
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
    in->playlistItems->setRowCount(0);
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
            updatePlayListItems(items["name"], items["artist"], items["album"],items["genre"]);
        }
    }
    input.close();
}


void library::updatePlayListItems(const QString &name, const QString &artist,
                                  const QString &album, const QString &genre)
{
    int row = in->playlistItems->rowCount();
    in->playlistItems->insertRow(row);
    in->playlistItems->setItem(row,0, new QTableWidgetItem(name));
    //in->playlistItems->setItem(row,2, new QTableWidgetItem(time));
    in->playlistItems->setItem(row,1, new QTableWidgetItem(artist));
    in->playlistItems->setItem(row,2, new QTableWidgetItem(album));
    in->playlistItems->setItem(row,3, new QTableWidgetItem(genre));
    //in->playlistItems->setItem(row,5, new QTableWidgetItem(file));
}

void library::setNameFile(const QString fileNames)
{
   in->name->setText(sanitizeFileName(fileNames));
}

QString library::sanitizeFileName(const QString& fileNames)
{
    QString cleanStr = fileNames;
    int pos = fileNames.indexOf("music/") + 6;
    int pos2 = fileNames.indexOf(".mp3");
    if(pos2 == -1)
        return cleanStr.mid(pos);
    else
        return cleanStr.mid(pos,(pos2 - pos));
}
