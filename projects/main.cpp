#include <QCoreApplication>
#include <cassert>
#include "i18n/classes/finder.h"
#include "i18n/classes/app.h"

void scanDir(QDir dir, QStringList const& filters = {{"*.h"}, {"*.cpp"}}) noexcept {
    dir.setNameFilters(filters);
    dir.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks);

    qDebug() << "Scanning: " << dir.path();

    auto const& fileList = dir.entryList();
    for (auto i = 0; i != fileList.count(); ++i)
        qDebug() << "Found file: " << fileList[i];

    dir.setFilter(QDir::AllDirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
    auto const& dirList = dir.entryList();
    for (auto i = 0; i != dirList.size(); ++i)  {
        auto const& newPath = QString("%1/%2").arg(dir.absolutePath(), dirList.at(i));
        scanDir(QDir(newPath));
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //scanDir(QDir("/home/dix/projects/irondoom/projects/1/"));
    scanDir(QDir("c:/projects/irondoom/projects/1/"));

    return 0;
}
