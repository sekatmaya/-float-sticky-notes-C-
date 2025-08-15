#include <QApplication>
#include "NotesWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    NotesWindow win;
    win.show();
    return app.exec();
}