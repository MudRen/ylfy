inherit ROOM;
void create()
{
        set("short", "ǰ��԰");
        set("long", @LONG
��������֮����������Լ�һ�ߣ��ı߻������࣬��Ψ��ĵ����ʤ���ǻ�����Ѱ
����¥��֮�࣬�ˡ�Ҧ�ơ���κ�ϡ�������Ʒ��һ����ֵ��ǧ���ǻ����������Ŷ��棬
��Χ�Ժ�ʯ��֮���仨���絤�̣���ɫ���ã��⻪��Ŀ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"pingfeng",
  "southwest" : __DIR__"bamboo_bridge1",
  "east" : __DIR__"garden1",
  "west" : __DIR__"garden2",
]));
        set("outdoors","dali");

        setup();

}
