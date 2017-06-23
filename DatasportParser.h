#pragma once

#include "DatasportData.hpp"

#include <htmlcxx/html/ParserDom.h>

class DatasportParser
{
public:
    DatasportData parse(const std::string & rawHtml);


private:
    Rows getData(const std::string & rawHtml, int numberOfColumns);
    Headers getColumns(const std::string & rawHtml);

    htmlcxx::HTML::ParserDom parser;
};

