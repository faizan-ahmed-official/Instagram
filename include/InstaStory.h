#pragma once

#include <QWidget>

class InstaStory : public QWidget {
    public:
        InstaStory(QWidget *parent = nullptr);

        void setStoryBorder(bool border);
        void setStoryPicture(const QString &picturePath);

    protected:
        void paintEvent(QPaintEvent *event) override;

    private:
        bool m_border = false;
        QString m_picPath;
        QPixmap m_plusIcon;
};
