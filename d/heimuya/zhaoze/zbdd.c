
inherit ROOM;

void create()
{
	set("short", "���ߴ��");
	set("long", @LONG
���²��������ٿ���˫����ǰ��һ���������ڰ�������ͷ��ֻ����ˮ����
ŭ����ӿ��ˮ���ļ�������ɽʯ���������Ρ�롣һ����ʯ���ֱͨ������
LONG
);
	set("outdoors", "zbdd");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tsq",
  "west" : "/d/tianlongsi/dadao1",
]));

	setup();
	replace_program(ROOM);
}
