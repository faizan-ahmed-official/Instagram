#include "Database.h"
#include <QSqlError>
#include <QSqlQuery>

Database::Database(QObject *parent) : QObject(parent) {
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/faiza/Desktop/instaDatabaseReal.db");
    sqlQuerry = QSqlQuery(database);
    if(!database.open()){
        qDebug() << "database doesnot open";
        qDebug() << database.lastError().text();
    }
    
}

std::vector<Database::InstaPostData> Database::readPostsData() {
    QString query = "SELECT * FROM insta_post_data;";
    
    if(sqlQuerry.exec(query)){
        while(sqlQuerry.next()){
            Database::InstaPostData I1;
            I1.name = sqlQuerry.value("name").toString();
            I1.musicName = sqlQuerry.value("music").toString();
            I1.likeCount = sqlQuerry.value("likes").toInt();
            I1.commentCount = sqlQuerry.value("comments").toInt();
            I1.repostCount = sqlQuerry.value("repost").toInt();
            I1.shareCount = sqlQuerry.value("share").toInt();
            I1.saveCount = sqlQuerry.value("favourite").toInt();
            instaDataVec.push_back(I1);
        }
    }
    else{
        qDebug() << "something went wrong";
        qDebug() << database.lastError().text();
    }
    return instaDataVec;
}