#include "musicengine.h"
#include "ui_musicengine.h"

musicEngine::musicEngine(QWidget *parent) :
    QWidget(parent),
    balance(0),
    volume(50)
{
    deviceList = irrklang::createSoundDeviceList();
    int deviceCount = deviceList->getDeviceCount();
    qDebug()<<"Number of devices found: "<<deviceCount;
    for(int i = 0; i < deviceCount; ++i)
    {
        qDebug()<<deviceList->getDeviceDescription(i);
        //qDebug()<<deviceList->getDeviceDescription(i);
        listOfDevices.append(deviceList->getDeviceDescription(i));
        listOfDevices << deviceList->getDeviceDescription(i);
    }
    setDevice(0);
    setBalance(balance);
    setVolume(volume);
    system("pwd");
    qDebug()<<"Ended music engine constructor";
}



musicEngine::~musicEngine()
{
    deviceList->drop();
    if (music)
        music->drop(); // release music stream.

    engine->drop(); // delete engine
}

musicEngine::musicEngine(string whatToPlay)
{
    currentPlay = whatToPlay;
}

float musicEngine::getBalance()
{
    return balance;
}

float musicEngine::getVolume()
{
    return volume;
}

QStringList& musicEngine::getDevices()
{
    return listOfDevices;
}

void musicEngine::loop(bool yes)
{

}

void musicEngine::play()
{
    engine->stopAllSounds();
    music = engine->play2D((currentPlay).c_str(),false, false, true);
    //music->setVolume(volume);


    //engine->setAllSoundsPaused(false);
    //music = engine->play2D((currentPlay).c_str(),false, false, true);
    if(music)
    {
        qDebug()<<"Attempting to play music";
        music->setPan(balance);
        volume = music->getVolume();
        //cout<<volume<<endl;
        timer = new QTimer(this);
        timer->setTimerType(Qt::TimerType::CoarseTimer);
        timer->start(500);
        connect(timer,SIGNAL(timeout()),this,SLOT(onSoundStopped()));
        emit songData(music->getVolume()*100,music->getPlayLength());
    }
}

void musicEngine::unpause() {
    //engine->stopAllSounds();
    engine->setAllSoundsPaused(false);

    //engine->setAllSoundsPaused(false);
    //music = engine->play2D((currentPlay).c_str(),false, false, true);
    if(music)
    {
        qDebug()<<"Attempting to unpause music";
        music->setPan(balance);
        volume = music->getVolume();
        //cout<<volume<<endl;
        timer = new QTimer(this);
        timer->setTimerType(Qt::TimerType::CoarseTimer);
        timer->start(500);
        connect(timer,SIGNAL(timeout()),this,SLOT(onSoundStopped()));
        emit songData(music->getVolume()*100,music->getPlayLength());
    }
}


void musicEngine::onSoundStopped()
{
    emit currPositionInSong(music->getPlayPosition());
}

void musicEngine::setDevice(int deviceNumber)
{
    const char* deviceID = deviceList->getDeviceID(deviceNumber);
    if(engine)
        engine->drop();
    engine = createIrrKlangDevice();
    setBalance(0);

}

void musicEngine::pause()
{
    music->setIsPaused(true);
    /*
    if(music->getIsPaused()) {
        music->setIsPaused(true);
    } else {
        music->setIsPaused(true);
    }
    music->setIsPaused(music->getIsPaused() ? false : true);*/
}

void musicEngine::stop()
{
    music->stop();
    music->drop();
}

void musicEngine::fastForward()
{
   if(music)
   {
       float currPos = music->getPlayPosition()+5000;
       if(currPos >= music->getPlayLength())
            currPos = music->getPlayLength();
        music->setPlayPosition(currPos);
        emit currPositionInSong(music->getPlayPosition());
   }
}

void musicEngine::rewind()
{
    if(music)
    {
      float currPos = music->getPlayPosition() - 5000;
      if(currPos <= 0)
         currPos = 0;
      music->setPlayPosition(currPos);
      emit currPositionInSong(music->getPlayPosition());
    }
}

void musicEngine::restart()
{
    music->setPlayPosition(0);
    emit currPositionInSong(0);
}

void musicEngine::setVolume(int vol)
{
    volume = vol;
    if(music)
        music->setVolume(volume/100.);
}

void musicEngine::setPlayingOffset(float timeOffset)
{
    float millisecs = timeOffset/100. * music->getPlayLength();
    music->setPlayPosition(millisecs);
}

void musicEngine::setBalance(int pan)
{
    balance = -pan/50.0;
    if(music)
        music->setPan(balance);
}

void musicEngine::setWhatToPlay(string whatToPlay)
{
   currentPlay = whatToPlay;
}

void musicEngine::onTimeOut()
{
    if(music->isFinished())
    {
        delete timer;
        emit songFinished();
    }
}

irrklang::ISound* musicEngine::getMusic() {
    return music;
}

void musicEngine::posChanged(float time) {
    //music->g;
    emit currPositionInSong(time);
}
