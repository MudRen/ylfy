//ROOM damen.c

inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long",@LONG
������������ǰ�Ĺ㳡��������Ȼ���������������������ͤ¥��
ȫ���㳡������ֲ��ï�ܵ���ɼ����Ũ���أ���������������������
���м�һ����ש�̳ɵĴ��ֱͨ���ת�����ߵ���������೤�ȣ�ͨ��
�����ط���
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
		"north" : __DIR__"miaomen",
                "south" : __DIR__"dadian",
                "east"  : __DIR__"zoulang1",
                "west"  :__DIR__"zoulang2",
	]));

	set("objects",([
	]));
	setup();
}
