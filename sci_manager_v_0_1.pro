QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    main.cpp \
    mainwindow.cpp \
    sci_tools_tree.cpp \
    sci_ui_add_item_dialog.cpp \
    sci_ui_file.cpp \
    sci_ui_folder.cpp \
    sci_ui_folder_edit_widget.cpp \
    sci_ui_library_widget.cpp \
    sci_ui_open_library_dialog.cpp

HEADERS += \
    mainwindow.h \
    sci_tools_tree.h \
    sci_ui_add_item_dialog.h \
    sci_ui_file.h \
    sci_ui_folder.h \
    sci_ui_folder_edit_widget.h \
    sci_ui_library_widget.h \
    sci_ui_open_library_dialog.h

FORMS += \
    mainwindow.ui \
    sci_ui_add_item_dialog.ui \
    sci_ui_folder_edit_widget.ui \
    sci_ui_library_widget.ui \
    sci_ui_open_library_dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
