#ifndef TST_STDOUT_H
#define TST_STDOUT_H

#include <gtest/gtest.h>

#include<fstream>

// dup, dup2
#include <unistd.h>

#include <fcntl.h>

extern "C" {
#include "Header.h"
}


#define MAXLINE 1024

// Проверка поиска кол-ва корней для уравнения с одним корнем
TEST(TestCaseFindRoots, TestFindOneRootCount) {
	int a = 1; int b = -6; int c = 9;
	EXPECT_EQ(rootScan(a, b, c), 1);
}

// Проверка поиска кол-ва корней для уравнения с нулём корней
TEST(TestCaseFindRoots, TestFindZeroRootCount) {
	int a = 2; int b = 0; int c = 6;
	EXPECT_EQ(rootScan(a, b, c), 0);
}

// Проверка поиска кол-ва корней для уравнения с двумя корнем
TEST(TestCaseFindRoots, TestFindTwoRootCount) {
	int a = 2; int b = 3; int c = 0;
	EXPECT_EQ(rootScan(a, b, c), 2);
}

// Проверка поиска корней для уравнения с двумя корнями
TEST(TestCaseFindRoots, TestFindTwoRoots) {
	int a = 2; int b = 3; int c = 0;
	EXPECT_EQ(findFirstRoot(a, b, c), 0);
	EXPECT_EQ(findSecondRoot(a, b, c), -1.5);
}

// Проверка поиска корней для уравнения с одним корнями
TEST(TestCaseFindRoots, TestFindOneRoot) {
	int a = 1; int b = -6; int c = 9;
	EXPECT_EQ(findFirstRoot(a, b, c), 3);
	EXPECT_EQ(findSecondRoot(a, b, c), 3);
}

#endif // TST_STDOUT_H
