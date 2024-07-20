#include <iostream>
#include "gtest/gtest.h"
#include <stddef.h>
#include "uri.hpp"

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

//TEST(uri_tests, parse_from_string_urn_single_character_path_delimiter) {
//    magno::uri uri;
////    uri.set_path_delimiter(":");
//    ASSERT_TRUE(uri.parse_from_string("urn:book:fantasy:Hobbit"));
//    ASSERT_EQ("urn", uri.get_scheme());
//    ASSERT_EQ("", uri.get_host());
//    ASSERT_EQ((std::vector<std::string>{
//                   "book",
//                   "fantasy",
//                   "Hobbit"
//               }),
//              uri.get_path());
//}

//TEST(uri_tests, parse_from_string_urn_multi_character_path_delimiter) {
//    magno::uri uri;
//    uri.set_path_delimiter("/-");
//    ASSERT_TRUE(uri.parse_from_string("urn:bo-/ok/-fant/asy/-Hob-bit"));
//    ASSERT_EQ("urn", uri.get_scheme());
//    ASSERT_EQ("", uri.get_host());
//    ASSERT_EQ((std::vector<std::string>{
//                   "bo-/ok",
//                   "fant/asy",
//                   "Hob-bit"
//               }),
//              uri.get_path());
//}

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
//    ASSERT_EQ((std::vector<std::string>{
//                   "",
//                   "foo",
//                   "bar"
//               }),
//              uri.get_path());
}
















