#ifndef TREEMODEL_H
#define TREEMODEL_H
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QAbstractItemModel>
class TreeModel : public QAbstractItemModel
{
public:
    TreeModel(QObject *parent=0);
    ~TreeModel();
    virtual int rowCount(const QModelIndex &parent) const;      //行数量
    virtual int columnCount(const QModelIndex &parent) const;   //列数量
    virtual QVariant data(const QModelIndex &index, int role) const;    //数据
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role);
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    //virtual QModelIndex index(int row, int column, const QModelIndex &parent) const;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;
private:

};

#endif // TREEMODEL_H
