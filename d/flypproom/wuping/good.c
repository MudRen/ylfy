// /clone/misc/gift.c	
#include <ansi.h>
#define GIFT_NAME "�����"	
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
��  ��������������ʦ��                      �� 	
��                                            �� 	
����������������ʦ����ά��ϵͳ,��������һ�� ��      	
��            ��ʧ�ظ��貹��!                 ��              	
������������������������������������������������	
FYZQ ��ʦ��һ��С���⣬���(chai)��������ʲô��	
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
     object me = this_player();


  if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
if (me->query("��",1))        	
	{
	  destruct(this_object());
	  return notify_fail("һ��Ư������ӰͻȻ��һ�������г���,һ��ץ�������е����,����ͷ���˰��죺��ѽ~����Ѿ��ù��˰�~����͵��Ŷ~!!��˵��ת������.\n");
		
		
	}
  
          me->add("max_neili", 500000);	
           me->add("max_jingli",5000);	
       me->add("potential",50000);
       me->add("combat_exp",10000000) ;
	   if (me->query_skill("literate",1)<5000)
	   {
		   me->set_skill("literate",3000);
	   }
		if (me->query_skill("unarmed",1)<5000)
	   {
		   me->set_skill("unarmed",1000);
	   }
	   if (me->query_skill("dodge",1)<5000)
	   {
		   me->set_skill("dodge",1000);
	   }
	   if (me->query_skill("parry",1)<5000)
	   {
		   me->set_skill("parry",1000);
	   }
		if (me->query_skill("sword",1)<5000)
	   {
		   me->set_skill("sword",1000);
	   }
	   if (me->query_skill("force",1)<5000)
	   {
		   me->set_skill("force",1000);
	   }


tell_object(me,HIC "��С������Ĳ��������ֻ��һ�����������о��Լ���Ǳ����������Щ��\n" NOR);	

//ɾ���ϴ����������ɵĲ��������ӱ��β�����ȷ��ÿλ���ֻ����һ�Ρ�
me->delete("����",1);    	
me->set("��",1);      	
     destruct(this_object());
	 return 1;
}
void owner_is_killed() { destruct(this_object()); }
int query_autoload() { return 1; }
