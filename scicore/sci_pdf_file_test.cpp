#include "sci_pdf_file_test.h"
#include "sci_folder.h"
#include "sci_pdf_file.h"
namespace scicore {
void sci_pdf_file_test::initTestCase()
{
    //init
}

void sci_pdf_file_test::add_file_test()
{
    scicore::sci_folder testFolder("test");
    scicore::sci_pdf_file testSon("testSon","D:",NULL);
    QVERIFY(testFolder.add_file(&testSon));
}

void sci_pdf_file_test::add_file_test_data()
{

}

void sci_pdf_file_test::get_path_test()
{
    std::string path = "D:";
    scicore::sci_pdf_file testFile("testFile",path,NULL);
    QVERIFY(path==testFile.get_path());
}

void sci_pdf_file_test::get_path_test_data()
{

}

void sci_pdf_file_test::set_path_test()
{
    std::string path = "C:";
    scicore::sci_pdf_file testFile("testFile","D:",NULL);
    testFile.set_path(path);
    QVERIFY(path==testFile.get_path());
}

void sci_pdf_file_test::set_path_test_data()
{

}

void sci_pdf_file_test::cleanupTestCase()
{
    //cleanup
}

}
