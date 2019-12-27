#include <QApplication>
#include <QTest>

#include "settings_unittest.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTest::qExec(new Settings_Test, argc, argv);
    return 0;
}

#include "build-debug/moc_settings_unittests.cpp"
