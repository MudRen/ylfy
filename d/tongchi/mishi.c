inherit ROOM;
void create()
{
          set("short", "����");
        set("long", @LONG
���ң���˵�������һ���书�ؼ���
LONG
        );
        set("exits", ([
                   "down" : __DIR__"yishi",
        ]));
        set("objects", ([
       __DIR__"obj/jing" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
