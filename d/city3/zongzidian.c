// Room:/d/chengdu/zongzidian.c
// oooc 1998/6/28

inherit ROOM;

void create()
{
	set("short", "�������ӵ�");
	set("long", @LONG
����һ�Һͼ��ˡ�����ի����Ӫ�����ӵꡣ�����������־�˵
�Ǻ������ص�һ����������Ϊ���ϵ�����¥��һ����˻����գ���
��������̣�����Ҫ׬ǮΪ����������������������������ϣ�
���������һֱ���ã�����������ϼ���������Ц�ݡ�
LONG
	);

	set("exits", ([
		
                "west" : __DIR__"xiaojie1",
	]));

	set("objects", ([
		__DIR__"npc/zhangqinlin" : 1,
	]));

	setup();
	replace_program(ROOM);
}

