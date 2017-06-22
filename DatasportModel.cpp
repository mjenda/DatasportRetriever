#include "DatasportModel.h"

DatasportModel::DatasportModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int DatasportModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 2;
}

int DatasportModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 3;
}

QVariant DatasportModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
       return QString("Row%1, Column%2")
                   .arg(index.row() + 1)
                   .arg(index.column() +1);
    }
    return QVariant();
}
