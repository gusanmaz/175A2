#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.h"
#include "tess.h"

class Cylinder : public Shape {
public:
	Cylinder() {};
	~Cylinder() {};

	void draw() {
		glBegin(GL_TRIANGLES);		

		for (int i = 0; i < m_segmentsX; ++i) {

			float lowerX = ithSliceXComponent(0.5,i,m_segmentsX);
			float upperX = ithSliceXComponent(0.5,i+1,m_segmentsX);
			float lowerZ = ithSliceZComponent(0.5,i,m_segmentsX);
			float upperZ = ithSliceZComponent(0.5,i+1,m_segmentsX);

			/* bottom base */
			glNormal3f(0, -1, 0);
			glVertex3f(0.0, -0.5, 0.0);
			glVertex3f(upperX,-0.5,upperZ);
			glVertex3f(lowerX,-0.5,lowerZ);

			for (float y = 0.0; y < m_segmentsY; ++y) {

				float lowerY = -0.5 + y / m_segmentsY;
				float upperY = -0.5 + (y + 1.0) / m_segmentsY; 

				Vector norm((lowerX+upperX)/2, 0, (lowerZ+upperZ)/2);
				norm.normalize();

				glNormal3f(norm[0],norm[1],norm[2]);
				glVertex3f(lowerX,lowerY,lowerZ);
				glVertex3f(upperX,lowerY,upperZ);
				glVertex3f(lowerX,upperY,lowerZ);

				glNormal3f(norm[0],norm[1],norm[2]);
				glVertex3f(lowerX,upperY,lowerZ);
				glVertex3f(upperX,lowerY,upperZ);
				glVertex3f(upperX,upperY,upperZ);
			}			

			/* top base */
			glNormal3f(0, 1, 0);
			glVertex3f(0.0, 0.5, 0.0);
			glVertex3f(lowerX,0.5,lowerZ);
			glVertex3f(upperX,0.5,upperZ);
		}
		glEnd();
	};

	void drawNormal() {
		glBegin(GL_LINES);
		for (int i = 0; i < m_segmentsX; ++i) {
			for (int j = 0; j < m_segmentsY; ++j) {
				Point p1 = Point(ithSliceXComponent(0.5,i,m_segmentsX),
					             -0.5 + (1.0 * j) / m_segmentsY,
					             ithSliceZComponent(0.5,i,m_segmentsX));
				Vector v = Vector(ithSliceXComponent(0.5,i,m_segmentsX),
					              0.0,
					              ithSliceZComponent(0.5,i,m_segmentsX));
				v.normalize();
				Point p2 = p1 + v / 10;
				glVertex3f(p1[0],p1[1],p1[2]);
                glVertex3f(p2[0],p2[1],p2[2]);
			}
		}
		glEnd();
	};
};

#endif
