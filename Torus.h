#ifndef TORUS_H
#define TORUS_H

#include "Shape.h"
#include "tess.h"

class Torus : public Shape {
public:
	Torus() {
		R = 0.25;
		r = 0.15;
	};

	Torus(float R, float r) {
		R = R;
		r = r;
	};

	~Torus() {};

	void draw() {
		glBegin(GL_TRIANGLES);

		for (int i = 0; i < m_segmentsX; ++i) {

			float theta0 = 2.0 * i * PI / m_segmentsX;
			float theta1 = 2.0 * (i+1) * PI / m_segmentsX;

			for (int j = 0; j < m_segmentsY; ++j) {
				float phi0 = 2.0 * j * PI / m_segmentsY;
				float phi1 = 2.0 * (j+1) * PI / m_segmentsY;

				Point p1((R + r * cos(phi0)) * cos(theta0),
					r * sin(phi0),
					(R + r * cos(phi0)) * sin(theta0)),
				p2((R + r * cos(phi0)) * cos(theta1),
					r * sin(phi0),
					(R + r * cos(phi0)) * sin(theta1)),
				p3((R + r * cos(phi1)) * cos(theta0),
					r * sin(phi1),
					(R + r * cos(phi1)) * sin(theta0)),
				p4((R + r * cos(phi1)) * cos(theta1),
					r * sin(phi1),
					(R + r * cos(phi1)) * sin(theta1));

				Vector n1 = p1 - p2;
				Vector n2 = p3 - p2;
				Vector norm = cross(n1, n2);
				norm.normalize();
				glNormal3f(norm[0],norm[1],norm[2]);
				glVertex3f(p1[0],p1[1],p1[2]);
				glVertex3f(p2[0],p2[1],p2[2]);
				glVertex3f(p3[0],p3[1],p3[2]);

				n1 = p2 - p3;
				n2 = p4 - p3;

				norm = cross(n2, n1);
				norm.normalize();

				glNormal3f(norm[0],norm[1],norm[2]);
				glVertex3f(p3[0],p3[1],p3[2]);
				glVertex3f(p2[0],p2[1],p2[2]);
				glVertex3f(p4[0],p4[1],p4[2]);
			}
		}

		glEnd();
	};

	void drawNormal() {
		glBegin(GL_LINES);

		for (int i = 0; i < m_segmentsX; ++i) {
			float theta = 2.0 * i * PI / m_segmentsX;
			for (int j = 0; j < m_segmentsY; ++j) {
				float phi = 2.0 * j * PI / m_segmentsY;
				Point p1 = Point((R + r * cos(phi)) * cos(theta),
				r * sin(phi),
				(R + r * cos(phi)) * sin(theta));
				Vector v = Vector(r * cos(phi) * cos(theta),
				r * sin(phi),
				r * cos(phi) * sin(theta));
				v.normalize();
				Point p2 = p1 + v / 10.;
				glVertex3f(p1[0],p1[1],p1[2]);
				glVertex3f(p2[0],p2[1],p2[2]);
			}
		}
		glEnd();
	};
private:
	float r;
	float R;
};

#undef PHI
#undef THETA
#undef RHO

#endif
