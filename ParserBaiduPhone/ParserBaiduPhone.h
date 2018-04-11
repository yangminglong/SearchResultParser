#ifndef PARSERBAIDUPHONE_H
#define PARSERBAIDUPHONE_H


#include "isearchresultparser.h"

class ParserBaiduPhone : public ISearchResultParser
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID ISearchResultParser_iid FILE "ParserBaiduPhone.json")
    Q_INTERFACES(ISearchResultParser)
public:
    ParserBaiduPhone(QObject *parent = 0);

public:
    virtual QString name();

    virtual SearchType searchType();

    virtual void getResultsAsyn(const QString& keyword, ResultTypes flags = ResultAll, std::function<void(QList<const SearchResult>&)> pFun = 0);
private:

};

#endif // PARSERBAIDUPHONE_H
