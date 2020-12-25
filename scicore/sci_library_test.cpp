#include "sci_folder.h"
#include "sci_library.h"
#include "sci_library_test.h"

namespace scicore {
void sci_library_test::initTestCase()
{

}

void sci_library_test::set_root_test()
{
    scicore::sci_library testLibrary;
    scicore::sci_folder testFolder("testFolder");
    testLibrary.set_root(&testFolder);

}

void sci_library_test::set_root_test_data()
{

}

void sci_library_test::get_root_test()
{
    scicore::sci_library testLibrary;
    scicore::sci_folder testFolder("testFolder");
    testLibrary.set_root(&testFolder);
    QVERIFY(&testFolder == testLibrary.get_root());
}

void sci_library_test::get_root_test_data()
{

}

void sci_library_test::total_file_test()
{
    scicore::sci_library testLibrary;
    scicore::sci_folder testFolder("testFolder");
    testLibrary.set_root(&testFolder);

    QFETCH(int, number);
    QFETCH(int, result);

    for(int i = 0; i < number; i++)
    {
        testFolder.add_file(new scicore::sci_folder((QString("testSon")+i).toStdString()));
    }

    QVERIFY(testLibrary.total_file(testLibrary.get_root())==result);

    for(int i = number-1; i >= 0; i--)
    {
        delete testFolder.remove_file(i);
    }
}

void sci_library_test::total_file_test_data()
{
    QTest::addColumn<int>("number");
    QTest::addColumn<int>("result");

    QTest::newRow("number0")  << 0 << 1;
    QTest::newRow("number100")  << 100 << 101;
    QTest::newRow("number1000")  << 1000 << 1001;
}

void sci_library_test::total_file_test2()
{
    scicore::sci_library testLibrary;
    scicore::sci_folder testFolder("testFolder");
    testLibrary.set_root(&testFolder);

    QFETCH(int, number);
    QFETCH(int, result);

    scicore::sci_folder *testSon;
    for(int i = 0; i < number; i++)
    {
        testSon = new scicore::sci_folder((QString("testSon")+i).toStdString());
        testFolder.add_file(testSon);
        for(int j = 0; j < number; j++)
        {
        testSon->add_file(new scicore::sci_folder((QString("testSon")+i+j).toStdString()));
        }
    }

    QVERIFY(testLibrary.total_file(testLibrary.get_root())==result);

    scicore::sci_file *testSon2;
    for(int i = number-1; i >= 0; i--)
    {
        testSon2 = testFolder.get_child(i);
        for (int j = number-1; j >= 0; j--)
        {
            delete testSon2->remove_file(i);
        }
        delete testFolder.remove_file(i);

    }
}

void sci_library_test::total_file_test2_data()
{
    QTest::addColumn<int>("number");
    QTest::addColumn<int>("result");

    QTest::newRow("number0")  << 0 << 1;
    QTest::newRow("number10")  << 10 << 111;
}



void sci_library_test::cleanupTestCase()
{

}
}
