#include "diffractiongrating.h"



diffractiongrating::diffractiongrating(float w, float h, float d, float o, float bw, float ba, float g) {
	width = w;
	height = h;
	depth = d;
	diffraction_order = o;
	blaze_wavelength = bw;
	blaze_angle = ba;
	grooves_per_mm = g;
}

float diffractiongrating::getWidth() const {
	return width;
}

float diffractiongrating::getHeight() const {
	return height;
}

float diffractiongrating::getDepth() const {
	return depth;
}

float diffractiongrating::getOrder() const {
	return diffraction_order;
}

float diffractiongrating::getBlazeWave() const {
	return blaze_wavelength;
}

float diffractiongrating::getBlazeAngle() const {
	return blaze_angle;
}

float diffractiongrating::getGrooves() const {
	return grooves_per_mm;
}

void diffractiongrating::setWidth(float w) {
	width = w;
}

void diffractiongrating::setHeight(float h) {
	height = h;
}

void diffractiongrating::setDepth(float d) {
	depth = d;
}

void diffractiongrating::setOrder(float o) {
	diffraction_order = o;
}

void diffractiongrating::setBlazeWave(float bw) {
	blaze_wavelength = bw;
}

void diffractiongrating::setBlazeAngle(float ba) {
	blaze_angle = ba;
}

void diffractiongrating::setGrooves(float g) {
	grooves_per_mm = g;
}