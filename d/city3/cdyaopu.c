
inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ��
�ϵļ��ٸ�С������ɢ�������ġ���ҽƽһָ���ڲ輸�ԣ�����
���Ų裬��Ҳ������һ�ۡ�һ��С���վ�ڹ�̨���к��Ź˿͡�
��̨������һ�ŷ��ƵĹ��(guanggao)��
LONG
	);
	set("item_desc", ([
		"guanggao" : "�����������ҩƷ��
��ҩ��\t��ʮ������
������ҩ���ϰ����顣\n",
	]));

//	set("item_desc", ([
//		"guanggao" : "�����ϰ�ƽһָ�����ҩδ�飬������ͣӪҵ��\n",
//	]));

	set("objects", ([
		__DIR__"npc/ping" : 1,
		__DIR__"npc/huoji2" : 1,
	]));

	set("exits", ([
                "north" : __DIR__"xijie1",
	]));

	setup();
	replace_program(ROOM);
}

