#include <QString>
#include <QObject>

#include <QtCore/QDebug>
#include <QtCore/QJsonDocument>
#include <QtCore/QCoreApplication>

#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>

class Response
{
    public:
        int status_code;
        QString url, data;
};

class GitHub
{
    public:
        QString download(QString url_)
        {
            return url_;
        }
    private:
        QString pass = "1488";
};
