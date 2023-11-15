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

TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, same_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaaa");
	ASSERT_EQ(4, actual);
}

TEST(PasswordTest, mixed_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aA");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, not_mixed_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aa");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, upper_lower_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("zZzhi");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, invalid_password)
{
	Password my_password;
	bool actual = my_password.authenticate("ChicoCA-95929");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, valid_password)
{
	Password my_password;
	bool actual = my_password.authenticate("abcdefgh");
	ASSERT_EQ(true, actual);
}