// Room: /d/nanyang/shijie1.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "ʯ��");
    set("long", @LONG
��������ɽ��´������ɽɽ�š�һ��������ʯ����ͬ������
���Ѷ��ϣ�ֱû�ƶˡ���ɽȺ���������ɫ��ɽ�����˸������
����С֮�⡣�����м���������С���������ƺ�������������
Щʲô��
LONG
    );
    set("objects", ([ /* sizeof() == 2 */
  "/d/shaolin/npc/xiao-fan" : 1,
  "/d/shaolin/npc/tiao-fu" : 2,
]));
    set("no_clean_up", 0);
    set("outdoors", "shaolin");
    set("exits", ([ /* sizeof() == 3 */
   "east" : "/d/songshan/taishique",	
  "northup" : __DIR__"shijie2",
  "west" : __DIR__"xiaojing1",
]));
    setup();
    replace_program(ROOM);
}
