/*****************************************************************************
 
                         TGUI�ϵ����뷨˵��

*****************************************************************************/

//--------------------------���뷨��ʾ����------------------------------
//��ռ4��: ���ȿɸ�����ʾ�����ȵ���:

//��һ�У���ǰ���޸ĵ��ַ��������ͣ�ڴ�λ��
//�ڶ��У����뷨ͼ��+��ʾ
//������: ƴ��ʱ����ʾƴ���ַ�������ʱ��ʾ���ȷ���
//�����У�ƴ��ʱ��ʾ����ĺ��֣�����ʱ��ʾ���ȷ���

//����С��Ҫ��128*64ʾ��(����ʾ��ʾ��):ԭ��ʾ���й������֣�����༭����
//Ĭ�ϵ�һ��Ϊƴ�����뷨״̬:
//��������������������
//���й���          ��
//��ƴ��            ��
//��                ��
//��                �� 
//��������������������
//--------------------------���뷨���л�------------------------------
//1.1����Ϊƴ�����뷨״̬����#���л����뷽ʽ�����:
//��������������������
//���й���          ��
//��123             ��
//��                ��
//��                �� 
//��������������������
//1.2�����л������������뷨״̬����#�������л����뷽ʽ�����:
//��������������������
//���й���          ��
//��abc             ��
//��                ��
//��                �� 
//��������������������
//1.3�����л�����Сд��ĸ���뷨״̬����#�������л����뷽ʽ�����:
//��������������������
//���й���          ��
//��ABC             ��
//��                ��
//��                �� 
//��������������������
//1.4�����л�����D��д��ĸ���뷨״̬����#�������л����뷽ʽ�����:
//��������������������
//���й���          ��
//��ƴ��            ��
//��                ��
//��                �� 
//��������������������
//1.5�ػ�����ƴ�����뷨״̬
//��������������������
//���й���          ��
//��ƴ��            ��
//��                ��
//��                �� 
//��������������������
//1.5���޸���ɻ�ȡ���޸ģ�ֱ�Ӱ����˳��������˳��˽���

//----------------------------ƴ�����뷨------------------------------
//2.1.�ڽ���ƴ�����뷨״̬�����������롰�ˡ���,�������һ����ĸr�����:
//��������������������
//���й���          ��
//��ƴ��->ƴ������  ��
//��1p 2q 3r 4s     ��
//��ƽ1 Ƭ2 Ʒ3 ��4 �� 
//��������������������
//2.2.����ƴ����Ӧ�����ּ�eѡ��������ĸ,���ﰴ3�������:
//��������������������
//���й���          ��
//��ƴ��->ƴ������  ��
//��1pei 2re 3se    ��
//����1 ��2 ��3 ��4 �� 
//��������������������
//2.3.����ƴ����Ӧ�����ּ�nѡ��������ĸ,���ﰴ6�������:
//��������������������
//���й���          ��
//��ƴ��->ƴ������  ��
//��1pen 2ren 3sen  ��
//����1 ��2         �� 
//��������������������
//2.4.�����Ѵ�renƴ���ˣ����ǰ���ȷ�ϡ����¡����л���ƴ��ѡ��״̬�����:
//��������������������
//���й���          ��
//��ƴ��->ƴ��ѡ��  ��
//��1pen 2ren 3sen  ��
//����1 ��2         �� 
//��������������������
//2.5.ע�⣬�ڶ��С�ƴ�����롱��ɡ�ƴ��ѡ���ˣ���ƴ����ĸ������ʾ��Χ��
//  ��ɰ����»�����ҳ�������鿴��һҳƴ������������ʾ��Χ����ren��Ӧ�����I2�����:
//��������������������
//���й���          ��
//��ƴ��->����ѡ��  ��
//��1pen 2ren 3sen  ��
//����1 ��2 ��3 ��4 �� 
//��������������������
//2.6.ע�⣬�ڶ��С�ƴ��ѡ�񡱱�ɡ�����ѡ���ˣ������ֲ�����ʾ��Χ��
//  ��ɰ����»�����ҳ�������鿴��һҳ���֣���������ʾ��Χ�������ˡ���Ӧ�����I1�����:
//��������������������
//���й��˩�        ��
//��ƴ��            ��
//��                ��
//��                �� 
//��������������������
//2.7.���������Ѿ�������

//----------------------------�������뷨------------------------------
//3.1.��1.2�������뷨״̬��ֱ������С�������ּ�����
//��������������������
//���й���1��       ��
//��123             ��
//��                ��
//��                �� 
//��������������������
//----------------------------��С���뷨------------------------------
//4.1.��1.3,1.4 ��Сд��ĸ���뷨״̬��ֱ������С���̶�Ӧ���ּ����μ���
//      �����Ӧƴ�����磺������E�����һ�ΰ�3����:
//��������������������
//���й���1D��      ��
//��ABC             ��
//��                ��
//��                �� 
//��������������������
//4.2.���Կ�����Ӧ����һ����ĸ"D"�����ˣ�������3����:
//��������������������
//���й���1E��      ��
//��ABC             ��
//��                ��
//��                �� 
//��������������������
//4.3������ɣ��ȴ�Լ1S��������¸���ĸ

//----------------------------�������뷨------------------------------
//5.1.��1.1-1.4���κ����뷨״̬������*�������ɽ����������״̬:
//��������������������
//���й���1E��      ��
//��  1  .2  ,3  ?4 ��
//�� @1  #2  $3  %4 ��
//����1 ��2 ��3 ��4 ��
//��������������������
//5.2�����������"��"�������3��1�У����������ּ�31,��ѡ��:
//��������������������
//���й���1E��    ��
//��  1  .2  ,3  ?4 ��
//�� @1  #2  $3  %4 ��
//����1 ��2 ��3 ��4 ��
//��������������������
//5.3��û���ҵ���Ҫ�ķ��ţ��ɰ����»�����ҳ���鿴��һ��:
//��������������������
//���й���1E��    ��
//�� <1  >2  [3  ]4 ��
//�� {1  }2  (3  )4 ��
//�� /1  \2  -3  _4 ��
//��������������������
//5.4�����˳������˵����뷨״̬
