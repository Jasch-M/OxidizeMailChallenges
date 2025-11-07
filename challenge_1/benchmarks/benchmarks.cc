// ReSharper disable CppUseAuto
// ReSharper disable CppVariableCanBeMadeConstexpr
#include <benchmark/benchmark.h>
#include <challenge_1/src/lib.h>
#include <challenge_1/tests/structures.hh>
#include <cstring>


static void BM_RotateLeftPtrs_Ten(benchmark::State &state)
{
    const int count = 10;
    int **elements = new int *[count];
    for (int i = 0; i < count; ++i)
    {
        elements[i] = new int(i);
    }

    for (auto _: state)
    {
        rotate_left_ptrs(reinterpret_cast<void **>(elements), count);
    }

    for (int i = 0; i < count; ++i) delete elements[i];
    delete[] elements;
}

BENCHMARK(BM_RotateLeftPtrs_Ten);

static void BM_RotateLeftPtrs_Hundred(benchmark::State &state)
{
    const int count = 100;
    int **elements = new int *[count];
    for (int i = 0; i < count; ++i)
    {
        elements[i] = new int(i);
    }

    for (auto _: state)
    {
        rotate_left_ptrs(reinterpret_cast<void **>(elements), count);
    }

    for (int i = 0; i < count; ++i) delete elements[i];
    delete[] elements;
}

BENCHMARK(BM_RotateLeftPtrs_Hundred);

static void BM_RotateLeftPtrs_Thousand(benchmark::State &state)
{
    const int count = 1000;
    int **elements = new int *[count];
    for (int i = 0; i < count; ++i)
    {
        elements[i] = new int(i);
    }

    for (auto _: state)
    {
        rotate_left_ptrs(reinterpret_cast<void **>(elements), count);
    }

    for (int i = 0; i < count; ++i) delete elements[i];
    delete[] elements;
}

BENCHMARK(BM_RotateLeftPtrs_Thousand);

static void BM_RotateLeftPtrs_Struct_Point(benchmark::State &state)
{
    const int count = 100;
    Point **elements = new Point *[count];
    for (int i = 0; i < count; ++i)
    {
        elements[i] = new Point{i, -i};
    }

    for (auto _: state)
    {
        rotate_left_ptrs(reinterpret_cast<void **>(elements), count);
    }

    for (int i = 0; i < count; ++i) delete elements[i];
    delete[] elements;
}

BENCHMARK(BM_RotateLeftPtrs_Struct_Point);

static void BM_RotateLeftPtrs_Struct_NamedValue(benchmark::State &state)
{
    const int count = 100;
    NamedValue **elements = new NamedValue *[count];
    for (int i = 0; i < count; ++i)
    {
        elements[i] = new NamedValue{"Test", static_cast<double>(i)};
    }

    for (auto _: state)
    {
        rotate_left_ptrs(reinterpret_cast<void **>(elements), count);
    }

    for (int i = 0; i < count; ++i) delete elements[i];
    delete[] elements;
}

BENCHMARK(BM_RotateLeftPtrs_Struct_NamedValue);


static void BM_RotateLeftInplace_Ten(benchmark::State &state)
{
    const int count = 10;
    int *elements = new int[count];
    for (int i = 0; i < count; ++i) elements[i] = i;

    for (auto _: state)
    {
        rotate_left_inplace(elements, count);
    }

    delete[] elements;
}

BENCHMARK(BM_RotateLeftInplace_Ten);

static void BM_RotateLeftInplace_Hundred(benchmark::State &state)
{
    const int count = 100;
    int *elements = new int[count];
    for (int i = 0; i < count; ++i) elements[i] = i;

    for (auto _: state)
    {
        rotate_left_inplace(elements, count);
    }

    delete[] elements;
}

BENCHMARK(BM_RotateLeftInplace_Hundred);

static void BM_RotateLeftInplace_Thousand(benchmark::State &state)
{
    const int count = 1000;
    int *elements = new int[count];
    for (int i = 0; i < count; ++i) elements[i] = i;

    for (auto _: state)
    {
        rotate_left_inplace(elements, count);
    }

    delete[] elements;
}

BENCHMARK(BM_RotateLeftInplace_Thousand);

static void BM_RotateLeftInplace_TenThousand(benchmark::State &state)
{
    const int count = 10000;
    int *elements = new int[count];
    for (int i = 0; i < count; ++i) elements[i] = i;

    for (auto _: state)
    {
        rotate_left_inplace(elements, count);
    }

    delete[] elements;
}

BENCHMARK(BM_RotateLeftInplace_TenThousand);

static void BM_RotateLeftInplace_Million(benchmark::State &state)
{
    const int count = 1000000;
    int *elements = new int[count];
    for (int i = 0; i < count; ++i) elements[i] = i;

    for (auto _: state)
    {
        rotate_left_inplace(elements, count);
    }

    delete[] elements;
}

BENCHMARK(BM_RotateLeftInplace_Million);

static void BM_RotateLeftInplace_String(benchmark::State &state)
{
    const char *str = "Scores_Oxidize_Mail";
    const size_t len = strlen(str);
    int *elements = new int[len];
    for (size_t i = 0; i < len; ++i) elements[i] = str[i];

    for (auto _: state)
    {
        rotate_left_inplace(elements, len);
    }

    delete[] elements;
}

BENCHMARK(BM_RotateLeftInplace_String);


static void BM_RotateLeftGeneric_Int_Ten(benchmark::State &state)
{
    const int count = 10;
    int *elements = new int[count];
    for (int i = 0; i < count; ++i) elements[i] = i;

    for (auto _: state)
    {
        rotate_left_inplace_generic(elements, sizeof(int), count);
    }

    delete[] elements;
}

BENCHMARK(BM_RotateLeftGeneric_Int_Ten);

static void BM_RotateLeftGeneric_Int_Hundred(benchmark::State &state)
{
    const int count = 100;
    int *elements = new int[count];
    for (int i = 0; i < count; ++i) elements[i] = i;

    for (auto _: state)
    {
        rotate_left_inplace_generic(elements, sizeof(int), count);
    }

    delete[] elements;
}

BENCHMARK(BM_RotateLeftGeneric_Int_Hundred);

static void BM_RotateLeftGeneric_Int_Thousand(benchmark::State &state)
{
    const int count = 1000;
    int *elements = new int[count];
    for (int i = 0; i < count; ++i) elements[i] = i;

    for (auto _: state)
    {
        rotate_left_inplace_generic(elements, sizeof(int), count);
    }

    delete[] elements;
}

BENCHMARK(BM_RotateLeftGeneric_Int_Thousand);

static void BM_RotateLeftGeneric_Int_Million(benchmark::State &state)
{
    const int count = 1000000;
    int *elements = new int[count];
    for (int i = 0; i < count; ++i) elements[i] = i;

    for (auto _: state)
    {
        rotate_left_inplace_generic(elements, sizeof(int), count);
    }

    delete[] elements;
}

BENCHMARK(BM_RotateLeftGeneric_Int_Million);

static void BM_RotateLeftGeneric_Char(benchmark::State &state)
{
    const char *str = "Scores_Oxidize_Mail";
    const size_t len = strlen(str);
    char *elements = new char[len + 1];
    strcpy(elements, str);

    for (auto _: state)
    {
        rotate_left_inplace_generic(elements, sizeof(char), len);
    }

    delete[] elements;
}

BENCHMARK(BM_RotateLeftGeneric_Char);

static void BM_RotateLeftGeneric_Point_Ten(benchmark::State &state)
{
    const int count = 10;
    Point *elements = new Point[count];
    for (int i = 0; i < count; ++i) elements[i] = Point{i, -i};

    for (auto _: state)
    {
        rotate_left_inplace_generic(elements, sizeof(Point), count);
    }

    delete[] elements;
}

BENCHMARK(BM_RotateLeftGeneric_Point_Ten);

static void BM_RotateLeftGeneric_Point_Hundred(benchmark::State &state)
{
    const int count = 100;
    Point *elements = new Point[count];
    for (int i = 0; i < count; ++i) elements[i] = Point{i, -i};

    for (auto _: state)
    {
        rotate_left_inplace_generic(elements, sizeof(Point), count);
    }

    delete[] elements;
}

BENCHMARK(BM_RotateLeftGeneric_Point_Hundred);

static void BM_RotateLeftGeneric_RgbPixel_Hundred(benchmark::State &state)
{
    const int count = 100;
    RgbPixel *elements = new RgbPixel[count];
    for (int i = 0; i < count; ++i)
    {
        elements[i] = RgbPixel{
            static_cast<uint8_t>(i % 256),
            static_cast<uint8_t>((i * 2) % 256),
            static_cast<uint8_t>((i * 3) % 256)
        };
    }

    for (auto _: state)
    {
        rotate_left_inplace_generic(elements, sizeof(RgbPixel), count);
    }

    delete[] elements;
}

BENCHMARK(BM_RotateLeftGeneric_RgbPixel_Hundred);

static void BM_RotateLeftGeneric_NamedValue_Ten(benchmark::State &state)
{
    const int count = 10;
    NamedValue *elements = new NamedValue[count];
    for (int i = 0; i < count; ++i)
    {
        std::string name = "Val" + std::to_string(i);
        elements[i] = NamedValue{name, i * 1.0};
    }

    for (auto _: state)
    {
        rotate_left_inplace_generic(elements, sizeof(NamedValue), count);
    }

    delete[] elements;
}

BENCHMARK(BM_RotateLeftGeneric_NamedValue_Ten);

static void BM_RotateLeftGeneric_NamedValue_Hundred(benchmark::State &state)
{
    const int count = 100;
    NamedValue *elements = new NamedValue[count];
    for (int i = 0; i < count; ++i)
    {
        std::string name = "Val" + std::to_string(i);
        elements[i] = NamedValue{name, i * 1.0};
    }

    for (auto _: state)
    {
        rotate_left_inplace_generic(elements, sizeof(NamedValue), count);
    }

    delete[] elements;
}

BENCHMARK(BM_RotateLeftGeneric_NamedValue_Hundred);

BENCHMARK_MAIN();
