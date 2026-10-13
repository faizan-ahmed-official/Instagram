#include <QSqlDatabase>
#include <QSqlQuery>
#include <QObject>

#include <vector>

class Database : public QObject {
    public:
    Database(QObject *parent = nullptr);

    struct InstaPostData {
        QString name;
        QString musicName;
        int likeCount, commentCount, repostCount, shareCount, saveCount;
    };
    
    std::vector<InstaPostData> readPostsData();

    private:
    QSqlDatabase database;
    QSqlQuery sqlQuerry;
    std::vector<InstaPostData> instaDataVec;
};