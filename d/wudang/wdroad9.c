// wdroad9.c ����·
// by Xiang

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
	������һ����������Ļ���·�ϣ���������ɭɭ�����֡�
���Ϸ���һ��С·ͨ���Ĵ����Ҿ��ڡ�
LONG
	);
        set("outdoors", "emei");

	set("exits", ([
                "southwest": "/d/emei/shanlu1",
                "north": "/d/wudang/wdroad8",
"southeast": "/d/henshan/hsroad8",	
	]));
	setup();
	replace_program(ROOM);
}

