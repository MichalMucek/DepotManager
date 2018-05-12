#pragma once

#include <string>

using namespace std;

enum Units_of_power
{
	W,
	//Watt
	kW,
	//Kilowatt
	MECHANICAL_hp,
	//Koñ mechaniczny 
	ELECTRICAL_hp
}; //Elektryczny koñ mechaniczny
enum Units_of_speed { kmph, mph };

enum Status_of_vehicle
{
	ON_ROUTE,
	READY_FOR_THE_COURSE,
	IN_MAINTENANCE,
	DAMAGED
};

class Vehicle
{
	/*
	-Num oznacza "Number" - iloœæ
	*/

protected:
	string id;

	string name, manufacturer, designation;
	int yearOfProduction;

	int enginesNum;
	Units_of_power unitOfPower;
	double* enginesPower;

	double speedMax;
	Units_of_speed unitOfSpeed;

	int seatsNum,
	    standingPlacesNum,
	    passenegersMax;

	int weight,
	    length,
	    width,
	    height;

	int entriesNum,
	    *floorHeights;

	Status_of_vehicle status;

	string createId();

public:
	void readNameManufacturerAndDesignation();
	void readEnginesPower();
	void readSpeedMax();
	void readPassenegerNum();
	void readMeasurements();
	void readStatus();
	virtual void readSpecialProperties();

	void resetNameEtc();
	void resetEnginesPower();
	void resetSpeedMax();
	void resetPassenegersNum();
	void resetMeasurements();
	virtual void resetSpecialProperties();

	virtual void saveToFile();

	void sayStatus();
	virtual void showInfo();

	friend bool displayAllVehicles();
	friend bool editVehicle(Vehicle*);
	friend bool displayHistoryOfVehicle(string);

	template <class VehicleType>
	friend VehicleType readFromFileToObject(string);

	template <class VehicleType>
	friend void verifyAndSave(VehicleType&);

	Vehicle();
	~Vehicle();
};
