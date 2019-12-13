
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"��Ϣ��"NOR);
	set("long", @LONG
�����ǹ�Ĺ���ӵ���Ϣ�ң����пտն�����һ���Ĺ���졣һ�鳤����ʯ
���������������Ų�ϯ��һ���ײ������������������һ���˸ߵ����������
�У��������
LONG
);

	set("exits", ([
		"north" : __DIR__"gmht",
	]));

	set("objects", ([
		__DIR__"obj/bed" : 1,
	]));

	set("sleep_room", 1);
	set("no_fight", 1);

	create_door("north", "ʯ��", "south");
	setup();
}

void init()
{
	add_action("do_zuo", "zuo");
	add_action("do_liao", "liao");
}

int do_zuo(string arg)
{
	mapping fam;
	object me = this_player();
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
		return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");
	if (arg == "bed"){
		if (me->query("qi") < 40 )
			return notify_fail("�����̫�٣��޷������Ϻ���\n");
		if ( me->query("potential") - me->query("learned_points") < 1 )
			return notify_fail("���Ǳ��û�ˣ������ټ�����ϰ��\n");
		write(HIC"�������������ȶ�����\n"NOR);
		if (me->query_skill("force", 1) < 20){
			message_vision(HIR"$N��δ����,�͹ֽ�һ��, �Ӵ�������������������ܲ���ǧ�����֮������\n"NOR, me);
		return 1;
	}
        if ((me->query("potential") - me->query("learned_points")) < 1)
        	return notify_fail("���Ǳ�ܲ����ˡ�\n");
	if (me->query_skill("yunv-xinjing", 1) > 50)
		return notify_fail("�����Ů�ľ������൱���,���񴲲�����������ϰ�ڹ��ˡ�\n");
		write("�躮��֮��Ȼ��Ч��������Ȼ�������㿪ʼ��ϰ�ڹ��ķ������������ޱȡ� \n"NOR);
		me->receive_damage("qi", 10 + random(15));
		me->add("potential", -1);
		me->start_busy(random(2));
		me->improve_skill("yunv-xinjing", (int)(me->query_int()/2) +
		(int)(me->query_con()/2) );
		return 1;
	}
	return notify_fail("��Ҫ��������? \n");
}

int do_liao(string arg)
{
	object me = this_player();

	if (me->is_fighting() || me->is_busy())
		return notify_fail("����æ���ء�\n");
	if ((int)this_player()->query("eff_qi") == (int)this_player()->query("max_qi"))
		return notify_fail("����������û���ܵ��κ��˺���\n");
	if ( (int)me->query_condition( "marks_bed" ) > 0 ){
		me->receive_wound("qi", 10);
		message_vision(HIR"$NͻȻֻ��һ���溮�������壬������������ʱ��̫�̣�������δ��ԭ֮�ʡ�\n"NOR, me);
		me->unconcious();
		return 1;
	}
	if (arg == "bed") {
		message_vision(HIY"$N���Ϻ���, Ҫ��ǧ�꺮������. \n"NOR, me);
		if (me->query_skill("yunv-xinjing", 1) < 40)
			return notify_fail("�����������Դ������Ů�ľ��ڹ��ศ, �����޷�����. \n");
		me->set("eff_qi", me->query("max_qi"));
		me->apply_condition("marks_bed", 25);
		return 1;
	}
	return notify_fail("��Ҫ��������? \n");
}
