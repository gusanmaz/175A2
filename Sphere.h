#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"
#include "tess.h"

class Sphere : public Shape {
public:
	Sphere() {};
	~Sphere() {};

	void draw() {
		glBegin(GL_TRIANGLES);

		for (float y = 0; y < m_segmentsY; ++y) {
			float lowerY = 0.5 - y / m_segmentsY;
			float upperY = 0.5 - (y+1.0) / m_segmentsY;
			float lowerR = transverseSliceRadiusSphere(0.5,lowerY);
			float upperR = transverseSliceRadiusSphere(0.5,upperY);
			for (int i = 0; i < m_segmentsX; ++i) {

				float lowerXL = ithSliceXComponent(lowerR,i,m_segmentsX);
				float upperXL = ithSliceXComponent(lowerR,i+1,m_segmentsX);
				float lowerZL = ithSliceZComponent(lowerR,i,m_segmentsX);
				float upperZL = ithSliceZComponent(lowerR,i+1,m_segmentsX);

				float lowerXU = ithSliceXComponent(upperR,i,m_segmentsX);
				float upperXU = ithSliceXComponent(upperR,i+1,m_segmentsX);
				float lowerZU = ithSliceZComponent(upperR,i,m_segmentsX);
				float upperZU = ithSliceZComponent(upperR,i+1,m_segmentsX);

				glVertex3f(lowerXL,lowerY,lowerZL);
				glVertex3f(upperXL,lowerY,upperZL);
				glVertex3f(lowerXU,upperY,lowerZU);
				glVertex3f(lowerXU,upperY,lowerZU);
				glVertex3f(upperXL,lowerY,upperZL);
				glVertex3f(upperXU,upperY,upperZU);
			}
		}	
		glEnd();
	};

	void drawNormal() {
		glBegin(GL_LINES);
		for (float y = 0; y < m_segmentsY; ++y) {
			float Y = 0.5 - y / m_segmentsY;
			float R = transverseSliceRadiusSphere(0.5,Y);
			for (int i = 0; i < m_segmentsX; ++i) {
				Point p1(ithSliceXComponent(R,i,m_segmentsX),Y,ithSliceZComponent(R,i,m_segmentsX));
				Vector v(p1[0],p1[1],p1[2]);
				v.normalize();
				glVertex3f(p1[0],p1[1],p1[2]);
				Point p2 = p1 + v / 10;
				glVertex3f(p2[0],p2[1],p2[2]);
			}
		}
		glEnd();
	};
};

#endif
