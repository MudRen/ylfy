// Room: /d/wudie/jm.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ȥ����ɽׯ�ıؾ�֮·��Ⱥɽ�����۵ף���������Ľ�����
�ơ�ֻ��һ�����Ŷ���ʯ��С����ǰ���ӣ�С·������һ��ï�ܵ���
�֡�����С·�ϣ�����һ���Ŀ������ĸо���
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"southdown" : __DIR__"shanlu40",
		"north" : __DIR__"qjm",
	]));
	set("no_clean_up", 0);
	set("objects", ([
        __DIR__"npc/diefeng" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
    object ob=present("die feng", environment(me));
    if ((me->query("family/family_name") != "�����") && dir == "north" &&
                objectp(ob) && living(ob) )
       return notify_fail("������ס��˵�����㲻������ɵ��ӣ�\n��ȥ���в��㣬��������\n��������Ȱ���\n");
        
        return ::valid_leave(me, dir);
}
