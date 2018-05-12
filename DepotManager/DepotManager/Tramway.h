#pragma once

#include "Vehicle.h"

class Tramway : public virtual Vehicle
{
	/*
	-Num oznacza "Number" - ilo��
	*/

protected:
	int trackGauge, //rozstaw szyn
	    supplyVoltage, //napi�cie zasilania
	    segmentsNum; //ilo�� wagon�w

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
