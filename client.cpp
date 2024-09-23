#include "client.h"
#include <QDebug>

client::client():
    work(new boost::asio::io_context::work(iocontext)),
    resolver(iocontext),
    socket(iocontext)
{
    worker = std::thread([&](){
        iocontext.run();
    });
}

client::~client()
{
    iocontext.stop();
    worker.join(); // worker스레드 종료 대기
    work.reset();
}

void client::Get(const QString &url, const QString &p)
{
    //1. url -> ep resolve
    server = url.toStdString();
    path = p.toStdString();
    boost::asio::ip::tcp::resolver::query query(server,"http");
    resolver.async_resolve(query, boost::bind(
                                      &client::handle_resolve,
                                              this,
                                              boost::asio::placeholders::error,
                                              boost::asio::placeholders::iterator)
                           );

    //2. connect


    //3. send

    //4. recv

}

void client::handle_resolve(const boost::system::error_code &error,
                            boost::asio::ip::tcp::resolver::iterator endpoint_iterator)
{

    if(!error){
        boost::asio::ip::tcp::endpoint ep = *endpoint_iterator;

        qDebug() << ep.address().to_string().c_str() << Qt::endl;

        socket.async_connect(*endpoint_iterator, boost::bind(
                                                     &client::handle_connect,
                                                             this,
                                                             boost::asio::placeholders::error,
                                                             endpoint_iterator
                                                     )
                             );
    }
}

void client::handle_connect(const boost::system::error_code &error,
                            boost::asio::ip::tcp::resolver::iterator endpoint_iterator)
{
    if(!error){
        //success
        std::ostream os(&requestbuf);

        os << "Get" << path << " HTTP/1.0\r\n";
        os << "Host: " <<server<<"\r\n";
        os << "Accept: */*\r\n";
        os << "Connection: close\r\n\r\n";

        std::istream is(&requestbuf);
        std::string requestStr((std::istreambuf_iterator<char>(is)), std::istreambuf_iterator<char>());
        qDebug() << "Request buffer content:" << QString::fromStdString(requestStr);

        //write
        boost::asio::async_write(socket, requestbuf,
                                 boost::bind(
                                     &client::handle_write,
                                             this,
                                             boost::asio::placeholders::error
                                            )
                                 );
    }
    else{
        qDebug() << error.message().c_str() << Qt::endl;
    }
}

void client::handle_write(const boost::system::error_code &error)
{
    if(!error){
        boost::asio::async_read_until(socket, reponsebuf, "\r\n",
                                      boost::bind(
                                          &client::handle_readLine,
                                                  this,
                                                  boost::asio::placeholders::error
                                            )
                                    );

    }else{
        qDebug() << "handle write : " << error.message().c_str() << Qt::endl;
    }
}

void client::handle_readLine(const boost::system::error_code &error)
{
    if(!error){
        std::istream is(&reponsebuf);
        // std::string buff;
        // is >> buff;
        // qDebug() << "readLine handler >> " << buff.c_str()<<Qt::endl;

        std::string http_version;
        unsigned int status_code;
        std::string message;

        is >> http_version;
        is >> status_code;
        std::getline(is, message);

        //error check
        //1. http_version HTTP/

        //2.status_code != 200
        if(status_code != 200){
            return;
        }

        boost::asio::async_read_until(socket, reponsebuf, "\r\n\r\n",
                                      boost::bind(
                                          &client::handle_readHeader,
                                          this,
                                          boost::asio::placeholders::error
                                          )
                                      );
        //3.
    }else{
        qDebug() << "handle read : " << error.message().c_str() << Qt::endl;
    }
}

void client::handle_readHeader(const boost::system::error_code &error)
{
    std::istream istrm(&reponsebuf);

    std::string header;

    while(std::getline(istrm,header) && header != "\r"){
        //header
        oss << header << std::endl;
    }

    boost::asio::streambuf::const_buffers_type buf = reponsebuf.data();
    std::string str(boost::asio::buffers_begin(buf),
                    boost::asio::buffers_begin(buf)+reponsebuf.size());

    oss << str;

    qDebug() << oss.str().c_str() << Qt::endl;

    boost::asio::async_read(socket, reponsebuf,
                            boost::asio::transfer_at_least(1), //1바이트라도 읽으면
                            boost::bind(
                                &client::handle_readContent,
                                this,
                                boost::asio::placeholders::error
                                        )
                            );

}

void client::handle_readContent(const boost::system::error_code &error)
{
    if(!error){
        oss << &reponsebuf;

        boost::asio::async_read(socket, reponsebuf,
                                boost::asio::transfer_at_least(1), //1바이트라도 읽으면
                                boost::bind(
                                    &client::handle_readContent,
                                    this,
                                    boost::asio::placeholders::error
                                    )
                                );
    }else if(error == boost::asio::error::eof){
        qDebug() << oss.str().c_str() << Qt::endl;
        emit read_finish(QString::fromStdString(oss.str()));
    }else{
        emit read_failed(QString::fromStdString(error.message()));
    }

}





















