LIBS += -lv4l2 -lv4lconvert
HEADERS += src/mainwindow.h \
    src/capturethread.h \
    src/videowidget.h
SOURCES += src/mainwindow.cpp \
    src/main.cpp \
    src/capturethread.cpp \
    src/videowidget.cpp


DESTDIR = debug
OBJECTS_DIR = debug/.obj
MOC_DIR = debug/.moc
RCC_DIR = debug/.rcc
UI_DIR = debug/.ui
