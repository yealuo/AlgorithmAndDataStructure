#include <iostream>


using namespace std;

int main() {
    perror("测试");
    perror("内存分配失败！");
    exit(EXIT_FAILURE);
    return 0;
}