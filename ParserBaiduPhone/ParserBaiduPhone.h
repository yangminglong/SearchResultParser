#ifndef PARSERBAIDUPHONE_H
#define PARSERBAIDUPHONE_H


#include "isearchresultparser.h"

#include <QMutex>

class HttpManager;

class ParserBaiduPhone : public ISearchResultParser
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID ISearchResultParser_iid FILE "ParserBaiduPhone.json")
    Q_INTERFACES(ISearchResultParser)
public:
    ParserBaiduPhone(QObject *parent = 0);

public:
    virtual QString name();

    virtual SearchDeviceType searchType();

    virtual void getResultsAsyn(const QString& keyword, int totalRecordNum, ResultTypes flags = ResultAll, int maxThreadNum = 10);
signals:

private slots:
    void transaction(ResultTypes flags);
    void parseResults(const QByteArray &datas, ResultTypes flags);
private:
    int m_recordNum; // 单页显示的搜索记录数

    QList<QUrl> m_requestUrls; // 待执行的
    QMutex m_mutex;
};

#endif // PARSERBAIDUPHONE_H
