#include "./include/Instagram.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc,argv);
    app.setWindowIcon(QIcon(":/icons/instagram.ico"));
    Instagram *instaHome = new Instagram(); 

    return app.exec();
}
