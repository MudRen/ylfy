inherit ROOM;
void create()
{
    set("short", "ʯ��");
    set("long", @LONG 
ʯ�������������죬�ٲ��ڽ���Խ��ԽС��ˮ��Ҳ����Զȥ
����Զ�����ƺ����Կ���ʯ��һ�ǡ�
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
 ]));
    set("no_clean_up", 0);
    set("outdoors", "tongchi");
    set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shandao3",
  "north" : __DIR__"damen",
]));
    setup();
    replace_program(ROOM);
}
