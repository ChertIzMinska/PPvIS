/*!
\file
\brief ���� , � ������� �������� ����� .

���� �������� ����� , ������� �������� ����������������� ������� � ������� ������ Game.

*/
#include "CppUnitTest.h"
#include "Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	
	TEST_CLASS(UnitTest1)
	{
	public:
		/// <summary>
		/// Test1.
		/// \details Test1 ��������� ��������� �� ������� ������������ �������� �������������� � ������������.
		/// </summary>
		TEST_METHOD(Test1)
		{
			Game test(3);

			test[1][2] = 1;
			test[0][1] = 0;

			Assert::IsTrue(test[1][2] == 1);
			Assert::IsTrue(test[0][1] == 0);
			Assert::IsTrue(test[0][0] == -1);
		}


		/// <summary>
		/// Test2.
		///\details Test2 ��������� ��������� �� �������� ����� _Win , ���� � ���������� � �������� ���������� �� ���������.
		/// </summary>
		TEST_METHOD(Test2)
		{
			Game test(3);

			for (int i = 0; i < 3; i++)
				test[i][i] = 1;

			Assert::IsTrue(test._Win() == 1);
		}
		/// <summary>
		/// Test3.
		///\details Test3  ��������� ��������� �� �������� ����� _Win , ���� � ���������� 0 ���� ���������� �� �������� ���������.
		/// </summary>
		TEST_METHOD(Test3)
		{
			Game test(3);

			for (int i = 0; i < 3; i++)
				test[3-i-1][3-i-1] = 0;

			Assert::IsTrue(test._Win() == 0);
		}
		/// <summary>
		/// Test4.
		///\details Test4 ��������� ��������� �� �������� ����� _Win , ���� � ���������� � �������� ���������� � ����� ������.
		/// </summary>
		TEST_METHOD(Test4)
		{
			Game test(3);

			for (int i = 0; i < 3; i++)
				test[0][i] = 1;

			Assert::IsTrue(test._Win() == 1);

		}
		/// <summary>
		/// Test5.
		///\details Test5 ��������� ��������� �� �������� ����� _Win , ���� � ���������� 0 ���� ���������� � ����� ��������.
		/// </summary>
		TEST_METHOD(Test5)
		{
			Game test(3);

			for (int i = 0; i < 3; i++)
				test[i][0] = 0;

			Assert::IsTrue(test._Win() == 0);
		}
		/// <summary>
		/// Test6.
		///\details Test6 ��������� ��������� �� �������� ����� _Win , ���� ��������� ��������� ������ � ���������� .
		/// </summary>
		TEST_METHOD(Test6)
		{
			Game test(3);

			test[0][0] = 0;
			test[1][1] = 1;
			test[2][2] = 1;

			Assert::IsTrue(test._Win() == -1);
		}
		/// <summary>
		/// Test7.
		///\details Test7 ��������� �� ������������ ������� _Is.
		/// </summary>
		TEST_METHOD(Test7)
		{
			Game test(3);
			test[1][2] = 0;

			Assert::IsTrue(test._Is(1, 2) == true);
			Assert::IsFalse(test._Is(0, 0) != false);
		}
		/// <summary>
		/// Test8.
		///\details Test8 ��������� ���������� �� �������� �������� ����� _Get_size.
		/// </summary>
		TEST_METHOD(Test8)
		{
			Game test(5);

			Assert::IsTrue(test._Get_size() == 5);
		}
		
	};
}
