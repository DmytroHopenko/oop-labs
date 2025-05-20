#ifndef BUILDER_H
#define BUILDER_H

#pragma once
#include <string>
#include <vector>

using namespace std;

class Computer {
public:
    string cpu;
    string gpu;
    string ram;
    string storage;
    string powerSupply;
    string caseType;
    string os;
    vector<string> peripherals;

    string ToString() const;
};

class ComputerBuilder {
protected:
    Computer* computer;

public:
    ComputerBuilder();
    virtual ~ComputerBuilder();

    void createNewComputer();
    Computer* getComputer();

    virtual void buildCPU() = 0;
    virtual void buildGPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;
    virtual void buildPowerSupply() = 0;
    virtual void buildCase() = 0;
    virtual void installOS() = 0;
    virtual void addPeripherals() = 0;
};

class GamingComputerBuilder : public ComputerBuilder {
public:
    void buildCPU() override;
    void buildGPU() override;
    void buildRAM() override;
    void buildStorage() override;
    void buildPowerSupply() override;
    void buildCase() override;
    void installOS() override;
    void addPeripherals() override;
};

class OfficeComputerBuilder : public ComputerBuilder {
public:
    void buildCPU() override;
    void buildGPU() override;
    void buildRAM() override;
    void buildStorage() override;
    void buildPowerSupply() override;
    void buildCase() override;
    void installOS() override;
    void addPeripherals() override;
};

class ComputerDirector {
private:
    ComputerBuilder* builder;

public:
    void setBuilder(ComputerBuilder* b);
    Computer* construct();
};


#endif //BUILDER_H
