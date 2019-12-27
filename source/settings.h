#ifndef SETTINGS_HELPER_H
#define SETTINGS_HELPER_H

#include <QKeySequence>
#include <QObject>
#include <QString>
#include <QTranslator>

#define ORGANIZATION_NAME "-"
#define ORGANIZATION_DOMAIN "ScreenShooter"
#define APPLICATION_NAME "Screenshooter"

class CSettingsHelper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString info READ info)
public:
    CSettingsHelper(QObject *parent = Q_NULLPTR);

    bool event(QEvent *ev);
    QString info();

    QKeySequence getHotkey();

signals:
    void setSettings();
    void replaseHotkey(const QKeySequence new_hotkey, const QKeySequence
        old_hotkey);
    void retranslateUi();

public slots:
    void setInfo(const QString &str);
    void saveSettings();
    void setAutorun();
    void unsetAutorun();
    void setLocaleId(const int &id);

private:
    void loadSettings();

    struct CSettingsInfo
    {
        int8_t autorun;
        int8_t locale;
        QString path;
        QString hotkey;
        QString getInfo();
    } settingsInfo;

    QTranslator translator;

    Q_DISABLE_COPY(CSettingsHelper)
};

#endif // SETTINGS_HELPER_H
