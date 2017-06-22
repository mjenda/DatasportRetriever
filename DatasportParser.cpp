#include "DatasportParser.h"

#include <iostream>
#include <boost/algorithm/string.hpp>

DatasportData DatasportParser::parse(const std::string &rawHtml)
{
    auto columns = getColumns(rawHtml);

    for (auto column : columns)
    {
        std::cout << column << ";";
    }

    std::cout << std::endl;

    auto lines = getData(rawHtml, columns.size());

    for (auto line : lines)
    {
        for (auto entry : line)
        {
            std::cout << entry << ";";
        }
        std::cout << std::endl;
    }

    return {columns, lines};
}

Rows DatasportParser::getData(const std::string &rawHtml, int numberOfColumns)
{
    Rows rows {};
    std::vector<std::string> row {};

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
        row.push_back(data);
        columnNumber++;
        if (columnNumber == numberOfColumns)
        {
            columnNumber = 0;
            rows.push_back(row);
            row.clear();
        }
    }
    return rows;
}

Headers DatasportParser::getColumns(const std::string &rawHtml)
{
    Headers columns {};

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
