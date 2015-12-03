/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#include <gtest/gtest.h>
#include <plist/Objects.h>

using plist::Boolean;
using plist::String;
using plist::Dictionary;

TEST(Boolean, New)
{
    auto t = Boolean::New(true);
    EXPECT_TRUE(t->value());

    auto f = Boolean::New(false);
    EXPECT_FALSE(f->value());
}

TEST(Boolean, Identity)
{
    auto t1 = Boolean::New(true);
    auto t2 = Boolean::New(true);
    EXPECT_EQ(t1, t2);

    auto f1 = Boolean::New(false);
    auto f2 = Boolean::New(false);
    EXPECT_EQ(f1, f2);
}

TEST(Boolean, Coerce)
{
    auto s1 = String::New("yes");
    auto b1 = Boolean::Coerce(s1.get());
    EXPECT_TRUE(b1->value());

    auto s2 = String::New("YES");
    auto b2 = Boolean::Coerce(s2.get());
    EXPECT_TRUE(b2->value());

    auto s3 = String::New("Yes");
    auto b3 = Boolean::Coerce(s3.get());
    EXPECT_TRUE(b3->value());

    auto s4 = String::New("trUE");
    auto b4 = Boolean::Coerce(s4.get());
    EXPECT_TRUE(b4->value());

    auto s5 = String::New("NO");
    auto b5 = Boolean::Coerce(s5.get());
    EXPECT_FALSE(b5->value());

    auto s6 = String::New("false");
    auto b6 = Boolean::Coerce(s6.get());
    EXPECT_FALSE(b6->value());

    auto s7 = String::New("");
    auto b7 = Boolean::Coerce(s7.get());
    EXPECT_FALSE(b7->value());

    auto a8 = Dictionary::New();
    auto b8 = Boolean::Coerce(a8.get());
    EXPECT_EQ(b8, nullptr);
}
