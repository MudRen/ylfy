// Room: /d/heimuya/zhaoze/shimao2.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ֻ������С���ϵ���һ¯̴�㣬�������������ϸ���һ��ɮ�ˡ�һ������
��ڣ��߱���Ŀ���������ù��ˡ���һ�����ֲ�ɮ�ۣ����������İ�ü����
�Ǵ�����������Ŀ���飬ü����������࣬��һ��Ӻ�ݸ߻�����ɫ��ȴ��һ��
��֪��
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"shimao1",
]));
    set("objects", ([
        __DIR__"npc/tzhuseng" : 1,
        __DIR__"npc/yideng" : 1,
    ]));


	setup();
	replace_program(ROOM);
}
