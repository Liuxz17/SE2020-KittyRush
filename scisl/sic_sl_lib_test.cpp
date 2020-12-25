#include "sci_sl_lib_test.h"
#include "scicore/sci_folder.h"
#include "sci_sl_lib.h"

namespace scisl {
void sci_sl_lib_test::initTestCase(){

}

void sci_sl_lib_test::initTestCase_data(){
    QTest::addColumn<int>("number");
    QTest::addColumn<int>("result");
    QTest::addColumn<QString>("path");

    QTest::newRow("number0")  << 0 << 1 << QString("D:/testLibrary0.sclb");
    QTest::newRow("number10")  << 10 << 111 << QString("D:/testLibrary10.sclb");
    QTest::newRow("number20")  << 20 << 421 << QString("D:/testLibrary20.sclb");
}



void sci_sl_lib_test::save_test(){
    scicore::sci_library testLibrary;
    scicore::sci_folder testFolder("testFolder");

    testLibrary.set_root(&testFolder);

    QFETCH_GLOBAL(int, number);
    QFETCH_GLOBAL(int, result);
    QFETCH_GLOBAL(QString, path);

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

    sci_sl_lib testSl(path.toStdString(),&testLibrary);
    testSl.save();

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

void sci_sl_lib_test::save_test_data(){

}

void sci_sl_lib_test::load_test(){

    QFETCH_GLOBAL(int, number);
    QFETCH_GLOBAL(int, result);
    QFETCH_GLOBAL(QString, path);

    scicore::sci_library testLibrary;
    sci_sl_lib testSl(path.toStdString(),&testLibrary);
    testSl.load();
    QVERIFY(testLibrary.total_file(testLibrary.get_root())==result);
}

void sci_sl_lib_test::load_test_data(){

}

void sci_sl_lib_test::cleanupTestCase(){

}

}
