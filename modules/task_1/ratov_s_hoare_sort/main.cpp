#include <gtest/gtest.h>
#include <algorithm>

#include "./hoare_sort.h"

TEST(Hoare_Sort_Simple_Merge, Empty_Vector)
{
    std::vector<int> v = getRandomVector(0);
    int lastIndex = static_cast<int>(v.size() - 1);
    ASSERT_NO_THROW(hoareSort(&v, 0, lastIndex));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge, Positive_Numbers)
{
    std::vector<int> v = getRandomVector(100, 1);
    int lastIndex = static_cast<int>(v.size() - 1);
    ASSERT_NO_THROW(hoareSort(&v, 0, lastIndex));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge, Numbers_Small_Size)
{
    std::vector<int> v = getRandomVector(100);
    int lastIndex = static_cast<int>(v.size() - 1);
    ASSERT_NO_THROW(hoareSort(&v, 0, lastIndex));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge, Numbers_Big_Size)
{
    std::vector<int> v = getRandomVector(10000);
    int lastIndex = static_cast<int>(v.size() - 1);
    ASSERT_NO_THROW(hoareSort(&v, 0, lastIndex));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge, Already_Sorted)
{
    std::vector<int> v = getRandomVector(100, 2);
    int lastIndex = static_cast<int>(v.size() - 1);
    ASSERT_NO_THROW(hoareSort(&v, 0, lastIndex));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge, Worst_Case_Unsorted)
{
    std::vector<int> v = getRandomVector(100, 3);
    int lastIndex = static_cast<int>(v.size() - 1);
    ASSERT_NO_THROW(hoareSort(&v, 0, lastIndex));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge, Left_Empty)
{
    std::vector<int> v = getRandomVector(100);
    int lastIndex = static_cast<int>(v.size() - 1);
    hoareSort(&v, 0, lastIndex);
    ASSERT_NO_THROW(merge(&v, 0, 0, v.size() - 1));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge, Right_Empty)
{
    std::vector<int> v = getRandomVector(100);
    int lastIndex = static_cast<int>(v.size() - 1);
    hoareSort(&v, 0, lastIndex);
    ASSERT_NO_THROW(merge(&v, 0, v.size() - 1, v.size() - 1));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge, Same_Size)
{
    std::vector<int> v = getRandomVector(100);
    int lastIndex = static_cast<int>(v.size() - 1);
    int midIndex = v.size() / 2;
    hoareSort(&v, 0, midIndex);
    hoareSort(&v, midIndex + 1, lastIndex);
    ASSERT_NO_THROW(merge(&v, 0, midIndex, v.size() - 1));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge, Different_Size)
{
    std::vector<int> v = getRandomVector(100);
    int lastIndex = static_cast<int>(v.size() - 1);
    int divisionIndex = v.size() / 8;
    hoareSort(&v, 0, divisionIndex);
    hoareSort(&v, divisionIndex + 1, lastIndex);
    ASSERT_NO_THROW(merge(&v, 0, divisionIndex, v.size() - 1));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge, Large_Vectors)
{
    std::vector<int> v = getRandomVector(10000);
    int lastIndex = static_cast<int>(v.size() - 1);
    int midIndex = v.size() / 2;
    hoareSort(&v, 0, midIndex);
    hoareSort(&v, midIndex + 1, lastIndex);
    ASSERT_NO_THROW(merge(&v, 0, midIndex, v.size() - 1));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge, Even_Size)
{
    std::vector<int> v = getRandomVector(100);
    ASSERT_NO_THROW(runHoareSort(&v));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(Hoare_Sort_Simple_Merge, Odd_Size)
{
    std::vector<int> v = getRandomVector(111);
    ASSERT_NO_THROW(runHoareSort(&v));
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
