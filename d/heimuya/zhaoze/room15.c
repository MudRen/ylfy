
inherit ROOM;
void create()
{
	set("short", "é��");
	set("long", @LONG
���Ǽ�Ͱ���é�ݣ��ıڹ�����Ұ�޵�ͷ­�͸����������ë��
ֻ��é���������һ������ʹ���������Ե���ɭ�ֲ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"room14",
]));
        set("objects", ([ 
        __DIR__"npc/fonghuang" : 1,
]));

	set("channel_id", "é��");

	setup();
	replace_program(ROOM);
}
