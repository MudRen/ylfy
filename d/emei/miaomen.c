//ROOM damen.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long",@LONG
�����������ֵĴ��š�һ����ש���ֱͨ�ſڣ���·�����������˸���
�����ߵ���ǰ������������Ϲ���һ���ң������������֡������֡���
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "east" : __DIR__"jinding",
                "south" : __DIR__"guangchang",
	]));

	set("objects",([
	]));
	setup();
}
