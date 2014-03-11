#ifndef CUBE_H
#define CUBE_H

#include "Shape.h"

class Cube : public Shape {
public:
	Cube() {};
	~Cube() {};

	void draw() {
		glBegin(GL_TRIANGLES);

		Point p1, p2, p3, p4;

		for (float x = 0; x < m_segmentsX; ++x) {
			for (float y = 0; y < m_segmentsY; ++y) {

					/* front face */
				p1 = Point(-0.5+x/m_segmentsX,-0.5+y/m_segmentsY,0.5);
				p2 = Point(-0.5+(x+1.0)/m_segmentsX,-0.5+y/m_segmentsY,0.5);
				p3 = Point(-0.5+x/m_segmentsX,-0.5+(y+1.0)/m_segmentsY,0.5);
				p4 = Point(-0.5+(x+1.0)/m_segmentsX,-0.5+(y+1.0)/m_segmentsY,0.5);

				glNormal3f(0,0,1);
				glVertex3f(p1[0], p1[1], p1[2]);
				glVertex3f(p2[0], p2[1], p2[2]);
				glVertex3f(p3[0], p3[1], p3[2]);

				glNormal3f(0,0,1);
				glVertex3f(p3[0], p3[1], p3[2]);
				glVertex3f(p2[0], p2[1], p2[2]);
				glVertex3f(p4[0], p4[1], p4[2]);

					/* right face */
				p1 = Point(0.5,-0.5+y/m_segmentsY,0.5-x/m_segmentsX);
				p2 = Point(0.5,-0.5+y/m_segmentsY,0.5-(x+1.0)/m_segmentsX);
				p3 = Point(0.5,-0.5+(y+1.0)/m_segmentsY,0.5-x/m_segmentsX);
				p4 = Point(0.5,-0.5+(y+1.0)/m_segmentsY,0.5-(x+1.0)/m_segmentsX);

				glNormal3f(1, 0, 0);
				glVertex3f(p1[0], p1[1], p1[2]);
				glVertex3f(p2[0], p2[1], p2[2]);
				glVertex3f(p3[0], p3[1], p3[2]);

				glNormal3f(1, 0, 0);
				glVertex3f(p3[0], p3[1], p3[2]);
				glVertex3f(p2[0], p2[1], p2[2]);
				glVertex3f(p4[0], p4[1], p4[2]);
				
					/* back face */
				p1 = Point(0.5-x/m_segmentsX,-0.5+y/m_segmentsY,-0.5);
				p2 = Point(0.5-(x+1.0)/m_segmentsX,-0.5+y/m_segmentsY,-0.5);
				p3 = Point(0.5-x/m_segmentsX,-0.5+(y+1.0)/m_segmentsY,-0.5);
				p4 = Point(0.5-(x+1.0)/m_segmentsX,-0.5+(y+1.0)/m_segmentsY,-0.5);

				glNormal3f(0, 0, -1);
				glVertex3f(p1[0], p1[1], p1[2]);
				glVertex3f(p2[0], p2[1], p2[2]);
				glVertex3f(p3[0], p3[1], p3[2]);

				glNormal3f(0, 0, -1);
				glVertex3f(p3[0], p3[1], p3[2]);
				glVertex3f(p2[0], p2[1], p2[2]);
				glVertex3f(p4[0], p4[1], p4[2]);				

					/* left face */
				p1 = Point(-0.5,-0.5+y/m_segmentsY,-0.5+x/m_segmentsX);
				p2 = Point(-0.5,-0.5+y/m_segmentsY,-0.5+(x+1.0)/m_segmentsX);
				p3 = Point(-0.5,-0.5+(y+1.0)/m_segmentsY,-0.5+x/m_segmentsX);
				p4 = Point(-0.5,-0.5+(y+1.0)/m_segmentsY,-0.5+(x+1.0)/m_segmentsX);

				glNormal3f(-1, 0, 0);
				glVertex3f(p1[0], p1[1], p1[2]);
				glVertex3f(p2[0], p2[1], p2[2]);
				glVertex3f(p3[0], p3[1], p3[2]);
				glNormal3f(-1, 0, 0);
				glVertex3f(p3[0], p3[1], p3[2]);
				glVertex3f(p2[0], p2[1], p2[2]);
				glVertex3f(p4[0], p4[1], p4[2]);				

			}
			for (float z = 0; z < m_segmentsX; ++z) {

					/* top face */
				p1 = Point(-0.5+x/m_segmentsX,0.5,0.5-z/m_segmentsX);
				p2 = Point(-0.5+x/m_segmentsX,0.5,0.5-(z+1.0)/m_segmentsX);
				p3 = Point(-0.5+(x+1.0)/m_segmentsX,0.5,0.5-z/m_segmentsX);
				p4 = Point(-0.5+(x+1.0)/m_segmentsX,0.5,0.5-(z+1.0)/m_segmentsX);

				glNormal3f(0, 1, 0);
				glVertex3f(p1[0], p1[1], p1[2]);
				glVertex3f(p2[0], p2[1], p2[2]);
				glVertex3f(p3[0], p3[1], p3[2]);

				glNormal3f(0, 1, 0);
				glVertex3f(p3[0], p3[1], p3[2]);
				glVertex3f(p2[0], p2[1], p2[2]);
				glVertex3f(p4[0], p4[1], p4[2]);				

					/* bottom face */
				p1 = Point(-0.5+x/m_segmentsX,-0.5,-0.5+z/m_segmentsX);
				p2 = Point(-0.5+x/m_segmentsX,-0.5,-0.5+(z+1.0)/m_segmentsX);
				p3 = Point(-0.5+(x+1.0)/m_segmentsX,-0.5,-0.5+z/m_segmentsX);
				p4 = Point(-0.5+(x+1.0)/m_segmentsX,-0.5,-0.5+(z+1.0)/m_segmentsX);

				glNormal3f(0, -1, 0);
				glVertex3f(p1[0], p1[1], p1[2]);
				glVertex3f(p2[0], p2[1], p2[2]);
				glVertex3f(p3[0], p3[1], p3[2]);

				glNormal3f(0, -1, 0);
				glVertex3f(p3[0], p3[1], p3[2]);
				glVertex3f(p2[0], p2[1], p2[2]);
				glVertex3f(p4[0], p4[1], p4[2]);				

			}
		}

		glEnd();
	};

	void drawNormal() {
		glBegin(GL_LINES);
		for (float x = 0; x < m_segmentsX; ++x) {
			for (float y = 0; y < m_segmentsY; ++y) {
					/* front face */
				glVertex3f(-0.5+x/m_segmentsX,-0.5+y/m_segmentsY,0.5);
				glVertex3f(-0.5+x/m_segmentsX,-0.5+y/m_segmentsY,0.6);
					/* right face */
				glVertex3f(0.5,-0.5+y/m_segmentsY,0.5-x/m_segmentsX);
				glVertex3f(0.6,-0.5+y/m_segmentsY,0.5-x/m_segmentsX);
					/* back face */
				glVertex3f(0.5-x/m_segmentsX,-0.5+y/m_segmentsY,-0.5);
				glVertex3f(0.5-x/m_segmentsX,-0.5+y/m_segmentsY,-0.6);
					/* left face */
				glVertex3f(-0.5,-0.5+y/m_segmentsY,-0.5+x/m_segmentsX);
				glVertex3f(-0.6,-0.5+y/m_segmentsY,-0.5+x/m_segmentsX);
			}
			for (float z = 0; z < m_segmentsX; ++z) {
					/* top face */
				glVertex3f(-0.5+x/m_segmentsX,0.5,0.5-z/m_segmentsX);
				glVertex3f(-0.5+x/m_segmentsX,0.6,0.5-z/m_segmentsX);
					/* bottom face */
				glVertex3f(-0.5+x/m_segmentsX,-0.5,-0.5+z/m_segmentsX);
				glVertex3f(-0.5+x/m_segmentsX,-0.6,-0.5+z/m_segmentsX);
			}
		}
		glEnd();
	};
};

#endif
