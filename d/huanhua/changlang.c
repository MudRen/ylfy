//changlang.c

inherit ROOM;
void init();
void create()
{
        set("short", "����");
        set("long", @LONG
һ�������ĳ��ȣ�����û��ʲô����⻬��ʯ��������һЩ��Ȼ��
����ʱ����һЩ佻����ִҴ��߹�������ͨ��佻����ɵ����á�
LONG
        );

        set("exits", ([
              "north" : __DIR__"xiuxishi",
                "east" : __DIR__"jiashan",
                "west" : __DIR__"changlang2",
                ]));
        set("no_clean_up", 0);
        set("coor/x",120);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",120);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",120);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",120);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
}


int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "佻�����" ) && dir == "north" )
               return notify_fail("�㲻��佻����ɵĵ��ӣ��ܽ�ȥ���\n");
                
        return ::valid_leave(me, dir);
}


