
inherit ROOM;
void init();

void create()
{
	set("short","У��");
	set("long", @LONG
������ɱ��¥��У������������һЩɱ��¥�ĵ�
����������ϰ�书��У���Ķ�����ɱ��¥�ı����ң�
������ɱ��¥������Ϣ�ĵط���У���ı�����ɱ��¥
��ǰ�
LONG
	   );
	set("exits",([/* sizeof()==4 */
	    "south" : __DIR__"fenglin",
	    "north" : __DIR__"qiandian",
	    "west" : __DIR__"xiuxishi",
	    "east" : __DIR__"liangongfang",
	   ]));
	set("no_clean_up", 0);
	set("outdoors", "shashou" );

	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	"/clone/board/shashou_b"->foo();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "ɱ��¥" ) && dir == "west" )
                return notify_fail("�㲻��ɱ��¥�ĵ��ӣ��ܽ�ȥ���\n");
                
        return ::valid_leave(me, dir);
}

