#include "../include/InstaNavBar.h"

#include <QPainter>

InstaNavBar::InstaNavBar(QWidget *parent) : QWidget(parent) {
        setFixedSize(320,60);

        const int iconW = 28, iconH = 28;

        auto scaledIcon = [this](const QString &path) {
                return QPixmap(path).scaled(iconW, iconH, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        };

        m_homeIcon = scaledIcon(":/icons/home.svg");
        m_reelsIcon = scaledIcon(":/icons/reels.svg");
        m_sendIcon = scaledIcon(":/icons/nav-send.svg");
        m_searchIcon = scaledIcon(":/icons/search.svg");
        m_profileIcon = scaledIcon(":/icons/profile.svg");
}

void InstaNavBar::paintEvent(QPaintEvent *event) {
        QPainter painter(this);
        painter.setRenderHints(QPainter::TextAntialiasing | QPainter::Antialiasing | QPainter:: SmoothPixmapTransform);

        QRect rec = rect().adjusted(1,1,-1,-1);
        int navigationBarRecW = 320;
        int navigationBarRecH = 60;
        int navigationBarRecX = rect().left() + (rect().width() - navigationBarRecW) / 2;
        int navigationBarRecY = rec.top();
        QRect navigationBarRec(navigationBarRecX,navigationBarRecY,navigationBarRecW,navigationBarRecH);

        painter.save();
        painter.setOpacity(0.7);
        painter.setPen(QPen(QColor("#FFFFFF"),1.0));
        painter.setBrush(Qt::black);
        painter.drawRoundedRect(navigationBarRec,navigationBarRecH / 2,navigationBarRecH / 2);
        painter.restore();

        int iconW = 28;
        int iconH = 28;
        int spacing = 30;

        int homeIconRecX = navigationBarRecX + spacing;
        int homeIconRecY = (navigationBarRec.height() - iconH) / 2;
        QRect homeIconRec(homeIconRecX,homeIconRecY,iconW,iconH);

        painter.drawPixmap(homeIconRec,m_homeIcon);

        int reelsIconRectX = homeIconRec.right() + spacing;
        int reelsIconRectY = (navigationBarRec.height() - iconH) / 2;
        QRect reelsIconRec(reelsIconRectX,reelsIconRectY,iconW,iconH);

        painter.drawPixmap(reelsIconRec,m_reelsIcon);

        int sendIconRecX = reelsIconRec.right() + spacing;
        int sendIconRecY = (navigationBarRec.height() - iconH) / 2;
        QRect sendIconRec(sendIconRecX,sendIconRecY,iconW,iconH);

        painter.drawPixmap(sendIconRec,m_sendIcon);
            
        int searchIconRecX = sendIconRec.right() + spacing;
        int searchIconRecY = (navigationBarRec.height() - iconH) / 2;
        QRect searchIconRec(searchIconRecX,searchIconRecY,iconW,iconH);

        painter.drawPixmap(searchIconRec,m_searchIcon);

        int profileIconRecX = searchIconRec.right() + spacing;
        int profileIconRecY = (navigationBarRec.height() - iconH) / 2;
        QRect profileIconRec(profileIconRecX,profileIconRecY,iconW,iconH);

        painter.drawPixmap(profileIconRec,m_profileIcon);
}
        