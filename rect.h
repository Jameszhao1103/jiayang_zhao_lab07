#ifndef RECT_H
#define RECT_H

#include "vec2.h"
#include "shape.h"

/* simple data representation of a rectangle */
class Rect : public shape {
  public:
	Rect(double lX, double lY, double rX, double rY, color C, double deep) : shape{C, deep},
		upperL(lX, lY), lowerR(rX, rY) {}
	
	Rect(vec2(left), vec2(right), color C, double deep) : shape{C, deep},
		upperL(left), lowerR(right) {}
	Rect(vec2(left), double width, double height, color C, double deep) : shape{C, deep},
		upperL(left), lowerR(left.x()+width,left.y()+height) {}

	bool eval(double x, double y) override {
		if ((x >= upperL.x() && x <= lowerR.x()) && (y >= upperL.y() && y <= lowerR.y())) {
			return true;
		}
		return false;
	}

	void translate(vec2 offset) {
		upperL += offset;
		lowerR += offset;
	}

	double getWidth() const {return lowerR.x() - upperL.x(); }
	double getHeight() const {return lowerR.y() - upperL.y(); }
	double getArea() const {return (lowerR.x() - upperL.x())*(lowerR.y() - upperL.y());}

	void setLCorner(vec2 inLCor) { upperL = inLCor; }
	void setRCorner(vec2 inRCor) {lowerR = inRCor;}

	void validate() override {
		try
		{
			if(upperL.x()< 0 || upperL.y()< 0||lowerR.x()< 0 || lowerR.y()< 0)
			{
				throw std::invalid_argument("rect vert less zero");
			}
		}
		catch(const std::invalid_argument& e)
		{
			setColor(color(0,0,0));
			std::cerr << e.what() << std::endl;
		}
		try
		{
			if(upperL.x()> lowerR.x() || upperL.y()> lowerR.y())
			{
				throw std::invalid_argument("rect order incorrect");
			}
		}
		catch(const std::invalid_argument& e)
		{
			setColor(color(255,0,0));
			vec2 temp = upperL;
			setLCorner(lowerR);
			setRCorner(temp);
			std::cerr << e.what() << std::endl;
		}
	}
  private:
	vec2 upperL;
	vec2 lowerR;

};

#endif
