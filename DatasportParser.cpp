#include "DatasportParser.h"

#include <iostream>
#include <boost/algorithm/string.hpp>

void DatasportParser::parse(const std::string &rawHtml)
{
    auto columns = getColumns(rawHtml);

    for (auto column : columns)
    {
        std::cout << column << " # ";
    }

    std::cout << std::endl;

    auto lines = getData(rawHtml, columns.size());

    for (auto line : lines)
    {
        for (auto entry : line)
        {
            std::cout << entry << " # ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<std::string> > DatasportParser::getData(const std::string &rawHtml, int numberOfColumns)
{
    std::vector<std::vector<std::string>> columns {};
    std::vector<std::string> line {};

    auto dom = parser.parseTree(rawHtml);

    int columnNumber = 0;
    for (auto it = dom.begin(); it != dom.end(); ++it)
    {
        if (it->tagName() != "td")
        {
            continue;
        }

        std::string data = std::next(it)->tagName();

        boost::trim(data);
        line.push_back(data);
        columnNumber++;
        if (columnNumber == numberOfColumns)
        {
            columnNumber = 0;
            columns.push_back(line);
            line.clear();
        }
    }
    std::cout << "DUPA" << std::endl;
    return columns;
}

std::vector<std::string> DatasportParser::getColumns(const std::string &rawHtml)
{
    std::vector<std::string> columns {};

    auto dom = parser.parseTree(rawHtml);

    for (auto it = dom.begin(); it != dom.end(); ++it)
    {
        if (it->tagName() == "th")
        {
            columns.push_back(std::next(it)->tagName());
        }
    }

    return columns;
}
