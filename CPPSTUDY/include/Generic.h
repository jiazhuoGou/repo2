#include<iostream>

template <class T, typename Q>

  auto  add(T x, Q y)
  {
      return (x + y);
  }

//  函数模板定义
template <typename T>

T Max(T x, T y)
{
    return (x > y?x : y);
}

