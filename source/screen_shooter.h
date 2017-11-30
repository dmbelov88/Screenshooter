#ifndef SCREEN_SHOOTER_H
#define SCREEN_SHOOTER_H

#include <QScreen>
#include <QWindow>
#include <QPixmap>
#include <QStandardPaths>
#include <QMessageBox>
#include <QtConcurrent>
#include <QGuiApplication>
#include <QDir>
#include <QWidget>

#include "global_hotkeys.h"

class CScreenshooter: public QWidget
{
    Q_OBJECT
public:
    CScreenshooter(QWidget *parent = Q_NULLPTR);
    ~CScreenshooter() = default;

signals:
    void warning(uint id);

public slots:
    void onActivated(QKeySequence sequence);

private:
    auto checkFilePath(auto path);
    QString filePath, filePathMini;
};


#endif // SCREEN_SHOOTER_H
