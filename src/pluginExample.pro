TEMPLATE = lib

QT -= gui
QT += core network

CONFIG += warn_on release shared

VERSION = 2.1.0
INCLUDEPATH += ./include/simpleini
INCLUDEPATH += ./include/udp
INCLUDEPATH += ./include/XPLM

DEFINES += XPLM200 XPLM210

win32{
    TARGET = plugin/win.xpl
    DEFINES += APL=0 IBM=1 LIN=0 WIN_32=1
    QMAKE_CXXFLAGS += -std=c++11

    QMAKE_LIBDIR += $$PWD\lib
    LIBS += -g -Llib -static -static-libgcc -static-libstdc++ -lsetupapi -lXPLM_64 -lXPWidgets_64
}

unix:!macx { 
    TARGET = plugin/lin.xpl
    DEFINES += APL=0 IBM=0 LIN=1
    QMAKE_CXXFLAGS += -std=gnu++11 -O1
    LIBS += ../lib/XPLM.lib 
    LIBS += -lrt
}

macx { 
    TARGET = plugin/mac.xpl
    DEFINES += APL=1 IBM=0 LIN=0
    QMAKE_LFLAGS += -flat_namespace -undefined suppress
    
    # Build for multiple architectures.
    # The following line is only needed to build universal on PPC architectures.
    # QMAKE_MAC_SDK=/Developer/SDKs/MacOSX10.4u.sdk
    # This line defines for which architectures we build.
    CONFIG += x86 ppc
}

HEADERS += \
    owneddata.h # Class for manage custom datarefs

SOURCES += \
    main.cpp \
    owneddata.cpp

