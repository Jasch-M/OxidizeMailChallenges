#ifndef CHALLENGES_1_TESTS_STRUCTURES_HH
#define CHALLENGES_1_TESTS_STRUCTURES_HH

#include <ostream>
#include <string>
#include <cstring>
#include <cstdint>

struct Point
{
    int x;
    int y;

    Point()
        :x(0), y(0)
    { }

    Point(const int x, const int y)
        : x(x), y(y)
    { }

    bool operator==(const Point &other) const
    {
        return x == other.x && y == other.y;
    }

    friend std::ostream &operator<<(std::ostream &os, const Point &point)
    {
        return os << "Point(" << point.x << ", " << point.y << ")";
    }
};

struct RgbPixel
{
    uint8_t red, green, blue;

    RgbPixel()
        : red(0), green(0), blue(0)
    { }

    RgbPixel(const int red, const int green, const int blue)
        : red(red), green(green), blue(blue)
    { }

    bool operator==(const RgbPixel &other) const
    {
        return red == other.red && green == other.green && blue == other.blue;
    }

    friend std::ostream &operator<<(std::ostream &os, const RgbPixel &rgb_pixel)
    {
        return os << "RGB(" << static_cast<int>(rgb_pixel.red) << ", "
               << static_cast<int>(rgb_pixel.green) << ", "
               << static_cast<int>(rgb_pixel.blue) << ")";
    }
};


struct NamedValue
{
    char name[16];
    double value;

    NamedValue()
        : name{}, value(0)
    {

    }

    NamedValue(const std::string &name, const double value)
        : name{}, value(value)
    {
        for (int i = 0; i < 16; i++)
        {
            this->name[i] = name[i];
        }
    }

    bool operator==(const NamedValue &other) const
    {
        return strcmp(name, other.name) == 0 && value == other.value;
    }

    friend std::ostream &operator<<(std::ostream &os, const NamedValue &named_value)
    {
        return os << "NamedValue(\"" << named_value.name << "\", " << named_value.value << ")";
    }
};

#endif //CHALLENGES_1_TESTS_STRUCTURES_HH