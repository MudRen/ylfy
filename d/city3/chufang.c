//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ�ų�������̨�Ϸ�������������,ÿ�ڹ���ǰ����һ
λ��ʦ��,�������ں���䤱��س��Ųˡ�
LONG
        );

        set("exits", ([
                "west" : __DIR__"chenmapo",                
        ]));
        set("objects", ([
                __DIR__"npc/dashifu" : 3,
        ]));
      
        setup();
        replace_program(ROOM);
}

 
