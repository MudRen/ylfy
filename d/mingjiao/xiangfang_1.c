// Room: xiangfang_1.c

inherit ROOM;

void create()
{
        set("short", "�᷿");
        set("long", @LONG
���������������Ӵ����ý���������᷿������򵥣�ȴ���õ�
�ɾ����࣬һ�Ŵ��ִ������ʡ��м���Сͯ������ϸ�������Ρ���
�������������й�͵����ˡ�������ǹ�����ǰ����

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"guangming-ding",
]));
        set("sleep_room", 1);
        set("no_fight", 1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
 
