// Created by moisrex on 1/27/20.
#include <gtest/gtest.h>
#include <string>
#include <webpp/utils/casts.h>

using namespace webpp;
using namespace std;

TEST(Casts, ToInt) {
    EXPECT_EQ(to_uint("10"), 10);
    EXPECT_EQ(to_int("+10"), 10);
    EXPECT_EQ(to_int("-10"), -10);
    EXPECT_EQ(to_uint("-10"), 10);
    EXPECT_EQ(to<int>("-10"), -10);
    EXPECT_EQ(to<unsigned long long>("+1025153153"), 1025153153);

    auto invalids = {
        "one",
        "+two",
        "12a",
        "a11",
        "+a11",
        "111-751",
        "123,321",
        "123.123",
        "123+123"
    };

    for (auto const& c : invalids) {
        EXPECT_EQ(to<int>(c), 0);
        EXPECT_EQ(to_uint64(c), 0);
        try {
            to<int, true, true>(c);
            EXPECT_TRUE(false) << c;
        } catch (std::exception const& err) {
            EXPECT_TRUE(true);
        }
    }
}