#include <array>
#include <cassert>  // assert()
#include <iostream> // cout, endl
#include <iterator> // std::begin(), std::end()
#include <vector>

// The test manager header
#include "../tm/test_manager.hpp"

// The graal header in which the solution is coded.
#include "../include/graal.hpp"

#define which_lib graal // uncomment this if you wanna run the graal library
// #define which_lib std // uncomment this if you wanna run the std library.

#define YES 1
#define NO 0

// Change NO into YES to activate the test.
#define MIN_MAX YES
#define REVERSE YES
#define COPY YES
#define FINDIF YES
#define ALLOFF YES
#define ANYOF YES
#define NONEOF YES
#define EQUAL YES
#define UNIQUE YES
#define PARTITION NO

int main() {
  // Creates a test manager for the DAL class.
  TestManager tm{"Graal Test Suite"};

#if MIN_MAX
  {
    //=== Test #1
    BEGIN_TEST(tm, "MinMax1", "Unique Values Sorted.");
    // DISABLE();
    constexpr std::array original_array{1, 2, 3, 4, 5};

    // const auto [ min, max ] = graal::minmax( std::begin(A), std::end(A),
    // std::less< int >() );
    auto result = which_lib::minmax(std::begin(original_array),
                                    std::end(original_array), std::less<>());
    const auto *min = result.first;
    const auto *max = result.second;

    EXPECT_NE(min, nullptr);
    EXPECT_EQ(min, std::begin(original_array));
    EXPECT_EQ(*min, 1);

    EXPECT_NE(max, nullptr);
    EXPECT_EQ(max, std::prev(std::end(original_array)));
    EXPECT_EQ(*max, 5);
  }
#endif

#if MIN_MAX
  {
    //=== Test #2
    BEGIN_TEST(tm, "MinMax2", "Unique Values Reverse Sorted.");
    // DISABLE();
    constexpr std::array vec_test{5, 4, 3, 2, 1};

    // const auto [ min, max ] = graal::minmax( std::begin(A), std::end(A),
    // std::less< int >() );
    auto result = which_lib::minmax(std::begin(vec_test), std::end(vec_test),
                                    std::less<>());
    const auto *min = result.first;
    const auto *max = result.second;

    EXPECT_NE(min, nullptr);
    EXPECT_EQ(min, std::prev(std::end(vec_test)));
    EXPECT_EQ(*min, 1);

    EXPECT_NE(max, nullptr);
    EXPECT_EQ(max, std::begin(vec_test));
    EXPECT_EQ(*max, 5);
  }
#endif

#if MIN_MAX
  {
    BEGIN_TEST(tm, "MinMax3", "All Equal.");
    // DISABLE();
    std::array vec_test{1, 1, 1, 1, 1};

    // const auto [ min, max ] = graal::minmax( std::begin(A), std::end(A),
    // std::less< int >() );
    auto result = which_lib::minmax(std::begin(vec_test), std::end(vec_test),
                                    std::less<>());
    auto *min = result.first;
    auto *max = result.second;
    EXPECT_NE(min, nullptr);
    EXPECT_EQ(min, std::begin(vec_test));
    EXPECT_EQ(*min, 1);

    EXPECT_NE(max, nullptr);
    EXPECT_EQ(max, std::prev(std::end(vec_test)));
    EXPECT_EQ(*max, 1);
  }
#endif

#if MIN_MAX
  {
    BEGIN_TEST(tm, "MinMax4", "Unique Values Random Order");
    constexpr std::array vec_test{2, 3, 5, 4, 1};

    // const auto [ min, max ] = graal::minmax( std::begin(A), std::end(A),
    // std::less< int >() ); const auto [ expected_min, expected_max ] =
    // std::minmax_element( std::begin(A), std::end(A) );
    auto result = which_lib::minmax(std::begin(vec_test), std::end(vec_test),
                                    std::less<>());
    const auto *min = result.first;
    const auto *max = result.second;
    auto eresult =
        std::minmax_element(std::begin(vec_test), std::end(vec_test));
    const auto *expected_min = eresult.first;
    const auto *expected_max = eresult.second;

    EXPECT_NE(min, nullptr);
    EXPECT_EQ(min, expected_min);
    EXPECT_EQ(*min, 1);

    EXPECT_NE(max, nullptr);
    EXPECT_EQ(max, expected_max);
    EXPECT_EQ(*max, 5);
  }
#endif

#if MIN_MAX
  {
    BEGIN_TEST(tm, "MinMax5", "RepeatedValuesRandomOrder");
    constexpr std::array vec_test{2, 3, 2, 5, 1, 4, 5, 4, 1};

    // const auto [ min, max ] = graal::minmax( std::begin(A), std::end(A),
    // std::less< int >() ); const auto [ expected_min, expected_max ] =
    // std::minmax_element( std::begin(A), std::end(A) );
    auto result = which_lib::minmax(std::begin(vec_test), std::end(vec_test),
                                    std::less<>());
    const auto *min = result.first;
    const auto *max = result.second;
    auto expected_result =
        std::minmax_element(std::begin(vec_test), std::end(vec_test));
    const auto *expected_min = expected_result.first;
    const auto *expected_max = expected_result.second;
    EXPECT_NE(min, nullptr);
    EXPECT_EQ(min, expected_min);
    EXPECT_EQ(*min, 1);

    EXPECT_NE(max, nullptr);
    EXPECT_EQ(max, expected_max);
    EXPECT_EQ(*max, 5);
  }
#endif

#if MIN_MAX
  {
    BEGIN_TEST(tm, "MinMax6", "EmptyList");
    std::array A{1};

    // const auto [ min, max ] = graal::minmax( std::begin(A), std::begin(A),
    // std::less< int >() ); const auto [ expected_min, expected_max ] =
    // std::minmax_element( std::begin(A), std::begin(A) );
    auto result =
        which_lib::minmax(std::begin(A), std::begin(A), std::less<>());
    auto *min = result.first;
    auto *max = result.second;
    auto eresult = std::minmax_element(std::begin(A), std::begin(A));
    auto *expected_min = eresult.first;
    auto *expected_max = eresult.second;

    EXPECT_NE(min, nullptr);
    EXPECT_EQ(min, expected_min);
    EXPECT_EQ(*min, 1);

    EXPECT_NE(max, nullptr);
    EXPECT_EQ(max, expected_max);
    EXPECT_EQ(*max, 1);
  }
#endif

#if MIN_MAX
  {
    BEGIN_TEST(tm, "MinMax7", "SingleElement ");
    std::array vec_test{1};

    // const auto [ min, max ] = graal::minmax( std::begin(A), std::end(A),
    // std::less< int >() ); const auto [ expected_min, expected_max ] =
    // std::minmax_element( std::begin(A), std::end(A) );
    auto result = which_lib::minmax(std::begin(vec_test), std::end(vec_test),
                                    std::less<>());
    auto *min = result.first;
    auto *max = result.second;
    auto eresult =
        std::minmax_element(std::begin(vec_test), std::end(vec_test));
    auto *expected_min = eresult.first;
    auto *expected_max = eresult.second;

    EXPECT_NE(min, nullptr);
    EXPECT_EQ(min, expected_min);
    EXPECT_EQ(*min, 1);

    EXPECT_NE(max, nullptr);
    EXPECT_EQ(max, expected_max);
    EXPECT_EQ(*max, 1);
  }
#endif

  //== Reverse

#if REVERSE
  {
    BEGIN_TEST(tm, "Reverse", "ReverseEntireArrayEven");
    std::array input{1, 2, 3, 4, 5, 6};
    constexpr std::array reversed_input{6, 5, 4, 3, 2, 1};

    which_lib::reverse(input.begin(), input.end());

    EXPECT_TRUE(std::equal(std::begin(input), std::end(input),
                           std::begin(reversed_input)));
  }
#endif

#if REVERSE
  {
    BEGIN_TEST(tm, "Reverse2", "ReverseEntireArrayOdd");
    std::array input{1, 2, 3, 4, 5};
    constexpr std::array reversed_input{5, 4, 3, 2, 1};

    which_lib::reverse(std::begin(input), std::end(input));
    EXPECT_TRUE(std::equal(std::begin(input), std::end(input),
                           std::begin(reversed_input)));
  }
#endif

#if REVERSE
  {
    BEGIN_TEST(tm, "Reverse3", "ReversePartOfArrayEven");
    std::array input{1, 2, 3, 4, 5, 6, 7};
    constexpr std::array reversed_input{1, 2, 6, 5, 4, 3, 7};

    which_lib::reverse(std::begin(input) + 2, std::begin(input) + 6);
    EXPECT_TRUE(std::equal(std::begin(input), std::end(input),
                           std::begin(reversed_input)));
  }
#endif

#if REVERSE
  {
    BEGIN_TEST(tm, "Reverse4", "ReversePartOfArrayOdd");
    std::array input{1, 2, 3, 4, 5, 6, 7};
    constexpr std::array reversed_input{1, 6, 5, 4, 3, 2, 7};

    which_lib::reverse(std::begin(input) + 1, std::begin(input) + 6);
    EXPECT_TRUE(std::equal(std::begin(input), std::end(input),
                           std::begin(reversed_input)));
  }
#endif

  //== Copy

#if COPY
  {
    BEGIN_TEST(tm, "Copy", "CopyEntireArray");
    std::array input{'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    std::array input_copy{'-', '-', '-', '-', '-', '-', '-'};

    which_lib::copy(std::begin(input), std::end(input), std::begin(input_copy));
    EXPECT_TRUE(
        std::equal(std::begin(input), std::end(input), std::begin(input_copy)));
  }
#endif

#if COPY
  {
    BEGIN_TEST(tm, "Copy2", "CopyPartOfArray");
    std::array input{'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    std::array input_copy{'a', 'b', '-', '-', '-', '-', '-'};

    which_lib::copy(std::begin(input) + 2, std::end(input),
                    std::begin(input_copy) + 2);
    EXPECT_TRUE(
        std::equal(std::begin(input), std::end(input), std::begin(input_copy)));
  }
#endif

#if COPY
  {
    BEGIN_TEST(tm, "Copy3", "CopyFinalPartOfArray");
    const auto offset{5};
    std::array input{'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    std::array input_copy{'a', 'b', 'c', 'd', 'e', '-', '-'};

    which_lib::copy(std::begin(input) + offset, std::end(input),
                    std::begin(input_copy) + offset);
    EXPECT_TRUE(
        std::equal(std::begin(input), std::end(input), std::begin(input_copy)));
  }
#endif

#if COPY
  {
    BEGIN_TEST(tm, "Copy4", "CopySingleElementArray");
    std::array input{'a'};
    std::array input_copy{'-'};

    which_lib::copy(std::begin(input), std::end(input), std::begin(input_copy));
    EXPECT_TRUE(
        std::equal(std::begin(input), std::end(input), std::begin(input_copy)));
  }
#endif

  //== fund_if()

#if FINDIF
  {
    BEGIN_TEST(tm, "FindIf", "SeveralAreTrue");
    const auto target{5};
    constexpr std::array input{1, 6, 3, 6, 5, 2, 6};
    const auto *result =
        which_lib::find_if(std::begin(input), std::end(input),
                           [](int e) -> bool { return e > target; });
    EXPECT_EQ(std::begin(input) + 1, result);
  }
#endif

#if FINDIF
  {
    BEGIN_TEST(tm, "FindIf2", "NoneIsTrue");
    const auto target{5};
    constexpr std::array input{1, 2, 3, 4, 5};
    const auto *result =
        which_lib::find_if(std::begin(input), std::end(input),
                           [](int e) -> bool { return e > target; });
    EXPECT_EQ(std::end(input), result);
  }
#endif

#if FINDIF
  {
    BEGIN_TEST(tm, "FindIf3", "AllAreTrue");
    const auto target{5};
    constexpr std::array input{6, 7, 8, 9, 10};
    const auto *result =
        which_lib::find_if(std::begin(input), std::end(input),
                           [](int e) -> bool { return e > target; });
    EXPECT_EQ(std::begin(input), result);
  }
#endif

#if FINDIF
  {
    BEGIN_TEST(tm, "FindIf4", "PredicateTrueAtBeginning");
    const auto target{5};
    constexpr std::array input{6, 2, 3, 4, 5, 2, 1};
    const auto *result =
        which_lib::find_if(std::begin(input), std::end(input),
                           [](int e) -> bool { return e > target; });
    EXPECT_EQ(std::begin(input), result);
  }
#endif

#if FINDIF
  {
    BEGIN_TEST(tm, "FindIf5", "PredicateTrueAtMiddle");
    const auto target{5};
    constexpr std::array input{1, 2, 3, 6, 5, 2, 1};
    const auto *result =
        which_lib::find_if(std::begin(input), std::end(input),
                           [](int e) -> bool { return e > target; });
    EXPECT_EQ(std::begin(input) + 3, result);
  }
#endif

#if FINDIF
  {
    BEGIN_TEST(tm, "FindIf6", "PredicateTrueAtEnd");
    const auto target{5};
    constexpr std::array input{1, 2, 3, 4, 5, 2, 6};
    const auto *result =
        which_lib::find_if(std::begin(input), std::end(input),
                           [](int e) -> bool { return e > target; });
    EXPECT_EQ(std::prev(std::end(input)), result);
  }
#endif

  //== all_of

#if ALLOFF
  {
    BEGIN_TEST(tm, "AllOf", "AllAreOk");
    constexpr std::array input{10, 20, 30, 40, 50, 60, 70};
    bool result;

    result = which_lib::all_of(std::begin(input), std::end(input),
                               [](const int &e) { return e > 0; });

    EXPECT_TRUE(result);
  }
#endif

#if ALLOFF
  {
    BEGIN_TEST(tm, "AllOf2", "AllAreNotOk");
    constexpr std::array input{10, 20, 30, 40, 50, 60, 70};
    bool result;

    result = which_lib::all_of(std::begin(input), std::end(input),
                               [](const int &e) { return e < 0; });

    EXPECT_FALSE(result);
  }
#endif

#if ALLOFF
  {
    BEGIN_TEST(tm, "AllOf3", "FewAreOk");
    const auto target{30};
    constexpr std::array input{10, 20, 30, 40, 50, 60, 70};
    bool result;

    result = which_lib::all_of(std::begin(input), std::end(input),
                               [](const int &e) { return e > target; });

    EXPECT_FALSE(result);
  }
#endif

#if ALLOFF
  {
    BEGIN_TEST(tm, "AllOf4", "EmptyInput");
    const auto target{30};
    constexpr std::array input{10, 20, 30, 40, 50, 60, 70};
    bool result;

    result = which_lib::all_of(std::begin(input), std::begin(input),
                               [](const int &e) { return e > target; });

    EXPECT_TRUE(result);
  }
#endif

  //== any_of

#if ANYOF
  {
    BEGIN_TEST(tm, "AnyOf1", "AllAreOk");
    const auto target{0};
    constexpr std::array input{10, 20, 30, 40, 50, 60, 70};
    bool result;

    result = which_lib::any_of(std::begin(input), std::end(input),
                               [](const int &e) { return e > target; });

    EXPECT_TRUE(result);
  }
#endif

#if ANYOF
  {
    BEGIN_TEST(tm, "AnyOf2", "AllAreNotOk");
    const auto target{0};
    constexpr std::array input{10, 20, 30, 40, 50, 60, 70};
    bool result;

    result = which_lib::any_of(std::begin(input), std::end(input),
                               [](const int &e) { return e < target; });

    EXPECT_FALSE(result);
  }
#endif

#if ANYOF
  {
    BEGIN_TEST(tm, "AnyOf3", "FewAreOk");
    const auto target{30};
    constexpr std::array input{10, 20, 30, 40, 50, 60, 70};
    bool result;

    result = which_lib::any_of(std::begin(input), std::end(input),
                               [](const int &e) { return e > target; });

    EXPECT_TRUE(result);
  }
#endif

#if ANYOF
  {
    BEGIN_TEST(tm, "AnyOf4", "EmptyInput");
    const auto target{30};
    constexpr std::array input{10, 20, 30, 40, 50, 60, 70};
    bool result;

    result = which_lib::any_of(std::begin(input), std::begin(input),
                               [](const int &e) { return e > target; });

    EXPECT_FALSE(result);
  }
#endif

  //== none_of

#if NONEOF
  {
    BEGIN_TEST(tm, "NoneOf1", "AllAreOk");
    const auto target{0};
    constexpr std::array input{10, 20, 30, 40, 50, 60, 70};
    bool result;

    result = which_lib::none_of(std::begin(input), std::end(input),
                                [](const int &e) { return e > target; });

    EXPECT_FALSE(result);
  }
#endif

#if NONEOF
  {
    BEGIN_TEST(tm, "NoneOf2", "AllAreNotOk");
    const auto target{0};
    constexpr std::array input{10, 20, 30, 40, 50, 60, 70};
    bool result;

    result = which_lib::none_of(std::begin(input), std::end(input),
                                [](const int &e) { return e < target; });

    EXPECT_TRUE(result);
  }
#endif

#if NONEOF
  {
    BEGIN_TEST(tm, "NoneOf3", "FewAreOk");
    const auto target{30};
    constexpr std::array input{10, 20, 30, 40, 50, 60, 70};
    bool result;

    result = which_lib::none_of(std::begin(input), std::end(input),
                                [](const int &e) { return e > target; });

    EXPECT_FALSE(result);
  }
#endif

#if NONEOF
  {
    BEGIN_TEST(tm, "NoneOf4", "EmptyInput");
    const auto target{30};
    constexpr std::array input{10, 20, 30, 40, 50, 60, 70};
    bool result;

    result = which_lib::none_of(std::begin(input), std::begin(input),
                                [](const int &e) { return e > target; });

    EXPECT_TRUE(result);
  }
#endif

  //=== equal, version #1
#if EQUAL
  {
    BEGIN_TEST(tm, "Equal", "AllAreEqualSameSize ");
    constexpr std::array input{'a', 'b', 'c', 'd'};
    constexpr std::array input_copy{'a', 'b', 'c', 'd'};

    bool result;
    result = which_lib::equal(std::begin(input), std::end(input),
                              std::begin(input_copy),
                              [](int a, int b) -> bool { return a == b; });
    EXPECT_TRUE(result);
  }
#endif

#if EQUAL
  {
    BEGIN_TEST(tm, "Equal2", "AllAreNotEqualSameSize");
    constexpr std::array input{'a', 'b', 'c', 'd'};
    constexpr std::array target{'x', 'y', 'z', 'w'};

    bool result;
    result =
        which_lib::equal(std::begin(input), std::end(input), std::begin(target),
                         [](int a, int b) -> bool { return a == b; });
    EXPECT_FALSE(result);
  }
#endif

#if EQUAL
  {
    BEGIN_TEST(tm, "Equal3", "PartAreEqualSameSize");
    constexpr std::array input{'a', 'b', 'c', 'd'};
    constexpr std::array target{'x', 'y', 'c', 'd'};

    bool result;
    result =
        which_lib::equal(std::begin(input), std::end(input), std::begin(target),
                         [](int a, int b) -> bool { return a == b; });
    EXPECT_FALSE(result);
  }
#endif

#if EQUAL
  {
    BEGIN_TEST(tm, "Equal4", "AllAreEqual1stGreater2nd");
    std::array input{'a', 'b', 'c', 'd', 'e', 'f'};
    std::array target{'a', 'b', 'c', 'd'};

    bool result;
    result = which_lib::equal(std::begin(input), std::end(input),
                              std::begin(target), std::end(target),
                              [](int a, int b) -> bool { return a == b; });
    EXPECT_FALSE(result);
  }
#endif

#if EQUAL
  {
    BEGIN_TEST(tm, "Equal5", "AllAreEqual1stGreater2ndCorrectRange");
    std::array input{'a', 'b', 'c', 'd', 'e', 'f'};
    std::array input_copy{'a', 'b', 'c', 'd'};

    bool result;
    result = which_lib::equal(
        std::begin(input),
        std::begin(input) +
            std::distance(std::begin(input_copy), std::end(input_copy)),
        std::begin(input_copy), std::end(input_copy),
        [](int a, int b) -> bool { return a == b; });
    EXPECT_TRUE(result);
  }
#endif

#if EQUAL
  {
    BEGIN_TEST(tm, "Equal6", "PartIsNotEqual");
    std::array input{'a', 'b', 'c', 'd', 'e', 'f'};
    std::array target{'x', 'y', 'a', 'b', 'c', 'd', 'h', 'i'};
    const auto offset_begin{2};
    const auto offset_end{6};

    bool result;
    result = which_lib::equal(std::begin(input), std::end(input),
                              std::begin(target) + offset_begin,
                              std::end(target) + offset_end,
                              [](int a, int b) -> bool { return a == b; });
    EXPECT_FALSE(result);
  }
#endif

#if EQUAL
  {
    BEGIN_TEST(tm, "Equal7", "PartIsEqual");
    std::array input{'a', 'b', 'c', 'd'};
    std::array target{'x', 'y', 'a', 'b', 'c', 'd', 'h', 'i'};
    const auto offset_begin{2};
    const auto offset_end{6};

    bool result;
    result = which_lib::equal(std::begin(input), std::end(input),
                              std::begin(target) + offset_begin,
                              std::begin(target) + offset_end,
                              [](int a, int b) -> bool { return a == b; });
    EXPECT_TRUE(result);
  }
#endif

  //== unique()
#if UNIQUE1
  {
    BEGIN_TEST(tm, "Unique", "SomeRepetitions");
    std::array input{1, 2, 3, 4, 5, 5, 4, 4, 4, 3, 2, 3, 2, 1};
    constexpr std::array expected{1, 2, 3, 4, 5};

    auto *result = which_lib::unique(std::begin(input), std::end(input),
                                     std::equal_to<>());
    // []( const int& a, const int& b )->bool{ return a == b; } );

    EXPECT_EQ(std::distance(input.begin(), result),
              std::distance(expected.begin(), expected.end()));
    EXPECT_TRUE(std::equal(std::begin(input), result, std::begin(expected)));
  }
#endif

#if UNIQUE2
  {
    BEGIN_TEST(tm, "Unique2", "AllEquals");
    std::array input{1, 1, 1, 1, 1, 1, 1};
    constexpr std::array expected{1};

    auto *result = which_lib::unique(
        std::begin(input), std::end(input),
        [](const int &a, const int &b) -> bool { return a == b; });

    EXPECT_EQ(std::distance(input.begin(), result),
              std::distance(expected.begin(), expected.end()));
    EXPECT_TRUE(std::equal(std::begin(input), result, std::begin(expected)));
  }
#endif

#if UNIQUE3
  {
    BEGIN_TEST(tm, "Unique3", "AllAreUnique");
    std::array input{1, 2, 3, 4, 5, 6, 7};
    constexpr std::array expected{1, 2, 3, 4, 5, 6, 7};

    auto *result = which_lib::unique(
        std::begin(input), std::end(input),
        [](const int &a, const int &b) -> bool { return a == b; });

    EXPECT_EQ(std::distance(input.begin(), result),
              std::distance(expected.begin(), expected.end()));
    EXPECT_TRUE(std::equal(std::begin(input), result, std::begin(expected)));
  }
#endif

#if UNIQUE4
  {
    BEGIN_TEST(tm, "Unique4", "MirrorUnique");
    std::array original_array{1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
    constexpr std::array expected_array{1, 2, 3, 4, 5};

    auto *result = which_lib::unique(
        std::begin(original_array), std::end(original_array),
        [](const int &a, const int &b) -> bool { return a == b; });

    EXPECT_EQ(std::distance(original_array.begin(), result),
              std::distance(expected_array.begin(), expected_array.end()));
    EXPECT_TRUE(std::equal(std::begin(original_array), result,
                           std::begin(expected_array)));
  }
#endif

  //== partition()
#if PARTITION
  {
    BEGIN_TEST(tm, "Partition", "AllAreTrue");
    std::array original_array{6, 7, 8, 9, 10};
    constexpr std::array expected_array{6, 7, 8, 9, 10};

    auto predicate = [](const int &e) -> bool { return e > 5; };

    auto *result = which_lib::partition(std::begin(original_array),
                                        std::end(original_array), predicate);

    // Location of the pointer must be correct.
    EXPECT_EQ(result, std::end(original_array));
    // Uset STL function to test whether the partion worked.
    EXPECT_TRUE(std::is_partitioned(std::begin(original_array),
                                    std::end(original_array), predicate));
    // Let us see if the elements have been preserved.
    std::sort(std::begin(original_array), std::end(original_array));
    std::vector<int> v_intersection;
    std::set_intersection(std::begin(original_array), std::end(original_array),
                          std::begin(expected_array), std::end(expected_array),
                          std::back_inserter(v_intersection));
    EXPECT_EQ((size_t)std::distance(std::begin(original_array),
                                    std::end(original_array)),
              v_intersection.size());
  }
#endif

#if PARTITION
  {
    BEGIN_TEST(tm, "Partition2", "NoneAreTrue");
    std::array original_array{0, 1, 2, 3, 4};
    constexpr std::array expected_array{0, 1, 2, 3, 4};

    auto predicate = [](const int &e) -> bool { return e > 5; };

    auto *result = which_lib::partition(std::begin(original_array),
                                        std::end(original_array), predicate);

    // Location of the pointer must be correct.
    EXPECT_EQ(std::distance(std::begin(original_array), result), 0);
    // Uset STL function to test whether the partion worked.
    EXPECT_TRUE(std::is_partitioned(std::begin(original_array),
                                    std::end(original_array), predicate));
    EXPECT_EQ(result, std::begin(original_array));
    // Let us see if the elements have been preserved.
    std::sort(std::begin(original_array), std::end(original_array));
    std::vector<int> v_intersection;
    std::set_intersection(std::begin(original_array), std::end(original_array),
                          std::begin(expected_array), std::end(expected_array),
                          std::back_inserter(v_intersection));
    EXPECT_EQ((size_t)std::distance(std::begin(original_array),
                                    std::end(original_array)),
              v_intersection.size());
  }
#endif

#if PARTITION
  {
    BEGIN_TEST(tm, "Partition3", "SomeAreTrueInverted");
    std::array original_array{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::array expected_array{6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    const auto target{5};
    // Lambda
    auto predicate = [](const int &e) -> bool { return e > target; };

    auto *result = which_lib::partition(std::begin(original_array),
                                        std::end(original_array), predicate);
    EXPECT_EQ(std::distance(std::begin(original_array), result), target);
    // Uset STL function to test whether the partion worked.
    EXPECT_TRUE(std::is_partitioned(std::begin(original_array),
                                    std::end(original_array), predicate));
    // Let us see if the elements have been preserved.
    std::sort(std::begin(original_array), std::end(original_array));
    std::sort(std::begin(expected_array), std::end(expected_array));
    std::vector<int> v_intersection;
    std::set_intersection(std::begin(original_array), std::end(original_array),
                          std::begin(expected_array), std::end(expected_array),
                          std::back_inserter(v_intersection));
    EXPECT_EQ((size_t)std::distance(std::begin(original_array),
                                    std::end(original_array)),
              v_intersection.size());
  }
#endif

#if PARTITION
  {
    BEGIN_TEST(tm, "Partition4", "SomeAreTrueInterleaved");
    std::array original_array{1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
    constexpr std::array expected_array{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const auto target{5};

    auto predicate = [](const int &e) -> bool { return e > target; };

    auto *result = which_lib::partition(std::begin(original_array),
                                        std::end(original_array), predicate);
    EXPECT_EQ(std::distance(std::begin(original_array), result), target);
    // Uset STL function to test whether the partion worked.
    EXPECT_TRUE(std::is_partitioned(std::begin(original_array),
                                    std::end(original_array), predicate));
    // Let us see if the elements have been preserved.
    std::sort(std::begin(original_array), std::end(original_array));
    std::vector<int> v_intersection;
    std::set_intersection(std::begin(original_array), std::end(original_array),
                          std::begin(expected_array), std::end(expected_array),
                          std::back_inserter(v_intersection));
    EXPECT_EQ((size_t)std::distance(std::begin(original_array),
                                    std::end(original_array)),
              v_intersection.size());
  }
#endif

  tm.summary();
  std::cout << '\n';

  return EXIT_SUCCESS;
}
