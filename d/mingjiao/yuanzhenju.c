// Room: yuanzhenju.c

inherit ROOM;

void create()
{
        set("short", "Բ���");
        set("long", @LONG
С��һ�����ŵ�Ϧ����һ����ͷ������Ŀ�������������⣬
˫�ֽ��գ�������ȫ�������ɱ����������ʱ���׼��Ҫɱ
����������񫣬��������������������Ҫɱ�㣡���ӣ�����
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"luzhou",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yuan" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

