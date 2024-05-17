#include "BaseListModel.h"

#include <QDebug>

BaseListModel::BaseListModel(QObject *parent, QList<QObject*> *list)
    : QAbstractListModel(parent),
      _list(list)
{
    //! modify
//    QHash<int, QByteArray> roles;
//    roles[Qt::UserRole + 1] = "object";
//    setRoleNames(roles);
    //! --

    _roleNames[Qt::UserRole + 1] = "object";

//    //! modify
//    _roleNames[Qt::UserRole + 2] = "sectionKey";
//    //! --
}

BaseListModel::~BaseListModel()
{

}

int BaseListModel::indexOf(QObject *obj) const
{
    return _list->indexOf(obj);
}

void BaseListModel::clearData()
{
    qDebug() << Q_FUNC_INFO << "size = " << _list->size();
//    reset();
    beginResetModel();
    if (_list->size() > 0) {
        foreach (auto item, *_list) {
            qDebug() << item;
            if (nullptr != item) {
                delete item;
                item = nullptr;
            }
        }
    }
    _list->clear();
    endResetModel();
    qDebug() << Q_FUNC_INFO << "end";
}

int BaseListModel::dataSize() const
{
    return _list->size();
}

int BaseListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _list->count();
}

int BaseListModel::itemCount() const
{
    return _list->count();
}

int BaseListModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 1;
}

QVariant BaseListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= _list->count())
        return QVariant();
    if (role == Qt::UserRole + 1)
    {
        QObject *obj = _list->at(index.row());
        return QVariant::fromValue(obj);
    }
    return QVariant(0);
}

bool BaseListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.row() < 0 || index.row() >= _list->count())
        return false;

    if (role == Qt::UserRole + 1)
    {
        _list->replace(index.row(), reinterpret_cast<QObject*>(value.toInt()));
        return true;
    }

    return false;
}

void BaseListModel::insertItem(int index, QObject *item)
{
    beginInsertRows(QModelIndex(), index, index);
    _list->insert(index, item);
    connect(item, SIGNAL(destroyed()), this, SLOT(removeDestroyedItem()));
    endInsertRows();

    emit itemAdded(item);
    emit itemCountChanged();
}

void BaseListModel::prependItems(const QList<QObject *> &items, bool isReset)
{
    if (!isReset) {
        beginInsertRows(QModelIndex(), 0, items.size() - 1);
    }
    foreach (auto item, items) {
        if (nullptr != item) {
            _list->prepend(item);
            connect(item, SIGNAL(destroyed()), this, SLOT(removeDestroyedItem()));
        }
    }
    if (!isReset) {
        endInsertRows();
        emit itemCountChanged();
    }
}

void BaseListModel::pushFrontItems(const QList<QObject *> &items)
{
    prependItems(items);
}

void BaseListModel::appendItems(const QList<QObject *>& items, bool isReset)
{
    if (!isReset) {
        beginInsertRows(QModelIndex(), _list->count() == 0 ? 0 : _list->count(), _list->count() + items.size() - 1);
    }
    _list->append(items);
    foreach (auto item, items) {
        if (nullptr != item) {
            connect(item, SIGNAL(destroyed()), this, SLOT(removeDestroyedItem()));
        }
    }
    if (!isReset) {
        endInsertRows();
        emit itemCountChanged();
    }
}

void BaseListModel::pushBackItems(const QList<QObject *> &items)
{
    appendItems(items);
}

void BaseListModel::addItem(QObject *item)
{
    insertItem(_list->count(), item);
}

void BaseListModel::addItemBegin(QObject *item)
{
    insertItem(0, item);
}

void BaseListModel::removeDestroyedItem()
{
    QObject *obj = QObject::sender();
    removeObject(obj);
}

void BaseListModel::removeObject(QObject *item)
{
    int index = _list->indexOf(item);
    if (index >= 0) {
        beginRemoveRows(QModelIndex(), index, index);
        _list->removeAt(index);
        disconnect(item, SIGNAL(destroyed()), this, SLOT(removeDestroyedItem()));
        endRemoveRows();
        emit itemCountChanged();
    }
}

//! modify
QObject * BaseListModel::takeItemAt(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    disconnect(((QObject*)_list->at(index)), SIGNAL(destroyed()), this, SLOT(removeDestroyedItem()));
    QObject * item = _list->takeAt(index);
    endRemoveRows();
    emit itemCountChanged();

    return item;
}
//! --

void BaseListModel::removeItem(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    disconnect(((QObject*)_list->at(index)), SIGNAL(destroyed()), this, SLOT(removeDestroyedItem()));
    _list->removeAt(index);
    endRemoveRows();
    emit itemCountChanged();
}

QObject* BaseListModel::get(int index)
{
    if (index >= _list->count() || index < 0)
        return nullptr;

    return _list->at(index);
}

QList<QObject*> *BaseListModel::getList()
{
    return _list;
}

void BaseListModel::setList(QList<QObject *> *list)
{
    QList<QObject *> *oldList = _list;
    beginResetModel();
    _list = list;
    endResetModel();
    emit itemCountChanged();
    delete oldList;
}

void BaseListModel::reset()
{
    //! modify
//    QAbstractListModel::reset();

    beginResetModel();
    _list->clear();
    endResetModel();
    //! --

    emit itemCountChanged();
}

void BaseListModel::move(int oldRow, int newRow)
{
    //! modify
    if (oldRow == newRow)
        return;
    //! --

    if (oldRow < 0 || oldRow >= _list->count())
        return;

    if (newRow < 0 || newRow >= _list->count())
        return;

    beginMoveRows(QModelIndex(), oldRow, oldRow, QModelIndex(), (newRow > oldRow) ? (newRow + 1) : newRow);
    _list->move(oldRow, newRow);
    endMoveRows();
}

QHash<int, QByteArray>	BaseListModel::roleNames() const
{
    return _roleNames;
}
