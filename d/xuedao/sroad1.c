// sroad1.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","ɽ·");
        set("long",@LONG
�������ǳ�ɽ���룬��ͨ���㡣һ��ɽ·������ɽ�䣬������
�رߺ���ԭ��
LONG );
        set("exits",([
                "north"  : "/d/xueshan/caoyuan",
"northwest"  : "/d/lingxiao/boot",	
                "westup" : __DIR__"sroad2",
        ]));
        set("outdoors", "xueshan");
        set("no_clean_up", 0);
        set("coor/x",-110);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

