// Room: luzhou.c

inherit ROOM;

void create()
{
        set("short", "ɳĮ����");
        set("long", @LONG
�������Х���������׵Ĵ�ɳĮ�У�һƬɳĮ������
����¥�㸡���������ǰ��һƬƬ���̵�Ҭ������һ�����峺
�ĺ�ˮ���Լ����������ݵء���ֻС����һ����ˮ��һ�߸�
�����ò����У�������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zhang-shi",
  "south" : "/d/xingxiu/silk2",
  "north" : __DIR__"shanjiao",
  "east" : __DIR__"yuanzhenju",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");
        set("can_dig",1);
        set("dig_out",50);

        setup();
        replace_program(ROOM);
}

