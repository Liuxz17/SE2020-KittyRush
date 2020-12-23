QT       += core gui
QT       += core testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


INCLUDEPATH += $$PWD/poppler
LIBS += -L$$PWD/poppler -llibpoppler
LIBS += -L$$PWD/poppler -llibpoppler-qt5

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
    empty_detail_widget.cpp \
    library_sl_test.cpp \
    library_widget.cpp \
    main.cpp \
    scicore/sci_library.cpp \
    scicore/sci_file.cpp \
    scicore/sci_folder.cpp \
    scicore/sci_pdf_file.cpp \
    scicore/sci_pdf_paper.cpp \
    scigui/folder/sci_ui_add_item_dialog.cpp \
    scigui/folder/sci_ui_folder_edit_widget.cpp \
    scigui/lib_buffer/sci_ui_total_library_widget.cpp \
    scigui/new_library/sci_ui_open_library_dialog.cpp \
    scigui/pdf_paper/sci_pdf_canvas.cpp \
    scigui/pdf_paper/sci_pdf_detail_widget.cpp \
    scigui/pdf_paper/sci_pdf_load_thread.cpp \
    scigui/pdf_paper/sci_pdf_paper_widget.cpp \
    scigui/pdf_paper/sci_pdf_reader.cpp \
    scigui/pdf_paper/sci_pdf_utils.cpp \
    scigui/sci_file_model.cpp \
    scigui/sci_file_visitor_adaptor.cpp \
    scigui/sci_ui_file.cpp \
    scigui/sci_ui_file_tree_view.cpp \
    scigui/sci_ui_folder.cpp \
    scigui/sci_ui_lib_buffer.cpp \
    scigui/sci_ui_library_widget.cpp \
    scigui/sci_ui_local_search_result_dialog.cpp \
    scigui/sci_ui_local_search_widget.cpp \
    scigui/sci_ui_pdf_paper.cpp \
    scigui/sci_ui_display_tab_widget.cpp \
    scisl/sci_sl.cpp \
    scisl/sci_sl_file.cpp \
    scisl/sci_sl_file_visitor_adaptor.cpp \
    scisl/sci_sl_folder.cpp \
    scisl/sci_sl_lib.cpp \
    scisl/sci_sl_lib_buffer.cpp \
    scisl/sci_sl_pdf_paper.cpp

HEADERS += \
    empty_detail_widget.h \
    library_sl_test.h \
    library_widget.h \
    scicore/sci_file.h \
    scicore/sci_folder.h \
    scicore/sci_library.h \
    scicore/sci_pdf_file.h \
    scicore/sci_pdf_paper.h \
    scicore/sci_file_visitor.h \
    scigui/folder/sci_ui_add_item_dialog.h \
    scigui/folder/sci_ui_folder_edit_widget.h \
    scigui/lib_buffer/sci_ui_total_library_widget.h \
    scigui/new_library/sci_ui_open_library_dialog.h \
    scigui/pdf_paper/sci_pdf_canvas.h \
    scigui/pdf_paper/sci_pdf_detail_widget.h \
    scigui/pdf_paper/sci_pdf_load_thread.h \
    scigui/pdf_paper/sci_pdf_paper_widget.h \
    scigui/pdf_paper/sci_pdf_reader.h \
    scigui/pdf_paper/sci_pdf_utils.h \
    scigui/sci_file_model.h \
    scigui/sci_file_visitor_adaptor.h \
    scigui/sci_ui_file.h \
    scigui/sci_ui_file_tree_view.h \
    scigui/sci_ui_folder.h \
    scigui/sci_ui_lib_buffer.h \
    scigui/sci_ui_library_widget.h \
    scigui/sci_ui_local_search_result_dialog.h \
    scigui/sci_ui_local_search_widget.h \
    scigui/sci_ui_pdf_paper.h \
    scigui/sci_ui_display_tab_widget.h \
    scisl/sci_sl.h \
    scisl/sci_sl_file.h \
    scisl/sci_sl_file_visitor_adaptor.h \
    scisl/sci_sl_folder.h \
    scisl/sci_sl_lib.h \
    scisl/sci_sl_lib_buffer.h \
    scisl/sci_sl_pdf_paper.h

FORMS += \
    display_widget.ui \
    empty_detail_widget.ui \
    library_widget.ui \
    scigui/folder/sci_ui_add_item_dialog.ui \
    scigui/folder/sci_ui_folder_edit_widget.ui \
    scigui/lib_buffer/sci_ui_total_library_widget.ui \
    scigui/new_library/sci_ui_open_library_dialog.ui \
    scigui/pdf_paper/sci_pdf_paper_widget.ui \
    scigui/pdf_paper/sci_pdf_reader.ui \
    scigui/sci_ui_library_widget.ui \
    scigui/sci_ui_local_search_result_dialog.ui \
    scigui/sci_ui_local_search_widget.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    folder_icon.qrc
