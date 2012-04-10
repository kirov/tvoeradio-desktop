#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtSingleApplication>
#include <QDesktopServices>
#include <QDir>
#include <QIcon>
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkDiskCache>
#include <QNetworkProxy>
#include <QNetworkReply>
#include <QSettings>
#include "bridge.h"
#include "defines.h"
#include "networkcookiejar.h"

class Application : public QtSingleApplication
{
    Q_OBJECT

public:
    Application(int & argc, char ** argv);
    ~Application();

    QNetworkAccessManager *networkAccessManager;
    Bridge *bridge;

    QMainWindow *mainWindow;

#ifdef Q_WS_MAC
    void setupMacHandlers();
#endif

signals:

public slots:
    void on_sslError(QNetworkReply *reply, const QList<QSslError> &errors);
};


#endif // APPLICATION_H
