// /d/city/obj/gift.c
// ע�⣺���﷢��Add�ĵ��ø�ʽ���ʹ�� add(string prop, mixed data, 1)

#include <ansi.h>
#define LAST_PAR "sorry"
#define THIS_PAR "sorrysf"
#define GIFT_NAME "���������"

inherit ITEM;

void create()
{
    set_name(HIR + GIFT_NAME + NOR, ({"gift","liwu"}));
    set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
        set("long", @LONG
������������������������������������������������	
��                                            �� 	
��  Ϧ�����֣�������ʦ��                      ��        	
��                                            �� 	
��       ������������ף����WANFU ALL          ��                	
��                                            �� 	
��            ϣ�����ǵ����������!           ��        	
��                                            �� 	
��                                            �� 	
��                        sigh, addoil!       �� 	
��                                            �� 	
������������������������������������������������	
XYZX ��ʦ��һ��С���⣬���(chai)��������ʲô��	
LONG
);
    set("value", 0);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_drop",1);
  }
    setup();
}
void init()
{
    add_action("do_chai", "chai");
}

int do_chai(string arg)
{
	mapping my_score;
	string *myscore;
	int max;
	object me = this_player();
	
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	
	if (me->query(THIS_PAR + "_chai"))
	{
		tell_object(me,HIY "һ��Ư������ӰͻȻ��һ�������г���,һ��ץ�������е����,����ͷ���˰��죺��ѽ~����Ѿ��ù��˰�~����͵��Ŷ~!!��˵��ת������.\n"NOR);
		destruct(this_object());
	}
	else
	{
		/*_________________����״̬_______________________*/
		my_score = get_mapping_config(DATA_CONFIG_DIR+"mapping/gift_new.mapp");
		if ( mapp(my_score) && sizeof(my_score) )
		{
			myscore = keys(my_score);
			for ( int i=0; i<sizeof(myscore); i++ )
			{
				if ( me->query(myscore[i], 1) < my_score[myscore[i]] )
					me->set(myscore[i], my_score[myscore[i]]);
			}
		}
		/*____________________end_________________________*/
		/*____________________����________________________*/
		my_score = get_mapping_config(DATA_CONFIG_DIR+"mapping/gift_new_skill.mapp");
		if ( mapp(my_score) && sizeof(my_score) )
		{
			myscore = keys(my_score);
			for ( int i=0; i<sizeof(myscore); i++ )
			{
				if ( me->query_skill(myscore[i], 1) < my_score[myscore[i]] )
					me->set_skill(myscore[i], my_score[myscore[i]]);
			}
		}
		/*____________________end_________________________*/
		/*___________________�ָ�������___________________*/
		max = me->query("max_jingli") / 4;
		me->set("max_jing", max);
		me->set("eff_jing", max);
		me->set("jing", max);
		max = me->query("max_neili") / 4;
		me->set("max_qi", max);
		me->set("eff_qi", max);
		me->set("qi", max);
		/*____________________end_________________________*/
		tell_object(me,HIC "��С������Ĳ��������ֻ��һ������������ʱ����ԼԼ�е��Լ���������һЩ�仯��\n" NOR);
		
		//ɾ���ϴ����������ɵĲ��������ӱ��β�����ȷ��ÿλ���ֻ����һ�Ρ�
		me->delete(LAST_PAR + "_chai");
		me->set(THIS_PAR + "_chai",1);
		destruct(this_object());
	}
	return 1;
}

void owner_is_killed() { destruct(this_object()); }
