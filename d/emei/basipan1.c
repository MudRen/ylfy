// Room: /d/emei/basipan1.c ������ ��ʮ����1

inherit ROOM;

void create()
{
	set("short", "��ʮ����");
	set("long", @LONG
�����ǰ�ʮ���̵���㣬Ҳ�Ƕ���ɽ��Σ�յ�һ��·�̣��ɴ�����ʯ��
�ϣ�������˿��Կ���ǰ����˵�Ь�ף�ǰ����˻�ͷ��ɼ���������˵�
������������һ����ÿ��ʮ������Ҫ������Ϣ��
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "west": __DIR__"leidongping",
		"westup" : __DIR__"basipan2",
	]));

	setup();
}
