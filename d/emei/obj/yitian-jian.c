// yitian-jian ���콣
// Modifyied by Uranus

#include <weapon.h>
#include <ansi.h>
int do_hukan();
inherit SWORD;

void create()
{
        set_name(HIY HIW "���콣" NOR,({ "yitian jian", "yitian", "sword", "jian" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("icon", "10016");
            set("value",50000);
//             set("no_drop", "�������������뿪�㡣\n");	
		set("no_put",1);
                set("material", "steel");
                set("long", "����һ���ĳ������ĹŽ��������Ͻ�˿���������֡����족��
����������������һ����������δ���ʣ��ѿɼ��䲻����\n");
                set("wield_msg", HIY "$N��ৡ���һ�����$n" + HIY + "���˸�������������â���£�
�����Ƿɡ� ....$N���ɵô��ĵ�����һ�����ƺ�����\n" NOR);
                set("unwield_msg", HIW "���콣"HIY"����һ���׹⣬��ৡ��ط��뽣�ʡ�\n" NOR);
                set("unequip_msg", HIW "���콣"HIY"����һ���׹⣬��ৡ��ط��뽣�ʡ�\n" NOR);
        }
init_sword(400,2);	
        setup();
}

// Add by Uranus

void init()
{
        add_action("do_hukan", "hukan");
}

int do_hukan()
{
	object me,dao,jian,book;
	string own;
	me = this_player();
	jian = this_object();

	if ( !present("tulong dao", me) )
		return notify_fail(HIW"�㻹û���õ��������أ���ʲô�����콣������\n"NOR);

	dao=present("tulong dao", me);

	if ( dao->query("name") != HIW HIY "������" NOR )
	{
		dao->unequip();
		dao->set("name", "�ϵ���" + dao->query("name"));
		dao->set("value", 0);
		dao->set("weapon_prop", 0);
		message_vision(HIC"$N���һ�������������������콣��ȥ��\n���������ž��һ���ϳ����ء�\n"NOR,me);
		return notify_fail(HIW"�����������ֻ���Ǽٵİɣ�\n"NOR);
	}

	if ( me->query("neili") <2000 )
		return notify_fail(HIW"�������̫���ˣ�ֻ�¿����ϰɣ�\n"NOR);

else if ( jian->query("name") == HIY HIW "���콣" NOR )	
	{
		jian->unequip();
		jian->set("name", "�ϵ���" + jian->query("name"));
		jian->set("value", 10000);
		jian->set("weapon_prop", 0);
		dao->unequip();
		dao->set("name", "�ϵ���" + dao->query("name"));
		dao->set("value", 10000);
		dao->set("weapon_prop", 0);
		message_vision(HIC"$N���һ�������������������콣��ȥ��\n"+
				"ֻ��һ���������֮�������콣��������˫˫�ϳ����ء�\n"NOR,me);
book = new("/clone/misc/wumu-yishu");	
		own = me->query("id");
		book->set("master",own);
		book->move(me);
		message_vision(HIC"$N�Ӷϵ������������ó�һ���顣\n"NOR,me);
		return 1;
	}
}

/* --- End of Modify --- */



int query_autoload() { return 1; }
