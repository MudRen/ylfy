
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������������ˣ����ŵĵ�������һ�䡰ǧ��֮��ʼ����
�¡�����˵��ʱ��ʫ�˱����ڴ������˾�ġ��źܿ������Ǻ�
��������ˣ������ϵ���ʨ��ͷ����һ������ʮ��ͷ֮�ࡣ����
�����Ϻӣ�ˮ���峺���ף�һȺС����ˮ����Ϸ���֡�
LONG
	);

	set("exits", ([
                "west" : __DIR__"wangjianglou1",
                "east" : __DIR__"xuetao",
	]));

        set("outdoors", "chengdu");
	setup();
	replace_program(ROOM);
}



