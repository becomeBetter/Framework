#ifndef ECOMPONENTTYPE_H
#define ECOMPONENTTYPE_H
namespace RC_Framework {

    enum Component_Type
    {
        ECT_MAIN_UI,//主界面

        ECT_PLATFORM,//平台

        ECT_USER_INTERFACE,//用户界面

        ECT_BUSSINESS_LOGIC,//业务逻辑

        ECT_SYSTEM_SERVICE,//系统服务

        ECT_USER_PLUGIN//用户插件
    };

    enum Module_Status
    {
        EMS_UNINITIALIZED = 0x00000000,//未初始化

        EMS_INITIALIZING = 0x00000001,//正在初始化

        EMS_INITIALIZED = 0x00000002//已经初始化
    };
}
#endif // ECOMPONENTTYPE_H
