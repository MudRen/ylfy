// Room: /chengdu/xijie1.c

inherit ROOM;

void create()
{
        set("short", "�����");
	set("long", @LONG
�����ǳɶ�������֣��������������ַǷ���������������
�ȵĵ��̣�������ɫ�Ļ�������Ʈ��ɷ�����ޡ������İ���һ��
��ʮ��������ϼ�������̼�Ҳ��ʧʱ�����Ƴ�����ƽʱ�򲻵�
�Ķ������ϱ��Ǽ�ҩ�̣��������Ǹ�ռ�������ӡ�
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "east" : __DIR__"xijie2",
                "south" : __DIR__"cdyaopu",
                "west" : __DIR__"xijie",
                "north" : __DIR__"zhanbu",

	]));

	setup();
	replace_program(ROOM);
}

