TEMPLATE = app
TARGET = videowidget

QT += multimedia multimediawidgets

HEADERS = \
    videoplayer.h

SOURCES = \
    main.cpp \
    videoplayer.cpp

RESOURCES += video_resource.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/multimedia/videowidget
INSTALLS += target

QT+=widgets
