#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>

using namespace std;

namespace SSDK
{
    /**
     *  @brief Rectangle
     *         获取元件的X,Y坐标,角度及元件的长和宽的值
     *  @author bob
     *  @version 1.00 2017-11-21 bob
     *                note:create it
     */
    class Rectangle
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //构造 & 析构 函数
        //初始化类的成员变量
        Rectangle();
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //访存函数,给类的成员变量赋值
        //给成员变量X赋值,获取元件的X轴坐标
        void setX(double x){ this->m_X = x;}
        //给成员变量Y赋值,获取元件的Y轴坐标
        void setY(double y){ this->m_Y = y;}
        //给成员变量angle赋值,获取元件的角度
        void setAngle(double angle){this->m_angle = angle;}
        //给成员变量width赋值,获取元件的宽度
        void setWidth(double width){this->m_width = width;}
        //给成员变量height赋值,获取元件的高度
        void setHeight(double height){this->m_height = height;}
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //成员变量
        double m_X;                           //元件X的坐标
        double m_Y;                           //元件Y的坐标
        double m_angle;                       //元件的角度
        double m_width;                       //元件的宽度
        double m_height;                      //元件的高度
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    };
}  //End of namespace SSDK

#endif // RECTANGLE_HPP
