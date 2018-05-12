#pragma once

#include "Tramway.h"


class Trolleybus : public Tramway
{
public:
	void readSpecialProperties() override;
	void readSpecialPropertiesFromFile(fstream&);
	void createId();
	void saveToFile() override;

	void resetSpecialProperties() override;

	void showInfo() override;

	Trolleybus();
	~Trolleybus();
};
