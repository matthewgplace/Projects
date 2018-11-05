#pragma once
class lens
{
private:
	float diameter;
	float thickness;
	float focal_length;
	float object_distance;
	float refractive_index;

public:
	lens(float diameter, float thickness, float focal_length, float object_distance, float refractive_index);

	float getRadius() const;
	float getDiameter() const;
	float getThickness() const;
	float getFocalLength() const;
	float getObjectDistance() const;
	float getImageDistance() const;
	float getRefractiveIndex() const;
	float getFRatio() const;
	float getPrinciplePlane() const;
	float getCenterDistance() const;
	float getLastPlaneDistance() const;
	void setDiameter(float diameter);
	void setThickness(float thickness);
	void setFocalLength(float focal_length);
	void setObjectDistance(float object_distance);
	void setRefractiveIndex(float refractive_index);


};

