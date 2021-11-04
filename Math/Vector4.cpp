#include "Vector4.h"
#include "Mathf.h"

inline Vector4 Vector4::operator-() const {
    return Vector4(-x, -y, -z, -w);
}

inline Vector4 Vector4::operator+(const Vector4& rhs) const {
    return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}

inline Vector4 Vector4::operator-(const Vector4& rhs) const {
    return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

inline Vector4& Vector4::operator+=(const Vector4& rhs) {
    x += rhs.x; y += rhs.y; z += rhs.z; w += rhs.w; return *this;
}

inline Vector4& Vector4::operator-=(const Vector4& rhs) {
    x -= rhs.x; y -= rhs.y; z -= rhs.z; w -= rhs.w; return *this;
}

inline Vector4 Vector4::operator*(const float a) const {
    return Vector4(x * a, y * a, z * a, w * a);
}

inline Vector4 Vector4::operator*(const Vector4& rhs) const {
    return Vector4(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
}

inline Vector4& Vector4::operator*=(const float a) {
    x *= a; y *= a; z *= a; w *= a; return *this;
}

inline Vector4& Vector4::operator*=(const Vector4& rhs) {
    x *= rhs.x; y *= rhs.y; z *= rhs.z; w *= rhs.w; return *this;
}

inline Vector4 Vector4::operator/(const float a) const {
    return Vector4(x / a, y / a, z / a, w / a);
}

inline Vector4& Vector4::operator/=(const float a) {
    x /= a; y /= a; z /= a; w /= a; return *this;
}

inline bool Vector4::operator==(const Vector4& rhs) const {
    return (x == rhs.x) && (y == rhs.y) && (z == rhs.z) && (w == rhs.w);
}

inline bool Vector4::operator!=(const Vector4& rhs) const {
    return (x != rhs.x) || (y != rhs.y) || (z != rhs.z) || (w != rhs.w);
}

inline bool Vector4::operator<(const Vector4& rhs) const {
    if (x < rhs.x) return true;
    if (x > rhs.x) return false;
    if (y < rhs.y) return true;
    if (y > rhs.y) return false;
    if (z < rhs.z) return true;
    if (z > rhs.z) return false;
    if (w < rhs.w) return true;
    if (w > rhs.w) return false;
    return false;
}

inline float Vector4::operator[](int index) const {
    return (&x)[index];
}

inline float& Vector4::operator[](int index) {
    return (&x)[index];
}

inline void Vector4::set(float x, float y, float z, float w) {
    this->x = x; this->y = y; this->z = z; this->w = w;
}

//inline float Vector4::length() const {
//    return sqrtf(x * x + y * y + z * z + w * w);
//}
//
//inline float Vector4::distance(const Vector4& vec) const {
//    return sqrtf((vec.x - x) * (vec.x - x) + (vec.y - y) * (vec.y - y) + (vec.z - z) * (vec.z - z) + (vec.w - w) * (vec.w - w));
//}
//
//inline Vector4& Vector4::normalize() {
//    //NOTE: leave w-component untouched
//    //@@const float EPSILON = 0.000001f;
//    float xxyyzz = x * x + y * y + z * z;
//    //@@if(xxyyzz < EPSILON)
//    //@@    return *this; // do nothing if it is zero vector
//
//    //float invLength = invSqrt(xxyyzz);
//    float invLength = 1.0f / sqrtf(xxyyzz);
//    x *= invLength;
//    y *= invLength;
//    z *= invLength;
//    return *this;
//}

inline float Vector4::dot(const Vector4& rhs) const {
    return (x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w);
}

inline bool Vector4::equal(const Vector4& rhs, float epsilon) const {
    return Mathf::Fabs(x - rhs.x) < epsilon && Mathf::Fabs(y - rhs.y) < epsilon &&
        Mathf::Fabs(z - rhs.z) < epsilon && Mathf::Fabs(w - rhs.w) < epsilon;
}

inline Vector4 operator*(const float a, const Vector4 vec) {
    return Vector4(a * vec.x, a * vec.y, a * vec.z, a * vec.w);
}