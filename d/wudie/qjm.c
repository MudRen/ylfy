// Room: /d/wudie/qjm.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
����԰�У�����������԰�еľ���������԰�б鲼��֪�����滨��
�ݡ�ǰ����һ���޴���ٲ���������ˮ����������ҫ�£�����һ��
�ʺ硣�ٲ�������һ�����̵�ˮ̶����Ӱ���滨��ݡ�ˮ̶������һ��
��ɽ����ɽ�Ͽ϶��ܺ��棬������(jump)��ȥˣһ�¡�
LONG
);
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jm",
  "north" : __DIR__"pxt",
]));

        setup();
        replace_program(ROOM);
}
