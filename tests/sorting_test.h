#ifndef FIBONACHI_H
#define FIBONACHI_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

extern "C" {
#include "Header.h"
}

//�������� ���������� �����
TEST(TestCaseSorting, TestShellsort) {

	const int N = 4;
	int* a = new int[N];
	a[0] = -2; a[1] = -5; a[2] = 0; a[3] = 1;
	shellsort(a, 0, N - 1);
	//EXPECT_EQ(1, 1);
	EXPECT_TRUE((a[0] == -5) && (a[1] == -2) && (a[2] == 0) && (a[3] == 1));
}
//�������� ���������� �������
TEST(TestCaseSorting, TestSelection) {

	const int N = 4;
	int* a = new int[N];
	a[0] = -2; a[1] = -5; a[2] = 0; a[3] = 1;
	selection(a, 0, N - 1);
	EXPECT_EQ(1, 1);
	EXPECT_TRUE((a[0] == -5) && (a[1] == -2) && (a[2] == 0) && (a[3] == 1));
}

//�������� ���������� ������
TEST(TestCaseSorting, TestShaker) {

	const int N = 4;
	int* a = new int[N];
	a[0] = -2; a[1] = -5; a[2] = 0; a[3] = 1;
	shaker(a, 0, N - 1);
	//EXPECT_EQ(1, 1);
	EXPECT_TRUE((a[0] == -5) && (a[1] == -2) && (a[2] == 0) && (a[3] == 1));
}

//�������� ���������� ��������
TEST(TestCaseSorting, TestInsertion) {

	const int N = 4;
	int* a = new int[N];
	a[0] = -2; a[1] = -5; a[2] = 0; a[3] = 1;
	insertion(a, 0, N - 1);
	//EXPECT_EQ(1, 1);
	EXPECT_TRUE((a[0] == -5) && (a[1] == -2) && (a[2] == 0) && (a[3] == 1));
}

//�������� ���������� ���������
TEST(TestCaseSorting, TestBubble) {

	const int N = 4;
	int* a = new int[N];
	a[0] = -2; a[1] = -5; a[2] = 0; a[3] = 1;
	bubble(a, 0, N - 1);
	//EXPECT_EQ(1, 1);
	EXPECT_TRUE((a[0] == -5) && (a[1] == -2) && (a[2] == 0) && (a[3] == 1));
}

//��������� ���������� ���� ����������
TEST(TestCaseSorting, TestEqualsSortingResults) {

	const int N = 1000;
	int* a = new int[N];
	int* b = new int[N];
	randmass(a, N);
	for (int i = 0; i < N; i++)
	{
		b[i] = a[i];
	}
	shellsort(a, 0, N - 1);
	insertion(b, 0, N - 1);

	//EXPECT_EQ(1, 1);
	for (int i = 0; i < N; i++)
	{
		EXPECT_TRUE(a[i] == b[i]);
	}
}

#endif // FIBONACHI_H
