inherit ROOM;
void create()
{
        set("short", "ǰ��԰");
        set("long", @LONG
佻�������֮����������Լ�һ�ߣ��ı߻������࣬��Ψ��ĵ����ʤ���ǻ�����Ѱ
����¥��֮�࣬�ˡ�Ҧ�ơ���κ�ϡ�������Ʒ��һ����ֵ��ǧ���ǻ����������Ŷ��棬
��Χ�Ժ�ʯ��֮���仨���絤�̣���ɫ���ã��⻪��Ŀ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"guanyuge",
  "southwest" : __DIR__"qiao",
]));
	set("outdoors","huanhua");
        set("coor/x",70);
	set("coor/y",-80);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-80);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-80);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
