#include "addFinishedCourse.h"
#include "Course.h"

void addFinishedCourse()
{
	Course finishedCourse;

	if (finishedCourse.readCourse())
		finishedCourse.saveCourseToFile();
}
