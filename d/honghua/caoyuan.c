// Room: /d/honghua/caoyuan.c
// Date:  98/10/29
inherit ROOM;
void create()
{
	set("short", "��ԭ");
	set("long", @LONG
��������˼������Ĵ��ԭ��һ���޼ʵĲݵ���粨������ؽ�
�Ӵ��м����ڵ㣬���ܷǳ��İ�����ֻ�ǲ�ʱ����Ů�����ĸ�����֪
���Ķ�Ʈ��Ĵ���.
LONG
	);
	set("exits", ([
		"north" : __DIR__"shanxia",
		"south" : "/d/xingxiu/saimachang",
		]));
	set("outdoors", "honghua");
	set("coor/x",-130);
	set("coor/y",60);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",60);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",60);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",60);
	set("coor/z",0);
	setup();
}
