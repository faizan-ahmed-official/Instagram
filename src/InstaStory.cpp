#include "../include/InstaStory.h"

#include <QPainter>
#include <QPainterPath>

InstaStory::InstaStory(QWidget *parent) : QWidget(parent) {
    setFixedSize(100, 80);

    m_plusIcon = QPixmap(":/icons/plus-black.svg").scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void InstaStory::setStoryBorder(bool border) {
    m_border = border;
    update();
}

void InstaStory::setStoryPicture(const QString &picturePath) {
    m_picPath = picturePath;
    update();
}

void InstaStory::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);

    const int picRecW = 80;
    const int picRecH = 80;
    const int picRecX = (width() - picRecW) / 2;
    const int picRecY = (height() - picRecH) / 2;

    QRect picRec(picRecX, picRecY, picRecW, picRecH);

    painter.save();
    QPainterPath path;
    path.addEllipse(picRec.center(), 30, 30);
    painter.setClipPath(path);

    painter.drawPixmap(picRec, QPixmap(m_picPath).scaled(60, 60, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    painter.restore();

    if (m_border) {
        painter.setBrush(Qt::transparent);

        QConicalGradient gradient(picRec.center(), 42);
        gradient.setColorAt(0.00, QColor("#FEDA75"));
        gradient.setColorAt(0.15, QColor("#FA7E1E"));
        gradient.setColorAt(0.35, QColor("#D62976"));
        gradient.setColorAt(0.55, QColor("#962FBF"));
        gradient.setColorAt(0.75, QColor("#4F5BD5"));
        gradient.setColorAt(1.00, QColor("#FEDA75"));

        QPen pen;
        pen.setWidth(4);
        pen.setBrush(gradient);

        painter.setPen(pen);
        painter.drawEllipse(picRec.center(), 36, 36);
    } else {
        int plusRecW = 20;
        int plusRecH = 20;
        int plusRecX = picRec.right() - 30;
        int plusRecY = picRec.bottom() - 30;

        QRect plusRec(plusRecX, plusRecY, plusRecW, plusRecH);

        painter.setBrush("#f8f8f8");
        painter.drawEllipse(plusRec.center(), 10, 10);

        int plusIconX = plusRec.left() + (plusRecW - 22) / 2;
        int plusIconY = plusRec.top() + (plusRecH - 22) / 2;
        painter.drawPixmap(plusIconX, plusIconY, m_plusIcon);
    }
}