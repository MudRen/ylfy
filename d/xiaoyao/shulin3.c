
inherit ROOM;
#define DA_EXP 3000+random(3000)
void create()
{
	set("short", "����");
	set("long", @LONG
����һƬï�ܵ����֡��ܶ�ü�ʮ�ɸߵĴ�������һ�飬��һ�Ѱ�����
��ɡ�������¶����ڱεð�Ȼ�޹⡣�����л���ʱ������������Ȼ���������졣
�����Ǹ�����da���ĺû��ᡣ
LONG
    );
	set("objects", ([ ]));
	set("outdoors", "xiaoyao");
	set("exits", ([ /* sizeof() == 4 */
		"west" : "/d/wudang/wdroad4",
		"south" : __DIR__"shulin3",
		"north" : __DIR__"shulin3",
		"east" : __DIR__"shulin2",
		]));
	set("no_clean_up", 0);
set("no_msg_vision",1);
	setup();
}

void init()
{
	add_action("do_da", "da");
}

int do_da()
{
	object me;
	string *name, *color, get_name;
	int val, max, exp, pot, flag;
	
	me = this_player();
	name = ({ "��ȸ", "ɽ��", "ϲȵ", "��ѻ", "�ž�", "����", "��ü��", "��ݺ", "������", "��˿ȸ" });
	color = ({ RED, GRN, YEL, BLU, MAG, CYN, WHT, HIR, HIG, HIY, HIB, HIM, HIC, HIW });
	
	if ( !me ) return 0;
	if ( me->is_busy() ) return notify_fail("�㻹�ǵȹ�װ���˼��ٴ���ɣ�\n");
	if ( me->query("qi") < 10 ) return notify_fail(HIY"�㻹������Ϣһ�°ɣ����ҲҪ������Ӵ��\n"NOR);
	if ( me->query("xyzx_sys/level") >= 100 )
		return notify_fail(HIR"���Ѿ�����ͨ������������ĥ���ˣ�����ȥ�������ڡ�\n"NOR);

	me->start_busy(1);
	me->receive_damage("qi", 10);
	tell_object(me,"�������ʱ��ˣ�õ�С��С������׼���ϵ�Сȸ��ȥ......\n");
	tell_object(me,"��ֻ������һ�����������\n");
	max = sizeof(name);
	val = random(max);
	exp = DA_EXP;
	pot = exp/10;
	flag = random(sizeof(color));

	if ( random(100) > 98 ) 
		tell_object(me,"��ʲôҲû�򵽡�\n");
	else
	{
		get_name = color[flag]+name[val];
		me->add("combat_exp", exp, 1);
		me->add("potential", pot, 1);
		tell_object(me,"���һֻ"+get_name+"��\n"NOR);
		tell_object(me, "��õ���"HIM+(exp*me->query_exp_times())+NOR"�㾭�顣\n");
		tell_object(me, "��õ���"HIY+pot+NOR"��Ǳ�ܡ�\n");

	}
	
	return 1;
}
