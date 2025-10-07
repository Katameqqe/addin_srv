#pragma once

#include "../../json/serialization.hpp"

namespace JSONstructs
{
struct ClassificationLabelData
{
    ClassificationLabelData(std::vector<std::string> aNames):
        names(aNames) {}
    std::vector<std::string> names;

    PBNJSON_SERIALIZE( ClassificationLabelData,
        (std::vector<std::string>, names)
    )
};

struct FontData
{
    FontData(std::string aFontName, std::string aFontColor, std::string aFontSize, std::string aText):
        fontName(aFontName),
        fontColor(aFontColor),
        fontSize(aFontSize),
        text(aText) {}

    std::string fontName;
    std::string fontColor;
    std::string fontSize;
    std::string text;

    PBNJSON_SERIALIZE( FontData,
        (std::string, fontName)
        (std::string, fontColor)
        (std::string, fontSize)
        (std::string, text)
    )
};

struct WaterMarkData
{
    WaterMarkData(std::string aFontName, std::string aFontColor, std::string aFontSize, std::string aRotation, std::string aTransparency, std::string aText):
        fontName(aFontName),
        fontColor(aFontColor),
        fontSize(aFontSize),
        rotation(aRotation),
        transparency(aTransparency),
        text(aText) {}

    WaterMarkData(FontData &aFD, std::string aRotation, std::string aTransparency):
        fontName(aFD.fontName),
        fontColor(aFD.fontColor),
        fontSize(aFD.fontSize),
        rotation(aRotation),
        transparency(aTransparency),
        text(aFD.text) {}

    std::string fontName;
    std::string fontColor;
    std::string fontSize;
    std::string rotation;
    std::string transparency;
    std::string text;

    PBNJSON_SERIALIZE( WaterMarkData,
        (std::string, fontName)
        (std::string, fontColor)
        (std::string, fontSize)
        (std::string, rotation)
        (std::string, transparency)
        (std::string, text)
    )
};

struct XMLClassificationData
{
    XMLClassificationData(std::vector<FontData> aHDR, std::vector<FontData> aFTR, WaterMarkData aWM):
        hdr(aHDR),
        ftr(aFTR),
        wm(aWM) {}

    std::vector<FontData> hdr;
    std::vector<FontData> ftr;
    WaterMarkData wm;

    PBNJSON_SERIALIZE( XMLClassificationData,
        (std::vector<FontData>, hdr)
        (std::vector<FontData>, ftr)
        (WaterMarkData, wm)
    )
};

struct ClassificationSettings
{
    ClassificationSettings(std::string aName, std::vector<std::string> aValues, std::vector<FontData> aHdr, std::vector<FontData> aFtr, WaterMarkData aWm):
        name(aName),
        values(aValues),
        hdr(aHdr),
        ftr(aFtr),
        wm(aWm) {}
    ClassificationSettings(std::string aName, std::vector<std::string> aValues, XMLClassificationData aXMLData):
        name(aName),
        values(aValues),
        hdr(aXMLData.hdr),
        ftr(aXMLData.ftr),
        wm(aXMLData.wm) {}

    std::string name;
    std::vector<std::string> values;
    std::vector<FontData> hdr;
    std::vector<FontData> ftr;
    WaterMarkData wm;

    PBNJSON_SERIALIZE( ClassificationSettings,
        (std::string, name)
        (std::vector<std::string>, values)
        (std::vector<FontData>, hdr)
        (std::vector<FontData>, ftr)
        (WaterMarkData, wm)
    )
};

}