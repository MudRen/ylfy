// Room: /d/nanyang/kedian1.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "������ջ");
    set("long", @LONG
����һ��Զ��������������ջ������ǳ���¡������οͶ�ѡ��
��������ţ��������������������صķ������顣��С����������
æ������ת���Ӵ�����ǻ�����Ŀ��ˡ�ǽ�Ϲ���һ������(paizi)��
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
  "/d/shaolin/npc/xiao-er" : 1,
]));
    set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "¥���ŷ���ÿҹ����������
",
]));
    set("valid_startroom", 1);
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"kedian2",
  "west" : __DIR__"nanyang",
]));
    setup();
    replace_program(ROOM);
}
