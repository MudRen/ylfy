// Room: /d/emei/dabeita.c ������ ����

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
����һ��שʯ�ṹ�ı������������㣬�������˽��Σ��������ᣬ�ܽ���
������һ����Сͭ�壬��綣�����졣����ǽ���οյ�����������񣬻��ü
��Ŀ����ŭĿԲ����һ������̬άФ��������ڴ�����һ�ȹ��ε�Сľ�ţ���
�������ò���Ϳ�档
LONG
	);

	set("exits", ([
		"east" : __DIR__"gudelin3",
                "enter" : __DIR__"baota1",
	]));
	set("outdoors", "emei");
        set("objects",([
               CLASS_D("emei") + "/jingdao" : 1,
	]));

        setup();
}

int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");

    if ((!myfam || myfam["family_name"] != "������") && dir == "enter") {
        if(objectp(present("jing dao", environment(me))))
            return notify_fail("����������סȥ·������˵���������Ƿ���ʥ�أ������Ҵ���\n");
    }

    return ::valid_leave(me, dir);
}


