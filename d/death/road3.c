// Room: /d/death/road3.c
inherit ROOM;
void create()
{
        set("short", "·�ľ�ͷ");
        set("long", @LONG
������һ����ů��������Ͷ���������·�ϣ�ֻ���������û�п��֣�
Ҳû�б��ˡ���ǲ�����������Щɶ��Ҳ�벻����Ҫ��ʲô����ĸ�
���������ߣ�������Ʈѽ��Ʈѽ...
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/death/road3",
  "south" : "/d/death/road2",
]));
        set("no_fight",1);
        setup();
        replace_program(ROOM);
}
