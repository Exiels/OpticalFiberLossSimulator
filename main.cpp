#include <QApplication>
#include <QtWidgets>
#include "mainframe.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainFrame *fenetre;

    fenetre = new MainFrame();
    fenetre->show();

    return app.exec();
}
