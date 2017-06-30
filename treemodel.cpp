#include "treemodel.h"
#include <QVariant>
#include <QBrush>
#include <QFont>
TreeModel::TreeModel(QObject *parent)
    :QAbstractItemModel(parent)
{
    int values[N]={36,10,26,3,7, 11,15, 1,2,3,4,5,6,7,8};
    for(int i=0;i<N;++i)
    {
        numbers[i]=values[i];
    }
    timer=new QTimer(this);
    timer->setInterval(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerHit()));
    timer->start();
}

TreeModel::~TreeModel()
{

}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    if(!parent.isValid())   //只有根节点
           return 1;
    if(parent.internalId()<N/2)     //非叶节点
           return 2;
    return 0;   //叶子节点
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!parent.isValid())
        return createIndex(row,column,quintptr(0));
    int parent_idx=parent.internalId();
    int idx=parent_idx * 2 + (row+1);   //2*i+1 or 2*i+2
    return createIndex(row,column,idx);
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if(index.internalId()==0)
        return QModelIndex();
    int parent_idx=(index.internalId()-1)/2;
    return createIndex((parent_idx+1)%2,0,parent_idx);
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
    case Qt::DisplayRole:{
        int value=numbers[index.internalId()];
        return QVariant(value);}
    case Qt::ForegroundRole: {
        if(index.internalId()>=N/2)
            return QBrush(Qt::red);
        break;}
    case Qt::FontRole:{
        QFont font;
        if(index.internalId()>=N/2)
            font.setPointSize(26);
        else
            font.setPointSize(20);
        return font;}
    }
    return QVariant();
}
/*
bool TreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return true;
}
*/
QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role==Qt::DisplayRole && section==0 && orientation==Qt::Horizontal){
        return QString("Full Binary Tree");
    }
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
    if(index.internalId()<N/2)
        return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
    else
        return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
}

void TreeModel::timerHit()
{
    numbers[14]=(numbers[14]+1)%60;
    numbers[6]=numbers[14]+numbers[13];
    numbers[2]=numbers[6]+numbers[5];
    numbers[0]=numbers[2]+numbers[1];
    QModelIndex idx_14=createIndex(1,0,14);
    QModelIndex idx_6=createIndex(1,0,6);
    QModelIndex idx_2=createIndex(1,0,2);
    QModelIndex idx_0=createIndex(0,0,quintptr(0));

    emit dataChanged(idx_14,idx_14);
    emit dataChanged(idx_6,idx_6);
    emit dataChanged(idx_2,idx_2);
    emit dataChanged(idx_0,idx_0);
}
