// Room: /chengdu/cdkedian2.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "��ջ��¥");
	set("long", @LONG
	�������ڿ͵��¥�������ϣ����������ӿͷ��ﲻʱ�غ���
�Ĵ�����һ��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ�����������¥��
���ƹ񴦸���Ǯ������˯����
LONG
	);

	set("exits", ([
                "down" : __DIR__"cdkedian",
                "east" : __DIR__"cdkedian3",
                "west" : __DIR__"cdkedian4",
	]));

	setup();
	replace_program(ROOM);
}

