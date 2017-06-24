#include "treemodel.h"
#include <QVariant>
TreeModel::TreeModel(QObject *parent)
    :QAbstractItemModel(parent)
{

}
TreeModel::~TreeModel()
{

}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    return 0;
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    return 0;
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    return QVariant();
}

bool TreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return true;
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}
/*
QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    return QModelIndex;
}
*/
Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsUserCheckable;
}
