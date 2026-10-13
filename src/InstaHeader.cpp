#include "../include/InstaHeader.h"

#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

InstaHeader::InstaHeader(QWidget *parent) : QWidget(parent) {
    setFixedSize(500, 80);

    addContentBtn = new QPushButton(this);
    addContentBtn->setIcon(QIcon(":/icons/plus.svg"));
    addContentBtn->setFixedSize(36, 36);
    addContentBtn->setIconSize(QSize(36, 36));
    addContentBtn->setStyleSheet("background-color: transparent; border: none; border-radius: 8px;");

    notificationBtn = new QPushButton(this);
    notificationBtn->setIcon(QIcon(":/icons/likes.svg"));
    notificationBtn->setStyleSheet("background-color: transparent; border: none; border-radius: 8px;");
    notificationBtn->setFixedSize(36, 36);
    notificationBtn->setIconSize(QSize(36, 36));

    dropDownIcon = new QLabel(this);
    dropDownIcon->setAttribute(Qt::WA_TranslucentBackground);
    QPixmap dropDownScaled = QPixmap(":/icons/chevron-down.svg").scaled(36, 36, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    dropDownIcon->setPixmap(dropDownScaled);
    dropDownIcon->setFixedSize(36, 36);

    instaTextLogo = new QLabel(this);
    QPixmap instaLogo(":/icons/insta-header-text.png");
    QPixmap scaledInstaLogo = instaLogo.scaled(160, 60, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    instaTextLogo->setPixmap(scaledInstaLogo);
    instaTextLogo->setFixedSize(160, 60);

    hLayout = new QHBoxLayout(this);
    hLayout->addWidget(addContentBtn);
    hLayout->addStretch();
    hLayout->addWidget(instaTextLogo);
    hLayout->addWidget(dropDownIcon);
    hLayout->addStretch();
    hLayout->addWidget(notificationBtn);
}
