#include "app/app.h"
int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    App w;
    w.show();
    return app.exec();
}
