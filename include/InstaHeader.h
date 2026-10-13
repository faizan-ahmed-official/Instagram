#pragma once

#include <QWidget>

class QPushButton;
class QLabel;
class QHBoxLayout;

class InstaHeader : public QWidget {
    public:
        InstaHeader(QWidget *parent = nullptr);

    private:
        QPushButton *addContentBtn = nullptr;
        QPushButton *notificationBtn = nullptr;
        QLabel *instaTextLogo = nullptr;
        QLabel *dropDownIcon = nullptr;
        QHBoxLayout *hLayout = nullptr;
};
