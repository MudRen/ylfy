// Room: chufang.c

inherit ROOM;

void create()
{
        set("short", "��ʳ��");
        set("long", @LONG
�㿴�������Ѿ��������������˽��ڣ�Χ�Ű����������š�һ��
�ϳ��ӹ���������ӭ�˹�����ָ��ָ�����������ʣ�µ�Ψһһ��ȳ
���ȵ�С�������εض��������ʼ硣

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zoulang4",
]));
        set("no_fight", "1");
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chuzi" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

