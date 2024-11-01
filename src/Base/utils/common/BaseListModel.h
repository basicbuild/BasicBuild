/*!
 * \file BaseListModel.h
 * \brief 与qml交互ListModel基类
 */
#pragma once
#ifndef BaseListModel_H_8cae6f5a_7b5b_4006_98c2_c4dbca433f23
#define BaseListModel_H_8cae6f5a_7b5b_4006_98c2_c4dbca433f23

#include <QAbstractListModel>
#include <QMap>
#include <QList>
#include "Base_global.h"

class BASE_EXPORT BaseListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int itemCount READ itemCount NOTIFY itemCountChanged)

    //! modify
    QHash<int, QByteArray> _roleNames;

public:
    explicit BaseListModel(QObject *parent = nullptr, QList<QObject*> *list = new QList<QObject*>());
    ~BaseListModel();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int itemCount() const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Q_INVOKABLE void reset();
    Q_INVOKABLE void move(int oldRow, int newRow);

    void insertItem(int index, QObject *item);
    void prependItems(const QList<QObject *>& items, bool isReset = false);
    void pushFrontItems(const QList<QObject *>& items);
    void appendItems(const QList<QObject *>& items, bool isReset = false);
    void pushBackItems(const QList<QObject *>& items);

    void addItem(QObject *item);
    void addItemBegin(QObject *item);
    void removeObject(QObject *item);
    Q_INVOKABLE void removeItem(int index);
    Q_INVOKABLE QObject* get(int index);
    int indexOf(QObject *obj) const;
    void clearData();
    int dataSize() const;

    //! modify
    QObject * takeItemAt(int index);
    //! --

    template<typename T>
    QList<T*> *getList();
    QList<QObject*> *getList();

    template<typename T>
    void setList(QList<T*> *list);
    void setList(QList<QObject*> *list);

    //! modify
    virtual QHash<int, QByteArray>	roleNames() const;
    //! --

private:
    QList<QObject*> *_list;

private slots:
    void removeDestroyedItem();

signals:
    void itemAdded(QObject *item);
    void itemCountChanged();
};

template<typename T>
QList<T*> *BaseListModel::getList()
{
    return reinterpret_cast<QList<T *> *>(_list);
}

template<typename T>
void BaseListModel::setList(QList<T*> *list)
{
    setList(reinterpret_cast<QList<QObject *> *>(list));
}

#endif // BaseListModel_H_8cae6f5a_7b5b_4006_98c2_c4dbca433f23
