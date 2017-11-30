#include <QtTest>

#include "settings.h"

class Test_Settings : public QObject
{
  Q_OBJECT
public:
  Test_Settings();

signals:
  void setInfo(const QString &str);

private slots:
  void test_organization();
  void test_info();
  void test_initHotkey();
//  void test_saveSettings();
//  void test_setAutorun();
//  void test_unsetAutorun();
//  void test_loadSettings();

private:
  CSettingsHelper settingsHelper;
};

Test_Settings::Test_Settings()
{
  QCoreApplication::setOrganizationName(QString(ORGANIZATION_NAME) + QString("_test"));
  QCoreApplication::setOrganizationDomain(QString(ORGANIZATION_DOMAIN) + QString("_test"));
  QCoreApplication::setApplicationName(QString(APPLICATION_NAME) + QString("_test"));
}

void Test_Settings::test_organization()
{
  QVERIFY(!QCoreApplication::organizationName().isEmpty());
  QVERIFY(!QCoreApplication::organizationDomain().isEmpty());
  QVERIFY(!QCoreApplication::applicationName().isEmpty());
}

void Test_Settings::test_info()
{
  QString str = settingsHelper.info();
  QStringList list = str.split("|");

  QCOMPARE(list.size(), 4);

  connect(this, &Test_Settings::setInfo, &settingsHelper, &CSettingsHelper::setInfo);
  QString info = "1|1|tmp|Ctrl+Shift+A";
  emit setInfo(info);

  str.clear(); list.clear();
  str = settingsHelper.info();
  list = str.split("|");
  QCOMPARE(list[0].toInt(), 1);
  QCOMPARE(list[1].toInt(), 1);
  QCOMPARE(list[2], QString("tmp"));
  QCOMPARE(list[3], QString("Ctrl+Shift+A"));
}

void Test_Settings::test_initHotkey()
{
  QKeySequence sequence = settingsHelper.getHotkey();
  QVERIFY(!sequence.isEmpty());
}

//void Test_Settings::test_saveSettings()
//{
//  settingsHelper.
//}
//void Test_Settings::test_setAutorun()
//{
//  settingsHelper.
//}
//void Test_Settings::test_unsetAutorun()
//{
//  settingsHelper.
//}
//void Test_Settings::test_loadSettings()
//{
//  settingsHelper.loadSettings();
//}

QTEST_MAIN(Test_Settings)

#include "test_settings.moc"
