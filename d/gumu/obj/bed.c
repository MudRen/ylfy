//Modify By csy 98/12/29 bed.c ����
#include <ansi.h>

inherit ITEM;

void create()
{
     set_name(HIC"����"NOR, ({"hanyu chuang","bed","chuang"}));
     set_weight(2500000);
     if (clonep())
     set_default_object(__FILE__);
     else {
     set("unit", "��");
     set("long", HIC"�˴�����ȥ����ͨͨ������ʯ��ȴ�ǽ�����������������������������񴲣�
��˵�д˴������κ������˲����л���֮Ч��С��Ů�������ܽ��ַ�����ȫ��
���Ӻ���һ�������ӳ����죬�˴�������Ĩ���������Դ˴����ٳ��书, ����
���ڹ���Ϊ��\n"NOR);

     set("value", 800000);
     setup();
     }
}

