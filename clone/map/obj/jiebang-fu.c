//���� ���װ����
#include <ansi.h>
inherit ITEM;
inherit F_SAVE;

void create()
    {
    set_name( HIG"����"NOR, ({"jiebang fu"}));
	set_weight(5);
	set("long",
		"����һ�ž�������ħ���û����ɵ�ħ��ʯ������԰���ճ��(jie)�ڰ�װ�������װ���İ󶨡�\n" NOR);
	set("unit", "��");		
	set("value", 1);
	set("owner_id",1);
	set("xyzx_save_item", 1);
    set("value", 2000000000);	
    setup();	
}

void init()
{
    if ( environment() == this_player() )
		add_action("do_jie", "jie");
}

int do_jie(string arg)
{
	object me, ob, obj;
	string str, item;

	me = this_player();
	ob = this_object();	

	if ( environment(ob) != me )
		return 0;
	
	if ( sscanf(arg, "%s to %s", str, item) != 2 )
		return notify_fail("ָ���ʽ��jie ��ֽӢ���� to װ��Ӣ����\n");
	
	if ( !objectp(ob = present(str, me)) || !function_exists("do_jie", ob) )
		return notify_fail("ָ���ʽ��jie ��ֽӢ���� to װ��Ӣ����\n");
	
	if ( !objectp(obj = present(item, me)) && !objectp(ob = present(arg, me)))
		return notify_fail("������û������������\n");
	
	if ( !obj->query("armor_prop/armor") && !obj->query("weapon_prop/damage") )
		return notify_fail("��ֻ���ý��������������ߡ�\n");	
	
    if ( obj->query("equipped") )
      return notify_fail("��������������Ʒ��װ������ճ��������\n");
  
    if ( !obj->query("xyzx_sys/bind_type", 2) && !obj->query("xyzx_sys/bind_type", 1))
      return notify_fail("���װ���Ѿ�������ˣ������ʲô��\n");
  
	if ( obj->is_character() )
      return notify_fail("��Ҫ�ý������ʲô����\n");
	
	if ( obj->query("armor_prop/armor") || obj->query("weapon_prop/damage") && obj->query("xyzx_sys/bind_type", 1) && obj->query("xyzx_sys/bind_type", 2) )
	{
	message_vision(HIM"$N�ѽ���ճ����" + obj->query("name") + HIM"�ϣ�" + obj->query("name") + HIM"����˰󶨡�\n"NOR, me);	
	obj->set("owner_id", 1);
	obj->delete("bind_master_level");
	obj->set("xyzx_sys/bind_type", 0);
	obj->set("xyzx_save_item", 1);
	destruct(ob);
	return 1; 
	}	
}	  	  