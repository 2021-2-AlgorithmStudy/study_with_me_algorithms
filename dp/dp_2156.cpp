#include<iostream>
#include<algorithm>
int quantity[10001] = { 0, };
int changable[10001] = { 0, };


int main_2156() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> quantity[i];
        changable[i] = quantity[i];
    }

    changable[1] = quantity[0] + quantity[1];
    changable[2] = std::max({ changable[0] + quantity[2], quantity[1] + quantity[2], changable[1] });
    //changable[1] �� max ������ �񱳴���� �Ǵ°��� ����Ʈ

    for (int i = 3; i < n; i++) {
        changable[i] = std::max({ changable[i - 1],changable[i - 2] + quantity[i],changable[i - 3] + quantity[i - 1] + quantity[i] });
        //changable[i-1] �� max ������ �񱳴���� �Ǵ°��� ����Ʈ
    }

    std::cout << changable[n - 1] << std::endl;

    return 0;
}