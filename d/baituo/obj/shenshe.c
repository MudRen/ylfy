//shenshe.c
inherit ITEM;
void create()
{
	set_name("��·����", ({ "shenshe"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����ʶ·���������ߣ����԰����˴�����
		      ��ɽ��(��Ҽ���home����)\n");
		set("unit", "��");
		set("value", 0);
	}
}
void init()
{
    if ( !this_player()->is_ghost() )
 add_action("do_home","home");
}
int do_home()
{
    object me = this_player();
object ob;	
   if(me->query("family/family_name") != "����ɽ��")
	  return notify_fail("�㲻�ǰ���ɽ�ɵ��ӣ�����·���ߡ�������ʹ����\n");
        if( me->over_encumbranced() )
                return notify_fail("��ĸ��ɹ��أ��������á�\n");
        if( me->is_busy() )
                return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
		if(environment(me)->query("no_fly"))
			return 0;
        if (me->is_fighting()) return 0;
ob=first_inventory(me);	
if (ob->is_character() && !ob->is_corpse() )	
return 0;	
ob=next_inventory(ob);

   message_vision("$N�ӻ����ͳ�����·���ߡ������ﲻ֪����Щʲô��\n
   �ͼ�����·���ߡ�����о�ӣ�ҡͷ��β�ذ�$N������ɽ��ȥ������\n",me);
   me->move("/d/baituo/damen");
   return 1;
}
