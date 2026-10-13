#pragma once

#include <QWidget>

class QPixmap;

class InstaNavBar : public QWidget {
    public:
        InstaNavBar(QWidget *parent = nullptr);

    protected:
        void paintEvent(QPaintEvent *event) override;

    private:
        QPixmap m_homeIcon, m_reelsIcon, m_sendIcon, m_searchIcon, m_profileIcon;
};