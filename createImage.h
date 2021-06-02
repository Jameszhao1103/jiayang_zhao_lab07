#include "color.h"

template<class T>
void createImage(image<T>& theImg, vector<shared_ptr<shape>> theShapes, T inC){}



template<>
inline void createImage<int>(image<int>& theImg, 
				vector<shared_ptr<shape>> theShapes, int inC) {

	float res;
	color drawC;

	bool inTrue = false;
	double curDepth = -1.0;
	//for every point in the 2D space
	for (int y=0; y < theImg.h(); y++) {
		for (int x =0; x < theImg.w(); x++) {

			inTrue = false;
			curDepth = -1;
			//iterate through all possible equations
			for (auto eq : theShapes) {
				if (eq->eval(x, y) && eq->getDepth() > curDepth){
					inC = eq->getInC().r()*0.299+eq->getInC().g()*0.587+eq->getInC().b()*0.114;
					inTrue = true;
					curDepth = eq->getDepth();
				}
			}
					
			if (inTrue) {			
				theImg.setPixel(x, y, inC);
			}
		}
	}
}

template<>
inline void createImage<bool>(image<bool>& theImg, 
				vector<shared_ptr<shape>> theShapes, bool inC) {

	float res;
	color drawC;

	bool inTrue = false;
	double curDepth = -1.0;

	//for every point in the 2D space
	for (int y=0; y < theImg.h(); y++) {
		for (int x =0; x < theImg.w(); x++) {

			inTrue = false;
			curDepth = -1;
			//iterate through all possible equations
			for (auto eq : theShapes) {
				if (eq->eval(x, y) && eq->getDepth() > curDepth) {
					inC = 1;
					inTrue = true;
					curDepth = eq->getDepth();
				}
			}
					
			if (inTrue) {			
				theImg.setPixel(x, y, inC);
			}
		}
	}
}

/*write out PPM data, using the defined implicit equation 
  interior points write a differnt color then exterior points */
template<>
inline void createImage<color>(image<color>& theImg, 
				vector<shared_ptr<shape>> theShapes, color inC) {

	float res;
	color drawC;

	bool inTrue = false;
	double curDepth = -1.0;

	//for every point in the 2D space
	for (int y=0; y < theImg.h(); y++) {
		for (int x =0; x < theImg.w(); x++) {

			inTrue = false;
			curDepth = -1;
			//iterate through all possible equations
			for (auto eq : theShapes) {
				if (eq->eval(x, y) && eq->getDepth() > curDepth) {
					inC = eq->getInC();
					inTrue = true;
					curDepth = eq->getDepth();
				}
			}
					
			if (inTrue) {			
				theImg.setPixel(x, y, inC);
			}
		}
	}
}

template<>
inline void createImage<char>(image<char>& theImg, 
				vector<shared_ptr<shape>> theShapes, char inC) {

	float res;
	color drawC;

	bool inTrue = false;
	double curDepth = -1.0;

	//for every point in the 2D space
	for (int y=0; y < theImg.h(); y++) {
		for (int x =0; x < theImg.w(); x++) {

			inTrue = false;
			curDepth = -1;
			//iterate through all possible equations
			for (auto eq : theShapes) {
				if (eq->eval(x, y) && eq->getDepth() > curDepth) {
					inTrue = true;
					curDepth = eq->getDepth();
				}
			}
					
			if (inTrue) {			
				theImg.setPixel(x, y, inC);
			}
		}
	}
}