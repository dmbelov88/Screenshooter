#include "global_hotkeys.h"

#include <QApplication>
#include <QDebug>

CGlobalHotkeys::~CGlobalHotkeys()
{
  reset();
}

void CGlobalHotkeys::replaceHotkey(const QKeySequence &newSequence,
    const QKeySequence &oldSequence)
{
  unsetHotkey(oldSequence);
  setHotkey(newSequence);
}

void CGlobalHotkeys::reset()
{
  qApp->removeNativeEventFilter(this);
}

void CGlobalHotkeys::sync()
{
  qApp->installNativeEventFilter(this);
}
