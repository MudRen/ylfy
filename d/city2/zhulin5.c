// Room: /d/city2/zhulin5.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����С��");
	set("long", @LONG
���ܶ������ܵ����֣�һ̤�������������·�������˼�������
Ω����̤��ƺ֮����ż����΢�������Ҷ�������������������˳�
��Ϊ֮һ�ӣ����Ǿ��ѵ��������ڡ�
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));
	set("exits", ([ /* sizeof() == 5 */
  "southwest" : __DIR__"zhulin5.c",
  "west" : __DIR__"zhulin5.c",
  "northeast" : __DIR__"zhulin5.c",
  "south" : __DIR__"zhulin4",
  "east" : __DIR__"zhulin5.c",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "city2");
	setup();
}
