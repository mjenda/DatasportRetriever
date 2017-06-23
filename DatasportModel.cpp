#include "DatasportModel.h"
#include <QDebug>
#include <QStringList>
#include <DatasportHtmlGetter.h>

DatasportModel::DatasportModel(QObject *parent)
    : QAbstractTableModel(parent),
      competitionId(-1),
      resultsData(),
      datasportHtmlGetter(new DatasportHtmlGetter(this))
{
    QObject::connect(datasportHtmlGetter, &DatasportHtmlGetter::finished,
                         this, &DatasportModel::newData);
}

void DatasportModel::setCompetition(int _competitionId)
{
    competitionId = _competitionId;
    datasportHtmlGetter->get(competitionId);
}

int DatasportModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return resultsData.second.size();
}

int DatasportModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return resultsData.first.size();
}

QVariant DatasportModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
       auto & data = resultsData.second;
       return QString::fromStdString(data[index.row()][index.column()]);
    }
    return QVariant();
}

QVariant DatasportModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    auto & headers = resultsData.first;

    if(orientation == Qt::Horizontal && role == Qt::DisplayRole && headers.size() > section)
    {
        return QString::fromStdString(headers[section]);
    }
    else return QAbstractTableModel::headerData(section, orientation, role);
}

void DatasportModel::newData(const DatasportData &results)
{
    resultsData = results;

    emit layoutChanged();
}
