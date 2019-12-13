// �����������ֵ
#define ADD_MAX_SX_NUM 1000
// ����������ߵȼ�
#define MAX_LEVLUP_NUM 30

inherit ITEM;
inherit F_SAVE;
#include <item_sx.h>

void create()
{	      
	set_name( HIW"������"NOR, ({"hanyu jingtie"}) );
    set_weight(5);
	set("long", "һ��Ƚϳ����Ĳ��ϣ�����ʹ��������������(ronglian)�ڱ������������ԡ�\n"NOR);	
	set("unit", "��");
	set("value", 1);
	set("owner_id",1);
	set("xyzx_save_item", 1);
	set("xyzx_sys/bind_type", 0);

	setup();
}

void init()
{
    if ( environment() == this_player() )
		add_action("do_ronglian", "ronglian");
}

int do_ronglian(string arg)
{
	object me, ob, obj;
	string str, item, *item_sx, *item_jc;
	int i, v, sx_num;

	me = this_player();
	ob = this_object();
	v = 0;

	if ( environment(ob) != me )
		return 0;
	
	if ( !arg )
		return notify_fail("��Ҫ�Ѻ���������(ronglian)��ʲô�ϣ�\n");
	
	if ( sscanf(arg, "%s to %s", str, item) != 2 )
		return notify_fail("ָ���ʽ��ronglian ������Ӣ���� to װ��Ӣ����\n");
	
	//if ( !objectp(ob = present(str, me)) || !function_exists("do_tie", ob) )
	//	return notify_fail("ָ���ʽ��tie ��ֽӢ���� to װ��Ӣ����\n");
	
	if ( !objectp(obj = present(item, me)) && !objectp(ob = present(arg, me)))
		return notify_fail("������û������������\n");
	
	if ( !obj->query("armor_prop/armor") && !obj->query("weapon_prop/damage") )
		return notify_fail("��ֻ���ú�����������������ߵĵȼ���\n");
	
	if ( obj->query("equipped") )
      return notify_fail("��������������Ʒ��װ�������ú��������С�\n");
   
    if ( obj->query("weapon_prop/damage") )
		v = obj->query("weapon_prop/level");
	
	else if ( obj->query("armor_prop/armor") )
		v = obj->query("armor_prop/level");
	
    if ( v >= 30 )
      return notify_fail("���װ���Ѿ������ˣ���������ʲô��\n");
  
	if ( obj->is_character() )
      return notify_fail("��Ҫ�Ѻ���������(ronglian)��ʲô�ϣ�\n");

      if ( obj->query("no_tie"))                                      
        return notify_fail("����װ�����������ȼ���\n");
      
	// ʧ�����趨
	if ( random(MAX_LEVLUP_NUM + 1) < v )	
	{
		message_vision(HIM"$N��ͼ�������Ѻ�����������" + obj->query("name") + HIM"�������ȼ���������ȴ����������߶���ֱ�ӱ����������\n"NOR, me);
		tell_object(me, HIY + obj->query("name") + HIY"�ȼ�����ʧ�ܡ�\n"NOR);
		destruct(ob);
		return 1;
	}	
	
	if ( obj->query("weapon_prop/damage") )
	{
		message_vision(HIM"$N�Ѻ�����������" + obj->query("name") + HIM"�ϣ�" + obj->query("name") + HIM"�ĵȼ�������"HIW + chinese_number(obj->query("weapon_prop/level") + 1) + "��" + HIM"��\n"NOR, me);
		item_sx = keys(weapon_shuxing);
		item_jc = values(weapon_shuxing);
		v = sizeof(item_sx);
		for (i = 0; i < v; i++)
		{
			if ( obj->query("weapon_prop/" + item_sx[i]) )
			{
				sx_num = obj->query("weapon_prop/" + item_sx[i]) * (obj->query("weapon_prop/level") + 1) / 100;
				if ( sx_num < 1 )
					sx_num = 1;
				else if ( sx_num > ADD_MAX_SX_NUM )
					sx_num = ADD_MAX_SX_NUM;
				obj->add("weapon_prop/" + item_sx[i], sx_num);
				message_vision(HIG + obj->query("name") + HIG"��" + item_jc[i] + "����Ч��������"HIW + chinese_number(sx_num) + "�㡣\n"NOR, me, ob);
			}
		}
		obj->add("weapon_prop/level", 1);
		// ��ֵ����
		obj->add("value", obj->query("value") / 100 * obj->query("weapon_prop/level"));
	}
	else if ( obj->query("armor_prop/armor") )
	{
		message_vision(HIM"$N�Ѻ�����ճ����" + obj->query("name") + HIM"�ϣ�" + obj->query("name") + HIM"�ĵȼ�������"HIW + chinese_number(obj->query("armor_prop/level") + 1) + "��" + HIM"��\n"NOR, me);
		item_sx = keys(armor_shuxing);
		item_jc = values(armor_shuxing);
		v = sizeof(item_sx);
		for (i = 0; i < v; i++)
		{
			if ( obj->query("armor_prop/" + item_sx[i]) )
			{
				sx_num = obj->query("armor_prop/" + item_sx[i]) * (obj->query("armor_prop/level") + 1) / 100;
				if ( sx_num < 1 )
					sx_num = 1;
				else if ( sx_num > ADD_MAX_SX_NUM )
					sx_num = ADD_MAX_SX_NUM;
				obj->add("armor_prop/" + item_sx[i], sx_num);
				message_vision(HIG + obj->query("name") + HIG"��" + item_jc[i] + "����Ч��������"HIW + chinese_number(sx_num) + "�㡣\n"NOR, me, ob);
			}
		}
		obj->add("armor_prop/level", 1);
		// ��ֵ����
		obj->add("value", obj->query("value") / 100 * obj->query("armor_prop/level"));
	}

	obj->set("xyzx_save_item", 1);
	obj->set("owner_id", 1);
	destruct(ob);
	return 1;
}