#include "ParserBaiduPhone.h"


ParserBaiduPhone::ParserBaiduPhone(QObject *parent)
    : ISearchResultParser(parent)
{
}

QString ParserBaiduPhone::name()
{
    return u8"百度搜索-Phone";
}

ISearchResultParser::SearchType ParserBaiduPhone::searchType()
{
    return SearchPhone;
}

void ParserBaiduPhone::getResultsAsyn(const QString &keyword, ISearchResultParser::ResultTypes flags, std::function<void (QList<const ISearchResultParser::SearchResult> &)> pFun)
{

}

