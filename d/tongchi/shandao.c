inherit ROOM;
void create()
{
    set("short", "ʯ��");
    set("long", @LONG
ʯ���������ƺ���ÿ�����Щ�����µ�ɽ���������������
�����Ϊһˬ��Զ����������ˮ�������н�Զ��ɽ���Ϲ���
�˺��ܵ����ܣ��������ҡ߮��
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
 ]));
    set("no_clean_up", 0);
    set("outdoors", "shaolin");
    set("exits", ([ /* sizeof() == 2 */
  "southdown" : "/d/xingxiu/jiayuguan",
  "northup" : __DIR__"shandao2",
]));
    setup();
    replace_program(ROOM);
}
