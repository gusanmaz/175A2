#ifndef COHE_H
#define CONE_H

#include "Shape.h"
#include "tess.h"

class Cone : public Shape {
public:
	Cone() {};
	~Cone() {};

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
		}
		for (float y = 0; y < m_segmentsY; ++y) {
			float lowerY = 0.5 - y / m_segmentsY;
			float upperY = 0.5 - (y+1.0) / m_segmentsY;
			float lowerR = transverseSliceRadiusCone(0.5,1.0,lowerY+0.5);
			float upperR = transverseSliceRadiusCone(0.5,1.0,upperY+0.5);
			for (int i = 0; i < m_segmentsX; ++i) {

				float lowerXL = ithSliceXComponent(lowerR,i,m_segmentsX);
				float upperXL = ithSliceXComponent(lowerR,i+1,m_segmentsX);
				float lowerZL = ithSliceZComponent(lowerR,i,m_segmentsX);
				float upperZL = ithSliceZComponent(lowerR,i+1,m_segmentsX);

				float lowerXU = ithSliceXComponent(upperR,i,m_segmentsX);
				float upperXU = ithSliceXComponent(upperR,i+1,m_segmentsX);
				float lowerZU = ithSliceZComponent(upperR,i,m_segmentsX);
				float upperZU = ithSliceZComponent(upperR,i+1,m_segmentsX);

				Vector norm((ithSliceXComponent(0.5,i,m_segmentsX) + 
							ithSliceXComponent(0.5,i+1,m_segmentsX))/2,
					              0.25,
					        (ithSliceZComponent(0.5,i,m_segmentsX) +
					        ithSliceZComponent(0.5,i+1,m_segmentsX))/2);
				norm.normalize();

				glNormal3f(norm[0],norm[1],norm[2]);
				glVertex3f(lowerXL,lowerY,lowerZL);
				glVertex3f(upperXL,lowerY,upperZL);
				glVertex3f(lowerXU,upperY,lowerZU);

				glNormal3f(norm[0],norm[1],norm[2]);
				glVertex3f(lowerXU,upperY,lowerZU);
				glVertex3f(upperXL,lowerY,upperZL);
				glVertex3f(upperXU,upperY,upperZU);
			}
		}
		glEnd();
	};

	void drawNormal() {
		glBegin(GL_LINES);
		for (int i = 0; i < m_segmentsX; ++i) {
			for (int j = 0; j < m_segmentsY; ++j) {
				float r = transverseSliceRadiusCone(0.5,1.0,-0.5+(1.0*j)/m_segmentsY+0.5);
				Point p1 = Point(ithSliceXComponent(r,i,m_segmentsX),
					             -0.5 + (1.0 * j) / m_segmentsY,
					             ithSliceZComponent(r,i,m_segmentsX));
				Vector v = Vector(ithSliceXComponent(0.5,i,m_segmentsX),
					              0.25,
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
