// Room: /d/emei/xixiangchi.c ������ ϴ���


inherit ROOM;


void create()
{
	set("short", "ϴ���");
	set("long", @LONG
���Ǻܴ��һ��ƽ̨���м���һ����ˮ����Ȫ���ж���ˮ�����ˮ
�棬����ˮ�ذ��˷������������ڡ����ϲ�ľ��������˵�������������
�������ϴ����Ҳ��˶�������
LONG
	);
         set("outdoors", "emei");
	set("exits", ([
                "northdown":__DIR__"podao2",
                "west" : __DIR__"guanyintang",
		"southup" : __DIR__"lingyunti",
	]));

	set("objects",([
	        "/d/emei/npc/haoke" : 2,
        ]));
	setup();

}
