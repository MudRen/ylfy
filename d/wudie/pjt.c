// Room: /d/wudie/pjt.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "Ʈ��԰");
        set("long", @LONG
��������������ҩ�ģ���֪������������ô�ࣿ��ǧ������ڣ�
����ɽ���˲Ρ������˲���˼�������԰�ӵ�һ���������һ��ѩ��
�겻����ѩ�п��ż���׻��������������ʿ�����������ɽѩ������
���������ҩ�ġ���������ʤ����
LONG
);
        set("no_fight", "1");
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"rht",
  "south" : __DIR__"wdt",
  "west" : __DIR__"dyt",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
