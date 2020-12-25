#ifndef SCI_LIBRARY_TEST_H
#define SCI_LIBRARY_TEST_H
#include <QtTest/QtTest>

namespace scicore {
class sci_library_test: public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void set_root_test();
    void set_root_test_data();
    void get_root_test();
    void get_root_test_data();
    void total_file_test();     //树有一层
    void total_file_test_data();
    void total_file_test2();    //树有二层
    void total_file_test2_data();
    void cleanupTestCase();
};



#endif // SCI_LIBRARY_TEST_H
}
