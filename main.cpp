#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QIcon>
#include "mainwindow.h"

#include <QtGui/QFileOpenEvent>
#include <QLoggingCategory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLoggingCategory::setFilterRules(QStringLiteral("*.debug=false\n*.info=false"));
    a.setOrganizationName("SpotLite");
    a.setApplicationName("Spotlite Release 3.0");
    a.setApplicationDisplayName("Spotlite Release 3.0");
    QTranslator _qttrans;
    _qttrans.load("qt_nl.qm", /*QLibraryInfo::location(QLibraryInfo::TranslationsPath)*/ a.applicationDirPath() );
    QApplication::installTranslator(&_qttrans);
    const QIcon appIcon(QStringLiteral(":/icons/icon.ico"));
    QApplication::setWindowIcon(appIcon);
    MainWindow w;
    w.setWindowIcon(appIcon);
    w.show();

    QStringList args = a.arguments();
    if ( args.count() > 1)
    {
        foreach (QString arg, args)
        {
            w.openFile(arg);
        }
    }


    return a.exec();
}
