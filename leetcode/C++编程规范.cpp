/*

*/
#include "common.h"
#include "test_tree.h"
#include "test_list.h"
#include "timer.h"
#include <fstream>
#include <exception>
#include <memory>
#include <optional>

/*********************************************************************/
/* constexpr 与 const 常量与只读*/
/*********************************************************************/
template <int N>
class C
{
};

constexpr int FivePlus(int x) { return 5 + x; }

void f(const int x)
{
    // C<x> c1;           // Error: x is not compile-time evaluable.
    C<FivePlus(6)> c2; // OK
}

void TestConstexpr()
{
    const int x = 5;
    C<x> c1;           // OK!!! 此处用x的「常量」语义
    *(int *)(&x) = 6;  // Still OK! 只处用x的「只读」语义，去除const后可写
    C<x> c2;           // Still OK! c2是C<5>类型（不是C<6>！）
    C<FivePlus(x)> c3; // Still OK! c3是C<10>类型（不是C<11>！）

    printf("X的值 %d\n", x); // 此处绝大多数（所有？）C++编译器会输出5！！
                             // （然而，如果用一个C编译器来编译类似代码，一定输出6）
    const int *p = &x;
    printf("X得值 %d\n", *p); // 此处，大多数C++编译器输出6
}

/*********************************************************************/
/* constexpr 函数*/
/*********************************************************************/
// Pass by value
constexpr float exp(float x, int n)
{
    return n == 0 ? 1 : n % 2 == 0 ? exp(x * x, n / 2)
                                   : exp(x * x, (n - 1) / 2) * x;
}

// Pass by reference
constexpr float exp2(const float &x, const int &n)
{
    return n == 0 ? 1 : n % 2 == 0 ? exp2(x * x, n / 2)
                                   : exp2(x * x, (n - 1) / 2) * x;
}

//
// Compile-time computation of array length
template <typename T, int N>
constexpr int length(const T (&)[N])
{
    return N;
}

// Recursive constexpr function
constexpr int fac(int n)
{
    return n == 1 ? 1 : n * fac(n - 1);
}

// User-defined type
class Foo
{
public:
    constexpr explicit Foo(int i) : _i(i) {}
    constexpr int GetValue() const
    {
        return _i;
    }

private:
    int _i;
};

/*********************************************************************/
/* 变参函数 LOG打印 */
/*********************************************************************/
constexpr char INFO[] = "[INFO]";
constexpr char DEBUG[] = "[DEBUG]";
constexpr char WARNGING[] = "[WARNGING]";
constexpr char ERROR[] = "[ERROR]";

void Loge(int priority)
{
    std::cerr << priority << std::endl;
}

template <typename T, typename... Args>
constexpr void Loge(int priority, T head, Args... tail)
{
    std::cerr << head << " ";
    Loge(priority, tail...);
}

void Log(void)
{
    std::cerr << std::endl;
}

template <typename T, typename... Args>
constexpr void Log(T head, Args... tail)
{
    std::cerr << head << " ";
    Log(tail...);
}

void TestLog()
{
    Log(ERROR, "this is a error", 1, 1.1, '.');
}

int TestConstexprFunc()
{
    // foo is const:
    constexpr Foo foo(5);
    // foo = Foo(6); //Error!

    // Compile time:
    constexpr float x = exp(5, 3);
    constexpr float y{exp(2, 5)};
    constexpr int val = foo.GetValue();
    constexpr int f5 = fac(5);
    const int nums[]{1, 2, 3, 4};
    const int nums2[length(nums) * 2]{1, 2, 3, 4, 5, 6, 7, 8};
    cout << exp(2, 5) << length(nums) << length(nums2) << endl;

    // Run time:
    cout << "The value of foo is " << foo.GetValue() << endl;
}

/*********************************************************************/
/* 右值引用 */
/*********************************************************************/
struct RValue
{
    RValue() : sources("hello!!!") {}
    RValue(RValue &&a)
    {
        sources = std::move(a.sources);
        cout << "&& RValue" << endl;
    }

    RValue(const RValue &a)
    {
        sources = a.sources;
        cout << "& RValue" << endl;
    }

    void operator=(const RValue &&a)
    {
        sources = std::move(a.sources);
        cout << "&& ==" << endl;
    }

    void operator=(const RValue &a)
    {
        sources = a.sources;
        cout << "& ==" << endl;
    }

    string sources;
    ;
};

RValue get()
{
    RValue a;
    return a;
}

void put(RValue a)
{
    Log(a.sources);
}

int TestMove()
{
    RValue a = get();
    cout << "---------------" << endl;
    put(RValue());
    return 0;
}

/*********************************************************************/
/* 异常处理 */
/*********************************************************************/
class FooException : public exception
{
public:
    FooException(const std::string &exceptLog, unsigned int code)
        : m_code(code), m_what_arg(exceptLog) {}

    virtual const char *what(void) const noexcept override
    {
        auto text = "[ERROR] INFO: " + m_what_arg + " CODE: " + std::to_string(m_code);
        return text.c_str();
    }

private:
    unsigned int m_code;
    std::string m_what_arg;
};

class FooFileTest
{
public:
    FooFileTest(const std::string &fileName)
    {
        file.open(fileName); // RAII会自动关闭文件
        if (file.fail())
        {
            try
            {
                throw FooException("Cannot open file", 10086); // 抛出异常，使得Foo的构造失败
            }
            catch (const FooException &e)
            {
                cout << e.what() << endl;
            }
        }
        // resource = std::make_unique<int>(); // 使用智能指针保证释放
        // DoMoreInitialization();              // 这里的异常会抛出构造函数
    }

private:
    std::ifstream file;
    // std::unique_ptr<int> resource;
};

class FooFileTestC
{
public:
    static std::optional<FooFileTestC> Create(const std::string &fileName)
    {
        std::ifstream file(fileName); // RAII会自动关闭文件
        if (file.fail())
        {
            return {}; // 返回特殊值
        }
        std::unique_ptr<int> resource = std::make_unique<int>(); // 使用智能指针保证释放
        return FooFileTestC(std::move(file), std::move(resource));
    }

private:
    FooFileTestC(std::ifstream file, std::unique_ptr<int> resource)
        : file(std::move(file)), resource(std::move(resource))
    {
        // 这样的构造函数只设置成员值，不会出错
    }
    std::ifstream file;
    std::unique_ptr<int> resource;
};

void TestException()
{
    FooFileTest f("./1.txt");
    std::optional<FooFileTestC> fc = FooFileTestC::Create("./2.txt");
    if (fc)
    {
        Log("fc create success");
    }
    else
    {
        Log("fc create false");
    }
}

int main()
{
    PrintTitle(__FILE__);
    TestConstexpr();
    TestConstexprFunc();
    TestLog();
    TestMove();
    TestException();
    return 0;
}