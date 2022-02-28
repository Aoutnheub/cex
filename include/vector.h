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

        private:
            T x_, y_;
            double length_;
            bool recal_len = true;

        public:
            Vector2D() {}
            Vector2D(T _x, T _y) : x_(_x), y_(_y) {}

            T x() { return x_; }

            void x(T _x) { x_ = _x; recal_len = true; }

            T y() { return y_; }

            void y(T _y) { y_ = _y; recal_len = true; }

            void xy(T _x, T _y) {
                x_ = _x; y_ = _y;
                recal_len = true;
            }

            double length() {
                if(recal_len)
                    length_ = std::sqrt(x_ * x_ + y_ * y_);
                recal_len = false;

                return length_;
            }

            void normalize() {
                double len = length();
                x_ /= len; y_ /= len;
                recal_len = true;
            }

            Vector2D<T> normalized() {
                double len = length();
                return Vector2D<T>(x_ / len, y_ / len);
            }

            T dot(Vector2D<T> _vec) {
                return x_ * _vec.x() + y_ * _vec.y();
            }

            Vector2D<T> operator+(Vector2D<T> &_vec) {
                return Vector2D<T>(x_ + _vec.x(), y_ + _vec.y());
            }

            Vector2D<T> operator*(T _val) {
                return Vector2D<T>(x_ * _val, y_ * _val);
            }

            Vector2D<T> operator/(T _val) {
                return Vector2D<T>(x_ / _val, y_ / _val);
            }

            Vector2D<T> operator%(T _val) {
                return Vector2D<T>(x_ % _val, y_ % _val);
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

        private:
            T x_, y_, z_;
            double length_;
            bool recal_len = true;

        public:
            Vector3D() {}
            Vector3D(T _x, T _y, T _z) : x_(_x), y_(_y), z_(_z) {}

            T x() { return x_; }

            void x(T _x) { x_ = _x; recal_len = true; }

            T y() { return y_; }

            void y(T _y) { y_ = _y; recal_len = true; }

            T z() { return z_; }

            void z(T _z) { z_ = _z; recal_len = true; }

            void xyz(T _x, T _y, T _z) {
                x_ = _x; y_ = _y; z_ = _z;
                recal_len = true;
            }

            double length() {
                if(recal_len)
                    length_ = std::sqrt(x_ * x_ + y_ * y_ + z_ * z_);
                recal_len = false;

                return length_;
            }

            void normalize() {
                double len = length();
                x_ /= len; y_ /= len; z_ /= len;
                recal_len = true;
            }

            Vector3D<T> normalized() {
                double len = length();
                return Vector3D<T>(x_ / len, y_ / len, z_ / len);
            }

            T dot(Vector3D<T> _vec) {
                return x_ * _vec.x() + y_ * _vec.y() + z_ * _vec.z();
            }

            Vector3D<T> operator+(Vector3D<T> &_vec) {
                return Vector3D<T>(x_ + _vec.x(), y_ + _vec.y(), z_ + _vec.z());
            }

            Vector3D<T> operator*(T _val) {
                return Vector3D<T>(x_ * _val, y_ * _val, z_ * _val);
            }

            Vector3D<T> operator/(T _val) {
                return Vector3D<T>(x_ / _val, y_ / _val, z_ / _val);
            }

            Vector3D<T> operator%(T _val) {
                return Vector3D<T>(x_ % _val, y_ % _val, z_ % _val);
            }
    };

    template<typename T>
    class Vector4D {
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

        private:
            T x_, y_, z_, w_;
            double length_;
            bool recal_len = true;

        public:
            Vector4D() {}
            Vector4D(T _x, T _y, T _z, T _w) : x_(_x), y_(_y), z_(_z), w_(_w) {}

            T x() { return x_; }

            void x(T _x) { x_ = _x; recal_len = true; }

            T y() { return y_; }

            void y(T _y) { y_ = _y; recal_len = true; }

            T z() { return z_; }

            void z(T _z) { z_ = _z; recal_len = true; }

            T w() { return w_; }

            void w(T _w) { w_ = _w; recal_len = true; }

            void xyzw(T _x, T _y, T _z, T _w) {
                x_ = _x; y_ = _y; z_ = _z; w_ = _w;
                recal_len = true;
            }

            double length() {
                if(recal_len)
                    length_ = std::sqrt(x_ * x_ + y_ * y_ + z_ * z_ + w_ * w_);
                recal_len = false;

                return length_;
            }

            void normalize() {
                double len = length();
                x_ /= len; y_ /= len; z_ /= len; w_ /= len;
                recal_len = true;
            }

            Vector3D<T> normalized() {
                double len = length();
                return Vector3D<T>(x_ / len, y_ / len, z_ / len, w_ / len);
            }

            T dot(Vector4D<T> _vec) {
                return x_ * _vec.x() + y_ * _vec.y() + z_ * _vec.z() + w_ * _vec.w();
            }

            Vector4D<T> operator+(Vector3D<T> &_vec) {
                return Vector4D<T>(x_ + _vec.x(), y_ + _vec.y(), z_ + _vec.z(), w_ + _vec.w());
            }

            Vector4D<T> operator*(T _val) {
                return Vector4D<T>(x_ * _val, y_ * _val, z_ * _val, w_ * _val);
            }

            Vector4D<T> operator/(T _val) {
                return Vector4D<T>(x_ / _val, y_ / _val, z_ / _val, w_ / _val);
            }

            Vector4D<T> operator%(T _val) {
                return Vector4D<T>(x_ % _val, y_ % _val, z_ % _val, w_ % _val);
            }
    };
}
