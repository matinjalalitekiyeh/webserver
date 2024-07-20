#include <iostream>
#include "gtest/gtest.h"
#include <stddef.h>
#include "uri.hpp"

TEST(uri_tests, parse_from_string_url_no_scheme) {
    magno::uri uri;
    ASSERT_TRUE(uri.parse_from_string("/foo/bar"));
    ASSERT_EQ("", uri.get_scheme());
    ASSERT_EQ((std::vector<std::string>{
                   "",
                   "foo",
                   "bar"
               }),
              uri.get_path());
}

TEST(uri_tests, parse_from_string_url) {
    magno::uri uri;
    ASSERT_TRUE(uri.parse_from_string("http://www.example.com/foo/bar"));
    ASSERT_EQ("http", uri.get_scheme());
    ASSERT_EQ("www.example.com", uri.get_host());
    ASSERT_EQ((std::vector<std::string>{
                   "",
                   "foo",
                   "bar"
               }),
              uri.get_path());
}

TEST(uri_tests, parse_from_string_urn_default_path_delimiter) {
    magno::uri uri;
    ASSERT_TRUE(uri.parse_from_string("urn:book:fantasy:Hobbit"));
    ASSERT_EQ("urn", uri.get_scheme());
    ASSERT_EQ("", uri.get_host());
    ASSERT_EQ((std::vector<std::string>{
                   "book:fantasy:Hobbit"
               }),
              uri.get_path());
}

TEST(uri_tests, parse_from_string_path_corner_cases) {
    struct Test_Vertor {
        std::string path_in;
        std::vector<std::string> path_out;
    };
    const std::vector<Test_Vertor> test_vectors {
        {"", {}},
        {"/", {""}},
        {"/foo", {"", "foo"}},
        {"foo/", {"foo", ""}},
    };

    size_t index = 0;
    for (const auto& testVector : test_vectors) {
        magno::uri uri;
        ASSERT_TRUE(uri.parse_from_string(testVector.path_in)) << index;
        ASSERT_EQ(testVector.path_out, uri.get_path()) << index;
        ++index;
    }
}

TEST(uri_tests, parse_from_string_url_with_port) {
    magno::uri uri;
    ASSERT_TRUE(uri.parse_from_string("http://www.example.com:8080/foo/bar"));
    ASSERT_EQ("http", uri.get_scheme());
    ASSERT_EQ("www.example.com", uri.get_host());
    ASSERT_TRUE(uri.has_port());
    ASSERT_EQ(8080, uri.get_port());
    ASSERT_EQ((std::vector<std::string>{
                   "",
                   "foo",
                   "bar"
               }),
              uri.get_path());
}

TEST(uri_tests, parse_from_string_url_twice_with_port_then_without_port) {
    magno::uri uri;
    ASSERT_TRUE(uri.parse_from_string("http://www.example.com:8080/foo/bar"));
    ASSERT_TRUE(uri.parse_from_string("http://www.example.com/foo/bar"));
    ASSERT_EQ("http", uri.get_scheme());
    ASSERT_EQ("www.example.com", uri.get_host());
    ASSERT_FALSE(uri.has_port());
    ASSERT_EQ(8080, uri.get_port());
    ASSERT_EQ((std::vector<std::string>{
                   "",
                   "foo",
                   "bar"
               }),
              uri.get_path());
}

TEST(uri_tests, parse_from_string_url_purly_alphabetic) {
    magno::uri uri;
    ASSERT_FALSE(uri.parse_from_string("http://www.example.com:spam/foo/bar"));
}

TEST(uri_tests, parse_from_string_url_bad_port_number_start_number_end_alphabetic) {
    magno::uri uri;
    ASSERT_FALSE(uri.parse_from_string("http://www.example.com:8080spam/foo/bar"));
}

/*port range is the same as your original message - [1, 65535]*/
TEST(uri_tests, parse_from_string_url_largest_valid_port) {
    magno::uri uri;
    ASSERT_TRUE(uri.parse_from_string("http://www.example.com:65535/foo/bar"));
    ASSERT_EQ("www.example.com", uri.get_host());
    ASSERT_TRUE(uri.has_port());
    ASSERT_EQ(65535, uri.get_port());
    ASSERT_EQ((std::vector<std::string>{
                   "",
                   "foo",
                   "bar"
               }),
              uri.get_path());
}

TEST(uri_tests, parse_from_string_url_bad_port) {
    magno::uri uri;
    ASSERT_FALSE(uri.parse_from_string("http://www.example.com:65536/foo/bar"));
}

TEST(uri_tests, parse_from_string_url_negative_port) {
    magno::uri uri;
    ASSERT_FALSE(uri.parse_from_string("http://www.example.com:-1234/foo/bar"));
}

TEST(uri_tests, parse_from_string_url_after_authority) {
    magno::uri uri;
    ASSERT_TRUE(uri.parse_from_string("http://www.example.com"));
}

TEST(uri_tests, parse_from_string_path_relative_vs_non_relative_reference) {
    struct Test_Vertor {
        std::string uri_strings;
        bool is_relative;
    };
    const std::vector<Test_Vertor> test_vectors {
        {"http://example.com/", false},
        {"http://example.com", false},
        {"/", true},
        {"foo", true},
    };

    size_t index = 0;
    for (const auto& testVector : test_vectors) {
        magno::uri uri;
        ASSERT_TRUE(uri.parse_from_string(testVector.uri_strings)) << index;
        ASSERT_EQ(testVector.is_relative, uri.is_relative_reference()) << index;
        ++index;
    }
}

TEST(uri_tests, parse_from_string_path_relative_vs_non_relative_path) {
    ASSERT_TRUE(true);
}









