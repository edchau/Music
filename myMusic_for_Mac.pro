
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myMusic
TEMPLATE = app


SOURCES += main.cpp\
            mainwindow.cpp \
            musicengine.cpp \
    playlist.cpp \
    library.cpp

HEADERS  += mainwindow.h \
    musicengine.h \
    playlist.h \
    library.h

FORMS    += mainwindow.ui \
    musicengine.ui \
    playlist.ui \
    library.ui


#VIRGIL WINDOWS
#=========================================================
#INCLUDEPATH += "irrKlang-1.6.0\\include"
#DEPENDPATH += "irrKlang-1.6.0\\lib\\Win32-gcc"

#LIBS +=  -L"irrKlang-1.6.0\\lib\\Win32-gcc" -lirrklang
#==========================================================

#MAC EDWARD and WESLEYmyMusic_for_Mac_with_irrklang
#=================================================================

INCLUDEPATH += "irrKlang-64bit-1.6.0/include"
DEPENDPATH += "irrKlang-64bit-1.6.0/bin/macosx-gcc"

LIBS +=  -L"irrKlang-64bit-1.6.0/bin/macosx-gcc" -lirrklang


#=================================================================
mac {
  Resources.files += "irrKlang-64bit-1.6.0/bin/macosx-gcc/libirrklang.dylib"
  Resources.files += "irrKlang-64bit-1.6.0/bin/macosx-gcc/ikpFLAC.dylib"
  Resources.files += "irrKlang-64bit-1.6.0/bin/macosx-gcc/ikpMP3.dylib"
# you can put more of these as you need, and it can even copy folders
# Resources.files += what you need
  Resources.path = Contents/MacOS
  QMAKE_BUNDLE_DATA += Resources
}
