#include "lens.h"
#include <cmath>



lens::lens(float d, float t, float f, float o, float n) {
	diameter = d;
	thickness = t;
	focal_length = f;
	object_distance = o;
	refractive_index = n;
}

float lens::getRadius() const {
	return diameter / 2.0f;
}

float lens::getDiameter() const {
	return diameter;
}

float lens::getThickness() const {
	return thickness;
}

float lens::getFocalLength() const {
	return focal_length;
}

float lens::getObjectDistance() const {
	return object_distance;
}

float lens::getImageDistance() const {
	if (focal_length != object_distance) {
		return (focal_length * object_distance) / (object_distance - focal_length);
	}
	else {
		return 1000000000.0f;
	}
	
}

float lens::getRefractiveIndex() const {
	return refractive_index;
}

float lens::getFRatio() const {
	return focal_length / diameter;
}

float lens::getPrinciplePlane() const {
	return -focal_length * (1.0f - sqrtf(1.0f - thickness / (refractive_index * focal_length)));
}

float lens::getCenterDistance() const {
	return object_distance + thickness / 2.0f - focal_length * (1.0f - sqrtf(1.0f - thickness / (refractive_index * focal_length)));
}

float lens::getLastPlaneDistance() const {
	return object_distance + thickness - 2.0f * focal_length * (1.0f - sqrtf(1.0f - thickness / (refractive_index * focal_length)));
}

void lens::setDiameter(float d) {
	diameter = d;
}

void lens::setThickness(float t) {
	thickness = t;
}

void lens::setFocalLength(float f) {
	focal_length = f;
}

void lens::setObjectDistance(float o) {
	object_distance = o;
}

void lens::setRefractiveIndex(float n) {
	refractive_index = n;
}
