inherit ROOM;
 
void create()
{
        set("short", "ʥ����");
        set("long",@LONG
�����Ǻ�ľ�µ�ʥ�����ڵء�ʥ���á��������޲�����,ɲ��
Ư��.����һλ����Ů��,�������.�
LONG );
        set("exits", ([
  "east"   : __DIR__"chitang",
]));
        set("objects", ([
		__DIR__"npc/ren" : 1,
		__DIR__"npc/shinu":2,
           ]));       
         setup();
         replace_program(ROOM);
}
