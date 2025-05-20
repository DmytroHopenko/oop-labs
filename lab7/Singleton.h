#ifndef SINGLETON_H
#define SINGLETON_H

#pragma once
#include <string>
#include <unordered_map>

using namespace std;

class ConfigManager {
private:
    static ConfigManager* _instance;
    unordered_map<string, string> _config;

    ConfigManager();

    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;

public:
    static ConfigManager* GetInstance();

    void LoadDefaults();
    void SetValue(const string& key, const string& value);
    string GetValue(const string& key) const;
};


#endif //SINGLETON_H
