#ifndef _HTTP_REQUEST
#define _HTTP_REQUEST

namespace http{

struct request {
    std::string method;
    std::string uri;
    std::string version;
};

}

#endif