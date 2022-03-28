#pragma once
#include <type_traits>
#include <cstdint>
#include <cmath>

namespace cex {
    template<typename T>
    class Vector2D {
        static_assert(
            std::is_same<T, std::uint8_t>::value ||
            std::is_same<T, std::int8_t>::value ||
            std::is_same<T, std::uint16_t>::value ||
            std::is_same<T, std::int16_t>::value ||
            std::is_same<T, std::uint32_t>::value ||
            std::is_same<T, std::int32_t>::value ||
            std::is_same<T, std::uint64_t>::value ||
            std::is_same<T, std::int64_t>::value ||
            std::is_same<T, float>::value ||
            std::is_same<T, double>::value,
            "Only integer and float types allowed"
        );

        public:
            T x, y;

            Vector2D() {}
            Vector2D(T _x, T _y) : x(_x), y(_y) {}

            float length() {
                return std::sqrt(x * x + y * y);
            }

            // float angle() {}

            // float angleTo(Vector2D<T> _vec) {}

            T dot(Vector2D<T> _vec) {
                return x * _vec.x + y * _vec.y;
            }

            T sum() { return x + y; }

            Vector2D<T> normalize() {
                double len = length();
                return Vector2D<T>(x / len, y / len);
            }

            Vector2D<T> sin() {
                return Vector2D<T>(std::sin(x), std::sin(y));
            }

            Vector2D<T> cos() {
                return Vector2D<T>(std::cos(x), std::cos(y));
            }

            Vector2D<T> tan() {
                return Vector2D<T>(std::tan(x), std::tan(y));
            }

            Vector2D<T> cot() {
                return Vector2D<T>(1 / std::tan(x), 1 / std::tan(y));
            }

            Vector2D<T> abs() {
                return Vector2D<T>(std::abs(x), std::abs(y));
            }

            Vector2D<T> ceil() {
                return Vector2D<T>(std::ceil(x), std::ceil(y));
            }

            Vector2D<T> floor() {
                return Vector2D<T>(std::floor(x), std::floor(y));
            }

            Vector2D<T> round() {
                return Vector2D<T>(std::round(x), std::round(y));
            }

            // Vector2D<T> clamp(float _len) {}

            Vector2D<T> operator+(T _val) {
                return Vector2D<T>(x + _val, y + _val);
            }

            Vector2D<T> operator+(Vector2D<T> _vec) {
                return Vector2D<T>(x + _vec.x, y + _vec.y);
            }

            Vector2D<T> operator*(T _val) {
                return Vector2D<T>(x * _val, y * _val);
            }

            Vector2D<T> operator*(Vector2D<T> _vec) {
                return Vector2D<T>(x * _vec.x, y * _vec.y);
            }

            Vector2D<T> operator/(T _val) {
                return Vector2D<T>(x / _val, y / _val);
            }

            Vector2D<T> operator/(Vector2D<T> _vec) {
                return Vector2D<T>(x / _vec.x, y / _vec.y);
            }

            Vector2D<T> operator%(T _val) {
                return Vector2D<T>(x % _val, y % _val);
            }

            Vector2D<T> operator%(Vector2D<T> _vec) {
                return Vector2D<T>(x % _vec.x, y % _vec.y);
            }
    };

    template<typename T>
    class Vector3D {
        static_assert(
            std::is_same<T, std::uint8_t>::value ||
            std::is_same<T, std::int8_t>::value ||
            std::is_same<T, std::uint16_t>::value ||
            std::is_same<T, std::int16_t>::value ||
            std::is_same<T, std::uint32_t>::value ||
            std::is_same<T, std::int32_t>::value ||
            std::is_same<T, std::uint64_t>::value ||
            std::is_same<T, std::int64_t>::value ||
            std::is_same<T, float>::value ||
            std::is_same<T, double>::value,
            "Only integer and float types allowed"
        );

        public:
            T x, y, z;

            Vector3D() {}
            Vector3D(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}

            float length() {
                return std::sqrt(x * x + y * y + z * z);
            }

            // float angleTo(Vector3D<T> _vec) {}

            T dot(Vector3D<T> _vec) {
                return x * _vec.x + y * _vec.y + z * _vec.z;
            }

            T sum() { return x + y + z; }

            Vector3D<T> normalize() {
                double len = length();
                return Vector3D<T>(x / len, y / len, z / len);
            }

            Vector3D<T> sin() {
                return Vector3D<T>(std::sin(x), std::sin(y), std::sin(z));
            }

            Vector3D<T> cos() {
                return Vector3D<T>(std::cos(x), std::cos(y), std::cos(z));
            }

            Vector3D<T> tan() {
                return Vector3D<T>(std::tan(x), std::tan(y), std::tan(z));
            }

            Vector3D<T> cot() {
                return Vector3D<T>(1 / std::tan(x), 1 / std::tan(y), 1 / std::tan(z));
            }

            Vector3D<T> abs() {
                return Vector3D<T>(std::abs(x), std::abs(y), std::abs(z));
            }

            Vector3D<T> ceil() {
                return Vector3D<T>(std::ceil(x), std::ceil(y), std::ceil(z));
            }

            Vector3D<T> floor() {
                return Vector3D<T>(std::floor(x), std::floor(y), std::floor(z));
            }

            Vector3D<T> round() {
                return Vector3D<T>(std::round(x), std::round(y), std::round(z));
            }

            Vector3D<T> cross(Vector3D<T> _vec) {
                return Vector3D<T>(
                    y * _vec.z - z * _vec.y,
                    z * _vec.x - x * _vec.z,
                    x * _vec.y - y * _vec.x
                );
            }

            Vector3D<T> operator+(T _val) {
                return Vector3D<T>(x + _val, y + _val, z + _val);
            }

            Vector3D<T> operator+(Vector3D<T> _vec) {
                return Vector3D<T>(x + _vec.x, y + _vec.y, z + _vec.z);
            }

            Vector3D<T> operator*(T _val) {
                return Vector3D<T>(x * _val, y * _val, z * _val);
            }

            Vector3D<T> operator*(Vector3D<T> _vec) {
                return Vector3D<T>(x * _vec.x, y * _vec.y, z * _vec.z);
            }

            Vector3D<T> operator/(T _val) {
                return Vector3D<T>(x / _val, y / _val, z / _val);
            }

            Vector3D<T> operator/(Vector3D<T> _vec) {
                return Vector3D<T>(x / _vec.x, y / _vec.y, z / _vec.z);
            }

            Vector3D<T> operator%(T _val) {
                return Vector3D<T>(x % _val, y % _val, z % _val);
            }

            Vector3D<T> operator%(Vector3D<T> _vec) {
                return Vector3D<T>(x % _vec.x, y % _vec.y, z % _vec.z);
            }
    };
}
