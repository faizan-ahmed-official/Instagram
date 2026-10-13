#pragma once

#include <QStyledItemDelegate>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QFont>
#include <QFontMetrics>

class InstaPostDelegate : public QStyledItemDelegate {
    public:
        InstaPostDelegate(QObject *parent = nullptr);

    protected:
        QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
        void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
        
    private:
        const QString followText = "Follow";
        mutable QFont font = QFont();
        QFontMetrics fm{QFont()};
        QPixmap m_musicIcon, m_likesIcon, m_commentsIcon, m_repostIcon, m_shareIcon, m_saveIcon;
};