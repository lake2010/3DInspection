#include "appsetting.hpp"

using namespace App;
using namespace std;


AppSetting::AppSetting()
{
    //初始化成员变量
    this->m_companyName = "";
    this->m_laneMode = "";
    this->m_lang = "";
    this->m_machineType ="";
    this->m_theme = "";
}

AppSetting::~AppSetting()
{

}

void AppSetting::readAppSetting(const QString &path)
{
    try
    {
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //判断配置文件在目录中是否存在
        //将数据写入至配置文件中
        if(!QFile::exists(path))
        {
            writeAppSetting(path);
        }
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //如果配置文件存在,则读取文件中相应的数据并判断数据是否符合要求
        //如果数据不符合要求,则将该字段数据写为默认值
        else
        {
            //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            //step1
            //读取文件Theme内容,并判断是否在枚举中,如果不在则写入默认值
            QSettings configFile(path,QSettings::IniFormat);

            this->m_theme = configFile.value("THEME").toString().toStdString();

            //判断当前主题是否在枚举中,如果不在,则写入默认值
            if( this->m_theme != VAR_TO_STR(THEME::BLACK) &&
                this->m_theme != VAR_TO_STR(THEME::WHITE))
            {
                configFile.setValue("THEME","BLACK");
            }

            //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

            //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            //step2
            //读取文件Lang内容,并判断是否在枚举中,如果不在则写入默认值
            this->m_lang = configFile.value("LANG").toString().toStdString();

            if( this->m_lang != VAR_TO_STR(LANG::CN) &&
                this->m_lang != VAR_TO_STR(LANG::EN) )
            {
                configFile.setValue("LANG","CN");
            }

            //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

            //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            //step3
            //读取文件LaneMode内容,并判断是否在枚举中,如果不在则写入默认值
            this->m_laneMode = configFile.value("LANEMODE").toString().toStdString();

            if( this->m_laneMode != VAR_TO_STR(LANEMODE::SIMULATOR) &&
                this->m_laneMode != VAR_TO_STR(LANEMODE::SINGLELANE) &&
                this->m_laneMode != VAR_TO_STR(LANEMODE::DUANLANE))
            {
                configFile.setValue("LANEMODE","SINGLELANE");
            }
            //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

            //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            //step4
            //读取文件MachineType内容,并判断是否在枚举中,如果不在则写入默认值
            this->m_machineType = configFile.value("MACHINETYPE").toString().toStdString();

            if( this->m_machineType != VAR_TO_STR(MACHINETYPE::AOI) &&
                this->m_machineType != VAR_TO_STR(MACHINETYPE::SPI))
            {
                configFile.setValue("MACHINETYPE","AOI");
            }

            //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

            //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            //step5
            //读取文件CompanyName内容,并判断是否在枚举中,如果不在则写入默认值
            this->m_companyName = configFile.value("COMPANTNAME").toString().toStdString();
            //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        }
        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    }
    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //如果捕获异常,则输出异常信息
    catch(const exception &ex)
    {
        THROW_EXCEPTION(ex.what());
    }
    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
}

void AppSetting::writeAppSetting(const QString &path)
{
    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //将类QSettings实例化一个对象
    //path:存放文件的路径
    //QSettings::IniFormat: 为存放文件的格式
    QSettings configFile(path,QSettings::IniFormat);

    //将配置文件的"Theme","CompanyName","MachineType","LaneMode","Lang"写入默认值
    configFile.setValue("THEME","BLACK");
    configFile.setValue("MACHINETYPE","AOI");
    configFile.setValue("LANEMODE","SINGLELANE");
    configFile.setValue("LANG","CN");
    configFile.setValue("COMPANYNAME","Scijet");
    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
}
