#include "../include/InstaPostDelegate.h"
#include "../include/InstaPostRoles.h"

#include <QPainter>
#include <QPainterPath>
#include <QPixmap>
#include <QRect>
#include <QPixmapCache>

InstaPostDelegate::InstaPostDelegate(QObject *parent) : QStyledItemDelegate(parent) {
    font.setFamily("Segoe UI");
    font.setPixelSize(18);
    font.setBold(true);

    fm = QFontMetrics(font);

    const int iconW = 28;
    const int iconH = 28;
    auto scaledIcon = [this](const QString &path, const QSize &size = QSize(28, 28)){
        return QPixmap(path).scaled(size,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    };

    m_musicIcon = scaledIcon(":/icons/music.svg",QSize(18,18));
    m_likesIcon = scaledIcon(":/icons/likes.svg");
    m_commentsIcon = scaledIcon(":/icons/comments.svg");
    m_repostIcon = scaledIcon(":/icons/repost.svg");
    m_shareIcon = scaledIcon(":/icons/send.svg");
    m_saveIcon = scaledIcon(":/icons/save.svg");
}

QSize InstaPostDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QSize size = QStyledItemDelegate::sizeHint(option, index);
    size.setHeight(730);
    size.setWidth(460);
    return size;
}

void InstaPostDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    painter->setRenderHints(QPainter::TextAntialiasing | QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    
    QPixmap picture;
    const QString profilePicPath = index.data(InstaPostRoles::ProfilePicture).toString();
    if (!QPixmapCache::find(profilePicPath,&picture)){
        picture = QPixmap(profilePicPath).scaled(60, 60, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }

    const QString name = index.data(InstaPostRoles::UserName).toString();
    const QString melodyIconPath = index.data(InstaPostRoles::MelodyIcon).toString();
    const QString musicName = index.data(InstaPostRoles::MusicName).toString();
    bool follow = index.data(InstaPostRoles::Follow).toBool();
    bool menu = index.data(InstaPostRoles::Menu).toBool();
    const QString postPicture = index.data(InstaPostRoles::PostPicture).toString();
    const int likesCount = index.data(InstaPostRoles::LikesCount).toInt();
    const int commentsCount = index.data(InstaPostRoles::CommentsCount).toInt();
    const int repostCount = index.data(InstaPostRoles::RepostCount).toInt();
    const int shareCount = index.data(InstaPostRoles::ShareCount).toInt();
    const int saveCount = index.data(InstaPostRoles::SaveCount).toInt();

    QRect rect = option.rect;

    // profile Information rectangle for a post
    const int profileInfoRecW = rect.width();
    const int profileInfoRecH = 80;
    const int profileInfoRecX = (rect.width() - profileInfoRecW) / 2;
    const int profileInfoRecY = rect.top();
    QRect profileInfoRec(profileInfoRecX, profileInfoRecY, profileInfoRecW, profileInfoRecH);

    // profile Picture Rectangle
    const int profilePictureRecW = 60;
    const int profilePictureRecH = 60;
    const int profilePictureRecX = profileInfoRec.left() + 10;
    const int profilePictureRecY = profileInfoRec.top() + (profileInfoRec.height() - profilePictureRecH) / 2;
    QRect profilePictureRec(profilePictureRecX, profilePictureRecY, profilePictureRecW, profilePictureRecH);

    painter->save();

    // masking for circular profile picture
    QPainterPath path;
    path.addEllipse(profilePictureRec);

    painter->setClipPath(path);
    painter->drawPixmap(profilePictureRec,picture);

    painter->restore();

    // profile Name Reactnagle
    
    const int nameW = fm.horizontalAdvance(name);
    const int nameH = fm.height();
    const int nameX = profilePictureRec.right() + 14;
    const int nameY = profilePictureRec.top() + 6 + fm.ascent();
    QRect nameRec(nameX, nameY, nameW, nameH);

    painter->setFont(font);
    painter->setPen(QColor("#fffcfc"));
    painter->drawText(nameX, nameY, name);

    // music icon rectangle
    const int musicIconRecW = 18;
    const int musicIconRecH = 18;
    const int musicIconRecX = profilePictureRec.right() + 14;
    const int musicIconRecY = nameRec.bottom() - 12;
    QRect musicIconRec(musicIconRecX, musicIconRecY, musicIconRecW, musicIconRecH);

    painter->drawPixmap(musicIconRec, m_musicIcon);

    painter->save();
    font.setBold(false);
    painter->setFont(font);

    // music name rectangle
    const int musicNameRecW = fm.horizontalAdvance(musicName);
    const int musicNameRecH = fm.height();
    const int musicNameRecX = musicIconRec.right() + 14;
    const int musicNameRecY = musicIconRec.top() + (musicIconRec.height() - musicNameRecH) / 2 + fm.ascent();
    QRect musicNameRec(musicNameRecX, musicNameRecY, musicNameRecW, musicNameRecH);

    painter->drawText(musicNameRecX, musicNameRecY, musicName);
    painter->restore();

    // follow button rounded rectangle
    const int roundedFollowRecW = 80;
    const int roundedFollowRecH = 40;
    const int roundedFollowRecX = profileInfoRec.right() - 4 - roundedFollowRecW;
    const int roundedFollowRecY = profileInfoRec.top() + (profileInfoRec.height() - roundedFollowRecH) / 2;
    QRect roundedFollowRec(roundedFollowRecX, roundedFollowRecY, roundedFollowRecW, roundedFollowRecH);

    painter->drawRoundedRect(roundedFollowRec, 8, 8);

    // follow Text rectangle inside rounded rectangle
    const int followTextW = fm.horizontalAdvance(followText);
    const int followTextH = fm.height();
    const int followTextX = roundedFollowRec.left() + (roundedFollowRec.width() - followTextW) / 2;
    const int followTextY = roundedFollowRec.top() + (roundedFollowRec.height() - followTextH) / 2 + fm.ascent();

    QRect followTextRec(roundedFollowRecX, roundedFollowRecY, roundedFollowRecW, roundedFollowRecH);
    painter->drawText(followTextX, followTextY, followText);

    // menu as a lines by drawing
    // painter->drawLine(roundedFollowRec.right() + 8 , followTextY,rect.right() - 10,followTextY);
    // painter->drawLine(roundedFollowRec.right() + 8 , followTextRec.bottom(),rect.right() - 10,followTextRec.bottom());

    // post picture rectangle
    const int postPictureRecW = rect.width();
    const int postPictureRecH = rect.width() + 100;
    const int postPictureRecX = (rect.width() - postPictureRecW) / 2;
    const int postPictureRecY = profileInfoRec.bottom() + 4;
    QRect postPictureRec(postPictureRecX, postPictureRecY, postPictureRecW, postPictureRecH);

    painter->drawPixmap(postPictureRec, QPixmap(postPicture).scaled(rect.width(), rect.width() + 100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

    // reach rectangle involving likes, comments, reposts, shares and saves
    const int reachRecW = rect.width();
    const int reachRecH = 60;
    const int reachRecX = (rect.width() - reachRecW) / 2;
    const int reachRecY = (rect.bottom() - reachRecH) - 4;
    QRect reachRec(reachRecX, reachRecY, reachRecW, reachRecH);

    // like Icon rectangle
    const int likeIconRecW = 28;
    const int likeIconRecH = 28;
    const int likeIconRecX = reachRec.left() + 12;
    const int likeIconRecY = reachRec.top() + (reachRec.height() - likeIconRecH) / 2;
    QRect likeRec(likeIconRecX, likeIconRecY, likeIconRecW, likeIconRecH);

    painter->drawPixmap(likeRec, m_likesIcon);

    // likes count as a text
    const int likeCountW = fm.horizontalAdvance(QString::number(likesCount));
    const int likeCountH = fm.height();
    const int likeCountX = likeRec.right() + 4;
    const int likeCountY = likeRec.top() + (likeRec.height() - likeCountH) / 2 + fm.ascent();

    painter->drawText(likeCountX, likeCountY, QString::number(likesCount));

    // comment rectangle
    const int commentIconRecH = 28;
    const int commentIconRecW = 28;
    const int commentIconRecX = likeRec.right() + likeCountW + 12 + 4;
    const int commentIconRecY = reachRec.top() + (reachRec.height() - commentIconRecH) / 2;
    QRect commentRec(commentIconRecX, commentIconRecY, commentIconRecW, commentIconRecH);

    painter->drawPixmap(commentRec, m_commentsIcon);

    // comments count as a text
    const int commentCountW = fm.horizontalAdvance(QString::number(commentsCount));
    const int commentCountH = fm.height();
    const int commentCountX = commentRec.right() + 4;
    const int commentCountY = commentRec.top() + (commentRec.height() - commentCountH) / 2 + fm.ascent();

    painter->drawText(commentCountX, commentCountY, QString::number(commentsCount));

    // repost Rectangle
    const int repostIconRecW = 28;
    const int repostIconRecH = 28;
    const int repostIconRecX = commentRec.right() + commentCountW + 12 + 4;
    const int repostIconRecY = reachRec.top() + (reachRec.height() - repostIconRecH) / 2;
    QRect repostRec(repostIconRecX, repostIconRecY, repostIconRecW, repostIconRecH);

    painter->drawPixmap(repostRec, m_repostIcon);

    // repost count as text
    const int repostCountW = fm.horizontalAdvance(QString::number(repostCount));
    const int repostCountH = fm.height();
    const int repostCountX = repostRec.right() + 4;
    const int repostCountY = repostRec.top() + (repostRec.height() - repostCountH) / 2 + fm.ascent();

    painter->drawText(repostCountX, repostCountY, QString::number(repostCount));

    // share rectangle
    const int shareIconRecW = 28;
    const int shareIconRecH = 28;
    const int shareIconRecX = repostRec.right() + repostCountW + 12 + 4;
    const int shareIconRecY = reachRec.top() + (reachRec.height() - shareIconRecH) / 2;
    QRect shareRec(shareIconRecX, shareIconRecY, shareIconRecW, shareIconRecH);

    painter->drawPixmap(shareRec, m_shareIcon);

    // share count as text
    const int shareCountW = fm.horizontalAdvance(QString::number(shareCount));
    const int shareCountH = fm.height();
    const int shareCountX = shareRec.right() + 4;
    const int shareCountY = shareRec.top() + (shareRec.height() - shareCountH) / 2 + fm.ascent();

    painter->drawText(shareCountX, shareCountY, QString::number(shareCount));

    // save rectangle
    const int saveIconRecW = 28;
    const int saveIconRecH = 28;
    const int saveIconRecX = reachRec.right() - saveIconRecW - 12;
    const int saveIconRecY = reachRec.top() + (reachRec.height() - saveIconRecH) / 2;

    QRect saveIconRec(saveIconRecX, saveIconRecY, saveIconRecW, saveIconRecH);
    painter->drawPixmap(saveIconRec, m_saveIcon);
}