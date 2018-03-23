#ifndef _HTTP_LISTENER
#define _HTTP_LISTENER

#include "response.h"
#include "request.h"

namespace http {

class listener {
    public:
        virtual response onRequest(request& req);
}; 

}
#endif