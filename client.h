#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <memory>
#include <thread>

class client
{
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

private:
    boost::asio::io_context iocontext;
    std::shared_ptr<boost::asio::io_context::work> work;
    std::thread worker;

    boost::asio::ip::tcp::resolver resolver;
    std::string server,path;
    boost::asio::ip::tcp::socket socket;
    boost::asio::streambuf requestbuf;
    boost::asio::streambuf reponsebuf;

};

#endif // CLIENT_H
