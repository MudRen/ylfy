// Room: /d/emei/podao2.c ������ �µ�2

inherit ROOM;

void create()
{
	set("short", "�µ�");
	set("long", @LONG
����խխ����ɽС·��һֱ��ֱ���ϡ���·Խ�����ͣ��㲻�ɵ�������
�������²�С�ı����鵽�¹�֮�С��������������Ȼ�γɵ�һ���ʯ��
�ϣ��Ѿ��е��ǳ�ƣ�͡�
LONG
	);

	set("exits", ([
                "northdown" : __DIR__"podao1",
                "southup": __DIR__"xixiangchi",
	]));

        set("outdoors", "emei");
	setup();
	replace_program(ROOM);
}



