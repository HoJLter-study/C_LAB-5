#include "pch.h"
#include "CppUnitTest.h"
#include "Date.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	TEST_CLASS(tests)
	{
	public:
		
		TEST_METHOD(ConstructorTest1)
		{
			Date obj;
			Assert::IsTrue(obj.getDay() == 1 && obj.getMonth() == 1 && obj.getYear() == 1970);
		}

		TEST_METHOD(ConstructorTest2)
		{
			Date obj(12, 3, 2026);
			Assert::IsTrue(obj.getDay() == 12 && obj.getMonth() == 3 && obj.getYear() == 2026);
		}

		TEST_METHOD(StudyTimeTest1)
		{
			Date obj(1, 1, 2026);
			Assert::IsTrue(obj.isStudyTime() == false);
		}

		TEST_METHOD(StudyTimeTest2)
		{
			Date obj(12, 3, 2026);
			Assert::IsTrue(obj.isStudyTime());
		}

		TEST_METHOD(OperatorTest1)
		{
			Date obj1(12, 3, 2026);
			Date obj2(3, 5, 2077);
			Assert::IsTrue(obj2 > obj1);
		}

		TEST_METHOD(OperatorTest2)
		{
			Date obj1(12, 3, 2026);
			Date obj2(3, 5, 2077);
			Assert::IsTrue(obj2 > obj1);
		}

		TEST_METHOD(OperatorTest3)
		{
			Date obj1(12, 3, 1900);
			Date obj2(3, 5, 2026);
			Assert::IsTrue(obj1 < obj2);
		}

		TEST_METHOD(OperatorTest4)
		{
			Date obj1(1, 1, 1984);
			Date obj2(1, 1, 1984);
			Assert::IsTrue(obj2 == obj1);
		}

		TEST_METHOD(OperatorTest5)
		{
			Date obj1(1, 1, 1984);
			Date obj2(2, 1, 1984);
			Assert::IsTrue(obj2 != obj1);
		}

		TEST_METHOD(OperatorTest6)
		{
			Date obj1(1, 1, 1984);
			Date obj2(1, 5, 1924);
			Assert::IsTrue(obj2 != obj1);
		}

		TEST_METHOD(OperatorTest7)
		{
			Date obj1(1, 1, 2005);
			std::stringstream ss("19.01.1984");
			ss >> obj1;
			Assert::IsTrue(obj1.getDay() == 19 && obj1.getMonth() == 1 && obj1.getYear() == 1984);
		}

		TEST_METHOD(OperatorTest8)
		{
			Date obj1;
			std::stringstream ss;
			ss << obj1;
			Assert::IsTrue(ss.str() == "01.01.1970");
		}

	};
}
	
