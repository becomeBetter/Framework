#ifndef ITABMENU_H
#define ITABMENU_H
#define IID_TAB_MENU ("713ABDEF-6D72-4C32-A7E3-6925F01D06AB")

struct ITabMenu
{
	//获取菜单ID
	virtual QString getMenuID(unsigned int index) const = 0;

	//使index处的菜单处于选中状态
	virtual void setChecked(unsigned int index) = 0;
};
#endif//ITABMENU_H