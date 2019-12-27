#include <QApplication>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQuickStyle>
#include <QQuickWindow>

#include <memory>

#include "global_hotkeys_impl.h"
#include "screen_shooter.h"
#include "settings.h"
#include "nativeeventfilter.h"

int main(int argc, char *argv[])
{
  QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
  QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
  QCoreApplication::setApplicationName(APPLICATION_NAME);

  qApp->setWindowIcon(QIcon("qrc:/icon/app.ico"));

  CSettingsHelper settings;
  QApplication app(argc, argv);
  auto screenShooter = std::make_shared<CScreenshooter>(Q_NULLPTR);
  auto globalHotheys = std::make_shared<CGlobalHotkeysImpl>(Q_NULLPTR);
  globalHotheys->setHotkey(settings.getHotkey());
  globalHotheys->sync();
  qApp->postEvent(&settings, new QEvent(QEvent::None));

  QObject::connect(&settings, &CSettingsHelper::replaseHotkey,
      globalHotheys.get(), &CGlobalHotkeysImpl::onReplaceHotkey);
  QObject::connect(globalHotheys.get(), &CGlobalHotkeysImpl::activated,
      screenShooter.get(), &CScreenshooter::onActivated);

  QQuickStyle::setStyle("Material");

  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("CSettingsHelper", &settings);
  engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

  return app.exec();
}
