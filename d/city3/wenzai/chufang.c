//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������¼ҵĳ������¼�����Ǻ��������Ĵ�ʦ������
����ȫ�ҵĻ�ʳ���¼ҵ�ʦ����ȫ�ɶ����Ǻ��������ģ���
ʱ��û������ʱ�䣬��ʦ���������������̡�
LONG
        );

        set("exits", ([
                "east" : __DIR__"zoulang3",                
        ]));
        set("objects", ([
                __DIR__"npc/dashifu" : 1,
        ]));
      
        setup();
        replace_program(ROOM);
}

 
