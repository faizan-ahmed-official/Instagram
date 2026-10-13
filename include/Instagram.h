#pragma once

#include <QWidget>

class InstaHeader;
class InstaStories;
class QVBoxLayout;
class QListView;
class QStandardItemModel;
class QStandardItem;
class InstaPostDelegate;
class ScrollBar;
class InstaNavBar;

class Instagram : public QWidget {
    public:
        explicit Instagram(QWidget *parent = nullptr);

    private:
        InstaHeader *instaHeader = nullptr;
        InstaStories *storySection = nullptr;
        QVBoxLayout *Vlayout = nullptr;

        QListView *list = nullptr;
        
        QStandardItemModel *model = nullptr;

        InstaPostDelegate *delegate = nullptr;
        ScrollBar *vScrollBar = nullptr; 
        InstaNavBar *navBar = nullptr;
};