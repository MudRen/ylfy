// Room: /d/cxwxm/feifeng2.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "�ɷ��");
        set("long", @LONG
�����������Ĺ뷿��Ҳ�����ճ���ױ���ĵط�������һ����ľ��ױ̨��
������Ƕ�ŵ���һ������ɫ��ͭ������ױ̨�ϻ������Ż��۵���ۡ���̨��
�ڷ���һ�˸ߵĴ�ƿ�в�����ɢ������������򻨡�

LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"feifeng",
  "west" : __DIR__"feifeng3",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
