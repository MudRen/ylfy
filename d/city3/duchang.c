//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "�ĳ�");
        set("long", @LONG
������һ�Ҷĳ�,������ͻῴ���پ��������ĸ�����
"Ը�ķ���".�ഫ���ǵ����"��Ĺ�"��ԯ����Ĵ��ֱʡ�
��˵������һ��������������￪�˸����ӡ�ûǮ����
��ûؼұ�����ȥ��
LONG
        );

        set("exits", ([
                "west" : __DIR__"beijie2",
                "east" : __DIR__"duchang1",  
        ]));
      
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "east" && this_player()->query("age")<18)
                return notify_fail("С�޶��Ҽҵ�����ͷ��ɶ��?!\n");
        return ::valid_leave(me, dir);
}

 
