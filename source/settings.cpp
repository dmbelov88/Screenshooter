#include "settings.h"

#include <QCoreApplication>
#include <QDebug>
#include <QSettings>

CSettingsHelper::CSettingsHelper(QObject *parent) : QObject(parent)
{
  loadSettings();
}

bool CSettingsHelper::event(QEvent *ev)
{
  Q_UNUSED(ev);

  if (settingsInfo.locale == -1)
  {
    QString locale =  QLocale::system().uiLanguages().at(0).split("-").at(0);
    if (locale != "en")
    {
    translator.load(QString("Language_") + locale , "../translations");
    qApp->installTranslator(&translator);
    }
    else
      settingsInfo.locale = 0;
  }

  emit setSettings();
  return true;
}

QString CSettingsHelper::info()
{
  return settingsInfo.getInfo();
}

void CSettingsHelper::setInfo(const QString &str)
{
  QStringList list = str.split("|");

  emit replaseHotkey(QKeySequence::fromString(list[3]),
      QKeySequence::fromString(settingsInfo.hotkey));

  settingsInfo.autorun = list[0].toInt();
  settingsInfo.locale = list[1].toInt();
  settingsInfo.path = list[2];
  settingsInfo.hotkey = list[3];
}

QKeySequence CSettingsHelper::getHotkey()
{
  return QKeySequence::fromString(settingsInfo.hotkey);
}

void CSettingsHelper::saveSettings()
{
  QSettings settings(QCoreApplication::organizationName(),
                     QCoreApplication::applicationName());
  settings.setValue("General/autorun", settingsInfo.autorun);
  settings.setValue("General/locale", settingsInfo.locale);
  settings.setValue("General/path", settingsInfo.path);
  settings.setValue("General/shortcut", settingsInfo.hotkey);
  settings.sync();
}

void CSettingsHelper::loadSettings()
{
  QSettings settings(QCoreApplication::organizationName(),
                     QCoreApplication::applicationName());
  settingsInfo.autorun = settings.value("General/autorun", 0).toInt();
  settingsInfo.locale = settings.value("General/locale", -1).toInt();
  settingsInfo.path = settings.value("General/path","Screenshooter").toString();
  settingsInfo.hotkey = settings.value("General/shortcut", "Ctrl+S").toString();
}

void CSettingsHelper::setAutorun()
{
#ifdef Q_OS_WIN32
  QSettings settings("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\
                     CurrentVersion\\Run", QSettings::NativeFormat);
                     settings.setValue(APPLICATION_NAME, QDir::toNativeSeparators(
                                         QCoreApplication::applicationFilePath()));
      settings.sync();
#endif
}

void CSettingsHelper::unsetAutorun()
{
#ifdef Q_OS_WIN32
  QSettings settings("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\
                     CurrentVersion\\Run", QSettings::NativeFormat);
                     settings.remove(APPLICATION_NAME);
    #endif
}

void CSettingsHelper::setLocaleId(const int &id)
{
  if (id == 1)
  {
    translator.load(QString("Language_ru"), "../translations");
    qApp->installTranslator(&translator);
  }
  else
    qApp->removeTranslator(&translator);

  emit retranslateUi();
}

QString CSettingsHelper::CSettingsInfo::getInfo()
{
  QString info;
  info.append(QString::number(autorun) + "|" + QString::number(locale) + "|" +
              path + "|" + hotkey);
  return info;
}
