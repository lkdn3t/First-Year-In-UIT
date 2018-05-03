#include <iostream>
using namespace std;

class Ellipse {
protected:
	struct Point2D {
		float x;
		float y;
	} Center;
	float MajorAxis;
	float MinorAxis;
	float FocusAxis;

public:
	Ellipse(float xCenter = 0, float yCenter = 0, float MajorAxis = 0, float MinorAxis = 0, float FocusAxis = 0);
	float getXCenter() const;
	float getYCenter() const;
	float getMajorAxis() const;
	float getMinorAxis() const;
	float getFocusAxis() const;

	void setXCenter(float XCenter);
	void setYCenter(float YCenter);
	void setMajorAxis(float MajorAxis);
	void setMinorAxis(float MinorAxis);
	void setFocusAxis(float FocusAxis);

public:
	virtual void GetData();
	virtual void PutData() const;
};