QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Adgust/addchannel.cpp \
    Adgust/adgustmag.cpp \
    Adgust/channelitem.cpp \
    Adgust/draftbtn.cpp \
    Adgust/eqitem.cpp \
    Gather/audiodata.cpp \
    Gather/calculatemag.cpp \
    Module/EQ.cpp \
    Module/algorithmDesign.cpp \
    Module/app.cpp \
    Module/pubchart.cpp \
    Module/qaesencryption.cpp \
    Module/qcustomplot.cpp \
    Module/range.cpp \
    Module/voicechart.cpp \
    Send/serialprot.cpp \
    helpdlg.cpp \
    main.cpp \
    mainwindow.cpp \
    smoothsetdlg.cpp

HEADERS += \
    Adgust/addchannel.h \
    Adgust/adgustmag.h \
    Adgust/channelitem.h \
    Adgust/draftbtn.h \
    Adgust/eqitem.h \
    Gather/audiodata.h \
    Gather/calculatemag.h \
    LodeQss.h \
    Module/EQ.h \
    Module/algorithmDesign.h \
    Module/app.h \
    Module/pubchart.h \
    Module/qaesencryption.h \
    Module/qcustomplot.h \
    Module/range.h \
    Module/voicechart.h \
    Send/serialprot.h \
    Send/threadwork.h \
    helpdlg.h \
    mainwindow.h \
    smoothsetdlg.h

FORMS += \
    Adgust/addchannel.ui \
    Adgust/adgustmag.ui \
    Adgust/channelitem.ui \
    Adgust/draftbtn.ui \
    Adgust/eqitem.ui \
    Gather/calculatemag.ui \
    Module/pubchart.ui \
    Module/range.ui \
    Module/voicechart.ui \
    Send/serialprot.ui \
    helpdlg.ui \
    mainwindow.ui \
    smoothsetdlg.ui

UI_DIR=./Ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_ICONS = vehicle.ico

RESOURCES += \
    res.qrc


win32: LIBS += -L$$PWD/./ -llibfftw3f-3

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
