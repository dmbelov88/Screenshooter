#include <memory>

#include "screen_shooter.h"

auto CScreenshooter::checkFilePath(auto path)
{
    auto initialPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    initialPath.append(std::move(path));
    QDir dir(initialPath);
    if (!dir.exists())
        qDebug() << dir.mkdir(std::move(initialPath));

    return initialPath;
}

CScreenshooter::CScreenshooter(QWidget *parent): QWidget(parent)
{
    filePath = checkFilePath(QString("/Screenshooter"));
    filePathMini = checkFilePath(QString("/Screenshooter/mini"));
}

void CScreenshooter::onActivated(QKeySequence sequence)
{
    Q_UNUSED(sequence)

    QtConcurrent::run([this]{

        auto screen = QGuiApplication::primaryScreen();
        auto window = windowHandle();
        if (window)
            screen = window->screen();
        if (!screen)
            return;

        auto screenshot = screen->grabWindow(0);

        auto screenshotMini = screenshot.scaled(QSize(64,64), Qt::KeepAspectRatio, Qt::SmoothTransformation);

        auto format = "png";
        auto currentDateTime = QDateTime::currentDateTime().toString("yyyy.mm.dd hh.mm.ss.zzz.");
        auto path  = filePath + ("/screen_")  + currentDateTime + format;
        auto path_mini = filePathMini + ("/screen_mini_")  + currentDateTime + format;

        qDebug() << path;
        if (!screenshot.save(std::move(path))) {
            qDebug() << "no saved";
            // emit warning(1);
            //                QMessageBox::warning(this, tr("Save Error"), tr("The image could not be saved to \"%1\".")
            //                                     .arg(QDir::toNativeSeparators(filePath)));
        }

        qDebug() << path_mini;
        if (!screenshotMini.save(std::move(path_mini))) {
            qDebug() << "no saved";
            // emit(2);
            //                QMessageBox::warning(this, tr("Save Error"), tr("The image could not be saved to \"%1\".")
            //                                     .arg(QDir::toNativeSeparators(filePathMini)));
        }

    });
}
