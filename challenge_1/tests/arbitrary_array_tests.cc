// ReSharper disable CppUseAuto
#include <gtest/gtest.h>
#include <challenge_1/src/lib.h>
#include "structures.hh"

TEST(ArrayLeftInplaceGenericTests, Null) {
    ASSERT_EQ(0, rotate_left_inplace_generic(nullptr, sizeof(int), 0));
}

TEST(ArrayLeftInplaceGenericTests, Stack_Empty) {
    int elements[] = {};
    ASSERT_EQ(0, rotate_left_inplace_generic(elements, sizeof(int), 0));
}

TEST(ArrayLeftInplaceGenericTests, Heap_Empty) {
    Point* elements = new(std::nothrow) Point[0];
    if (!elements) {
        GTEST_SKIP() << "Failed to allocate memory for the test.";
    }
    ASSERT_EQ(0, rotate_left_inplace_generic(elements, sizeof(Point), 0));
    delete[] elements;
}

TEST(ArrayLeftInplaceGenericTests, Stack_One_Element) {
    Point element = {10, 20};
    ASSERT_EQ(0, rotate_left_inplace_generic(&element, sizeof(Point), 1));
    ASSERT_EQ(Point(10, 20), element);
}

TEST(ArrayLeftInplaceGenericTests, Heap_One_Element) {
    NamedValue* elements = new(std::nothrow) NamedValue[1];
    if (!elements) GTEST_SKIP() << "Failed to allocate element.";
    elements[0] = NamedValue("Test", 99.9);

    ASSERT_EQ(0, rotate_left_inplace_generic(elements, sizeof(NamedValue), 1));
    ASSERT_EQ(NamedValue("Test", 99.9), elements[0]);
    delete[] elements;
}

TEST(ArrayLeftInplaceGenericTests, Stack_Two_Elements) {
    RgbPixel elements[] = {RgbPixel(255, 0, 0), RgbPixel(0, 255, 0)};
    ASSERT_EQ(0, rotate_left_inplace_generic(elements, sizeof(RgbPixel), 2));
    ASSERT_EQ(RgbPixel(0, 255, 0), elements[0]);
    ASSERT_EQ(RgbPixel(255, 0, 0), elements[1]);
}

TEST(ArrayLeftInplaceGenericTests, Heap_Two_Elements) {
    int* elements = new(std::nothrow) int[2];
    if (!elements) GTEST_SKIP() << "Failed to allocate elements.";
    elements[0] = 100;
    elements[1] = 200;

    ASSERT_EQ(0, rotate_left_inplace_generic(elements, sizeof(int), 2));

    ASSERT_EQ(200, elements[0]);
    ASSERT_EQ(100, elements[1]);
    delete[] elements;
}

TEST(ArrayLeftInplaceGenericTests, Stack_Three_Elements) {
    Point elements[] = {Point(1, 2), Point(3, 4), Point(5, 6)};
    ASSERT_EQ(0, rotate_left_inplace_generic(elements, sizeof(Point), 3));
    ASSERT_EQ(Point(3, 4), elements[0]);
    ASSERT_EQ(Point(5, 6), elements[1]);
    ASSERT_EQ(Point(1, 2), elements[2]);
}

TEST(ArrayLeftInplaceGenericTests, Heap_Three_Elements) {
    Point* elements = new(std::nothrow) Point[3];
    if (!elements) GTEST_SKIP() << "Failed to allocate elements.";
    elements[0] = {1, 2};
    elements[1] = {3, 4};
    elements[2] = {5, 6};

    ASSERT_EQ(0, rotate_left_inplace_generic(elements, sizeof(Point), 3));

    ASSERT_EQ(Point(3, 4), elements[0]);
    ASSERT_EQ(Point(5, 6), elements[1]);
    ASSERT_EQ(Point(1, 2), elements[2]);
    delete[] elements;
}

TEST(ArrayLeftInplaceGenericTests, Stack_Ten_Elements_NamedValue) {
    NamedValue elements[10];
    for (int i = 0; i < 10; ++i) {
        std::string name = "Val" + std::to_string(i);
        elements[i] = NamedValue(name, i * 1.0);
    }

    NamedValue first_element = elements[0];

    ASSERT_EQ(0, rotate_left_inplace_generic(elements, sizeof(NamedValue), 10));

    for (int i = 0; i < 9; ++i) {
        ASSERT_EQ(elements[i].value, (i + 1) * 1.0);
    }
    ASSERT_EQ(elements[9], first_element);
}

TEST(ArrayLeftInplaceGenericTests, Heap_Ten_Elements) {
    const int count = 10;
    int* elements = new(std::nothrow) int[count];
    if (!elements) GTEST_SKIP() << "Failed to allocate elements.";
    for (int i = 0; i < count; ++i) elements[i] = i;

    ASSERT_EQ(0, rotate_left_inplace_generic(elements, sizeof(int), count));

    for (int i = 0; i < count - 1; ++i) {
        ASSERT_EQ(i + 1, elements[i]);
    }
    ASSERT_EQ(0, elements[count - 1]);
    delete[] elements;
}

TEST(ArrayLeftInplaceGenericTests, Stack_Scores_Oxidize_Mail) {
    char elements[] = "Scores_Oxidize_Mail";
    const size_t len = strlen(elements);

    ASSERT_EQ(0, rotate_left_inplace_generic(elements, sizeof(char), len));
    ASSERT_STREQ("cores_Oxidize_MailS", elements);
}

TEST(ArrayLeftInplaceGenericTests, Heap_Scores_Oxidize_Mail) {
    const char* str = "Scores_Oxidize_Mail";
    const size_t len = strlen(str);
    char* elements = new(std::nothrow) char[len + 1];
    if (!elements) GTEST_SKIP() << "Failed to allocate elements.";
    strcpy(elements, str);

    ASSERT_EQ(0, rotate_left_inplace_generic(elements, sizeof(char), len));

    ASSERT_STREQ("cores_Oxidize_MailS", elements);
    delete[] elements;
}


TEST(ArrayLeftInplaceGenericTests, Stack_Hundred_Elements) {
    Point elements[100];
    for (int i = 0; i < 100; ++i) elements[i] = Point(i, -i);
    Point first_element = elements[0];

    ASSERT_EQ(0, rotate_left_inplace_generic(elements, sizeof(Point), 100));

    for (int i = 0; i < 99; ++i) {
        ASSERT_EQ(Point(i + 1, -(i + 1)), elements[i]);
    }
    ASSERT_EQ(first_element, elements[99]);
}

TEST(ArrayLeftInplaceGenericTests, Heap_Hundred_Elements) {
    const int count = 100;
    int* elements = new(std::nothrow) int[count];
    if (!elements) GTEST_SKIP() << "Failed to allocate elements.";
    for (int i = 0; i < count; ++i) elements[i] = i;

    ASSERT_EQ(0, rotate_left_inplace_generic(elements, sizeof(int), count));

    for (int i = 0; i < count - 1; ++i) {
        ASSERT_EQ(i + 1, elements[i]);
    }
    ASSERT_EQ(0, elements[count - 1]);
    delete[] elements;
}

TEST(ArrayLeftInplaceGenericTests, Heap_Thousand_Elements) {
    const int count = 1000;
    int* elements = new(std::nothrow) int[count];
    if (!elements) GTEST_SKIP() << "Failed to allocate elements.";
    for (int i = 0; i < count; ++i) elements[i] = i;

    ASSERT_EQ(0, rotate_left_inplace_generic(elements, sizeof(int), count));

    for (int i = 0; i < count - 1; ++i) {
        ASSERT_EQ(i + 1, elements[i]);
    }
    ASSERT_EQ(0, elements[count - 1]);
    delete[] elements;
}

TEST(ArrayLeftInplaceGenericTests, Heap_Million_Elements) {
    const int count = 1000000;
    int* elements = new(std::nothrow) int[count];
    if (!elements) GTEST_SKIP() << "Failed to allocate elements for 1M test.";
    for (int i = 0; i < count; ++i) elements[i] = i;

    ASSERT_EQ(0, rotate_left_inplace_generic(elements, sizeof(int), count));

    for (int i = 0; i < count - 1; ++i) {
        ASSERT_EQ(i + 1, elements[i]);
    }
    ASSERT_EQ(0, elements[count - 1]);
    delete[] elements;
}