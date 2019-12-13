#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIB"������"NOR, ({ "tuzhu" }) );
    set_weight(1);
            set("no_put", 1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	       
            set("no_put", 1);
	     set("icon", "05005");
            set("no_steal", 1);
            set("no_get", 1);
            set("no_beg", 1);
            set("value", 100000);
            set("unit", "��");
            set("material", "paper");
            set("long", "�������(gohome),��(usezhu)���뿪�Թ�����(setzhu)�����ÿռ���λ��\n");
          }

    setup();
}
void init()
{
	add_action("do_eatt", "gohome");
	add_action("do_eat", "usezhu");
	add_action("do_set", "setzhu");
}

int do_set(string arg)
{
	object *inv;
	int sizeinv;
        object me = this_player();
        string target;
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�㲻�ܱ�����������!\n");
       		
		}
    if (me->is_fighting()) 
        return notify_fail("���������������!\n");
    if (me->is_busy()) 
        return notify_fail("������������!\n");
    if (me->query("neili")<1000)
	return notify_fail("�����������!\n");
    if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR)
{
        target=(string)file_name(environment(me));
        me->set("jobtarget",target);
        me->start_busy(8);
        message_vision(HIG "$N�԰����ó���һ������������!\n" NOR, me);
        message_vision(HIG "�´�ʹ���������㽫��ֱ����������!\n" NOR, me);
        me->add("neili",-1000);
}	
else 
{
        message_vision(HIG "$N���ﲻ��ʹ��!\n" NOR, me);
}
	return 1;
}


int do_eat(string arg)
{
	object *inv;
	int sizeinv;
        object me = this_player();
        object tarset;
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�㲻�ܱ�����������!\n");
       		
		}

    if (me->is_fighting()) 
        return notify_fail("���������������!\n");
    if (me->is_busy()) 
        return notify_fail("������������!\n");
    if (me->query("neili")<1000)
	return notify_fail("�����������!\n");

    if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR)
{
        if (!me->query("jobtarget"))
       {
        me->move("d/city/guangchang");
       }
      else{
      tarset=me->query("jobtarget");
      me->move(tarset);
      }
        me->start_busy(8);
        message_vision(HIG "$N�԰����ó���һ������������!\n" NOR, me);
        me->add("neili",-1000);
	destruct(this_object());
}	
else 
{
        message_vision(HIG "$N���ﲻ��ʹ��!\n" NOR, me);
}
	return 1;
}

int do_eatt(string arg)
{
	object *inv;
	int sizeinv;
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�㲻�ܱ�����������!\n");
       		
		}

    if (me->is_fighting()) 
        return notify_fail("���������������!\n");
    if (me->is_busy()) 
        return notify_fail("������������!\n");

    if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR)
{
        me->move("d/migong/migong3");
        me->start_busy(8);
        message_vision(HIG "$N�԰����ó���һ������������!\n" NOR, me);
	destruct(this_object());
}	
else 
{
        message_vision(HIG "$N���ﲻ��ʹ��!\n" NOR, me);
}
	return 1;
}