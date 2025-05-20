#include "Singleton.h"

ConfigManager* ConfigManager::_instance = nullptr;

ConfigManager::ConfigManager() {
    LoadDefaults();
}

ConfigManager* ConfigManager::GetInstance() {
    if (!_instance) {
        _instance = new ConfigManager();
    }
    return _instance;
}

void ConfigManager::LoadDefaults() {
    _config["mode"] = "debug";
    _config["language"] = "en";
    _config["theme"] = "dark";
}

void ConfigManager::SetValue(const string& key, const string& value) {
    _config[key] = value;
}

string ConfigManager::GetValue(const string& key) const {
    auto it = _config.find(key);
    if (it != _config.end()) {
        return it->second;
    }
    return "undefined";
}
