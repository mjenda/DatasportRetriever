#pragma once

#include <vector>
#include <string>
#include <htmlcxx/html/ParserDom.h>

class DatasportParser
{
public:
    std::pair<std::vector<std::string>, std::vector<std::vector<std::string>>> parse(const std::string & rawHtml);


private:
    std::vector<std::vector<std::string>> getData(const std::string & rawHtml, int numberOfColumns);
    std::vector<std::string> getColumns(const std::string & rawHtml);

    htmlcxx::HTML::ParserDom parser;
};

