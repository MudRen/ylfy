// /d/emei/yixiantian.c ����ɽһ����
// create by host nov,20

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "һ����");
	set("long", @LONG
����һ������ɽ�����Ѷ��ϵ�С·����ϡ���Կ���Զ����һ�����Ρ��
������ǰ�档ֻ����������������Ԩ�������ƺ���������֪�����ж����
�Ƽ�׳�ۣ������ּ�����Ҫ���Ի��в���ʹ�˸е���ɭɭ�ĺ��⡣
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
		"northdown" : __DIR__"niuxinting",
                "southup": __DIR__"shangu",
		]));
	set("no_clean_up", 0);

	set("objects", ([ 
	]));

	setup();

}
int valid_leave(object me,string dir)
{
		
        if(me->query_skill("dodge",1) < 20  && dir=="southup" )
	{
		me->receive_damage("qi", 5);
		me->receive_wound("qi",  5);
		message_vision(HIR"$N̫���ˣ�˵ʲôҲ�޷������Ｗ��ȥ��\n"NOR, me);
	        return notify_fail("");
         }
            return ::valid_leave(me,dir);
}
