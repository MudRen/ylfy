inherit ROOM;
 
void create()
{
        set("short", "�׻���");
        set("long",@LONG
�����Ǻ�ľ�µĵڶ����á��׻��á���������ש�̵�,���ں�ʬ���ء�
LONG );
        set("exits", ([
  "north"   : __DIR__"baistep2",
  "south"      : __DIR__"chitang", 
]));
        set("objects", ([
		__DIR__"npc/shanggy" : 1,
           ]));       
         setup();
         replace_program(ROOM);
}
