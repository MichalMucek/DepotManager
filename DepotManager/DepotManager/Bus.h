#pragma once

#include "Vehicle.h"

using namespace std;

class Bus : public virtual Vehicle
{
protected:
	double fuelMax, fuelCurrent;

public:
	void readSpecialProperties() override;
	void readSpecialPropertiesFromFile(fstream&);
	void saveToFile() override;
	void createId();

	void resetSpecialProperties() override;

	void showInfo() override;

	Bus();
	~Bus();
};
