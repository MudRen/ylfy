// Room: /d/nanyang/nanyang.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
������ǵ�����������Ĺʾӡ������ǲ�����Ϊ�س�Ҫ�壬
���������Ŀ����ر�࣬����Ҳ�����ȫ����¥����ջ����꣬
�����Ӷ��ǡ������˿����٣�����������ɫ�ҴҵĽ������ˡ�
LONG
    );
    set("outdoors", "shaolin");
    set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"yidao3",
  "east" : __DIR__"kedian1",
  "south" : __DIR__"hanshui2",
]));
    set("objects", ([ /* sizeof() == 2 */
  "/d/city/npc/drunk" : 1,
  "/d/shaolin/npc/xiao-fan" : 1,
]));
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
