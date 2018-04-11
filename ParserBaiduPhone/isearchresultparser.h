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

    enum SearchType {
        SearchPc    ,
        SearchPhone ,
    };
    Q_ENUM(SearchType)

    struct SearchResult
    {
        SearchResult() {}
        ResultType type;
        QString title;
        QString url;
    };
public:
    ISearchResultParser(QObject *parent=Q_NULLPTR) : QObject(parent) { }

    virtual ~ISearchResultParser() {}

    virtual QString name() = 0;

    virtual SearchType searchType() = 0;

    virtual void getResultsAsyn(const QString& keyword, ResultTypes flags = ResultAll, std::function<void(QList<const SearchResult>&)> pFun = 0) = 0;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(ISearchResultParser::ResultTypes)
Q_DECLARE_METATYPE(ISearchResultParser::SearchResult)

#define ISearchResultParser_iid "org.qt-project.Qt.yangminglong.ISearchResultParser"
Q_DECLARE_INTERFACE(ISearchResultParser, ISearchResultParser_iid)

#endif // ISEARCHRESULTPARSER_H
