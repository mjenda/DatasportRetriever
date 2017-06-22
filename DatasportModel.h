#pragma once

#include <DatasportData.hpp>
#include <QAbstractTableModel>

class DatasportModel : public QAbstractTableModel
{

    Q_OBJECT
public:
    DatasportModel(QObject * parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

public slots:
    void newData(const DatasportData & results);

private:
    DatasportData resultsData;

};
