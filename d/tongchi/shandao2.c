inherit ROOM;
void create()
{
    set("short", "ʯ��");
    set("long", @LONG 
������ʯ��������Ȼ��������ͷ����ߵ�ɽ�����ų������
�Ľ��󣬳����˱�������̦��������ϡ��Щ����ĺۼ�����һ��
���ر���������ͨ�԰������Са����һ�Ρ�
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
 ]));
    set("no_clean_up", 0);
    set("outdoors", "tongchi");
    set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shandao",
    "east" : __DIR__"hu",
]));
    setup();
    replace_program(ROOM);
}
