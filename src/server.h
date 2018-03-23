#ifndef _HTTP_SERVER
#define _HTTP_SERVER

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <regex>
#include <vector>
#include "response.h"
#include "request.h"
#include "httplistener.h"

namespace http{

class server {

    private:
        int port;
        boost::asio::io_service io_service;
        boost::asio::ip::tcp::acceptor acceptor;
        listener* controller;

        static std::string makeString(boost::asio::streambuf& buffer);
        static request parseRequest(std::string header);

    public:
        server(const int port);

        void acceptIncoming();

        void on(listener& ctrl);
};

}

#endif