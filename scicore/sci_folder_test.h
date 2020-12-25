#ifndef TRIANGLETEST_H
#define TRIANGLETEST_H
#include <QtTest/QtTest>
namespace scicore {
//测试类
class sci_folder_test: public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void add_file_test();
    void add_file_test_data();
    void insert_file_test();
    void insert_file_test_data();
    void remove_file_test();
    void remove_file_test_data();
    void match_child_test();
    void match_child_test_data();
    void child_count_test();
    void child_count_test_data();
    void get_child_test();
    void get_child_test_data();
    void replace_file_test();
    void replace_file_test_data();
    void cleanupTestCase();
};

#endif // TRIANGLETEST_H
}
