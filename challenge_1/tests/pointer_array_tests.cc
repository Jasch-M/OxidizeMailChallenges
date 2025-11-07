// ReSharper disable CppUseAuto
#include <gtest/gtest.h>
#include <challenge_1/src/lib.h>
#include <cstring>
#include <new>

#include "structures.hh"


TEST(ArrayLeftPointerTests, Null)
{
    rotate_left_ptrs(nullptr, 0);
    SUCCEED();
}

TEST(ArrayLeftPointerTests, Stack_Empty)
{
    int elements[] = {};
    void *elements_void = elements;
    rotate_left_ptrs(&elements_void, sizeof(elements) / sizeof(int));
    SUCCEED();
}

TEST(ArrayLeftPointerTests, Heap_Empty)
{
    void **elements = new(std::nothrow) void *[0];
    if (!elements)
    {
        GTEST_SKIP() << "Failed to allocate memory for the test.";
    }
    rotate_left_ptrs(reinterpret_cast<void **>(&elements), 0);
    delete[] elements;
    SUCCEED();
}

TEST(ArrayLeftPointerTests, Stack_One_Element)
{
    int elements[] = {4};
    void *elements_void = elements;
    rotate_left_ptrs(&elements_void, 1);
    ASSERT_EQ(4, elements[0]);
}

TEST(ArrayLeftPointerTests, Heap_One_Element)
{
    int **elements = new(std::nothrow) int *[1];
    if (!elements)
    {
        GTEST_SKIP() << "Failed to allocate pointer array.";
    }

    elements[0] = new(std::nothrow) int(4);
    if (!elements[0])
    {
        delete[] elements;
        GTEST_SKIP() << "Failed to allocate element.";
    }

    rotate_left_ptrs(reinterpret_cast<void **>(elements), 1);

    ASSERT_EQ(4, *elements[0]);

    delete elements[0];
    delete[] elements;
}


TEST(ArrayLeftPointerTests, Stack_Two_Elements)
{
    int first_location = 4;
    int second_location = -2;

    int *elements[] = {&first_location, &second_location};
    int **elements_decayed = elements;
    void **elements_void = reinterpret_cast<void **>(elements_decayed);
    rotate_left_ptrs(elements_void, 2);

    ASSERT_EQ(-2, *elements[0]);
    ASSERT_EQ(4, *elements[1]);
}

TEST(ArrayLeftPointerTests, Heap_Two_Elements)
{
    int **elements = new(std::nothrow) int *[2];
    if (!elements)
    {
        GTEST_SKIP() << "Failed to allocate pointer array.";
    }

    elements[0] = new(std::nothrow) int(4);
    elements[1] = new(std::nothrow) int(-2);

    if (!elements[0] || !elements[1])
    {
        delete elements[0];
        delete elements[1];
        delete[] elements;
        GTEST_SKIP() << "Failed to allocate one or more elements.";
    }

    rotate_left_ptrs(reinterpret_cast<void **>(elements), 2);

    ASSERT_EQ(-2, *elements[0]);
    ASSERT_EQ(4, *elements[1]);

    delete elements[0];
    delete elements[1];
    delete[] elements;
}


TEST(ArrayLeftPointerTests, Stack_Three_Elements_Struct)
{
    Point first_location = {1, 2};
    Point second_location = {3, 4};
    Point third_location = {5, 6};

    Point *elements[] = {&first_location, &second_location, &third_location};
    Point **elements_decayed = elements;
    void **elements_void = reinterpret_cast<void **>(elements_decayed);
    rotate_left_ptrs(elements_void, 3);

    ASSERT_EQ((Point{3, 4}), *elements[0]);
    ASSERT_EQ((Point{5, 6}), *elements[1]);
    ASSERT_EQ((Point{1, 2}), *elements[2]);
}

TEST(ArrayLeftPointerTests, Heap_Three_Elements_Struct)
{
    Point **elements = new(std::nothrow) Point *[3];
    if (!elements)
    {
        GTEST_SKIP() << "Failed to allocate pointer array.";
    }

    elements[0] = new(std::nothrow) Point{1, 2};
    elements[1] = new(std::nothrow) Point{3, 4};
    elements[2] = new(std::nothrow) Point{5, 6};

    if (!elements[0] || !elements[1] || !elements[2])
    {
        delete elements[0];
        delete elements[1];
        delete elements[2];
        delete[] elements;
        GTEST_SKIP() << "Failed to allocate one or more Point elements.";
    }

    Point original_first = *elements[0];
    Point original_second = *elements[1];
    Point original_third = *elements[2];

    rotate_left_ptrs(reinterpret_cast<void **>(elements), 3);

    ASSERT_EQ(original_second, *elements[0]);
    ASSERT_EQ(original_third, *elements[1]);
    ASSERT_EQ(original_first, *elements[2]);

    delete elements[0];
    delete elements[1];
    delete elements[2];
    delete[] elements;
}


TEST(ArrayLeftPointerTests, Stack_Four_Elements)
{
    double first_location = 1.1;
    double second_location = 2.2;
    double third_location = 3.3;
    double forth_location = 4.4;

    double *elements[] = {&first_location, &second_location, &third_location, &forth_location};
    void **elements_void = reinterpret_cast<void **>(elements);
    rotate_left_ptrs(elements_void, 4);

    ASSERT_TRUE(abs(2.2 - *elements[0]) < 0.1);
    ASSERT_TRUE(abs(3.3 - *elements[1]) < 0.1);
    ASSERT_TRUE(abs(4.4 - *elements[2]) < 0.1);
    ASSERT_TRUE(abs(1.1 - *elements[3]) < 0.1);
}

TEST(ArrayLeftPointerTests, Heap_Four_Elements)
{
    float **elements = new(std::nothrow) float *[4];
    if (!elements)
    {
        GTEST_SKIP() << "Failed to allocate pointer array.";
    }

    for (int i = 0; i < 4; ++i)
    {
        elements[i] = new(std::nothrow) float((i + 1) * 1.1f);
        if (!elements[i])
        {
            for (int j = 0; j < i; ++j) delete elements[j];
            delete[] elements;
            GTEST_SKIP() << "Failed to allocate float element " << i;
        }
    }

    rotate_left_ptrs(reinterpret_cast<void **>(elements), 4);

    ASSERT_FLOAT_EQ(2.2f, *elements[0]);
    ASSERT_FLOAT_EQ(3.3f, *elements[1]);
    ASSERT_FLOAT_EQ(4.4f, *elements[2]);
    ASSERT_FLOAT_EQ(1.1f, *elements[3]);

    for (int i = 0; i < 4; ++i) delete elements[i];
    delete[] elements;
}

TEST(ArrayLeftPointerTests, Stack_Five_Elements_MixedStruct)
{
    RgbPixel first_location = {255, 0, 0};
    RgbPixel second_location = {0, 255, 0};
    RgbPixel third_location = {0, 0, 255};
    RgbPixel fourth_location = {128, 128, 0};
    RgbPixel fifth_location = {0, 128, 128};

    RgbPixel *elements[] = {&first_location, &second_location, &third_location, &fourth_location, &fifth_location};
    RgbPixel **elements_decayed = elements;
    void **elements_void = reinterpret_cast<void **>(elements_decayed);
    rotate_left_ptrs(elements_void, 5);

    ASSERT_EQ((RgbPixel{0,255,0}), *elements[0]);
    ASSERT_EQ((RgbPixel{0,0,255}), *elements[1]);
    ASSERT_EQ((RgbPixel{128,128,0}), *elements[2]);
    ASSERT_EQ((RgbPixel{0,128,128}), *elements[3]);
    ASSERT_EQ((RgbPixel{255,0,0}), *elements[4]);
}

TEST(ArrayLeftPointerTests, Heap_Five_Elements_MixedStruct)
{
    NamedValue **elements = new(std::nothrow) NamedValue *[5];
    if (!elements)
    {
        GTEST_SKIP() << "Failed to allocate pointer array.";
    }


    elements[0] = new(std::nothrow) NamedValue{"Alpha", 1.0};
    elements[1] = new(std::nothrow) NamedValue{"Beta", 2.0};
    elements[2] = new(std::nothrow) NamedValue{"Gamma", 3.0};
    elements[3] = new(std::nothrow) NamedValue{"Delta", 4.0};
    elements[4] = new(std::nothrow) NamedValue{"Epsilon", 5.0};

    bool allocation_failed = false;
    for (int i = 0; i < 5; ++i) if (!elements[i]) allocation_failed = true;

    if (allocation_failed)
    {
        for (int i = 0; i < 5; ++i) delete elements[i];
        delete[] elements;
        GTEST_SKIP() << "Failed to allocate one or more NamedValue elements.";
    }

    NamedValue original_first = *elements[0];
    NamedValue original_second = *elements[1];

    rotate_left_ptrs(reinterpret_cast<void **>(elements), 5);

    ASSERT_EQ(original_second, *elements[0]);
    ASSERT_EQ(*elements[4], original_first);

    for (int i = 0; i < 5; ++i) delete elements[i];
    delete[] elements;
}


TEST(ArrayLeftPointerTests, Stack_Ten_Elements)
{
    int first_location = 0;
    int second_location = 1;
    int third_location = 2;
    int fourth_location = 3;
    int fifth_location = 4;
    int sixth_location = 5;
    int seventh_location = 6;
    int eighth_location = 7;
    int ninth_location = 8;
    int tenth_location = 9;

    int *elements[] = {
        &first_location, &second_location, &third_location,
        &fourth_location, &fifth_location, &sixth_location,
        &seventh_location, &eighth_location, &ninth_location,
        &tenth_location
    };
    void **elements_void = reinterpret_cast<void **>(elements);
    rotate_left_ptrs(elements_void, 10);

    for (int i = 0; i < 9; ++i)
    {
        ASSERT_EQ(i + 1, *elements[i]);
    }
    ASSERT_EQ(0, *elements[9]);
}

TEST(ArrayLeftPointerTests, Heap_Ten_Elements)
{
    int **elements = new(std::nothrow) int *[10];
    if (!elements)
    {
        GTEST_SKIP() << "Failed to allocate pointer array.";
    }

    for (int i = 0; i < 10; ++i)
    {
        elements[i] = new(std::nothrow) int(i);
        if (!elements[i])
        {
            for (int j = 0; j < i; ++j) delete elements[j];
            delete[] elements;
            GTEST_SKIP() << "Failed to allocate element " << i;
        }
    }

    rotate_left_ptrs(reinterpret_cast<void **>(elements), 10);

    for (int i = 0; i < 9; ++i)
    {
        ASSERT_EQ(i + 1, *elements[i]);
    }
    ASSERT_EQ(0, *elements[9]);

    for (int i = 0; i < 10; ++i) delete elements[i];
    delete[] elements;
}


TEST(ArrayLeftPointerTests, Heap_Hundred_Elements)
{
    const int count = 100;
    int **elements = new(std::nothrow) int *[count];
    if (!elements)
    {
        GTEST_SKIP() << "Failed to allocate pointer array.";
    }

    for (int i = 0; i < count; ++i)
    {
        elements[i] = new(std::nothrow) int(i);
        if (!elements[i])
        {
            for (int j = 0; j < i; ++j) delete elements[j];
            delete[] elements;
            GTEST_SKIP() << "Failed to allocate element " << i;
        }
    }

    int original_first = *elements[0];
    int original_last = *elements[count - 1];

    rotate_left_ptrs(reinterpret_cast<void **>(elements), count);

    ASSERT_EQ(1, *elements[0]);
    ASSERT_EQ(original_last, *elements[count-2]);
    ASSERT_EQ(original_first, *elements[count-1]);

    for (int i = 0; i < count; ++i) delete elements[i];
    delete[] elements;
}

TEST(ArrayLeftPointerTests, Heap_Thousand_Elements)
{
    const int count = 1000;
    int **elements = new(std::nothrow) int *[count];
    if (!elements)
    {
        GTEST_SKIP() << "Failed to allocate pointer array.";
    }

    for (int i = 0; i < count; ++i)
    {
        elements[i] = new(std::nothrow) int(i);
        if (!elements[i])
        {
            for (int j = 0; j < i; ++j) delete elements[j];
            delete[] elements;
            GTEST_SKIP() << "Failed to allocate element " << i;
        }
    }

    rotate_left_ptrs(reinterpret_cast<void **>(elements), count);

    for (int i = 0; i < count - 1; ++i)
    {
        ASSERT_EQ(i + 1, *elements[i]);
    }
    ASSERT_EQ(0, *elements[count-1]);

    for (int i = 0; i < count; ++i) delete elements[i];
    delete[] elements;
}
