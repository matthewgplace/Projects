#include "classicastrospectrograph.h"
#include <cmath>


classicastrospectrograph::classicastrospectrograph(float minw, float maxw, float td,
	float tf, float cd, float cf, float cl, float gw, float gp, float ga, float gg,
	float go, float fd, float ff, float fp, float fl, float fi, float dw, float p) {
	
	minimum_wavelength = minw;
	maximum_wavelength = maxw;
	telescope_diameter = td;
	telescope_focal_length = tf;
	collimator_diameter = cd;
	collimator_focal_length = cf;
	collimator_lastplane = cl;
	grating_width = gw;
	grating_position = gp;
	grating_angle = ga;
	grating_grooves = gg;
	grating_order = go;
	focuser_diameter = fd;
	focuser_focal_length = ff;
	focuser_position = fp;
	focuser_lastplane = fl;
	focuser_image_distance = fi;
	detector_width = dw;
	pixel_size = p;
}

float classicastrospectrograph::getCenWavelength() const {
	return (minimum_wavelength + maximum_wavelength) / 2.0f;
}

float classicastrospectrograph::getIncidentAngle() const {
	if (grating_angle >= 0.0f) {
		return 3.1415926535897932384626f / 2.0f - grating_angle;
	}
	else {
		return -3.1415926535897932384626f / 2.0f - grating_angle;
	}
}

float classicastrospectrograph::getCenDiffractAngle() const {
	return asinf(grating_order * getCenWavelength() *
		grating_grooves * 1000.0f - sinf(getIncidentAngle()));
}

float classicastrospectrograph::getMaxDiffractAngle() const {
	return asinf(grating_order * maximum_wavelength *
		grating_grooves * 1000.0f - sinf(getIncidentAngle()));
}

float classicastrospectrograph::getMinDiffractAngle() const {
	return asinf(grating_order * minimum_wavelength *
		grating_grooves * 1000.0f - sinf(getIncidentAngle()));
}

float classicastrospectrograph::getInitialBeamWidth() const {
	return (telescope_diameter * collimator_focal_length) / telescope_focal_length;
}

float classicastrospectrograph::getCollimatedRadius() const {
	if (getInitialBeamWidth() >= collimator_diameter) {
		return collimator_diameter / 2.0f;
	}
	else {
		return getInitialBeamWidth() / 2.0f;
	}
}

float classicastrospectrograph::getSpectralRangeMin() const {
	float dispersion = fabsf((pixel_size * 1000.0f * cosf(getCenDiffractAngle())) /
		(grating_grooves * focuser_focal_length));

	return getCenWavelength() * 1E9f - 0.5f * dispersion * detector_width * 1000.0f / pixel_size;
}

float classicastrospectrograph::getSpectralRangeMax() const {
	float dispersion = fabsf((pixel_size * 1000.0f * cosf(getCenDiffractAngle())) /
		(grating_grooves * focuser_focal_length));

	return getCenWavelength() * 1E9f + 0.5f * dispersion * detector_width * 1000.0f / pixel_size;
}

float classicastrospectrograph::getResolvingPower() const {
	float diffracteddispersion = (cosf(getCenDiffractAngle()) / cosf(getIncidentAngle() + 0.000001f)) *
		((collimator_focal_length * telescope_diameter) / telescope_focal_length) +
		(focuser_position * detector_width) / focuser_focal_length;

	float afactor = cosf(getIncidentAngle()) / cosf(getCenDiffractAngle() + 0.000001f); //anamorphic factor, making sure to never divide by 0.

	float FWHM = sqrtf(powf(afactor * focuser_focal_length / collimator_focal_length, 2.0f) *
		(powf(2E-5f, 2.0f) * powf(telescope_focal_length, 2.0f) +
		powf(0.01f, 2.0f)) + powf(0.015f, 2.0f) + powf(getCenWavelength() * 1000.0f * 
		focuser_focal_length / diffracteddispersion, 2.0f) + powf(pixel_size * 0.001f, 2.0f));

	return afactor * focuser_focal_length * (tanf(getIncidentAngle()) + sinf(getCenDiffractAngle()) /
		cosf(getIncidentAngle() + 0.000001f)) / FWHM;
}

float classicastrospectrograph::getResolution() const {
	return getCenWavelength() / getResolvingPower();
}

float classicastrospectrograph::getDiffractedDispersion() const {
	return (cosf(getCenDiffractAngle()) / cosf(getIncidentAngle() + 0.000001f)) *
		((collimator_focal_length * telescope_diameter) / telescope_focal_length) +
		(focuser_position * detector_width) / focuser_focal_length;
}

float classicastrospectrograph::getFocuserAngle() const {
	return getCenDiffractAngle() - getIncidentAngle() + 3.1415926535897932384626f / 2.0f;
}

float classicastrospectrograph::getGratingLightMajAxis() const {
	float beamradius = getCollimatedRadius() / sinf(grating_angle + 0.000001f);
	
	return beamradius * sinf(grating_angle - getFocuserAngle());
}

float classicastrospectrograph::getGratingAngle() const {
	return grating_angle;
}

float classicastrospectrograph::getDetectorWidth() const {
	return detector_width;
}

float classicastrospectrograph::getPixelSize() const {
	return pixel_size;
}

float classicastrospectrograph::getDistSourceToGrating() const {
	return collimator_lastplane + grating_position;
}

float classicastrospectrograph::getGratingTopX() const {
	return collimator_lastplane + grating_position - grating_width / 2.0f * cosf(grating_angle);
}

float classicastrospectrograph::getGratingBottomX() const {
	return collimator_lastplane + grating_position + grating_width / 2.0f * cosf(grating_angle);
}

float classicastrospectrograph::getGratingY() const {
	return grating_width / 2.0f * sinf(grating_angle);
}

float classicastrospectrograph::getGratingRayTopX() const {
	float distanceshift = getCollimatedRadius() * cosf(grating_angle) / sinf(grating_angle + 0.000001f);
	return collimator_lastplane + grating_position - distanceshift;
}

float classicastrospectrograph::getGratingRayY() const {
	return getCollimatedRadius();
}

float classicastrospectrograph::getGratingRayBottomX() const {
	float distanceshift = getCollimatedRadius() * cosf(grating_angle) / sinf(grating_angle + 0.000001f);
	return collimator_lastplane + grating_position + distanceshift;
}

float classicastrospectrograph::getFocuserCenterX() const {
	return getDistSourceToGrating() - (focuser_position +
		((focuser_lastplane - focuser_position) / 2.0f)) * 
		cosf(getCenDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserCenterY() const {
	return (focuser_position + ((focuser_lastplane - focuser_position) / 2.0f)) *
		sinf(getCenDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserTopX() const {
	return getDistSourceToGrating() - (focuser_position +
		((focuser_lastplane - focuser_position) / 2.0f)) *
		cosf(getCenDiffractAngle() - getIncidentAngle()) -
		focuser_diameter * 0.5f * cosf(getFocuserAngle());
}

float classicastrospectrograph::getFocuserTopY() const {
	return (focuser_position + ((focuser_lastplane - focuser_position) / 2.0f)) *
		sinf(getCenDiffractAngle() - getIncidentAngle()) +
		focuser_diameter * 0.5f * sinf(getFocuserAngle());
}

float classicastrospectrograph::getFocuserBottomX() const {
	return getDistSourceToGrating() - (focuser_position +
		((focuser_lastplane - focuser_position) / 2.0f)) *
		cosf(getCenDiffractAngle() - getIncidentAngle()) +
		focuser_diameter * 0.5f * cosf(getFocuserAngle());
}

float classicastrospectrograph::getFocuserBottomY() const {
	return (focuser_position + ((focuser_lastplane - focuser_position) / 2.0f)) *
		sinf(getCenDiffractAngle() - getIncidentAngle()) -
		focuser_diameter * 0.5f * sinf(getFocuserAngle());
}

float classicastrospectrograph::getFocuserTopRX() const {
	float raylength = (focuser_position + getGratingLightMajAxis()) /
		cosf(getMaxDiffractAngle() - getCenDiffractAngle());

	return getGratingRayTopX() - raylength * cosf(getMaxDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserTopRY() const {
	float raylength = (focuser_position + getGratingLightMajAxis()) /
		cosf(getMaxDiffractAngle() - getCenDiffractAngle());

	return getGratingRayY() + raylength * sinf(getMaxDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserTopGX() const {
	float raylength = (focuser_position + getGratingLightMajAxis());

	return getGratingRayTopX() - raylength * cosf(getCenDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserTopGY() const {
	float raylength = (focuser_position + getGratingLightMajAxis());

	return getGratingRayY() + raylength * sinf(getCenDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserTopBX() const {
	float raylength = (focuser_position + getGratingLightMajAxis()) /
		cosf(getMinDiffractAngle() - getCenDiffractAngle());

	return getGratingRayTopX() - raylength * cosf(getMinDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserTopBY() const {
	float raylength = (focuser_position + getGratingLightMajAxis()) /
		cosf(getMinDiffractAngle() - getCenDiffractAngle());

	return getGratingRayY() + raylength * sinf(getMinDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserCenRX() const {
	float raylength = focuser_position / cosf(getMaxDiffractAngle() - getCenDiffractAngle());

	return getDistSourceToGrating() - raylength * cosf(getMaxDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserCenRY() const {
	float raylength = focuser_position / cosf(getMaxDiffractAngle() - getCenDiffractAngle());

	return raylength * sinf(getMaxDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserCenGX() const {
	float raylength = focuser_position;

	return getDistSourceToGrating() - raylength * cosf(getCenDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserCenGY() const {
	float raylength = focuser_position;

	return raylength * sinf(getCenDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserCenBX() const {
	float raylength = focuser_position / cosf(getMinDiffractAngle() - getCenDiffractAngle());

	return getDistSourceToGrating() - raylength * cosf(getMinDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserCenBY() const {
	float raylength = focuser_position / cosf(getMinDiffractAngle() - getCenDiffractAngle());

	return raylength * sinf(getMinDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserBottomRX() const {
	float raylength = (focuser_position - getGratingLightMajAxis()) /
		cosf(getMaxDiffractAngle() - getCenDiffractAngle());

	return getGratingRayBottomX() - raylength * cosf(getMaxDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserBottomRY() const {
	float raylength = (focuser_position - getGratingLightMajAxis()) /
		cosf(getMaxDiffractAngle() - getCenDiffractAngle());

	return -getGratingRayY() + raylength * sinf(getMaxDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserBottomGX() const {
	float raylength = (focuser_position - getGratingLightMajAxis());

	return getGratingRayBottomX() - raylength * cosf(getCenDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserBottomGY() const {
	float raylength = (focuser_position - getGratingLightMajAxis());

	return -getGratingRayY() + raylength * sinf(getCenDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserBottomBX() const {
	float raylength = (focuser_position - getGratingLightMajAxis()) /
		cosf(getMinDiffractAngle() - getCenDiffractAngle());

	return getGratingRayBottomX() - raylength * cosf(getMinDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserBottomBY() const {
	float raylength = (focuser_position - getGratingLightMajAxis()) /
		cosf(getMinDiffractAngle() - getCenDiffractAngle());

	return -getGratingRayY() + raylength * sinf(getMinDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserThruTopRX() const {
	float raylength = (focuser_position + getGratingLightMajAxis()) /
		cosf(getMaxDiffractAngle() - getCenDiffractAngle());

	float maxshift = raylength * sinf(getMaxDiffractAngle() - getCenDiffractAngle());

	return getGratingRayTopX() - (focuser_lastplane + getGratingLightMajAxis()) *
		cosf(getCenDiffractAngle() - getIncidentAngle()) -
		maxshift * cosf(getFocuserAngle());
}

float classicastrospectrograph::getFocuserThruTopRY() const {
	float raylength = (focuser_position + getGratingLightMajAxis()) /
		cosf(getMaxDiffractAngle() - getCenDiffractAngle());

	float maxshift = raylength * sinf(getMaxDiffractAngle() - getCenDiffractAngle());

	return getGratingRayY() + (focuser_lastplane + getGratingLightMajAxis()) *
		sinf(getCenDiffractAngle() - getIncidentAngle()) +
		maxshift * sinf(getFocuserAngle());
}

float classicastrospectrograph::getFocuserThruTopGX() const {
	float raylength = (focuser_lastplane + getGratingLightMajAxis());

	return getGratingRayTopX() - raylength * cosf(getCenDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserThruTopGY() const {
	float raylength = (focuser_lastplane + getGratingLightMajAxis());

	return getGratingRayY() + raylength * sinf(getCenDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserThruTopBX() const {
	float raylength = (focuser_position + getGratingLightMajAxis()) /
		cosf(getMinDiffractAngle() - getCenDiffractAngle());

	float minshift = raylength * sinf(getMinDiffractAngle() - getCenDiffractAngle());

	return getGratingRayTopX() - (focuser_lastplane + getGratingLightMajAxis()) *
		cosf(getCenDiffractAngle() - getIncidentAngle()) -
		minshift * cosf(getFocuserAngle());
}

float classicastrospectrograph::getFocuserThruTopBY() const {
	float raylength = (focuser_position + getGratingLightMajAxis()) /
		cosf(getMinDiffractAngle() - getCenDiffractAngle());

	float minshift = raylength * sinf(getMinDiffractAngle() - getCenDiffractAngle());

	return getGratingRayY() + (focuser_lastplane + getGratingLightMajAxis()) *
		sinf(getCenDiffractAngle() - getIncidentAngle()) +
		minshift * sinf(getFocuserAngle());
}

float classicastrospectrograph::getFocuserThruCenRX() const {
	float raylength = focuser_position / cosf(getMaxDiffractAngle() - getCenDiffractAngle());

	float maxshift = raylength * sinf(getMaxDiffractAngle() - getCenDiffractAngle());

	return getDistSourceToGrating() - focuser_lastplane *
		cosf(getCenDiffractAngle() - getIncidentAngle()) -
		maxshift * cosf(getFocuserAngle());
}

float classicastrospectrograph::getFocuserThruCenRY() const {
	float raylength = focuser_position / cosf(getMaxDiffractAngle() - getCenDiffractAngle());

	float maxshift = raylength * sinf(getMaxDiffractAngle() - getCenDiffractAngle());

	return focuser_lastplane * sinf(getCenDiffractAngle() - getIncidentAngle()) +
		maxshift * sinf(getFocuserAngle());
}

float classicastrospectrograph::getFocuserThruCenGX() const {
	float raylength = focuser_lastplane;

	return getDistSourceToGrating() - raylength * cosf(getCenDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserThruCenGY() const {
	float raylength = focuser_lastplane;

	return raylength * sinf(getCenDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserThruCenBX() const {
	float raylength = focuser_position / cosf(getMinDiffractAngle() - getCenDiffractAngle());

	float minshift = raylength * sinf(getMinDiffractAngle() - getCenDiffractAngle());

	return getDistSourceToGrating() - focuser_lastplane *
		cosf(getCenDiffractAngle() - getIncidentAngle()) -
		minshift * cosf(getFocuserAngle());
}

float classicastrospectrograph::getFocuserThruCenBY() const {
	float raylength = focuser_position / cosf(getMinDiffractAngle() - getCenDiffractAngle());

	float minshift = raylength * sinf(getMinDiffractAngle() - getCenDiffractAngle());

	return focuser_lastplane * sinf(getCenDiffractAngle() - getIncidentAngle()) +
		minshift * sinf(getFocuserAngle());
}

float classicastrospectrograph::getFocuserThruBottomRX() const {
	float raylength = (focuser_position - getGratingLightMajAxis()) /
		cosf(getMaxDiffractAngle() - getCenDiffractAngle());

	float maxshift = raylength * sinf(getMaxDiffractAngle() - getCenDiffractAngle());

	return getGratingRayBottomX() - (focuser_lastplane - getGratingLightMajAxis()) *
		cosf(getCenDiffractAngle() - getIncidentAngle()) -
		maxshift * cosf(getFocuserAngle());
}

float classicastrospectrograph::getFocuserThruBottomRY() const {
	float raylength = (focuser_position - getGratingLightMajAxis()) /
		cosf(getMaxDiffractAngle() - getCenDiffractAngle());

	float maxshift = raylength * sinf(getMaxDiffractAngle() - getCenDiffractAngle());

	return -getGratingRayY() + (focuser_lastplane - getGratingLightMajAxis()) *
		sinf(getCenDiffractAngle() - getIncidentAngle()) +
		maxshift * sinf(getFocuserAngle());
}

float classicastrospectrograph::getFocuserThruBottomGX() const {
	float raylength = (focuser_lastplane - getGratingLightMajAxis());

	return getGratingRayBottomX() - raylength * cosf(getCenDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserThruBottomGY() const {
	float raylength = (focuser_lastplane - getGratingLightMajAxis());

	return -getGratingRayY() + raylength * sinf(getCenDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getFocuserThruBottomBX() const {
	float raylength = (focuser_position - getGratingLightMajAxis()) /
		cosf(getMinDiffractAngle() - getCenDiffractAngle());

	float minshift = raylength * sinf(getMinDiffractAngle() - getCenDiffractAngle());

	return getGratingRayBottomX() - (focuser_lastplane - getGratingLightMajAxis()) *
		cosf(getCenDiffractAngle() - getIncidentAngle()) -
		minshift * cosf(getFocuserAngle());
}

float classicastrospectrograph::getFocuserThruBottomBY() const {
	float raylength = (focuser_position - getGratingLightMajAxis()) /
		cosf(getMinDiffractAngle() - getCenDiffractAngle());

	float minshift = raylength * sinf(getMinDiffractAngle() - getCenDiffractAngle());

	return -getGratingRayY() + (focuser_lastplane - getGratingLightMajAxis()) *
		sinf(getCenDiffractAngle() - getIncidentAngle()) +
		minshift * sinf(getFocuserAngle());
}

float classicastrospectrograph::getDetectorCenterX() const {
	return getDistSourceToGrating() - focuser_lastplane * 
		cosf(getCenDiffractAngle() - getIncidentAngle()) -
		focuser_focal_length * cosf(getCenDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getDetectorCenterY() const {
	return focuser_lastplane * sinf(getCenDiffractAngle() - getIncidentAngle()) +
		focuser_focal_length * sinf(getCenDiffractAngle() - getIncidentAngle());
}

float classicastrospectrograph::getDetectorTopX() const {
	return getDistSourceToGrating() - focuser_lastplane *
		cosf(getCenDiffractAngle() - getIncidentAngle()) -
		focuser_focal_length * cosf(getCenDiffractAngle() - getIncidentAngle()) -
		detector_width / 2.0f * cosf(getFocuserAngle());
}

float classicastrospectrograph::getDetectorTopY() const {
	return focuser_lastplane * sinf(getCenDiffractAngle() - getIncidentAngle()) +
		focuser_focal_length * sinf(getCenDiffractAngle() - getIncidentAngle()) +
		detector_width / 2.0f * sinf(getFocuserAngle());
}

float classicastrospectrograph::getDetectorBottomX() const {
	return getDistSourceToGrating() - focuser_lastplane *
		cosf(getCenDiffractAngle() - getIncidentAngle()) -
		focuser_focal_length * cosf(getCenDiffractAngle() - getIncidentAngle()) +
		detector_width / 2.0f * cosf(getFocuserAngle());
}

float classicastrospectrograph::getDetectorBottomY() const {
	return focuser_lastplane * sinf(getCenDiffractAngle() - getIncidentAngle()) +
		focuser_focal_length * sinf(getCenDiffractAngle() - getIncidentAngle()) -
		detector_width / 2.0f * sinf(getFocuserAngle());
}

float classicastrospectrograph::getDetectorRX() const {
	float y = focuser_position * tanf(getMaxDiffractAngle() - getCenDiffractAngle());
	float r = sqrtf(powf(focuser_image_distance, 2.0f) + powf(y, 2.0f));
	float theta = acosf(focuser_image_distance / r);
	float shift = (focuser_image_distance - focuser_focal_length) * tanf(theta);

	if (grating_order >= 0) {
		return getDistSourceToGrating() - focuser_lastplane *
			cosf(getCenDiffractAngle() - getIncidentAngle()) -
			focuser_focal_length * cosf(getCenDiffractAngle() - getIncidentAngle()) -
			shift * cosf(getFocuserAngle());
	}
	else {
		return getDistSourceToGrating() - focuser_lastplane *
			cosf(getCenDiffractAngle() - getIncidentAngle()) -
			focuser_focal_length * cosf(getCenDiffractAngle() - getIncidentAngle()) +
			shift * cosf(getFocuserAngle());
	}
}

float classicastrospectrograph::getDetectorRY() const {
	float y = focuser_position * tanf(getMaxDiffractAngle() - getCenDiffractAngle());
	float r = sqrtf(powf(focuser_image_distance, 2.0f) + powf(y, 2.0f));
	float theta = acosf(focuser_image_distance / r);
	float shift = (focuser_image_distance - focuser_focal_length) * tanf(theta);

	if (grating_order >= 0) {
		return focuser_lastplane * sinf(getCenDiffractAngle() - getIncidentAngle()) +
			focuser_focal_length * sinf(getCenDiffractAngle() - getIncidentAngle()) +
			shift * sinf(getFocuserAngle());
	}
	else {
		return focuser_lastplane * sinf(getCenDiffractAngle() - getIncidentAngle()) +
			focuser_focal_length * sinf(getCenDiffractAngle() - getIncidentAngle()) -
			shift * sinf(getFocuserAngle());
	}
}

float classicastrospectrograph::getDetectorBX() const {
	float y = focuser_position * tanf(getMinDiffractAngle() - getCenDiffractAngle());
	float r = sqrtf(powf(focuser_image_distance, 2.0f) + powf(y, 2.0f));
	float theta = acosf(focuser_image_distance / r);
	float shift = (focuser_image_distance - focuser_focal_length) * tanf(theta);

	if (grating_order >= 0) {
		return getDistSourceToGrating() - focuser_lastplane *
			cosf(getCenDiffractAngle() - getIncidentAngle()) -
			focuser_focal_length * cosf(getCenDiffractAngle() - getIncidentAngle()) +
			shift * cosf(getFocuserAngle());
	}
	else {
		return getDistSourceToGrating() - focuser_lastplane *
			cosf(getCenDiffractAngle() - getIncidentAngle()) -
			focuser_focal_length * cosf(getCenDiffractAngle() - getIncidentAngle()) -
			shift * cosf(getFocuserAngle());
	}
}

float classicastrospectrograph::getDetectorBY() const {
	float y = focuser_position * tanf(getMinDiffractAngle() - getCenDiffractAngle());
	float r = sqrtf(powf(focuser_image_distance, 2.0f) + powf(y, 2.0f));
	float theta = acosf(focuser_image_distance / r);
	float shift = (focuser_image_distance - focuser_focal_length) * tanf(theta);

	if (grating_order >= 0) {
		return focuser_lastplane * sinf(getCenDiffractAngle() - getIncidentAngle()) +
			focuser_focal_length * sinf(getCenDiffractAngle() - getIncidentAngle()) -
			shift * sinf(getFocuserAngle());
	}
	else {
		return focuser_lastplane * sinf(getCenDiffractAngle() - getIncidentAngle()) +
			focuser_focal_length * sinf(getCenDiffractAngle() - getIncidentAngle()) +
			shift * sinf(getFocuserAngle());
	}
}