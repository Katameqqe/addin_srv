#include "JSONmanager.hpp"

JSONstructs::XMLClassificationData JSONmanager::generateXMLClassificationFonts()
{
    JSONstructs::FontData hdr("Arial", "0000FF", "14", "SECRET");
    JSONstructs::FontData ftr(hdr);
    JSONstructs::WaterMarkData wm(hdr, "45", "1000");

    JSONstructs::XMLClassificationData resultJson(
        std::vector<JSONstructs::FontData>{hdr},
        std::vector<JSONstructs::FontData>{ftr},
        wm
    );

    return resultJson;
}

JSONstructs::ClassificationLabelData JSONmanager::generateClassificationLabels()
{
    JSONstructs::ClassificationLabelData resultJson(
        std::vector<std::string>{
            "Defualt",
            "Resurected",
            "Listed",
            "Hollowed",
            "Personal"
    });
    return resultJson;
}

JSONstructs::ClassificationSettings JSONmanager::generateClassificationSettings()
{
    JSONstructs::FontData hdr("Arial", "0000FF", "14", "SECRET");
    JSONstructs::FontData ftr(hdr);
    JSONstructs::WaterMarkData wm(hdr, "45", "1000");

    JSONstructs::ClassificationSettings resultJson(
        "Default",
        std::vector<std::string>{
            "Defualt",
            "Resurected",
            "Listed",
            "Hollowed",
            "Personal"
        },
        std::vector<JSONstructs::FontData>{hdr},
        std::vector<JSONstructs::FontData>{ftr},
        wm
    );

    return resultJson;
}

template<typename T>
std::string JSONmanager::serialize(const T& JSONstruct)
{
    std::string resultString;
    pbnjson::pbnjson_serialize(JSONstruct, resultString);
    return resultString;
}

template std::string JSONmanager::serialize<JSONstructs::ClassificationLabelData>(const JSONstructs::ClassificationLabelData&);
template std::string JSONmanager::serialize<JSONstructs::XMLClassificationData>(const JSONstructs::XMLClassificationData&);
template std::string JSONmanager::serialize<JSONstructs::ClassificationSettings>(const JSONstructs::ClassificationSettings&);