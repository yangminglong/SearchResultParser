#ifndef ISEARCHRESULTPARSER_H
#define ISEARCHRESULTPARSER_H
#include <QObject>
#include <functional>

class ISearchResultParser : public QObject
{
    Q_OBJECT
public:
    enum ResultType {
        ResultNormal = 0x01,
        ResultAdvert = 0x10,
        ResultAll    = ResultNormal|ResultAdvert
    };
    Q_DECLARE_FLAGS(ResultTypes, ResultType)
    Q_FLAG(ResultTypes)

    enum SearchDeviceType {
        SearchPc    ,
        SearchPhone ,
    };
    Q_ENUM(SearchType)

    struct ResultRecordInfo
    {
        ResultRecordInfo() {}

        ResultType type;
        QString title;
        QString url;
    };
public:
    ISearchResultParser(QObject *parent=Q_NULLPTR) : QObject(parent) { }

    virtual ~ISearchResultParser() {}

    virtual QString name() = 0;

    virtual SearchDeviceType searchType() = 0;

    virtual void getResultsAsyn(const QString& keyword, int totalRecordNum, ResultTypes flags = ResultAll) = 0;

signals:
    void searchReply(const ResultRecordInfo& result);
};

Q_DECLARE_OPERATORS_FOR_FLAGS(ISearchResultParser::ResultTypes)
Q_DECLARE_METATYPE(ISearchResultParser::ResultRecordInfo)

#define ISearchResultParser_iid "org.qt-project.Qt.yangminglong.ISearchResultParser"
Q_DECLARE_INTERFACE(ISearchResultParser, ISearchResultParser_iid)

#endif // ISEARCHRESULTPARSER_H
