// Room: /d/wudie/ydt.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "�޵���");
        set("long", @LONG
���������ŵ���Ϣ�ĵط������õķǳ����£����߷�һ����������
�ϰ������ؼ���һ���ľ����������һ����ױ̨��ǽ�Ϲ���һ�ѹ�ɫ��
��ı�������ʱ���вʵ��ɽ��ɳ���
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wdt",
  "north" : __DIR__"rht",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
