#ifndef SCI_PDF_FILE_TEST_H
#define SCI_PDF_FILE_TEST_H
#include <QtTest/QtTest>
namespace scicore {
class sci_pdf_file_test: public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void add_file_test();
    void add_file_test_data();
    void get_path_test();
    void get_path_test_data();
    void set_path_test();
    void set_path_test_data();
    void cleanupTestCase();
};

#endif // SCI_PDF_FILE_TEST_H
}
