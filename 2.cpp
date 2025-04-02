#include <iostream>
using namespace std;

class Box {
private:
    float x, y, z;  // 长方体的长、宽、高

public:
    // 默认构造函数，将所有值初始化为0
    Box() {
        x = y = z = 0;
        cout << "x=" << x << " y=" << y << " z=" << z << endl;
        cout << "s=0" << endl;   // 表面积
        cout << "v=0" << endl;   // 体积
    }

    // 带一个参数的构造函数
    Box(float length) {
        x = length;
        y = z = 0;
        cout << "x=" << x << " y=" << y << " z=" << z << endl;
        cout << "s=0" << endl;   // 表面积为0因为只有长度
        cout << "v=0" << endl;   // 体积为0因为缺少宽或高
    }

    // 带两个参数的构造函数
    Box(float length, float width) {
        x = length;
        y = width;
        z = 0;
        cout << "x=" << x << " y=" << y << " z=" << z << endl;
        cout << "s=0" << endl;   // 表面积为0因为没有高度
        cout << "v=0" << endl;   // 体积为0因为没有高度
    }

    // 带三个参数的构造函数
    Box(float length, float width, float height) {
        x = length;
        y = width;
        z = height;
        cout << "x=" << x << " y=" << y << " z=" << z << endl;

        // 计算表面积：2(长×宽 + 长×高 + 宽×高)
        float s = 2 * (x*y + x*z + y*z);
        cout << "s=" << s << endl;

        // 计算体积：长×宽×高
        float v = x * y * z;
        cout << "v=" << v << endl;
    }
};

int main() {
    // 测试不同的构造函数
    Box b1;                  // 无参数构造函数
    Box b2(10);             // 一个参数构造函数
    Box b3(10, 20);         // 两个参数构造函数
    Box b4(10, 20, 30);     // 三个参数构造函数

    return 0;
}