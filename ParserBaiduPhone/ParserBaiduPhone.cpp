#include "ParserBaiduPhone.h"

#include "httpManager.h"

#include <QNetworkReply>
#include <QUrlQuery>

ParserBaiduPhone::ParserBaiduPhone(QObject *parent)
    : ISearchResultParser(parent)
    , m_recordNum(10)
{
}

QString ParserBaiduPhone::name()
{
    return u8"百度搜索-Phone";
}

ISearchResultParser::SearchDeviceType ParserBaiduPhone::searchType()
{
    return SearchPhone;
}

void ParserBaiduPhone::getResultsAsyn(const QString &keyword, int totalRecordNum, ISearchResultParser::ResultTypes flags, int maxThreadNum)
{
    QString host = "https://m.baidu.com/s";
    int pages = floor(totalRecordNum/m_recordNum)+1;

    QUrl url(host);
    for (int i = 0; i < pages; i++)
    {
        QUrlQuery q;
        q.addQueryItem("ie", "utf8");
        q.addQueryItem("oe", "utf8");
        q.addQueryItem("wd", keyword);
        q.addQueryItem("rn", QString("%1").arg(m_recordNum));
        q.addQueryItem("ch", "3");
        q.addQueryItem("pn", QString("%1").arg(m_recordNum*i));
        // 设置参数
        url.setQuery(q);
        // 添加到容器
        m_requestUrls.append(url);
    }

    // 将创建的线程数
    int num = qMin(m_requestUrls.size(), maxThreadNum);

    for (int i = 0; i < num; i++) {
        transaction(flags);
    }
}

void ParserBaiduPhone::transaction(ResultTypes flags)
{
    if (m_requestUrls.size() == 0) {
        return;
    }

    m_mutex.lock();
    QUrl url = m_requestUrls.takeAt(0);
    m_mutex.unlock();

    HttpManager *manager = new HttpManager(this);
    manager->startRequest(url, HttpManager::Get, QByteArray(), [=](QByteArray* datas, QNetworkReply* reply){
        if (reply->error() == QNetworkReply::NoError) {
            // 解析结果
            parseResults(datas, flags);
            // 立即释放
            manager->deleteLater();
            // 继续执行
            transaction(flags);
        }
    });

}

void ParserBaiduPhone::parseResults(const QByteArray &datas, ISearchResultParser::ResultTypes flags)
{

}

