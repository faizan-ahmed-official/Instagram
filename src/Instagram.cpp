#pragma once

#include "../include/Instagram.h"
#include "../include/InstaHeader.h"
#include "../include/InstaStories.h"
#include "../include/InstaPostDelegate.h"
#include "../include/ScrollBar.h"
#include "../include/InstaPostRoles.h"
#include "../include/InstaNavBar.h"
#include "./core/Database.h"
#include <QVBoxLayout>
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>

Instagram::Instagram(QWidget *parent) : QWidget(parent) {
    setFixedSize(500, 680);

    Database d1;
    model = new QStandardItemModel();
    std::vector<Database::InstaPostData> vec = d1.readPostsData();
    for(int i = 0; i < vec.size(); i++){
        Database::InstaPostData I1 = vec[i];
        
        QStandardItem *item = new QStandardItem();
        item->setData(QString(":/pictures/afaq.jpeg"), InstaPostRoles::ProfilePicture);
        item->setData(I1.name, InstaPostRoles::UserName);
        item->setData(I1.musicName, InstaPostRoles::MusicName);
        item->setData(QString(":/pictures/afaq.jpeg"), InstaPostRoles::PostPicture);
        item->setData(I1.likeCount, InstaPostRoles::LikesCount);
        item->setData(I1.commentCount, InstaPostRoles::CommentsCount);
        item->setData(I1.repostCount, InstaPostRoles::RepostCount);
        item->setData(I1.shareCount, InstaPostRoles::ShareCount);
        item->setData(I1.saveCount, InstaPostRoles::SaveCount);
        model->appendRow(item);
    }

    setWindowIcon(QIcon(":/icons/instagram.ico"));
    setWindowTitle("Instagram");

    // Header
    instaHeader = new InstaHeader();

    // Stories Widget
    storySection = new InstaStories();

    // Vertical Layout
    Vlayout = new QVBoxLayout();
    Vlayout->setContentsMargins(0, 0, 0, 0);
    Vlayout->setSpacing(0);
    Vlayout->addWidget(instaHeader);
    Vlayout->addWidget(storySection);
    Vlayout->addSpacing(4);


    // ScrollBar
    vScrollBar = new ScrollBar();
    vScrollBar->setDarkMode(true);

    // Delegate
    delegate = new InstaPostDelegate();

    // List
    list = new QListView();
    list->setSpacing(2);
    list->setLayoutMode(QListView::Batched);
    list->setBatchSize(10);
    list->setUniformItemSizes(true);
    list->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    list->setStyleSheet({"background-color : transparent; border : none;"});
    list->setItemDelegate(delegate);
    list->setModel(model);
    list->setVerticalScrollBar(vScrollBar);

    Vlayout->addWidget(list);
    setLayout(Vlayout);

    // Nav Bar
    navBar = new InstaNavBar(this);
    navBar->move((width() - navBar->width()) / 2, rect().bottom() - 100);
    navBar->show();

    show();
}
