// Room: /city/zuixianlou.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "ӭ�ɾ�¥");
	set("long", @LONG
��Բ������������ӭ�ɾƿ���˵�����˲�֪�����˲�������
�Ƕ�ӭ�ɾ�¥���ɾ��޲����ڡ�¥�²��ü��ף��˿Ͷ��ǴҴҵ�
���ˣ������ӡ����ȡ��׾ƾ͸�·ȥ�ˡ�¥����������
LONG
	);

	set("exits", ([
                "north" : __DIR__"xijie2",
                "up" : __DIR__"cdjiulou2",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));

	setup();
	replace_program(ROOM);
}

