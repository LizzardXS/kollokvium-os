#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <gtest/gtest.h>

std::vector<unsigned long long> generateFibonacci(size_t n) {
    if (n == 0) {
        throw std::invalid_argument("n должно быть натуральным числом (n > 0)");
    }

    std::vector<unsigned long long> fib(n);
    fib[0] = 0;
    if (n > 1) fib[1] = 1;
    for (size_t i = 2; i < n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib;
}

bool isPalindrome(int number) {
    if (number < 0) return false;
    std::string str = std::to_string(number);
    return std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin());
}

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

TEST(FibonacciTest, GeneratesCorrectSequence) {
    EXPECT_EQ(generateFibonacci(1), std::vector<unsigned long long>({0}));
    EXPECT_EQ(generateFibonacci(5), std::vector<unsigned long long>({0, 1, 1, 2, 3}));
}

TEST(PalindromeTest, IdentifiesPalindromes) {
    EXPECT_TRUE(isPalindrome(121));
    EXPECT_TRUE(isPalindrome(1221));
    EXPECT_FALSE(isPalindrome(123));
    EXPECT_FALSE(isPalindrome(-121));
}

TEST(LinkedListTest, ReversesListCorrectly) {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;

    ListNode* reversed = reverseList(node1);
    EXPECT_EQ(reversed->val, 3);
    EXPECT_EQ(reversed->next->val, 2);
    EXPECT_EQ(reversed->next->next->val, 1);
    EXPECT_EQ(reversed->next->next->next, nullptr);

    delete node3;
    delete node2;
    delete node1;
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
