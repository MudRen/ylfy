// jiashan
// by chenww
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
��������һ����ɽȺ,��佻���������ܹ��ɽ���Ƶ�.����������
����,�������ҵ�����--���춴.����ǰ��һ����ͷ������ͷ,��������
ɨ��.
LONG
	);
        set("outdoors", "huanhua");

	set("exits", ([
		"west" : __DIR__"changlang",
		"east" : __DIR__"jiantiand",
	]));
      set("objects", ([
               __DIR__"npc/yabo" : 1]));
                

	set("coor/x",130);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",130);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",130);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",130);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
	}


int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "佻�����") && dir == "east" &&
                objectp(present("ya bo", environment(me))))
           return notify_fail("�Ʋ����������������ס��,Ц�������춴��佻����ɵĽ���,�������ڡ�\n");
                
        return ::valid_leave(me, dir);
}
