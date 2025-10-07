#pragma once 
#include "JSONstructs.hpp"
#include <stdio.h>

class JSONmanager
{
public:
    static JSONstructs::ClassificationLabelData generateClassificationLabels();
    static JSONstructs::XMLClassificationData generateXMLClassificationFonts();
    static JSONstructs::ClassificationSettings generateClassificationSettings();

    template<typename T>
    static std::string serialize(const T& JSONstruct);
};