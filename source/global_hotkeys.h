#ifndef GLOBAL_HOTKEYS_H
#define GLOBAL_HOTKEYS_H

#include <QObject>
#include <QAbstractNativeEventFilter>
#include <QByteArray>
#include <QHash>
#include <QKeySequence>
#include <QVector>

class CGlobalHotkeys: public QAbstractNativeEventFilter
{
public:
  virtual ~CGlobalHotkeys();
  virtual void setHotkey(const QKeySequence &sequence) = 0;
  virtual void unsetHotkey(const QKeySequence &sequence) = 0;

  void sync();
  void replaceHotkey(const QKeySequence &newSequence,
      const QKeySequence &oldSequence);

protected:
  virtual unsigned int stringToModificator(const QString &sequence) = 0;
  virtual unsigned int getHotkey(const QKeySequence &sequence) = 0;
  virtual void unsetHotkeys() = 0;

  void reset();

  QVector<QKeySequence> Hotkeys;
};

#endif // GLOBAL_HOTKEYS_H
