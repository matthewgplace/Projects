#include "telescope.h"



telescope::telescope(float d, float f) {
	diameter = d;
	focal_length = f;
}

float telescope::getRadius() const {
	return diameter / 2.0f;
}

float telescope::getDiameter() const {
	return diameter;
}

float telescope::getFocalLength() const {
	return focal_length;
}

float telescope::getFRatio() const {
	return focal_length / diameter;
}

void telescope::setDiameter(float d) {
	diameter = d;
}

void telescope::setFocalLength(float f) {
	focal_length = f;
}