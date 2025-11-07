// ReSharper disable CppUseAuto
#include <gtest/gtest.h>
#include <challenge_1/src/lib.h>

TEST(ArrayLeftInplaceTests, Null) {
    rotate_left_inplace(nullptr, 0);
    SUCCEED();
}

TEST(ArrayLeftInplaceTests, Stack_Empty) {
    int elements[] = { };
    rotate_left_inplace(elements, 0);
    SUCCEED();
}

TEST(ArrayLeftInplaceTests, Heap_Empty) {
    int* elements = new(std::nothrow) int[0];
    if (!elements) {
        GTEST_SKIP() << "Failed to allocate memory for the test.";
    }
    rotate_left_inplace(elements, 0);
    delete[] elements;
    SUCCEED();
}

TEST(ArrayLeftInplaceTests, Stack_One_Element) {
    int elements[] = { 4 };
    rotate_left_inplace(elements, 1);
    ASSERT_EQ(4, elements[0]);
}

TEST(ArrayLeftInplaceTests, Heap_One_Element) {
    int* elements = new(std::nothrow) int[1];
    if (!elements) GTEST_SKIP() << "Failed to allocate element.";
    elements[0] = 4;
    rotate_left_inplace(elements, 1);
    ASSERT_EQ(4, elements[0]);
    delete[] elements;
}

TEST(ArrayLeftInplaceTests, Stack_Two_Elements) {
    int elements[] = { 4, -2 };
    rotate_left_inplace(elements, 2);
    ASSERT_EQ(-2, elements[0]);
    ASSERT_EQ(4, elements[1]);
}

TEST(ArrayLeftInplaceTests, Heap_Two_Elements) {
    int* elements = new(std::nothrow) int[2];
    if (!elements) GTEST_SKIP() << "Failed to allocate elements.";
    elements[0] = 4;
    elements[1] = -2;
    rotate_left_inplace(elements, 2);
    ASSERT_EQ(-2, elements[0]);
    ASSERT_EQ(4, elements[1]);
    delete[] elements;
}

TEST(ArrayLeftInplaceTests, Stack_Three_Elements) {
    int elements[] = {1, 2, 3};
    rotate_left_inplace(elements, 3);
    ASSERT_EQ(2, elements[0]);
    ASSERT_EQ(3, elements[1]);
    ASSERT_EQ(1, elements[2]);
}

TEST(ArrayLeftInplaceTests, Heap_Three_Elements) {
    int* elements = new(std::nothrow) int[3];
    if (!elements) GTEST_SKIP() << "Failed to allocate elements.";
    elements[0] = 1;
    elements[1] = 2;
    elements[2] = 3;
    rotate_left_inplace(elements, 3);
    ASSERT_EQ(2, elements[0]);
    ASSERT_EQ(3, elements[1]);
    ASSERT_EQ(1, elements[2]);
    delete[] elements;
}

TEST(ArrayLeftInplaceTests, Stack_Ten_Elements) {
    int elements[10];
    for (int i = 0; i < 10; ++i) elements[i] = i;
    rotate_left_inplace(elements, 10);
    for (int i = 0; i < 9; ++i) {
        ASSERT_EQ(i + 1, elements[i]);
    }
    ASSERT_EQ(0, elements[9]);
}

TEST(ArrayLeftInplaceTests, Heap_Ten_Elements) {
    const int count = 10;
    int* elements = new(std::nothrow) int[count];
    if (!elements) GTEST_SKIP() << "Failed to allocate elements.";
    for (int i = 0; i < count; ++i) elements[i] = i;
    rotate_left_inplace(elements, count);
    for (int i = 0; i < count - 1; ++i) {
        ASSERT_EQ(i + 1, elements[i]);
    }
    ASSERT_EQ(0, elements[count - 1]);
    delete[] elements;
}

TEST(ArrayLeftInplaceTests, Stack_Scores_Oxidize_Mail_As_Ints) {
    const char* str = "Scores_Oxidize_Mail";
    const size_t len = strlen(str);
    int elements[20];
    for(size_t i = 0; i < len; ++i) elements[i] = str[i];

    rotate_left_inplace(elements, len);

    const char* expected_str = "cores_Oxidize_MailS";
    for(size_t i = 0; i < len; ++i) {
        ASSERT_EQ(expected_str[i], elements[i]);
    }
}

TEST(ArrayLeftInplaceTests, Heap_Scores_Oxidize_Mail_As_Ints) {
    const char* str = "Scores_Oxidize_Mail";
    const size_t len = strlen(str);
    int* elements = new(std::nothrow) int[len];
    if (!elements) GTEST_SKIP() << "Failed to allocate elements.";

    for(size_t i = 0; i < len; ++i) elements[i] = str[i];

    rotate_left_inplace(elements, len);

    const char* expected_str = "cores_Oxidize_MailS";
    for(size_t i = 0; i < len; ++i) {
        ASSERT_EQ(expected_str[i], elements[i]);
    }
    delete[] elements;
}


TEST(ArrayLeftInplaceTests, Stack_Hundred_Elements) {
    int elements[100];
    for (int i = 0; i < 100; ++i) elements[i] = i;
    rotate_left_inplace(elements, 100);
    for (int i = 0; i < 99; ++i) {
        ASSERT_EQ(i + 1, elements[i]);
    }
    ASSERT_EQ(0, elements[99]);
}

TEST(ArrayLeftInplaceTests, Heap_Hundred_Elements) {
    const int count = 100;
    int* elements = new(std::nothrow) int[count];
    if (!elements) GTEST_SKIP() << "Failed to allocate elements.";
    for (int i = 0; i < count; ++i) elements[i] = i;
    rotate_left_inplace(elements, count);
    for (int i = 0; i < count - 1; ++i) {
        ASSERT_EQ(i + 1, elements[i]);
    }
    ASSERT_EQ(0, elements[count - 1]);
    delete[] elements;
}

TEST(ArrayLeftInplaceTests, Stack_Thousand_Elements) {
    // This test is possible on the stack, but approaches the default limit on some systems.
    int elements[1000];
    for (int i = 0; i < 1000; ++i) elements[i] = i;
    rotate_left_inplace(elements, 1000);
    for (int i = 0; i < 999; ++i) {
        ASSERT_EQ(i + 1, elements[i]);
    }
    ASSERT_EQ(0, elements[999]);
}

TEST(ArrayLeftInplaceTests, Heap_Thousand_Elements) {
    const int count = 1000;
    int* elements = new(std::nothrow) int[count];
    if (!elements) GTEST_SKIP() << "Failed to allocate elements.";
    for (int i = 0; i < count; ++i) elements[i] = i;
    rotate_left_inplace(elements, count);
    for (int i = 0; i < count - 1; ++i) {
        ASSERT_EQ(i + 1, elements[i]);
    }
    ASSERT_EQ(0, elements[count - 1]);
    delete[] elements;
}

TEST(ArrayLeftInplaceTests, Heap_Million_Elements) {
    // A stack-based version of this test would cause a stack overflow.
    const int count = 1000000;
    int* elements = new(std::nothrow) int[count];
    if (!elements) GTEST_SKIP() << "Failed to allocate elements for 1M test.";

    for (int i = 0; i < count; ++i) elements[i] = i;

    rotate_left_inplace(elements, count);

    for (int i = 0; i < count - 1; ++i) {
        ASSERT_EQ(i + 1, elements[i]);
    }
    ASSERT_EQ(0, elements[count - 1]);
    delete[] elements;
}