#include "RequestsHandler.hpp"

RequestsHandler::RequestsHandler()
{
    JSONstructs::ClassificationLabelData a = JSONmanager::generateClassificationLabels();
    JSONstructs::XMLClassificationData b = JSONmanager::generateXMLClassificationFonts();
    JSONstructs::ClassificationSettings c = JSONmanager::generateClassificationSettings();
    _classificationLabels = JSONmanager::serialize(a);
    _XMLClassificationFonts = JSONmanager::serialize(b);
    _classificationSettings = JSONmanager::serialize(c);
}

void RequestsHandler::getClassificationLabels(const httplib::Request &req, httplib::Response &res)
{
    res.set_content(_classificationLabels, "application/json");
    res.set_header("Access-Control-Allow-Origin","https://192.168.128.4:443");
}

void RequestsHandler::getClassificationFonts(const httplib::Request &req, httplib::Response &res)
{
    res.set_content(_XMLClassificationFonts, "application/json");
    res.set_header("Access-Control-Allow-Origin","https://192.168.128.4:443");
}

void RequestsHandler::getClassificationSettings(const httplib::Request &req, httplib::Response &res)
{
    res.set_content(_classificationSettings, "application/json");
    res.set_header("Access-Control-Allow-Origin","https://192.168.128.4:443");
}
