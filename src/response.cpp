#include "response.h"

namespace http{

response::response() : status("200 OK"), contentType("text/html"), message(""), additionalHeaders(){

}

response::response(std::string type, std::string msg) : status("200 OK"),contentType(type), message(msg), additionalHeaders(){

}

response::response(std::string status, std::string type, std::string msg) : status(status),contentType(type), message(msg), additionalHeaders(){

}

const response response::error("404 NotFound", "text/html", "Resource not found");

void response::setMime(std::string mimeType){
    this->contentType = mimeType;
}

void response::setStatus(std::string status){
    this->status = status;
}

void response::setMessage(std::string message){
    this->message = message;
}

void response::addHeader(std::string header){
    this->additionalHeaders.push_back(header);
}

std::string response::encode(){
    //Default headers
    std::stringstream sb;
    sb << "HTTP/1.0 " << this->status << "\r\n";
    sb << "Content-Length: " << this->message.length() << "\r\n";
    sb << "Content-Type: " << this->contentType << "\r\n";

    //Additional headers
    for(std::vector<std::string>::iterator it = this->additionalHeaders.begin(); it != this->additionalHeaders.end(); it++) {
        sb << (*it) << "\r\n";
    }
    //-----------------

    //Message 
    sb << "\r\n";
    sb << this->message;

    return sb.str();
}

}