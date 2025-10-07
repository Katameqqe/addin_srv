#pragma once
#include "../../httplib.h"
#include "../../JSON/JSONstructs.hpp"
#include "../../JSON/JSONmanager.hpp"

class RequestsHandler
{
public:
    RequestsHandler();
    void getClassificationLabels(const httplib::Request &req, httplib::Response &res);
    void getClassificationFonts(const httplib::Request &req, httplib::Response &res);
    void getClassificationSettings(const httplib::Request &req, httplib::Response &res);
private:
    std::string _XMLClassificationFonts;
    std::string _classificationLabels;
    std::string _classificationSettings;
};