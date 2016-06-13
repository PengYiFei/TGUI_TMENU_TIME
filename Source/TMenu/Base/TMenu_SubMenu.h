/* ----------------------------------------------------------------------------
 *                TMenu�Ӳ˵�ʵ��
 * --------------------------------------------------------------------------*/

#ifndef __T_MENU_SUB_MENU_H 
#define __T_MENU_SUB_MENU_H

#include "TMenuBase.h"

/**********************************************************************
                      ������
**********************************************************************/
//����Ĭ�ϵ�ѡ��ť��ʽ(��TWidget.h�뵥ѡ�ؼ�):
#define   TM_SUB_MENU_STYLE_DEFAULT \
  (TWIDGET_EN_HEADER | TWIDGET_EN_VSCOLL | TWIDGET_EN_NOTIFY)

//ע:���õ���:
//#define   TWIDGET_EN_FRAME    0x80  //�ù������б߿�,��LC�߶�>-3��ʱ������Ч
//#define   TWIDGET_EN_HEADER   0x40  //������ʾ����ͷ
//#define   TWIDGET_EN_HSCOLL   0x20  //������ʾˮƽ������
//#define   TWIDGET_EN_VSCOLL   0x10  //������ʾ��������
//#define   TWIDGET_EN_RETURN   0x08  //�����ػ���־
//#define   TWIDGET_EN_NOTIFY   0x04  //�޹�������߿�ʱ�������û���ʱ��ʾ��ʾ��Ϣ
//#define   TLISTBOXEX_EN_RETURN  0x02      //������������

/**********************************************************************
                     �û�ʹ�����
**********************************************************************/
//��Ϊ�Ӳ˵�ʱ,�˵��ṹ�����¶���:
//typedef struct _TMenu{
//  TMTYPE_SUBMENU;           //�˵�����Ϊ�Ӳ˵�ģʽ
//  unsigned char Size;       //�ɹ�ѡ����Ӳ˵������
//  LanguageCode_t *pgHeader; //�˵�ͷ,ΪNULLʱ�ӻص����ȡ
//  struct _TMenu *pParent;   //���ѵĸ��˵�,û��ʱΪNULL
//  const TMenu_t*;           //������ѵ��Ӳ˵���������ͷ
//  TMenuNotify_t Notify;     //���û��ռ佻����ͨ������
//}TMenu_t;

//��ģʽ���û�����־

//�û������ݽṹ:
struct _SubMenuUser{
 TItemSize_t Sel;  //��ǰ�Ӳ˵�����λ��
 //�û����ر�־,����ģ��ص�����˵��
 unsigned char UserFlag; 
};

//�Ӳ˵�ģʽ�����޻ص�����
//���лص�����ʱ,��ʾ�ò˵��ڰ�������,����Ӧ����ͨ��:
//����Ϊ:TM_NOTIFY_SET_DATAʱ,��ʾ��Sel���ڰ�ȷ������

//�ڻص�������ִ�ж�Ӧ������󣬻�����UserFlag���÷���״̬:
//������1ʱ,��ʾ����Ϊ����,������Բ�ѡ��

/**********************************************************************
                     �ڲ����ݽṹ
**********************************************************************/
struct _SubMenuData{
 TListboxEx_t  ListboxEx;   //�ṹ����
 unsigned char Flag;            //�ڲ���־
 struct _SubMenuUser User;     //�û�����
};

//------------------------��������ʵ��----------------------------
//1:���������Ͳ˵�,���û���������ݲ�������ʾ
//���ش����ɹ�:
signed char TMenu_SubMenuCreate(const TMenu_t *pMenu,    //ָ��Ĳ˵�ϵͳ
                                TWinHandle_t hWin,       //������˵��Ĵ���
                                //�������������,�����ʾ�ϴβ˵�λ��
                                unsigned char Data,
                                void *pv);      //�ɹ�ʹ�õ����ɻ�����


//------------------------��Ӧ��������ʵ��----------------------------
//2:��Ӧ��������������������û��������ݽ���,��������ʾ
//����ֵ����Ϊ: ��ֵ:������Ӧ�Ӳ˵�,-1,����,-2:�����ϲ�˵�
signed char TMenu_SubMenuKey(const TMenu_t *pMenu,    //ָ��Ĳ˵�ϵͳ
                             unsigned char Key,       //����ļ�ֵ
                             void *pv);      //�ѱ�ʹ�õ��������ݻ�����

//-------------------------�Ӳ˵�ͨ���ص�ʵ�ֺ���-----------------------------
//�����ڲ�ͨ��ʹ��
const void*TMenu_SubMenu_Notify(void *pvPource,
                                unsigned char Type,
                                const void *pvData);

/**********************************************************************
                      �ص�����
**********************************************************************/

//----------------------�õ���ǰ��ʾ��ʽ-------------------------
#ifdef TMENU_STYLE_VARIABLE   //�ɱ���ʽʱ���û�������
  unsigned char TMenu_SubMenu_cbGetCurStyle(void);
#else
  #define TMenu_SubMenu_cbGetCurStyle() \
    (TM_SUB_MENU_STYLE_DEFAULT | TLISTBOXEX_EN_RETURN)
#endif

#endif