// xueyi.c Ѫ��
// ������������С���޸�

#include <ansi.h>
#include <armor.h>
inherit SURCOAT;
inherit F_UNIQUE;

mapping default_dirs = ([
	"north":	"����",
	"south":	"�ϱ�",
	"east":		"����",
	"west":		"����",
	"northup":	"����",
	"southup":	"�ϱ�",
	"eastup":	"����",
	"westup":	"����",
	"northdown":	"����",
	"southdown":	"�ϱ�",
	"eastdown":	"����",
	"westdown":	"����",
	"northeast":	"����",
	"northwest":	"����",
	"southeast":	"����",
	"southwest":	"����",
	"up":		"����",
	"down":		"����",
	"enter":	"����",
	"out":		"����",
]);

void create()
{
        set_name(HIR"Ѫ��"NOR, ({ "xueyi","yi" }) );
        set("long",@LONG
Ѫ��ɫһ�㱡���Ĳ�֪��ʲô�����Ƴɵ���ᣬװ��˫���Ͽ���
�����������Ի��裬��������������Գ����ı����Ϊ�����
�á�ʵ��Ѫ�����֮��֮һ��
LONG );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 10);
		set("value", 100000);
		set("armor_prop/dodge", 100);
		set("wear_msg","$N�ó�"HIR"Ѫ��"NOR"չ������ϸ�İ��ڱۡ���֮�䣬˫��һ�����ܷ��衣\n");
	}
	setup();
}

void init()
{
	add_action( "do_fly", "fly" );
}

int do_fly(string arg)
{
	string dest, mout, min, dir;
	object env, obj, me;
	mapping exit;

	me = this_player();
	env = environment(me);

	if ( !arg ) return notify_fail("��Ҫ���ĸ�����ɣ�\n");

	if ( me->over_encumbranced() )
		return notify_fail("��ĸ��ɹ��أ��������á�\n");

	if ( me->is_busy() )
		return notify_fail("��Ķ�����û����ɣ������ƶ���\n");

	if (!me->is_fighting())
		return notify_fail("Ѫ�������ս����ʹ�ã�ƽ��������ȥ����̫��ҡ����\n");

	if(!env) return notify_fail("������Ҳȥ���ˡ�\n");

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) )
			return notify_fail("�������û�г�·��\n");

	dest = exit[arg];

	if( !(obj = find_object(dest)) )
		call_other(dest, "???");
	if( !(obj = find_object(dest)) )
		return notify_fail("�޷��ƶ���\n");

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;

	mout = HIC"\n$NͻȻԾ��˫��һչ������"HIR"Ѫ��"HIC"������"NOR + dir + HIC"���˳�ȥ��\n\n"NOR;
	min = "�����һ����Ӱ����"HIC"Ѫ��"NOR"���˹��������������˵��ϡ�\n";

	message_vision( mout, me );
	me->move(obj);
	message( "vision", min, environment(me), ({me}) );

	return 1;
}
