#include "server.h"

using boost::asio::ip::tcp;

namespace http{

server::server(const int port) : port(port), io_service(), acceptor(io_service, tcp::endpoint(tcp::v4(), port)), controller(NULL){

}

std::string server::makeString(boost::asio::streambuf& buffer){
    return {
        boost::asio::buffers_begin(buffer.data()),
        boost::asio::buffers_end(buffer.data())
    };
}

request server::parseRequest(std::string header){
    //Get method
    int pos = header.find(' ');
    std::string method = header.substr(0, pos);
    header = header.substr(pos + 1, header.length() - pos - 1);

    //Get uri
    pos = header.find(' ');
    std::string uri = header.substr(0, pos);
    header = header.substr(pos + 1, header.length() - pos - 1);

    //Get version
    pos = header.find(' ');
    std::string version = header.substr(0, pos);
    header = header.substr(pos + 1, header.length() - pos - 1);

    return {method,uri,version};
}

void server::acceptIncoming(){
    //Accept
    tcp::socket socket(this->io_service);
    this->acceptor.accept(socket);

    //Read message
    boost::asio::streambuf rbuffer;
    std::size_t bytes_transfered = boost::asio::read_until(socket, rbuffer,"\r\n");
    std::string input = server::makeString(rbuffer);
    rbuffer.consume(bytes_transfered);

    //Parse message
    request req = parseRequest(input);
    std::cout << req.method << " recieved for " << req.uri << std::endl;

    //Craft result
    response res = response::error;
    if(this->controller != NULL){
        res = (this->controller)->onRequest(req);
    }

    //Output response
    boost::system::error_code ignored_error;
    boost::asio::write(socket, boost::asio::buffer(res.encode()), ignored_error);
}

void server::on(listener& ctrl){
    this->controller = &ctrl;
}

}