#include "Builder.h"
#include <sstream>
#include <iostream>

using namespace std;

/* === Computer === */
string Computer::ToString() const {
    ostringstream out;
    out << "Computer Configuration:\n";
    out << "CPU: " << cpu << "\n";
    out << "GPU: " << gpu << "\n";
    out << "RAM: " << ram << "\n";
    out << "Storage: " << storage << "\n";
    out << "Power Supply: " << powerSupply << "\n";
    out << "Case: " << caseType << "\n";
    out << "OS: " << os << "\n";
    out << "Peripherals: ";
    for (const auto& p : peripherals) {
        out << p << ", ";
    }
    return out.str();
}

/* === ComputerBuilder (base) === */
ComputerBuilder::ComputerBuilder() : computer(nullptr) {}

ComputerBuilder::~ComputerBuilder() {
    delete computer;
}

void ComputerBuilder::createNewComputer() {
    computer = new Computer();
}

Computer* ComputerBuilder::getComputer() {
    return computer;
}

/* === GamingComputerBuilder === */
void GamingComputerBuilder::buildCPU()        { computer->cpu = "Intel Core i9-13900K"; }
void GamingComputerBuilder::buildGPU()        { computer->gpu = "NVIDIA RTX 4090"; }
void GamingComputerBuilder::buildRAM()        { computer->ram = "64GB DDR5"; }
void GamingComputerBuilder::buildStorage()    { computer->storage = "2TB NVMe SSD"; }
void GamingComputerBuilder::buildPowerSupply(){ computer->powerSupply = "1000W Gold"; }
void GamingComputerBuilder::buildCase()       { computer->caseType = "CoolerMaster RGB Tower"; }
void GamingComputerBuilder::installOS()       { computer->os = "Windows 11 Pro"; }
void GamingComputerBuilder::addPeripherals()  { computer->peripherals = {"Gaming Mouse", "Mechanical Keyboard", "4K Monitor"}; }

/* === OfficeComputerBuilder === */
void OfficeComputerBuilder::buildCPU()        { computer->cpu = "Intel Core i5-12400"; }
void OfficeComputerBuilder::buildGPU()        { computer->gpu = "Integrated Graphics"; }
void OfficeComputerBuilder::buildRAM()        { computer->ram = "16GB DDR4"; }
void OfficeComputerBuilder::buildStorage()    { computer->storage = "512GB SSD"; }
void OfficeComputerBuilder::buildPowerSupply(){ computer->powerSupply = "500W Bronze"; }
void OfficeComputerBuilder::buildCase()       { computer->caseType = "Mini Tower"; }
void OfficeComputerBuilder::installOS()       { computer->os = "Windows 10 Home"; }
void OfficeComputerBuilder::addPeripherals()  { computer->peripherals = {"Basic Mouse", "Standard Keyboard", "1080p Monitor"}; }

/* === Director === */
void ComputerDirector::setBuilder(ComputerBuilder* b) {
    builder = b;
}

Computer* ComputerDirector::construct() {
    builder->createNewComputer();
    builder->buildCPU();
    builder->buildGPU();
    builder->buildRAM();
    builder->buildStorage();
    builder->buildPowerSupply();
    builder->buildCase();
    builder->installOS();
    builder->addPeripherals();
    return builder->getComputer();
}