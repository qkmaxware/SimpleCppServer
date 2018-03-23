#ifndef _HTTP_RESPONSE
#define _HTTP_RESPONSE

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

namespace http{

namespace mimes {

    //Text
    static std::string PLAIN_TEXT("text/plain");
    static std::string HTML("text/html");
    static std::string CSS("text/css");
    static std::string JAVASCRIPT("text/javascript");
    //Images
    static std::string JPEG("image/jpeg");
    static std::string PNG("image/png");
    static std::string GIF("image/gif");
    static std::string BMP("image/bmp");
    static std::string WEBP("image/webp");
    //Audio
    static std::string MIDI("audio/midi");
    static std::string MPEG("audio/mpeg");
    static std::string WEBM_AUDIO("audio/webm");
    static std::string OGG_AUDIO("audio/ogg");
    static std::string WAV("audio/wav");
    //Video
    static std::string MP4("video/mp4");
    static std::string WEBM_VIDEO("video/webm");
    static std::string OGG_VIDEO("video/ogg");
    //Applications
    static std::string OCTET_STREAM("application/octet-stream");
    static std::string PKCS12("application/pkcs12");
    static std::string XHTML_XML("application/xhtml+xml");
    static std::string XML("applicaion/xml");
    static std::string PDF("application/pdf");
    static std::string JSON("application/json");

}

namespace codes {

    static std::string INFO_100("100 Continue");
    static std::string INFO_101("101 Switching Protocols");
    static std::string INFO_102("102 Processing");
    static std::string INFO_103("103 Early Hints");
    static std::string SUCCESS_200("200 Ok");
    static std::string SUCCESS_201("201 Created");
    static std::string SUCCESS_202("202 Accepted");
    static std::string SUCCESS_203("203 Non-Authoritative Information");
    static std::string SUCCESS_204("204 No Content");
    static std::string SUCCESS_205("205 Reset Content");
    static std::string SUCCESS_206("206 Partial Content");
    static std::string SUCCESS_207("207 Multi-Status");
    static std::string SUCCESS_208("208 Already Reported");
    static std::string SUCCESS_226("226 IM Used");
    static std::string REDIRECT_300("300 Multiple Choices");
    static std::string REDIRECT_302("302 Found");
    static std::string REDIRECT_303("303 See Other");
    static std::string REDIRECT_304("304 Not Modified");
    static std::string REDIRECT_305("305 Use Proxy");
    static std::string REDIRECT_306("306 Switch Proxy");
    static std::string REDIRECT_307("307 Temporary Redirect");
    static std::string REDIRECT_308("308 Permanent Redirect");
    static std::string CLIENT_ERR_400("400 Bad Request");
    static std::string CLIENT_ERR_401("401 Unauthorized");
    static std::string CLIENT_ERR_402("402 Payment Required");
    static std::string CLIENT_ERR_403("403 Forbidden");
    static std::string CLIENT_ERR_404("404 NotFound");
    static std::string CLIENT_ERR_405("405 Method Not Allowed");
    static std::string CLIENT_ERR_406("406 Not Acceptable");
    static std::string CLIENT_ERR_407("407 Proxy Authentication Required");
    static std::string CLIENT_ERR_408("408 Request Timeout");
    static std::string CLIENT_ERR_409("409 Conflict");
    static std::string CLIENT_ERR_410("410 Gone");
    static std::string CLIENT_ERR_411("411 Length Required");
    static std::string CLIENT_ERR_412("412 Precondition Failed");
    static std::string CLIENT_ERR_413("413 Payload Too Large");
    static std::string CLIENT_ERR_414("414 URI Too Long");
    static std::string CLIENT_ERR_415("415 Unsupported Media Type");
    static std::string CLIENT_ERR_416("416 Range Not Satisfiable");
    static std::string CLIENT_ERR_417("417 Expectation Failed");
    static std::string CLIENT_ERR_418("418 I'm a Teapot");
    static std::string CLIENT_ERR_421("421 Misdirected Request");
    static std::string CLIENT_ERR_422("422 Unprocessable Entity");
    static std::string CLIENT_ERR_423("423 Locked");
    static std::string CLIENT_ERR_424("424 Failed Dependency");
    static std::string CLIENT_ERR_426("426 Upgrade Required");
    static std::string CLIENT_ERR_428("428 Precondition Required");
    static std::string CLIENT_ERR_429("429 Too Many Requests");
    static std::string CLIENT_ERR_431("431 Request Header Fields Too Large");
    static std::string CLIENT_ERR_451("451 Unavailable For Legal Reasons");
    static std::string SERVER_ERR_500("500 Internal Server Error");
    static std::string SERVER_ERR_501("501 Not Implemented");
    static std::string SERVER_ERR_502("502 Bad Gateway");
    static std::string SERVER_ERR_503("503 Service Unavailable");
    static std::string SERVER_ERR_504("504 Gateway Timeout");
    static std::string SERVER_ERR_505("505 HTTP Version Not Supported");
    static std::string SERVER_ERR_506("506 Variant Also Negotiates");
    static std::string SERVER_ERR_507("507 Insufficient Storage");
    static std::string SERVER_ERR_508("508 Loop Detected");
    static std::string SERVER_ERR_510("510 Not Extended");
    static std::string SERVER_ERR_511("511 Network Authentication Required");

}

class response {

    private:
        std::string status;
        std::string contentType;
        std::string message;
        std::vector<std::string> additionalHeaders;

    public:
        response();
        response(std::string type, std::string msg);
        response(std::string status, std::string type, std::string msg);

        static const response error;

        void setMime(std::string mimeType);
        void setStatus(std::string status);
        void setMessage(std::string message);
        void addHeader(std::string header);

        std::string encode();

};

}

#endif