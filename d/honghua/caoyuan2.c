// Room: /d/honghua/caoyuan2.c
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
		"north" : __DIR__"caoyuan3",
		"south" : __DIR__"caoyuan",
		]));
	set("outdoors", "honghua");
	setup();
}
