// zimuzhen.c
#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("��ĸ����", ({"zimuzhen", "zhen" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "����һ��ϸ����˿�����롣\n");
		set("unit", "Щ");
                set("base_value", 1);
		set("material", "steel");
                set("base_unit", "��");
		set("base_weight", 10); 
	}	
        set_amount(50);
        init_throwing(300);
        setup();
}

void init()
{
        add_action("do_wield", "wield");
	add_action("do_unwield", "unwield");
}

int do_wield(string arg)
{  
       object me=this_player();

        object ob;
        string str;
	
        if (!id(arg))   return notify_fail("��Ҫװ��ʲô��\n");


	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( ob->query("equipped") )
		return notify_fail("���Ѿ�װ�����ˡ�\n");


	if( ob->wield() ) {
              if( !stringp(str = ob->query("wield_msg")) )
			str = "$Nװ��$n��������\n";
              message_vision(str, me, ob);me->set_temp("marks/��ĸ��",1);

              return 1;
	}

        else
                return 0;
}
int do_unwield(string arg)

{  
       object me=this_player();

        object ob;
        string str;

        if (!id(arg))   
			return notify_fail("��Ҫ����ʲô��\n");

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( ob->query("equipped") )
		return notify_fail("���Ѿ������ˡ�\n");

	if( ob->unwield() ) {
              if( !stringp(str = ob->query("unwield_msg")) )
			str = "$N�������е�$n��\n";
              message_vision(str, me, ob);me->delete_temp("marks/��ĸ��");

              return 1;
	}

        else
                return 0;
}