#include "DatasportModel.h"

DatasportModel::DatasportModel(QObject *parent) : QAbstractTableModel(parent)
{

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

void DatasportModel::newData(const std::pair<std::vector<std::string>, std::vector<std::vector<std::string> > > &results)
{
    resultsData = results;
    emit layoutChanged();
}
