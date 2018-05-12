#pragma once

#include "Vehicle.h"

class Tramway : public virtual Vehicle
{
	/*
	-Num oznacza "Number" - iloœæ
	*/

protected:
	int trackGauge, //rozstaw szyn
	    supplyVoltage, //napiêcie zasilania
	    segmentsNum; //iloœæ wagonów

public:
	void readSpecialProperties() override;
	void readSpecialPropertiesFromFile(fstream&);
	void saveToFile() override;
	void createId();

	void resetSpecialProperties() override;

	void showInfo() override;

	Tramway();
	~Tramway();
};
