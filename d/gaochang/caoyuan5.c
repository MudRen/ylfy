// Room
inherit ROOM;
void create()
{
	set("short", "���");
	set("long", @LONG
���ƽ̹�羵����ɳĮ�ϵ�ɳ�����ȫȻ��ͬ��ֻ��һƬƽɳ������Զ����
ֻ�������ӣ����������������˾�������Ҳ������֮�У��پ���ǧ���ޣ�һ��
��С�쳣��
LONG
	);
	set("no_new_clean_up", 0);
	set("outdoors", "caoyuan5");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"caoyuan4",
   "southwest" : "/d/xingxiu/nanjiang",
]));

	setup();
	replace_program(ROOM);
}