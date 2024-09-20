#ifndef CLIENTMAIN_H
#define CLIENTMAIN_H

#include <QMainWindow>
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Clientmain;
}
QT_END_NAMESPACE

class Clientmain : public QMainWindow
{
    Q_OBJECT

public:
    Clientmain(QWidget *parent = nullptr);
    ~Clientmain();

private slots:
    void on_btOk_clicked();

private:
    Ui::Clientmain *ui;
    client* Client;
};
#endif // CLIENTMAIN_H
