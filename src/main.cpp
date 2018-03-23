#include "server.h"
#include <iostream>
#include <string>

using namespace http;
using namespace std;

int main(){
    cout << "Starting server ..." << endl;
    
    http::server server(8080);
    
    //application app; //app extends http::listener
    //server.on(app);

    server.acceptIncoming();

    return 0;
}