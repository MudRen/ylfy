
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(HIG"��ɽ����"NOR, ({ "dushan huangyu","dushan","huangyu"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",HIG"���Ǵ��������ղص�һ�鼫Ʒ��ɽܽ�������ʵ�ϸ�壬��Ӳ���ܣ�������ʯ����Ө�����˰������֡�\n"
		    						"���ƺ�����������ľ��ò��ϡ�\n\n"NOR);
                set("no_sell", 1);
                //set("no_drop", "��ô���ļ�Ʒ�ʼ���ʯ����ɲ������ⶪ����\n");
                set("rate", 4); //���ò��ϵȼ�
                set("rigidity",250+random(50)); //���ò���Ӳ�ȣ�Ҳ������Ӳ��
                set("can_make", "all");
                set("not_make", ({ "��", "ս��","����", "ѥ��", "����" ,"ָ��"}));
                set("material_attrib", "stone");
                set("power_point", 290+random(30)); //���ɺ��jiali��С
              }
}

