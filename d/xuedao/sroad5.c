// sroad5.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","��ѩɽ");
        set("long",@LONG
�����ر�ѩ������ǰ�װ�����һƬ���Ӷ����������ģ�������ʼ���١�
LONG );
        set("exits",([
                "eastdown"  : __DIR__"sroad4",
                "southup"   : __DIR__"sroad6",
        ]));
        set("outdoors", "xueshan");
        set("no_clean_up", 0);
        set("coor/x",-150);
	set("coor/y",0);
	set("coor/z",40);
	set("coor/x",-150);
	set("coor/y",0);
	set("coor/z",40);
	set("coor/x",-150);
	set("coor/y",0);
	set("coor/z",40);
	set("coor/x",-150);
	set("coor/y",0);
	set("coor/z",40);
	setup();
	replace_program(ROOM);
}
