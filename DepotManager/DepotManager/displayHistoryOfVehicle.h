#pragma once

#include "Course.h"
#include "Vehicle.h"
#include "Tramway.h"
#include "Bus.h"
#include "Trolleybus.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool displayHistoryOfVehicle();
ostream& operator <<(ostream&, Course&);
