// Room: shulin12.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һƬټ������֣���ľ���죬���Ʊ��ա����������ʧ�˷���
��֪�������Լ����ںδ������в�ʱ����Ұ�޹���ĵͺ��Х��,���㲻
��ë���Ȼ��ֻ������뿪��

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"shulin11",
  "west" : __DIR__"shulin11",
  "south" : __DIR__"shulin6",
  "east" : __DIR__"shulin",
]));
        set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/huo-chan" : 1,
]));
set("no_clean_up", 0);  	

        setup();
//  27          replace_program(ROOM);	
}
void init()
{
add_action("do_use", "use");
}

int do_use(string arg)
{
object me;
me = this_player();
if( !arg || arg=="" ) return 0; 	
if (!present("fire", me))  return 0;
if( arg=="fire" ) {
write(
"���ȼ�˻��ۣ��������ֶ������������ѵ�С·����֪ͨ��δ���\n");
set("exits/northeast", __DIR__"xuanya");         	
remove_call_out("close");
call_out("close", 20, this_object());
return 1;
}
}

void close(object room)
{
message("vision","�����ӵĹ��߽�������������\n", room);
room->delete("exits/northeast");
}

