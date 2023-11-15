/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, letters_repeated_at_end)
{
	Password my_p;
	int count = my_p.count_leading_characters("ZZAABB");
	ASSERT_EQ(2,count);
}

TEST(PasswordTest, non_letter_password)
{
	Password test;
	int pass = test.count_leading_characters("__password");
	ASSERT_EQ(2,pass);
}

TEST(PasswordTest, upper_lower)
{
	Password test;
	int pass = test.count_leading_characters("Aabbcc");
	ASSERT_EQ(1,pass);
}

TEST(PasswordTest, no_pass)
{
	Password test;
	int pass = test.count_leading_characters("");
	ASSERT_EQ(1,pass);
}

TEST(PasswordTest, mixed_pass)
{
	Password test;
	int pass = test.has_mixed_case("Aabbcc");
	ASSERT_EQ(true,pass);
}

TEST(PasswordTest, all_lower)
{
	Password test;
	int pass = test.has_mixed_case("ksifhe");
	ASSERT_FALSE(pass);
}

TEST(PasswordTest, all_upper)
{
	Password test;
	int pass = test.has_mixed_case("BIJUFY");
	ASSERT_FALSE(pass);
}

TEST(PasswordTest, special_mix)
{
	Password test;
	int pass = test.has_mixed_case("#1Aa");
	ASSERT_EQ(true,pass);
}

TEST(PasswordTest, set_short)
{
	Password test;
	test.set("1");
	int auth = test.authenticate("1");
	ASSERT_FALSE(auth);
}

TEST(PasswordTest, set_leading_chars)
{
	Password test;
	test.set("aaaaa1234");
	int auth = test.authenticate("aaaaa1234");
	ASSERT_FALSE(auth);
}

TEST(PasswordTest, set_mixed_case)
{
	Password test;
	test.set("aaabc1234");
	int auth = test.authenticate("aaabc1234");
	ASSERT_FALSE(auth);
}

TEST(PasswordTest, set_old_password) 
{
	Password test;
	test.set("Aabccccc");
	int auth1 = test.authenticate("Aabccccc");
	ASSERT_TRUE(auth1);
	test.set("Bbcddddd");
	int auth2 = test.authenticate("Bbcddddd");
	ASSERT_TRUE(auth2);
	test.set("Aabccccc");
	int auth = test.authenticate("Aabccccc");
	ASSERT_FALSE(auth);
}

TEST(PasswordTest, set_password) 
{
	Password test;
	test.set("Aabccccc");
	int auth = test.authenticate("Aabccccc");
	ASSERT_TRUE(auth);
}
