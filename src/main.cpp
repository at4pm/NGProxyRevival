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

void proxySend(CCHttpClient* self, CCHttpRequest* req) {
    auto uri = Mod::get()->getSettingValue<std::string>("server");
    
    std::string newUri = req->getUrl();
    newUri = str_replace(newUri, "audio.ngfiles.com", uri);
    newUri = str_replace(newUri, "http://", "https://");
        
    req->setUrl(newUri.c_str());
    self->send(req);
}

$execute {
    Mod::get()->hook(
        reinterpret_cast<void*>(
			geode::addresser::getNonVirtual(&cocos2d::extension::CCHttpClient::send)
        ),
        &proxySend,
        "cocos2d::extension::CCHttpClient::send",
        tulip::hook::TulipConvention::Thiscall
    );
}