// Room: /d/emei/basipan3.c ������ ��ʮ����3

inherit ROOM;

void create()
{
	set("short", "��ʮ����");
	set("long", @LONG
�����ǰ�ʮ��������һ��·�������Ѿ�����ƽ������·Ҳ�Կ�����
һЩ��������Ю�������ϣ�����������һ�����ϵ�ʯ�ף�����ȥ�Ѿ�����
ңң������һ�����������Ϸ�������ͨ������ɽ�Ľ𶥡�
LONG
           );
        set("outdoors", "emei");
	set("exits", ([
                "northdown":__DIR__"basipan2",
                "south":__DIR__"jieyindian",
                "west": __DIR__"shijie1",
                "east": __DIR__"milin3",
	]));

	setup();
}



