#ifndef ITABMENU_H
#define ITABMENU_H
#define IID_TAB_MENU ("713ABDEF-6D72-4C32-A7E3-6925F01D06AB")

struct ITabMenu
{
	//��ȡ�˵�ID
	virtual QString getMenuID(unsigned int index) const = 0;

	//ʹindex���Ĳ˵�����ѡ��״̬
	virtual void setChecked(unsigned int index) = 0;
};
#endif//ITABMENU_H