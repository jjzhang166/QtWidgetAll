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
};

#endif // TREEMODEL_H
