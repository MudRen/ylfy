//      neidian.c �ڵ�
//      Designed by secret (����)
//      97/04/09
inherit ROOM;
void create()
{
        set("short","�ڵ�");
        set("long",@LONG
    ������ѩɽ�µ��ڵҲ�������˼��͵ĵط���
LONG
        );
        set("exits",([
                "east" : __DIR__"tiantai",
                "west" : __DIR__"midao",
                "south" : __DIR__"zoulang3",
        ]));
      set("objects",([
        CLASS_D("xueshan")+"/jiumozhi" :1
      ]));
        setup();
        replace_program(ROOM);
}
