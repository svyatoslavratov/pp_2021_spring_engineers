#include <gtest/gtest.h>
#include <algorithm>

#include "./hoare_sort_omp.h"

TEST(Hoare_Sort_Simple_Merge_OpenMP, Empty_Vector)
{
    std::vector<int> v = getRandomVector(0);
    int lastIndex = static_cast<int>(v.size() - 1);
    ASSERT_NO_THROW(hoareSort(&v, 0, lastIndex));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge_OpenMP, Positive_Numbers)
{
    std::vector<int> v = getRandomVector(100, 1);
    int lastIndex = static_cast<int>(v.size() - 1);
    ASSERT_NO_THROW(hoareSort(&v, 0, lastIndex));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge_OpenMP, Numbers_Small_Size)
{
    std::vector<int> v = getRandomVector(100);
    int lastIndex = static_cast<int>(v.size() - 1);
    ASSERT_NO_THROW(hoareSort(&v, 0, lastIndex));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge_OpenMP, Numbers_Big_Size)
{
    std::vector<int> v = getRandomVector(10000);
    int lastIndex = static_cast<int>(v.size() - 1);
    ASSERT_NO_THROW(hoareSort(&v, 0, lastIndex));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge_OpenMP, Already_Sorted)
{
    std::vector<int> v = getRandomVector(100, 2);
    int lastIndex = static_cast<int>(v.size() - 1);
    ASSERT_NO_THROW(hoareSort(&v, 0, lastIndex));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge_OpenMP, Worst_Case_Unsorted)
{
    std::vector<int> v = getRandomVector(100, 3);
    int lastIndex = static_cast<int>(v.size() - 1);
    ASSERT_NO_THROW(hoareSort(&v, 0, lastIndex));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge_OpenMP, Left_Empty)
{
    std::vector<int> v = getRandomVector(100);
    int lastIndex = static_cast<int>(v.size() - 1);
    hoareSort(&v, 0, lastIndex);
    ASSERT_NO_THROW(merge(&v, 0, 0, v.size() - 1));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge_OpenMP, Right_Empty)
{
    std::vector<int> v = getRandomVector(100);
    int lastIndex = static_cast<int>(v.size() - 1);
    hoareSort(&v, 0, lastIndex);
    ASSERT_NO_THROW(merge(&v, 0, v.size() - 1, v.size() - 1));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge_OpenMP, Same_Size)
{
    std::vector<int> v = getRandomVector(100);
    int lastIndex = static_cast<int>(v.size() - 1);
    int midIndex = v.size() / 2;
    hoareSort(&v, 0, midIndex);
    hoareSort(&v, midIndex + 1, lastIndex);
    ASSERT_NO_THROW(merge(&v, 0, midIndex, v.size() - 1));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge_OpenMP, Different_Size)
{
    std::vector<int> v = getRandomVector(100);
    int lastIndex = static_cast<int>(v.size() - 1);
    int divisionIndex = v.size() / 8;
    hoareSort(&v, 0, divisionIndex);
    hoareSort(&v, divisionIndex + 1, lastIndex);
    ASSERT_NO_THROW(merge(&v, 0, divisionIndex, v.size() - 1));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge_OpenMP, Large_Vectors)
{
    std::vector<int> v = getRandomVector(10000);
    int lastIndex = static_cast<int>(v.size() - 1);
    int midIndex = v.size() / 2;
    hoareSort(&v, 0, midIndex);
    hoareSort(&v, midIndex + 1, lastIndex);
    ASSERT_NO_THROW(merge(&v, 0, midIndex, v.size() - 1));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge_OpenMP, Even_Size)
{
    std::vector<int> v = getRandomVector(1000000);
    ASSERT_NO_THROW(runHoareSort(&v));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge_OpenMP, Odd_Size)
{
    std::vector<int> v = getRandomVector(2222222);
    ASSERT_NO_THROW(runHoareSort(&v));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
