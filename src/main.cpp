#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include "main/RequestsHandler/RequestsHandler.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>

#define ADDIN_API_CLASSIFICATION_LABELS_ENDPOINT "/api/v1/classification-labels"
#define ADDIN_API_CLASSIFICATION_XML_FONTS "/api/v1/xml-fonts"
#define ADDIN_API_CLASSIFICATION_SETTINGS "/api/v1/classification-settings"


std::string load_file(const std::string &path)
{
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) return "<h1>File not found</h1>";

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main()
{
    httplib::SSLServer svr("cert.pem", "key.pem");

    RequestsHandler reqHandler;

    svr.Get(ADDIN_API_CLASSIFICATION_LABELS_ENDPOINT, std::bind(&RequestsHandler::getClassificationLabels, &reqHandler, std::placeholders::_1, std::placeholders::_2));
    svr.Get(ADDIN_API_CLASSIFICATION_XML_FONTS, std::bind(&RequestsHandler::getClassificationFonts, &reqHandler, std::placeholders::_1, std::placeholders::_2));
    svr.Get(ADDIN_API_CLASSIFICATION_SETTINGS, std::bind(&RequestsHandler::getClassificationSettings, &reqHandler, std::placeholders::_1, std::placeholders::_2));

    svr.set_mount_point("/", "officeAddin/src");

    svr.set_logger([](const httplib::Request &req, const httplib::Response &res) {
        printf("[%s] %s %s %s -> %d\n", req.remote_addr.c_str(), req.method.c_str(), req.path.c_str(), req.version.c_str(), res.status);
    });

    std::cout << "Server Started!" << std::endl;
    svr.listen("0.0.0.0", 443);
    return 0;
}
