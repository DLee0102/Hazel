# Hazel

1. startup file 很重要，决定默认调试的程序；可以在sln文件中设置startup file；
2. 虚析构函数的作用：确保子类的析构函数被调用，防止内存泄漏（特别是当子类对象被基类指针指向时）；任何基类的构造函数都应该是虚函数
3. 动态联编和静态联编（绑定）：这个概念和virtual有关；
4. 关于这里为什么要用virtual和static：方便获取被基类指针或引用指向的派生类的类别;也可以不声名virtual，因为这一宏是在子类当中使用的，当然，声明virtual将使代码逻辑更清晰；
```cpp
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }
```
5. 上面使用override的原因：override是C++11的新特性，用来显式的标注一个成员函数覆盖了基类的虚函数，这样可以让编译器帮助检查是否真的覆盖了基类的虚函数，如果没有覆盖，编译器会报错。如果不使用override，则可能不小心写成重载函数的情况，而编译器也不会报错。
6. 私有成员是那些我们不想暴露给外部用户的细节，这些细节我们了解就够了，因此设计为私有的


# 在HOTPOT开发中可能会用到的特性

1. 虚函数
2. 头文件处理
3. BIT()宏
