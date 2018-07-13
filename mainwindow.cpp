#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    engine(new musicEngine(this))
{

    ui->setupUi(this);
    engine->setBalance(0);
    engine->setVolume(50);
    setupUI();
    setDeviceList();
    setupSignalsSlots();
    lastSong = 0;
    //engine->setWhatToPlay("/Users/Edward/Dropbox/final/myMusic_for_Mac_with_irrklang/music/Hawaii Five 0.mp3");
    //engine->play();
    //engine->pause();
    setupLibrary();
    ui->pause->setVisible(false);
    ui->play->setVisible(true);
    /*timer = new QTimer(this);
    timer->setTimerType(Qt::TimerType::CoarseTimer);
    timer->start(500);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateLists()));*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupLibrary() {
    ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    vector<string> arr;
    QDir finder;
    QString name;
    QString list;
    finder.cdUp();
    finder.cdUp();
    finder.cdUp();
    name = finder.path();
    list = finder.path();
    name.append("/playlist/Library.playlist");
    //cout<<name.toStdString()<<endl;
    currentList = name;
    list.append("/playlist");
    in.open(currentList.toStdString());

    QTableWidgetItem *item;
    item = new QTableWidgetItem(name);
    ui->table->setColumnCount(5);

    ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);
    string temp;
    int count = 0;
    while(getline(in,temp)) {
        arr.push_back(temp);
        //cout<<"temp: "<<temp<<endl;
        count++;
    }
    if(count<10)
        ui->table->setRowCount(10);
    else
        ui->table->setRowCount(count);
    for(int i = 0; i<count; i++) {
        item = new QTableWidgetItem(QString::fromStdString(arr.at(i)));
        ui->table->setItem(i,0,item);
    }

    QDir played;
    played.setCurrent(list);
    uint j = played.count();
    //cout<<j<<endl;
    for(int k = 0; k<j; k++) {
        string file;
        file = played[k].toStdString();
        if(file.find(".playlist") != string::npos) {
            //cout<<index<<endl;
            int index = file.find(".playlist");
            QString res;
            res = QString::fromStdString(file.substr(0, index));
            ui->playlist_finder->addItem(res);
        }
    }
    //ui->playlist_finder->
    in.close();
}

void MainWindow::setupUI()
{
    ui->volume->setValue(engine->getVolume());
    QRect rec = QApplication::desktop()->screenGeometry();
    this->show();
    this->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    //this->setGeometry(rec.width()/2-400,rec.height()/2-300,800,600);
}

void MainWindow::setupSignalsSlots()
{
    connect(ui->deviceList,SIGNAL(currentIndexChanged(int)),engine,SLOT(setDevice(int)));
    connect(ui->volume,SIGNAL(valueChanged(int)),engine,SLOT(setVolume(int)));
    //connect(ui->balance,SIGNAL(valueChanged(int)),engine,SLOT(setBalance(int)));

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(endProgram()));
    connect(engine,SIGNAL(songData(size_t,size_t)),this,SLOT(musicPlaying(size_t,size_t)));

    connect(ui->play,SIGNAL(clicked(bool)), this, SLOT(play()));
    connect(ui->pause,SIGNAL(clicked(bool)), this, SLOT(pause()));
    connect(ui->next,SIGNAL(clicked(bool)), this, SLOT(next()));
    connect(ui->prev,SIGNAL(clicked(bool)), this, SLOT(prev()));
    connect(engine,SIGNAL(currPositionInSong(float)), this, SLOT(slide(float)));
    connect(ui->time_slider,SIGNAL(sliderReleased()), this, SLOT(sliderChanged()));
    connect(ui->loop_button,SIGNAL(clicked(bool)), this, SLOT(looped()));
    connect(ui->shuffle_button, SIGNAL(clicked(bool)), this, SLOT(shuffle()));
    connect(ui->addMusicButton, SIGNAL(clicked(bool)), this, SLOT(openMusicFile()));
    connect(ui->table,SIGNAL(cellDoubleClicked(int,int)), this, SLOT(doubled(int, int)));
    //connect(ui->playlist_finder, SIGNAL(activated(int)), this, SLOT(updateLists()));

    connect(ui->create_playlist, SIGNAL(clicked(bool)), this, SLOT(playlist_editor()));
    connect(ui->playlist_finder, SIGNAL(currentIndexChanged(int)), this, SLOT(playlist_select()));
    connect(engine, SIGNAL(songFinished()), this, SLOT(reseter()));
}


void MainWindow::setDeviceList()
{
    QStringList list = engine->getDevices();
    for(int i = 0; i < list.size(); ++i)
        ui->deviceList->addItem(list[i]);
}

void MainWindow::endProgram()
{
    this->close();
}

void MainWindow::musicPlaying(size_t volume, size_t time)
{
    ui->volume->setValue(volume);
    qDebug()<<"Volume: "<<volume<<" Time: "<<time<<endl;
}

void MainWindow::doubled(int row, int col) {
    ui->table->setCurrentCell(row, 0);
    play();
    //engine->setWhatToPlay();
}

void MainWindow::slide(float time) {
    //cout<<"slided"<<endl;
    int min, secs;
    min = time/60000;
    secs = ((int)time/1000)%60;
    QString timer;
    timer = QString::number(min);
    if(secs<10)
        timer.append(":0");
    else
        timer.append(":");
    timer.append(QString::number(secs));
    ui->currentTime_label->setText(timer);
    ui->time_slider->setMaximum((int)engine->getMusic()->getPlayLength());
    ui->time_slider->setValue((int)time);
    if(engine->getMusic()->isFinished()) {
        ui->currentTime_label->setText("0:00");
        ui->totalTime_label->setText("/ 0:00");
    }
}

int MainWindow::shuffleValue() {
    int total = ui->table->rowCount();
    srand(time(NULL));
    int next = rand() % total;
    while(next == lastSong) {
        next = rand() % total;
    }
    //cout<<next<<endl;
    lastSong = next;
    return next;
}

void MainWindow::shuffle() {
    //ui->shuffle_button->setCheckable(true);
    if(shuffling) {
        ui->shuffle_button->setText("Shuffle: off");
        shuffling = false;
    } else {
        ui->shuffle_button->setText("Shuffle: on");
        shuffling = true;
    }
}

void MainWindow::looped() {
    //ui->loop_button->setCheckable(true);
    if(loop) {
        ui->loop_button->setText("Loop: off");
        loop = false;
    } else {
        ui->loop_button->setText("Loop: on");
        loop = true;
    }
}

void MainWindow::sliderChanged() {
    //cout<<engine->getMusic()->getPlayPosition()<<endl;
    //cout<<ui->time_slider->value()<<endl;
    engine->getMusic()->setPlayPosition(ui->time_slider->value());
    //cout<<"got clicked"<<endl;
}

void MainWindow::play() {
    if(ui->table->currentItem() != nullptr) {

        //cout<<"inside play"<<endl;
        QDir finder;
        QString song;
        finder.cdUp();
        song = finder.path();
        song.append("/music/");
        QString toPlay = ui->table->currentItem()->text();
        song.append(toPlay);
        song.append(".mp3");
        //cout<<"song: "<<song.toStdString()<<endl;
        //cout<<"engine: "<<engine->getMusic()->getIsPaused()<<endl;
        //cout<<"engine: "<<!engine->getMusic()->getIsPaused()<<endl;

        if(sameSong.compare(song) != 0) {
            //cout<<"inside if"<<endl;
            engine->setWhatToPlay(song.toStdString());
            engine->play();
        } else {
            engine->unpause();
        }
        //cout<<toPlay.toStdString();
        //engine->play();
        ui->play->setVisible(false);
        ui->pause->setVisible(true);
        sameSong = song;
        float time = engine->getMusic()->getPlayLength();
        int min, secs;
        min = time/60000;
        secs = ((int)time/1000)%60;
        QString timer;
        timer.append("/ ");
        timer.append(QString::number(min));
        if(secs<10)
            timer.append(":0");
        else
            timer.append(":");
        timer.append(QString::number(secs));
        ui->totalTime_label->setText(timer);
    }
}

void MainWindow::pause() {
    engine->pause();
    ui->pause->setVisible(false);
    ui->play->setVisible(true);
}

void MainWindow::next() {
    QModelIndex next;
    if(shuffling) {
        int index = shuffleValue();
        //cout<<"shuffled: "<<index<<endl;
        next = ui->table->model()->index(index, 0);
        ui->table->setCurrentIndex(next);
    } else {
        if(loop) {
            int index = ui->table->currentRow();
            next = ui->table->model()->index(index + 1, 0);
            //cout<<"loop: "<<index<<endl;
            if(index >= songCount-1) {
                next = ui->table->model()->index(0,0);
                cout<<"loop if: "<<index<<endl;
            }
        } else {
            int index = ui->table->currentRow();
            next = ui->table->model()->index(index + 1, 0);
            //cout<<"else: "<<index<<endl;
            if(index >= songCount-1) {
                next = ui->table->model()->index(songCount - 1,0);
            }
        }
        ui->table->setCurrentIndex(next);
    }
    //ui->table->setCurrentIndex(next);
    //cout<<ui->table->currentRow()<<": "<<songCount<<endl;

    this->play();
    ui->play->setVisible(false);
    ui->pause->setVisible(true);
}

void MainWindow::prev() {
    QModelIndex prev;
    if(engine->getMusic()->getPlayPosition() > 5000) {
        QDir finder;
        QString song;
        finder.cdUp();
        song = finder.path();
        song.append("/music/");
        QString toPlay = ui->table->currentItem()->text();
        song.append(toPlay);
        song.append(".mp3");
        engine->setWhatToPlay(song.toStdString());
        engine->play();
    } else {
        if(loop) {
            int index = ui->table->currentRow();
            prev = ui->table->model()->index(index - 1, 0);
            if(index == 0) {
                prev = ui->table->model()->index(songCount-1, 0);
            }
        } else {
            int index = ui->table->currentRow();
            prev = ui->table->model()->index(index - 1, 0);
            if(index == 0) {
                prev = ui->table->model()->index(0, 0);
            }
        }

        ui->table->setCurrentIndex(prev);

        //cout<<ui->table->currentRow()<<": "<<songCount<<endl;
        this->play();
    }
    ui->play->setVisible(false);
    ui->pause->setVisible(true);
}


void MainWindow::playlist_editor() {
    playlist list;
    list.setModal(true);
    list.exec();
}

void MainWindow::playlist_select() {
    QString name;
    QString beg;
    name = ui->playlist_finder->currentText();
    QDir finder;
    finder.cdUp();

    beg = finder.path();
    beg.append("/playlist/");
    beg.append(name);
    beg.append(".playlist");
    currentList=beg;
    this->setTable();
    //cout<<"playlist select: "<<beg.toStdString()<<endl;
}

void MainWindow::setTable() {
    ui->table->clear();
    int count = 0;
    QFile input(currentList);
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
    ui->table->setRowCount(0);
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
            count++;
            int row = ui->table->rowCount();
            ui->table->insertRow(row);
            ui->table->setItem(row,0, new QTableWidgetItem(items["name"]));
            QDir finder;
            QString song;
            finder.cdUp();
            song = finder.path();
            song.append("/music/");
            QString toPlay = items["name"];
            song.append(toPlay);
            song.append(".mp3");
            cout<<"song: "<<song.toStdString()<<endl;
            engine->setWhatToPlay(song.toStdString());
            engine->play();
            float time = engine->getMusic()->getPlayLength();
            int min, secs;
            min = time/60000;
            secs = ((int)time/1000)%60;
            QString timer;
            timer = QString::number(min);
            if(secs<10)
                timer.append(":0");
            else
                timer.append(":");
            timer.append(QString::number(secs));
            engine->pause();
            ui->table->setItem(row,1, new QTableWidgetItem(timer));
            ui->table->setItem(row,2, new QTableWidgetItem(items["artist"]));
            ui->table->setItem(row,3, new QTableWidgetItem(items["album"]));
            ui->table->setItem(row,4, new QTableWidgetItem(items["genre"]));
            //ui->table->setItem(row,5, new QTableWidgetItem(items["file"]));

            //updatePlayListItems(items["name"],items["time"], items["artist"], items["album"],items["genre"],items["file"]);
        }
    }
    songCount = count;
    input.close();
}

void MainWindow::reseter() {
    ui->currentTime_label->setText("0:00");
    ui->totalTime_label->setText(("0:00"));
}

void MainWindow::openMusicFile() {
    lib.setModal(true);
    lib.exec();
}

void MainWindow::updateLists() {
    ui->playlist_finder->clear();
    QDir finder;
    QString list;
    finder.cdUp();
    list = finder.path();
    cout<<list.toStdString()<<endl;
    list.append("/playlist");

    QDir played;
    played.setCurrent(list);
    uint j = played.count();
    //cout<<j<<endl;
    for(int k = 0; k<j; k++) {
        string file;
        file = played[k].toStdString();
        if(file.find(".playlist") != string::npos) {
            //cout<<index<<endl;
            int index = file.find(".playlist");
            QString res;
            res = QString::fromStdString(file.substr(0, index));
            ui->playlist_finder->addItem(res);
        }
    }
}

