#include "Builder.h"
#include "Singleton.h"
#include <iostream>

int main() {
    cout << "-------------------------\n";
    cout << "Builder\n";
    cout << "-------------------------\n";
    ComputerDirector director;

    GamingComputerBuilder gaming;
    OfficeComputerBuilder office;

    director.setBuilder(&gaming);
    Computer* gamerPC = director.construct();
    cout << gamerPC->ToString() << "\n";
    delete gamerPC;

    cout << "-------------------------\n";

    director.setBuilder(&office);
    Computer* officePC = director.construct();
    cout << officePC->ToString() << "\n";
    delete officePC;

    cout << "-------------------------\n";
    cout << "Singleton\n";
    cout << "-------------------------\n";

    ConfigManager* config = ConfigManager::GetInstance();

    cout << "App Mode: " << config->GetValue("mode") << endl;
    cout << "Language: " << config->GetValue("language") << endl;

    config->SetValue("language", "uk");
    config->SetValue("theme", "light");

    cout << "Updated Language: " << config->GetValue("language") << endl;
    cout << "Updated Theme: " << config->GetValue("theme") << endl;

    ConfigManager* anotherRef = ConfigManager::GetInstance();
    cout << "[Another Reference] Theme: " << anotherRef->GetValue("theme") << endl;

    return 0;
}
