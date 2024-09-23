#include "clientmain.h"
#include "ui_clientmain.h"
#include <QRegularExpression>

Clientmain::Clientmain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Clientmain)
    , Client(new client)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    // ui->tableWidget->setHorizontalHeader(QString("key;value").split(";"));
    ui->tableWidget->setHorizontalHeaderLabels(QString("key;value").split(";"));

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->lineEdit->setText("http://www.boost.org/LICENSE_1_0.txt");

    connect(Client,SIGNAL(read_finish(QString)), this, SLOT(on_success(QString)));
}

Clientmain::~Clientmain()
{
    delete ui;
    delete Client;
}

void Clientmain::on_btOk_clicked()
{
    QString url = ui->lineEdit->text();
    // std::string std_url = url.toStdString();

    QRegularExpression re("^(?:([A-Za-z]+):)?(\\/{0,3})([0-9.\\-A-Za-z]+)(?::(\\d+))?(?:\\/([^?#]*))?(?:\\?([^#]*))?(?:#(.*))?$");
    QRegularExpressionMatch match = re.match(url);

    if(match.hasMatch()){
        auto hostName = match.captured(3);
        auto urlPath = "/" + match.captured(5);

        Client->Get(hostName, urlPath);
    }
    // Client->Get("www.boost.org","/");
}

void Clientmain::on_success(const QString &msg)
{
    ui->textEdit_2->setText(msg);
}

