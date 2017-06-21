#include "DatasportHtmlGetter.h"

#include "DatasportParser.h"

DatasportHtmlGetter::DatasportHtmlGetter(QObject *parent)
    : QObject(parent)
{

}

void DatasportHtmlGetter::onFinished()
{
    QIODevice * content = static_cast<QIODevice*>(QObject::sender());
    QString results = content->readAll();
    rawHtml += results;

    DatasportParser parser;
    parser.parse(rawHtml.toStdString());
}
