// Room: /d/wudang/xiaochidian.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "С�Ե�");
    set("long", @LONG
���С�Ե겼�ü��ף���ֱ����һ������͸��������Ҳ�ܽ�С�Եꡣ
�˿Ͷ��ǴҴҵ����ˣ������ӡ����ȡ��׾ƾ͸�·ȥ�ˡ�
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoer3" : 1,
]));
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"shijie5",
  "east" : __DIR__"xiaolu4",
  "southdown" : __DIR__"xuanwumen",
]));
    setup();
    replace_program(ROOM);
}
