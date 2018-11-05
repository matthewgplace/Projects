#pragma once
class telescope
{
private:
	float diameter;
	float focal_length;

public:
	telescope(float diameter, float focal_length);
	float getRadius() const;
	float getDiameter() const;
	float getFocalLength() const;
	float getFRatio() const;
	void setDiameter(float diameter);
	void setFocalLength(float focal_length);

};

