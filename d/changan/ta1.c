// Room: /d/changan/ta1.c
// This is a room made by Wsl.

inherit ROOM;

void create()
{
	set("short", "[1;37mС����[2;37;0m");
	set("long", @LONG
С�������ھ�����䣬��ȴ�����С���ʳ�С����������15��
��˫������Ϊһ���������������ۡ�
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ca34",
]));

	setup();
	replace_program(ROOM);
}
