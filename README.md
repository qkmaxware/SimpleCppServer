# SimpleCppServer
Extremely primitive web-server example using Boost::asio tcp sockets

# Example useage
```cpp
#include "server.h"
#include "httplistener.h"
#include <iostream>
#include <string>

using namespace http;
using namespace std;

class app: public http::listener {
    public:
        response onRequest(request& req) override {
           //Handle request (FORMAT) (RESOURCE) (HTTP VERSION)
           //Ex. GET / HTTP/1.1
           return response();
        }
}

int main(){
    cout << "Starting server ..." << endl;
    
    //Create server on port 8080
    http::server server(8080);
    
    //Create an app to handle http requests
    app myapp;
    
    //Tell the server to delegate all inbound requests to the app's handler
    server.on(myapp);

    //Accept and handle inbound requests until loop is broken.
    while(true){
        server.acceptIncoming();
    }
    
    return 0;
}
```
