// Room: /d/tianlongsi/doushuai.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "���ʴ�ʿԺ");
    set("long", @LONG
����һ��ΰ������ܵ�����Զ�ĵط��������Ͼ���������������ɮ��
��֮������Ĳ���á����ǳ��˲������״���ĵط�������ò�Ҫ���Դ���
��������ȷ���ܸ���ɮ�Ǵ�ȥ����Ϣ��
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/xianglu" : 1,
]));
    set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"sanwugong",
  "northeast" : __DIR__"doumugong",
  "north" : __DIR__"qingxinge",
]));
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
