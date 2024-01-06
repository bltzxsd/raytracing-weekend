#pragma once

#include <cmath>
#include <iostream>

class Vec3 {
    double e[3];

  public:
    Vec3() : e(0, 0, 0) {}

    Vec3(double x, double y, double z) : e(x, y, z) {}

    double x() const {
        return e[0];
    }

    double y() const {
        return e[1];
    }

    double z() const {
        return e[2];
    }

    inline double dot(Vec3& other) {
        return this->e[0] * other.e[0] + this->e[1] * other.e[1]
            + this->e[2] * other.e[2];
    }

    inline Vec3 cross(Vec3& other) {
        return Vec3(
            this->e[1] * other.e[2] - this->e[2] * other.e[1],
            this->e[2] * other.e[0] - this->e[0] * other.e[2],
            this->e[0] * other.e[1] - this->e[1] * other.e[0]
        );
    }



    Vec3 operator-() const {
        return Vec3(-e[0], -e[1], -e[2]);
    }

    double operator[](int i) const {
        return e[i];
    }

    double& operator[](int i) {
        return e[i];
    }

    Vec3& operator+=(const Vec3& other) {
        e[0] += other.e[0];
        e[1] += other.e[1];
        e[2] += other.e[2];
        return *this;
    }

    Vec3& operator*=(double constant) {
        e[0] *= constant;
        e[1] *= constant;
        e[2] *= constant;
        return *this;
    }

    Vec3& operator/=(double constant) {
        return *this *= 1 / constant;
    }

    double len_square() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }

    double len() const {
        return std::sqrt(len_square());
    }

    friend inline std::ostream& operator<<(std::ostream& out, const Vec3& vec) {
        return out << vec.e[0] << ' ' << vec.e[1] << ' ' << vec.e[2];
    }

    friend inline Vec3 operator+(const Vec3& self, const Vec3& other) {
        return Vec3(
            self.e[0] + other.e[0],
            self.e[1] + other.e[1],
            self.e[2] + other.e[2]
        );
    }

    friend inline Vec3 operator-(const Vec3& self, const Vec3& other) {
        return Vec3(
            self.e[0] - other.e[0],
            self.e[1] - other.e[1],
            self.e[2] - other.e[2]
        );
    }

    friend inline Vec3 operator*(const Vec3& self, const Vec3& other) {
        return Vec3(
            self.e[0] * other.e[0],
            self.e[1] * other.e[1],
            self.e[2] * other.e[2]
        );
    }

    friend inline Vec3 operator*(double constant, const Vec3& other) {
        return Vec3(
            constant * other.e[0],
            constant * other.e[1],
            constant * other.e[2]
        );
    }

    friend inline Vec3 operator*(const Vec3& other, double constant) {
        return constant * other;
    }

    friend inline Vec3 operator/(Vec3 self, double constant) {
        return (1 / constant) * self;
    }

    inline Vec3 unit() {
        return *this / this->len(); 
    }
};
