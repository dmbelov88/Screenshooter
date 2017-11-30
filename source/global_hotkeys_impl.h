#ifndef GLOBAL_HOTKEYS_IMPL_H
#define GLOBAL_HOTKEYS_IMPL_H

#include <QObject>
#include <QAbstractNativeEventFilter>
#include <QByteArray>
#include <QHash>
#include <QKeySequence>
#include <QVector>

#include "global_hotkeys.h"

class CGlobalHotkeysImpl: public QObject, public CGlobalHotkeys
{
  Q_OBJECT
public:
  explicit CGlobalHotkeysImpl(QObject *parent = Q_NULLPTR);

  bool nativeEventFilter(const QByteArray &eventType, void *message,
      long *result);
  void setHotkey(const QKeySequence &sequence) override;
  void unsetHotkey(const QKeySequence &sequence) override;

signals:
  void activated(QKeySequence sequence);

public slots:
  void onReplaceHotkey(const QKeySequence &newKey,const QKeySequence &oldKey);

private:
  unsigned int stringToModificator(const QString &sequence) override;
  unsigned int getHotkey(const QKeySequence &sequence) override;
  void unsetHotkeys() override;
};

#endif // GLOBAL_HOTKEYS_IMPL_H
