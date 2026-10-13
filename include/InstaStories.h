#pragma once

#include <QWidget>

class QHBoxLayout;

class InstaStories : public QWidget {
    public:
        InstaStories(QWidget *parent = nullptr);
           
    private:
        QHBoxLayout *HLayout = nullptr;
};
