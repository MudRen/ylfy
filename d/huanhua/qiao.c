inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
佻�Ϫ�ɺ�«״���ڴ�һ�������������������ƻ�żפ��Զ���ƻ���㣬������Ӱ
ө�⣬�����ѱ档����ʱ��˪����𣬷��ֽ�Ⱦ�Ʊ̣�Ұ��˥��ܽ�أ���ӳˮ�ʣ�«έ
�к���Ⱥ������߿���ƣ��������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"huayuan",
  "west" : __DIR__"bridge1",
]));
        set("objects", ([
        __DIR__"npc/shi" : 3,
                        ]) );

	set("outdoors","huanhua");
        set("coor/x",60);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
