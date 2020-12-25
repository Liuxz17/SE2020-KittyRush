#include "sci_folder_test.h"
#include "sci_folder.h"
namespace scicore {
void sci_folder_test::initTestCase()
{
    //init
}

void sci_folder_test::add_file_test()
{
    scicore::sci_folder testFolder("test");
    scicore::sci_folder testSon("testSon");
    QVERIFY(testFolder.add_file(&testSon));
}

void sci_folder_test::add_file_test_data()
{
    //data
}

void sci_folder_test::insert_file_test()
{
    scicore::sci_folder testFolder("test");
    scicore::sci_folder testSon0("testSon0");
    testFolder.add_file(&testSon0);
    scicore::sci_folder testSon1("testSon1");
    testFolder.add_file(&testSon1);
    scicore::sci_folder testSon2("testSon2");

    QFETCH(int, index);
    QFETCH(bool, result);
    QVERIFY(testFolder.insert_file(&testSon2, index)==result);
}

void sci_folder_test::insert_file_test_data()
{

    QTest::addColumn<int>("index");
    QTest::addColumn<bool>("result");

    QTest::newRow("index0")  << 0 << true;
    QTest::newRow("index1")  << 1 << true;
    QTest::newRow("index3_none")  << 3 << false;
}

void sci_folder_test::remove_file_test()
{
    scicore::sci_folder testFolder("test");
    scicore::sci_folder testSon0("testSon0");
    testFolder.add_file(&testSon0);
    scicore::sci_folder testSon1("testSon1");
    testFolder.add_file(&testSon1);

    QFETCH(int, index);
    QFETCH(bool, result);
    QVERIFY((testFolder.remove_file(index)!=NULL)==result);
}

void sci_folder_test::remove_file_test_data()
{
    QTest::addColumn<int>("index");
    QTest::addColumn<bool>("result");

    QTest::newRow("index0")  << 0 << true;
    QTest::newRow("index1")  << 1 << true;
    QTest::newRow("index2_none")  << 2 << false;
}

void sci_folder_test::match_child_test()
{
    scicore::sci_folder testFolder("test");
    scicore::sci_folder testSon0("testSon0");
    testFolder.add_file(&testSon0);
    scicore::sci_folder testSon1("testSon1");
    testFolder.add_file(&testSon1);
    scicore::sci_folder testSon2("testSon2");

    scicore::sci_folder *list[3];
    list[0] = &testSon0;
    list[1] = &testSon1;
    list[2] = &testSon2;

    QFETCH(int, index);
    QFETCH(int, result);
    QVERIFY(testFolder.match_child(list[index])==result);
}

void sci_folder_test::match_child_test_data()
{
    QTest::addColumn<int>("index");
    QTest::addColumn<int>("result");

    QTest::newRow("index0")  << 0 << 0;
    QTest::newRow("index1")  << 1 << 1;
    QTest::newRow("index2_none")  << 2 << -1;

}

void sci_folder_test::child_count_test()
{
    scicore::sci_folder testFolder("test");

    QFETCH(int, number);
    QFETCH(int, result);

    for(int i = 0; i < number; i++)
    {
        testFolder.add_file(new scicore::sci_folder((QString("testSon")+i).toStdString()));
    }

    QVERIFY(testFolder.child_count()==result);

    for(int i = number-1; i >= 0; i--)
    {
        delete testFolder.remove_file(i);
    }
}
void sci_folder_test::child_count_test_data()
{
    QTest::addColumn<int>("number");
    QTest::addColumn<int>("result");

    QTest::newRow("number0")  << 0 << 0;
    QTest::newRow("number100")  << 100 << 100;
    QTest::newRow("number1000")  << 1000 << 1000;
}

void sci_folder_test::get_child_test()
{
    scicore::sci_folder testFolder("test");
    scicore::sci_folder testSon0("testSon0");
    testFolder.add_file(&testSon0);
    scicore::sci_folder testSon1("testSon1");
    testFolder.add_file(&testSon1);

    scicore::sci_folder *list[3];
    list[0] = &testSon0;
    list[1] = &testSon1;
    list[2] = NULL;

    QFETCH(int, index);

    QVERIFY(testFolder.get_child(index)==list[index]);


}

void sci_folder_test::get_child_test_data()
{
    QTest::addColumn<int>("index");

    QTest::newRow("index0")  << 0;
    QTest::newRow("index1")  << 1;
    QTest::newRow("index2_none")  << 2;
}

void sci_folder_test::replace_file_test()
{
    scicore::sci_folder testFolder("test");
    scicore::sci_folder testSon0("testSon0");
    testFolder.add_file(&testSon0);
    scicore::sci_folder testSon1("testSon1");
    testFolder.add_file(&testSon1);
    scicore::sci_folder testSon2("testSon2");
    testFolder.add_file(&testSon2);

    QFETCH(int, from);
    QFETCH(int, to);
    QFETCH(bool, result);

    QVERIFY(testFolder.replace_file(from,to)==result);
}

void sci_folder_test::replace_file_test_data()
{
    QTest::addColumn<int>("from");
    QTest::addColumn<int>("to");
    QTest::addColumn<bool>("result");

    QTest::newRow("0to1")  << 0 << 1 << true;
    QTest::newRow("1to2")  << 1 << 2 << true;
    QTest::newRow("0to3_none")  << 0 << 3 << false;
    QTest::newRow("3to0_none")  << 3 << 0 << false;
}

void sci_folder_test::cleanupTestCase()
{
    //cleanup
}

}
