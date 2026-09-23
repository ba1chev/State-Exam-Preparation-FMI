#include "exercise_05.h"

int Color::clamp(const int value) {
    if (value < 0) {
        return 0;
    }
    if (value > 255) {
        return 255;
    }
    return value;
}

Color::Color(const int red, const int green, const int blue, const int alfa) {
    this->red = clamp(red);
    this->green = clamp(green);
    this->blue = clamp(blue);
    this->alfa = clamp(alfa);
}

Color& Color::operator += (const Color& other) {
    this->red = clamp(this->red + other.red);
    this->green = clamp(this->green + other.green);
    this->blue = clamp(this->blue + other.blue);
    this->alfa = clamp(this->alfa + other.alfa);

    return *this;
}

Color& Color::operator -= (const Color& other) {
    this->red = clamp(this->red - other.red);
    this->green = clamp(this->green - other.green);
    this->blue = clamp(this->blue - other.blue);
    this->alfa = clamp(this->alfa - other.alfa);

    return *this;
}

Color& Color::operator *= (const Color& other) {
    this->red = clamp(this->red * other.red / 255);
    this->green = clamp(this->green * other.green / 255);
    this->blue = clamp(this->blue * other.blue / 255);
    this->alfa = clamp(this->alfa * other.alfa / 255);

    return *this;
}

Color& Color::operator *= (const float scalar) {
    this->red = clamp((int)(this->red * scalar));
    this->green = clamp((int)(this->green * scalar));
    this->blue = clamp((int)(this->blue * scalar));

    return *this;
}

Color Color::operator ~ () const {
    return Color(255 - this->red, 255 - this->green, 255 - this->blue, this->alfa);
}

int& Color::operator [] (const size_t index) {
    if (index == 0) {
        return this->red;
    }
    if (index == 1) {
        return this->green;
    }
    if (index == 2) {
        return this->blue;
    }
    if (index == 3) {
        return this->alfa;
    }
    throw std::out_of_range("Index is out of range");
}

const int& Color::operator [] (const size_t index) const {
    if (index == 0) {
        return this->red;
    }
    if (index == 1) {
        return this->green;
    }
    if (index == 2) {
        return this->blue;
    }
    if (index == 3) {
        return this->alfa;
    }
    throw std::out_of_range("Index is out of range");
}

Color::operator bool () const {
    return this->alfa != 0;
}

std::ostream& operator << (std::ostream& os, const Color& color) {
    os << "rgba(" << color.red << ", " << color.green << ", "
        << color.blue << ", " << color.alfa << ")";
    return os;
}

std::istream& operator >> (std::istream& is, Color& color) {
    is >> color.red >> color.green >> color.blue >> color.alfa;
    return is;
}

Color operator + (const Color& left, const Color& right) {
    Color result = left;
    result += right;
    return result;
}

Color operator - (const Color& left, const Color& right) {
    Color result = left;
    result -= right;
    return result;
}

Color operator * (const Color& left, const Color& right) {
    Color result = left;
    result *= right;
    return result;
}

Color operator * (const Color& left, const float scalar) {
    Color result = left;
    result *= scalar;
    return result;
}

Color operator * (const float scalar, const Color& right) {
    Color result = right;
    result *= scalar;
    return result;
}

bool operator == (const Color& left, const Color& right) {
    return left[0] == right[0] && left[1] == right[1] &&
        left[2] == right[2] && left[3] == right[3];
}

bool operator != (const Color& left, const Color& right) {
    return !(left == right);
}
