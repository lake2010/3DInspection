#ifndef FORMATCONVERTION_HPP
#define FORMATCONVERTION_HPP

#include<iostream>
#include<string>
#include<sstream>

#include "../sdk/customexception.hpp"

using namespace std;

class FormatConvertion
{
public:
    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //构造 & 析构函数
    FormatConvertion();
    ~FormatConvertion();

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //成员函数
    /*
    *  @brief  intToString
    *           将整形数字转换为字符串
    *  @param  var : 整形变量,即需要转换成字符串的整形变量
    *  @return  将整形数字转换后的字符传返回
    */
    std::string intToString(int var);
    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
};

#endif // FORMATCONVERTION_HPP