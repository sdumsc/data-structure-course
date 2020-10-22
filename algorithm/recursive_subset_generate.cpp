#include <iostream>
#include <functional>

using namespace std;

//递归实现子集生成（对main函数解耦）.
template <class T>
void subset_generate(T * a, int m, int n, int * t, function<void(T *, int *, int)> f);

int main() {
    cout << "Simple test using char array." << endl;
    cout << "Please enter the #array: ";
    int n = 0;
    cin >> n;
    char * a = new char[n];
    //初始化字符数组。
    for (int i = 0; i < n; i++) {
        a[i] = (char)(i + 97);
    }
    subset_generate<char>(a, 0, n, (int *)nullptr, [](char * a, int * t, int n) -> void {
        cout << "{";
        int flag = 0;
        for (int i = 0; i < n; i++)
            if(t[i]) {
                cout << a[i] << ", ";
                flag = 1;
            }
        if (flag) cout << "\b\b";
        cout << "}" << endl;
        return;
    });
    return 0;
}

template <class T>
void subset_generate(T * a, int m, int n, int * t, function<void(T *, int *, int)> f) {
    if ( m == n ) {
        //通过仿函数来传递对生成子集进行的操作，简单的函数式编程，自由度更高一点。
        //测试中给出的实现是子集打印。
        f(a, t, n);
        //哈哈哈哈，基线条件忘记返回了。 我就是一个憨批。 -- debug有感。
        return;
    }
    
    //使用t数组记录递归状态，首先要进行初始化。
    if ( t == nullptr ) {
        t = new int[n];
    }

    //对每个元素的两种状态进行递归。
    for (int i = 0; i < 2; i++) {
        t[m] = i;
        subset_generate(a, m+1, n, t, f);
    }
    return;
}