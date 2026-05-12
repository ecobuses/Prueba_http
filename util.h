#ifndef UTIL_H
#define UTIL_H
#include<QString>
#include<QJsonArray>
#include<QJsonObject>
#include<QJsonDocument>
#include<QEventLoop>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include<QTimer>
class util
{
public:
    util();
    int static postHttp(QJsonArray &);
private:
    QString url="http://localhost:8080/magnitud";
};

#endif // UTIL_H
