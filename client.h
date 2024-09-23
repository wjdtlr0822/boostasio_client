#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QString>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <memory>
#include <thread>

class client : public QObject
{
    Q_OBJECT
public:
    client();
    virtual ~client();

    void Get(const QString& url, const QString& path);
    void handle_resolve(const boost::system::error_code &error,
                        boost::asio::ip::tcp::resolver::iterator endpoint_iterator);

    void handle_connect(const boost::system::error_code &error,
                        boost::asio::ip::tcp::resolver::iterator endpoint_iterator);

    void handle_write(const boost::system::error_code &error);
    void handle_readLine(const boost::system::error_code &error);
    void handle_readHeader(const boost::system::error_code &error);
    void handle_readContent(const boost::system::error_code &error);

private:
    boost::asio::io_context iocontext;
    std::shared_ptr<boost::asio::io_context::work> work;
    std::thread worker;

    std::ostringstream oss;

    boost::asio::ip::tcp::resolver resolver;
    std::string server,path;
    boost::asio::ip::tcp::socket socket;
    boost::asio::streambuf requestbuf;
    boost::asio::streambuf reponsebuf;

signals:
    void read_finish(const QString& msg);
    void read_failed(const QString& msg);

};

#endif // CLIENT_H
