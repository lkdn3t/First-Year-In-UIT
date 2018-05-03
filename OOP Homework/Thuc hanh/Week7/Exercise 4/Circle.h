#include "Ellipse.h"

class Circle: public Ellipse {
public:
	Circle(float XCenter = 0, float YCenter = 0, float Radius = 0);
	float getRadius() const;
	void  setRadius(float Radius);

public:
	void GetData();
	void PutData() const;
};