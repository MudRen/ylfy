// Room: /d/emei/jiudaoguai2.c ������ ��ʮ�ŵ���2

inherit ROOM;

void create()
{
	set("short", "��ʮ�ŵ���");
	set("long", @LONG
�������Ѿ����뵽ɽ�ȸ��أ�ֻ��������������¼�������ɽȪ���ཻ
���ش�ġ��ˡ��֣�����ֱ�£����鵷������һ��խխ��ɽ��������С·
���ض����ٲ��Ϸ���ʯ�������˹����һ�����ݡ����϶��˼���ľ׮����
�ϴֳ���������Ϊ���֡�
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
		"northeast" : __DIR__"jiudaoguai1",
                "southup": __DIR__"jiudaoguai3",
	]));

	setup();
}



