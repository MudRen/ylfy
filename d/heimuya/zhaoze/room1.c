
inherit ROOM;
void create()
{
	set("short", "С��");
	set("long", @LONG
����һ��С���ţ�һ���峺��СϪ�����»�����������ʱ����Ƥ
��С��Ծ��ˮ�棬�������»���һ������ɫ�Ļ��ߡ�
LONG
	);
	set("outdoors", "room1");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"room2",
  "northeast" : "/d/heimuya/guang",
]));

	setup();
	replace_program(ROOM);
}
