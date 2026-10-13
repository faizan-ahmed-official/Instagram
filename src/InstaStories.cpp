#include "../include/InstaStories.h"
#include "../include/InstaStory.h"

#include <QHBoxLayout>

InstaStories::InstaStories(QWidget *parent) : QWidget(parent) {
    setFixedSize(500, 80);

    HLayout = new QHBoxLayout();
    HLayout->setContentsMargins(0, 0, 0, 0);
    HLayout->setSpacing(0);

    InstaStory *s1 = new InstaStory();
    s1->setStoryBorder(false);
    s1->setStoryPicture(":/pictures/faizan.jpeg");

    InstaStory *s2 = new InstaStory();
    s2->setStoryBorder(true);
    s2->setStoryPicture(":/pictures/afaq.jpeg");

    InstaStory *s3 = new InstaStory();
    s3->setStoryBorder(true);
    s3->setStoryPicture(":/pictures/omer.jpeg");

    InstaStory *s4 = new InstaStory();
    s4->setStoryBorder(true);
    s4->setStoryPicture(":/pictures/anfal.jpeg");

    InstaStory *s5 = new InstaStory();
    s5->setStoryBorder(true);
    s5->setStoryPicture(":/pictures/kashif.jpeg");

    HLayout->addWidget(s1);
    HLayout->addSpacing(2);
    HLayout->addWidget(s2);
    HLayout->addSpacing(2);
    HLayout->addWidget(s3);
    HLayout->addSpacing(2);
    HLayout->addWidget(s4);
    HLayout->addSpacing(2);
    HLayout->addWidget(s5);
    HLayout->addStretch();

    setLayout(HLayout);
}
