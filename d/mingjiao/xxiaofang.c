// Room: xxiangfang.c

inherit ROOM;

void create()
{
        set("short", "���᷿");
        set("long", @LONG
��������������һ����˼�С��Ĺ뷿�������ߵ���һ����ױ̨��̨
�Ϻ�����գ���ҫ�÷��л��Ž��أ������ûʡ���һ��������������������
�ʹ�����ǰ������һ��Ů�ӵķۺ���Ь���������˸�˯�ڴ��ϡ���뷿ֻ��
һ�����ţ��������ա�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"houyuan",
]));
        set("sleep_room", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

