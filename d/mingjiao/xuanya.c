// Room: /d/mingjiao/xuanya.c
// lisa 2003.7.3
#include <ansi.h>;
#include <room.h>;
inherit ROOM;
string look_sign(object me);
void create()
{
set("short", "����");
set("long", @LONG
�������֣���ǰ��Ȼһ����Ⱥɽ���죬�������������֮�У�����
�����Ŀ�����������һ����ȴ�������ͱ�(qiaobi)�类�������ɣ�
����ס�
LONG );
set("exits", ([
"southwest" : __DIR__"shulin12",
]));
set("item_desc", ([
"qiaobi": (: look_sign :),
]) );
set("outdoors", "mingjiao");
setup();
}
string look_sign(object me)
{
return "��̽ͷ���ͱ�����������ֻ���������ơ�һ�󼱷�����������㲻�ɵ����˼�����\n";
}
void init()
{
add_action("do_tiao","tiao");
add_action("do_tiao","jump");
}
int do_tiao(string str)
{
object me;
me=this_player();
if (!str || str==" ") return 0;
if (str!="qiaobi") return notify_fail("��Ҫ���Ķ�����\n");	
if (str=="qiaobi")	
{
message_vision("$N������Ƭ�̣��͵�Ծ�������¡�\n", me);
me->move("/d/mingjiao/gudi1");       	
me->unconcious();	
if (me->query_skill("dodge",1)<1000)	
{
me->set_temp("last_damage_from", "������ɱ��");                 	
me->die();
}
}
return 1;
}
