TEMPLATE      = app
CONFIG          += qt warn_on
HEADERS          = BrowserNode.h BrowserView.h BrowserSearchDialog.h \
        ControlWindow.h UserDialog.h
SOURCES          = main.cpp BrowserNode.cpp ControlWindow.cpp \
        BrowserView.cpp Pixmap.cpp BrowserSearchDialog.cpp \
        UserDialog.cpp myio.cpp 


TARGET          = projectControl
DEFINES          = BooL=bool FALSE=false TRUE=true TR=tr
INCLUDEPATH   = 
QT += network widgets
DESTDIR = ../../bin
