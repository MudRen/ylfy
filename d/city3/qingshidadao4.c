// Room: /chengdu/qingshidadao4.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "��ʯ���");
	set("long", @LONG
�������ǳɶ��ؽ��ˡ�һ����ʯ���̳ɵ�·���ȽϿ���
��·�����ֵ������������������΢�紵��ɳɳ���졣����
��������ɶ��ǣ����������˵�Ҳ���١�������ȥ������Լ
�����ɶ��ǵĳ�ǽ����ʯ·�������죬����ͨ����
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "west" : __DIR__"gangdao",
                "east" : __DIR__"qingshidadao3",
	]));

	setup();
	replace_program(ROOM);
}

