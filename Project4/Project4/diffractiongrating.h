#pragma once
class diffractiongrating
{
private:
	float width;
	float height;
	float depth;
	float diffraction_order;
	float blaze_wavelength;
	float blaze_angle;
	float grooves_per_mm;

public:
	diffractiongrating(float width, float height, float depth, float diffraction_order, float blaze_wavelength, float blaze_angle, float grooves_per_mm);

	float getWidth() const;
	float getHeight() const;
	float getDepth() const;
	float getOrder() const;
	float getBlazeWave() const;
	float getBlazeAngle() const;
	float getGrooves() const;
	void setWidth(float width);
	void setHeight(float height);
	void setDepth(float depth);
	void setOrder(float diffraction_order);
	void setBlazeWave(float blaze_wavelength);
	void setBlazeAngle(float blaze_angle);
	void setGrooves(float grooves_per_mm);

};

