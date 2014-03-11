/*
 * camera.cpp
 */
#include "Camera.h"


Camera::Camera() {}

Camera::~Camera() {}

void Camera::Orient(Point& eye, Point& focus, Vector& up) {
    eyePoint = eye;
    look = focus - eye;
    look.normalize();
    this->up = up;

    w = Vector(look);
    w.negate();
    u = cross(up, w);
    u.normalize();
    v = cross(w, u);
    v.normalize();
}


void Camera::Orient(Point& eye, Vector& look, Vector& up) {
    eyePoint = eye;
    this->look = look;
    this->up = up;

    w = Vector(look);
    w.normalize();
    w.negate();
    u = cross(up, w);
    u.normalize();
    v = cross(w, u);
    v.normalize();
}

Matrix Camera::GetProjectionMatrix() { 
    double c = -near / far;
    Matrix Mpp = Matrix(1, 0, 0, 0,
                        0, 1, 0, 0,
                        0, 0, -1.0/(c+1.0), c / (c + 1.0),
                        0, 0, -1, 0);
    Matrix Sxyz = Matrix(1.0/(tan(DEG_TO_RAD(view*width/height/2))*far),0,0,0,
                          0, 1.0/(tan(DEG_TO_RAD(view/2))*far), 0, 0,
                          0, 0, 1.0/far, 0,
                          0, 0, 0, 1);
    Matrix R(u[0], u[1], u[2], 0,
             v[0], v[1], v[2], 0,
             w[0], w[1], w[2], 0,
               0,    0,    0,  1);
    Matrix T = trans_mat(Vector(-eyePoint[0],-eyePoint[1],-eyePoint[2]));
    return Mpp * Sxyz;
}

void Camera::SetViewAngle (double viewAngle) { view = viewAngle; }
void Camera::SetNearPlane (double nearPlane) { near = nearPlane; }
void Camera::SetFarPlane (double farPlane) { far = farPlane; }

void Camera::SetScreenSize (int screenWidth, int screenHeight) {
	width = screenWidth;
	height = screenHeight;
}

Matrix Camera::GetModelViewMatrix() {
    Matrix R(u[0], u[1], u[2], 0,
             v[0], v[1], v[2], 0,
             w[0], w[1], w[2], 0,
               0,    0,    0,  1);
    Point Pn = eyePoint; //+ near * look;
    Matrix T = trans_mat(Vector(-Pn[0],-Pn[1],-Pn[2]));
    return R * T;
}

void Camera::RotateV(double angle) {
    angle = DEG_TO_RAD(angle);
    Matrix R = rot_mat(v, angle);
    u = R * u;
    w = R * w;
    look = R * look;
}

void Camera::RotateU(double angle) {
    angle = DEG_TO_RAD(angle);
    Matrix R = rot_mat(u, angle);
    v = R * v;
    w = R * w;
    look = R * look;
}

void Camera::RotateW(double angle) {
    angle = DEG_TO_RAD(angle);
    Matrix R = rot_mat(w, angle);
    v = R * v;
    u = R * u;
}

void Camera::Translate(const Vector &v) {
    eyePoint = eyePoint + v;
}

void Camera::Rotate(Point p, Vector axis, double degrees) {
    Matrix R = rot_mat(p, axis, DEG_TO_RAD(degrees));
    w = R * w;
    v = R * v;
    u = R * u;
    look = R * look;
}

Point Camera::GetEyePoint() { return eyePoint; }
Vector Camera::GetLookVector() { return look; }
Vector Camera::GetUpVector() { return up; }
double Camera::GetViewAngle() { return view; }
double Camera::GetNearPlane() { return near; }
double Camera::GetFarPlane() { return far; }
int Camera::GetScreenWidth() { return width; }
int Camera::GetScreenHeight() { return height; }
double Camera::GetFilmPlanDepth() { return far - near; }
double Camera::GetScreenWidthRatio() { return width / height; }
