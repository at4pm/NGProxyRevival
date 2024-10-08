#include <Geode/Geode.hpp>
#include <Geode/modify/CCHttpClient.hpp>

using namespace geode::prelude;

std::string str_replace(std::string string, std::string toReplace, std::string replacement) {
    size_t pos = string.find(toReplace);
    while (pos != std::string::npos) {
        string.replace(pos, toReplace.size(), replacement);
        pos = string.find(toReplace, pos + replacement.size());
    }

    return string;
}

class $modify(CCHttpClient) {
    void send(CCHttpRequest* req) {
        auto serverUrl = Mod::get()->getSettingValue<std::string>("serverr");

        std::string newUrl = req->getUrl();

        if (serverUrl.find("https://") != std::string::npos) {
            newUrl = str_replace(newUrl, "https://audio.ngfiles.com", serverUrl);
        } else {
            newUrl = str_replace(newUrl, "audio.ngfiles.com", serverUrl);
            newUrl = str_replace(newUrl, "audio.ngfiles.com", serverUrl);
        }

        req->setUrl(newUrl.c_str());
        return CCHttpClient::send(req);
    }
};