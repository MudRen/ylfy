// Room: yaofang1.c

inherit ROOM;

void create()
{
        set("short", "ҩ��");
        set("long", @LONG
һ�����������һ��Ǻ�˵�ҩζ�˱Ƕ������߸ߵ͵͵ĳ������
���˲�֪����ҩƷ������������ҩ������ҩʦ����������˸�Ҿ����
��������Ц��Ц��������ʲô���ܲ������㡣
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zoulang1",
  "east" : __DIR__"danfang",
]));
set("objects",([
        __DIR__"npc/hu-dizi" : 1,
]));
        set("no_clean_up", 0);
        set("no_fight", 1);

        setup();
        replace_program(ROOM);
}

