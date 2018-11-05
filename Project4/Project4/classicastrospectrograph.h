#pragma once
class classicastrospectrograph
{
private:
	float minimum_wavelength; //m
	float maximum_wavelength; //m
	float telescope_diameter; //mm
	float telescope_focal_length; //mm
	float collimator_diameter; //mm
	float collimator_focal_length; //mm
	float collimator_lastplane; //mm
	float grating_width; //mm
	float grating_position; //mm
	float grating_angle; //radians
	float grating_grooves; //grooves per mm
	float grating_order; 
	float focuser_diameter; //mm
	float focuser_focal_length; //mm
	float focuser_position; //mm
	float focuser_lastplane; //mm
	float focuser_image_distance; //mm
	float detector_width; //mm
	float pixel_size; //microns

public:
	classicastrospectrograph(float minimum_wavelength, float maximum_wavelength, float telescope_diameter,
		float telescope_focal_length, float collimator_diameter, float collimator_focal_length,
		float collimator_lastplane, float grating_width, float grating_position, float grating_angle,
		float grating_grooves, float grating_order, float focuser_diameter, float focuser_focal_length,
		float focuser_position, float focuser_lastplane, float focuser_image_distance, 
		float detector_width, float pixel_size);

	float getCenWavelength() const;
	float getIncidentAngle() const;
	float getCenDiffractAngle() const;
	float getMaxDiffractAngle() const;
	float getMinDiffractAngle() const;
	float getInitialBeamWidth() const;
	float getCollimatedRadius() const;
	float getSpectralRangeMin() const;
	float getSpectralRangeMax() const;
	float getResolvingPower() const;
	float getResolution() const;
	float getDiffractedDispersion() const;
	float getGratingLightMajAxis() const;
	float getFocuserAngle() const;
	float getGratingAngle() const;
	float getDetectorWidth() const;
	float getPixelSize() const;
	float getDistSourceToGrating() const;
	float getGratingTopX() const;
	float getGratingBottomX() const;
	float getGratingY() const;
	float getGratingRayTopX() const;
	float getGratingRayY() const;
	float getGratingRayBottomX() const;
	float getFocuserCenterX() const;
	float getFocuserCenterY() const;
	float getFocuserTopX() const;
	float getFocuserTopY() const;
	float getFocuserBottomX() const;
	float getFocuserBottomY() const;
	float getFocuserTopRX() const;
	float getFocuserTopRY() const;
	float getFocuserTopGX() const;
	float getFocuserTopGY() const;
	float getFocuserTopBX() const;
	float getFocuserTopBY() const;
	float getFocuserCenRX() const;
	float getFocuserCenRY() const;
	float getFocuserCenGX() const;
	float getFocuserCenGY() const;
	float getFocuserCenBX() const;
	float getFocuserCenBY() const;
	float getFocuserBottomRX() const;
	float getFocuserBottomRY() const;
	float getFocuserBottomGX() const;
	float getFocuserBottomGY() const;
	float getFocuserBottomBX() const;
	float getFocuserBottomBY() const;
	float getFocuserThruTopRX() const;
	float getFocuserThruTopRY() const;
	float getFocuserThruTopGX() const;
	float getFocuserThruTopGY() const;
	float getFocuserThruTopBX() const;
	float getFocuserThruTopBY() const;
	float getFocuserThruCenRX() const;
	float getFocuserThruCenRY() const;
	float getFocuserThruCenGX() const;
	float getFocuserThruCenGY() const;
	float getFocuserThruCenBX() const;
	float getFocuserThruCenBY() const;
	float getFocuserThruBottomRX() const;
	float getFocuserThruBottomRY() const;
	float getFocuserThruBottomGX() const;
	float getFocuserThruBottomGY() const;
	float getFocuserThruBottomBX() const;
	float getFocuserThruBottomBY() const;
	float getDetectorCenterX() const;
	float getDetectorCenterY() const;
	float getDetectorTopX() const;
	float getDetectorTopY() const;
	float getDetectorBottomX() const;
	float getDetectorBottomY() const;
	float getDetectorRX() const;
	float getDetectorRY() const;
	float getDetectorBX() const;
	float getDetectorBY() const;
};

