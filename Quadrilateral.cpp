#include "Quadrilateral.h"
#include <iostream>
#include "graph1.h"
#include "Shape.h"

Quadrilateral::Quadrilateral()
 {
	 this->a.setPoint(0,0);
	 this->b.setPoint(0,0);
	 this->c.setPoint(0,0);
	 this->d.setPoint(0,0);
 }

Quadrilateral::Quadrilateral(GenPoint a, GenPoint b, GenPoint c, GenPoint d, Color color)
 {
	 this->a.setPoint(a.getX(),a.getY());
	 this->b.setPoint(b.getX(),b.getY());
	 this->c.setPoint(c.getX(),c.getY());
	 this->d.setPoint(d.getX(),d.getY());
	 this->color.setColor(color.getRed(),color.getGreen(),color.getBlue());
 }

void Quadrilateral::setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d)
 {
	 this->a.setPoint(a.getX(),a.getY());
	 this->b.setPoint(b.getX(),b.getY());
	 this->c.setPoint(c.getX(),c.getY());
	 this->d.setPoint(d.getX(),d.getY());
 }

double Quadrilateral::getPerimeter()
 {
	double total;

	double side1 = sqrt( (pow(a.getX() - b.getX(), 2.0)) + (pow(a.getY() - b.getY(), 2.0)));
	double side2 = sqrt( (pow(b.getX() - c.getX(), 2.0)) + (pow(b.getY() - c.getY(), 2.0)));
	double side3 = sqrt( (pow(c.getX() - d.getX(), 2.0)) + (pow(c.getY() - d.getY(), 2.0)));
	double side4 = sqrt( (pow(d.getX() - a.getX(), 2.0)) + (pow(d.getY() - a.getY(), 2.0)));

	total = side1 + side2 + side3 + side4;

	return total;
 }

void Quadrilateral::print()
 {
	 gout << setPos(200,405) << "Shape info follows for: Quadrilateral" << endg;
	 gout << setPos(200,420) << "Point a: (" << a.getX() << "," << a.getY() << ")" << endg;
	 gout << setPos(200,435) << "Point b: (" << b.getX() << "," << b.getY() << ")" << endg;
	 gout << setPos(200,450) << "Point c: (" << c.getX() << "," << c.getY() << ")" << endg;
	 gout << setPos(200,465) << "Point d: (" << d.getX() << "," << d.getY() << ")" << endg;
	 gout << setPos(200,480) << "Perimeter: " << getPerimeter() << endg;
 }

void Quadrilateral::draw()
 {
	 int line1 = drawLine(a.getX(),a.getY(),b.getX(),b.getY(),2);
	 ::setColor(line1,color.getRed(),color.getGreen(),color.getBlue());
	 int line2 = drawLine(b.getX(),b.getY(),c.getX(),c.getY(),2);
	 ::setColor(line2,color.getRed(),color.getGreen(),color.getBlue());
	 int line3 = drawLine(c.getX(),c.getY(),d.getX(),d.getY(),2);
	 ::setColor(line3,color.getRed(),color.getGreen(),color.getBlue());
	 int line4 = drawLine(d.getX(),d.getY(),a.getX(),a.getY(),2);
	 ::setColor(line4,color.getRed(),color.getGreen(),color.getBlue());
 }
