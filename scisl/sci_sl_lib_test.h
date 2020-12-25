#ifndef SCI_SL_LIB_TEST_H
#define SCI_SL_LIB_TEST_H
#include  <QtTest/QtTest>

namespace scisl {

class sci_sl_lib_test: public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void initTestCase_data();
    void save_test();
    void save_test_data();
    void load_test();
    void load_test_data();
    void cleanupTestCase();
};

#endif // SCI_SL_LIB_TEST_H

}
